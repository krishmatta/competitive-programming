#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 998244353;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int gcd(int a, int b, int& x, int& y) {
  if(b == 0) {
    x = 1;
    y = 0;
    return a;
  }

  int x1, y1;
  int d = gcd(b, a % b, x1, y1);
  x = y1;
  y = x1 - y1 * (a / b);
  return d;
}

int inverse(int x) {
  int ret, temp;
  gcd(x, MOD, ret, temp);
  return ret;
}

void pos_mod(ll& x) {
  int ret = x % MOD;
  if(ret < 0) {
    ret += MOD;
  }
  x = ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t; cin >> t;
  while(t--) {
    int n, q; cin >> n >> q;
    vector<pair<int, int> > a_pair;
    for(int i = 0; i < n; i++) {
      int ai; cin >> ai;
      a_pair.push_back(make_pair(ai, i));
    }
    vector<pair<int, int> > b_pair;
    for(int i = 0; i < n; i++) {
      int bi; cin >> bi;
      b_pair.push_back(make_pair(bi, i));
    }

    sort(all(a_pair));
    sort(all(b_pair));

    vector<int> a_inv(n, 0);
    vector<int> b_inv(n, 0);

    for(int i = 0; i < n; i++) {
      pair<int, int> ai = a_pair[i];
      pair<int, int> bi = b_pair[i];

      a_inv[ai.second] = i;
      b_inv[bi.second] = i;
    }

    vector<int> a;
    vector<int> b;
    vector<int> a_idx;
    vector<int> b_idx;
    for(int i = 0; i < n; i++) {
      a.push_back(a_pair[i].first);
      a_idx.push_back(a_pair[i].second);

      b.push_back(b_pair[i].first);
      b_idx.push_back(b_pair[i].second);
    }

    ll curr = 1;
    for(int i = 0; i < n; i++) {
      ll mn = min(a[i], b[i]);
      curr *= mn;
      curr %= MOD;
    }

    cout << curr << " ";

    for(int k = 0; k < q; k++) {
      int o, x; cin >> o >> x; x--;
      if(o == 1) {
	int i = a_inv[x];

	int j = upper_bound(all(a), a[i]) - a.begin(); j--; // last element equal to us (want to swap w)

	// compute out
	int i_term = min(a[i], b[i]);
	ll inv_i = inverse(i_term) % MOD;
	curr *= inv_i;
	pos_mod(curr);

	if(i != j) {
	    int j_term = min(a[j], b[j]);
	    ll inv_j = inverse(j_term) % MOD;
	    curr *= inv_j;
	    pos_mod(curr);
	}

	// handle swapping
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp + 1;

	int jx = a_idx[j]; // original index

	a_idx[j] = a_idx[i];
	a_idx[i] = jx;

	a_inv[x] = j;
	a_inv[jx] = i;

	// compute in
	i_term = min(a[i], b[i]);
	curr *= (ll) i_term;
	curr %= MOD;

	if(i != j) {
	    int j_term = min(a[j], b[j]);
	    curr *= (ll) j_term;
	    curr %= MOD;
	}
      } else {
	int i = b_inv[x];

	int j = upper_bound(all(b), b[i]) - b.begin(); j--; // last element equal to us (want to swap w)

	// compute out
	int i_term = min(a[i], b[i]);
	ll inv_i = inverse(i_term) % MOD;
	curr *= inv_i;
	pos_mod(curr);

	if(i != j) {
	    int j_term = min(a[j], b[j]);
	    ll inv_j = inverse(j_term) % MOD;
	    curr *= inv_j;
	    pos_mod(curr);
	}

	// handle swapping
	int tmp = b[i];
	b[i] = b[j];
	b[j] = tmp + 1;

	int jx = b_idx[j]; // original index

	b_idx[j] = b_idx[i];
	b_idx[i] = jx;

	b_inv[x] = j;
	b_inv[jx] = i;

	// compute in
	i_term = min(a[i], b[i]);
	curr *= (ll) i_term;
	curr %= MOD;

	if(i != j) {
	    int j_term = min(a[j], b[j]);
	    curr *= (ll) j_term;
	    curr %= MOD;
	}
      }
      cout << curr << " ";
    }

    cout << "\n";
  }
}
