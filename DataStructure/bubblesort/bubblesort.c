#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h>

#define N 100000

int A[N];

void bubblesort(){
int i,j,k;

	for (i=0;i<(N-1);i++){
		for (j=N-1;j>=(i+1);j--)
		  if (A[j]<A[j-1]){
				k=A[j-1];
				A[j-1]=A[j];
				A[j]=k;
		  }
	}
}

main(){
int i;
clock_t start, end;
float diff_time;

    srand(time(NULL));
    for (i=0;i<N;i++)
        A[i]=rand()%7901+100; 

    //for (i=0;i<N;i++)
    //    printf("%d\n",A[i]);
    
	start = clock();//�}�l�ɶ�     
    bubblesort();  
    end = clock();//�����ɶ� 
    diff_time = (float)(end-start)/CLOCKS_PER_SEC;//��� 
    printf("\n����ɶ� = %.3f��\n",(float)diff_time); 
       
	//printf("--------------\n"); 
    //for (i=0;i<N;i++)
    //    printf("%d\n",A[i]);
        
	system("pause");	
}
