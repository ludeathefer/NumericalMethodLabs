#include <iostream>
#include <cmath>
using namespace std;

class Matrix
{
private:
    int n;
    float **mat;
    float *constMat;
    float *MatAns;

public:
    Matrix()
    {
        cout << "Enter no of constants" << endl;
        cin >> n;

        mat = new float *[n];
        constMat = new float[n];
        MatAns = new float[n];
        for (int j = 0; j < n; j++)
        {
            mat[j] = new float[n];
        }
    }
    ~Matrix()
    {
        for (int j = 0; j < n; j++)
        {
            delete[] mat[j];
        }
        delete[] mat;
        delete[] constMat;
    }
    void InputMatrix()
    {
        cout << "Enter matrix coefficients" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> mat[i][j];
            }
        }
        cout << endl
             << "Enter constants" << endl;

        for (int i = 0; i < n; i++)
        {

            cin >> constMat[i];
        }
    }
    void DisplayMat()
    {
        cout << endl
             << "The matrix is" << endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << "\t";
            }
            cout << constMat[i];
            cout << endl;
        }
    }
    void GaussElimination()
    {
        for (int i = 0; i < n; i++)
        {
            float div = mat[i][i];
            if (div == 0)
            {
                cout << "Error, division by zero" << endl;
                exit(1);
            }
            for (int j = 0; j < n; j++)
            {

                mat[i][j] /= div;
            }
            constMat[i] /= div;
            for (int k = i + 1; k < n; k++)
            {
                double factor = mat[k][i];
                for (int j = 0; j < n; j++)
                {
                    mat[k][j] -= factor * mat[i][j];
                }
                constMat[k] -= factor * constMat[i];
            }
            MatAns[i] = constMat[i];
        }
    }
    void EvaluateVars()
    {
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (j != i)
                {
                    MatAns[i] = MatAns[i] - (mat[i][j] * MatAns[j]);
                }
                if (i == j)
                {
                    MatAns[i] = MatAns[i] / mat[i][j];
                }
            }
        }
        cout << "The value of variables are:" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << MatAns[i] << "\t";
        }
    }
};
int main()
{
    Matrix M;
    M.InputMatrix();
    M.GaussElimination();
    M.EvaluateVars();
    return 0;
}