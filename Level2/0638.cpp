//スマホコーディング
#include <iostream>
using namespace std;
typedef long long ll;

int bitcnt(ll a)
{
    int ret = 0;
    for (; a != 0; a &= a - 1)
        ret++;
    return ret;
}

int main()
{
    ll n;
    cin >> n;
    if (n <= 5)
    {
        cout << -1 << endl;
        return 0;
    }

    ll a, b;
    for (a = 3; a < n; a++)
    {
        b = n - a;
        if (bitcnt(a) != 1 && bitcnt(b) != 1)
            break;
    }

    if (a == n)
        cout << -1 << endl;
    else
        cout << a << " " << b << endl;

    return 0;
}