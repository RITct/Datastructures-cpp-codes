#include<iostream>
using namespace std;


class que
{
	
	struct node
	{
		int data;
		struct node *link;
	};


	struct node *rear,*front;

public:

	int size;
	que()
	{
		rear=NULL;
		front=NULL;
	}
	void push(int );
	int pop();
	void display();
};


void que::push(int a)
{
	struct node *p;
	p=new struct node;
	p->data=a;

	if(rear==NULL)
	{
		rear=p;
		rear->link=NULL;
		front=rear;
	}
	else
	{
		rear->link=p;
		rear=p;
		rear->link=NULL;
	}
}

int que::pop()
{
	int temp;
	struct node *t;

	if(front==NULL)
	{
		cout<<"||";
		return 0;
	}
	else if(front==rear)
	{
		t=front;
		temp=front->data;
		rear=NULL;
		front=NULL;
		delete t;
		return temp;
	}
	else
	{
		t=front;
		temp=front->data;
		front=front->link;
		delete t;
		return temp;
	}
}

void que::display()
{
	struct node *temp;
	temp=front;
	while(temp!=NULL)
	{
		cout<<" "<<(temp->data);
		temp=temp->link;
	}
	cout<<"\n";

}


int main()	
{
	que one;
	int b,c;
	cout<<"Size of que :";cin>>one.size;
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