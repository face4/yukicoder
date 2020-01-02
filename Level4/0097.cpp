#include<iostream>
using namespace std;

unsigned xor128_x = 123456789, xor128_y = 362436069, xor128_z = 521288629, xor128_w = 88675123;
unsigned xor128() {
	unsigned t = xor128_x ^ (xor128_x << 11);
	xor128_x = xor128_y; xor128_y = xor128_z; xor128_z = xor128_w;
	return xor128_w = xor128_w ^ (xor128_w >> 19) ^ (t ^ (t >> 8));
}

void generateA(int N, int A[]) {
    for(int i = 0; i < N; ++ i)
        A[i] = xor128() % 100003;
}

typedef long long ll;
ll modpow(ll a, ll b, ll p = 1e9+7){
    if(b == 0)  return 1;

    if(b % 2 == 0){
        ll d = modpow(a, b/2, p);
        return (d*d) % p;
    }else{
        return (a%p * modpow(a, b-1, p)) % p;
    }
}

const int mod = 100003;

int main(){
    int n, q;
    cin >> n >> q;
    int a[n];
    generateA(n, a);
    bool b[100004] = {};
    for(int i = 0; i < n; i++)  b[a[i]] = true;
    bool f = (ll)n*q < 5e7;
    while(q--){
        ll x;
        cin >> x;
        if(x == 0){
            cout << 0 << endl;
            continue;
        }
        int ans = 0;
        if(f){
            for(int i = 0; i < n; i++)  ans = max(ans, (int)(x*a[i]%mod));
        }else{
            int inv = modpow(x, mod-2, mod);
            for(ans = 100002;;ans--){
                if(b[(ll)ans*inv%mod])  break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
