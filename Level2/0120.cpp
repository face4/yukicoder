// AC後追記
// vectorではなくpriority queueを使うようにすれば、
// 毎回ソートしなくて済む、実行時間も速くなる

#include<iostream>
#include<map>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;

    while(t-- > 0){
        int n, x;
        cin >> n;

        map<int,int> cnt;
        for(int i = 0; i < n; i++){
            cin >> x;
            cnt[x]++;
        }

        vector<int> counts;
        for(map<int,int>::iterator it = cnt.begin(); it != cnt.end(); it++){
            counts.push_back((*it).second);
        }        

        sort(counts.begin(), counts.end());
        
        int ans = 0;
        int len = counts.size();
        
        while(len >= 3){
            if(counts[len-3] == 0)  break;
            ans++;
            counts[len-1]--;
            counts[len-2]--;
            counts[len-3]--;
            sort(counts.begin(), counts.end());
        }

        cout << ans << endl;
    }

    return 0;
}