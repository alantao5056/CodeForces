#include <bits/stdc++.h>

using namespace std;

int T;

int main() {
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N; cin >> N;

    vector<int> a(N);
    for (int j = 0; j < N; j++) {
      cin >> a[j];
    }

    vector<int> b(N);
    bool first = true;
    for (int j = 0; j < N; j++) {
      cin >> b[j];
      if (b[j] != a[j]) first = false;
    }

    if (first) {
      cout << "Bob" << endl;
      continue;
    }

    bool second = true;
    for (int j = N-1; j >= 0; j--) {
      if (b[j] != a[N-j-1]) {
        second = false;
      }
    }

    if (second) {
      cout << "Bob" << endl;
      continue;
    }
    cout << "Alice" << endl;
  }

  return 0;
}