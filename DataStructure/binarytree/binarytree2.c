#include <stdio.h>

struct NODE{
	int val;
	struct NODE *left,*right;
};

struct NODE *root=NULL;

struct NODE * inserttree2(struct NODE *current,int n){
struct NODE *temp;
	if (current==NULL){
		temp=malloc(sizeof(struct NODE));
		temp->val=n;
		temp->left=temp->right=NULL;
		return temp;
	}
	if (n<=current->val)
		current->left=inserttree2(current->left,n);
	else
	    current->right=inserttree2(current->right,n);
	return current;
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
		root=inserttree2(root,n);
	}
	inorder(root);
}
