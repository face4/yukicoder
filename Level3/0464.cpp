#include<iostream>
#include<vector>
using namespace std;

string s;
bool visit[5000][5000] = {}, memo[5000][5000] = {};

bool isPalindrome(int i, int j){
    if(visit[i][j]) return memo[i][j];

    visit[i][j] = true;
    
    if(i + 1 == j){
        return memo[i][j] = (s[i]==s[j]);
    }else{
        bool b = (s[i] == s[j]) && isPalindrome(i+1, j-1);
        return memo[i][j] = b;
    }
}

int main(){
    cin >> s;
    
    int n = s.length();
    vector<int> v[n], aft(n, 0);

    for(int i = 0; i < n; i++)  visit[i][i] = memo[i][i] = true;

    for(int i = 0; i < n; i++){
        for(int j = i; j < n-2; j++){
            if(isPalindrome(i,j))   v[i].push_back(j);
        }
    }

    for(int i = 0; i < n; i++){
        if(isPalindrome(i, n-1))    aft[i] = 1;
    }

    for(int i = n-2; i >= 0; i--)   aft[i] += aft[i+1];

    // 最悪計算量はO(n^2)なので間に合うはず...?
    long long ans = 0;
    for(int i : v[0]){
        for(int j : v[i+1]){
            ans += aft[j+2];
        }
    }

    cout << ans << endl;

    return 0;
}