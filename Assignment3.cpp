/*Wap a program in c or cpp to store a matrix. Write functions for
1.Check whether the matrix is upper triangular or not
2.Compute summation of diagonal elements
3.Compute transpose of matrix
4.Compute addiiton, substraction and multiplication on 2 matrices*/
#include<iostream>
#include<stdio.h>
using namespace std;
class Matrix
{

	int m,n;
	int mat[8][8];
public:
	int  col()
	{
		return m;
	}

	int  row()
	{
		return n;
	}

	void insertion()
	{
		cout<<"Enter the size of columns and rows of the matrix:\n";
		cout<<"Column:";
		cin>>m;
		cout<<"Rows:";
		cin>>n;
		cout<<"Enter values into the matrix:"<<endl;
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
			{
				cin>>mat[i][j];
			}
		cout<<"your matrix is:"<<endl;
		for(int i=0;i<m;i++)
		{	for(int j=0;j<n;j++)
				{cout<<mat[i][j]<<"\t";}
		cout<<endl;
		}
	}

	void triangular()
	{
		int check=1;
		if(m!=n)
			cout<<"Cannot compute on non square matrix";
		else
			for(int i=1;i<m;i++)
				for(int j=0;j<i;j++)
				{
					if(mat[i][j]==0)
						check=0;
					else
						check=1;
				}
			if(check==0)
				cout<<"It is a triangular matrix\n";
			else
				cout<<"Not a triangular matrix\n";
	}

	void summation()
	{
		int sum=0;
		if(m!=n)
			cout<<"Cannot compute on non square matrix";
		else

			cout<<"Summation of diagonal matrix is:"<<endl;
			for(int i=0;i<m;i++)
				for(int j=0;j<n;j++)
				{
					if(i==j)
					sum=sum+mat[i][j];
				}
			cout<<sum<<endl;
	}

	void transpose()
	{
		cout<<"Transpose of matrix is:"<<endl;
		for(int i=0;i<m;i++)
		{	for(int j=0;j<n;j++)
				{cout<<mat[j][i]<<"\t";}
		cout<<endl;
		}
	}
	void add(Matrix x,Matrix y)
	{
		if(m!=x.col() && n!=x.row())
			cout<<"Cannot compute on non square matrix";
		else
			cout<<"Addition of matrix A and B"<<endl;
			for(int i=0;i<x.m;i++)
				{	for(int j=0;j<x.n;j++)
						{cout<<x.mat[i][j]+y.mat[i][j]<<"\t";}
				cout<<endl;
				}
	}

	void subs(Matrix x,Matrix y)
	{
		if(m!=x.col() && n!=x.row())
			cout<<"Cannot compute on non square matrix";
		else
		cout<<"Substraction of matrix A and B"<<endl;
		for(int i=0;i<x.m;i++)
			{	for(int j=0;j<x.n;j++)
					{cout<<x.mat[i][j]-y.mat[i][j]<<"\t";}
			cout<<endl;
			}
	}

	void mult(Matrix x,Matrix y)
	{
		if(n!=x.row())
			cout<<"Cannot compute on non square matrix";
		else
		cout<<"Multiplictaion of matrix A and B"<<endl;
		for(int i=0;i<x.m;i++)
			{	for(int j=0;j<x.n;j++)
					{cout<<x.mat[i][j]*y.mat[i][j]<<"\t";}
			cout<<endl;
			}
	}
};

int main()
{
	Matrix a;
	a.insertion();
	char ch='y';
	while(ch=='y' || ch=='Y')
		{
			int options;
			cout<<"\nWhat do u want to do?\n"<<endl;
			cout<<"1.Transpose of matrix A"<<endl;
			cout<<"2.Check whether the matrix is triangular or not"<<endl;
			cout<<"3.Summation of diagonal elements of the matrix"<<endl;
			cout<<"4.Add a Matrix B to Matrix A"<<endl;
			cout<<"5.Substract a Matrix B to Matrix A"<<endl;
			cout<<"6.Multiply a Matrix B to Matrix A"<<endl;
			cout<<"Option:";
			cin>>options;
			cout<<endl;

			switch(options)
			{
				case 1:
					a.transpose();
					break;
				case 2:
					a.triangular();
					break;
				case 3:
					a.summation();
					break;
				case 4:
					Matrix b;
					b.insertion();
					a.add(a,b);
					break;
				case 5:
					Matrix c;
					c.insertion();
					a.subs(a,c);
					break;
				case 6:
					Matrix d;
					d.insertion();
					a.mult(a,d);
					break;
			}
			cout<<"\nDo you want to do anything else?(y/n)"<<endl;
			cin>>ch;
		}
	return 0;

}
