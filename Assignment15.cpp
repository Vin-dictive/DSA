#include <iostream>
#include <cstdlib>

using namespace std;

struct Node
{
  int data;
  int priority;
  Node *next;
};

class Priority_Queue
{
  Node *front, *rear;
public:
  Priority_Queue()
  {
    front=NULL;
    rear=NULL;
  }
  void enqueue();
  int dequeue();
  void show();
};


void Priority_Queue::enqueue()
{
  Node *temp;
  temp=new Node;
  cout<<"ENTER THE VALUE : ";
  int a,b;
  cin>>a;
  cout<<"ENTER THE PRIORITY : ";
  cin>>b;
  temp->data=a;
  temp->priority=b;
  temp->next=NULL;
  if(front==NULL)
    front=rear=temp;
  else
  {
    if(front->next==NULL)
    {
      if(temp->priority<front->priority)
      {
        temp->next=front;
        front=temp;
      }
      else if(temp->priority>=front->priority)
      {
        rear->next=temp;
        rear=temp;
      }
    }

    else
    {
      Node *t;
      t=front;
      if(front->priority>temp->priority)
      {
        temp->next=front;
        front=temp;
        return;
      }
      if(rear->priority<=temp->priority)
      {
        rear->next=temp;
        temp->next=NULL;
        rear=temp;
        return;
      }
      while(t->next->priority<=temp->priority)
        t=t->next;
      temp->next=t->next;
      t->next=temp;
    }
  }
}

void Priority_Queue::show()
{
  Node *t;
  t=front;
  if(front==NULL)
  {
    cout<<"Empty queue!!\n";
    return;
  }
  cout<<"FRONT|->|";
  while(t!=NULL)
  {
    cout<<t->data<<"|PRIORITY="<<t->priority<<"|->";
    t=t->next;
  }
  cout<<"|REAR"<<endl;
}

int Priority_Queue::dequeue()
{
  int val=-1;
  if(front==NULL)
    return val;
  else
  {
    val=front->data;
    Node *temp;
    temp=front;
    front=front->next;
    delete temp;
    return val;
  }
}

int main()
{
  Priority_Queue p;
  int a;
  int ch=0;
  while(ch!=4)
  {
    cout<<"********* QUEUE *********\n";
    cout<<"1. ADD TO QUEUE\n2. REMOVE FROM QUEUE\n3. SHOW QUEUE\n4. EXIT\nEnter choice: ";
    cin>>ch;
    switch(ch)
    {
      case 1:
        p.enqueue();
        break;
      case 2:
        a=p.dequeue();
        if(a==-1)
          cout<<"Empty queue!!\n";
        else
          cout<<"REMOVED "<<a<<"!!\n";
        break;
      case 3:
        p.show();
        break;
      case 4:
        break;
      default:
        cout<<"WRONG INPUT\n";
    }
  }
  return 0;
}
