#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> f(int n){
    vector<vector<int>> ret(n, vector<int>(n, 0));
    int now = 1, i = 0, j = n/2;
    while(now <= n*n){
        if(ret[i][j])   i = (i+2)%n, j = (j-1+n)%n;
        ret[i][j] = now++;
        i = (i-1+n)%n, j = (j+1)%n;
    }
    return ret;
}

vector<vector<int>> g(int n){
    vector<vector<int>> ret(n, vector<int>(n, 0));
    vector<bool> used(n*n+1, 0);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i%4 == 0 || i%4 == 3){
                if(j%4 == 0 || j%4 == 3)    ret[i][j] = i*n+j+1, used[ret[i][j]] = true;
            }else if(i%4 == 1 || i%4 == 2){
                if(j%4 == 1 || j%4 == 2)    ret[i][j] = i*n+j+1, used[ret[i][j]] = true;
            }
        }
    }
    int now = 1;
    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            if(ret[i][j])   continue;
            while(used[now])    now++;
            ret[i][j] = now++;
        }
    }
    return ret;
}

int lux[3][2][2] = {
    {{4, 1}, {2, 3}},
    {{1, 4}, {2, 3}},
    {{1, 4}, {3, 2}}
};

vector<vector<int>> h(int n){
    vector<vector<int>> ret(n, vector<int>(n, 0));
    vector<vector<int>> ing = f(n/2);
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            ing[i][j] = (ing[i][j]-1)*4;
        }
    }
    for(int i = 0; i < n/2; i++){
        for(int j = 0; j < n/2; j++){
            int ind;
            if(i <= n/2/2)          ind = j==n/2/2&&i==n/2/2;
            else if(i > n/2/2+1)    ind = 2;
            else                    ind = !(j==n/2/2&&i==n/2/2+1);
            for(int k = 0; k < 2; k++){
                for(int l = 0; l < 2; l++){
                    ret[i*2+k][j*2+l] = ing[i][j]+lux[ind][k][l];
                }
            }
        }
    }
    return ret;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> v;
    if(n%2 == 1)        v = f(n);
    else if(n%4 == 0)   v = g(n);
    else                v = h(n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << v[i][j] << " \n"[j==n-1];
        }
    }
    return 0;
}