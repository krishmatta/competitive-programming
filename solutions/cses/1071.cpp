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

  int t;
  cin >> t;
  while (t--) {
    ll y, x;
    cin >> y >> x;
    ll layer = max(y, x);
    ll ret = (layer - 1) * (layer - 1);

    if (layer % 2) {
      if (y == layer) {
        ret += x;
      } else {
        ret += layer + (layer - y);
      }
    } else {
      if (x == layer) {
        ret += y;
      } else {
        ret += layer + (layer - x);
      }
    }

    cout << ret << "\n";
  }
}
