#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //�]�t�w�qtime()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*tail=NULL,*temp;//��C��head�ҫ��A�w�]���Ŧ�C

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
  if (head!=NULL){//���O�Ŧ�C 
    ptr=head;
    do{
      printf("%d\n",ptr->val);
      ptr=ptr->next;
    }while (ptr!=head);   
  }//end of if
  printf("------------\n");

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
      //����head���V����temp�A�����b�Ŧ�C�[�J��1��node
      head=temp;
      tail=temp;
      head->next=head;//�ܦ�������C
    }
    else{//�N�s���ͪ�node�[�J��C�A�}�Y 
      temp->next=head;//(1)
      head=temp;//(2)
      tail->next=temp;//(3)
    }
  } while (temp->val>100);
 
  printlist();
  
  system("pause");

}
