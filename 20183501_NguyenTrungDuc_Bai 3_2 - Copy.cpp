#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; 
int mark[100][100]; 

const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2}; 
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuy?n tìm du?c
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//Kiem tra quan ma co ra ngoai ban co khong
bool isIn(int x,int y){
	return x > 0 && y > 0 && x <= n && y <= n;
}
//# Thu?t toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
      	if(k==n*n+1){
      		print_sol();
		}
		if(isIn(xx,yy)){
      		if(mark[xx][yy]==0){
      			mark[xx][yy]=k;
      			X[k]=xx;
      			Y[k]=yy;
				TRY(k+1);
				X[k]=0;
				Y[k]=0;
				mark[xx][yy]=0;	
			}
		}	
    }
}

int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
