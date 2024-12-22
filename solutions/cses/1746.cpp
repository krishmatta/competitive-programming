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

  int n, m;
  cin >> n >> m;
  vector<int> x;
  for (int i = 0; i < n; i++) {
    int xi;
    cin >> xi;
    x.push_back(xi);
  }

  vector<int> dp(102, 0);
  dp[0] = 0;
  dp[m + 1] = 0;
  if (x[0] == 0) {
    for (int i = 1; i <= m; i++) {
      dp[i] = 1;
    }
  } else {
    dp[x[0]] = 1;
  }

  for (int i = 1; i < n; i++) {
    vector<int> nxt(102, 0);
    for (int j = 1; j <= m; j++) {
      if (x[i] == 0) {
        nxt[j] += dp[j - 1];
        nxt[j] %= MOD;
        nxt[j] += dp[j];
        nxt[j] %= MOD;
        nxt[j] += dp[j + 1];
        nxt[j] %= MOD;
      } else {
        if (x[i] == j) {
          nxt[j] += dp[j - 1];
          nxt[j] %= MOD;
          nxt[j] += dp[j];
          nxt[j] %= MOD;
          nxt[j] += dp[j + 1];
          nxt[j] %= MOD;
        }
      }
    }
    dp = nxt;
  }
  int ret = 0;
  for (int i = 1; i <= m; i++) {
    ret += dp[i];
    ret %= MOD;
  }
  cout << ret;
}
