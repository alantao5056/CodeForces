#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    int N, M, Q; cin >> N >> M >> Q;

    vector<int> a(N);
    vector<int> b(M);
    for (int j = 0; j < N; j++) {
      cin >> a[j];
    }
    for (int j = 0; j < M; j++) {
      cin >> b[j];
    }
    
    sort(a.begin(), a.end(), std::greater<>());
    sort(b.begin(), b.end(), std::greater<>());

    vector<ll> as(N+1);
    for (int j = N-1; j >= 0; j--) {
      as[j] = as[j+1];
      as[j] += a[j];
    }

    vector<ll> bs(M+1);
    for (int j = M-1; j >= 0; j--) {
      bs[j] = bs[j+1];
      bs[j] += b[j];
    }

    vector<pair<ll, pii>> ps = {{0, {0, 0}}};
    int ai = 0;
    int bi = 0;
    ll cur = 0;
    while (ai < N || bi < M) {
      int ac = ai < N ? a[ai] : -1;
      int bc = bi < M ? b[bi] : -1;

      if (ac > bc) {
        cur += ac;
        ai++;
      } else {
        cur += bc;
        bi++;
      }
      ps.push_back(make_pair(cur, make_pair(ai, bi)));
    }

    for (int j = 0; j < Q; j++) {
      int x, y, z; cin >> x >> y >> z;
      int low = 0;
      int high = z;
      
      while (low < high) {
        int mid = low + (high - low + 1) / 2;
        if (ps[mid].second.first <= x && ps[mid].second.second <= y)
          low = mid;
        else
          high = mid - 1;
      }

      ll res = ps[low].first;
      int rem = z - low;
      if (ps[low].second.first < x) {
        res += as[ps[low].second.first] - as[ps[low].second.first + rem];
      } else {
        res += bs[ps[low].second.second] - bs[ps[low].second.second + rem];
      }

      cout << res << endl;
    }
  }

  return 0;
}