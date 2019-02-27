/*A magic square is an n * n matrix of the integers 1 to n2 such that
the sum of each row, column, and diagonal is the same. The figure
given below is an example of magic square for case n=5. In this example,
the common sum is 65. Write C/C++ Program for magic square*/

#include <iostream>
using namespace std;


void CalcMagic(int n)
{

  int matrix[n][n];
  int nsqr = n * n;
  int i=0, j=n/2;     // start position

  for (int k=1; k<=nsqr; ++k)
  {
    matrix[i][j] = k;
    i--;
    j++;

    if (k%n == 0)
    {
      i += 2;
      --j;
    }
    else
    {
      if (j==n)
        j -= n;
      else if (i<0)
        i += n;
    }
  }
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      cout<<matrix[i][j]<<"\t";
    }
    cout<<endl;
  }

}

int main()
{
  int x;
  cout<<"enter the n value for magic sqaure:";
  cin>>x;
  CalcMagic(x);

  return 0;
}
