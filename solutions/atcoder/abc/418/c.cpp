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

  int n, q; cin >> n >> q;
  vector<ll> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(all(a));
  vector<ll> prefix(n+1, 0);
  for(int i = 1; i <= n; i++) {
    prefix[i] = prefix[i-1] + a[i-1];
  }

  for(int i = 0; i < q; i++) {
    int bi; cin >> bi;
    int j = lower_bound(all(a), bi) - a.begin();
    if(j >= n) {
      cout << -1 << "\n";
    } else {
      ll xi = prefix[j] + (ll) (n - j) * ((ll) bi - 1) + 1;
      cout << xi << "\n";
    }
  }
}
