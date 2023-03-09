#include <bits/stdc++.h>

using namespace std;

#define LL long long
#define PII pair<int , int>
#define PLI pair<LL  , int>
#define PLL pair<LL , LL>
#define bit(x) (1<<x)
#define bitl(x) (1LL<<x)
#define cnti(x) (__builtin_ctz(x))
#define cntl(x) (__builtin_ctzll(x))
#define clzi(x) (__builtin_clz(x))
#define clzll(x) (__builtin_clzll(x))

#define Error(x) cerr<<#x<<" = "<<x<<endl;

int tc , n , m;

int main(){
	cin>>tc;
	while(tc--){
		cin>>n>>m;
		int cnt = 64 - clzll(1LL*(n+1));
		LL val = bitl(cnt);
		cout<<n*m<<endl;
		for(int i = 2 ; i <= n+1 ; i++ ){
			for(int j = 0 ; j < m ; j++ ){
				cout<<i + j * val<<" \n"[j == m-1];
			}
		}
	}
	return 0;
}

