#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)

using namespace std;

typedef pair<int, int> p;
typedef long long ll;
const int MOD = 1000000007;
const int MAX = 1e6;

ll fact[MAX], fact_inv[MAX], inv[MAX];

void combInit(int SIZE) {
  // fact.resize(SIZE + 5);
  // fact_inv.resize(SIZE + 5);
  // inv.resize(SIZE + 5);
  fact[0] = fact[1] = 1;
  fact_inv[0] = fact_inv[1] = 1;
  inv[1] = 1;
  for (int i = 2; i < SIZE + 5; i++) {
    fact[i] = fact[i - 1] * i % MOD;
    inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
    fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
  }
}

ll comb(int n, int k) {
  // assert(!(n < k));
  // assert(!(n < 0 || k < 0));
  return fact[n] * (fact_inv[k] * fact_inv[n - k] % MOD) % MOD;
}

int main() {
  int x, y;
  cin >> x >> y;
  if ((x + y) % 3 != 0) {
    cout << 0 << endl;
    return 0;
  }
  int n = (2 * y - x) / 3;
  int m = (2 * x - y) / 3;
  // cout << n <<", "<< m << endl;
  combInit(n + m);
  ll ans = comb(n + m, n);
  cout << ans << endl;

  return 0;
}