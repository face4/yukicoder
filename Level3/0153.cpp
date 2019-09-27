#include<iostream>
#include<set>
using namespace std;

int grundy[101] = {};
bool vis[101] = {};

int f(int x){
    if(x == 1){
        vis[x] = true;
    }else if(x == 2){
        vis[x] = true;
        grundy[x] = 1;
    }
    if(vis[x])  return grundy[x];
    vis[x] = true;
    set<int> s;
    s.insert(f(x/2)^f(x-x/2));
    if(x%3 == 0)    s.insert(f(x/3)^f(x/3)^f(x/3));
    if(x%3 == 1)    s.insert(f(x/3)^f(x/3)^f(x/3+1));
    if(x%3 == 2)    s.insert(f(x/3)^f(x/3+1)^f(x/3+1));
    int num = 0;
    while(s.count(num)) num++;
    return grundy[x] = num;
}

int main(){
    int n;
    cin >> n;
    cout << (f(n) == 0 ? 'B' : 'A') << endl;
    return 0;
}