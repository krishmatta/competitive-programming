#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9+7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x; cin >> n >> x;
    vector<int> h;
    vector<int> s;
    for(int i = 0; i < n; i++) {
      int hi; cin >> hi;
      h.push_back(hi);
    }
    for(int i = 0; i < n; i++) {
      int si; cin >> si;
      s.push_back(si);
    }

    vector<int> dp(x + 1, 0);
    for(int i = 0; i < n; i++) {
      for(int j = x; j > -1; j--) {
	if(j >= h[i]) {
	  dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
	}
      }
    }
    cout << dp[x];
}
