#include<iostream>
using namespace std;

int main(){
    long long h, w, n, k;
    cin >> h >> w >> n >> k;
    cout << ((h+w-1)%n == k%n ? "YES" : "NO") << endl;
    return 0;
}