#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

int N, M, S, F;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> N >> M;

  vector<vector<pii>> adj(N);
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c; a--; b--;

    adj[a].push_back({c, b});
    adj[b].push_back({c, a});
  }

  cin >> S >> F; S--; F--;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  vector<int> mind(N, INT_MAX);
  mind[S] = 0;
  pq.push({0, S});

  while (!pq.empty()) {
    pii cur = pq.top(); pq.pop();

    for (pii nb : adj[cur.second]) {
      int newd = nb.first + mind[cur.second];
      if (newd < mind[nb.second]) {
        mind[nb.second] = newd;
        pq.push({newd, nb.second});
      }
    }
  }

  cout << (mind[F] == INT_MAX ? -1 : mind[F]) << endl;

  return 0;
}