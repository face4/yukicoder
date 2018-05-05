#include <iostream>
using namespace std;

typedef long long ll;

int D[200001];

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> D[i];
    ll counts = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i != D[i])
        {
            int indextmp = D[i];
            while (indextmp != i)
            {
                int tmp = D[indextmp];
                D[indextmp] = indextmp;
                counts++;
                indextmp = tmp;
            }
        }
    }

    if (counts > k || (k - counts) % 2 == 1)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
    }

    return 0;
}