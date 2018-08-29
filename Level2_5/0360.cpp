#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool ask(vector<int> v){
    for(int i = 0; i < 5; i++){
        if((v[i]-v[i+1])*(v[i+2]-v[i+1]) <= 0 || v[i] >= v[i+2])    return false;
    }
    return true;
}

int main(){
    vector<int> v(7);
    for(int i = 0; i < 7; i++)  cin >> v[i];
    sort(v.begin(), v.end());

    bool found = false;
    do{
        if(ask(v))      found = true;
    }while(!found && next_permutation(v.begin(), v.end()));

    if(found)   cout << "YES" << endl;
    else        cout << "NO" << endl;

    return 0;
}