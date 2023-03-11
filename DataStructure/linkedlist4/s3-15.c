#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //�]�t�w�qtime()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp,*current,*precurrent;//��C��head�ҫ��A�w�]���Ŧ�C

//�C�����ͤ@��node����ơA�^�Ƿs����node���_�l��}
struct ANODE * generateanode(){
struct ANODE * ptr;

  ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
  ptr->val= rand()%1001;
  ptr->next=NULL;
  
  return ptr;//������ƪ��^�ǭȡA���V�t�m���O����_�l��}
}

//�̧ǦC�L��C���C��node����
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

  if ((current!=NULL)&&(current->val==n)) return 1;//node�����   
  else return 0;//node�S���
}

main(){
struct ANODE *ptr;
int i,n;
	
  srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^
	
  //�Y�[�J�snode����>100�A�h�~�򲣥ͤU�@�snode
  do{
  //���ͤ@�ӷs��node
    temp= generateanode();

    if (head==NULL){//��Ӭ��Ŧ�C
      head=temp;
    }
    else{//�N�s���ͪ�node�[�J��C�A����m�]�ȥѤp�ܤj�ƦC�^
      current=head;
      precurrent=NULL;
      while ((current!=NULL)&&(current->val<temp->val)){
        precurrent=current;
        current=current->next;
      }
      if (precurrent==NULL)
        head=temp;//(1),�A�ι�3-3������
      else
        precurrent->next=temp; //(1),�A�ι�3-1�ι�3-2������
      temp->next=current;//(2)
    }

  } while (temp->val>100);
 
  printlist();
  
  //�C��Ū�J�@n�ȡA�M��linked list����node���ӭȪ̡A�R����node
  while (1){
    scanf("%d",&n); 
    
    if (n<0) break;//���X�j��A�����{��
    else{
        if (findnode(n)){//���i�R����node
            if (precurrent==NULL)//case a�G���R����node���Ĥ@
                head=current->next;//(1)
            else////case b�G���R����node���O�Ĥ@��node
                precurrent->next=current->next;//(1)
            free(current);//(2)
        }
    }
    printlist();
    
  }//end of while

  

  system("pause");

}
