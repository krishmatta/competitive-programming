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

  int t; cin >> t;
  while(t--) {
    string x, y; cin >> x >> y;
    int n = sz(x);
    vector<int> dp(2, 0);
    for(int i = n - 1; i > -1; i--) {
      int xi = x[i] - '0';
      int yi = y[i] - '0';
      vector<int> nxt(2, 0);
      for(int j = 0; j < 2; j++) {
        int to = xi ^ j;
        nxt[j] = dp[to];
        if(to != yi) {
          nxt[j]++;
        }
        nxt[j] = min(nxt[j], dp[1-to] + 1);
      }
      dp = nxt;
    }
    cout << dp[0] << "\n";
  }
}
