#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG_
#include "../../onlinejudge/dump.cpp"
#else
#define dump(...)
#endif

int main(void) {
    srand (time(NULL));
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n = 3000000000;
    // long long n = 100;
    // RGB 012
    vector<int> light;
    light.push_back(1);
    for (long long i = 1; i < n; i++){
        // progress
        if (i % 10000000LL == 0){
            dump((double)i/(double)n);
        }
        int r = rand()%10;
        if (light[light.size()-1] == 0){
            if (r < 8){
                light.push_back(0);
            } else {
                light.push_back(1);
            }
            continue;
        }
        if (light[light.size()-1] == 1){
            if (r < 9){
                light.push_back(1);
            } else {
                light.push_back(2);
            }
            continue;
        }
        if (light[light.size()-1] == 2){
            if (r < 9){
                light.push_back(2);
            } else {
                light.push_back(0);
            }
            continue;
        }
    }
    vector<long long> res(6);
    vector<string> title = {"RR", "RG", "GG", "GB", "BB", "BR"};
    for (long long i = 0; i < n-2; i++){
        int l1 = light[i];
        i++;
        int l2 = light[i];
        if (l1 == 0 && l2 == 0) res[0]++; // RR
        if (l1 == 0 && l2 == 1) res[1]++; // RG
        if (l1 == 1 && l2 == 1) res[2]++; // GG
        if (l1 == 1 && l2 == 2) res[3]++; // GB
        if (l1 == 2 && l2 == 2) res[4]++; // BB
        if (l1 == 2 && l2 == 0) res[5]++; // BR
    }
    for (int i = 0; i < 6; i++){
        cout << title[i] << " " << ((double)res[i] / (double)n) * 2.0 << endl;
    }
    vector<long long> res1(9);
    long long count = 0;
    vector<string> title1 = {"RG", "RRG", "RRR", "GB", "GGB", "GGG", "BR", "BBR", "BBB"};
    // RG RRG RRR GB GGB GGG BR BBR BBB
    // 0  1   2   3  4   5   6  7   8
    for (long long i = 0; i < n-5; i++){
        int l1 = light[i];
        if (l1 == 0){ // R
            i++;
            int l2 = light[i];
            if (l2 == 1){ // RG
                res1[0]++;
                count++;
                continue;
            }
            if (l2 == 0){ // RR
                i++;
                int l3 = light[i];
                if (l3 == 1){
                    res1[1]++;
                    count++;
                    continue;
                } else {
                    res1[2]++;
                    count++;
                    continue;
                }
            }
        }
        if (l1 == 1){ // G
            i++;
            int l2 = light[i];
            if (l2 == 2){ // GB
                res1[3]++;
                count++;
                continue;
            }
            if (l2 == 1){ // GG
                i++;
                int l3 = light[i];
                if (l3 == 2){
                    res1[4]++; // GGB
                    count++;
                    continue;
                } else {
                    res1[5]++; // GGG
                    count++;
                    continue;
                }
            }
        }
        if (l1 == 2){ // B
            i++;
            int l2 = light[i];
            if (l2 == 0){ // BR
                res1[6]++;
                count++;
                continue;
            }
            if (l2 == 2){ // BB
                i++;
                int l3 = light[i];
                if (l3 == 0){
                    res1[7]++; // BBR
                    count++;
                    continue;
                } else {
                    res1[8]++; // BBB
                    count++;
                    continue;
                }
            }
        }
    }
    cout << endl;
    for (int i = 0; i < 9; i++){
        cout << title1[i] << " " << (double)res1[i] / (double)count << endl;
    }
    return 0;
}