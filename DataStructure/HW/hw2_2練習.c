#include <stdlib.h>
int gg[5][7]={
0,0,0,0,0,0,0,
0,0,0,1,1,1,0,
0,1,1,0,1,1,0,
0,1,1,1,0,1,0,
0,0,0,0,0,0,0};
struct NODE{
	int val;
	struct NODE *gg;
}*p=NULL,*w=NULL;


void pmatrix(){
int i,j;

   printf("----------------------\n");
   for (i=0;i<5;i++){
   	   for (j=0;j<7;j++)
   	      printf("%d",gg[i][j]);
   	   printf("\n");
   }
}

main(){
int j,k,w=1;  

  pmatrix();


}
