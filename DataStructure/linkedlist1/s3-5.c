#include <stdio.h>
#include <stdlib.h>// for system("pause");
#include <time.h> //�]�t�w�qtime()

struct ANODE{
int val;
struct ANODE *next;
};
struct ANODE *head=NULL,*temp;//��C��head�ҫ��A�w�]���Ŧ�C


main(){
	
  srand(time(NULL));//�]�üƺؤl�]�ϥβ{�b���t�ήɶ��A�������Ͷüƫe�Ρ^

  //�إ߷snode�A�å�temp�ҫ��A�]�wnode���ܼƤ��e	
  temp=(struct ANODE *)malloc(sizeof(struct ANODE));
  temp->val=rand()%1001;
  temp->next=NULL;

  //����head���V����temp�A�����b�Ŧ�C�[�J��1��node
  head=temp;
  
  //�L�X��C��1��node��val��
  printf("%d %d\n",head->val,temp->val);

system("pause");

}
