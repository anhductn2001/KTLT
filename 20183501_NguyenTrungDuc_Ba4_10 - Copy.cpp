#include <bits/stdc++.h>
using namespace std;
map<string, int> f[1005];
map<string, int> df;
vector<string> temp[1005];
int maxf[1005];
int n, q,start,len,res;
string str;
double maxs, score;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); 
    cin >> n;
    for (int i = 0; i < n; i++) {
    	map<string, int> temp_df;
        cin >> str;
        start = 0;
        int len = str.length();
        for (int j = 0; j <= len; j++) {
            if (str[j] == ',' || j == len) {
                string u = str.substr(start, j - start);
                temp[i].push_back(u);
                f[i][u]++;
                start = j+1;
                if (++temp_df[u] == 1) {
					df[u]++;
				}
            }
        }
        for (auto k : f[i]) {
           maxf[i] = max(maxf[i], k.second);
        }
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> str;
        vector<string> t;
        start = 0;
        len = str.length();

        for (int j = 0; j <= len; j++) {
            if (str[j] == ',' || j == len) {
                string u = str.substr(start, j - start);
                t.push_back(u);
                start = j+1;
            }
        }
        res = 0;
        maxs = -1e9;
        for (int k = 0; k < n; k++) {
            score = 0;
            int maxF = maxf[k]; 
            for (string s : t) {     
                int F=f[k][s];
                if (F!= 0)
                    score+=(0.5+0.5*F/maxF)*log2(1.0*n/df[s]);
            }
            if (maxs < score) {
                maxs = score;
                res = k;
            }
        }
        cout << res + 1 << endl;
    }
}
