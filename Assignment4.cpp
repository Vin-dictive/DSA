/*An m x n matrix is said to have a saddle point if some entry a[i][j] is the smallest value in
row i and the largest value in j. Write C/ C++ function that determines the location of a
saddle point if one exists.*/
#include<iostream>
using namespace std;

int main()
{

    int a[10][10], i, j, num;
    int sm, p, larg, f = 1;

    cout << "Enter Size of Matrix :";
    cin>>num;

    cout << "\nEnter 2D Array Elements :";
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << "\n2D Array List is :\n\n";
    for (i = 0; i < num; i++)
    {
        for (j = 0; j < num; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }


    for (i = 0; i < num; i++)
    {
        p = 0;
        sm = a[i][0];
        for (j = 0; j < num; j++)
        {
            if (sm >= a[i][j])
            {
                sm = a[i][j];
                p = j;
            }
        }
        larg = 0;
        for (j = 0; j < num; j++)
        {
            if (larg < a[j][p])
            {
                larg = a[j][p];
            }
        }

        if (sm == larg)
        {
            cout << "\nValue of Saddle Point :" << sm<<endl;
            f = 0;
        }
    }

    if (f > 0) {
        cout << "\nNo Saddle Point ";
    }

    return 0;
}
