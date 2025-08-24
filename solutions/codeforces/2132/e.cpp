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

  ll t; cin >> t;
  while(t--) {
    ll n, m, q; cin >> n >> m >> q;

    vector<ll> a(n, 0);
    vector<ll> b(m, 0);

    for(ll i = 0; i < n; i++) {
      cin >> a[i];
    }

    for(ll i = 0; i < m; i++) {
      cin >> b[i];
    }

    sort(all(a));
    sort(all(b));

    vector<ll> pfix_a(n + 1, 0);
    vector<ll> pfix_b(m + 1, 0);

    for(ll i = 1; i <= n; i++) {
      pfix_a[i] = pfix_a[i-1] + a[i-1];
    }

    for(ll i = 1; i <= m; i++) {
      pfix_b[i] = pfix_b[i-1] + b[i-1];
    }

    vector<pair<ll, pair<ll, ll>>> aggregate;
    for(ll i = 0; i < n; i++) {
      aggregate.push_back(make_pair(a[i], make_pair(1, 0)));
    }
    for(ll i = 0; i < m; i++) {
      aggregate.push_back(make_pair(b[i], make_pair(0, 1)));
    }

    sort(all(aggregate));

    ll curr_a = 0;
    ll curr_b = 0;
    for(ll i = m + n - 1; i > -1; i--) {
      ll x = aggregate[i].first;
      ll in_a = aggregate[i].second.first;
      ll in_b = aggregate[i].second.second;

      curr_a += in_a;
      curr_b += in_b;

      aggregate[i] = make_pair(x, make_pair(curr_a, curr_b));
    }
    aggregate.push_back(make_pair(0, make_pair(0, 0)));

    for(ll i = 0; i < q; i++) {
      ll xi, yi, zi; cin >> xi >> yi >> zi;

      auto curr = aggregate[m + n - zi];

      ll want_x = curr.second.first;
      ll want_y = curr.second.second;

      ll have_x = want_x;
      ll have_y = want_y;

      if(want_x > xi) {
        have_x = xi;
        have_y = zi - have_x;
      } else if(want_y > yi) {
        have_y = yi;
        have_x = zi - have_y;
      }

      ll ai = n - have_x;
      ll bi = m - have_y;

      ll ret = (pfix_a[n] - pfix_a[ai]) + (pfix_b[m] - pfix_b[bi]);
      cout << ret << "\n";
    }
  }
}
