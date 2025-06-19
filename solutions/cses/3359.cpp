#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int dr[2] = {0, 1};
int dc[2] = {1, 0};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n; cin >> n;
  vector<string> grid;
  for(int i = 0; i < n; i++) {
    string s; cin >> s;
    grid.push_back(s);
  }

  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, make_pair(-1, -1)));

  vector<pair<int, int>> curr; curr.push_back(make_pair(0, 0));
  for(int i = 0; i < 2 * n - 2; i++) {
    int mn = INF;

    for(pair<int, int> idx : curr) {
      int curr_char = (int) grid[idx.first][idx.second];
      mn = min(mn, curr_char);
    }

    vector<pair<int, int>> mn_set;
    for(pair<int, int> idx : curr) {
      int curr_char = (int) grid[idx.first][idx.second];
      if(curr_char == mn) {
        mn_set.push_back(idx);
      }
    }

    vector<pair<int, int>> next;
    for(pair<int, int> idx : mn_set) {
      for(int j = 0; j < 2; j++) {
        pair<int, int> next_idx = make_pair(idx.first + dr[j], idx.second + dc[j]);
        if(next_idx.first >= 0 && next_idx.first < n && next_idx.second >= 0 && next_idx.second < n && parent[next_idx.first][next_idx.second].first == -1) {
          parent[next_idx.first][next_idx.second] = idx;
          next.push_back(next_idx);
        }
      }
    }
    curr = next;
  }

  vector<char> ret;
  pair<int, int> curr_idx = make_pair(n - 1, n - 1);
  while(curr_idx.first != 0 || curr_idx.second != 0) {
    ret.push_back(grid[curr_idx.first][curr_idx.second]);
    curr_idx = parent[curr_idx.first][curr_idx.second];
  }
  ret.push_back(grid[0][0]);
  for(int i = sz(ret) - 1; i > -1; i--) {
    cout << ret[i];
  }
}
