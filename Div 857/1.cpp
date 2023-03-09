#include <bits/stdc++.h>

using namespace std;

#define mx 1111

int tc , n;
int a[mx];

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>tc;
	while(tc--){
		cin>>n;
		int pos = 0 , neg = 0;
		for(int i = 0 ; i < n ;i++ ) {
			cin>>a[i];
			if(a[i] < 0) neg++;
			else pos++;
		}
		for(int i=0 ; i<n ; i++ ) {
			if(i < pos) cout<<i+1<<" \n"[i == n-1];
			else cout<<2*pos - i-1<<" \n"[i == n-1];
		}
		for(int i = 0 ; i < n ; i++ ){
			if(i < 2*neg){
				if(i & 1) cout<<0;
				else cout<<1;
			}else{
				cout<<i - 2*neg+1; 
			}
			cout<<" \n"[i == n-1];
		}
	}
	
}
