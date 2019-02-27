/*Write C++ program to store first year percentage of students in array. Write function for
sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores.*/

#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;

void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}

int main()
{
  int n;
  cout<<"Enter the number of students from first year:";
  cin>>n;
  float roll[n];
  cout<<"Enter the Percentages:-\n";
    for(int i=0;i<n;i++)
    {
      if(roll[i-1]==97)
      {
        break;
      }
      cin>>roll[i];
    }

  cout<<"\n//////////////////Selection Sorting///////////////////////////\n";

  for(int i=0;i<n;i++)
  {
    for(int j=i+1;j<n;j++)
    {
      if(roll[i]>roll[j])
      {
        swap(&roll[i],&roll[j]);
      }
    }
  }
  cout<<"\n//////////////////////////////////////////////////////////////";
  cout<<"\n//////////////////////////////////////////////////////////////";
  cout<<"\nSorted list is :";
  for(int i=0;i<n;i++)
  {
    cout<<roll[i]<<" ";
  }

  cout<<"\n////////////////////Bubble Sorting///////////////////////////\n";


   for (int i = 0; i < n-1; i++)
   {
     for (int j = 0; j < n-i-1; j++)
     {
      if (roll[j] > roll[j+1])
      {
          swap(&roll[j], &roll[j+1]);
      }
     }
   }



  cout<<"\n//////////////////////////////////////////////////////////////";
  cout<<"\n//////////////////////////////////////////////////////////////";
  cout<<"\nSorted list is of first five percentages :";
  for(int i=0;i<5;i++)
  {
    cout<<roll[i]<<" ";
  }
  cout<<endl;
  return 0;
}
