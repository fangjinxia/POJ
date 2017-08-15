#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

//数字的位数可以用 log10((double)i) + 1 这个公式求出来
using namespace std;

///<int转string
/*
string Int_to_String(int n)
{
    stringstream stream;
    stream << n;  //n为int类型
    return stream.str();
}
*/
//动态规划
int main ()
{
    int n;
    cin >> n;
    int N = n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    //读入数据
    int row = 0;
    while(n--){
        for(int i = 0; i < N-n; ++i)
            cin >> dp[row][i];
        ++row;
    }
    //处理数据
    for(int i = 1; i < N; ++i){//行
        for(int j = 0; j <= i; ++j){//列
            if(j == 0){
                dp[i][j] += dp[i-1][j];
            }
            else if(j == i){
                dp[i][j] += dp[i-1][j-1];
            }
            else
                dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
        }
    }

    cout << *max_element(dp[N-1].begin(), dp[N-1].end()) << endl;
    return 0;
}

