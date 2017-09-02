#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;
///< 枚举
const double EPS = 1e-6;

int main ()
{
    string s;
    while(cin >> s){
        if(s == "*")
            break;
        int len = s.length();
        if(len <= 2){
            cout << s << " is surprising." << endl;
            continue;
        }

        bool ok = true;
        for(int i = 1; i < len-1; ++i){///<(i-1)-pairs
            map<string, int> mp;
            for(int j = 0; (i+j) < len; ++j){
                string str = "";
                str += s[j];
                str += s[i+j];
                //cout << str << endl;
                ++mp[str];
                if(mp[str] >= 2){
                    ok = false;
                    break;
                }
            }
            if(!ok)
                break;
        }

        if(!ok){
            cout << s << " is NOT surprising." << endl;
        }
        else{
            cout << s << " is surprising." << endl;
        }
    }

    return 0;
}
