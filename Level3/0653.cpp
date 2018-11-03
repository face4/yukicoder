#include<iostream>
#include<algorithm>
using namespace std;
#define inRange(x,a,b) (a <= x && x <= b)

void no(){
    cout << "No" << endl;
    exit(0);
}

int main(){
    string s;
    cin >> s;

    reverse(s.begin(), s.end());

    if(s.length() == 1) no();

    int tmp = s[0]-'0' + 10*(s[1]-'0');

    if(tmp < 10 || !inRange(tmp%10, 2, 4))  no();

    tmp /= 10;
    tmp--;
    
    bool alone = false;
    
    for(int i = 2; i < s.length(); i++){
        tmp += (s[i]-'0')*10;
        if(!inRange(tmp%10, 2, 4) && !alone)    alone = true;

        if(alone){
            if(inRange(tmp%10, 6, 7)){
                tmp /= 10;
            }else{
                no();
            }
        }

        if(!alone){
            if(inRange(tmp%10, 2, 4)){
                tmp /= 10;
                tmp--;
            }else{
                no();
            }
        }

    }
    
    if(tmp == 0 || inRange(tmp, 6, 7)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}