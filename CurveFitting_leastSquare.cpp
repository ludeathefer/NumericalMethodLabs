#include <iostream>
#include <cmath>
using namespace std;

void linear(float x[], float y[], int n)
{
    float Ex, Ey, Exy, Ex2;
    Ex = Ey = Exy = Ex2 = 0;
    for (int i = 0; i < n; i++)
    {
        Ex += x[i];
        Ey += y[i];
        Exy += x[i] * y[i];
        Ex2 += x[i] * x[i];
    }
    float denom = (Ex * Ex) - (Ex2 * n);
    float a = ((Ey * Ex) - (n * Exy)) / denom;
    float b = ((Ex * Exy) - (Ey * Ex2)) / denom;
    cout << "The best fit curve is of the form f(x) = y = ax + b such that:\n a = " << a << " and b = " << b << endl;
}
void exponential(float x[], float y[], int n)
{
    float Ex, Ey, Exy, Ex2;
    Ex = Ey = Exy = Ex2 = 0;
    for (int i = 0; i < n; i++)
    {
        y[i] = log(y[i]);
        Ex += x[i];
        Ey += y[i];
        Exy += x[i] * y[i];
        Ex2 += x[i] * x[i];
    }
    float denom = (Ex2 * n) - (Ex * Ex);
    float a = exp(((Ey * Ex2) - (Ex * Exy)) / denom);
    float b = ((n * Exy) - (Ey * Ex)) / denom;
    cout << "The best fit curve is of the form f(x) = y = ae^(bx) such that:\n a = " << a << " and b = " << b << endl;
}
int main()
{
    int n;
    cout << "No. of data pairs: ";
    cin >> n;
    float x[n], y[n];
    cout << "Enter the values in (x,y) format:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    linear(x, y, n);
    exponential(x, y, n);
    return 0;
}