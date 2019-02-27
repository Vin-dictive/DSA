/*Design a linked allocation system to represent and manipulate univariate polynomials with
integer coefficients (use circular linked lists with head nodes). Each term of the polynomial
will be represented as a node Thus. a node in this system will have three data members as
below:
Exponent
Link
Coefficient
To erase polynomials efficiently, we need to use an available-space list and associated
functions. The external (i.e.. for input or output) representation of a univariate polynomial
will be assumed to be a sequence of integers of the form: n, c 1 , e 1 ,c 2 . e 2 . c 3 . e 3 . . , c n e n
where e i represents an exponent and c i a coefficient; n gives the number of terms in the
polynomial. The exponents are in decreasing order — i.e., e 1 > e 2 > .... >e n .
Write and test the following functions:
1. istream&operator >>(istream& is, Polynomial& x): Read in an input polynomial
and convert it to its circular list representation using a head node.
2. ostream&operator<< (ostream&os, Polynomial& x): Convert x from its linked list
representation to its external representation and output it.
3. Polynomial:: Polynomial(const Polynomial& a) [Copy Constructor]: Initialize the
polynomial *this to the polynomial a.
4. const Polynomial& Polynomial :: operator=(const Polynomial& a) [Assignment
Operator]: Assign polynomial a to*this.
5. Polynomial:: Polynomial ( ) [Destructor]: Return all nodes of the polynomial *this
to the available-space list.
6. Polynomial operator+ (const Polynomial& a, const Polynomial& b) [Addition]:
Create and return the polynomial a + b. a and b are to be left unaltered.
7. Polynomial operator* (constPolynomial& a, constPolynomial& b) [Multiplication]:
Create and return the polynomial a * b. a and b are to be left unaltered.
8. floatPolynomial ::Evaluate(float x): Evaluate the polynomial *this at x and return the
result.*/
#include<iostream>
#include<string>
using namespace std;

class Node
{
public:
  int coeff;
	int pow;
	Node *next;
};

class Polynomial
{
public:
  Node *head=NULL;
//OVERLOADING  INSERTION AND OTHER OPERATORS
  friend  ostream & operator << (ostream &out, Polynomial &p)
  {
    Node *con=new Node;
    con=p.head;
    while(con!=NULL)
    {
      cout<<"Power of x^"<<con->pow<<" Coefficient:"<<con->coeff<<endl;
      con=con->next;
    }
  }

  friend istream & operator >> (istream &in, Polynomial &p)
  {
    string s;
    cout<<"Enter the Equation in the form of(ax@2+bx@1+c):-"<<endl;
  	cin>>s;
    int i=0,l=s.length();
  	int coeff,pow;
  	bool k=false;
  	Node* ret=new Node;
  	ret->next==NULL;
  	Node* start=ret;
  	while(i<l)
    {
  		coeff=0;
  		pow=0;
      //to check for minus in beginning of equation
  		if(s[i]=='-'&&i<l)
      {
  			k=true;
  			i++;
  		}
      //to check for x while traversing in the equation
  		if(s[i]=='x'&&i<l)
      {
  			coeff=1;
  		}
      //to store the Coefficient in coeff object
  		while(s[i]!='x'&&i<l)
      {
  			coeff=coeff*10+s[i]-'0';
  			i++;
  		}
      i+=2;
      //to store value of powers of x
  		while(i<l && s[i]!='+' && s[i]!='-')
      {
  			pow=pow*10+s[i]-'0';
  			i++;
  		}

  		i++;
  		start->coeff=coeff;
  		if(k)
        start->coeff*=-1;
  		start->pow=pow;
  		if(i<l)
      {
        cout<<endl;
  			start->next= new Node;
  			start=start->next;
  		}
  	}
    p.head=ret;
    return in;
  }

  Polynomial operator + (Polynomial p)
  {
    cout<<"\n\nADDITION OPERATION GIVES:\n\n";
    Node *x=new Node;
    Node *y=new Node;
    int q[20],s[20];
    int i=0;
    int count;
    int lol=0;
//4x^7+3x^3+9
//3x^5+5x^2+5
//5x^99+3x^43+2x^4+3
//7x^88+4x^40+3x^4+2
    x=head;
    y=p.head;

    while(x!=NULL)
    {
      q[i]=x->pow;
      s[i]=x->coeff;
      i++;
      count =i;
      x=x->next;
    }

    while(y!=NULL)
    {
      for(int j=0;j<count;j++)
      {

        if(q[j]==y->pow)
        {
          s[j]+=y->coeff;
          lol++;
        }
        else if(q[i-1]!=y->pow)
        {

          q[i]=y->pow;
          s[i]=y->coeff;
          i++;

        }
      }

    y=y->next;
    }

    for(int j=0;j<i-lol;j++)
    {
      cout<<"+"<<s[j]<<"x^"<<q[j]<<"  ";

    }
    return p;
  }




/*
  Polynomial multiply(Polynomial p,Polynomial q)
  {

    cout<<"\n\n\nMULTIPLICATION\n\n\n";
    int deg = p.head->pow + q.head->pow;
    Node *temp=new Node;
    Node *t1=new Node;
    Node *t2=new Node;
    Node *start=new Node;
    //################################################//

    //################################################//
    for(int i=deg; i>=0; i--)
    {
      t1=p.head;
      t2=q.head;
      temp->pow=i;
      temp->coeff=0;
      temp->next=NULL;
      while(t1!=NULL)
      {
        while(t2!=NULL)
        {
          if(( t2->pow + t1->pow )== i)
          {
            temp->coeff+=(t1->coeff*t2->coeff);

          }
          //###########################################//


          //###########################################//

          t2=t2->next;
        }
        t2=q.head;

        t1=t1->next;
      }
      if(temp->coeff!=0)
      {
        // cout<<"Power of x^"<<temp->pow;
        // cout<<" Coefficient:"<<temp->coeff<<endl;
        cout<<"+"<<temp->coeff<<"x^"<<temp->pow;
      }
    }


  }
*/
Polynomial operator * (Polynomial q)
{

  cout<<"\n\nMULTIPLICATION OPERATION GIVES:\n\n";
  int deg = head->pow + q.head->pow;
  Node *temp=new Node;
  Node *t1=new Node;
  Node *t2=new Node;
  Node *start=new Node;
  //################################################//

  //################################################//
  for(int i=deg; i>=0; i--)
  {
    t1=head;
    t2=q.head;
    temp->pow=i;
    temp->coeff=0;
    temp->next=NULL;
    while(t1!=NULL)
    {
      while(t2!=NULL)
      {
        if(( t2->pow + t1->pow )== i)
        {
          temp->coeff+=(t1->coeff*t2->coeff);

        }
        //###########################################//


        //###########################################//

        t2=t2->next;
      }
      t2=q.head;

      t1=t1->next;
    }
    if(temp->coeff!=0)
    {
      // cout<<"Power of x^"<<temp->pow;
      // cout<<" Coefficient:"<<temp->coeff<<endl;
      cout<<"+"<<temp->coeff<<"x^"<<temp->pow<<"  ";
    }
  }
}
Polynomial ()
{

}
Polynomial (const Polynomial &p)
{
  head=p.head;
  head->pow =p.head->pow;
}

void operator = (const Polynomial &p)
{
  head=p.head;
  head->pow =p.head->pow;
}

~Polynomial ()
{
  cout<<endl;
  cout<<"**********Destructor********";
  cout<<endl;

}
};


int main()
{

  Polynomial p;
  cout<<"\nEnter First Polynomial:\n";
  cin>>p;
  cout<<p;
  Polynomial q(p);

  cout<<"\n\n\nEnter Second Polynomial:\n";
  cin>>q;
  cout<<q;
  char y='n';
  do
  {
    cout<<"\nOperation to be conducted:\n";
    cout<<"1.ADDITION\n2.MULTIPLY \n";
    cout<<"Option:";
    int x;
    cin>>x;
    switch(x)
    {
      case 1:p+q;
      break;
      case 2:p*q;
      cout<<endl;
      //m.multiply(p,q);
      break;

    }
    cout<<"\n\n\nu wanna continue?(y/n):";
    cin>>y;
  }while(y=='y');

  return 0;


}
