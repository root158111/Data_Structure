#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h>


main(){
int i,n;
	
srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^

scanf("%d",&n);
for (i=0;i<n;i++)
   printf("%d\n",rand()%91+10);

system("pause");

}
