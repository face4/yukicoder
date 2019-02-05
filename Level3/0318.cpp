#include<iostream>
#include<map>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> a(n);
    map<int,int> last;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        last[a[i]] = i;
    }

    set<int> appear;
    for(int i = 0; i < n; i++){
        appear.insert(a[i]);
        cout << *appear.rbegin() << " \n"[i == n-1];
        if(last[a[i]] == i) appear.erase(a[i]);
    }

    return 0;
}