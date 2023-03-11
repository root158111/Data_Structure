#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //包含定義time()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//串列由head所指，預設為空串列

//每次產生一個node的函數，回傳新產生node的起始位址
struct ANODE * generateanode(){
struct ANODE * ptr;

  ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
  ptr->val= rand()%1001;
  ptr->next=NULL;
  
  return ptr;//此為函數的回傳值，指向配置的記憶體起始位址
}

//依序列印串列中每個node的值
void printlist(){
struct ANODE * ptr;

  ptr=head;
  while (ptr!=NULL){
    printf("%d\n",ptr->val);
    ptr=ptr->next;
  }
}

//依序列印串列中每個node的值
void freelist(){
struct ANODE * ptr;
 
  printf("--->釋放linked list\n"); 
  while (head!=NULL){
	ptr=head;
	head=head->next;
	free(ptr);
  }
}


main(){
struct ANODE *ptr;
int i;
	
  srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）
	
  //若加入新node之值>100，則繼續產生下一新node
  do{
    //產生一個新的node
    temp= generateanode();

    //將新產生的node加入串列的開頭
    temp->next=head;//(1)
    head=temp;//(2)
  } while (temp->val>100);

  printlist();//列印串列中node的值
  freelist();//釋放串列中所有node使用的記憶體 
  printlist();//列印串列中node的值

  system("pause");

}
