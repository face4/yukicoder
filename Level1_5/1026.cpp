#include<iostream>
#include<list>
using namespace std;

int main(){
    int n;
    cin >> n;
    list<char> l;
    while(n--){
        int t;
        char c;
        cin >> t >> c;
        if(t)   l.push_front(c);
        else    l.push_back(c);
    }
    for(char c : l) cout << c;
    cout << endl;
    return 0;
}