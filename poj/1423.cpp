#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;
///<求解一个数k的阶乘的位数
///<log10(double(k)) + 1

vector<int> v(10000010, 0);

int main ()
{
    int n;
    cin >> n;
    double cur = 0;
    for(int i = 1; i <= 10000000; ++i){
        cur += log10((double)i);
        v[i] = cur;        
    }
    while(n--){
        int k;
        cin >> k;
        cout << v[k]+1 << endl;

    }
    return 0;
}