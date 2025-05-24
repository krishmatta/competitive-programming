#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;
const int INF = 1e9;

#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()

struct Vertex {
  Vertex *l, *r;
  int mx;

  Vertex(int val) : l(nullptr), r(nullptr), mx(val) {}
  Vertex(Vertex *l, Vertex *r) : l(l), r(r), mx(-INF) {
    if (l) mx = max(mx, l->mx);
    if (r) mx = max(mx, r->mx);
  }
};

Vertex* build(vector<int> &a, int tl, int tr) {
  if(tl == tr)
    return new Vertex(a[tl]);
  int tm = (tl + tr) / 2;
  return new Vertex(build(a, tl, tm), build(a, tm+1, tr));
}

int get_mx(Vertex *v, int tl, int tr, int l, int r) {
  if(l > r)
    return -INF;
  if(l == tl && tr == r)
    return v->mx;
  int tm = (tl + tr) / 2;
  return max(get_mx(v->l, tl, tm, l, min(r, tm)), get_mx(v->r, tm+1, tr, max(l, tm+1), r));
}

Vertex* update(Vertex *v, int tl, int tr, int pos, int new_val) {
  if(tl == tr)
    return new Vertex(new_val);
  int tm = (tl + tr) / 2;
  if(pos <= tm)
    return new Vertex(update(v->l, tl, tm, pos, new_val), v->r);
  return new Vertex(v->l, update(v->r, tm+1, tr, pos, new_val));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q; cin >> n >> q;
  vector<int> a;
  for(int i = 0; i < n; i++) {
    int ai; cin >> ai;
    a.push_back(ai);
  }

  vector<int> idx = a;
  sort(all(idx));
  idx.erase(unique(all(idx)), idx.end());
  for(int i = 0; i < n; i++) {
    a[i] = lower_bound(all(idx), a[i]) - idx.begin();
  }

  vector<Vertex*> roots;
  vector<int> tmp(n + 1, 0);
  Vertex* root = build(tmp, 0, n);
  for(int i = 0; i < n; i++) {
    int prev = 0;
    if(a[i] > 0) {
      prev = get_mx(root, 0, n, 0, a[i] - 1);
    }
    int curr = get_mx(root, 0, n, a[i], a[i]);

    root = update(root, 0, n, a[i], max(curr, prev + 1));
    roots.push_back(root);
  }

  for(int i = 0; i < q; i++) {
    int ri, xi; cin >> ri >> xi;
    int j = lower_bound(all(idx),  xi) - idx.begin();
    if(idx[j] > xi) {
      j--;
    }
    cout << get_mx(roots[ri - 1], 0, n, 0, j) << "\n";
  }
}
