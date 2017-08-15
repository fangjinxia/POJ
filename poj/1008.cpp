#include <iostream>
#include <sstream>
#include <string>
#include <map>
#include <vector>

using namespace std;

map<string, int> mp;
vector<string> v;

int add_Haab()
{
    mp.insert(pair<string, int>("pop", 1));
    mp.insert(pair<string, int>("no", 2));
    mp.insert(pair<string, int>("zip", 3));
    mp.insert(pair<string, int>("zotz", 4));
    mp.insert(pair<string, int>("tzec", 5));
    mp.insert(pair<string, int>("xul", 6));
    mp.insert(pair<string, int>("yoxkin", 7));
    mp.insert(pair<string, int>("mol", 8));
    mp.insert(pair<string, int>("chen", 9));
    mp.insert(pair<string, int>("yax", 10));
    mp.insert(pair<string, int>("zac", 11));
    mp.insert(pair<string, int>("ceh", 12));
    mp.insert(pair<string, int>("mac", 13));
    mp.insert(pair<string, int>("kankin", 14));
    mp.insert(pair<string, int>("muan", 15));
    mp.insert(pair<string, int>("pax", 16));
    mp.insert(pair<string, int>("koyab", 17));
    mp.insert(pair<string, int>("cumhu", 18));
    mp.insert(pair<string, int>("uayet", 19));
    return 0;
}

int add_v()
{
    v.push_back("imix");
    v.push_back("ik");
    v.push_back("akbal");
    v.push_back("kan");
    v.push_back("chicchan");
    v.push_back("cimi");
    v.push_back("manik");
    v.push_back("lamat");
    v.push_back("muluk");
    v.push_back("ok");
    v.push_back("chuen");
    v.push_back("eb");
    v.push_back("ben");
    v.push_back("ix");
    v.push_back("mem");
    v.push_back("cib");
    v.push_back("caban");
    v.push_back("eznab");
    v.push_back("canac");
    v.push_back("ahau");
    return 0;
}

string Int_to_String(int n)
{
    stringstream stream;
    stream << n;  //nÎªintÀàĞÍ
    return stream.str();
}
int main ()
{
    add_Haab();
    add_v();

    int n;
    cin >> n;
    cout << n << endl;
    while(n--){
        string d, m;
        int y;
        cin >> d >> m >> y;

        int days = 0;
        for(int i = 0; i < d.length()-1; ++i){
            days *= 10;
            days += d[i] - '0';
        }
        days += (mp[m]<19) ? (mp[m]-1)*20 : 360;
        days += y*365;

        int year = days / 260;
        days -= (260*year);
        string day_name = v[days % 20];
        int day_num = days % 13 + 1;

        string res =  Int_to_String(day_num) + " " + day_name + " " + Int_to_String(year);
        cout << res << endl;
    }

    return 0;
}

