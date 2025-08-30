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

  ll x, y; cin >> x >> y;
  vector<ll> a; a.push_back(x); a.push_back(y);
  for(int i = 1; i < 9; i++) {
    string next = to_string(a[i-1]+a[i]);
    reverse(all(next));
    a.push_back(stoll(next));
  }
  cout << a[9];
}
