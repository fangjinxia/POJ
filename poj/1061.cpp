#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
long long gcd(long long a, long long b)
{
    return b == 0 ? a : gcd(b, a%b);
}

void exgcd(long long a, long long b, long long &x, long long &y)
{
    if(b == 0){
        x = 1;
        y = 0;
    }
    else{
        exgcd(b, a%b, x, y);
        long long tmp = x;
        x = y;
        y = tmp - a / b * y;
    }
}

int main ()
{
    long long s, t, m, n, L, x, y;
    cin >> s >> t >> m >> n >> L;

    long long p = (m - n + L) % L;
    long long q = (t - s + L) % L;
    long long g = gcd(p, L);
    if(q % g != 0){
        cout << "Impossible" << endl;
    }
    else{
        exgcd(p/g, L/g, x, y);
        cout << (x * (q/g) % L + L) % L << endl;
    }
    return 0;
}