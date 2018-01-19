#include <iostream>
#include<curses.h>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

//definition of the class node
class node{
public:
int data;
node * next;
node(){
data=0;
next=NULL; }
}*head,*tail;

//function prototypes
void insert();
void insertAt();
void deletenode();
void deleteAt(int pos,int count2);
int countItems();
void display();

int main()
{
int op;
char op2;
do{
cout<<"Enter Option\n1)Add Node at End of List\n2)Insert node at position\n3)Delete last node\n4)Delete node at a position\n5)Count number of items in the List\n6)Display List\n";
cin>>op;
switch(op)
{case 1:insert();
	break;
case 6: display();
	break;
case 2: insertAt();
	break;
case 3: deletenode();
	break;
case 4: {int pos;
	cout<<"\nEnter node position";
	cin>>pos;
	int count2;
	count2=countItems();
	deleteAt(pos,count2);}
	break;
case 5: {cout<<"\nThere are "<<countItems()<<" nodes present in the list.";}
	break;
};
cout<<"\nRun Again?";
cin>>op2;
}while(op2=='y');
return 0;}

//Function definitions start here:

//Function to insert a node at the end of the list
void insert()
{node *temp=new node;
int d;
cout<<"\nEnter data";
cin>>d;
if(head==NULL)
{temp->data=d;
head=temp;
tail=temp;
}
else{
temp->data=d;
tail->next=temp;
tail=temp;}
}

//Function to insert a node at any position 
void insertAt()
{node *temp=new node,*temp2=new node,*temp3= new node;
temp2=head;
int d,pos,count=1;
cout<<"Enter data and position of insertion" ;
cin>>d>>pos;
temp->data=d;
if((head==NULL)&&(pos>1))
cout<<"Linked List does not have that many elements";
else if(pos==1)
{temp->next=head;
head=temp;}
else{
while(count!=pos-1)
{temp2=temp2->next;
++count;}
temp3=temp2->next;
temp2->next=temp;
temp->next=temp3;}
}


//Function to delete the last node of the Linked List
void deletenode()
{node *temp=new node;
temp=head;
if(head==NULL)
cout<<"\nNo nodes present.";
else{
while((temp->next)->next!=NULL)
temp=temp->next;
}
node *temp2=new node;
temp2=temp->next;
delete temp2;
tail=temp;
tail->next=NULL;
}


//Function to delete node at the user-given position 
void deleteAt(int pos,int count2)
{node *temp=new node;
temp=head;
int count=1;
if(head==NULL)
	{cout<<"\nNo nodes present.";}
else if(pos>count2)
	{cout<<"\nLinked List does not have that many nodes present."; }
else if(pos==1)
	{head=head->next;}
else if(pos==count2)
	{deletenode(); }
else{
	while(count!=pos-1)
	{temp=temp->next;
	++count;}
	node *temp2=new node;
	temp2=(temp->next)->next;
	temp->next=temp2;
    }
}


//Function to count the number of nodes in the Linked List
int countItems()
{node *temp=new node;
temp=head;
int count=1;
if(head==NULL)
cout<<"\nNo nodes present.";
else
{while(temp!=NULL)
{temp=temp->next;
++count;}
return (count-1);
}
}


//Function to display the Linked List
void display()
{if(head==NULL)
cout<<"\nNo Nodes present.";
else{
node *temp=new node;
temp=head;
while(temp!=NULL)
{cout<<temp->data<<"->";
temp=temp->next;}
cout<<"NULL";
}
}



