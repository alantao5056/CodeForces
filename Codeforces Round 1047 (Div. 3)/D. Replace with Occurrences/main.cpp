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
  
  while (T--) {
    int N; cin >> N;

    map<int, vector<int>> pos;
    for (int i = 0; i < N; i++) {
      int x; cin >> x;
      pos[x].push_back(i);
    }

    bool flag = false;
    vector<int> res(N);
    int id = 1;
    for (const auto& p : pos) {
      int x = p.first;
      vector<int> poses = p.second;
      if (poses.size() % x != 0) {
        flag = true;
        break;
      }

      int cur = 0;
      while (cur < poses.size()) {
        for (int i = 0; i < x; i++) {
          res[poses[cur+i]] = id;          
        }
        cur+=x;
        id++;
      }
    }

    if (flag) {
      cout << -1 << endl;
      continue;
    }

    for (int i = 0; i < N-1; i++) {
      cout << res[i] << " ";
    }
    cout << res[N-1] << endl;
  }


  return 0;
}