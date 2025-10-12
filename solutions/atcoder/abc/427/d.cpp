#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, m, k; cin >> n >> m >> k;
    string s; cin >> s;
    vector<vector<int>> adj(n, vector<int>());
    for(int i = 0; i < m; i++) {
      int ui, vi; cin >> ui >> vi; ui--; vi--;
      adj[ui].push_back(vi);
    }

    vector<int> dp(n, 0); // 0 for alice, 1 for bob
    for(int i = 0; i < n; i++) {
      if(s[i] == 'B') {
        dp[i] = 1;
      } 
    }

    for(int i = 1; i < 2 * k + 1; i++) {
      vector<int> next_dp(n, 0);
      for(int j = 0; j < n; j++) {
        if((i & 1) == 0) {
          next_dp[j] = 1;
        }
        for(int l : adj[j]) {
          if(i & 1) {
            next_dp[j] = max(next_dp[j], dp[l]);
          } else {
            next_dp[j] = min(next_dp[j], dp[l]);
          }
        }
      }
      dp = next_dp;
    }

    if(dp[0]) {
      cout << "Bob";
    } else {
      cout << "Alice";
    }
    cout << "\n";
  }
}
