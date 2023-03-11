#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h>


main(){
int i,n;
	
srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）

scanf("%d",&n);
for (i=0;i<n;i++)
   printf("%d\n",rand()%91+10);

system("pause");

}
