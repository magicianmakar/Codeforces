#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> PII;
 
const int N = 5e5 + 5;
const int inf = 1e9 + 7;
PII x[N];
int mx[N];
 
int main() {
//	freopen("sam.in", "r", stdin);
	int ncase;
	for (scanf("%d", &ncase); ncase --; ) {
		int n;	scanf("%d", &n);
		for (int i = 0; i < n; i ++) {
			int a, b;	scanf("%d %d", &a, &b);
			x[i] = make_pair(a, b);
		}
		sort(x, x + n);
		mx[n] = -inf;
		for (int i = n - 1; i >= 0; i --) {
			mx[i] = max(x[i].second, mx[i + 1]);
		}
		int ans = inf;
		multiset<int> G;
		for (int i = 0; i < n; i ++) {
			int A = x[i].first;
			int B = mx[i + 1];
			auto it = G.lower_bound(A);
			ans = min(ans, abs(A - B));
			if (it != G.end() && *it >= B) ans = min(ans, abs(A - *it));
			if (it != G.begin()) {
				it --;
				if (*it >= B) ans = min(ans, abs(A - *it));
			}
			G.insert(x[i].second);
		}
		printf("%d\n", ans);
	}
}
