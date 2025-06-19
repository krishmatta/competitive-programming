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
  int sum = 0;
  vector<int> x(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> x[i];
    sum += x[i];
  }

  vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
  dp[0][x[0]] = true;
  for(int i = 1; i < n; i++) {
    dp[i][x[i]] = true;
    for(int j = 0; j < sum+1; j++) {
      dp[i][j] = dp[i][j] || dp[i-1][j];
      if(j >= x[i]) {
        dp[i][j] = dp[i][j] || dp[i-1][j-x[i]];
      }
    }
  }

  vector<int> ret;
  for(int i = 0; i < sum+1; i++) {
    if(dp[n-1][i]) {
      ret.push_back(i);
    }
  }
  cout << sz(ret) << "\n";
  for(int i : ret) {
    cout << i << " ";
  }
}
