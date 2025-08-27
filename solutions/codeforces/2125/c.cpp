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

  vector<ll> primes = {2LL, 3LL, 5LL, 7LL};

  int t; cin >> t;
  while(t--) {
    ll l, r; cin >> l >> r;

    ll ret = 0;
    for(ll i = 1; i < 16; i++) {
      vector<ll> nums;
      ll tot = 0;
      ll product = 1;
      for(int j = 0; j < 4; j++) {
        ll mask = 1 << j;
        if(i & mask) {
          product *= primes[j];
          tot++;
        }
      }


      ll count = (r / product) - ((l - 1) / product);
      if(tot & 1) {
        ret += count;
      } else {
        ret -= count;
      }
    }

    cout << (r - l + 1) - ret << "\n";
  }
}
