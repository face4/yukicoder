#include<iostream>
using namespace std;

int main(){
    int a[6];
    for(int i = 0; i < 6; i++)  cin >> a[i];
    int g;
    cin >> g;
    int b[6] = {500, 100, 50, 10, 5, 1};
    for(int i = 0; i < 6; i++){
        int take = min(g/b[i], a[i]);
        g -= take * b[i];
    }
    cout << (g == 0 ? "YES" : "NO") << endl;
    return 0;
}