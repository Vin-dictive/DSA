/*Department of Computer Engineering has student's club named 'Pinnacle Club'. Students of
Second, third and final year of department can be granted membership on request. Similarly
one may cancel the membership of club. First node is reserved for president of club and last
node is reserved for secretary of club. Write C++ program to maintain club member‘s
information using singly linked list. Store student PRN and Name. Write functions to
a) Add and delete the members as well as president or even secretary.
b) Compute total number of members of club
c) Display members
d) Display list in reverse order using recursion
e) Two linked lists exists for two divisions. Concatenate two lists.*/
#include<iostream>
using namespace std;

class Node
{
public:
    int prn;
    string name;
    Node *next;

};


class Pclub
{
    Node *head=NULL,*start=NULL,*temp;
public:

    void create();
    void display();
    void del();
    void rev();
    void revre(Node *t);
    void total();
    void options(Pclub &p);
    Pclub operator +(Pclub);
    void operator =(Pclub p)
    {
      head=p.head;
    }

};

Pclub Pclub::operator +(Pclub x)
{
  Node *t=new Node;
  if(head==NULL)
  {
    head=x.head;
    return *this;
  }
  else if (head!=NULL)
  {
    t=head;
    while(t->next!=NULL)
    {
      t=t->next;
    }
    t->next=x.head;
    return *this;
  }
  else
  {
    cout<<"ADD MEMBERS TO THE GROUPS!!";
    return *this;
  }
}

void Pclub::total()
{
    Node *t=head;
    int count=0;
    while(t!=NULL)
    {
      t=t->next;
      count++;
    }
    cout<<"\nTOTAL NO. OF MEMBERS ARE: "<<count;

}

void Pclub::revre(Node *t)
{
    if(t==NULL)
    {
      return;
    }
    else
    {
      revre(t->next);
      cout<<"|"<<t->prn<<"::"<<t->name<<"|<-";
    }

}

void Pclub::rev()
{

    Node *temp=head;
    if(temp==NULL)
    {
      cout<<"\nZero element in section.";
      return;
    }
    else
    {
      revre(temp);
    }
}


void Pclub::del()
{
  if(head!=NULL)
  {
    cout<<"\n*****************DELETION MENU*****************\n1.DELETE PRESIDENT\n2.DELETE SECRETARY\n3.DELETE A MEMBER IN ANY POSITION(0 index)\n4.DELETE A MEMBER BY NAME.\n ";
    int n;
    cout<<"Your Choice:";
    cin>>n;
    switch(n)
    {
      case 1: if(head==NULL)
              {
                cout<<"\nTHERE IS NO PRESIDENT!!";
              }
              else
              {
                Node *temp=head;
                head=head->next;
                delete temp;
                cout<<"\nDELETED";
              }
              cout<<"\n******************************************\n";
              display();
              cout<<"\n******************************************\n";
              break;
      case 2: if(head==NULL)
              {
                cout<<"\nTHERE IS NO SECRETARY!!";

              }
              else if(head->next==NULL)
              {
                cout<<"\nTHERE IS NO SECRETARY!!";
              }
              else
              {
                Node *temp=head;
                while(temp->next->next!=NULL)
                {
                    temp=temp->next;
                }
                Node *p=temp->next;
                temp->next=NULL;
                delete p;
                cout<<"\nDeleted";
              }
              cout<<"\n******************************************\n";
              display();
              cout<<"\n******************************************\n";
              break;

      case 3: cout<<"\nENTER THE POSITION TO DELETE: ";
              int n,i;
              cin>>n;

              if(n<0)
               { cout<<"\nPOSITION MUST BE A POSITIVE NUMBER:";break;}
              if(n==0)
              {
                 cout<<"\nCHOOSE DELETE PRESIDENT OPTION!!";
              }
              else
              {
                  Node *temp=head;
                  if(temp==NULL)
                  {
                      cout<<"\nTHERE ARE NO MEMBERS!!";
                  }
                  else
                  {


                  for(i=0;i<n-1;i++)
                  {
                      if(temp->next!=NULL)
                      temp=temp->next;
                      else
                      {cout<<"\nNO MEMBER AT THIS POSITION EXISTS!!"; break;}
                  }
                  if(temp->next!=NULL)
                  {
                      if(temp->next->next==NULL)
                         {cout<<"\nCHOOSE DELETE SECRETARY OPTION!!";break;}
                      else {Node *p=temp->next;
                      temp->next=p->next;
                      delete p;cout<<"\nDELETED";}
                  }
                  else{cout<<"\nNO MEMBER AT THIS POSITION EXISTS"; break;}
                  }
              }
              cout<<"\n******************************************\n";
              display();
              cout<<"\n******************************************\n";
              break;
       case 4:string s;
              cout<<"\nENTER THE MEMBERS NAME:";
              cin>>s;
              int cnt=0;
              Node *temp=head;
              if(temp!=NULL)
              {
                if(temp->name==s)
                {
                        cout<<"\nCHOOSE DELETE PRESIDENT OPTION!!";
                }
                else
                {
                   while(temp->next!=NULL)
                   {
                      if(temp->next->name==s)
                         {
                             if(temp->next->next==NULL)
                              {cout<<"\nCHOOSE DELETE SECRETARY OPTION!!";break;}
                             else
                              {
                                Node *p=temp->next;
                                temp->next=p->next;
                                delete p;
                                cnt++;
                              }
                         }
                         else
                         {
                           temp=temp->next;
                         }
                   }
                   if(cnt==0)
                   {
                     cout<<"\nMEMBER WITH THIS NAME DOES NOT EXIST!!";
                   }
                   else
                   {
                     cout<<"\nDELETED";
                   }
                }
              }
              else
              {
                cout<<"\nMEMBER WITH THIS NAME DOES NOT EXIST!!";
              }
              cout<<"\n******************************************\n";
              display();
              cout<<"\n******************************************\n";
              break;



    }
  }
  else cout<<"ADD MEMBERS FIRST!!";

}


void Pclub::create()
{

    cout<<"\n****************INSERTION MENU***************\n";
    int ch;
    temp=new Node;
    cout<<"\nENTER:-\nPRN:";
    cin>>temp->prn;
    cout<<"NAME:";
    cin>>temp->name;
    temp->next=NULL;

    cout<<"\nINSERT AS \n 1.PRESIDENT \n 2.SECRETARY \n 3.MEMBER \n ";
    cout<<"YOUR CHOICE:";
    cin>>ch;
    switch(ch)
    {
        case 1: if(head==NULL)
                {
                    head=temp;
                    start=temp;
                }
                else
                {
                    temp->next=head;
                    head=temp;
                }
                cout<<"\n******************************************\n";
                display();
                cout<<"\n******************************************\n";
                break;
        case 2:
              if(start==NULL)
               {
                   cout<<"\nEnter president first.";
               }
               else
               {
               while(start->next!=NULL)
               {
                   start=start->next;
               }
               start->next=temp;
               }
               cout<<"\n******************************************\n";
               display();
               cout<<"\n******************************************\n";
              break;
        case 3:
              if(start==NULL || start->next==NULL)
              {
                  cout<<"\nENTER A PRESIDENT AND A SECRETARY FIRST!!";
              }
              else
              {
                  while(start->next->next!=NULL)
                  {
                      start=start->next;
                  }
                  temp->next=start->next;
                  start->next=temp;
                  start=start->next;    /*second last*/
              }
              cout<<"\n******************************************\n";
              display();
              cout<<"\n******************************************\n";
              break;
    }
}
void Pclub::display()
{
    temp=head;
    if(temp==NULL)
    {
        cout<<"THE GROUP IS EMPTY!!";
    }
    while(temp!=NULL)
    {
        cout<<"|"<<temp->prn<<"::"<<temp->name<<"|->";
        temp=temp->next;
    }
}

void Pclub::options(Pclub &p)
{
  char ch,ans;
  do
  {
    cout<<"\n1.ADD MEMBERS.\n2.DELETE.\n3.DISPLAY IN REVERSE FASHION.\n4.TOTAL IN THIS GROUP.\n";
    cout<<"\nYour Choice:";
    int q;
    cin>>q;
    switch(q)
    {
        case 1: do
                {
                  p.create();
                  cout<<"ADD MORE?:(y/n):";
                  cin>>ans;
                }while(ans=='y'||ans=='Y');
                break;
        case 2: p.del();
                break;
        case 3: p.rev();
                break;
        case 4: p.total();
                break;
       default: cout<<"\nENTER A VALID OPTIONS!!";
    }
    cout<<"\nDO YOU WANT TO ALTER THE GROUP? (y/n):";
    cin>>ch;
  }while(ch=='y'||ch=='Y');
}




int main()
{
    Pclub p1;
    Pclub p2;
    Pclub p3;
    char ch;
    int q;
    do
    {
        cout<<"\n************WELCOME*************";
        cout<<"\n**********WHAT TO DO?***********";

        cout<<"\n1.CREATE THE GROUP A.\n2.CREATE THE GROUP B.\n3.JOIN THE TWO GROUPS TOGETHER. ";
        cout<<"\nYour Choice:";
        cin>>q;
        switch(q)
        {
            case 1: p1.options(p1);
                    break;
            case 2: p2.options(p2);
                    break;
            case 3: p3=p1+p2;
                    cout<<"\n*************************************\n";
                    p3.display();
                    cout<<"\n*************************************\n";
                    break;
             default: cout<<"\nEnter valid operation.";
        }
        cout<<"\nCONTINUE TO MAIN MENU? (y/n)";
        cin>>ch;

    }while(ch=='y'||ch=='Y');



    return 0;

}
