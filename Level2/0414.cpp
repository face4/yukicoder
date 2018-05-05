#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

int main()
{
    ll m;
    cin >> m;

    for (ll i = 2; i <= sqrt(m); i++)
    {
        if (m % i == 0)
        {
            cout << i << " " << m / i << endl;
            return 0;
        }
    }

    cout << 1 << " " << m << endl;
}
