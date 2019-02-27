/*The ticket booking system of Cinemax theater has to be implemented using C++ program.
There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained
to keep track of free seats at rows. Assume some random booking to start with. Use array to
store pointers (Head pointer) to each row. On demand
a) The list of available seats is to be displayed
b) The seats are to be booked
c) The booking can be cancelled.*/
#include<iostream>
#include<string>
using namespace std;

class node
{
public :
    char data;
    int id;
    string pwd;
    node *prev;
    node *next;
    node()
    {
        id=0;
        pwd='o';

    }
};

class node1
{
public:
    int id;
    string pwd;
    node1 *next1;
};

class list
{
    node1* head1=NULL;
    node1* start1=NULL;
public:
    int create(int ,string);
    int check(int,string);
    int check1(int ,string);
};

class hall
{
    node * head[10];
    node * start[10];
public:
    hall();
    void display();
    void books(int ,string);
    void cancel(int ,string);
    void bookc(int  ,string);
    void booked(int ,string);
    void available();
};

hall::hall()
{
    int i,j;
    for(i=0;i<10;i++)
    {
        head[i]=NULL;
        start[i]=NULL;
    }
    for(i=0;i<10;i++)
    {
        for(j=0;j<7;j++)
        {
            node* temp=new node;
            temp->prev=temp;
            temp->next-temp;
            temp->data='-';
            if(head[i]==NULL)
            {
                head[i]=temp;
                start[i]=temp;
            }
            else
            {
                temp->prev=start[i];
                start[i]->next=temp;
                start[i]=start[i]->next;

            }
        }
        start[i]->next=head[i];
        head[i]->prev=start[i];
        start[i]=start[i]->next;
    }

}
void hall::display()
{
    int i,j;

    cout<<"  ";

    for(i=0;i<7;i++)
    {
        cout<<i<<"   ";
    }
    cout<<"\n";
    for(i=0;i<10;i++)
    {
        cout<<i<<" ";

        for(j=0;j<7;j++)
        {

            cout<<start[i]->data<<"   ";
            start[i]=start[i]->next;
        }
        cout<<"\n";

    }
}

void hall::books(int q,string w)
{
    this->display();
    int n,i,a,b,j;
    cout<<"\nENTER NO. OF TICKETS: ";
    cin>>n;
    if(n>7)
        cout<<"\nMAX. 7 SEATS CAN BE BOOKED PER USER";
    else if(n<0)
        cout<<"\nENTER A VALID NUMBER OF TICKETS U WANNA BOOK!!";
    else if(n==0)
        cout<<"\nTHANK U";
    else
    {
        for(i=1;i<=n;i++)
        {
            cout<<"\n"<<i<<" SEAT: ";
            cin>>a>>b;
            if(a<0 || a>9 || b<0 || b>6)
             {
                  cout<<"\ENTER A VALID SEAT NUMBER!!";
                   i--;
             }
             else
             {
                 for(j=0;j<7;j++)
                 {
                     if(j==b)
                     {
                         if(start[a]->data=='-')
                         {
                             start[a]->data='*';
                             start[a]->id=q;
                             start[a]->pwd=w;
                             cout<<"\nYOUR SEATS HAVE BEEN BOOKED!!";
                             cout<<"\n      ENJOY THE SHOW!!";
                         }
                         else
                         {
                             cout<<"\nTHIS SEAT WAS ALREADY BOOKED!!";
                             i--;
                         }
                    }
                    start[a]=start[a]->next;
                 }
             }
        }
    }

}

void hall::cancel(int q,string w)
{
    int n,i,a,b,j;
    this->display();
    cout<<"\nENTER THE NO OF TICKETS U WANNA CANCEL: ";
    cin>>n;
    if(n<0)
    {
        cout<<"\nENTER A VALID NUMBER";
    }
    else if(n==0)
    {
        cout<<"\nTHANK U";
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            cout<<"\n"<<i<<" SEAT: ";
            cin>>a>>b;
            if(a<0 || a>9 || b<0 || b>6)
            {
               cout<<"\nSUCH A SEAT NUMBER DOES NOT EXISTS!!";
            }
            else
            {
                for(j=0;j<7;j++)
                {
                    if(j==b)
                    {
                        if(start[a]->data=='*' && start[a]->id==q && start[a]->pwd==w)
                        {
                            start[a]->data='-';
                            cout<<"\nTHIS SEAT HAS BEEN CANCELLED";
                        }
                        else
                        {
                            cout<<"\nCANNOT CANCEL SINCE THE TICKET WAS NOT BOOKED BY U!!";
                        }
                    }
                    start[a]=start[a]->next;
                }
            }
        }
    }
}

void hall::bookc(int q, string w)
{
    this->display();
    cout<<"\nENTER THE NO> OF SEATS U WANNA BOOK: ";
    int n,i,j,a,b,count=0,max=0;
    cin>>n;
    if(n<0)
    {
        cout<<"\nENTER UR STARTING SEAT NO:";
    }
    else if(n>7)
    {
        cout<<"\nTHAT MANY SEATS CANNOT BE BOOKED!";
    }
    else if(n==0)
    {
        cout<<"\nTHNAK U ";
    }
    else
    {
        cout<<"\nENTER UR STARTING SEAT NO:";
        cin>>a>>b;
        if(a<0 || a>9 || b<0 || b>6)
            {
               cout<<"\nSuch seat no. doesnot exists.";
            }
       else
       {
           for(i=0;i<7;i++)
           {
               if(i>=b && i<(b+n))
               {
                   if(start[a]->data=='-')
                   {
                       count++;
                   }
                   else
                   {
                       count=0;
                   }
                   if(count>max)
                   {
                       max=count;
                   }
               }
               start[a]=start[a]->next;
           }
           if(max<n)
           {
               cout<<"\n"<<n<<" GROUP SEATS FROM "<<"( "<<a<<" "<<b<<" )"<<" ARE NOT AVAILABLE!!";
           }
           else if(max==n)
           {
               for(i=0;i<7;i++)
            {
                if(i>=b && i<(b+n))
                {
                   start[a]->data='*';
                   start[a]->id=q;
                   start[a]->pwd=w;
                }
               start[a]=start[a]->next;
            }
            cout<<"\n"<<n<<" GROUPED SEATS "<<"( "<<a<<" "<<b<<" ) HAVE BEEN BOOKED!!ENJOY THE SHOW!!";
           }
       }

    }
}

void hall::booked(int q,string w)
{
    int i,j,m=0;
    for(i=0;i<10;i++)
    {
        for(j=0;j<7;j++)
        {
            if(start[i]->data=='*' && start[i]->id==q && start[i]->pwd==w)
            {
                cout<<"\nSeat no : ( "<<i<<" "<<j<<" )";
                m++;
            }
            start[i]=start[i]->next;
        }
    }
    if(m==0)
    {
        cout<<"\nYOU DO NOT HAVE ANY BOOKINGS";
    }
}

void hall::available()
{
    this->display();
    cout<<"\nAVAILABILITY:\n";
    int i,j,count,max,sum;

    for(i=0;i<10;i++)
    {
        count=0;
        max=0;
        sum=0;
        cout<<"\nROW "<<i<<" : ";
        for(j=0;j<7;j++)
        {

            if(start[i]->data=='-')
            {
                count++;
                sum++;
            }

            else
            {
                count=0;
            }
            if(count>max)
            {
                max=count;
            }

            start[i]=start[i]->next;

        }
        cout<<"TOTALLY "<<sum<<" SEATS ARE AVAILABLE AND GROUP SEATS AVAILABLE ARE "<<max ;


    }
}

int list::create(int a, string s)
{
    node1 * temp1=new node1;
    temp1->next1=NULL;
    temp1->id=a;
    temp1->pwd=s;

    if(this->check1(a,s))
    {
            if(head1==NULL)
         {
             head1=temp1;
             start1=temp1;
             cout<<"\nID HAS BEEN CREATED. PLS LOGIN TO CONTINUE.\n";
             return 1;
         }
            else
            {
               start1->next1=temp1;
               start1=start1->next1;
               cout<<"\nID HAS BEEN CREATED. PLS LOGIN TO CONTINUE.\n";
               return 1;
            }

    }
    else
    {
        cout<<"\nID ALREADY EXISTS.TRY ANOTHER ONE";
        return 0;
    }

}

int list::check(int a,string s)
{

    node1* temp1=head1;
    while(temp1!=NULL)
    {
        if(temp1->id==a && temp1->pwd==s)
        {

            return 0;

        }
        temp1=temp1->next1;
    }
    return 1;

}
int list::check1(int a,string s)
{

    node1* temp1=head1;
    while(temp1!=NULL)
    {
        if(temp1->id==a)
        {

            return 0;

        }
        temp1=temp1->next1;
    }
    return 1;

}




void welcome(int q, string w, hall &h)
{

    int z;
    char c;
    cout<<"_______________________________________________\n";
    cout<<"          LOGGED IN AS "<<"ID: "<<q<<endl;
    cout<<"_______________________________________________\n";

    do
    {
        cout<<"\n1.CHECK AVAILABILITY\n2.BOOK SEATS BY NUMBER\n3.BOOK GROUP SEATS\n4.CANCEL SEATS\n5.YOUR BOOKED SEATS\n6.LOGOUT:-";
        cout<<"\nENTER UR CHOICE: ";
        cin>>z;
        cout<<"\n\n";

        switch(z)
        {
            case 1: h.available();
                     break;
            case 2: h.books(q,w);
                     break;
            case 3: h.bookc(q,w);
                     break;
            case 4: h.cancel(q,w);
                     break;
            case 5: h.booked(q,w);
                     break;
            case 6: return;
            default: cout<<"\nEnter valid operation.";
        }
        cout<<"\nDo you want to continue?(y/n): ";
        cin>>c;
    }while(c=='y'||c=='Y');
}

int main()
{
    list l;
    hall h;
    char e;
    int q,m;
    string w;
    int r;
    do
    {
        int x;
        cout<<"_______________________________________________\n";
        cout<<"              WELCOME TO CINEMAX\n";
        cout<<"\n1.CREATE ID\n2.LOG IN\n3.EXIT\n";
        cout<<"\nENTER UR OPTION: \n";
        cin>>x;
        cout<<"_______________________________________________\n";

        switch(x)
        {
            case 1: cout<<"\n         NEW ID NUMBER: ";
                    cin>>q;
                    cout<<"\n         YOUR PASSWORD: ";
                    cin>>w;
                    r=l.create(q,w);

                   break;
            case 2:
                    cout<<"\n         ENTER ID NUMBER: ";
                    cin>>q;
                    cout<<"\n         ENTER PASSWORD: ";
                    cin>>w;
                    if(l.check(q,w))
                    {
                        cout<<"\nID DOES NOT EXIST!!";

                    }
                    else
                    {
                        welcome(q,w,h);
                    }
                    break;
            case 3: m=0;
                    break;
            default: cout<<"\nERROR!!";

        }


    }while(m);
    return 0;
}
