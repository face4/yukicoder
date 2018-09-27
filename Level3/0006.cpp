#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

int main(){
    bool nonprime[200001] = {};
    nonprime[0] = nonprime[1] = true;
    for(int i = 2; i < 200000; i++){
        if(nonprime[i]) continue;
        for(int j = i+i; j < 200001; j+=i){
            nonprime[j] = true;
        }
    }

    int k, n;
    cin >> k >> n;

    vector<int> prime, hash;

    for(int i = k; i <= n; i++){
        if(nonprime[i]) continue;
        int x = i;
        while(x > 9){
            int hash = 0;
            while(x > 0)    hash += x%10, x /= 10;
            x = hash;
        }
        prime.push_back(i);
        hash.push_back(x);
    }

    int siz = hash.size();
    int l = 0, r = 0, anspos = 0, maxlen = 1;
    set<int> s;
    while(l < siz){
        while(r < siz && s.count(hash[r]) == 0){
            s.insert(hash[r]);
            r++;
        }

        if(r-l >= maxlen){
            anspos = l;
            maxlen = r-l;
        }

        if(r == siz)  break;

        while(hash[l] != hash[r]){
            s.erase(hash[l]);
            l++;
        }
        
        l++;
        r++;
    }

    cout << prime[anspos] << endl;

    return 0;
}