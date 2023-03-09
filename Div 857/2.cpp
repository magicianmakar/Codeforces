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

int tc , n;

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>tc;
	while(tc--){
		cin>>n;
		int cur = 0 , val = 0 , cnt = 1 , num = 0;
		for(int i = 0 ; i < n ; i++ ){
			int day;cin>>day;
			if(day == 1){
				if(cur > cnt + val){
					
				}else{
					cur++;
				}
				val++;
				num++;
			}else{
				val = 0;
				cnt = num / 2 + 1;
				continue;
			}
		}
		cout<<cur<<endl;
	}
	return 0;
}

