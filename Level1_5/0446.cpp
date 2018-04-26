#include<iostream>
#include<iostream>

using namespace std;

int main(){
    string s1, s2;
    cin >> s1 >> s2;
    bool result = true;

    while(true){
        if(s1.length() > 5 || s2.length() > 5){
            result = false;
        }
        
        if((s1.length() != 1 && s1[0] == '0') || (s2.length() != 1 && s2[0] == '0')){
            result = false;
        }

        for(int i = 0; i < s1.length(); i++){
            if(s1[i] < '0' || s1[i] > '9'){
                result = false;
            }
        }

        for(int i = 0; i < s2.length(); i++){
            if(s2[i] < '0' || s2[i] > '9'){
                result = false;
            }
        }

        if(!result) break;

        int x = stoi(s1);
        int y = stoi(s2);
        if(x > 12345 || y > 12345){
            result = false;
        }
        break;
    }

    if(result)  cout << "OK" << endl;
    else        cout << "NG" << endl;

    return 0;
}