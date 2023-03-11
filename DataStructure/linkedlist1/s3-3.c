#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h>


main(){
int i;
	
srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）

do{
   i=rand()%1001;
   printf("%d\n",i);
} while (i>100);

system("pause");

}
