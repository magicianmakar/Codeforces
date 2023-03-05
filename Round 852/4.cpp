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

#define mx 1000010

int n , a[mx] , p[mx];

void Prime_Sieve(){
	for(int i = 2 ; i < mx ; i++ ) p[i] = 1;
	for(int i = 2 , u = sqrt(mx); i <= u ; i++ ) if(p[i] == 1){
		for(int j = i*i ; j < mx ; j += i) p[j] = 0;
	}
}

const int mod = 998244353;

int main(){
	freopen("sam.txt" , "r" , stdin);
	Prime_Sieve();
	cin>>n;
	for(int i = 0 ; i < 2*n ; i++ ) cin>>a[i];
	sort(a , a + 2*n);
	int cnt = 0 , ans = 1;
	int k = unique(a , a + 2*n) - a;
	for(int i = 0 ; i < k ; i++ ) if(p[a[i]]) cnt++;
	if(cnt < n) return cout<<0<<endl , 0;
	for(int i = 0 ; i < n ; i++ ){
		ans = (int) (1LL * ans * (cnt - i) % mod);
	}
	cout<<ans<<endl;
	return 0;
}

