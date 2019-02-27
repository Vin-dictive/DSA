/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<iostream>

using namespace std;

bool begining(char ch)
{
	if(ch=='('||ch=='{'||ch=='[')
		return true;
	else
		return false;
}

bool ending(char ch1,char ch2)
{
	if(ch1=='(')
    {
        if(ch2==')')
        return true;
        else return false;
    }
    else if(ch1=='{')
    {
        if(ch2=='}')
        return true;
         else return false;
    }
    else if(ch1=='[')
    {
        if(ch2==']')
        return true;
         else return false;
    }
    return false;
}

int main()
{
	string expression;
	cin>>expression;
	int flag=0;
	int n=expression.length();
	for(int i=0;i<n;i++)
	{
		if(begining(expression[i]))
		{
			for(int j=0;j<n;j++)
				if(ending(expression[i],expression[j]))
				{
					flag=1;
				}	
				else
					flag=0;
					break;
		}
	}
	if(flag==1)
	{
		cout<<"BALANCED";
	}
	else cout<<"UNBALANCED";
	return 0;
}
