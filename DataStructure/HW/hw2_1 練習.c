#include <stdio.h>
struct list{
	int row,col;
	struct list* zz;
};
struct list *h=NULL,*tmp;
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

int main(){
  int i,j,r=2,c=3;
  
  pmatrix();
  
  
}
