#include <stdio.h>

int f(int n){
struct ANODE{
	int size,preone,pretwo;
	struct ANODE * prenode;
};
struct ANODE *head,*temp;
int retval=0;

   if (n==0) return -3;
   else if (n==-1) return -2;
   
   head=malloc(sizeof(struct ANODE));
   head->size=n;
   head->preone=head->pretwo=0;
   head->prenode=NULL;
   
   while (head!=NULL){
   	  if (retval<0){
   	  	   if (head->preone==0){
   	  	   	   head->preone=retval;
   	  	   	   retval=0;
   	  	   }
   	  	   else{
   	  	   	   head->pretwo=retval;
   	  	   	   retval=0;
   	  	   }
   	  }
   	  else if (head->preone==0){
   	  	   if (head->size==-2) head->preone=-2;
   	  	   else{
   	  	   	   temp=malloc(sizeof(struct ANODE));
   	  	   	   temp->size=head->size+1;
   	  	   	   temp->preone=temp->pretwo=0;
   	  	   	   temp->prenode=head;
   	  	   	   head=temp;
   	  	   }
   	  }
   	  else if (head->pretwo==0){
   	  	   if (head->size==-3) head->pretwo=-2;
   	  	   else if (head->size==-2) head->pretwo=-3;
   	  	   else{
   	  	   	   temp=malloc(sizeof(struct ANODE));
   	  	   	   temp->size=head->size+2;
   	  	   	   temp->preone=temp->pretwo=0;
               temp->prenode=head;
   	  	   	   head=temp;
   	  	   }
   	  }
   	  else{
   	  	   retval=head->preone+head->pretwo;
   	  	   head=head->prenode;
   	  	   printf("%d\n",retval);
   	  }
   }

   return retval;

}
int main(){
   printf("--->%d\n",f(-6));   
}


