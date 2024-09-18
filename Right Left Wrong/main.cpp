#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T; cin >> T;

  for (int i = 0; i < T; i++) {
    int N; cin >> N;

    vector<ll> pref(N+1);
    for (int j = 1; j <= N; j++) {
      int x; cin >> x;
      pref[j] = pref[j-1] + x;
    }

    string rl; cin >> rl;

    int l = 0;
    int r = N-1;
    ll tot = 0;
    
    while (true) {
      while (l < N && rl[l] != 'L') l++;
      while (r >= 0 && rl[r] != 'R') r--;

      if (l > r) break;

      tot += pref[r+1] - pref[l];
      l++; r--;
    }

    cout << tot << endl;
  }

  return 0;
}