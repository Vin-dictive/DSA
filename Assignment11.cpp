/*Implement C++ program for expression conversion
a) infix to prefix,
b)prefix to postfix,
c) prefix to infix,
d) postfix to infix
e) postfix to prefix.
*/
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


//#######################################################//
//#######################################################//

bool Flag(char ch)
{
  if(!IsOperand(ch)||!IsOperator(ch))
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
      S.pop();//to pop '('
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

string getInfix(string exp)
{
    stack<string> s;
    for (int i=0; exp[i]!='\0'; i++)
    {
        if (IsOperand(exp[i]))
        {
         string op(1, exp[i]);
         s.push(op);
        }
        else
        {
          string op1 = s.top();
          s.pop();
          string op2 = s.top();
          s.pop();
          s.push("(" + op2 + exp[i] + op1 + ")");
        }
    }
    return s.top();
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

  do
  {
    cout<<"\n1.INFIX TO POSTFIX\n2.INFIX TO PREFIX\n3.POSTFIX TO INFIX\n4.PREFIX TO INFIX\n5.PREFIX TO POSTFIX\n6.POSTFIX TO PREFIX\n\nEnter ur option:";
    cin>>ch;
    switch (ch)
    {
      case 1:
			cout<<"\nENTER THE INFIX EXPRESSION:\n";
      cin>>expression;
      postfix = InfixToPostfix(expression);
      cout<<"Postfix expression will be\n"<<postfix<<"\n";
      break;
      case 2:
			cout<<"\nENTER THE INFIX EXPRESSION:\n";
      cin>>expression;
			prefix=reverseStr(expression);
      prefix = InfixToPostfix(prefix);
      prefix = reverseStr(prefix);
      cout<<"Prefix expression will be\n"<<prefix<<"\n";
      break;
			case 3:
			cout<<"\nENTER THE POSTFIX EXPRESSION:\n";
      cin>>expression;
      postfix = getInfix(expression);
      cout<<"Infix expression will be\n"<<postfix<<"\n";
      break;
      case 4:
			cout<<"\nENTER THE PREFIX EXPRESSION:\n";
      cin>>expression;
			prefix=reverseStr(expression);
			prefix = getInfix(prefix);
			prefix = reverseStr(prefix);
			cout<<"Infix expression will be\n"<<prefix<<"\n";
      break;
			case 5:
			cout<<"\nENTER THE PREFIX EXPRESSION:\n";
      cin>>expression;
			prefix=reverseStr(expression);
			prefix = getInfix(prefix);
			prefix = reverseStr(prefix);//now in infix
			prefix = InfixToPostfix(prefix);
			cout<<"Postfix expression will be\n"<<prefix<<"\n";
			break;
			case 6:
			cout<<"\nENTER THE POSTFIX EXPRESSION:\n";
      cin>>expression;
      postfix = getInfix(expression);
			postfix=reverseStr(postfix);
      postfix = InfixToPostfix(postfix);
      postfix = reverseStr(postfix);
      cout<<"Prefix expression will be\n"<<postfix<<"\n";
			break;
      default: cout<<"Enter a Valid option!!";
    }
    cout<<"\nDo you wanna continue to CONVERSION menu?(y/n):";
    cin>>y;
  }while(y=='y');
return 0;
}
