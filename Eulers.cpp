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
void Eulers(float x0, float y0, float h, float x, int i)
{

    while (fabs(x0 - x) > 0.00005)
    {
        cout << x0 << "\t" << y0 << endl;
        // cout << y0 << endl;
        float deri = slope(x0, y0, i);
        y0 += h * deri;
        x0 += h;
    }
}
int main()
{
    Eulers(0, 1, 0.2, 3, 1);
    Eulers(0, 1, 0.2, 5, 2);
    Eulers(0, 2, 0.2, 4, 3);
    Eulers(1, 2, 0.2, 4, 4);
    return 0;
}