#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
using namespace std;

int main(){
    int n, s;
    cin >> n >> s;

    vector<int> v(n);
    for(int i = 0; i < n; i++)  cin >> v[i];

    vector<pair<int,set<int>>> vp;
    int n1 = n/2;
    for(int i = 0; i < 1<<n1; i++){
        set<int> tmp;
        int tmpval = 0;
        for(int j = 0; j < n1; j++){
            if((i>>j)&1){
                tmp.insert(j+1);
                tmpval += v[j];
            }
        }
        vp.push_back({tmpval, tmp});
    }
    sort(vp.begin(), vp.end());
    
    vector<set<int>> ans;
    for(int i = 0; i < 1<<(n-n1); i++){
        set<int> tmp;
        int tmpval = 0;
        for(int j = 0; j < n-n1; j++){
            if((i>>j)&1){
                tmp.insert(n1+j+1);
                tmpval += v[n1+j];
            }
        }
        if(tmpval > s)  continue;
        
        set<int> emp;
        int l = lower_bound(vp.begin(), vp.end(), make_pair(s-tmpval, emp)) - vp.begin();
        int r = lower_bound(vp.begin(), vp.end(), make_pair(s-tmpval+1, emp)) - vp.begin();
        r--;

        while(l <= r){
            set<int> copy = vp[l].second;
            copy.insert(tmp.begin(), tmp.end());
            ans.push_back(copy);
            l++;
        }
    }

    sort(ans.begin(), ans.end());

    for(set<int> t : ans){
        for(auto it = t.begin(); it != t.end(); it++){
            if(it != t.begin()) cout << " ";
            cout << *it;
        }
        cout << endl;
    }

    return 0;
}