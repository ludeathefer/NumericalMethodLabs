#include <iostream>
#include <cmath>
using namespace std;

float func1(float x)
{
    return (pow(x, 3) - (3 * x) - 5);
}
float deri_func1(float x)
{
    return ((3 * x * x) - 3);
}
float func2(float x)
{
    return (log(x) - (1 / x));
}
float deri_func2(float x)
{
    return ((1 / x) + (1 / (x * x)));
}
float func3(float x)
{
    return (cos(x));
}
float deri_func3(float x)
{
    return (-sin(x));
}
float func4(float x)
{
    return (exp(x) - 5);
}
float deri_func4(float x)
{
    return (exp(x));
}
void Approximate(int i, int j)
{
    float x_k = j;
    float x_k1;
    float y_k, y_d;
    bool isApprox = false;

    do
    {
        switch (i)
        {
        case 1:
            y_k = func1(x_k);
            y_d = deri_func1(x_k);
            break;
        case 2:
            y_k = func2(x_k);
            y_d = deri_func2(x_k);
            break;
        case 3:
            y_k = func3(x_k);
            y_d = deri_func3(x_k);
            break;
        case 4:
            y_k = func4(x_k);
            y_d = deri_func4(x_k);
            break;
        default:
            cout << endl
                 << "Error. No function Exist" << endl;
            exit(1);
        }
        if (y_d == 0)
        {
            cout << endl
                 << "Local maxima or minima exits colseby." << endl;
            exit(0);
        }

        x_k1 = x_k - (y_k / y_d);

        if (fabs(x_k1 - x_k) < 0.0001)
        {
            cout << endl
                 << "The root for function " << i << " is " << x_k1 << endl;
            isApprox = true;
        }
        else
            x_k = x_k1;

    } while (!isApprox);
}
int main()
{
    Approximate(1, 2);
    Approximate(2, 3);
    Approximate(3, 5);
    Approximate(4, 10);
    Approximate(5, 9);
    return 0;
}
