// abc070c

#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int inf = 1000000007;

ll gcd(ll x, ll y) {
  return (x % y) ? gcd(y, x % y) : y;
}

ll lcm(ll x, ll y) {
  return x / gcd(x, y) * y;
}

int main() {
  int n;
  cin >> n;
  ll pre;
  cin >> pre;
  for (int i = 1; i < n; i++) {
    ll tmp;
    cin >> tmp;
    pre = lcm(pre, tmp);
  }
  cout << pre << endl;
  return 0;
}