#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;
const int N = 1e6 + 1;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, k; cin >> n >> k;
  vector<int> a;
  for(int i = 0; i < n; i++) {
    int ai; cin >> ai;
    a.push_back(ai);
  }

  vector<vector<int>> sieve(N);
  for(int i = 1; i * i < N; i++) {
    for(int j = i * i; j < N; j += i) {
      sieve[j].push_back(i);
      if(j / i != i) {
	sieve[j].push_back(j / i);
      }
    }
  }

  vector<int> num(N, 0);
  for(int i = 0; i < n; i++) {
    for(int d : sieve[a[i]]) {
      num[d]++;
    }
  }

  for(int i = 0; i < n; i++) {
    int ret = 1;
    for(int d : sieve[a[i]]) {
      if(num[d] >= k) {
	ret = max(ret, d);
      }
    }
    cout << ret << "\n";
  }
}
