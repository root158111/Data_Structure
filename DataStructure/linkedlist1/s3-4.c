#include <stdio.h>
#include <stdlib.h>// for system("pause");

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//串列由head所指，預設為空串列


main(){

  //建立新node，並由temp所指，設定node的變數內容	
  temp=(struct ANODE *)malloc(sizeof(struct ANODE));
  temp->val=349;
  temp->next=NULL;

  //指標head指向指標temp，完成在空串列加入第1個node
  head=temp;

  //印出串列第1個node的val值
  printf("%d %d\n",head->val,temp->val);

  system("pause");

}
