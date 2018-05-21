#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	double m, n;
	cin>>m>>n;
	m += n/3.0;
	cout << fixed << setprecision(9) << m << endl;
	return 0;
}