#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const int MOD = 1e9 + 7;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, M, H; cin >> N >> M >> H;

    vector<bool> horse(N+1);
    for (int j = 0; j < H; j++) {
      int cur; cin >> cur;
      horse[cur] = true;
    }

    vector<vector<pii>> adj(N+1);
    for (int j = 0; j < M; j++) {
      int u, v, w; cin >> u >> v >> w;

      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
    }

    vector<ll> dist(N+1, LLONG_MAX);
    vector<ll> distH(N+1, LLONG_MAX);
    dist[1] = 0;
    priority_queue<pli> pq;
    
    if (horse[1]) {
      distH[1] = 0;
    }
    pq.push({0, 1});

    while (!pq.empty()) {
      pli cur = pq.top(); pq.pop();

      bool h = false;
      if (cur.second < 0) {
        cur.second *= -1;
        h = true;
      }

      if (horse[cur.second]) {
        h = true;
      }

      for (pii nb : adj[cur.second]) {
        if (h) {
          ll curD = cur.first + nb.second / 2;
          if (curD < distH[nb.first]) {
            distH[nb.first] = curD;
            pq.push({curD, 0-nb.first});
          }
        } else {
          ll curD = cur.first + nb.second;
          if (curD < dist[nb.first]) {
            dist[nb.first] = curD;
            pq.push({curD, nb.first});
          }
        }
      }
    }

    vector<ll> dist2(N+1, LLONG_MAX);
    vector<ll> dist2H(N+1, LLONG_MAX);
    dist2[N] = 0;
    priority_queue<pli> pq2;

    if (horse[N]) {
      dist2H[N] = 0;
    }
    pq2.push({0, N});

    while (!pq2.empty()) {
      pli cur = pq2.top(); pq2.pop();

      bool h = false;
      if (cur.second < 0) {
        cur.second *= -1;
        h = true;
      }

      if (horse[cur.second]) {
        h = true;
      }

      for (pli nb : adj[cur.second]) {
        if (h) {
          ll curD = cur.first + nb.second / 2;
          if (curD < dist2H[nb.first]) {
            dist2H[nb.first] = curD;
            pq2.push({curD, 0-nb.first});
          }
        } else {
          ll curD = cur.first + nb.second;
          if (curD < dist2[nb.first]) {
            dist2[nb.first] = curD;
            pq2.push({curD, nb.first});
          }
        }
      }
    }

    ll ans = LLONG_MAX;
    for (int j = 1; j <= N; j++) {
      ans = min(ans, max(min(dist[j], distH[j]), min(dist2[j], dist2H[j])));
    }

    if (ans == LLONG_MAX) {
      cout << -1 << endl;
    } else {
      cout << ans << endl;
    }
  }

  return 0;
}