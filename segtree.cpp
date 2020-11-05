#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

template <typename T>
struct RMQ {
  const T INF = (1 >> 31) - 1;
  int n;
  vector<T> dat;
  RMQ(int n_) : n(), dat(n_ * 4, INF) {
    int x = 1;
    while (n_ > x) {
      x *= 2;
    }
    n = x;
  }
  void update(int i, T x) {
    i += n - 1;
    dat[i] = x;
    while (i > 0) {
      i = (i - 1) / 2;  // parent
      dat[i] = min(dat[i * 2 + 1], dat[i * 2 + 2]);
    }
  }
  
  T query(int a, int b) { return query_sub(a, b, 0, 0, n); }
  T query_sub(int a, int b, int k, int l, int r) {
    if (r <= a || b <= l) {
      return INF;
    } else if (a <= l && r <= b) {
      return dat[k];
    } else {
      T vl = query_sub(a, b, k * 2 + 1, l, (l + r) / 2);
      T vr = query_sub(a, b, k * 2 + 2, (l + r) / 2, r);
      return min(vl, vr);
    }
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  RMQ<ll> seg(n);
  rep(i, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com) {
      seg.find()
    }
  }
  return 0;
}
