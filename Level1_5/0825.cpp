#include<iostream>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    auto opt = [](int x)->int{
        return x%10 + x/10;
    };
    int ans = 1<<30;
    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            int tmp = i + 10*j;
            for(int k = 1; k <= tmp; k++){
                int num = a+b-i-j+opt(tmp-k);
                if(num == c)    ans = min(ans, k);
            }
        }
    }
    if(ans == 1<<30)    cout << "Impossible" << endl;
    else                cout << ans << endl;
    return 0;
}