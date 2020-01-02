#include<iostream>
#include<cstring>
using namespace std;

#define inRange(x,a,b) (a <= x && x < b)

int di[8] = {0,1,0,-1,1,1,-1,-1};
int dj[8] = {1,0,-1,0,1,-1,1,-1};

int way[50][50][4];
bool vis[50][50] = {};

void front(){
    cout << "F" << endl << flush;
}

void right(){
    cout << "R" << endl << flush;
}

void back(){
    cout << "B" << endl << flush;
}

void goal(){
    front();
    string s;
    cin >> s;
    if(s == "20151224") goal();
    exit(0);
}

// 次出力する
void dfs(int i, int j, int dir, int res){
    if(res == 20151224) goal();
    for(int k = 0; k < 4; k++){
        if(res > 0){
            if(res == 20151224) goal();
            int ni = i+di[dir], nj = j+dj[dir];
            if(!vis[ni][nj]){
                vis[ni][nj] = true;
                front();
                cin >> res;
                dfs(ni, nj, dir, res);
            }
        }
        right();
        cin >> res;
        dir = (dir+1)%4;
    }
    back();
    cin >> res;
    return;
}

int main(){
    vis[25][25] = true;
    int dir = 0, res;
    cin >> res;
    dfs(25, 25, 0, res);
}