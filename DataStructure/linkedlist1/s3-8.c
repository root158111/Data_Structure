#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //�]�t�w�qtime()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//��C��head�ҫ��A�w�]���Ŧ�C

//generateanode��ƨC�����ͤ@�ӷsnode�A�æ^�Ƿsnode���_�l��}
struct ANODE * generateanode(){
struct ANODE * ptr;

  ptr=(struct ANODE *)malloc(sizeof(struct ANODE));
  ptr->val= rand()%1001;
  ptr->next=NULL;
  
  return ptr;//������ƪ��^�ǭȡA���V�t�m���O����_�l��}
}

//printlist��ƨ̧ǦC�L��C���C��node����
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
	
  srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^
	
  //�I�s���generateanode()���ͤ@��node
  temp=generateanode();
  
  //�[�J��1��node
  head=temp;


  //�[�J��2~10��node
  for (i=0;i<9;i++){
    //���ͤ@�ӷs��node
    temp= generateanode();

    //�N�s���ͪ�node�[�J��C���}�Y
    temp->next=head;//(1)
    head=temp;//(2)

  }//end of for 

  //�C�L��10,9,..,1��node����
  printlist();

  system("pause");

}
