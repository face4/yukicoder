#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;

bool isprime(ll a){
    if(a == 1)      return false;
    if(a == 2)      return true;

    if(a%2 == 0)    return false;

    for(ll i = 3; i <= sqrt(a); i+=2){
        if(a%i == 0)    return false;
    }

    return true;
}

int main(){
    ll y, x;
    cin >> y >> x;

    if( (isprime(y) && isprime(x))   || 
        (isprime(y) && isprime(y+1)) ||
        (isprime(x) && isprime(x+1))   ){
        cout << "Second" << endl;
        return 0;
    }

    ll toy = y, tox = x;

    while(1){
        if(toy == 1)        toy++;
        else if(toy%2 == 0) toy++;
        else                toy += 2;
        if(isprime(toy))    break;
    }
    
    while(1){
        if(tox == 1)        tox++;
        else if(tox%2 == 0) tox++;
        else                tox += 2;
        if(isprime(tox))    break;
    }

    ll hands = toy-y + tox-x; // -2

    if(hands % 2 == 0)  cout << "Second" << endl;
    else                cout << "First" << endl;

    return 0;
}