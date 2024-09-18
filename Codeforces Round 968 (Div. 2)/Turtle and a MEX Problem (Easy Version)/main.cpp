#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

int T;

int mex(vector<int>& cur) {
  int i = -1;

  for (int j = 0; j < cur.size(); j++) {
    if (cur[j] != i) {
      if (cur[j] != ++i) {
        return i;
      }
    }
  }
  return i+1;
}

pii mex2(vector<int>& cur) {
  int i = -1;
  int missing = -1;

  bool flag = false;
  for (int j = 0; j < cur.size(); j++) {
    if (cur[j] != i) {
      if (cur[j] != ++i) {
        if (flag) {
          return {missing, i};
        }
        flag = true;
        missing = i;
        j--;
      }
    }
  }
  return {missing, i+1};
}

struct comp
{
    inline bool operator() (const pii& a, const pii& b) {
      if (a.first != b.first) {
        return a.first < b.first;
      }

      return a.second > b.second;
    }
};

int main() {
  freopen("1.in", "r", stdin);
  freopen("1.out", "w", stdout);

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, M; cin >> N >> M;

    int maxMex = 0;
    vector<pii> mexes(N);
    for (int j = 0; j < N; j++) {
      int L; cin >> L;
      vector<int> cur(L);

      for (int k = 0; k < L; k++) {
        cin >> cur[k];
      }

      sort(cur.begin(), cur.end());

      maxMex = max(maxMex, mex(cur));
      mexes[j] = mex2(cur);
    }

    sort(mexes.begin(), mexes.end(), comp());

    ll pred = ((ll) maxMex) * (min(M, maxMex)+1);
    if (M > maxMex) {
      pred += (ll) (maxMex + 1 + M) * (M-maxMex) / 2;
    }

    set<int> done;
    for (pii m : mexes) {
      if (m.first == -1 || m.second < maxMex || done.find(m.first) != done.end()) continue;

      pred += m.second - max(maxMex, m.first);
      done.insert(m.first);
    }

    cout << pred << endl;
  }

  return 0;
}