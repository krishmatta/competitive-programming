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

  int n; cin >> n;
  vector<string> s;
  for(int i = 0; i < n; i++) {
    string si; cin >> si;
    s.push_back(si);
  }
  int x; cin >> x;
  string y; cin >> y;
  if(y == s[x-1]) {
    cout << "Yes";
  } else {
    cout << "No";
  }
}
