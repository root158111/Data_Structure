#include <stdio.h>

struct NODE{
	int val;
	struct NODE *left,*right;
};

struct NODE *root=NULL;

void inserttree(int n){
struct NODE *temp,*ptr,*pre;

   temp=malloc(sizeof(struct NODE));
   temp->val=n;
   temp->left=temp->right=NULL;
   if (root==NULL) root=temp;
   else{
   	   ptr=root;
   	   while (ptr!=NULL){
   	   	  pre=ptr;
   	   	  if (n<=ptr->val)
   	   	  	 ptr=ptr->left;
   	   	  else
   	   	     ptr=ptr->right;
   	   }
   	   if (n<=pre->val)
   	      pre->left=temp;
   	   else
   	      pre->right=temp;   	      
   }
}

void inorder(struct NODE *ptr){
	if (ptr!=NULL){
		inorder(ptr->left);
		printf("%d\n",ptr->val);
		inorder(ptr->right);
	}
}

main(){
int n;
	for (;;){
		scanf("%d",&n);
		if (n<=0) break;
		inserttree(n);
	}
	inorder(root);
}
