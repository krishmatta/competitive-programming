#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

vector<vector<ll>> dp(5001, vector<ll>(3, 0)); // dp[i] -> given i money, max of each vitamin we can get
int n, x;

ll min_cost(ll v, int k) {
  int lo = 0;
  int hi = x + 1;

  while(lo < hi) {
    int mid = lo + (hi - lo) / 2;

    if (dp[mid][k] >= v) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }

  if(lo == 5001) {
    return INF;
  }
  return lo;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> x;
  vector<vector<ll>> vac;
  for(int i = 0; i < n; i++) {
    ll vi, ai, ci; cin >> vi >> ai >> ci;
    vector<ll> vaci;
    vaci.push_back(vi);
    vaci.push_back(ai);
    vaci.push_back(ci);
    vac.push_back(vaci);
  }

  for(int i = 0; i < n; i++) {
    for(int j = x; j >-1; j--) {
      for(int k = 1; k <= 3; k++) {
	if(vac[i][0] == k && j >= vac[i][2]) {
	  dp[j][k-1] = max(dp[j][k-1], dp[j - vac[i][2]][k-1] + vac[i][1]);
	}
      }
    }
  }

  ll lo = 0;
  ll hi = 1e9;
  while(lo < hi) {
    ll mid = lo + (hi - lo + 1) / 2;
    ll cost = min_cost(mid, 0) + min_cost(mid, 1) + min_cost(mid, 2);
    if(cost <= (ll) x) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }

  cout << lo;
}
