#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //�]�t�w�qtime()

struct ANODE{
int val;
struct ANODE *next,*prev;
};
struct ANODE *head,*temp,*current;

//�C�����ͤ@��node����ơA�^�Ƿs����node���_�l��}
struct ANODE * generateanode(){
struct ANODE * ptr;

  ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
  ptr->val= rand()%1001;
  ptr->prev=NULL;
  ptr->next=NULL;//���G�C�i�X�֬� ptr->prev=ptr->next=NULL;
  
  return ptr;//������ƪ��^�ǭȡA���V�t�m���O����_�l��}
}

//���V�L 
void printlistforward(){
struct ANODE * ptr;

  printf("----------------------\n");
  ptr=head->next;
  while (ptr!=head){
      printf("%d\n",ptr->val);
      ptr=ptr->next;
  }
}

//�f�V�L
void printlistbackward(){
struct ANODE * ptr;

  printf("----------------------\n");
  ptr=head->prev;
  while (ptr!=head){
      printf("%d\n",ptr->val);
      ptr=ptr->prev;
  }
}


//���w��V�L 
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
	
  srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^
	
  //���ͨϥ�dummy node���Ŧ�C
  head=(struct ANODE *)malloc(sizeof(struct ANODE));
  head->prev=head;
  head->next=head;//�o��C�i�X�֬�head->prev=head->next=head;
	
  //�Y�[�J�snode����>100�A�h�~�򲣥ͤU�@�snode
  do{
    //���ͤ@�ӷs��node
    temp= generateanode();
    
    //��[�J�snode���A���m 
    current=head->next;
    while ((current!=head)&&(current->val<temp->val))
        current=current->next;

    //�bcurrent���e�[�J�s��node
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
