#include <iostream>
#include <cstdio>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

int main ()
{
    int n;
    cin >> n;

    int k = 1;
    double const M_PI=3.14159265;
    while(n--){
        double x, y;
        cin >> x >> y;
        int res = ceil(M_PI * (x*x + y*y) / 100);
        printf("Property %d: This property will begin eroding in year %d.\n", k, res);
        ++k;
    }

    printf("END OF OUTPUT.");

    return 0;
}

