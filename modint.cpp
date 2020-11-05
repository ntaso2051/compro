#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;

const int mod = 1000000007;

class mint {
  ll x;

 public:
  constexpr mint(ll x = 0) : x((x % mod + mod) % mod) {}
  constexpr mint& operator+=(const mint& a) {
    if ((x += a.x) >= mod) x -= mod;
    return *this;
  }
  constexpr mint& operator-=(const mint& a) {
    if ((x += mod - a.x) >= mod) x -= mod;
    return *this;
  }
  constexpr mint& operator*=(const mint& a) {
    (x *= a.x) %= mod;
    return *this;
  }
  constexpr mint& operator/=(const mint& a) { return *this = *this * a.inv(); }
  constexpr mint operator+(const mint& a) const {
    mint r(*this);
    return r += a;
  }
  constexpr mint operator-(const mint& a) const {
    mint r(*this);
    return r -= a;
  }
  constexpr mint operator*(const mint& a) const {
    mint r(*this);
    return r *= a;
  }
  constexpr mint operator/(const mint& a) const {
    mint r(*this);
    return r /= a;
  }
  constexpr mint pow(ll t) const {
    if (!t) return 1;
    mint a = pow(t >> 1);
    a *= a;
    if (t & 1) a *= *this;
    return a;
  }
  constexpr mint inv() const { return pow(mod - 2); }

  friend ostream& operator<<(ostream& os, const mint& m) {
    os << m.x;
    return os;
  }
};

int main() {
  ll n;
  cin >> n;
  mint eight = 1;
  mint nine = 1;
  mint ten = 1;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  }
  if (n == 2) {
    cout << 2 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    eight *= 8;
    nine *= 9;
    ten *= 10;
  }
  mint ans = ten + eight - nine * 2;
  cout << ans << endl;
  return 0;
}
