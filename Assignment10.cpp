/*Implement C++ program for expression conversion as infix to postfix and its evaluation
using stack based on given conditions
i. Operands and operator, both must be single character.
ii. Input Postfix expression must be in a desired format.
iii. Only '+', '-', '*' and '/ ' operators are expected.*/
#include<iostream>
#include<stack>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
//#######################################################//
//Check for operand or not
//#######################################################//
bool IsOperand(char ch)
{
  if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
  {
  return true;
  }
return false;
}

bool IsOperandonly(char ch)
{
  if((ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
  {
  return true;
  }
return false;
}
//#######################################################//
//Check for operator or not
//#######################################################//
bool IsOperator(char C)
{
  if(C=='+'||C=='-'||C=='*'||C=='/'||C=='^')
  {
    return true;
  }
  return false;
}
//#######################################################//
//#######################################################//
bool IsLeftParenthesis(char ch)
{
  if(ch=='(')
  {
    return true;
  }
  return false;
}

bool IsRightParenthesis(char ch)
{
  if(ch==')')
  {
    return true;
  }
  return false;
}

//#######################################################//
//#######################################################//

bool Flag(char ch)
{
  if(!IsOperand(ch)||!IsOperator(ch)||!IsLeftParenthesis(ch)||!IsRightParenthesis(ch))
  {
    return false;
  }
  return true;
}

int IsRightAssociative(char op)
{
  if (op == '^')
  {
    return true;
  }
  return false;
}

int GetOperatorWeight(char op)
{
  int weight = -1;
  switch (op)
  {
    case '+':
    case '-':
    weight = 1;
    break;
    case '*':
    case '/':
    weight = 2;
    break;
    case '^':
    weight = 3;
    break;
  }
  return weight;
}

bool HasHigherPrecedence(char op1, char op2)
{
  int op1Weight = GetOperatorWeight(op1);
  int op2Weight = GetOperatorWeight(op2);

// If operators have equal precedence, return true if they are left associative
// BUT REMEMBER...return false, if right associative.
// if operator is left-associative, left one should be given priority.
if(op1Weight==op2Weight)
{
  if (IsRightAssociative(op1))
  {
    return false;
  }
  else
  {
    return true;
  }
}
return op1Weight > op2Weight ? true : false;
}

string InfixToPostfix(string expression)
{
  stack<char> S;
  string postfix = "";

  for (auto& elem : expression) //looping in strings
  {
      if (Flag(elem)) //gives false when an operator or operand is present
      {                //otherwise continues
          continue;
      }
      // If character is operator,
      //pop two elements from stack, perform operation and push the result back
      else if (IsOperator(elem))
      {
        while(!S.empty() && S.top()!='(' && HasHigherPrecedence(S.top(),elem))
        {
          postfix += S.top();//top element gets added
          S.pop();
        }
      S.push(elem);
      }
      else if (IsOperand(elem))
      {
        postfix += elem;
      }
      else if (elem == '(')
      {
        S.push(elem);
      }
      else if (elem == ')')
      {
        while (!S.empty() && S.top() != '(')
        {
          postfix += S.top();
          S.pop();
        }
      S.pop();
      }
  }

  while (!S.empty())
  {
      postfix += S.top();
      S.pop();
  }

  return postfix;
}

//#######################################################//
//#######################################################//


string reverseStr(string str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
			swap(str[i], str[n - i - 1]);

	n = str.length();
	for (int i = 0; i < n; i++)
	{
		if(str[i]=='(')
			str[i]=')';
		else  if(str[i]==')')
			str[i]='(';
	}

	return str;
}
//#######################################################//
//#######################################################//

string convert_check(string &token)
{
  char t;
//  cout<<"####2"<<endl;
  for (auto& elem1 : token) //looping in strings
  {
    if(IsOperandonly(elem1))
    {
      cout<<"Enter the value of "<<elem1<<":";
      cin>>elem1;
    //  cout<<"####3"<<endl;
      t=elem1;
      for (auto& temp : token) //looping in strings
      {
        if(temp==elem1)
        {
          //cout<<"####4"<<endl;
          temp=t;
        }
      }
    }
  }
  return token;
}
//#######################################################//
//#######################################################//
int evalPostfix(string expression)
{
  // stack is holding input numbers
  stack<int> stack;

  for (auto& elem : expression)
  {

    if (IsOperand(elem))
    {

      stack.push(elem - '0');
    }
    else
    {
      int a = stack.top();
      stack.pop();
      int b = stack.top();
      stack.pop();
      int result;
      switch (elem)
      {
        case '+': result = b + a; break;
        case '-': result = b - a; break;
        case '*': result = b * a; break;
        case '^': result = (int) pow((double) b, a); break;
      }
      stack.push(result);
    }
  }
  return stack.top();
}


//#######################################################//
//#######################################################//

//////////////////////////////////////////////////////////////////
////////////////////////////MAIN//////////////////////////////////
//////////////////////////////////////////////////////////////////
int main()
{
  string expression;
  string postfix;
  string prefix;
  int x;
  char y='y';
  int ch;
  cout<<"\n*********CONVERSION MENU*********\n";
  cout<<"\nENTER THE INFIX EXPRESSION:\n";
  getline(cin,expression);

  do
  {
    cout<<"\n*********CONVERT INFIX TO*********\n";
    cout<<"\n1.POSTFIX\n2.PREFIX\n3.CHANGE THE INFIX OPERATION\n4.EVALUATE\nEnter ur option:";
    cin>>ch;
    switch (ch)
    {
      case 1:
      postfix = InfixToPostfix(expression);
      cout<<"Postfix expression will be\n"<<postfix<<"\n";
      break;
      case 2:prefix=reverseStr(expression);
      prefix = InfixToPostfix(prefix);
      prefix = reverseStr(prefix);
      cout<<"Prefix expression will be\n"<<prefix<<"\n";
      break;
      case 3:
      cout<<"\nENTER THE INFIX EXPRESSION:\n";
      cin>>expression;
      break;
      case 4:
      convert_check(expression);
      //cout<<"###1"<<endl;
      x=evalPostfix(InfixToPostfix(expression));
      cout<<"Evaluation:"<<x;
      break;
      default: cout<<"Enter a Valid option!!";
    }
    cout<<"\nDo you wanna continue to CONVERSION menu?(y/n):";
    cin>>y;
  }while(y=='y');
return 0;
}
