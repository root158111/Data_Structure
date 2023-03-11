#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ANODE
{
	int power;
	int val;
	struct ANODE *next,*prev; 
};
struct ANODE * addfinal,* multfinal;
struct ANODE * generateanode()		//產生新的node 
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->prev=ptr->next=ptr;		
	return ptr;						
}
struct ANODE * generateanoderand(int pow)
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=rand()%10;				//製造n-1個數的次方數 
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr;						//這裡是函數的回傳值，指向配置的記憶體起始位址
}
struct ANODE * generateanodetitle(int pow)
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=rand()%9+1;			//製造開頭的數字(開頭不能為0) 
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr; 					//這裡是函數的回傳值，指向配置的記憶體起始位址
}
struct ANODE * generateanodeadd(int sum,int pow)		
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=sum;
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr;
}
int addrand(ANODE * temp,ANODE *current)
{
	current=current->next;
	temp->prev=current->prev;
	temp->next=current;
	current->prev->next=temp;
	current->prev=temp;
}
int printlist(ANODE * head)
{
	struct ANODE *ptr;
	printf("The first\n");
	ptr=head->next;			
	while(ptr!=head)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
}
int printfadd()
{
	struct ANODE * ptr;
	printf("The third\n");
	ptr=addfinal->next;
	while(ptr!=addfinal)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
	
}
int printfmult()
{
	struct ANODE * ptr;
	printf("The thord\n");
	ptr=multfinal->next;
	while(ptr!=multfinal)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
	
}
int countadd(ANODE * head,ANODE * head2)
{
	struct ANODE * ptr,* ptr2,*head3,*current;
	struct ANODE * addsum;
	ptr=head->prev;
	ptr2=head2->prev;
	int tempc,carry=0,pow=1;
	head3=generateanode();
			while((ptr->power<ptr2->power)&&(ptr!=head)) 
			{
				int s;
				s=ptr->val;
		
				addsum=generateanodeadd(s,pow);
				current=head3->next;
				while(current!=head3)
					current=current->next;
				addrand(addsum,current);
			
			    pow+=1;
				ptr=ptr->prev;
			}
		  
		while((ptr->power=ptr2->power)&&(ptr!=head)&&(ptr2!=head2))
		{
		
			int s;
			s=ptr->val+ptr2->val+carry;
			carry=s/10;
			tempc=s;
			s%=10;
		
			addsum=generateanodeadd(s,pow);
			current=head3->next;
			while(current!=head3)
				current=current->next;
			addrand(addsum,current);
			
		    pow+=1;
			ptr=ptr->prev;
			ptr2=ptr2->prev;
		}
		while(ptr!=head)
		{
			int s;
			s=ptr->val+carry;
			carry=s/10;
			tempc=s;
			s%=10;
		
			addsum=generateanodeadd(s,pow);
			current=head3->next;
			while(current!=head3)
				current=current->next;
			addrand(addsum,current);
			
			pow+=1;
			ptr=ptr->prev;
		}
		while(ptr2!=head2)
		{
			int s;
			s=ptr2->val+carry;
			carry=s/10;
			tempc=s;
			s%=10;
		
			addsum=generateanodeadd(s,pow);
			current=head3->next;
			while(current!=head3)
				current=current->next;
			addrand(addsum,current);
			
			pow+=1;
			ptr2=ptr2->prev;
		}
	carry=tempc/10;
	if(carry>0)
	{
		addsum=generateanodeadd(carry,pow);
		current=head3->next;
		while(current!=head3)
			current=current->next;
		addrand(addsum,current);
	}
	addfinal=head3;
	multfinal=head3;
	
}
int freelist(ANODE * freeadd)
{
	struct ANODE * ptr;
	while(freeadd->next!=freeadd)
	{
		ptr=freeadd->next;
		freeadd->next=ptr->next;
		ptr->next->prev=freeadd;
		free(ptr);
	}
}
int multcount(ANODE *head,ANODE *head2)
{
	free(multfinal);
	int c,num=0;
	struct ANODE * ptr,* ptr2,*temp;
	ptr=head->prev;
	int tempc,i=0,pow=1,dig=1;
	temp=generateanode();
	
	while(ptr!=head)
	{
		int carry=0;
		struct ANODE *head3,*current,*multsum;
		head3=generateanode();
		ptr2=head2->prev;	
		while(ptr2!=head2)
		{
			int s;
			s=ptr->val*ptr2->val+carry;	
			carry=s/10;
			tempc=s;
			s%=10;
		
			multsum=generateanodeadd(s,pow);
			current=head3->next;
			while(current!=head3)
				current=current->next;
			addrand(multsum,current);
		
			pow+=1;
			ptr2=ptr2->prev;
		}
		carry=tempc/10;
		if(carry>0)
		{
			multsum=generateanodeadd(carry,pow);
			current=head3->next;
			while(current!=head3)
				current=current->next;
			addrand(multsum,current);
		}
		countadd(temp,head3);
		temp=multfinal;
    	pow=dig+1;
    	dig+=1;
		ptr=ptr->prev;	
	}
}
main(){
	struct ANODE *head,*current,*current2,*temp,*temp2,*head2;
	int i,count=1,c,x;
	scanf("%d",&c);
	srand(time(NULL));
	head=generateanode();
	head2=generateanode();
	while(count<c){
		temp=generateanoderand(count);
		current=head->next;
		//while(current!=head)
		//	current=current->prev;
		addrand(temp,current);	
		count+=1;
	}
		temp=generateanodetitle(count);
		current=head->prev;
		while(current!=head)
			current=current->prev;
		addrand(temp,current);
		
		printlist(head);
		
		count=1;	
		scanf("%d",&x);
	while(count<x){	
		temp2=generateanoderand(count);
		current2=head2->prev;
		while(current2!=head2)
			current2=current2->prev;
		addrand(temp2,current2);
		count+=1;
	}
		temp2=generateanodetitle(count);
		current2=head2->prev;
		while(current2!=head2)
			current2=current2->prev;
		addrand(temp2,current2);
	
	printlist(head2);
	countadd(head,head2);
	printfadd();
	multcount(head,head2);
	printfmult();
	
	
}	
