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
    int M, N, a, b; cin >> M >> N >> a >> b;

    vector<int> fires(N);
    for (int i = 0; i < N; i++) {
      cin >> fires[i];
    }

    sort(fires.begin(), fires.end());

    int totTime;
    if (a < b) {
      totTime = b-1;
    } else {
      totTime = N-b;
    }

    int maxFires = abs(b-a)-1;

    
  }

  return 0;
}