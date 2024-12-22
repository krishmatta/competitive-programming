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

  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= x; i++) {
    for (int j = 0; j < n; j++) {
      if (i >= c[j]) {
        dp[i] += dp[i - c[j]];
        dp[i] %= MOD;
      }
    }
  }

  cout << dp[x];
}
