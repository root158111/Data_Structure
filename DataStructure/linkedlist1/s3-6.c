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
	
srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^
	
//�����ͤ@�ӫD�Ŧ�C�]�u���@��node�^
temp=(struct ANODE *)malloc(sizeof(struct ANODE));
temp->val=rand()%1001;
temp->next=NULL;

head=temp;

//���ͤ@�ӷs��node
temp=(struct ANODE *)malloc(sizeof(struct ANODE));
temp->val= rand()%1001;
temp->next=NULL;

//�N�s���ͪ�node�[�J��C���}�Y
temp->next=head;//(1)
head=temp;//(2)

//�L�X��C��2��node����
ptr=head->next;//�n�ŧiptr�����Vstruct ANODE������
printf("%d %d\n",head->val,ptr->val);



system("pause");

}
