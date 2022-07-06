#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double;
using str = string;

using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b) - 1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define rep(a) F0R(_, a)
#define each(a, x) for (auto& a: x)

const int dr[4] = {1, 0, -1, 0}, dc[4] = {0, 1, 0, -1};

const int MOD = 1e9+7;
const int INF = 1e9;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0);
  if (sz(name)) {
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
}

int m;

vector<pair<int, ll>> input(int n) {
  vector<pair<int, ll>> ret;
  F0R(i, n) {
    int x; cin >> x;
    if(!sz(ret) || ret[sz(ret) - 1].f != x) {
      ret.pb(mp(x, 1));
    } else {
      ret[sz(ret) - 1].s += 1;
    }
  }
  return ret;
}

bool apply(vector<pair<int, ll>>& curr) {
  bool can = false;
  vector<pair<int, ll>> ret;
  each(i, curr) {
    if(!(i.f % m)) {
      can = true;
      if(sz(ret) && ret[sz(ret) - 1].f == i.f / m) {
        ret[sz(ret) - 1].s += i.s * m;
      } else {
        ret.pb(mp(i.f / m, i.s * m));
      }
    } else {
      if(sz(ret) && ret[sz(ret) - 1].f == i.f) {
        ret[sz(ret) - 1].s += i.s;
      } else {
        ret.pb(mp(i.f, i.s));
      }
    }
  }
  curr = ret;
  return can;
}

bool equals(vector<pair<int, ll>> a, vector<pair<int, ll>> b) {
  if(sz(a) != sz(b)) {
    return false;
  }

  F0R(i, sz(a)) {
    if(a[i].f != b[i].f || a[i].s != b[i].s) {
      return false;
    }
  }
  return true;
}

void print(vector<pair<int, ll>> curr) {
  each(i, curr) {
    cout << i.f << " " << i.s << "  ";
  }
  cout << "\n";
}

int main() {
  setIO();

  int t; cin >> t;
  while(t) {
    int n; cin >> n >> m;
    vector<pair<int, ll>> a = input(n);
    int k; cin >> k;
    vector<pair<int, ll>> b = input(k);
    while(apply(a)) {}
    while(apply(b)) {}
    if(equals(a, b)) {
      cout << "YES";
    } else {
      cout << "NO";
    }
    cout << "\n";
    t--;
  }
}
