#include<iostream>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 2; i < n; i++){
		if(n%i == 0){
			cout << n/i << endl;
			return 0;
		}
	}
	
	cout << 1 << endl;
	return 0;
}