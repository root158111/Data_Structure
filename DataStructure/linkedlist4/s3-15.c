#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //包含定義time()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp,*current,*precurrent;//串列由head所指，預設為空串列

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

  printf("------------\n");
  ptr=head;
  while (ptr!=NULL){
    printf("%d\n",ptr->val);
    ptr=ptr->next;
  }
  printf("------------\n");
}

int findnode(int n){
  current=head;
  precurrent=NULL;
  while ((current!=NULL)&&(current->val<n)){
    precurrent=current;
    current=current->next;
  }

  if ((current!=NULL)&&(current->val==n)) return 1;//node有找到   
  else return 0;//node沒找到
}

main(){
struct ANODE *ptr;
int i,n;
	
  srand(time(NULL));//設亂數種子（使用現在的系統時間，首次產生亂數前用）
	
  //若加入新node之值>100，則繼續產生下一新node
  do{
  //產生一個新的node
    temp= generateanode();

    if (head==NULL){//原來為空串列
      head=temp;
    }
    else{//將新產生的node加入串列適當的位置（值由小至大排列）
      current=head;
      precurrent=NULL;
      while ((current!=NULL)&&(current->val<temp->val)){
        precurrent=current;
        current=current->next;
      }
      if (precurrent==NULL)
        head=temp;//(1),適用圖3-3的情形
      else
        precurrent->next=temp; //(1),適用圖3-1及圖3-2的情形
      temp->next=current;//(2)
    }

  } while (temp->val>100);
 
  printlist();
  
  //每次讀入一n值，尋找linked list中的node有該值者，刪除該node
  while (1){
    scanf("%d",&n); 
    
    if (n<0) break;//跳出迴圈，結束程式
    else{
        if (findnode(n)){//找到可刪除之node
            if (precurrent==NULL)//case a：欲刪除之node為第一
                head=current->next;//(1)
            else////case b：欲刪除之node不是第一個node
                precurrent->next=current->next;//(1)
            free(current);//(2)
        }
    }
    printlist();
    
  }//end of while

  

  system("pause");

}
