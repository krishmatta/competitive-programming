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
    int n; cin >> n;
    int mn = INF;
    int mx = 0;
    for(int i = 0; i < n; i++) {
      int hi; cin >> hi;
      mn = min(mn, hi);
      mx = max(mx, hi);
    }

    cout << mx - mn + 1 << "\n";
  }
}
