#include<iostream>
using namespace std;

int grundy[500] = {};
bool done[500] = {};
int l, d;

int dfs(int x){
    if(done[x]) return grundy[x];
    done[x] = true;
    bool memo[500] = {};
    for(int i = 1; i < x/3; i++){
        for(int j = i+1; x-i-j > j; j++){
            if(x-i-j-i > d) continue;
            memo[dfs(i)^dfs(j)^dfs(x-i-j)] = true;
        }
    }
    for(int i = 0; i < 500; i++){
        if(!memo[i])    return grundy[x] = i;
    }
    return -1;  // unreachable
}

int main(){
    cin >> l >> d;
    cout << (dfs(l)==0 ? "matsu" : "kado") << endl;
    return 0;
}