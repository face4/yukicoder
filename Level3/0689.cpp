#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n; cin >> n;
	vector<int> ans;
	
	if(n == 0){
	    cout << "2\n2 2\n";
	    return 0;
	}
	
	int two = 0, three = 0;
	for(int i = 1; i < 250; i++){
		for(int j = 1; i*j <= n; j++){
			if(i + j + n-i*j + 1 <= 250){
			    two = i, three = j;
			}
		}
    }
    for(int i = 0; i < two; i++) ans.push_back(2);
    for(int i = 0; i < three; i++) ans.push_back(3);
    if(n-(two*three)) ans.push_back(7);
    for(int i = 0; i < n-(two*three); i++) ans.push_back(12);
    
    int len = ans.size();
    cout << len << endl;
	for(int i = 0; i < len; i++){
		cout << ans[i] << " \n"[i==len-1];
	}
	
	return 0;
}