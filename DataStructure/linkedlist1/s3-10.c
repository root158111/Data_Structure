#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //�]�t�w�qtime()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//��C��head�ҫ��A�w�]���Ŧ�C

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


main(){
struct ANODE *ptr;
int i;
	
  srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^
	
  //�[�J��1~10��node
  for (i=0;i<10;i++){
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
