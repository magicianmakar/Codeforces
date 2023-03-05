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
map< string , int > H;
vector< string > V;
string s[50];

vector< string > S[50];

int cmp(int i , int j){
	if(s[i].length() < s[j].length()) return i < j;
	return s[i] < s[j];
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>tc;
	while(tc--){
		H.clear();V.clear();
		cin>>n;
		int ok = 0;
		for(int i= 0 ; i < 50 ; i++ ) S[i].clear();
		for(int i = 0 ; i < 2*n-2 ; i++ ) {
			cin>>s[i];
			if(s[i].length() >= n){
				ok = 1;break;
			}
			S[s[i].length()].push_back(s[i]);
		}
		for(int i = 1 ; i < n ; i++ ) {
			if(S[i].size() != 2){
				ok = 1;
				break;
			}
			reverse(S[i][0].begin() , S[i][0].end());
			if(S[i][0] != S[i][1]){
				ok = 1;break;
			}
		}
		if(ok) {
			puts("No");continue;
		}
		puts("Yes");
	}
	
	return 0;
}

