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
    int n, s; cin >> n >> s;

    int mn = INF;
    int mx = 0;
    for(int i = 0; i < n; i++) {
      int xi; cin >> xi;
      mn = min(mn, xi);
      mx = max(mx, xi);
    }

    int l = max(0, s - mn);
    int r = max(0, mx - s);

    cout << min(2 * l + r, 2 * r + l) << "\n";
  }
}
