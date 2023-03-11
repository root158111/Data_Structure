#include <stdio.h>
#include <stdlib.h>
struct NODE
{
	int r,c;
	struct NODE* next;
};
struct NODE *stack=NULL;

int puzzle[10][12] = 
{1,1,1,1,1,0,0,0,1,1,1,1,
1,0,0,0,1,1,1,1,1,1,1,1,
1,0,1,0,1,1,0,0,0,0,1,1,
1,0,1,0,1,1,0,1,1,0,1,1,
1,1,1,0,0,0,0,1,1,0,1,1,
1,1,1,0,1,1,0,1,1,0,1,1,
1,1,1,0,1,1,0,1,1,0,1,1,
1,1,1,0,1,1,0,0,1,0,1,1,
1,1,0,0,0,0,0,0,1,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1};	
				
int push(int r,int c){
	struct NODE * newnode;
	newnode = (struct NODE *)malloc(sizeof(struct NODE));
	if(!newnode)
	{
		printf("Error!記憶體配置失敗!\n");
		return 0;//push失敗 
	}
	newnode->r=r;
	newnode->c=c;
	newnode->next=stack;
	stack=newnode;
    return 1;//push ok
}

struct NODE * pop(){
	struct NODE * top;
	if (stack!=NULL)
	{
		top=stack;
		stack=stack->next;
		return top;
	}
	else return NULL;
	
}

main(){	
struct NODE *temp;
	int i,j;
	int r=1,c=1;
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",puzzle[i][j]);
		printf("\n");
	}
	while(r!=8||c!=10)
	{
		puzzle[r][c]=6;
		if(puzzle[r-1][c]==0)
		{			
			push(r,c);
			r -= 1;
		}
		else if(puzzle[r+1][c]==0)
		{			
			push(r,c);
			r+=1;
		}
		else if(puzzle[r][c-1]==0)
		{			
			push(r,c);
			c-=1;
		}
		else if(puzzle[r][c+1]==0)
		{			
			push(r,c);
			c+=1;
		}
		else
		{
			puzzle[r][c]=2;
			temp=pop();
			r=temp->r;
			c=temp->c;
			free(temp);
		}
	}
	puzzle[r][c]=6;	
	printf("---------------------------\n");
	for(i=0;i<10;i++)
	{
		for(j=0;j<12;j++)
			printf("%2d",puzzle[i][j]);
		printf("\n");
	}
	system("pause");
	
}
