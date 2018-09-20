#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v;
    for(int i = 1; i*(i+1) <= 20000000; i++)    v.push_back(i*(i+1)/2);

    int n;
    cin >> n;

    if(*lower_bound(v.begin(), v.end(), n) == n){
        cout << 1 << endl;
    }else{
        bool judge = false;
        for(int x : v){
            if(x > n)   break;
            if(*lower_bound(v.begin(), v.end(), n-x) == n-x)    judge = true;
        }
        if(judge)   cout << 2 << endl;
        else        cout << 3 << endl;
    }

    return 0;
}