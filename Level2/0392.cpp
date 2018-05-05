#include<iostream>
#include<vector>
using namespace std;

int main(){
    int m;
    cin >> m;
    while(m-- > 0){
        int x;
        cin >> x;
        vector<char> res;

        while(x != 0){
            if(x % 2 == 0){
                res.push_back('R');
            }else{
                res.push_back('L');
            }
            x--;
            x /= 2;
        }

        for(vector<char>::reverse_iterator it = res.rbegin(); it != res.rend(); it++){
            cout << (*it);
        }
        cout << endl;
    }

    return 0;
}
