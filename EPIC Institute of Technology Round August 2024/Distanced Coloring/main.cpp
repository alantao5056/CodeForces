#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N, M, K; cin >> N >> M >> K;

    if (K < M && K < N) {
      cout << (K*K) << endl;
      continue;
    }

    if (K >= M && K >= N) {
      cout << (M*N) << endl;
      continue;
    }

    if (K < M) {
      cout << (K*N) << endl;
      continue;
    }

    cout << (K*M) << endl;
  }

  return 0;
}