#include <iostream>
using namespace std;

int main()
{
    float xp, ys = 0, product;
    int n;
    cout << "Enter no of points" << endl;
    cin >> n;
    float *x, *y;
    x = new float[n];
    y = new float[n];
    cout << "Enter interpolation value" << endl;
    cin >> xp;
    cout << "Points: \n";
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    for (int i = 0; i <= n; i++)
    {
        product = 1;
        for (int j = 0; j <= n; j++)
        {

            if (i != j)
            {
                product *= (xp - x[j]) / (x[i] - x[j]);
            }
        }
        ys += product * y[i];
    }
    cout << "x = " << xp << "\t y = " << ys;
    return 0;
}
