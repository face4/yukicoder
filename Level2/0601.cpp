//スマホコーディング
#include <iostream>
using namespace std;

int main()
{
    int T[2][2] = {0};
    int n, a, b;
    cin >> n;
    while (n-- > 0)
    {
        cin >> a >> b;
        T[a % 2][b % 2]++;
    }

    int pairs = 0;

    for (int i = 0; i <= 1; i++)
        for (int j = 0; j <= 1; j++)
            pairs += T[i][j] / 2;

    if (pairs % 2)
        cout << "Alice" << endl;
    else
        cout << "Bob" << endl;

    return 0;
}