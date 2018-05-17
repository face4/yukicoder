//スマホコーディング
#include <iostream>
using namespace std;

int main()
{
    int r, k, h, w;
    char A[10][10];
    cin >> r >> k >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> A[i][j];

    if (r == 0)
    {
        for (int i = 0; i < k * h; i++)
        {
            for (int j = 0; j < k * w; j++)
            {
                cout << A[i / k][j / k];
            }
            cout << endl;
        }
    }
    else if (r == 90)
    {
        for (int i = 0; i < k * w; i++)
        {
            for (int j = k * h - 1; j >= 0; j--)
            {
                cout << A[j / k][i / k];
            }
            cout << endl;
        }
    }
    else if (r == 180)
    {
        for (int i = k * h - 1; i >= 0; i--)
        {
            for (int j = k * w - 1; j >= 0; j--)
            {
                cout << A[i / k][j / k];
            }
            cout << endl;
        }
    }
    else if (r == 270)
    {
        for (int i = k * w - 1; i >= 0; i--)
        {
            for (int j = 0; j < k * h; j++)
            {
                cout << A[j / k][i / k];
            }
            cout << endl;
        }
    }

    return 0;
}