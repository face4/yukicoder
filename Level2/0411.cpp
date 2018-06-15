// coding on smartphone
// 数列を
// 1.)kをかならず含み、k以上の値からなる
// 2.)その残り
// にわけ、それぞれソートして1,2の順に並べ、
// kを先頭にすれば昇順昇順列が得られる.
// 集合の数はn-k個を選ぶか選ばないかで考えて2^(n-k).
// kが1の場合はただの昇順列になってしまう場合が
// n通りあるのでnを引く

#include<iostream>
using namespace std;

int main(){
	int n, k;
	cin >> n >> k;
	int ans = 1<<(n-k);
	if(k==1)	ans -= n;
	cout << ans << endl;
	return 0;
}