/*In Second year Computer Engineering class of M students, set A of students play cricket and
set B of students play badminton. Write C/C++ program to find and display-
i.
Set of students who play either cricket or badminton or both
ii. Set of students who play both cricket and badminton
iii. Set of students who play only cricket
iv.
Set of students who play only badminton
v.
Number of students who play neither cricket nor badminton
(Note- While realizing the set duplicate entries are to avoided)*/
#include <stdio.h>
#include <iostream>
using namespace std;

class sets
{
  int n,a,b,h;
  int roll[100][2];
public:
  void insert()
  {
    int t;
    //Cricket players
    cout<<"Enter no. of cricket players:";
    cin>>a;
    cout<<"Enter the roll no.:";
    for (int i=0;i<a; i++)
    {
      cin>>t;
      roll[t-1][0]=1;
    }
    //Badminton players
    cout<<"Enter no. of Badminton players:";
    cin>>b;
    cout<<"Enter the roll no.:";
    for (int i=0;i<b; i++)
    {
      cin>>t;
      roll[t-1][1]=1;
    }
  }
  void onlycric()
  {
    //Only Cricket
    cout<<"Roll nos of only cricketers are:\n";
    int counta=0;
    for(int i=0;i<n;i++)
    {
      if(roll[i][0]==1 && roll[i][1]==0)
      {
        cout<<i+1<<"\t";
        counta++;
      }
    }
    cout<<"\nTotal no. of cricketers only are:"<<counta<<"\n";
  }
  void onlybaddy()
  {
    //Only Badminton
    cout<<"Roll nos of only badminton players are:\n";
    int countb=0;
    for(int i=0;i<n;i++)
    {
      if(roll[i][1]==1 && roll[i][0]==0)
      {
        cout<<i+1<<"\t";
        countb++;
      }
    }
    cout<<"\nTotal no. of Badminton players only are:"<<countb<<"\n";
  }
  void both()
  {
    //Both cricket and Badminton
    cout<<"Both cricket and Badminton players are Roll nos.:\n";
    int countboth=0;
    for(int i=0;i<n;i++)
    {
      if(roll[i][0]==1 && roll[i][1]==1)
      {
        cout<<i+1<<"\t";
        countboth++;
      }
    }
    cout<<"\nTotal no. of Both cricket and Badminton players are:"<<countboth<<"\n";
  }
  void playnothing()
  {
    //play nothing
    cout<<"Who play nothing:";
    int countnothing=0;
    for(int i=0;i<n;i++)
    {
      if(roll[i][0]==0 && roll[i][1]==0)
      {
        cout<<i+1<<"\t";
        countnothing++;
      }
    }
    cout<<"\nWho play nothing:"<<countnothing<<"\n";
  }
  void either()
  {
    cout<<"Who play either cricket or badminton or Both:\n";
    int blah=0;
    for(int i=0;i<n;i++)
    {
      if(roll[i][0]==1 || roll[i][1]==1)
      {
        cout<<i+1<<"\t";
      }
    }
    cout<<"\nWho play either cricket or badminton or Both:"<<blah;
  }
  sets()
  {
    cout<<"Enter the no. of students:";
    cin>>n;
  }
};
int main()
{
  int v;
  sets s1;
  s1.insert();

  char y='y';
  do
  {
    cout<<"\nWhat you wanna do?\n";
    cout<<"\n1.Only cricketers\n"<<"2.Only Badminton players\n"<<"3.Both\n"<<"4.Who play nothing\n";
    cout<<"4.Either play either cricket or badminton or Both:\n";
    cout<<"\nWhats your choice:";
    cin>>v;
    cout<<"\n";
    switch (v)
    {
      case 1:
              s1.onlycric();
              break;
      case 2:
              s1.onlybaddy();
              break;
      case 3:
              s1.both();
              break;
      case 4:
              s1.playnothing();
              break;
      case 5:
              s1.either();
              break;
      default:
              cout<<"Wrong option";
              break;

    }
    cout<<"Wanna continue?";
    cin>>y;
  }while(y=='y');
  return 0;
}
