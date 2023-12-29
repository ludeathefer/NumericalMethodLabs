#include <iostream>
#include <cmath>
using namespace std;

float func1(float x) { return (pow(x, 3) - (10 * pow(x, 2)) + (5 * x) - 8); };
float func2(float x) { return ((5 * log(x)) - 20); };
float func3(float x) { return (sin(x) * cos(x) - x + 5); };
float func4(float x) { return (exp(x) - 5); };

void Approximate(int i, float x_0, float x_1)
{
    float y_0, y_1;
    bool isApprox = false;
    do
    {
        switch (i)
        {
        case 1:
            y_0 = func1(x_0);
            y_1 = func1(x_1);
            break;
        case 2:
            y_0 = func2(x_0);
            y_1 = func2(x_1);
            break;
        case 3:
            y_0 = func3(x_0);
            y_1 = func3(x_1);
            break;
        case 4:
            y_0 = func4(x_0);
            y_1 = func4(x_1);
            break;
        default:
            cout << "Error. No function Exist" << endl;
            exit(1);
        }
        float x_2 = ((y_1 * x_0) - (y_0 * x_1)) / ((y_1 - y_0));
        if (fabs((x_2 - x_1) / x_2) < 0.0001)
        {
            cout << "The root of function " << i << " is " << x_2 << endl;
            isApprox = true;
        }
        else
        {
            x_0 = x_1;
            x_1 = x_2;
        }
    } while (!isApprox);
}

int main()
{
    Approximate(1, -40, 40);
    Approximate(2, 100, 200);
    Approximate(3, 1, 2);
    Approximate(4, 1, 3);
    Approximate(5, 1, 1);
    return 0;
}