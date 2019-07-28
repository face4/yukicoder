#include<iostream>
#include<vector>
using namespace std;

vector<int> defeat[300];

int ask(int x, int y){
    cout << "? " << x << " " << y << endl << flush;
    int ret;
    cin >> ret;
    if(ret == x)    defeat[x].push_back(y);
    else            defeat[y].push_back(x);
    return ret;
}

void answer(int x){
    cout << "! " << x << endl << flush;
}

void shrink(vector<int> &a){
    while(a.size() > 2){
        vector<int> b;
        int pos = 0;
        while(pos+1 < a.size()){
            b.push_back(ask(a[pos], a[pos+1]));
            pos += 2;
        }
        if(pos < a.size())  b.push_back(a[pos]);
        a = b;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 1; i <= n; i++) a.push_back(i);
    shrink(a);
    int top = ask(a[0], a[1]);
    shrink(defeat[top]);
    if(defeat[top].size() == 1){
        answer(defeat[top][0]);
    }else{
        answer(ask(defeat[top][0], defeat[top][1]));
    }
    return 0;
}