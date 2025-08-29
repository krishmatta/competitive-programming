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
    int n; cin >> n;
    vector<int> a(n, 0);
    vector<int> next_index(n, -1);
    vector<int> dp(n+1, 0);
    vector<vector<int>> indices(n+1, vector<int>());
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }

    for(int i = n - 1; i > -1; i--) {
      indices[a[i]].push_back(i);
      if(sz(indices[a[i]]) >= a[i]) {
        next_index[i] = indices[a[i]][sz(indices[a[i]])-a[i]];
      }
    }

    for(int i = n-1; i > -1; i--) {
      dp[i] = dp[i+1];
      if(next_index[i] != -1) {
        dp[i] = max(dp[i], a[i] + dp[next_index[i] + 1]);
      }
    }

    cout << dp[0] << "\n";
  }
}
