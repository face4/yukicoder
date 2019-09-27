#include<iostream>
using namespace std;

int main(){
    bool np[64] = {};
    np[0] = np[1] = true;
    for(int i = 2; i < 64; i++){
        if(np[i])   continue;
        for(int j = i+i; j < 64; j+=i)  np[j] = true;
    }

    auto f = [=](int x)->string{
        if(x < 2)   return to_string(x);
        if(!np[x])  return "Sosu!";
        int sum = -x;
        for(int i = 1; i*i <= x; i++){
            if(i*i == x)    return "Heihosu!";
            if(i*i*i == x)  return "Ripposu!";
            if(x%i) continue;
            sum += i + x/i; // absolutely i and x/i are different
        }
        return sum == x ? "Kanzensu!" : to_string(x);
    };

    int n;
    scanf("%d", &n);
    cout << f(n) << endl;
    return 0;
}