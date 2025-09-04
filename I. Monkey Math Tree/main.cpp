#include <bits/stdc++.h>
#include <numeric>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

long long mpow(long long a, long long b) {
  a %= MOD;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = res * a % MOD;
    a = a * a % MOD;
    b >>= 1;
  }
  return res;
}

int gcd(int a, int b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

int N = 1000002;

pii mult(pii a, pii b) {
  ll one = a.first * b.first;
  ll two = a.second * b.second;
  return make_pair(one%MOD, two%MOD);
}

pii add(pii a, pii b) {
  // second must be the same;
  return {(a.first + b.first)%MOD, a.second};
}

int getFractionModulo(pii p)
{
    int a = p.first; int b = p.second;
    int c = gcd(a, b);

    a = a / c;
    b = b / c;

    // (b ^ m-2) % m
    int d = mpow(b, MOD - 2);

    // Final answer
    int ans = ((ll)(a % MOD) * (d % MOD)) % MOD;

    return ans;
}

int main() {
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  // 0: yes, 1: no
  vector<vector<pii>> dp(N, vector<pii>(2, {1, 1}));

  for (int i = 3; i < N; i++) {
    pii a = dp[i-1][0];
    pii b = dp[i-1][1];
    // no
    dp[i][1] = add(mult(a, {1, i-1}), mult(b, {i-2, i-1}));
    // yes
    b.first += b.second;
    dp[i][0] = add(mult(a, {1, i-1}), mult(b, {i-2, i-1})); 
  }


  int T;
  cin >> T;
  while (T--) {
    int n; cin >> n;
    cout << getFractionModulo(dp[n+1][1]) << endl;
  }

  return 0;
}