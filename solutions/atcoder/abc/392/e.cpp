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

  int n, m; cin >> n >> m;
  vector<vector<pair<int, int>>> adj(n + 1);
  for(int i = 0; i < m; i++) {
    int ai, bi; cin >> ai >> bi;
    adj[ai].push_back(make_pair(bi, i + 1));
    if(ai != bi) {
      adj[bi].push_back(make_pair(ai, i + 1));
    }
  }

  vector<pair<int, int>> extra;
  int curr_cc = -1;
  vector<int> cc(n + 1, -1);
  vector<int> rep(n + 1, 0);
  vector<bool> used(m + 1, false);
  for(int i = 1; i <= n; i++) {
    if(cc[i] == -1) {

      curr_cc++;
      rep[curr_cc] = i;
      cc[i] = curr_cc;

      queue<int> q; q.push(i);
      while(!q.empty()) {
	int j = q.front(); q.pop();

	for(pair<int, int> kl : adj[j]) {
	  int k = kl.first;
	  int l = kl.second;

	  if(cc[k] == curr_cc && !used[l]) {
	    extra.push_back(kl);
	    used[l] = true;
	  } else if (cc[k] == -1) {
	    cc[k] = curr_cc;
	    q.push(k);
	    used[l] = true;
	  }
	}
      }
    }
  }

  cout << curr_cc << "\n";
  int prev = 0;
  vector<bool> merged(n, false);
  merged[0] = true;
  for(int i = 0; i < sz(extra); i++) {
    int og = extra[i].first;
    int edge = extra[i].second;
    int ccc = cc[og];

    if(!merged[ccc]) {
      cout << edge << " " << og << " " << rep[prev] << "\n";
      merged[ccc] = true;
    } else {
      while(prev <= curr_cc && merged[prev]) {
	prev++;
      }

      if(prev > curr_cc) {
	break;
      }

      cout << edge << " " << og << " " << rep[prev] << "\n";
      merged[prev] = true;
    }
  }
}
