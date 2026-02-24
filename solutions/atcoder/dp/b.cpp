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
  vector<int> h(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<int> dp(n, INF); dp[n-1] = 0;
  for(int i = n - 2; i > -1; i--) {
    for(int j = 1; j < k + 1; j++) {
      int l = i + j;
      if(l < n) {
        dp[i] = min(dp[i], dp[l] + abs(h[i] - h[l]));
      } else {
        break;
      }
    }
  }
  cout << dp[0];
}
