#include<iostream>
#include<vector>
using namespace std;

typedef pair<int,int> pii;

int count[2000001] = {};
bool np[2000001] = {};

int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) count[i] = 1;
    for(int i = 2; i <= n; i++){
        if(np[i])   continue;
        for(int j = i; j <= n; j += i){
            np[j] = true;
            int tmp = 0, cp = j;
            while(cp%i == 0)    tmp++, cp /= i;
            count[j] *= ++tmp;
        }
    }
    int tmp = 1<<30;
    vector<int> ans;
    for(int i = 1; i < n; i++){
        int score = abs((i-count[i])-(n-i-count[n-i]));
        if(score > tmp) continue;
        if(score < tmp) ans.clear();
        ans.push_back(i);
        tmp = score;
    }
    for(int i : ans)    cout << i << " " << n-i << endl;
    return 0;
}