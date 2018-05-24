// coding on smartphone
#include<iostream>
using namespace std;

char good[4] = {'g', 'o', 'o', 'd'};
char problem[7] = {'p', 'r', 'o', 'b', 'l', 'e', 'm'};

int main(){
	int t;
	cin >> t;
	while(t-- > 0){
		string s;
		cin >> s;
		int len = s.size();
		int ans = 11;
		for(int i = 0; i <= len-11; i++){
			int tmpgood = 0;
			for(int j = 0; j < 4; j++){
				if(s[i+j] != good[j])	tmpgood++;
			}
			
			for(int j = i+4; j <= len-7; j++){
				int tmpprob = 0;
				for(int k = 0; k < 7; k++){
					if(s[j+k] != problem[k])	tmpprob++;
				}
				
				ans = min(ans, tmpgood+tmpprob);
			}
		}
		
		cout << ans << endl;
	}// end of while
	return 0;
}