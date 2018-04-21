#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char g[31];
    int N;
    cin >> N;
    int A[N] = {};
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%s " , g);
            if(strcmp(g, "nyanpass") == 0){
                A[j]++;
            }
        }
    }

    int res = -1;
    for(int i = 0; i < N; i++){
        if(A[i] == N - 1){
            if(res == -1){
                res = i+1;
            }else{
                res = -1;
                break;
            }
        }
    }

    cout << res << endl;
    return 0;
}