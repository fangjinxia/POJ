#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

int main ()
{
    int n;
    cin >> n;
    cout << "INTERSECTING LINES OUTPUT" << endl;

    while(n--){
        int x1, y1, x2, y2, x3, y3, x4, y4;
        cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
        if((y2-y1) * (x4-x3) == (y4-y3) * (x2-x1)){///<两条直线斜率相同
            if((y2-y1) * (x3-x1) == (y3-y1) * (x2-x1)){
                cout << "LINE" << endl;
            }
            else{
                cout << "NONE" << endl;
            }
        }
        else{
            double a = x2-x1, b = y2-y1, c = x4-x3, d = y4-y3, x, y;
            if(a == 0){
                x = x1;
                y = (x1-x3) * d / c + y3;
            }
            else if(c == 0){
                x = x3;
                y = (x3-x1) * b / a + y1;
            }
            else{
                x = (y3 - y1 + b * x1 / a - d * x3 / c) / (b / a - d / c);
				y = (x - x1) * b / a + y1;
            }
            cout << "POINT " << fixed << setprecision(2) << x << " " << y << endl;
        }
    }

    cout << "END OF OUTPUT" << endl;
    return 0;
}