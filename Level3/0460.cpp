// 自力AC
#include<iostream>
#include<vector>
using namespace std;
#define inRange(x,a,b) (a <= x && x < b)

int h, w;

void flip(int i, int j, vector<vector<int>> &v){
    for(int k = -1; k <= 1; k++){
        for(int l = -1; l <= 1; l++){
            if(inRange(i+k, 0, h)&&inRange(j+l, 0, w)){
                v[i+k][j+l] = 1-v[i+k][j+l];
            }
        }
    }
}

int main(){
    cin >> h >> w;
    vector<vector<int>> v(h, vector<int>(w, 0));
    for(int i = 0; i < h*w; i++)    cin >> v[i/w][i%w];
    int ans = 1<<30;
    for(int s = 0; s < 1<<(h+w-1); s++){
        int tmp = 0;
        vector<vector<int>> t = v;
        for(int j = 0; j < w; j++){
            if((s>>j)&1){
                tmp++;
                flip(0, j, t);
            }
        }
        for(int i = 1; i < h; i++){
            if((s>>(w+i-1))&1){
                tmp++;
                flip(i, 0, t);
            }
        }
        for(int i = 1; i < h; i++){
            for(int j = 1; j < w; j++){
                if(t[i-1][j-1]){
                    tmp++;
                    flip(i, j, t);
                }
            }
        }
        bool valid = true;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < w; j++){
                valid &= t[i][j]==0;
            }
        }
        if(valid)   ans = min(ans, tmp);
    }
    if(ans == 1<<30)    cout << "Impossible" << endl;
    else                cout << ans << endl;
    return 0;
}