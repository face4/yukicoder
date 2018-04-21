#include<iostream>
using namespace std;

int main(){
    int n, res = 0, h1,m1,h2,m2;
    cin >> n;
    while(n-- > 0){
        scanf("%d:%d %d:%d", &h1, &m1, &h2, &m2);
        if(h1*60+m1 > h2*60+m2) h2 += 24;
        res += (h2-h1) * 60;
        res += (m2-m1);
    }
    cout << res << endl;
    return 0;
}