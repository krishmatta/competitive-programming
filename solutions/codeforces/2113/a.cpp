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
    int k, a, b, x, y; cin >> k >> a >> b >> x >> y;
    if(b > a) {
      swap(a, b);
      swap(x, y);
    }
    int ret = 0;
    if(x >= y) {
      ret = max(0, (k - b) / y);
      if(k >= b) {
        ret++;
      }
    } else {
      ret = max(0, (k - a) / x);
      if(k >= a) {
        ret++;
      }
      k -= x * ret;
      ret += max(0, (k - b) / y);
      if(k >= b) {
        ret++;
      }
    }
    cout << ret << "\n";
  }
}
