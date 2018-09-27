#include<iostream>
using namespace std;

int main(){
    int gx, gy, n, f, x, y, c;
    cin >> gx >> gy >> n >> f;

    int dist[101][101] = {};
    for(int i = 1; i <= 100; i++)   dist[0][i] = dist[0][i-1] + f;
    for(int i = 1; i <= 100; i++){
        for(int j = 0; j <= 100; j++){
            dist[i][j] = dist[i-1][j] + f;
        }
    }

    for(int q = 0; q < n; q++){
        cin >> x >> y >> c;
        if((x+y) * f < c)   continue;
        for(int i = 100-x; i >= 0; i--){
            for(int j = 100-y; j >= 0; j--){
                dist[i+x][j+y] = min(dist[i+x][j+y], dist[i][j] + c);
            }
        }
    }

    cout << dist[gx][gy] << endl;
    
    return 0;
}