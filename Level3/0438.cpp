#include<iostream>
using namespace std;
typedef long long ll;

void answer(ll a, ll b){
    int add = 0, sub = 0;
    if(a < 0){
        for(int i = 0; i < abs(a); i++) cout << "c";
        sub += (int)abs(a);
    }
    if(b < 0){
        for(int i = 0; i < abs(b); i++) cout << "w";
        sub += (int)abs(b);
    }
    if(a > 0){
        for(int i = 0; i < abs(a); i++) cout << "c";
        add += (int)abs(a)-1;
    }
    if(b > 0){
        for(int i = 0; i < abs(b); i++) cout << "w";
        if(add) add += 1;
        add += (int)abs(b)-1;
    }
    while(add-- > 0)    cout << "C";
    while(sub-- > 0)    cout << "W";
    cout << endl;
}

int main(){
    int x, y, z;
    cin >> x >> y >> z;
    
    if(z == 0){
        cout << "ccW" << endl;
        return 0;
    }  
    
    if(x == 0 && y == 0){
        if(z == 0)  cout << "c" << endl;
        else        cout << "NO" << endl;
        return 0;
    }

    if(x == 0 || y == 0){
        if(z%(max(x,y)) > 0 || z/(max(x,y)) > 5000)  cout << "NO" << endl;
        else{
            char c = x > y ? 'c' : 'w';
            for(int i = 0; i < z/max(x,y); i++)    cout << c;
            for(int i = 1; i < z/max(x,y); i++)    cout << "C";
            cout << endl;
        }
        return 0;
    }

    for(ll a = -5000; a <= 5000; a++){
        if(abs(z-a*x)%y)   continue;
        if(2*abs(a) + 2*(abs(z-a*x)/y) - 1 <= 10000){
            answer(a, (z-a*x)/y);
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}