#include<iostream>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;

    multiset<string> cust[21];

    for(int i = 0; i < n; i++){
        int x;
        cin >> x;

        if(x == 0){
            int n, m;
            string a;
            cin >> n >> m;
            for(int j = 0; j < m; j++){
                cin >> a;
                cust[n].insert(a);
            }
        }else if(x == 1){
            string b;
            cin >> b;

            bool eaten = false;
            for(int i = 1; i <= 20; i++){
                if(cust[i].find(b) != cust[i].end()){
                   cout << i << endl;
                   cust[i].erase(cust[i].find(b));
                   eaten = true;
                   break; 
                }
            }

            if(!eaten)  cout << -1 << endl;

        }else if(x == 2){
            int c;
            cin >> c;
            cust[c].clear();
        }
    }
    return 0;
}