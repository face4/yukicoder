#include<iostream>
#include<cstring>
using namespace std;

typedef long long ll;

string s = "0.1234567891011121314151617181920212223242526272829303132333435363738394041424344454647484950515253545556575859606162636465666768697071727374757677787980818283848586878889909192939495969798991";

ll MAX = 1000000000;

int main(){
    
    ll n;
    cin >> n;
    
    ll carry = 0;
    string res = "";
    for(int i = 18; i >= 0; i--){
        ll part = (ll)(stoll(s.substr(i*10+2, 10)));
        // 誤り if(part < MAX)   part *= 10; 
        part *= n;
        part += carry;
        
        carry = part/(10*MAX);
        part %= (10*MAX);

        string insert = to_string(part);
        while(insert.length() != 10)    insert = "0" + insert;
        res = insert + res;
    }

    cout << carry << "." << res << endl;
    return 0;
}