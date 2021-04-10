#include<bits/stdc++.h>
using namespace std;
void reversearray(int arr[], int size){

    int tmp;
	for (int i=0;i<(size/2);i++){
		tmp=arr[i];
		arr[i]=arr[size-i-1];
		arr[size-i-1]=tmp;
	}
}



void ptr_reversearray(int *arr, int size){
	int tmp;
  	for (int i=0;i<(size/2);i++){
		tmp=*(arr+i);
		*(arr+i)=*(arr+size-i-1);
		*(arr+size-i-1)=tmp;
	}
}
int main(){
	int arr[] = {9, 3, 5, 6, 2, 5};
reversearray(arr, 6);
for(int i = 0; i < 6; i++) cout << arr[i] << " ";
int arr2[] = {4, -1, 5, 9};
ptr_reversearray(arr2, 4);
for(int i = 0; i < 4; i++) cout << arr2[i] << " ";
return 0;
}
