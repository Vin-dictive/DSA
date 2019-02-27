/* Queues are frequently used in computer programming, and a typical example is the creation
of a job queue by an operating system. If the operating system does not use priorities, then
the jobs are processed in the order they enter the system. Write C++ program for simulating
job queue. Write functions to add job and delete job from queue*/

#include <iostream>
#include<stdlib.h>

using namespace std;

int main()
{
    int choice, i;
    char item[50];
    char arr_queue[100][50];
    int rear = 0;
    int front = 0;
    int exit = 1;

    cout << "\nWHat should i do next:-";
    do {
        cout << "\n\n Queue Main Menu";

        cout << "\n1.New job \n2.Complete Job \n3.Display Pending Jobs \nOthers to exit";
        cout << "\nEnter Your Choice : ";
        cin>>choice;
        switch (choice) {
            case 1:
                if (rear == 100)
                    cout << "\n## Queue Reached Max!!";
                else {
                    cout << "\nEnter The Job to be done : ";
                    cin>>arr_queue[rear++];
                  //cin>>item;
                    cout<<"\nJob has been queued!!";
                }
                break;
            case 2:
                if (front == rear)
                    cout << "\n## Queue is Empty!";
                else {
                    cout <<"Completed job  :" << arr_queue[front];
                    front++;
                }
                break;
            case 3:
                cout << "\n## Queue Size : " << (rear - front);
                for (i = front; i < rear; i++)
                    cout << "\nJobs Pending  : "<<endl<<i<<":" << arr_queue[i];
                break;
            default:
                exit = 0;
                break;
        }
    } while (exit);

    return 0;
}
