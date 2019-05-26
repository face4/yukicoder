#include<iostream>
#include<vector>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<int> cnt(9,0);
    for(char c : s) cnt[c-'1']++;
    for(int i = 0; i < 9; i++){
        if(cnt[i] == 4) continue;
        cnt[i]++;
        
        bool toitu = true, temp = false;
        for(int j = 0; j < 9; j++) toitu &= (cnt[j]==2||cnt[j]==0);

        for(int j = 0; j < 1<<9; j++){
            vector<int> cp = cnt;
            bool valid = true;
            for(int k = 0; k < 9; k++){
                if((j>>k)&1){
                    if(cp[k] < 3)  valid = false;
                    cp[k] -= 3;
                }
            }
            if(!valid)  continue;
            for(int janto = 0; janto < 9; janto++){
                if(cp[janto] < 2)   continue;
                vector<int> ncp= cp;
                ncp[janto] -= 2;
                bool ok = true;
                for(int k = 0; k < 7; k++){
                    if(ncp[k] == 0)  continue;
                    if(ncp[k+1]==0||ncp[k+2]==0){
                        ok = false;
                        break;
                    }
                    ncp[k]--, ncp[k+1]--, ncp[k+2]--;
                    k--;
                }
                for(int k = 0; k < 9; k++)  ok &= ncp[k]==0;
                if(ok)  temp = true;
            }
        }
        
        cnt[i]--;
        if(toitu || temp)   cout << i+1 << endl;
    }
    return 0;
}