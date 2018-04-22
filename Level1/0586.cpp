#include<iostream>
#include<set>
using namespace std;

int main(){
    set<int> reserve;
    int p1, p2, n, x, db = 0;
    cin >> p1 >> p2 >> n;
    while(n-- > 0){
        cin >> x;
        if(reserve.find(x) != reserve.end()){
            db++;
        }else{
            reserve.insert(x);
        }
    }

    cout << (db * (p1+p2)) << endl;
    return 0;
}