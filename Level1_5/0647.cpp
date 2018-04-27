#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<pair<int,int> > ms;
    int n, m;
    scanf("%d", &n);
    for(int i = 0; i< n; i++){
        int a, b;
        scanf("%d %d" , &a, &b);
        ms.push_back(make_pair(a,b));
    }
    
    scanf("%d" , &m);
    int x,y;
    int mentaiko[m] = {};
    for(int i = 0; i < m; i++){
        cin >> x >> y;
        for(vector<pair<int,int> >::iterator it = ms.begin(); it < ms.end(); it++){
            if((*it).first >= x && (*it).second <= y){
                mentaiko[i]++;
            }
        }
    }

    int miracle = *std::max_element(mentaiko, mentaiko+m);
    if(miracle == 0){
        cout << 0 << endl;
        return 0;
    }
    
    for(int i = 0; i < m; i++){
        if(mentaiko[i] == miracle){
            cout << i+1 << endl;
        }
    }
    return 0;
}