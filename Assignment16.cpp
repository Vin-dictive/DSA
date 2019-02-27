/*Pizza parlor accepting maximum M orders. Orders are served in first come first served
basis. Order once placed can not be cancelled. Write C++ program to simulate the system
using circular queue using array*/
#include <iostream>
#define M 15

using namespace std;

class Queue
{
private:
    int items[M], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        if(front == 0 && rear == M - 1)
        {
            return true;
        }
        if(front == rear + 1)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if(front == -1) return true;
        else return false;
    }

    void enQueue(int element)
    {
        if(isFull())
        {
            cout << "Queue is full";
        }
        else
        {
            if(front == -1) front = 0;
            rear = (rear + 1) % M;
            items[rear] = element;
            cout << endl << "Inserted " << element << endl;
        }
    }

    int deQueue()
    {
        int element;
        if(isEmpty())
        {
            cout << "Queue is empty" << endl;
            return(-1);
        }
        else
        {
            element = items[front];
            if(front == rear)
            {
                front = -1;
                rear = -1;
            }
            else
            {
                front=(front+1) % M;
            }
            return(element);
        }
    }

    void display()
    {
        /* Function to display status of Circular Queue */
        int i;
        if(isEmpty()) {
            cout << endl << "Empty Queue" << endl;
        }
        else
        {
            cout << "Front -> " << front;
            cout << endl << "Items -> "<<endl;
            for(i=front; i!=rear;i=(i+1)%M)
                cout << items[i]<<endl;
            cout << items[i];
            cout << endl << "Rear -> " << rear;
        }
    }

};


int main()
{
    Queue q;
    int elem;
    int ch;
    int t;
    char y='y';
    while(y=='y')
    {
      cout<<"PIZZA PARLOR!!\n";
      cout<<"\n1.Add order number\n2.If order is completed\n3.Show Order numbers list\n";
      cout<<"Enter the choice:";
      cin>>ch;
      switch(ch)
      {
        case 1:
        cout<<"Order number:";
        cin>>t;
        q.enQueue(t);
        break;
        case 2:
        cout<<"Order number has been served!!";
        elem=q.deQueue();
        cout << endl << "Completed order is " << elem;
        break;
        case 3:
        q.display();
        break;
      }
      cout<<"\nDo you want to continue?";
      cin>>y;
    }


    return 0;
}
