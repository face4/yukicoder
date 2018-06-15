#include<iostream>
#include<stack>
using namespace std;

#define W 3000
#define H 3000

char mat[H+1][W+1];
int cnt = 0;
int h, w;

void floodFill(int i, int j){
    stack<pair<int,int>> S;
    S.push({i,j});

    while(!S.empty()){
        pair<int,int> p = S.top(); S.pop();
        int y = p.first;
        int x = p.second;
        mat[y][x] = '0';

        if(y != 0 && mat[y-1][x] == '1')    S.push({y-1,x});
        if(y != h-1 && mat[y+1][x] == '1')  S.push({y+1,x});
        if(x != 0 && mat[y][x-1] == '1')    S.push({y,x-1});
        if(x != w-1 && mat[y][x+1] == '1')  S.push({y,x+1});
    }

    cnt++;
}

int main(){
    cin >> h >> w;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){ 
            if(mat[i][j]=='1')  floodFill(i,j);
        }
    }

    cout << cnt << endl;
    return 0;
}