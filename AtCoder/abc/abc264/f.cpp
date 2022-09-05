#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

const long long inf = 1e18;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<int> r(h);
    vector<int> c(w);
    for (int i = 0; i < h; i++){
        cin >> r[i];
    }
    for (int i = 0; i < w; i++){
        cin >> c[i];
    }
    vector<string> board_(h);
    for (int i = 0; i < h; i++){
        cin >> board_[i];
    }
    vector<vector<bool>> board(h, vector<bool>(w));
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            board[i][j] = (bool)(board_[i][j] - '0');
        }
    }
    // k = 0: iの反転回数
    // l = 0: jの反転回数
    vector<bool> first = {board[0][0], !board[0][0]};
    long long res = inf;
    for (int p = 0; p < 2; p++){
        vector dp(h, vector(w, vector(2, vector(2, inf))));
        if (p == 0){
            dp[0][0][0][0] = 0;
            dp[0][0][1][1] = r[0]+c[0];
        } else {
            dp[0][0][0][1] = c[0];
            dp[0][0][1][0] = r[0];
        }
        for (int i = 0; i < h; i++){
            for (int j = 0; j < w; j++){
                if (i == 0 && j == 0) continue;
                for (int k = 0; k < 2; k++){
                    for (int l = 0; l < 2; l++){
                        // 右
                        if (board[i][j] == first[p]){
                            // 白なら反転しなくていい. 上か左がそのまま. 
                            if (i > 0) {
                                dp[i][j][0][0] = min(dp[i-1][j][k][0], dp[i][j][0][0]);
                                dp[i][j][1][1] = min(dp[i-1][j][k][1] + r[i], dp[i][j][1][1]);
                            }
                            if (j > 0) {
                                dp[i][j][0][0] = min(dp[i][j-1][0][l], dp[i][j][0][0]);
                                dp[i][j][1][1] = min(dp[i][j-1][1][l] + c[j], dp[i][j][1][1]);
                            }
                        } else {
                            // 黒なら反転しないといけない. 上からきたらr, 左からきたらc
                            if (i > 0){
                                dp[i][j][1][0] = min(dp[i-1][j][k][0] + r[i], dp[i][j][1][0]);
                                dp[i][j][0][1] = min(dp[i-1][j][k][1], dp[i][j][0][1]);
                            }
                            if (j > 0){
                                dp[i][j][0][1] = min(dp[i][j-1][0][l] + c[j], dp[i][j][0][1]);
                                dp[i][j][1][0] = min(dp[i][j-1][1][l], dp[i][j][1][0]);
                            }
                        }
                    }
                }
            }
        }
        dump(dp);
        for (int k = 0; k < 2; k++){
            for (int l = 0; l < 2; l++){
                res = min(res, dp[h-1][w-1][k][l]);
            }
        }
    }
    cout << res << endl;
    return 0;
}