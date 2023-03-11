
int main(){
int i,j,n,base=6,extend=4;
char **p;

    scanf("%d",&n);
    p=malloc(n*sizeof(char *));
    for (i=0;i<n;i++){
    	*(p+i)=malloc(base+(i*extend)+1);
    	
    	for (j=0;j<base+(i*extend);j++)
    	    *(*(p+i)+j)='A';
    	*(*(p+i)+base+(i*extend))='\0';
    }

    for (i=0;i<n;i++)
    	printf("%d %d %s\n",p+i,*(p+i),*(p+i));	
}


