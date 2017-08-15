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
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    const int mod = 1e9;
    //处理数据
    for(int k = 1; k <= 22; ++k){
        for(int i = 2; i <= n; ++i){
            int tmp = 1 << (k-1);
            if(i >= tmp){
                dp[i] += dp[i-tmp];
            }
            if(dp[i] >= mod)
                dp[i] %= mod;
        }
    }

    cout << dp[n] << endl;
    return 0;
}

