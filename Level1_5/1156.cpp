#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;

int main(){
    int n;
    cin >> n;
    n--;
    int x[3][10] = {
        {100, 10-1001, 1-10, 100, 10, 1, -100, 0, 0, 0},
        {1100, 10-100, 1-10, 1000, 100, 10, 1, -10000, -1000, -1},
        {100000, 10000-100000, 1000, 1100-10010, 10-100, 101, 10000, 10, 1, -1001}
    };
    int y[3][10] = {
        {0,1001,10,0,0,0,100,0,0,0},
        {0,100,10,0,0,0,0,10000,1000,1},
        {0,100000,0,10010,100,0,0,0,0,1001}
    };
    vector<int> ng[3];
    ng[0] = {0, 1, 3};
    ng[1] = {0, 3, 7};
    ng[2] = {0, 1, 6};
    vector<int> v(10);
    iota(v.begin(), v.end(), 0);
    swap(v[0], v[1]);   // needless.
    do{
        int sum = 0;
        for(int i = 0; i < 10; i++) sum += v[i]*x[n][i];
        if(sum) continue;
        bool f = false;
        for(int i : ng[n]){
            f |= v[i]==0;
        }
        if(f)   continue;
        for(int i = 0; i < 10; i++) sum += v[i]*y[n][i];
        cout << sum << endl;
        return 0;
    }while(next_permutation(v.begin(), v.end()));
}