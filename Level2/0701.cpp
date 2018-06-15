#include<iostream>
using namespace std;

string enc(int x){
    string ret = "";
    while(x > 0){
        char a = (char)('a'+x%26);
        string next(1,a);
        ret = next + ret;
        x /= 26;
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    string now = "a";
    for(int i = 0; i < n-1; i++){
        cout << "a"+enc(i)+"a" << endl;
    }
    cout << "an" << endl;
    
    return 0;
}