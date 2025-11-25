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

  int Q; cin >> Q;

  set<pii> place; // id, money
  set<pii> money; // [money, id]

  int id = 1;
  while (Q--) {
    int x; cin >> x;
    if (x == 1) {
      int m; cin >> m;
      money.insert({-m, id});
      place.insert({id, -m});

      id++;
    } else if (x == 2) {
      // place
      pii target = *place.begin();
      cout << target.first << " ";
      
      money.erase(make_pair(target.second, target.first));
      place.erase(place.begin());
    } else {
      // money
      pii target = *money.begin();
      cout << target.second << " ";

      place.erase(make_pair(target.second, target.first));
      money.erase(money.begin());
    }
  }

  return 0;
}