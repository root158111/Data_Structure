#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //包含定義time()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//串列由head所指，預設為空串列

//generateanode函數每次產生一個新node，並回傳新node的起始位址
struct ANODE * generateanode(){
struct ANODE * ptr;

  ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
  ptr->val= rand()%1001;
  ptr->next=NULL;
  
  return ptr;//此為函數的回傳值，指向配置的記憶體起始位址
}

//printlist函數依序列印串列中每個node的值
void printlist(){
struct ANODE * ptr;

  ptr=head;
  while (ptr!=NULL){
    printf("%d\n",ptr->val);
    ptr=ptr->next;
  }
}


main(){
struct ANODE *ptr;
int i;
	
  srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）
	
  //呼叫函數generateanode()產生一個node
  temp=generateanode();
  
  //加入第1個node
  head=temp;


  //加入第2~10個node
  for (i=0;i<9;i++){
    //產生一個新的node
    temp= generateanode();

    //將新產生的node加入串列的開頭
    temp->next=head;//(1)
    head=temp;//(2)

  }//end of for 

  //列印第10,9,..,1個node的值
  printlist();

  system("pause");

}
