#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;

    int a[n], b[n], x;
    for(int i = 0; i < n; i++)  cin >> x, a[--x] = i;
    for(int i = 0; i < n; i++)  cin >> b[i], b[i]--;

    set<int> s, res;
    s.insert(-1);    // sentinel
    for(int i = 0; i < n; i++){
        if(*(--(s.end())) < a[b[i]])    res.insert(b[i]);
        s.insert(a[b[i]]);
    }

    for(int x : res)    cout << x+1 << endl;

    return 0;
}