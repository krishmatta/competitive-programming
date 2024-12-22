#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> uv;
    vector<vector<int>> vu(n + 1, vector<int>());
    for (int i = 0; i < m; i++) {
      int v, u;
      cin >> u >> v;
      uv.push_back(make_pair(u, v));
      vu[v].push_back(u);
    }

    vector<int> dp(n + 1, INF);
    dp[1] = 0;
    for (int i = 2; i <= n; i++) {
      dp[i] = dp[i - 1] + 1;
      for (int j : vu[i]) {
        dp[i] = min(dp[i], dp[j] + 1);
      }
    }

    sort(all(uv));

    vector<int> max_diff(1, 0);
    int curr_uv = 0;
    for (int i = 1; i <= n; i++) {
      max_diff.push_back(max_diff[i - 1]);
      while (curr_uv < m && uv[curr_uv].first <= i) {
        max_diff[i] =
            max(max_diff[i], uv[curr_uv].second - dp[uv[curr_uv].first] - 1);
        curr_uv++;
      }
    }

    for (int i = 1; i < n; i++) {
      if (max_diff[i - 1] > i) {
        cout << 0;
      } else {
        cout << 1;
      }
    }
    cout << "\n";
  }
}
