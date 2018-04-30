#include<iostream>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a = (int)(s[0] - '0');
    int b = (int)(s[1] - '0');
    int c = (int)(s[2] - '0');
    if(c >= 5){
        b++;
        if(b >= 10){
            b = 0;
            a++;
            if(a >= 10){
                a = 1;
                b = 0;
                s.append("h");
            }
        }
    }

    printf("%d.%d*10^%d\n", a, b, (int)(s.length())-1);
    return 0;
}