#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

struct Boy{
    string s;
    int height, weight;
};

bool comp(const Boy& a, const Boy& b){
    if(a.height != b.height){
        return a.height > b.height;
    }else{
        return a.weight < b.weight;
    }
}

int main(){
    vector<Boy> boys(3);
    for(int i = 0; i < 3; i++){
        boys[i].s = (char)('A'+ i);
        cin >> boys[i].height >> boys[i].weight; 
    }

    sort(boys.begin(), boys.end(), comp);
    for(int i = 0; i < 3; i++){
        cout << boys[i].s << endl;
    }

    return 0;
}