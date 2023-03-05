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

#define mx 100010

int tc , n;
int a[mx] , ans[mx][2];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>tc;
	while(tc--){
		cin>>n;
		for(int i = 0 ; i < n ; i++ ) cin>>a[i];
		ans[0][1] = 1;
		ans[0][0] = 1;
		for(int i = 1 ; i < n ; i++ ) {
			if(a[i] >= i+1) {
				ans[i][0] = max(ans[i-1][0] , ans[i-1][1]);
				ans[i][1] = ans[i-1][1] + 1;
			}else{
				ans[i][0] = ans[i-1][0];
				ans[i][1] = ans[i-1][1];
			}
		}
		for(int i = 0 ; i < n ; i++ ) cout<<max(ans[i][0] , ans[i][1])<<" \n"[i == n-1];
	}
	return 0;
}

