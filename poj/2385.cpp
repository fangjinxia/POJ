#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

//动态规划
int main ()
{
    int T, W;
    cin >> T >> W;
    vector<int> v(T, 0);
    //d[i][j]表示到达i时刻，已换树j次，位于j%2+1号树下。
    //d[i][j]=max(d[i-1][j],d[i-1][j-1])+((j&1)+1==a[i])。
    vector<vector<int>> dp(T, vector<int>(W+1, 0));
    for(int i = 0; i < T; ++i){
        cin >> v[i];
        dp[i][0] = (i ? dp[i-1][0] : 0)+ int(v[i] == 1);
    }

    for(int i = 0; i <= W; ++i){
        dp[0][i] = ((i&1)+1 == v[0]);
    }

    for(int i = 1; i < T; ++i){
        for(int j = 1; j <= W; ++j){
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + ((j&1)+1 == v[i]);
        }
    }


    cout << *max_element(dp[T-1].begin(), dp[T-1].end()) << endl;
    return 0;
}