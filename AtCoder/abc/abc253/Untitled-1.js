function formatDate(dt) {//yyyy-mm-dd
  var y = dt.getFullYear();
  var m = ('00' + (dt.getMonth()+1)).slice(-2);
  var d = ('00' + dt.getDate()).slice(-2);
  return (y + '-' + m + '-' + d);
}

function formatDate2(dt) {//yyyymmdd
  var y = dt.getFullYear();
  var m = ('00' + (dt.getMonth()+1)).slice(-2);
  var d = ('00' + dt.getDate()).slice(-2);
  return (y + m + d);
}

function applyDate() {//8日後の日付をyyyy-mm-ddに
  applyday = new Date()
  applyday.setDate(applyday.getDate() + 8); 
  return (formatDate(applyday))
}

function applyDate2() {//8日後の日付をyyyymmddに
  applyday = new Date()
  applyday.setDate(applyday.getDate() + 8); 
  return (formatDate2(applyday))
}

function copyDailyData() { //毎日転記して、締め切りましたを入力する関数
  const thisss =SpreadsheetApp.getActiveSpreadsheet();
  const thissf = thisss.getSheetByName('シート1');
  var ss = SpreadsheetApp.openById('1VWzjVcDfslmmvJqd3M0HE9KtYpZIhnqmHAUz9kUVoro');
  var sheets = ss.getSheets();
  var applyday = applyDate2();
  var appday = applyday.substring(2,8); //yymmddの形に直す

  ret = getsfname(sheets,appday) //該当の日付が含まれるシート名・日数を取得
  sfname = ret[0] //シート名
  minus = ret[1] //日数
  var sf = ss.getSheetByName(sfname)
  var lastRow = sf.getRange(2+8*minus,1).getNextDataCell(SpreadsheetApp.Direction.DOWN).getRow();
  var full = sf.getRange(5,2+8*minus,lastRow,8).getValues();
  for(let i=0;i<full.length;i++) {
    if(full[i][1]!=""){
      full[i].unshift(String(appday),"転記済み")
      thissf.appendRow(full[i]) //転記する
    }
  }
  //sf.getRange(15,2+8*minus,1,8).setBackground("#c0c0c0");
  //sf.getRange(15,2+8*minus,1,1).setValue("締め切りました");
}

function getsfname(sheets,today){//シート名を取ってくる関数
  for(let i=0;i<sheets.length;i++) {
    name = sheets[i].getName()
    if(name.indexOf("~") > -1 && name.indexOf("過去") == -1 && name.substring(0,2)==22){
      a = name.split("~")
      if(a[1].length==4){a[1]="22"+a[1]}
      if(Number(a[0])<Number(today)&&Number(a[1])>Number(today)){
        var sfname = sheets[i].getName()
        var minus = Number(today) - Number(a[0])
        break;
      }
    }
  }
  return [sfname,minus]
}

