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

#define oo 1e18
#define mx 888

int tc , n , m , p;
LL dist[mx][mx] , w[mx] , dp[mx] , day[mx];
vector< PII > con[mx];

void dijkstra(int st){
	priority_queue<int , vector<int> , greater<int> > que;
	while(!que.empty()) que.pop();
	for(int i = 0 ; i < mx ; i++ ) dist[st][i] = oo;
	dist[st][st] = 0;
	que.push(st);
	while(!que.empty()){
		int u  =que.top();que.pop();
		for(int i= con[u].size() - 1 ; ~i ; i-- ){
			int v =  con[u][i].first , cuv = con[u][i].second;
			if(dist[st][u] + cuv <= dist[st][v]){
				dist[st][v] = dist[st][u] + cuv;
				que.push(v);
			}
		}
	}
}

void solve(){
	priority_queue<int , vector<int> , greater<int> > que;
	while(!que.empty()) que.pop();
	for(int i = 0 ; i < mx ; i++ ) dp[i] = 0 , day[i] = oo;
	que.push(0);dp[0] = p , day[0] = 0;
	while(!que.empty()){
		int u = que.top();que.pop();
//		Error(u)
		for(int i = con[u].size() - 1 ; ~i ; i-- ){
			int v = con[u][i].first , cuv = con[u][i].second;
			for(int j = 0 ; j < n ; j++ ) {
				if(dist[j][v] != oo && day[j] != oo){
					LL val = max(0LL , (dist[j][v] - dp[j] - 1 + w[j]) / w[j]);
					if(day[v] >= val + day[j]){
						day[v] = val + day[j];
						if(dp[v] == oo) dp[v] = val * w[j] + dp[j] - dist[j][v];
						else dp[v] = max(val * w[j] + dp[j] - dist[j][v] , dp[v]);
						que.push(v);
					}
				}
			}
		}
//		if(u == n-1) return;
	}
}

int main(){
//	freopen("sam.txt" , "r" , stdin);
	cin>>tc;
	while(tc--){
		cin>>n>>m>>p;
		for(int i = 0 ; i < mx ; i++ ) con[i].clear();
		memset(dist , 0 , sizeof dist);
		for(int i = 0 ; i < n ; i++ ) cin>>w[i];
		for(int i = 0 ; i < m ; i++ ){
			int u , v , cuv;
			cin>>u>>v>>cuv;u-- , v--;
			con[u].push_back(PII(v , cuv));
		}
		for(int i = 0 ; i < n ; i++ ) dijkstra(i);
		solve();
//		for(int i = 0 ; i < n ; i++ ) {
//			Error(dp[i])Error(day[i])
//		}
		if(dist[0][n-1] == oo) {
			cout<<-1<<endl;
			continue;
		}
		if(day[n-1] != oo) cout<<day[n-1]<<endl;
		else cout<<-1<<endl;
	}
	return 0;
}

