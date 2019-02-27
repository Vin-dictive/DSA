/*Write C/C++ program to store marks scored for first test of subject 'Data Structures and
Algorithms' for N students. Compute
I. The average score of class
ii. Highest score and lowest score of class
iii. Marks scored by most of the students
iv. list of students who were absent for the test*/
#include <stdio.h>
#include <iostream>
using namespace std;
class Student
{
 public:
	float marks;
	char name[20];
	Student()
	{
	cout<<"\nEnter the name of the student:";
	cin>>name;
	cout<<"Enter the marks:(out of 100)(*for absentees put -1):";
	cin>>marks;
	}

};

int main()
{
	int n;
	int sum=0;
	int count=0;

	//Insertion into class
	cout<<"Enter the no. of students:";
	cin>>n;
	Student arr[n];

	//printing and counting Absentees
		cout<<"\nAbsentees are:";
		for(int i=0;i<n;i++)
		{
			if(arr[i].marks<0)
			{
				cout<<arr[i].name<<endl;
				count++;
			}
		}
	//Average calculation
  float avg;
	for(int i=0;i<n;i++)
	{
		{
			sum=sum+arr[i].marks+count;
			avg=sum/n;
		}
	}
  cout<<"\nAverage marks is:"<<avg<<endl;
	//Highest marks and lowest marks
	int high=arr[0].marks;
	int low =arr[0].marks;
	for(int i=0;i<n;i++)
	{
		if(arr[i].marks>=0)
		{
			if(arr[i].marks>=high)
			high=arr[i].marks;

			if(arr[i].marks<=low && arr[i].marks>=0)
			low=arr[i].marks;
		}
	}
	cout<<"\nHighest marks:"<<high;
	cout<<"\nLowest marks:"<<low<<endl;
  int a[6];
  for(int i=0;i<n;i++)
  {
    if(arr[i].marks<50)
      {a[0]++;}
    else if(arr[i].marks<=60 && arr[i].marks>50)
      {a[1]++;}
    else if(arr[i].marks<=70 && arr[i].marks>60)
      {a[2]++;}
    else if(arr[i].marks<=80 && arr[i].marks>70)
      {a[3]++;}
    else if(arr[i].marks<=90 && arr[i].marks>80)
      {a[4]++;}
    else if(arr[i].marks<=100 && arr[i].marks>90)
      {a[5]++;}
  }
  int highest=a[0];
  int b;
	for(int i=0;i<n;i++)
	{
		if(a[i]>=0)
		{
			if(a[i]>=highest)
			highest=a[i];
      b=i;
		}
	}
  switch (b)
  {
    case 0: cout<<"Marks scored are highest between 0 and 50:"<<highest;
            break;
    case 1: cout<<"Marks scored are highest between 50 and 60:"<<highest;
            break;
    case 2: cout<<"Marks scored are highest between 60 and 70:"<<highest;
            break;
    case 3: cout<<"Marks scored are highest between 70 and 80:"<<highest;
            break;
    case 4: cout<<"Marks scored are highest between 80 and 90:"<<highest;
            break;
    case 5: cout<<"Marks scored are highest between 90 and 100:"<<highest;
            break;

  }
  return 0;
}
