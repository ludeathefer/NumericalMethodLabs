#include <iostream>
#include <cmath>
using namespace std;

class Inverse
{
private:
    int n;
    float **mat;

public:
    Inverse(int i)
    {
        n = i;
        mat = new float *[n];
        for (int j = 0; j < (2 * n); j++)
        {
            mat[j] = new float[n];
        }
    }
    ~Inverse()
    {
        for (int i = 0; i < (2 * n); i++)
        {
            delete[] mat[i];
        }
        delete[] mat;
    }
    void InputMat()
    {
        cout << "Enter Matrix" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (2 * n); j++)
            {
                if (j < n)
                {
                    cin >> mat[i][j];
                }
                else
                {
                    if ((i + n) == j)
                    {
                        mat[i][j] = 1;
                    }
                    else
                    {
                        mat[i][j] = 0;
                    }
                }
            }
        }
    }
    void DisplayMat()
    {
        cout << "The matrix is: " << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < (2 * n); j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << endl;
        }
    }
    void EvalInverse()
    {
        float ratio;
        for (int i = 0; i < n; i++)
        {
            if (fabs(mat[i][i]) < 0.000005)
            {
                cerr << "Pivot element zero" << endl;
                exit(1);
            }
            for (int j = 0; j < n; j++)
            {

                if (j != i)
                {
                    ratio = mat[j][i] / mat[i][i];
                    for (int k = i; k < (2 * n); k++)
                    {
                        mat[j][k] = mat[j][k] - (ratio * mat[i][k]);
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            ratio = mat[i][i];
            for (int j = 0; j < (2 * n); j++)
            {
                mat[i][j] = mat[i][j] / ratio;
            }
        }
    }
};
int main()
{
    int n;
    cout << "Matrix Order: " << endl;
    cin >> n;
    Inverse I(n);
    I.InputMat();
    I.DisplayMat();
    I.EvalInverse();
    I.DisplayMat();
    return 0;
}