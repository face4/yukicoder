#include<iostream>
#include<stack>
using namespace std;

int main(){
    int h, w, n;
    cin >> h >> w >> n;

    char c;
    int s;
    stack<pair<char,int>> manip;
    for(int i = 0; i < n; i++){
        cin >> c >> s;
        manip.push({c,s});
    }

    int x = 0, y = 0;
    while(!manip.empty()){
        pair<char,int> p = manip.top(); manip.pop();
        if(p.first == 'R' && x == p.second){
            y--;
            if(y < 0)   y = w-1;
        }else if(p.first == 'C' && y == p.second){
            x--;
            if(x < 0)   x = h-1;
        }
    }

    if((x+y)%2 == 0)    cout << "white" << endl;
    else                cout << "black" << endl;
    
    return 0;
}