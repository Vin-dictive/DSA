/*A classic problem that can be solved by backtracking is called the Eight Queens problem,
which comes from the game of chess. The chess board consist of 64 square arranged in an
8 by 8 grid. The board normally alternates between black and white square, but this is not
relevant for the present problem. The queen can move as far as she wants in any direction,
as long as she follows a straight line, Vertically, horizontally, or diagonally. Write C++
program with recursive function for generating all possible configurations for 4-queen's
problem.*/


#include <iostream>
using namespace std;

int main()
{
  cout<<"Enter the size of n for N QUEEN problem:";
  int n;
  cin>>n;
  int arr[n];
  int last;
  for(int i=0;i<n;i++)
  {
    if(i==1)
    {arr[i]=1;}
    else
    {arr[i]=0;}
    cout<<arr[i]<<" ";
  }
  cout<<endl;
  for(int k=0;k<n-1;k++)
  {
    if(n%2!=0)
    {
      for(int i=0;i<2;i++)
      {
        last=arr[n-1];
        for(int j=n-1;j>0;j--)
        {
          arr[j]=arr[j-1];
        }
        arr[0]=last;
      }

      for(int i=0;i<n;i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;

    }
    else
    {
      if(arr[n-1]!=1)
      {
        for(int i=0;i<2;i++)
        {
          last=arr[n-1];
          for(int j=n-1;j>0;j--)
          {
            arr[j]=arr[j-1];
          }
          arr[0]=last;
        }
      }
      else
      {
        for(int i=0;i<1;i++)
        {
          last=arr[n-1];
          for(int j=n-1;j>0;j--)
          {
            arr[j]=arr[j-1];
          }
          arr[0]=last;
        }
      }


      for(int i=0;i<n;i++)
      {
        cout<<arr[i]<<" ";
      }
      cout<<endl;
    }

  }
  return 0;
}
