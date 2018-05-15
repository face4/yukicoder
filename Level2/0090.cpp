#include<iostream>
#include<algorithm>
#include<map>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    int arr[N];
    map<pair<int,int> , int> table;
    for(int i = 0; i < N; i++)  arr[i] = i;

    int item1, item2, score;
    for(int i = 0; i < M; i++){
        cin >> item1 >> item2 >> score;
        table[make_pair(item1,item2)] = score;
    }

    int res = 0;
    int a, b, s, apos, bpos, candidate;
    do{
        candidate = 0;
        for(auto it = table.begin(); it != table.end(); it++){
            a = it->first.first;
            b = it->first.second;
            s = it->second;

            for(int i = 0; i < N; i++){
                if(arr[i] == a) apos = i;
                if(arr[i] == b) bpos = i;
            }

            if(apos < bpos) candidate += s;
        }

        res = max(res, candidate);
    }while(next_permutation(arr, arr+N));

    cout << res << endl;

    return 0;
}