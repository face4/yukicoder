#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        multiset<int> cnt;
        int n = s.length();
        vector<int> pro(n, 0);
        for(int i = 4; i+7 <= n; i++){
            int diff = 0;
            for(int j = 0; j < 7; j++)  diff += "problem"[j]!=s[i+j];
            pro[i] = diff;
            cnt.insert(diff);
        }
        int ret = 11, tmp = 0;
        for(int i = 0; i+11 <= n; i++){
            string g = s.substr(i,4);
            int diff = 0;
            for(int j = 0; j < 4; j++)  diff += "good"[j]!=s[i+j];
            ret = min(ret, tmp+diff+(*cnt.begin()));
            cnt.erase(cnt.find(pro[i+4]));
            if(i >= 6){
                if(s.substr(i-6,7)=="problem")  tmp++;
            }
        }
        cout << ret << endl;
    }
    return 0;
}