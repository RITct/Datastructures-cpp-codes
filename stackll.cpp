#include<iostream>
using namespace std;


class stack
{
	
	struct node
	{
		int data;
		struct node *link;
	};


	struct node *top;

public:

	stack()
	{
		top=NULL;
	}
	void push(int );
	int pop();
	void display();
};


void stack::push(int a)
{
	struct node *p;
	p=new struct node;
	p->data=a;

	if(top==NULL)
	{
		top=p;
		top->link=NULL;
	}
	else
	{
		p->link=top;
		top=p;
	}
}

int stack::pop()
{
	int temp;

	if(top==NULL)
	{
		cout<<"||";
		return 0;
	}
	else
	{
		temp=top->data;
		top=top->link;
		return temp;
	}
}

void stack::display()
{
	struct node *temp;
	temp=top;
	while(temp!=NULL)
	{
		cout<<" "<<(temp->data);
		temp=temp->link;
	}
	cout<<"\n";

}


int main()
{
	stack one;
	int b,c;
	do
	{
		cout<<"1. push  2. pop  3. display  4. exit\n";
		cin>>b;
		switch(b)
		{
			case 1 : cout<<"ELEMENT: "; cin>>c;
					 one.push(c);break;

			case 2 : cout<<"-> "<<one.pop()<<"\n";break;

			case 3 : one.display();break;

			case 4 : b=-1;

		}
	}while(b!=-1);

}