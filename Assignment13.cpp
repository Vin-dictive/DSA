/*A palindrome is a string of character that‘s the same forward and backward. Typically,
punctuation, capitalization, and spaces are ignored. For example, ‖Poor Dan is in a droop‖ is
a palindrome, as can be seen by examining the characters ―poor danisina droop‖ and
observing that they are the same forward and backward. One way to check for a
palindrome is to reverse the characters in the string and then compare with them the
original-in a palindrome, the sequence will be identical. Write C++ program with functions-
1.to check whether given string is palindrome or not that uses a stack to determine
whether a string is a palindrome.
2. to remove spaces and punctuation in string, convert all the Characters to lowercase,
and then call above Palindrome checking function to check for a palindrome
3. to print string in reverse order using stack
*/
#include<iostream>
#include<string>

using namespace std;


string reverseStr(string str)
{
	int n = str.length();

	for (int i = 0; i < n / 2; i++)
			swap(str[i], str[n - i - 1]);

	n = str.length();
	for (int i = 0; i < n; i++)
	return str;
}

bool IsOperand(char ch)
{
  if((ch>='0'&&ch<='9')||(ch>='A'&&ch<='Z')||(ch>='a'&&ch<='z'))
  {
  return true;
  }
return false;
}

bool Isupper(char ch)
{
  if((ch>='A'&&ch<='Z'))
  {
  return true;
  }
return false;
}
//Poor Dan is in a droop
int main()
{
  string palin;
  string line="";
  string revline;
  cout<<"ENter the sentence to check palindrome:\n";
  getline(cin,palin);
  //converting up case to lower case
  for (auto& elem : palin)
  {
    if(Isupper(elem))
    {
      elem=elem+32;
    }
  }
  //removing spaces commas punctions
  for (auto& elem : palin)
  {
    if(IsOperand(elem))
    {
      line+=elem;
    }
  }

  cout<<endl<<line;
  revline=reverseStr(line);
  cout<<endl<<revline;

  if(revline == line)
  {
    cout<<"\nIts a Palindrome\n";
  }
  else
  {
    cout<<"\nNot a palindrome\n";
  }

  return 0;
}
