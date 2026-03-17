#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

const int MAXN = 2e5 + 1;
int n;
ll t[4*MAXN];

void build(vector<ll>& a, int v, int tl, int tr) {
  if(tl == tr) {
    t[v] = a[tl];
  } else {
    int tm = (tl + tr) / 2;
    build(a, v*2, tl, tm);
    build(a, v*2+1, tm+1, tr);
    t[v] = max(t[v*2], t[v*2+1]);
  }
}

ll mx(int v, int tl, int tr, int l, int r) {
  if(l > r) {
    return 0;
  }
  if(l == tl && r == tr) {
    return t[v];
  }
  int tm = (tl + tr) / 2;
  return max(mx(v*2, tl, tm, l, min(r, tm)), mx(v*2+1, tm+1, tr, max(l, tm+1), r));
}

void update(int v, int tl, int tr, int pos, ll new_val) {
  if(tl == tr) {
    t[v] = new_val;
  } else {
    int tm = (tl + tr) / 2;
    if(pos <= tm) {
      update(v*2, tl, tm, pos, new_val);
    } else {
      update(v*2+1, tm+1, tr, pos, new_val);
    }
    t[v] = max(t[v*2], t[v*2+1]);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<ll> h(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> h[i];
  }
  vector<ll> a(n, 0);
  for(int i = 0; i < n; i++) {
    cin >> a[i];
  }

  vector<ll> dp(n+1, 0);
  build(dp, 1, 0, n);

  for(int i = 0; i < n; i++) {
    update(1, 0, n, h[i], a[i] + mx(1, 0, n, 0, h[i] - 1));
  }

  cout << mx(1, 0, n, 0, n);
}
