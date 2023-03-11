#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //包含定義time()

struct ANODE{
int val;
struct ANODE *next,*prev;
};
struct ANODE *head,*temp,*current;

//每次產生一個node的函數，回傳新產生node的起始位址
struct ANODE * generateanode(){
struct ANODE * ptr;

  ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
  ptr->val= rand()%1001;
  ptr->prev=NULL;
  ptr->next=NULL;//此二列可合併為 ptr->prev=ptr->next=NULL;
  
  return ptr;//此為函數的回傳值，指向配置的記憶體起始位址
}

//順向印 
void printlistforward(){
struct ANODE * ptr;

  printf("----------------------\n");
  ptr=head->next;
  while (ptr!=head){
      printf("%d\n",ptr->val);
      ptr=ptr->next;
  }
}

//逆向印
void printlistbackward(){
struct ANODE * ptr;

  printf("----------------------\n");
  ptr=head->prev;
  while (ptr!=head){
      printf("%d\n",ptr->val);
      ptr=ptr->prev;
  }
}


//指定方向印 
void printlist(int dir){
struct ANODE * ptr;

  printf("----------------------\n");
  if (dir==1) ptr=head->next;
  else ptr=head->prev;
  while (ptr!=head){
      printf("%d\n",ptr->val);
      if (dir==1) ptr=ptr->next;
      else ptr=ptr->prev;
  }
}




main(){
struct ANODE *ptr;
int i,n;
	
  srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）
	
  //產生使用dummy node的空串列
  head=(struct ANODE *)malloc(sizeof(struct ANODE));
  head->prev=head;
  head->next=head;//這兩列可合併為head->prev=head->next=head;
	
  //若加入新node之值>100，則繼續產生下一新node
  do{
    //產生一個新的node
    temp= generateanode();
    
    //找加入新node的適當位置 
    current=head->next;
    while ((current!=head)&&(current->val<temp->val))
        current=current->next;

    //在current之前加入新的node
    temp->prev=current->prev;//(1)
    temp->next=current;//(2)   
    current->prev->next=temp;//(3)
    current->prev=temp;//(4)
    

  } while (temp->val>100);
 
  printlistforward();
  printlist(1);
  printlistbackward();
  printlist(2);
  
  system("pause");

}
