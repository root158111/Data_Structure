#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct ANODE
{
	int power;
	int val;
	struct ANODE *next,*prev; 
};
struct ANODE * addfinal,* multfinal; 	//最後存在這加法乘法 
struct ANODE * generateanode()		//domedone
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->prev=ptr->next=ptr;
	return ptr;
}
struct ANODE * generateanoderand(int pow)	//生成亂數用 
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=rand()%10;
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr;
}
struct ANODE * generateanodetitle(int pow) 	//開頭不能是0 另外做處理 
{
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=rand()%9+1;
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr;
}
struct ANODE * generateanodeadd(int sum,int pow)	//兩組亂數作加法!丟到這加法 
{ 
	struct ANODE *ptr;
	ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
	ptr->val=sum;
	ptr->power=pow;
	ptr->prev=ptr->next=NULL;
	return ptr;
}

int addrand(ANODE * temp,ANODE *current)  	//把數值插入鏈結裡 
{
	current=current->next;
	temp->prev=current->prev;
	temp->next=current;
	current->prev->next=temp;
	current->prev=temp;
}
int printlist(ANODE * head)				//印亂數的值 
{
	struct ANODE *ptr;
	printf("---------亂數產生---------\n");
	ptr=head->next;
	while(ptr!=head)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
}
int printfadd()							//印加法後的結果 
{
	struct ANODE * ptr;
	printf("---------加法---------\n");
	ptr=addfinal->next;
	while(ptr!=addfinal)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
	
}
int printfmult()						//印乘法後的結果 
{
	struct ANODE * ptr;
	printf("---------乘法---------\n");
	ptr=multfinal->next;
	while(ptr!=multfinal)
	{
		printf("%d",ptr->val);
		ptr=ptr->next;
	}
	printf("\n");
	
}
int countadd(ANODE * head,ANODE * head2)		//作加法的地方 
{
	struct ANODE * ptr,* ptr2,*head3,*current;
	struct ANODE * addsum;
	ptr=head->prev;				//ptr第1組指到head的尾巴 
	ptr2=head2->prev;			//ptr2第2組指到head的尾巴
	int tempc,carry=0,pow=1;
	head3=generateanode();			//最後存放加法的地方(運算後)開頭 
			while((ptr->power<ptr2->power)&&(ptr!=head)) 	//要使兩個資料以次方相同的方式做運算 
			{
				int s;
				s=ptr->val;
		
				addsum=generateanodeadd(s,pow);
				current=head3;
				addrand(addsum,current);
			
			    pow+=1;				//次方+1往下一個去 
				ptr=ptr->prev;		//往下一個次方指 
			}
		  
		while((ptr->power=ptr2->power)&&(ptr!=head)&&(ptr2!=head2)) //當次方向相同時開始做加法運算 
		{
		
			int s;
			s=ptr->val+ptr2->val+carry;		//鏈結1+鏈結2跟進位做加法 
			carry=s/10;						//相加結果除10取整數 
			tempc=s;						//儲存下一位的進位 
			s%=10;							//取相加的餘數 
		
			addsum=generateanodeadd(s,pow);
			current=head3;
			addrand(addsum,current);
			
		    pow+=1;
			ptr=ptr->prev;					//ptr指向下一個次方 
			ptr2=ptr2->prev;				//ptr2指向下一個次方
		}
		while(ptr!=head)		//避免次方太大，沒算到最高位元，可能會少很多位元 (判斷誰比較長?)
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
		while(ptr2!=head2)		//避免次方太大，沒算到最高位元，可能會少很多位元(判斷誰比較長?)
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
	if(carry>0)				//如果有最後(次方最高的)有進位在來這做進位(判斷有沒有進位)
	{
		addsum=generateanodeadd(carry,pow);
		current=head3;
		addrand(addsum,current);
	}
	addfinal=head3;			//全域變數的指標指向相加的結果
	multfinal=head3;		//全域變數的指標指向相加的結果
	
}
int freelist(ANODE * freeadd)			//釋放list記憶體 
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
int multcount(ANODE *head,ANODE *head2)				//做乘法的地方 
{
	free(multfinal);
	int c,num=0;
	struct ANODE * ptr,* ptr2,*temp;
	ptr=head->prev;									//把ptr指向最後一位(次方最小) 
	int tempc,i=0,pow=1,dig=1;
	temp=generateanode();
	
	while(ptr!=head)
	{
		int carry=0;
		struct ANODE *head3,*current,*multsum;
		head3=generateanode();
		ptr2=head2->prev;							//把ptr2指向最後一位(次方最小)
		while(ptr2!=head2)
		{
			int s;
			s=ptr->val*ptr2->val+carry;	 			//s一個一個數相乘後加上進位的結果 
			carry=s/10;
			tempc=s;
			s%=10;
		
			multsum=generateanodeadd(s,pow); 		//另外創一個鏈結 
			current=head3;
			addrand(multsum,current);
		
			pow+=1;
			ptr2=ptr2->prev;						//ptr2指向下一位(方向加1) 
		}
		carry=tempc/10;								//下一位的進位 
		if(carry>0)
		{
			multsum=generateanodeadd(carry,pow);
			current=head3;
			addrand(multsum,current);
		}
		countadd(temp,head3);						
		temp=multfinal;								//放最後乘法相加的運算值 
    	pow=dig+1;									//dig次方的進位(另外宣告) 
    	dig+=1;
		ptr=ptr->prev;	
	}
}
main(){
	struct ANODE *head,*current,*current2,*temp,*temp2,*head2;
	int i,count=1,c,x;
	scanf("%d",&c);
	srand(time(NULL));
	head=generateanode();		//NO1組的開頭 
	head2=generateanode();		//NO2組的開頭
	while(count<c){
		temp=generateanoderand(count);		//創亂數的地方  存在head1 
		current=head;
		addrand(temp,current);	
		count+=1;							//往下一個次方 
	}
		temp=generateanodetitle(count);
		current2=head2;
		addrand(temp,current);
		
		printlist(head);				//列出第1組數列
		
		count=1;						//次方的數 
		scanf("%d",&x);
	while(count<x){	
		temp2=generateanoderand(count);
		current2 =head2;				//創亂數的地方  存在head2
		addrand(temp2,current2);
		count+=1;
	}
		temp2=generateanodetitle(count);
		current=head2;
		addrand(temp2,current2);
	
	printlist(head2);					//列出第2組數列 
	countadd(head,head2);				//做相加的數列 
	printfadd();						//印出1+2的數列 
	multcount(head,head2);				//做相乘的數列 
	printfmult();						//印出1*2的數列
}	
