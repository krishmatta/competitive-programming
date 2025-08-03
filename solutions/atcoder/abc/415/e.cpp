#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const ll INF = 1e15;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h, w; cin >> h >> w;
  vector<vector<ll>> a(h, vector<ll>(w, 0));
  for(int i = 0; i < h; i++) {
    for(int j = 0; j < w; j++) {
      cin >> a[i][j];
    }
  }

  vector<ll> p(h + w - 1, 0);
  for(int i = 0; i < h + w - 1; i++) {
    cin >> p[i];
  }

  vector<ll> dp(w, 0);
  for(int i = h - 1; i > -1; i--){
    vector<ll> next_dp(w, 0);

    for(int j = w - 1; j > -1; j--) {
      int day = i + j;
      ll need = max(0LL, p[day] - a[i][j]);

      if(day < h + w - 2) {
        ll mn = INF;

        if(j + 1 < w) {
          mn = min(mn, next_dp[j+1]);
        }

        if(i + 1 < h) {
          mn = min(mn, dp[j]);
        }

        if(p[day] < a[i][j]) {
          mn -= a[i][j] - p[day];
        }

        need += max(0LL, mn);
      }

      next_dp[j] = need;
    }
    dp = next_dp;
  }
  cout << dp[0];
}
