#include<iostream>
using namespace std;

#define inRange(x, a, b)    a <= x && x < b
#define N 50

int main(){
    int h, w;
    cin >> h >> w;

    char mat[N][N];
    bool judge = true;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> mat[i][j];
            if(mat[i][j] == '#')   judge = false;
        }
    }

    if(judge){
        cout << "NO" << endl;
        return 0;
    }

    for(int di = 0; !judge && di < h; di++){
        for(int dj = -w+1; !judge && dj < w; dj++){
            
            if(di == 0 && dj == 0)  continue;

            int check[N][N] = {};
            bool inner = true;

            for(int i = 0; inner && i < h; i++){
                for(int j = 0; inner && j < w; j++){
                    if(mat[i][j] == '#' && check[i][j] == 0){
                        int ni = i + di;
                        int nj = j + dj;
                        if(inRange(ni, 0, h) && inRange(nj, 0, w) && mat[ni][nj] == '#' && check[ni][nj] == 0){
                            check[i][j] = 1;
                            check[ni][nj] = 1;
                        }else{
                            inner = false;
                        }
                    }
                }
            }

            if(inner)   judge = true;
        }
    }

    if(judge)   cout << "YES" << endl;
    else        cout << "NO" << endl;

    return 0;
}