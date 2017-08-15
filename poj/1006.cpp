#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool cmpFunc(int i)
{
    return (i == 3);
}

int main ()
{
    int peiod[3] = {23, 28, 33};
    int p, e, i, d;
    int n = 1;
    const int M = 21252+365;
    while(scanf("%d %d %d %d", &p, &e, &i, &d) != EOF){
        if((e == -1) && (i == -1) && (d == -1) && (p == -1)){
            break;
        }
        vector<int> v(M+1, 0);
        int init[3] = {p, e, i};
        for(int i = 0; i < 3; ++i){
            int k = init[i]%peiod[i];
            do{
                ++v[k];
                k += peiod[i];
            }while(k <= M);
        }

        int res = 0;
        for(int i = d; i <= M; ++i){
            if(v[i] == 3){
                res = i-d;
                break;
            }
        }
        res = (res == 0) ? 21252 : res;
        printf("Case %d: the next triple peak occurs in %d days.\n", n, res);
        ++n;
    }

    return 0;
}

