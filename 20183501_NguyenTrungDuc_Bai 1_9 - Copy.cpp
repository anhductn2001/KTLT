#include<stdio.h>
int n;
int *a;
int main(){
	scanf("%d", &n);
	a = new int[n];
	for(int i = 0; i < n; i++){
        scanf("%d", a+i); 
    }
    for(int i=0;i<n;i++){
    	for(int j=1;j<=n;j++){
    		for(int u = i;u<j;u++){
    			printf("%d ", a[u]);
    			if(u==j-1){
    				printf("\n");
    			}
			}
    		
    	}
    	
	}
	return 0;
}
