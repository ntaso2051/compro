#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> ip;
typedef long long ll;
const int inf = 1000000007;

class unionfind {
 public:
  UnionFind(int n = 0) : d(n, -1) {}
  int find(int x) const {
    if (d[x] < 0) return x;
    return d[x] = find(d[x]);
  }
  bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (d[x] > d[y]) swap(x, y);
    d[x] += d[y];
    d[y] = x;
    return true;
  }
  bool same(int x, int y) { return find(x) == find(y); }
  int size(int x) { return -d[find(x)]; }

 private:
  vector<int> d;
}


int main() {
  ll n, q;
  cin >> n >> q;
  unionfind uf(n);
  rep(i, q) {
    ll p, a, b;
    cin >> p >> a >> b;
    if (!p) {
      uf.unite(a, b);
    } else {
      if (uf.same(a, b))
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
  }
  return 0;
}