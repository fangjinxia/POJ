#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    char v[26] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '0', '7', '7', '8', '8', '8', '9', '9', '9', '0'};
    map<string, int> mp;

    while(n--){
        string str;
        cin >> str;
        //scanf("%s", str);
        string res = "";

        for(int i = 0; i < str.length(); ++i){
            if(str[i] == '-')
                continue;

            if(str[i] <= '9')
                res += str[i];
            else
                res += v[str[i] - 'A'];

        }
        res.insert(3, "-");
        ++mp[res];
    }

    bool flag = false;
    map<string, int>::iterator pos;
    for(pos = mp.begin(); pos != mp.end(); ++pos){
        if(pos->second > 1){
            flag = true;
            cout << pos->first << " " << pos->second << endl;
        }
    }

    if(!flag)
        cout << "No duplicates." << endl;

    return 0;
}