#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ANODE
{
	int power;
	int val;
	struct ANODE *next,*prev; 
};
struct ANODE * addfinal,* multfinal; 	//�̫�s�b�o�[�k���k 
struct ANODE * generateanode()		//domedone
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->prev=ptr->next=ptr;
	return ptr;
}
struct ANODE * generateanoderand(int pow)	//�ͦ��üƥ� 
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=rand()%10;
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr;
}
struct ANODE * generateanodetitle(int pow) 	//�}�Y����O0 �t�~���B�z 
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=rand()%9+1;
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr;
}
struct ANODE * generateanodeadd(int sum,int pow)	//��նüƧ@�[�k!���o�[�k 
{ 
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=sum;
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr;
}

int addrand(ANODE * temp,ANODE *current)  	//��ƭȴ��J�쵲�� 
{
	current=current->next;
	temp->prev=current->prev;
	temp->next=current;
	current->prev->next=temp;
	current->prev=temp;
}
int printlist(ANODE * head)				//�L�üƪ��� 
{
	struct ANODE *ptr;
	printf("---------�üƲ���---------\n");
	ptr=head->next;
	while(ptr!=head)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
}
int printfadd()							//�L�[�k�᪺���G 
{
	struct ANODE * ptr;
	printf("---------�[�k---------\n");
	ptr=addfinal->next;
	while(ptr!=addfinal)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
	
}
int printfmult()						//�L���k�᪺���G 
{
	struct ANODE * ptr;
	printf("---------���k---------\n");
	ptr=multfinal->next;
	while(ptr!=multfinal)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
	
}
int countadd(ANODE * head,ANODE * head2)		//�@�[�k���a�� 
{
	struct ANODE * ptr,* ptr2,*head3,*current;
	struct ANODE * addsum;
	ptr=head->prev;				//ptr��1�ի���head������ 
	ptr2=head2->prev;			//ptr2��2�ի���head������
	int tempc,carry=0,pow=1;
	head3=generateanode();			//�̫�s��[�k���a��(�B���)�}�Y 
			while((ptr->power<ptr2->power)&&(ptr!=head)) 	//�n�Ϩ�Ӹ�ƥH����ۦP���覡���B�� 
			{
				int s;
				s=ptr->val;
		
				addsum=generateanodeadd(s,pow);
				current=head3;
				addrand(addsum,current);
			
			    pow+=1;				//����+1���U�@�ӥh 
				ptr=ptr->prev;		//���U�@�Ӧ���� 
			}
		  
		while((ptr->power=ptr2->power)&&(ptr!=head)&&(ptr2!=head2)) //����V�ۦP�ɶ}�l���[�k�B�� 
		{
		
			int s;
			s=ptr->val+ptr2->val+carry;		//�쵲1+�쵲2��i�찵�[�k 
			carry=s/10;						//�ۥ[���G��10����� 
			tempc=s;						//�x�s�U�@�쪺�i�� 
			s%=10;							//���ۥ[���l�� 
		
			addsum=generateanodeadd(s,pow);
			current=head3;
			addrand(addsum,current);
			
		    pow+=1;
			ptr=ptr->prev;					//ptr���V�U�@�Ӧ��� 
			ptr2=ptr2->prev;				//ptr2���V�U�@�Ӧ���
		}
		while(ptr!=head)		//�קK����Ӥj�A�S���̰��줸�A�i��|�֫ܦh�줸 (�P�_�֤����?)
		{
			int s;
			s=ptr->val+carry;
			carry=s/10;
			tempc=s;
			s%=10;
		
			addsum=generateanodeadd(s,pow);
			current=head3;
			addrand(addsum,current);
			
			pow+=1;
			ptr=ptr->prev;
		}
		while(ptr2!=head2)		//�קK����Ӥj�A�S���̰��줸�A�i��|�֫ܦh�줸(�P�_�֤����?)
		{
			int s;
			s=ptr2->val+carry;
			carry=s/10;
			tempc=s;
			s%=10;
		
			addsum=generateanodeadd(s,pow);
			current=head3;
			addrand(addsum,current);
			
			pow+=1;
			ptr2=ptr2->prev;
		}
	carry=tempc/10;
	if(carry>0)				//�p�G���̫�(����̰���)���i��b�ӳo���i��(�P�_���S���i��)
	{
		addsum=generateanodeadd(carry,pow);
		current=head3;
		addrand(addsum,current);
	}
	addfinal=head3;			//�����ܼƪ����Ы��V�ۥ[�����G
	multfinal=head3;		//�����ܼƪ����Ы��V�ۥ[�����G
	
}
int freelist(ANODE * freeadd)			//����list�O���� 
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
int multcount(ANODE *head,ANODE *head2)				//�����k���a�� 
{
	free(multfinal);
	int c,num=0;
	struct ANODE * ptr,* ptr2,*temp;
	ptr=head->prev;									//��ptr���V�̫�@��(����̤p) 
	int tempc,i=0,pow=1,dig=1;
	temp=generateanode();
	
	while(ptr!=head)
	{
		int carry=0;
		struct ANODE *head3,*current,*multsum;
		head3=generateanode();
		ptr2=head2->prev;							//��ptr2���V�̫�@��(����̤p)
		while(ptr2!=head2)
		{
			int s;
			s=ptr->val*ptr2->val+carry;	 			//s�@�Ӥ@�ӼƬۭ���[�W�i�쪺���G 
			carry=s/10;
			tempc=s;
			s%=10;
		
			multsum=generateanodeadd(s,pow); 		//�t�~�Ф@���쵲 
			current=head3;
			addrand(multsum,current);
		
			pow+=1;
			ptr2=ptr2->prev;						//ptr2���V�U�@��(��V�[1) 
		}
		carry=tempc/10;								//�U�@�쪺�i�� 
		if(carry>0)
		{
			multsum=generateanodeadd(carry,pow);
			current=head3;
			addrand(multsum,current);
		}
		countadd(temp,head3);						
		temp=multfinal;								//��̫᭼�k�ۥ[���B��� 
    	pow=dig+1;									//dig���誺�i��(�t�~�ŧi) 
    	dig+=1;
		ptr=ptr->prev;	
	}
}
main(){
	struct ANODE *head,*current,*current2,*temp,*temp2,*head2;
	int i,count=1,c,x;
	scanf("%d",&c);
	srand(time(NULL));
	head=generateanode();		//NO1�ժ��}�Y 
	head2=generateanode();		//NO2�ժ��}�Y
	while(count<c){
		temp=generateanoderand(count);		//�жüƪ��a��  �s�bhead1 
		current=head;
		addrand(temp,current);	
		count+=1;							//���U�@�Ӧ��� 
	}
		temp=generateanodetitle(count);
		current2=head2;
		addrand(temp,current);
		
		printlist(head);				//�C�X��1�ռƦC
		
		count=1;						//���誺�� 
		scanf("%d",&x);
	while(count<x){	
		temp2=generateanoderand(count);
		current2 =head2;				//�жüƪ��a��  �s�bhead2
		addrand(temp2,current2);
		count+=1;
	}
		temp2=generateanodetitle(count);
		current=head2;
		addrand(temp2,current2);
	
	printlist(head2);					//�C�X��2�ռƦC 
	countadd(head,head2);				//���ۥ[���ƦC 
	printfadd();						//�L�X1+2���ƦC 
	multcount(head,head2);				//���ۭ����ƦC 
	printfmult();						//�L�X1*2���ƦC
}	
