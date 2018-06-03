#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

vector<int> ans;
vector<int> nodes;

void constructTree(int l, int r){
    if(r-l < 2){
        ans.push_back(nodes[l]);
        if(r != l)  ans.push_back(nodes[r]);
        return;
    }

    int mid = (l+r)/2;
    ans.push_back(nodes[mid]);    
    constructTree(l, mid-1);
    constructTree(mid+1, r);
}

int main(){
    int k;
    cin >> k;
    
    int n = pow(2,k)-1;
    ans.push_back(n);

    for(int i = 1; i < n; i++){
        nodes.push_back(i);
    }

    // arguments are indices
    constructTree(0, n-2);

    for(int i = 0; i < n; i++){
        if(i)   cout << " ";
        cout << ans[i];
    }
    cout << endl;

    return 0;
}