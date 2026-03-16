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

  int n, k; cin >> n >> k;
  vector<int> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<int> dp(k + 1, 1);
  for(int i = 0; i < n; i++) {
    vector<int> next_dp; next_dp.push_back(1);
    for(int j = 1; j <= k; j++) {
      if(j <= a[i]) {
        next_dp.push_back((next_dp[j-1] + dp[j]) % MOD);
      } else {
        next_dp.push_back(((dp[j] - dp[j-a[i]-1] + MOD) % MOD + next_dp[j-1]) % MOD);
      }
    }
    dp = next_dp;
  }
  cout << (dp[k] - dp[k-1] + MOD) % MOD;
}
