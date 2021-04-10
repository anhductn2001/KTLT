double* maximum(double* a, int size){

    double *max;

    max = a;

    if (a==NULL) return NULL;
	for(int i=0;i<size;i++){
		if(a[i]<a[i+1]){
			*max=a[i+1];
		}
	
	}
    

    return max;

}
