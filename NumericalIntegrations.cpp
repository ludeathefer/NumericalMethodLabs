#include <iostream>
#include <cmath>
using namespace std;

float func(float x)
{
    // return exp(pow(x, 2));
    // return exp(-pow(x, 2));
    return pow(x, 2) * log(x);
}

void Trapezoidal(float xn, float x0, int n)
{
    float sum = 0;
    float h = (xn - x0) / n;
    for (int i = 1; i < n; i++)
    {
        sum += func(x0 + h * i);
    }

    sum = (func(x0) + func(xn) + 2 * sum) * h / 2;

    cout << "Area from Trapezoidal rule is: " << sum << endl;
}
float Simpsons13(float xn, float x0, int n)
{
    float h = (xn - x0) / n;
    float sum = 0;
    if (n % 3 != 0)
    {
        cerr << "No of strips should be a multiple of 3.\n";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        sum += func(x0 + h * i) * ((i % 2) ? 4 : 2);
    }
    sum = (func(x0) + func(xn) + sum) * h / 3;

    cout << "Area from Simpsons 1/3 rule : " << sum << endl;
}
float Simpsons38(int n)
{
    float sum = 0;
    if ((n - 1) % 3)
    {
        cerr << "Number of data minus one should be multiple of 3\n";
        return 1;
    }
    float *x = new float[n], *y = new float[n];
    cout << "Enter x and y : ";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 1; i < n - 1; i++)
    {
        sum += y[i] * ((i % 3) ? 3 : 2);
    }
    sum = (y[0] + y[n - 1] + sum) * ((x[n - 1] - x[0]) / (n - 1)) * 3 / 8;
    cout << "Area from Simpsons 3/8 rule : " << sum << endl;
}

int main()
{
    float xn, x0;
    int n;
    cout << "For Trapezoidal rule and Simpsons 1/3 rule:\nEnter Upper limit, lower limit and no of strips: ";
    cin >> xn >> x0 >> n;
    Trapezoidal(xn, x0, n);
    Simpsons13(xn, x0, n);
    cout << "For Simpsons 3/8 rule:\nEnter No of data: ";
    cin >> n;
    Simpsons38(n);
}