// 紆余曲折の末なんとかAC.頭悪い実装な気がする.

#include<iostream>
using namespace std;

int main(){
    string ns, ms;
    int n, m;
    cin >> ns >> ms;
    n = ns[ns.size()-1]-'0';
    
    if(ms.size() == 1){
        m = stoi(ms);
        if(m == 0){
            cout << 1 << endl;
        return 0;
    }
    }else{
        m = stoi(ms.substr(ms.size()-2,2));
    }
    
    m %= 4;
    if(m == 0)   m = 4;
    int a = n;
    for(int i = 0; i < m-1; i++){
        a *= n;
    }
    cout << a%10 << endl;
    return 0;
}