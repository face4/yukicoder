// bubble sort
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<pair<int,int>> res;
    int A[n];
    for(int i = 0; i < n; i++)  cin >> A[i];

    for(int i = 0; i < n-1; i++){
        int min = A[i];
        int minIndex = i;
        for(int j = i+1; j < n; j++){
            if(min > A[j]){
                min = A[j];
                minIndex = j;
            }
        }

        if(i != minIndex){
            res.push_back({i, minIndex});
            swap(A[i],A[minIndex]);
        }
    }

    cout << res.size() << endl;
    for(pair<int,int> p : res){
        cout << p.first << " " << p.second << endl;
    }

    cin >> n; // dummy input
    return 0;
}