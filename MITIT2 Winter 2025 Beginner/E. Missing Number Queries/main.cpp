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

  int N, Q; cin >> N >> Q;

  vector<int> arr(N);
  vector<int> freq(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i]; arr[i]--;
    freq[arr[i]]++;
  }

  set<int> ava;
  for (int i = 0; i < N; i++) {
    if (freq[i] == 0) ava.insert(i);
  }

  for (int i = 0; i < Q; i++) {
    int f, a, b; cin >> f >> a >> b; a--; b--;

    if (f == 1) {
      freq[arr[a]]--;
      if (freq[arr[a]] == 0) {
        ava.insert(arr[a]);
      }
      freq[b]++;
      if (freq[b] == 1) {
        ava.erase(b);
      }
      arr[a] = b;
    } else {
      if (ava.size() == 0) {
        cout << (arr[(b+1)%N]+1) << endl;
      } else {
        cout << ((*ava.begin())+1) << endl;
      }
    }
  }

  return 0;
}