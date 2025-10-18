#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 998244353;

vector<int> fact(200001);

ll powmod(ll a, ll b, ll p){
  a %= p;
  if (a == 0) return 0;
  ll product = 1;
  while(b > 0){
    if (b&1){    // you can also use b % 2 == 1
      product *= a;
      product %= p;
      --b;
    }
    a *= a;
    a %= p;
    b /= 2;    // you can also use b >> 1
  }
  return product;
}

ll inv(ll a, ll p){
  return powmod(a, p-2, p);
}

ll nCk(ll n, ll k, ll p) {
  // if (n == k) return 1;
  return ((fact[n] * inv(fact[k], p) % p) * inv(fact[n-k], p)) % p;
}

int solve(int N, vector<int>& arr) {
  ll res = 1;
  int start = (N+1)/2;
  int ava = N%2==1 ? 1 : 2;
  
  for (int i = N; i >= 1; i--) {
    if (i > (N+1)/2) {
      if (arr[i] > 0) {
        return 0;
      }
      continue;
    }

    if (arr[i] > 0) {
      if (ava != 0 && ava >= arr[i]) {
        res *= nCk(ava, arr[i], MOD);
        res %= MOD;
      } else {
        return 0;
      }
    }
    
    ava -= arr[i];
    ava += 2;
  }

  if (ava != 2) {
    return 0;
  }
  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  fact[0] = 1;
  for (int i = 1; i <= 200000; i++) {
    ll x = (ll)fact[i-1] * i;
    fact[i] = x%MOD;
  }

  int T;
  cin >> T;

  while (T--) {
    int N; cin >> N;

    vector<int> arr(N+1);
    for (int i = 1; i <= N; i++) {
      cin >> arr[i];
    }

    cout << solve(N, arr) << endl;
  }

  return 0;
}