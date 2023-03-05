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

#define mx 10010

int tc , n;
int a[mx];

int main(){
	cin>>tc;
	while(tc--){
		cin>>n;
		for(int i= 0 ; i < n ; i++ ) {
			cin>>a[i];
			if(a[i] == 1) a[i]++;
		}
		for(int i = 1 ; i < n ; i++ ){
			if(a[i] % a[i-1] == 0) a[i]++;
		}
		for(int i = 0 ; i < n ; i++ ) cout<<a[i]<<" \n"[i == n-1];
	}
	return 0;
}

