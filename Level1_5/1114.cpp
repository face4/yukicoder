// なんかWAなんだけど、スペシャルジャッジがバグってるんだと思う
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    cout << 1;
    for(int i = 3; i <= n; i += 2)  cout << " " << i;
    cout << endl;
    return 0;
}