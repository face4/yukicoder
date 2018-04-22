#include<iostream>
using namespace std;

int main(){
    string s1, s2;
    string yf1, yf2;
    char hand1, hand2;
    cin >> s1 >> yf1 >> hand1;
    cin >> s2 >> yf2 >> hand2;
    if(yf1.size() == yf2.size()){
        if(yf1 == yf2){
            cout << "-1" << endl;
        }else{
            int one, two;
            for(int i = 0; i < yf1.size(); i++){
                one = (int)(yf1[i] - '0');
                two = (int)(yf2[i] - '0');
                if(one != two){
                    if(one > two){
                        cout << s1;
                    }else{
                        cout << s2;
                    }
                    break;
                }
            }
        }
    }else if(yf1.size() > yf2.size()){
        cout << s1;
    }else if(yf1.size() < yf2.size()){
        cout << s2;
    }
    cout << endl;
    return 0;
}