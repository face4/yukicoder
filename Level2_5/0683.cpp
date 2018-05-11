#include <iostream>
using namespace std;
typedef long long ll;

bool check(ll a, ll b)
{
    if (a == 0 || b == 0)
    {
        return true;
    }

    if (a % 2 == 0 && b % 2 == 0)
    {
        return check(a / 2, b - 1) || check(a - 1, b / 2);
    }
    else if (a % 2 == 0)
    {
        a /= 2;
        b--;
        return check(a, b);
    }
    else if (b % 2 == 0)
    {
        a--;
        b /= 2;
        return check(a, b);
    }
    else
    {
        return false;
    }
    false;
}

int main()
{
    ll a, b;
    cin >> a >> b;

    if (check(a,b))
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}