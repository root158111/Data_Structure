#include <stdlib.h>
#define N 15

struct NODE{
	int val;
	struct NODE *next;
};

struct NODE *head=NULL,*tail=NULL;


int dequeue(){
struct NODE *ptr;
int data=-1;

    if (head!=NULL){
    	ptr=head;
    	if (head==tail)
    	   head=tail=NULL;
    	else
    	   head=head->next;
        data=ptr->val;
        free(ptr);
    }
    return data;
}

void enqueue(int data){
struct NODE *ptr;

    ptr=malloc(sizeof(struct NODE));
    ptr->val=data;
    ptr->next=NULL;
    
    if (tail==NULL){
    	head=tail=ptr;
    }
    else{
    	tail->next=ptr;
    	tail=ptr;
    }
        
}

int data[15][15]={
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,
0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
0,0,1,1,1,1,0,0,0,1,0,0,0,0,0,
0,0,0,1,1,0,0,0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,
0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,
0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,
0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,
0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,
0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
};

void findthiscomponent(int componentcnt,int row,int col){
	data[row][col]=componentcnt+1;//marked from 2
	enqueue(row);
	enqueue(col);	
	while (head!=NULL){
		row=dequeue();
		col=dequeue();		
		if (data[row-1][col]==1){
		     data[row-1][col]=componentcnt+1;//marked from 2	
		     enqueue(row-1);
	             enqueue(col);	         
		}
		if (data[row+1][col]==1){
		     data[row+1][col]=componentcnt+1;//marked from 2	
		     enqueue(row+1);
	             enqueue(col);	         
		}
		if (data[row][col-1]==1){
		     data[row][col-1]=componentcnt+1;//marked from 2	
		     enqueue(row);
	             enqueue(col-1);	         
		}
		if (data[row][col+1]==1){
		     data[row][col+1]=componentcnt+1;//marked from 2	
		     enqueue(row);
	             enqueue(col+1);	         
		}
	}
}

main(){
int row,col,componentcnt=0;


    for (row=0;row<N;row++){
    	for (col=0;col<N;col++)
    	  printf("%d",data[row][col]);
    	printf("\n");
    }
    
    
    for (row=0;row<N;row++)
    	for (col=0;col<N;col++)
    	   if (data[row][col]==1){
    	   	   componentcnt++;
    	   	   findthiscomponent(componentcnt,row,col);
    	   }

    printf("coponents=%d\n",componentcnt);
    for (row=0;row<N;row++){
    	for (col=0;col<N;col++)
    	  printf("%d",data[row][col]);
    	printf("\n");
    }
    
}
