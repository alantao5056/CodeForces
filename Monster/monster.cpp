// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>

using namespace std;

int N;

int main() {
  cin >> N;

  vector <int> arr(N + 1);
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  vector <int> prefix1(N + 1);
  int count = N - 1;
  for (int i = 1; i <= N; i++) {
    prefix1[i] = max(prefix1[i - 1], arr[i] + count);
    count--;
  }

  vector <int> prefix2(N + 2);
  count = N - 1;
  for (int i = N; i >= 1; i--) {
    prefix2[i] = max(prefix2[i + 1], arr[i] + count);
    count--;
  }

  int total = INT_MAX;
  for (int i = 1; i <= N; i++) {
    total = min(total, max(arr[i], max(prefix1[i - 1], prefix2[i + 1])));
  }

  cout << total << endl;

  return 0;
}