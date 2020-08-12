#include<iostream>
#include<list>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    list<int> l;
    for(int i = 0; i < n; i++){
        int x;  cin >> x;
        l.push_back(x);
    }
    while(m--){
        char c; cin >> c;
        if(c == 'L')    *(++l.begin()) += l.front(), l.pop_front(), l.push_back(0);
        else            *(----l.end()) += l.back(), l.pop_back(), l.push_front(0);
    }
    for(auto it = l.begin(); it != l.end(); it != l.end()){
        cout << *it++, cout << (it == l.end() ? "\n" : " ");
    }
    return 0;
}