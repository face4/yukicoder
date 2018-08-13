#include<iostream>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;

    int a[n];
    for(int i = 0; i < n; i++)  cin >> a[i];

    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j + k < n; j++){
            if(a[j] > a[j+k]){
                cnt++;
                swap(a[j], a[j+k]);
            }
        }
    }

    for(int i = 1; i < n; i++)  if(a[i-1] > a[i])   cnt = -1;

    cout << cnt << endl;

    return 0;
}