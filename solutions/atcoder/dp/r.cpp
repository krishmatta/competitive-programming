#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

vector<vector<ll>> matrix_mul(vector<vector<ll>>& a, vector<vector<ll>>& b) {
  vector<vector<ll>> ret(sz(a), vector<ll>(sz(b[0]), 0LL));
  for(int i = 0; i < sz(a); i++) {
    for(int j = 0; j < sz(b[0]);j ++) {
      ll curr = 0;
      for(int k = 0; k < sz(a[0]); k++) {
        curr += (1LL * a[i][k] * b[k][j]) % MOD;
        curr %= MOD;
      }
      ret[i][j] = curr;
    }
  }
  return ret;
}

vector<vector<ll>> matpow(vector<vector<ll>>& a, ll b) {
  if(b == 0) {
    vector<vector<ll>> ret(sz(a), vector<ll>(sz(a[0]), 0));
    for(int i = 0; i < sz(a); i++) {
      ret[i][i] = 1;
    }
    return ret;
  }

  vector<vector<ll>> ret = matpow(a, b / 2);
  ret = matrix_mul(ret, ret);
  if(b % 2) {
    return matrix_mul(ret, a);
  } else {
    return ret;
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, k; cin >> n >> k;
  vector<vector<ll>> adj(n, vector<ll>(n, 0));
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      int aij; cin >> aij;
      if(aij) {
        adj[i][j] = 1;
      }
    }
  }

  vector<vector<ll>> curr = matpow(adj, k);
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      ret += curr[i][j];
      ret %= MOD;
    }
  }
  cout << ret;
}
