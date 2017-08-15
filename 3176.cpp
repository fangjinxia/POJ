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
    int N = n;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    //��������
    int row = 0;
    while(n--){
        for(int i = 0; i < N-n; ++i)
            cin >> dp[row][i];
        ++row;
    }
    //��������
    for(int i = 1; i < N; ++i){//��
        for(int j = 0; j <= i; ++j){//��
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

