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

  int n; cin >> n;
  vector<long double> p(n, 0.0);
  for(int i = 0; i < n; i++) {
    cin >> p[i];
  }

  vector<long double> dp(1, 1.0);
  for(int i = 0; i < n; i++) {
    vector<long double> next_dp(i + 2, 0.0);
    for(int j = 0; j < sz(next_dp); j++) {
      if(j > 0) {
        next_dp[j] += p[i] * dp[j - 1];
      }

      if(j < sz(dp)) {
        next_dp[j] += (1 - p[i]) * dp[j];
      }
    }
    dp = next_dp;
  }

  long double ret = 0.0;
  for(int i = (n + 1) / 2; i <= n; i++) {
    ret += dp[i];
  }
  cout << fixed << setprecision(15) << ret << "\n";
}
