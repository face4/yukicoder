#include<iostream>
#include<vector>
using namespace std;

int main(){
    int h, w;
    cin >> h >> w;
    char sky[h][w];
    vector<pair<int,int>> pos;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> sky[i][j];
            if(sky[i][j] == '*')    pos.push_back({i,j});
        }
    }

    pair<int,int> p1 = pos[0];
    pair<int,int> p2 = pos[1];
    
    if(p1.first == p2.first){
        for(int i = 0; i < h; i++){
            if(i != p1.first){
                sky[i][p1.second] = '*';
                break;
            }
        }
    }else{
        for(int i = 0; i < w; i++){
            if(i != p1.second){
                sky[p1.first][i] = '*';
                break;
                cout << p1.first << " : " << i << endl;
            }
        }
    }

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cout << sky[i][j];
        }
        cout << endl;
    }

    return 0;
}