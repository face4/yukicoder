#include<iostream>
using namespace std;

int main(){
    string key = "0000000000";
    int maxscore, nextnum, judgeN;
    string tmpkey,judgeS;

    for(int i = 0; i < 10; i++){
        maxscore = -1;
        tmpkey = key;
        for(int j = 0; j < 10; j++){
            nextnum = (key[i]-'0'+1)%10;
            key[i] = (char)('0'+nextnum);
            cout << key << endl << flush;
            cin >> judgeN >> judgeS;
            if(judgeS == "unlocked")    return 0;

            if(judgeN > maxscore){
                maxscore = judgeN;
                tmpkey = key;
            }
        }
        key = tmpkey;
    }
}