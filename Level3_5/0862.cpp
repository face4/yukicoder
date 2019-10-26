#include<iostream>
#include<vector>
using namespace std;

#define inRange(x,a,b) (a <= x && x <= b)

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> ans;
    int pos = 2;
    if(x == 1)  pos = 10;
    while(n-ans.size() > 4){
        if(!inRange(x,pos,pos+3)){
            for(int i = 0; i < 4; i++)  ans.push_back(pos+i);
        }
        pos += 4;
    }
    int base = (x-2)/4*4+2;
    vector<int> res({1, base, base+1, base+2, base+3});
    if(x == 1)  res = vector<int>({1, 2, 3, 4, 7});
    for(int i = 1; i < 1<<5; i++){
        vector<int> tmp;
        int xo = 0;
        for(int j = 0; j < 5; j++){
            if((i>>j)&1)    tmp.push_back(res[j]), xo ^= res[j];
        }
        if(tmp.size() != n-ans.size() || xo != x)   continue;
        for(int j : tmp)    ans.push_back(j);
        for(int j : ans)    cout << j << endl;
        return 0;
    }
}