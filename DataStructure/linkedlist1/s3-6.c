#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //包含定義time()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//串列由head所指，預設為空串列


main(){
struct ANODE *ptr;
	
srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）
	
//先產生一個非空串列（只有一個node）
temp=(struct ANODE *)malloc(sizeof(struct ANODE));
temp->val=rand()%1001;
temp->next=NULL;

head=temp;

//產生一個新的node
temp=(struct ANODE *)malloc(sizeof(struct ANODE));
temp->val= rand()%1001;
temp->next=NULL;

//將新產生的node加入串列的開頭
temp->next=head;//(1)
head=temp;//(2)

//印出串列中2個node的值
ptr=head->next;//要宣告ptr為指向struct ANODE的指標
printf("%d %d\n",head->val,ptr->val);



system("pause");

}
