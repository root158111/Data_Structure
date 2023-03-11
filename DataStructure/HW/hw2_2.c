#include <stdlib.h>
#include <stdio.h>
int data[5][7]={
0,0,0,0,0,0,0,
0,0,0,1,1,1,0,
0,1,1,0,1,1,0,
0,1,1,1,0,1,0,
0,0,0,0,0,0,0};
struct NODE{
	int val;
	struct NODE *next;
}*head=NULL,*tail=NULL;


void pmatrix(){
int i,j;

   printf("----------------------\n");
   for (i=0;i<5;i++){
   	   for (j=0;j<7;j++)
   	      printf("%d",data[i][j]);
   	   printf("\n");
   }
}

int deq(){
	struct NODE *ptr;
	int data=-1;
	if(head!=NULL){
		ptr=head;
		if(head==tail){
			head=tail=NULL;
		}
		else{
			head=head->next;
		}
		data=ptr->val;
		free(ptr);
	}
	return data;
}

void enq(int data){
	struct NODE *ptr;
	ptr=(struct NODE *)malloc(sizeof(struct NODE));
	ptr->val=data;
	ptr->next=NULL;
	if(tail==NULL){
		head=tail=ptr;
	}
	else{
		tail->next=ptr;
		tail=ptr;
	}
}

void find(int com,int r,int c){
	data[r][c]=com+1;
	enq(r);
	enq(c);
	while(head!=NULL){
		r=deq();
		c=deq();
		if(data[r-1][c]==1){
			data[r-1][c]=com+1;
			enq(r-1);
			enq(c);
		}
		if(data[r+1][c]==1){
			data[r+1][c]=com+1;
			enq(r+1);
			enq(c);
		}
		if(data[r][c-1]==1){
			data[r][c-1]=com+1;
			enq(r);
			enq(c-1);
		}
		if(data[r][c+1]==1){
			data[r][c+1]=com+1;
			enq(r);
			enq(c+1);
		}
	}
}

main(){
int com=0,r,c;

  pmatrix();
	for(c=0;c<5;c++)
		for(r=0;r<7;r++)
			if(data[r][c]==1){
				com++;
				find(com,r,c);
			}
	pmatrix();
}
