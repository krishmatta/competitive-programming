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

  int t; cin >> t;
  while(t--) {
    int n; cin >> n;
    vector<int> p(n, 0);
    for(int i = 0; i < n; i++) {
      cin >> p[i];
    }
    vector<pair<int, int>> edges;
    priority_queue<int, std::vector<int>, std::greater<int>> mns;
    for(int i = 0; i < n; i++) {
      vector<int> attach;
      while(sz(mns) && mns.top() < p[i]) {
        attach.push_back(mns.top());
        mns.pop();
      }

      if(!sz(attach)) {
        mns.push(p[i]);
      } else {
        mns.push(attach[0]);
        for(int v : attach) {
          edges.push_back(make_pair(v, p[i]));
        }
      }
    }

    if(sz(edges) == (n - 1)) {
      cout << "Yes\n";
      for(pair<int, int> uv : edges) {
        cout << uv.first << " " << uv.second << "\n";
      }
    } else {
      cout << "No\n";
    }
  }
}
