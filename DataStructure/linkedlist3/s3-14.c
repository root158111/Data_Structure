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

  ptr=head;
  while (ptr!=NULL){
    printf("%d\n",ptr->val);
    ptr=ptr->next;
  }
}

//�̧ǦC�L��C���C��node����
void freelist(){
struct ANODE * ptr;
 
  printf("--->����linked list\n"); 
  while (head!=NULL){
	ptr=head;
	head=head->next;
	free(ptr);
  }
}


main(){
struct ANODE *ptr;
int i;
	
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


  printlist();//�C�L��C��node����
  freelist();//�����C���Ҧ�node�ϥΪ��O���� 
  printlist();//�C�L��C��node����

system("pause");

}
