// coding on smartphone
#include<iostream>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	cout << 0 << " " << 2;
	int now = 2;
	bool flag = false;
	
	int i;
	for(i = 2; i < n-k; i++){
		if(!flag) now--;
		else 	  now+=2;
		cout << " " << now;
		flag = !flag;
	}
	
	for(; i < n; i++){
		cout << " " << now;
	}
	
	cout << endl;
	
	return 0;
}