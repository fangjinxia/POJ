#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

//���ֵ�λ�������� log10((double)i) + 1 �����ʽ�����
using namespace std;

///<intתstring
/*
string Int_to_String(int n)
{
    stringstream stream;
    stream << n;  //nΪint����
    return stream.str();
}
*/
//��̬�滮
int main ()
{
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;
    const int mod = 1e9;
    //��������
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

