#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //�]�t�w�qtime()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//��C��head�ҫ��A�w�]���Ŧ�C


main(){
struct ANODE *ptr;
int i;
	
srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^
	
//�����ͤ@�ӫD�Ŧ�C�]�u���@��node�^
temp=(struct ANODE *)malloc(sizeof(struct ANODE));
temp->val=rand()%1001;
temp->next=NULL;

head=temp;

//�[�J��2~10��node
for (i=0;i<9;i++){

  //���ͤ@�ӷs��node
  temp=(struct ANODE *)malloc(sizeof(struct ANODE));
  temp->val= rand()%1001;
  temp->next=NULL;

  //�N�s���ͪ�node�[�J��C���}�Y
  temp->next=head;//(1)
  head=temp;//(2)

}


//�C�L��10,9,..,1��node����
ptr=head;
while (ptr!=NULL){
  printf("%d\n",ptr->val);
  ptr=ptr->next;
}


system("pause");

}
