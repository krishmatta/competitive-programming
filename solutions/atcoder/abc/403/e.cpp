#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

struct Vertex {
  int next[26];
  bool in_x;
  set<int> yi;

  Vertex() {
    fill(begin(next), end(next), -1);
    in_x = false;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q; cin >> q;

  vector<Vertex> x(1);
  vector<Vertex> y(1);
  vector<string> ys;

  int ret = 0;
  for(int i = 0; i < q; i++) {
    int ti; cin >> ti;
    string si; cin >> si;

    if(ti == 1) {
      // Add to x trie
      int curr = 0;
      for(int j = 0; j < sz(si); j++) {
	int xj = si[j] - 'a';
	if(x[curr].next[xj] == -1) {
	  x[curr].next[xj] = sz(x);
	  x.emplace_back();
	}
	curr = x[curr].next[xj];
      }
      x[curr].in_x = true;

      // Prune y trie
      curr = 0;
      for(int j = 0; j < sz(si); j++) {
	if(curr == -1) {
	  break;
	}

	int xj = si[j] - 'a';
	curr = y[curr].next[xj];
      }

      if(curr != -1) { // Only if x has superstring in y
	set<int> yi = y[curr].yi;
	for(int j : yi) {
	  ret--;
	  curr = 0;
	  string sj = ys[j];
	  for(int k = 0; k < sz(sj); k++) {
	    y[curr].yi.erase(j);

	    int yj = sj[k] - 'a';
	    curr = y[curr].next[yj];
	  }
	  y[curr].yi.erase(j);
	}
      }
    } else {
      // Check if substring already exists in x
      int curr = 0;
      bool in_x = false;
      for(int j = 0; j < sz(si); j++) {
	if(curr == -1) {
	  break;
	}

	in_x |= x[curr].in_x;

	int yj = si[j] - 'a';
	curr = x[curr].next[yj];
      }

      if(curr != -1) {
	in_x |= x[curr].in_x;
      }

      // If not, add to y
      if(!in_x) {
	int ysi = sz(ys);
	ys.push_back(si);

	ret++;
	curr = 0;

	for(int j = 0; j < sz(si); j++) {
	  y[curr].yi.insert(ysi);
	  int yj = si[j] - 'a';
	  if(y[curr].next[yj] == -1) {
	    y[curr].next[yj] = sz(y);
	    y.emplace_back();
	  }
	  curr = y[curr].next[yj];
	}
	y[curr].yi.insert(ysi);
      }
    }

    cout << ret << "\n";
  }
}
