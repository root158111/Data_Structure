#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h>


main(){
int i;
	
srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^

do{
   i=rand()%1001;
   printf("%d\n",i);
} while (i>100);

system("pause");

}
