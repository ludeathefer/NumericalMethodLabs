#include <iostream>
#include <cmath>
using namespace std;

float slope(float x, float y, int i)
{
    switch (i)
    {
    case 1:
        return (x + y);

    case 2:
        return (x * cos(x));
    case 3:
        return (x * x + y);
    case 4:
        return (x * x + 2 * x - y);
    default:
        exit(1);
    }
}
void Rk4(float x0, float y0, float h, float x, int i)
{
    while (fabs(x - x0) > 0.0005)
    {
        cout << x0 << "\t" << y0 << endl;
        // cout << y0 << endl;
        float k1 = h * slope(x0, y0, i);
        float k2 = h * slope(x0 + h / 2, y0 + k1 / 2, i);
        float k3 = h * slope(x0 + h / 2, y0 + k2 / 2, i);
        float k4 = h * slope(x0 + h, y0 + k3, i);
        float k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y0 += k;
        x0 += h;
    }
}

int main()
{
    Rk4(0, 1, 0.2, 3, 1);
    Rk4(0, 1, 0.2, 5, 2);
    Rk4(0, 2, 0.2, 4, 3);
    Rk4(1, 2, 0.2, 4, 4);
    return 0;
}