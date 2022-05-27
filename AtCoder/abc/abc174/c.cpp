#include <stdio.h>
int a[1000001];
int main(){
  int K;
  scanf("%d",&K);
  a[1]=7%K;
  for(int i=2;i<=K;i++)a[i]=(a[i-1]*10+7)%K;
  
  for(int i=1;i<=K;i++)if(a[i]==0){
    printf("%d\n",i);
    return 0;
  }
  printf("-1\n");
}

