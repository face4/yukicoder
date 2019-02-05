#include<iostream>
#include<algorithm>
using namespace std;

int p(int i, int j){
    int ret = 1;
    while(j-- > 0)  ret *= i;
    return ret;
}

int main(){
    int t, b, n;
    cin >> t >> b;

    while(t-- > 0){
        string res = "";
        cin >> n;

        int cnt = 0;
        while(n){
            int tmp = n%(p(-b, cnt+1));
            if(tmp < 0) tmp -= b;
            string add{(char)('0'+tmp)};
            res += add;
            n -= tmp;
            n /= b;
        }
        
        if(res == "")   res = "0";
        
        reverse(res.begin(), res.end());

        cout << res << endl;
    }

    return 0;
}