/*Write C++ program for sparse matrix realization and operations on it-
transpose, Fast transpose and addition of two matrices*/
#include<iostream>

using namespace std;

class node
{
	public:
	node* next;
	int row;
	int col;
	int val;
};

class sparse
{
	node *head,*tail;
	int r,c;
	public:
	sparse();
	void create_s(int,int,int);
	void create(int ,int);
	void transpose();
	void add(sparse);
	void display();
};
void sparse :: create_s(int a,int b ,int c)
{
						node* temp=new node;
						temp->row=a;
						temp->col=b;
						temp->val=c;
						temp->next=NULL;
						if (head==NULL)
							head=tail=temp;
						else
							{
								tail->next=temp;
								tail=temp;
							}

}
sparse :: sparse()
{
	head=NULL;
}


void sparse :: create(int n,int m)
{
	int a;
	node* temp;
	r=n;
	c=m;
	for (int i=0;i<n;i++)
		for (int j=0;j<m;j++)
			{
				cout<<"Enter the elements : ";
				cin>>a;
				if (a!=0)
					{
						create_s(i,j,a);
					}
			}
			display();
}

void sparse :: transpose()
{
	node* temp;
	temp=head;
	while(temp!=NULL)
	{
		int tmp=temp->row;
		temp->row=temp->col;
		temp->col=tmp;
		temp=temp->next;
	}
	display();
}

void sparse :: add(sparse s)
{
	node *temp1,*temp2;
	temp1=head;
	sparse s1;
	while(temp1!=NULL)
	{
		temp2=s.head;
		while(temp2!=NULL)
		{
			if ((temp1->row==temp2->row)&&(temp1->col==temp2->col))
				{
					s1.create_s(temp1->row,temp1->col,temp1->val+temp2->val);
				}
				temp2=temp2->next;
		}
		temp1=temp1->next;
	}
	s1.display();
}
void sparse :: display()
{
	node *temp;
	cout<<"\n\n\t\tCompact Matrix\n\n";
	temp=head;
	cout<<"Row    : ";
	while(temp!=NULL)
		{
		  cout<<temp->row<<" ";
		  temp=temp->next;
		}
		cout<<"\n";
	temp=head;
	cout<<"Column : ";
	while(temp!=NULL)
		cout<<temp->col<<" ",temp=temp->next;
		cout<<"\n";
	temp=head;
	cout<<"Value  : ";
	while(temp!=NULL)
		cout<<temp->val<<" ",temp=temp->next;
	cout<<"\n";
}




int main()
{
	sparse s,s1;
	int r,c,r1,c1;
	char cha;
		do{
		    cout<<"Enter the Row :";
        cin>>r;
        if(r<=0)
            {
                cout<<"Wrong Input !! \n";
            }
        }while(r<=0);

		do{
		    cout<<"Enter the Column :";;
        cin>>c;
        if(c<=0)
            {
                cout<<"Wrong Input !! \n";
            }
        }while(c<=0);

			int ch;
			s.create(r,c);
        do
        {
	    cout<<"\n**************MENU**************\n";
	    cout<<"1.To Find transpose of sparse matrix \n";
			cout<<"2.To Add the two sparse matrix \n";
			cout<<"3.Exit\n";
			cout<<"Enter your choice : ";
			cin>>ch;
			int flag=0;
			switch(ch)
			{
				case 1 : s.transpose();
					break;
				case 2 :

			do{
				    cout<<"Enter the Row :";
                    cin>>r1;
                    if(r1<=0)
                        {
                            cout<<"Wrong Input !! \n";
                        }
                if(r!=r1)
				{
					cout<<"Rows are not equal!!\n";
				}
			}while(r1<=0 || r!=r1);

			do{
				    cout<<"Enter the Column :";;
                    cin>>c1;
                    if(c1<=0)
                        {
                            cout<<"Wrong Input !! \n";
                        }
                if(c!=c1)
				{
					cout<<"Columns are not equal!!\n";
				}
			}while(c1<=0 || c!=c1);

				s1.create(r1,c1);
				s.add(s1);
			  break;
				case 3 :
				    return 0;
				default : cout<<"\n\n\tWrong Choice!!\n\n";
			}
			cout<<"\nDo you want to continue?\n";
			cin>>cha;
            }while(cha=='y'||cha=='Y');

}
