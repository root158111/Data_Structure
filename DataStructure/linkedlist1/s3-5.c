#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //包含定義time()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//串列由head所指，預設為空串列


main(){
	
  srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）

  //建立新node，並由temp所指，設定node的變數內容	
  temp=(struct ANODE *)malloc(sizeof(struct ANODE));
  temp->val=rand()%1001;
  temp->next=NULL;

  //指標head指向指標temp，完成在空串列加入第1個node
  head=temp;
  
  //印出串列第1個node的val值
  printf("%d %d\n",head->val,temp->val);

system("pause");

}
