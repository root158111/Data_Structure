#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h>
#define N 10000

int A[N];

int partition(int p,int r){
int x,i,j,k;

	x=A[r];
	i=p-1;
	for (j=p;j<=r-1;j++){
		if (A[j]<=x){
			i++;
			k=A[i];
			A[i]=A[j];
			A[j]=k;
		}
	}
	k=A[i+1];
	A[i+1]=A[r];
	A[r]=k;
	return i+1;
}
void quicksort(int p,int r){
int q;	
	if (p<r){
	   q=partition(p,r); 
	   quicksort(p,q-1);
	   quicksort(q+1,r);	
	}
}



main(){
int i;

    srand(time(NULL));
    for (i=0;i<N;i++)
        A[i]=rand()%7901+100; 

    //for (i=0;i<100;i++)
    //    printf("%d\n",A[i]);
        
    quicksort(0,N-1);  
       
	printf("--------------\n"); 
    for (i=0;i<N;i++)
        printf("%d\n",A[i]);
        
	system("pause");	
}
