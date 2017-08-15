#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

int getIvs(string s, int len)
{
    int res = 0;
    for(int i = 0; i < len-1; ++i){
        for(int j = i+1; j < len; ++j){
            if(s[j] < s[i])
                ++res;
        }
    }

    return res;
}

int main ()
{
    int len, n;
    string str;
    cin >> len >> n;
    multimap<int, string> mp;

    while(n--){
        cin >> str;
        //º∆À„inversions
        int ivs = getIvs(str, len);
        mp.insert(pair<int, string>(ivs, str));
    }

    multimap<int, string>::iterator pos;
    for(pos = mp.begin(); pos != mp.end(); ++pos){
        cout << pos->second << endl;
    }
    return 0;
}
