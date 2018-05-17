// 誤差ゲー。何が問題だったのかいまだにわからない
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b;
    double utc;
    scanf("%d %d UTC%lf", &a, &b, &utc);
    utc = 9.0 - utc;
    a = (a + 24) * 60 + b;
    a = a - round(utc * 60);
    b = a % 60;
    a /= 60;
    a %= 24;
    cout << (a < 10 ? "0" : "") << a << ":" << (b < 10 ? "0" : "") << b << endl;
    return 0;
}