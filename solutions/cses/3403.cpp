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

  int n, m; cin >> n >> m;
  vector<int> a(n, 0);
  vector<int> b(m, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for(int i = 0; i < m; i++) {
    cin >> b[i];
  }

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for(int i = n - 1; i > -1; i--) {
    for(int j = m - 1; j > -1; j--) {
      dp[i][j] = int(a[i] == b[j]) + dp[i+1][j+1];
      dp[i][j] = max(dp[i][j], dp[i+1][j]);
      dp[i][j] = max(dp[i][j], dp[i][j+1]);
    }
  }
  cout << dp[0][0] << "\n";
  int i = 0;
  int j = 0;
  while(i < n && j < m) {
    if(dp[i][j] == int(a[i] == b[j]) + dp[i+1][j+1]) {
      if(a[i] == b[j]) {
        cout << a[i] << " ";
      }
      i = i+1;
      j = j+1;
    } else if(dp[i][j] == dp[i+1][j]) {
      i = i+1;
    } else {
      j = j+1;
    }
  }
}
