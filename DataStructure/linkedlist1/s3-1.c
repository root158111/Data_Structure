#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h>


main(){
	
srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）

printf("%d\n",rand()%1001);

system("pause");

}
