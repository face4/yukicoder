#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    pair<int,int> p[3], q[3];
    p[0] = {2, 8};  q[0] = {5, 8};
    p[1] = {3, 9};  q[1] = {4, 8};
    p[2] = {7, 9};  q[2] = {6, 8};
    while(n-- > 0){
        int x, y, tx, ty;
        cin >> x >> y >> tx >> ty;
        for(int i = 0; i < 3; i++){
            if(p[i].first == x && p[i].second == y){
                p[i].first = tx, p[i].second = ty;
                break;
            }
        }
    }
    bool valid = true;
    for(int i = 0; i < 3; i++)  valid &= (p[i].first == q[i].first && p[i].second==q[i].second);
    cout << (valid ? "YES" : "NO") << endl;
    return 0;
}