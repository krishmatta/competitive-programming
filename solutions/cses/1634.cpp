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

  int n, x;
  cin >> n >> x;
  vector<int> c;
  for (int i = 0; i < n; i++) {
    int ci;
    cin >> ci;
    c.push_back(ci);
  }

  vector<int> dp(x + 1, INF);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= x; j++) {
      if (j >= c[i]) {
        dp[j] = min(dp[j], dp[j - c[i]] + 1);
      }
    }
  }

  if (dp[x] == INF) {
    cout << -1;
  } else {
    cout << dp[x];
  }
}
