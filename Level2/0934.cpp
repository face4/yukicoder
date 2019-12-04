#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<int> ans;
    for(int i = 1; i <= n; i++){
        cout << "? " << n-1 << endl;
        bool b = true;
        for(int j = 1; j <= n; j++){
            if(i == j)  continue;
            if(!b)  cout << " ";
            b = false;
            cout << j;
        }
        cout << endl << flush;
        int ret;
        cin >> ret;
        if(ret == 0)    ans.insert(i);
    }
    cout << "! " << ans.size() << endl;
    for(auto it = ans.begin(); it != ans.end(); it++){
        if(it != ans.begin())   cout << " ";
        cout << *it;
    }
    cout << endl;
    return 0;
}