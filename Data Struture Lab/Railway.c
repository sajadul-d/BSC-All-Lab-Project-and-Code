// Railway Tricket Booking System using linked lists and Queues.

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define size 5


typedef struct NODE
{
	int tric_no;
	int age;
	char name[20];
	struct NODE *next;
} node;

node* deq();
void create();
int reserve(node*);
int cancel(int);
void enq(node*);
void display();


node *start;
node *front;
node *rear;
int count=0;
int num=0;

void create( )
{
	node *new;
	new=(node *)malloc(sizeof(node));
	new->tric_no=1;
	printf("Name: ");
	scanf("%s", new->name);
	printf("Age : ");
	scanf("%d", &new->age);
	start=new;
	new->next=NULL;
	num++;
	
}

int reserve(node *start)
{
	
	if(start==NULL)
	{
   		 create(start);
		 return 1;
	}
	else 
	{
	
	node *temp, *new_node;
	temp=start;
	while(temp->next!=NULL)
	{ 
	  temp=temp->next;
	}
	
	new_node=(node *)malloc(sizeof(node));
	
	printf("Name: ");
	scanf("%s", new_node->name);

	printf("Age : ");
	scanf("%d", &new_node->age);
	new_node->next=NULL;
	if(num<=size)
	{
		num++;
		new_node->tric_no=num;
		temp->next=new_node;
		
		return 1;
	}
	else
	{
		enq(new_node);
		return 0;
	}
}
}


int cancel(int tric)
{
	node *ptr, *preptr, *new;
	ptr=start;
	preptr=NULL;
	if(start==NULL)
	return -1;
	if(ptr->next==NULL && ptr->tric_no==tric)
		{
		start=NULL;
		num--;
		free(ptr);
		return 1;
		
		}
		
	else{	
	while(ptr->tric_no!=tric && ptr->next!=NULL)
		{
			preptr=ptr;
			ptr=ptr->next;
		}
		if(ptr==NULL && ptr->tric_no!=tric)
			return -1;
		else
			preptr->next=ptr->next;
		free(ptr);
		new=deq();
		while(preptr->next!=NULL)
			preptr=preptr->next;
		preptr->next=new;
		num--;
		return 1;
	
	}
}

void enq(node *new_node)
{
	if(rear==NULL)
	{
		rear=new_node;
		rear->next=NULL;
		front=rear;
	}
	else
	{
		node *temp;
		temp=new_node;
		rear->next=temp;
		temp->next=NULL;
		rear=temp;
	}
	count++;
}

node* deq()
{
	node *front1;
	front1=front;
	if(front==NULL)
		return NULL;
	else
	{
	    count-- ;
		if(front->next!=NULL)
		{
			front=front->next;
			front1->next=NULL;
			return front1;
		}
		else
		{
			front=NULL;
			rear=NULL;
			
			return front1;
		}
	}	
			
	
}


void display()
{
	node *temp;
	temp=start;
	while(temp!=NULL)
	{
		printf("\n Tricket Number: %d\n", temp->tric_no);
		printf("Name : %s\n\n", temp->name);
		temp=temp->next;
    }
    
}

int main()
{
	int choice, status=0,canc=0, tric=0;
	start=NULL;
	rear=NULL;
	front=NULL;
	
	
	
	printf("\t\t\t\t****RAILWAY Tricket Booking System****\t\t\t\t\n");
	int ch =0;
	while(ch!=4)
	{
	printf("\n\nDo you want to - \n Press 1 for Booking  a ticket? \n Press 2 for Cancel Booking \n Press 3 for Display passenger details \n press 4 for exiting\n\n");
	scanf("%d", &choice); 
	switch(choice)
	{	
		case 1 :  status=reserve(start);
	              if(status==0)
	                printf("\n Sorry sit is not available!! \n You are added to waiting list. Waiting list number %d", count);
	              else
	                printf(" \n Sit Booking Successful!!! Enjoy your journey! Your Tricket No is %d\n\n", num);
	                
	              break;
	        
	    case 2:   printf(" \n Give the Tricket number to be cancelled\n");
	              scanf(" %d", &tric);
	              if(tric>num)
	              printf("Invalid!!");
	              else
	              {
	              canc=cancel(tric);
	              if(canc==-1)
	              	printf("\n Your Tricket number is invalid!!\n");
	              else
	              	printf("\n Your tricket cancelled successfully!\n");
	              	}
	              break;
	              
	    case 3: display();
	    break;
	    case 4: exit(0);   
	    break;
	    default: printf("\n Your chouses are  Wrong !\n");       
	                           
		          
	
	}
	
}

}
