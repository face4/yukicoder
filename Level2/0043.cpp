#include<iostream>
#include<vector>
#include<set>
using namespace std;

int main(){
    int n;
    cin >> n;

    char s[n][n];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> s[i][j];
        }
    }

    vector<pair<int,int>> v;
    int residual = 0;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(s[i][j] == '-'){
                residual++;
                v.push_back({i,j});
            }  
        }
    }

    int ans = 6;
    for(int i = 0; i < 1<<residual; i++){
        for(int j = 0; j < residual; j++){
            if(i & 1<<j){
                s[v[j].first][v[j].second] = 'o';
                s[v[j].second][v[j].first] = 'x';
            }else{
                s[v[j].first][v[j].second] = 'x';
                s[v[j].second][v[j].first] = 'o';
            }
        }

        set<int> scores;
        int zero = 0;
        for(int i = 0; i < n; i++) if(s[0][i] == 'o')   zero++;
        scores.insert(zero);
        for(int i = 1; i < n; i++){
            int tmp = 0;
            for(int j = 0; j < n; j++)  if(s[i][j] == 'o')  tmp++;
            scores.insert(tmp);
        }

        int pos = 1;
        for(set<int>::reverse_iterator it = scores.rbegin();; it++){
            if(*it == zero) break;
            pos++;
        }

        ans = min(ans, pos);
    }

    cout << ans << endl;
    
    return 0;
}