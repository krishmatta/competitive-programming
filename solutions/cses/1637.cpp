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

  int n;
  cin >> n;

  vector<int> dp(n + 1, INF);
  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    int j = i;
    while (j > 0) {
      int x = j % 10;
      dp[i] = min(dp[i], dp[i - x] + 1);
      j /= 10;
    }
  }

  cout << dp[n];
}
