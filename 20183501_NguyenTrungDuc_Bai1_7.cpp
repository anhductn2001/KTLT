#include <stdio.h>

int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a = new int[n];
    for(int i = 0; i < n; i++){
        scanf("%d", (a + i)); 
    }
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
   	for(int i=0;i<n-1;i++){
  		for(int j=i+1;j<n;j++)
   		{
    		if(*(a+i)>*(a+j)) 
     		{
       		int temp=*(a+i);
       		*(a+i)=*(a+j);
       		*(a+j)=temp;
     		}
   		}
   	}
   	
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    

    return 0;
}
