#include <stdio.h>
#include <stdlib.h>
struct list{
	int r,c;
	struct list* next;
};
struct list *stack=NULL,*temp;
int A[6][6]={
1,1,1,1,1,1,
1,0,0,0,1,1,
1,0,1,0,1,1,
1,1,1,0,0,1,
1,0,0,0,0,1,
1,1,1,1,1,1};


void pmatrix(){
int i,j;

   printf("-----------------\n");
   for (i=0;i<6;i++){
   	  for (j=0;j<6;j++)
          printf("%d",A[i][j]);
      printf("\n");
   }
}

int push(int r,int c){
	struct list* newnode;
	newnode=(struct list*)malloc(sizeof(struct list));
	if(!newnode){
		printf("Error\n");
		return 0;
	}
	newnode->r=r;
	newnode->c=c;
	newnode->next=stack;
	stack=newnode;
	return 1;
}

struct list* pop(){
	struct list* top;
	if(stack!=NULL){
		top=stack;
		stack=stack->next;
		return top;
	}
	else return NULL;
}

int main(){
  int i,j,r=2,c=3;
  
  pmatrix();
  
  while(r!=2||c!=1){
  	A[r][c]=6;
  	if(A[r][c+1]==0){
  		push(r,c);
  		c+=1;
	  }
	else if(A[r+1][c]==0){
		push(r,c);
		r+=1;
	}
	else if(A[r-1][c]==0){
		push(r,c);
		r-=1;
	}
	else if(A[r][c-1]==0){
		push(r,c);
		c-=1;
	}
	else{
		A[r][c]=2;
		temp=pop();
		r=temp->r;
		c=temp->c;
		free(temp);
	}
  }
  A[r][c]=6;
  pmatrix();
}
