#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v(4);
    for(int i = 0; i < 4; i++)  cin >> v[i];
    sort(v.begin(), v.end());
    for(int i = 1; i < 4; i++){
        if(v[i-1]+1!=v[i]){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}