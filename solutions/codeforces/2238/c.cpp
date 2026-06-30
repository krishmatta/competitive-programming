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
    vector<int> p(n, -1);
    vector<int> deg(n, 0);
    vector<vector<int>> children(n, vector<int>());
    for(int i = 1; i < n; i++) {
      cin >> p[i]; p[i]--;
      deg[i]++; deg[p[i]]++;
      children[p[i]].push_back(i);
    }

    deque<int> dq;
    for(int i = 0; i < n; i++) {
      if(deg[i] == 1) {
        dq.push_back(i);
      }
    }

    vector<ll> height(n, 0);
    while(sz(dq)) {
      int curr = dq.front(); dq.pop_front();

      ll sub = 0;
      for(int i : children[curr]) {
        sub = max(sub, height[i]);
      }
      height[curr] = sub + 1;

      if(p[curr] != -1) {
        deg[p[curr]]--;
        if(deg[p[curr]] <= 1) {
          dq.push_back(p[curr]);
        }
      }
    }

    fill(all(deg), 0);

    for(int i = 1; i < n; i++) {
      deg[i]++; deg[p[i]]++;
    }

    for(int i = 0; i < n; i++) {
      if(deg[i] == 1) {
        dq.push_back(i);
      }
    }

    vector<ll> dp(n, 0);
    while(sz(dq)) {
      int curr = dq.front(); dq.pop_front();

      if(sz(children[curr]) == 0) {
        dp[curr] = 1;
      } else if(sz(children[curr]) == 1) {
        dp[curr] = 1LL + dp[children[curr][0]];
      } else {
        ll sub = 0;
        vector<ll> heights;
        for(int i : children[curr]) {
          sub += dp[i];
          heights.push_back(height[i]);
        }

        sort(all(heights));

        dp[curr] = 1LL + sub + heights[sz(heights)-2];
      }

      if(p[curr] != -1) {
        deg[p[curr]]--;
        if(deg[p[curr]] <= 1) {
          dq.push_back(p[curr]);
        }
      }
    }

    cout << dp[0] << "\n";
  }
}
