#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;


int N, M;
vector<ll> boys;
vector<ll> girls;

ll solve() {
  if (boys.front() > girls.back()) { return -1; }

  ll count = 0;

  // do number 1
  for (int i = 0; i < M - 1; i++) {
    count += girls[i];
  }

  bool lastFinish = girls.back() == boys.front();
  count += boys.front();

  // do the rest
  for (int i = 1; i < N; i++) {
    count += boys[i] * M;
  }

  if (!lastFinish) {
    count -= boys[1];
    count += girls.back();
  }

  return count;
}

int main() {
  cin >> N >> M;
  ll temp;
  for (int i = 0; i < N; i++) {
    cin >> temp;
    boys.push_back(temp);
  }

  for (int i = 0; i < M; i++) {
    cin >> temp;
    girls.push_back(temp);
  }

  sort(boys.rbegin(), boys.rend());
  sort(girls.rbegin(), girls.rend());

  cout << solve() << endl;

  return 0;
}