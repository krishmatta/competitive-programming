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

  string s, t; cin >> s >> t;
  vector<vector<int>> dp(sz(s)+1, vector<int>(sz(t)+1, 0));
  for(int i = sz(s) - 1; i > -1; i--) {
    for(int j = sz(t) - 1; j > -1; j--) {
      dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
      dp[i][j] = max(dp[i][j], dp[i+1][j+1]);
      if(s[i] == t[j]) {
        dp[i][j] = max(dp[i][j], 1 + dp[i+1][j+1]);
      }
    }
  }

  int curr = dp[0][0];
  int i = 0;
  int j = 0;
  while(curr) {
    if(s[i] == t[j] && curr == dp[i+1][j+1] + 1) {
      cout << s[i];
      i++;
      j++;
      curr--;
    } else {
      if(i + 1 < sz(s) && j + 1 < sz(t) && curr == dp[i+1][j+1]) {
        i++;
        j++;
      } else if(i + 1 < sz(s) && curr == dp[i+1][j]) {
        i++;
      } else {
        j++;
      }
    }
  }
}
