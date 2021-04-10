#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# s? th�nh ph? v� ma tr?n chi ph�
int cmin = INT_MAX; //# chi ph� di l?i nh? nh?t gi?a hai th�nh ph? kh�c nhau
int best = INT_MAX; //# t?ng chi ph� nh? nh?t c?n t�m, ban d?u d?t b?ng gi� tr? v� c�ng l?n INT_MAX = 2^31-1
int curr; //# t?ng chi ph� t?i th?i di?m hi?n t?i
int mark[MAX]; //# d�nh d?u nh?ng th�nh ph? d� di
int x[MAX]; //# luu gi? c�c th�nh ph? d� di

//# �?c d? li?u v�o
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}

//# Thu?t to�n quay lui
void TRY(int k){
    if(curr + cmin*(n-k+1)>=best){
    	return;
	}
    for(int i = 2; i <= n; i++){
    	if(mark[i]==0){
    		mark[i]=1;
    		x[k]=i;
    		curr+=c[x[k-1]][x[k]];
    		if(k==n){
    			if(curr+c[x[n]][x[1]]<best){
    				best=curr+c[x[n]][x[1]];
				}
			}
    		TRY(k+1);
    		mark[i]=0;
    		curr-=c[x[k-1]][x[k]];  		
		}
	}
}

int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
