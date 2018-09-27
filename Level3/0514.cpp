#include<iostream>
using namespace std;

int query(int x, int y){
    int ans;
    cout << x << " " << y << endl << flush;
    cin >> ans;
    if(ans == 0)    exit(0);
    return ans;
}

int main(){
    int a = query(0,0);
    int b = query(0,a);
    query(b/2, a-b/2);
}