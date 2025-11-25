#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

class DSU {
  vector<int> par;
public:
  DSU(int N) {
    par.resize(N+1, -1);
  }

  int find(int x) {
    if (par[x] < 0) {
      return x;
    }

    return par[x] = find(par[x]);
  }

  void combine(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return;
    if (par[a] < par[b]) {
      // b combine to a
      par[a] += par[b];
      par[b] = a;
    } else {
      par[b] += par[a];
      par[a] = b;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    int N, M, K; cin >> N >> M >> K;
    
    DSU dsu(N);
    vector<vector<int>> edges;
    int minD = INT_MAX;
    for (int i = 0; i < M; i++) {
      int a, b, s; cin >> a >> b >> s; a--; b--;

      if (s <= K) {
        dsu.combine(a, b);
      } else {
        edges.push_back({s, a, b});
      }

      minD = min(minD, abs(K-s));
    }

    sort(edges.begin(), edges.end());

    ll res = 0;
    bool added = false;
    for (auto e : edges) {
      if (dsu.find(e[1]) != dsu.find(e[2])) {
        res += e[0] - K;
        added = true;
        dsu.combine(e[1], e[2]);
      }
    }

    if (added) {
      cout << res << endl;
    } else {
      cout << minD << endl;
    }
  }

  return 0;
}