#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pli = pair<ll, int>;

const int MOD = 1e9 + 7;

ll solve(int N, vector<int>& points, vector<int>& next) {
  vector<ll> minD(N, LLONG_MAX - 1e9);
  minD[0] = 0;
  priority_queue<pli, vector<pli>, greater<pli>> q;
  q.push({0, 0});

  while (!q.empty()) {
    pli cur = q.top(); q.pop();
    int i = cur.second;
    if (minD[i] < cur.first) continue;
    ll cost = minD[i] + points[i];
    if (cost < minD[next[i]]) {
      minD[next[i]] = cost;
      q.push({cost, next[i]});
    }
    if (i > 0 && minD[i] < minD[i-1]) {
      minD[i-1] = minD[i];
      q.push({minD[i], i-1});
    }
  }

  ll pref = 0;
  ll res = 0;
  for (int i = 0; i < N; i++) {
    pref += points[i];
    res = max(res, pref - minD[i]);
  }

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  while (T--) {
    int N; cin >> N;
    vector<int> points(N);
    vector<int> next(N);
    for (int i = 0; i < N; i++) {
      cin >> points[i];
    }
    for (int i = 0; i < N; i++) {
      cin >> next[i]; next[i]--;
    }
    cout << solve(N, points, next) << endl;
  }

  return 0;
}