#include <iostream>
#include <climits>
using namespace std;
typedef long long ll;

ll getnum(int digit, string s)
{
    ll res = 0;
    ll base = 1;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        char x = s[i];
        if (x <= '9')
            res += ll(x - '0') * base;
        else
            res += ll(x - 'A' + 10) * base;
        base *= ll(digit);
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    string s;
    ll ans = LLONG_MAX;
    while (n-- > 0)
    {
        cin >> s;
        char m = '0';
        for (char x : s)
        {
            m = max(m, x);
        }
        ll now;
        if (m <= '9')
            now = getnum(m - '0' + 1, s);
        else
            now = getnum(m - 'A' + 11, s);
        ans = min(ans, now);
    }

    cout << ans << endl;
    return 0;
}