#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    static bool nonprime[5000001] = {};
    vector<int> prime;
    prime.push_back(0);
    for(int i = 2; i < 5000001; i++){
        if(!nonprime[i]){
            prime.push_back(i);
            for(int j = i+i; j < 5000001; j += i)  nonprime[j] = true;
        }
    }
    prime.push_back(5000001);

    int n = prime.size();
    
    int k, x;
    cin >> k;
    
    set<int> req;
    for(int i = 0; i < k; i++){
        cin >> x;
        req.insert(x);
    }

    int l = 1, r = 1, ans = -1;
    while(l < n-1 && r < n-1){
        set<int> now;
        while(r < n-1){
            int x = prime[r];
            bool valid = true;
            while(x > 0){
                if(req.count(x%10)) now.insert(x%10);
                else                valid = false;
                x /= 10;
            }
            if(!valid){
                l = r+1, r = r+1;
                break;
            }else{
                if(req.size() == now.size())    ans = max(ans, prime[r+1]-prime[l-1]-2);
            }
            r++;
        }
    }

    cout << ans << endl;

    return 0;
}