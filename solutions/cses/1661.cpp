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

  ll n, x; cin >> n >> x;
  vector<ll> a;
  for(int i = 0; i < n; i++) {
    ll ai; cin >> ai;
    a.push_back(ai);
  }

  map<ll, ll> prev; prev[0] = 1;
  ll ret = 0;
  ll curr = 0;
  for(int i = 0; i < n; i++) {
    curr += a[i];

    ll need = curr - x;
    if(prev.find(need) != prev.end()) {
      ret += prev[need];
    }

    if(prev.find(curr) == prev.end()) {
      prev[curr] = 0;
    }
    prev[curr]++;
  }

  cout << ret;
}
