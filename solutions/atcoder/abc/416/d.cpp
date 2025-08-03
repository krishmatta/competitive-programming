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
    ll m; cin >> m;
    vector<ll> a(n, 0);
    vector<ll> b(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
      cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    vector<bool> use(n, false);

    ll prev = -1;
    ll left = sz(b)-1;
    ll ret = 0;
    for(int i = sz(b) - 1; i > -1; i--) {
      ll complement = m - b[i] - 1;
      ll curr = upper_bound(all(a), complement) - a.begin();
      curr = max(curr, prev + 1);
      prev = curr;
      left = i;
      if(curr < sz(a)) {
        ret += (a[curr] + b[i]) % m;
        use[curr] = true;
        left--;
      } else {
        break;
      }
    }

    for(int i = 0; i < n; i++) {
      if(!use[i]) {
        ret += a[i];
      }

      if(i <= left) {
        ret += b[i];
      }
    }

    cout << ret << "\n";
  }
}
