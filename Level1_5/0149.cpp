#include<iostream>
using namespace std;

int main(){
    int aw, ab, bw, bb, c, d;
    cin >> aw >> ab >> bw >> bb >> c >> d;
    if(c > ab){
        aw -= c-ab;
        bw += c-ab;
    }

    aw += min(bw, d);
    cout << aw << endl;
    return 0;
}