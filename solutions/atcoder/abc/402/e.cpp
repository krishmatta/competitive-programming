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

  int n, x; cin >> n >> x;
  vector<int> s;
  vector<int> c;
  vector<int> p;
  for(int i = 0; i < n; i++) {
    int si, ci, pi; cin >> si >> ci >> pi;
    s.push_back(si);
    c.push_back(ci);
    p.push_back(pi);
  }

  vector<vector<double>> dp(x + 1, vector<double>(1 << n, 0.0));
  for(int i = 0; i <= x; i++) {
    for(int j = 0; j < (1 << n); j++) {
      for(int k = 0; k < n; k++) {
        if((((j >> k) & 1) == 0) && (c[k] <= i)) {
          double success = dp[i - c[k]][j | (1 << k)] + s[k];
          double fail = dp[i - c[k]][j];
          double pk = ((double) p[k]) / 100;
          dp[i][j] = max(dp[i][j], success * pk + fail * (1 - pk));
        }
      }
    }
  }
  cout << setprecision(7) << dp[x][0];
}
