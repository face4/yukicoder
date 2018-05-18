//スマホコーディング
#include <iostream>
using namespace std;

int main()
{
    int n;
    string s, t, u;
    cin >> n >> s;

    int len = s.size();
    if (len >= 4)
    {
        cout << "YES" << endl;
        return 0;
    }
    for (int i = 1; i <= len / 2; i++)
    {
        for (int j = 0; j <= len - i * 2; j++)
        {
            t = s.substr(j, i);
            u = s.substr(j + i, i);
            if (t == u)
            {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}