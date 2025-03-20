#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

vector<int> a(2e5+1, 0);
vector<int> vis(2e5+1, 0);
vector<vector<pair<int, int>>> adj;

bool good = true;

int dfs(int u, int k, int t) {
  int ret = 0;
  for(pair<int, int> uv : adj[u]) {
    int v = uv.first;
    int w = uv.second;

    int mask = 1 << k;

    int au = a[u] & mask;
    int av = a[v] & mask;
    w &= mask;

    if(vis[v] == t) {
      if((au ^ av) != w) {
	good = false;
	return 0;
      }
    } else {
      vis[v] = t;
      a[v] &= ~mask;
      a[v] |= (au ^ w);

      int curr = 0;
      if(a[v] & mask) {
	curr++;
      }
      ret += curr + dfs(v, k, t);
    }
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m; cin >> n >> m;
  for(int i = 0; i < n + 1; i++) {
    vector<pair<int, int>> curr;
    adj.push_back(curr);
  }

  for(int i = 0; i < m; i++) {
    int xi, yi, zi; cin >> xi >> yi >> zi;
    adj[xi].push_back(make_pair(yi, zi));
    adj[yi].push_back(make_pair(xi, zi));
  }

  int t = 1;
  for(int i = 1; i < n + 1 && good; i++) {
    if(!vis[i]) {
      for(int j = 0; j <= 30; j++) {
	int mask = 1 << j;

	vis[i] = t;
	int count_zero = dfs(i, j, t);

	t++;

	vis[i] = t;
	a[i] |= mask;
	int count_one = dfs(i, j, t) + 1;

	t++;

	if(count_zero < count_one) {
	  a[i] &= ~mask;
	  vis[i] = t;
	  dfs(i, j, t);
	  t++;
	}
      }
    }
  }

  if(good) {
    for(int i = 1; i < n + 1; i++) {
      cout << a[i] << " ";
    }
  } else {
    cout << -1;
  }
}
