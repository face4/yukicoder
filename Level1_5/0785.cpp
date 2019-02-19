#include<iostream>
using namespace std;

int main(){
    string r, g, b;
    cin >> r >> g >> b;
    int s, t, u;
    if(r == "NONE"){
        s = 16*16;
    }else{
        s = (16-(r.length()+1)/2)*(16-(r.length()+1)/2);
    }
    if(g == "NONE"){
        t = 16*16;
    }else{
        t = (16-(g.length()+1)/2)*(16-(g.length()+1)/2);
    }
    if(b == "NONE"){
        u = 16*16;
    }else{
        u = (16-(b.length()+1)/2)*(16-(b.length()+1)/2);
    }
    cout << s*t*u << endl;
    return 0;
}