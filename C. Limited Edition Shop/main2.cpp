#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int MOD = 1e9 + 7;

//! Currently set to SUM
struct SegmentTree {
  struct Node {
    ll val;
    ll add;
    ll set;
    bool hasSet;
    Node() : val(0), add(0), set(0), hasSet(false) {}
  };

  int n;
  vector<Node> tree;

  SegmentTree(int n) : n(n) {
    tree.resize(4 * n);
  }

  SegmentTree(const vector<ll>& arr) {
    n = arr.size();
    tree.resize(4 * n);
    build(arr, 1, 0, n - 1);
  }

  // operations

  // MAX
  // ll merge(ll a, ll b) { return max(a, b); }
  // ll neutral() { return ll_MIN; }

  // MIN
  // ll merge(ll a, ll b) { return min(a, b); }
  // ll neutral() { return ll_MAX; }

  // SUM
  ll merge(ll a, ll b) { return a + b; }
  ll neutral() { return 0; }

  // XOR
  // ll merge(ll a, ll b) { return a ^ b; }
  // ll neutral() { return 0; }

  void build(const vector<ll>& arr, ll v, int tl, int tr) {
    if (tl == tr) {
      tree[v].val = arr[tl];
      return;
    }
    ll tm = (tl + tr) / 2;
    build(arr, v * 2, tl, tm);
    build(arr, v * 2 + 1, tm + 1, tr);
    pull(v);
  }

  void pull(ll v) {
    tree[v].val = merge(tree[v * 2].val, tree[v * 2 + 1].val);
  }

  void push(ll v, int tl, int tr) {
    if (tl == tr) return;
    ll tm = (tl + tr) / 2;
    if (tree[v].hasSet) {
      applySet(v * 2, tree[v].set, tl, tm);
      applySet(v * 2 + 1, tree[v].set, tm + 1, tr);
      tree[v].hasSet = false;
    }
    if (tree[v].add != 0) {
      applyAdd(v * 2, tree[v].add, tl, tm);
      applyAdd(v * 2 + 1, tree[v].add, tm + 1, tr);
      tree[v].add = 0;
    }
  }

  // MAX and MIN
  // void applySet(ll v, ll val, ll tl = -1, ll tr = -1) {
  //   tree[v].val = val;
  //   tree[v].set = val;
  //   tree[v].add = 0;
  //   tree[v].hasSet = true;
  // }

  // void applyAdd(ll v, ll val, ll tl = -1, ll tr = -1) {
  //   if (tree[v].hasSet) {
  //     tree[v].set += val;
  //     tree[v].val += val;
  //   } else {
  //     tree[v].add += val;
  //     tree[v].val += val;
  //   }
  // }

  // SUM
  void applySet(ll v, ll val, int tl = -1, int tr = -1) {
    tree[v].val = (tr - tl + 1) * val;
    tree[v].set = val;
    tree[v].add = 0;
    tree[v].hasSet = true;
  }

  void applyAdd(ll v, ll val, int tl = -1, int tr = -1) {
    if (tree[v].hasSet) {
      tree[v].set += val;
      tree[v].val = (tr - tl + 1) * tree[v].set;
    } else {
      tree[v].add += val;
      tree[v].val += (tr - tl + 1) * val;
    }
  }

  // XOR
  // void applySet(ll v, ll val, ll tl = -1, ll tr = -1) {
  //   tree[v].val = ((tr - tl + 1) % 2) ? val : 0;
  //   tree[v].set = val;
  //   tree[v].add = 0;
  //   tree[v].hasSet = true;
  // }

  // void applyAdd(ll v, ll val, ll tl = -1, ll tr = -1) {
  //   if (tree[v].hasSet) {
  //     tree[v].set ^= val;
  //     if ((tr - tl + 1) % 2 == 1) tree[v].val ^= val;
  //   } else {
  //     tree[v].add ^= val;
  //     if ((tr - tl + 1) % 2 == 1) tree[v].val ^= val;
  //   }
  // }





  void updateSet(ll v, int tl, int tr, int l, int r, ll val) {
    if (l > r) return;
    if (l <= tl && tr <= r) {
      applySet(v, val, tl, tr);
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    updateSet(v * 2, tl, tm, l, min(r, tm), val);
    updateSet(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    pull(v);
  }

  void updateAdd(ll v, int tl, int tr, int l, int r, int val) {
    if (l > r) return;
    if (l <= tl && tr <= r) {
      applyAdd(v, val, tl, tr);
      return;
    }
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    updateAdd(v * 2, tl, tm, l, min(r, tm), val);
    updateAdd(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
    pull(v);
  }

  ll query(ll v, int tl, int tr, int l, int r) {
    if (l > r) return neutral();
    if (l <= tl && tr <= r) return tree[v].val;
    push(v, tl, tr);
    int tm = (tl + tr) / 2;
    ll left = query(v * 2, tl, tm, l, min(r, tm));
    ll right = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
    return merge(left, right);
  }

  // public methods
  void build(const vector<ll>& arr) {
    build(arr, 1, 0, n - 1);
  }

  void update(int l, int r, ll val) {
    updateSet(1, 0, n - 1, l, r, val);
  }

  void add(int l, int r, ll val) {
    updateAdd(1, 0, n - 1, l, r, val);
  }

  ll query(int l, int r) {
    return query(1, 0, n - 1, l, r);
  }
};

ll solve(vector<int>& vals, vector<int>& arr1, vector<int>& arr2, int N) {
  vector<int> p2(N+1);
  for (int i = 1; i <= N; i++) {
    p2[arr2[i]] = i;
  }
  
  SegmentTree st(N+2);

  for (int i = 1; i <= N; i++) {
    int np = p2[arr1[i]];
    if (vals[arr1[i]] <= 0) {
      st.add(0, 0, vals[arr1[i]]);
      st.add(np, np, -vals[arr1[i]]);
      continue;
    }

    ll lastTake = st.query(0, np-1) + vals[arr1[i]];

    // binary search
    int low = 0;
    int high = N;
    
    while (low < high) {
      int mid = low + (high - low + 1) / 2;
      if (st.query(0, mid) < lastTake)
        low = mid;
      else
        high = mid - 1;
    }

    ll prev = st.query(0, low);
    st.add(0, 0, vals[arr1[i]]);

    if (low+1 > np) {
      st.update(np, low, 0);
      ll after = st.query(0, low);
      st.add(low+1, low+1, -(after-prev));
    } else {
      st.add(np, np, -vals[arr1[i]]);
    }
  }

  return st.query(0, N);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  // freopen("1.in", "r", stdin);
  // freopen("1.out", "w", stdout);

  int T;
  cin >> T;

  while (T--) {
    int N; cin >> N;
    vector<int> vals(N+1);
    for (int i = 1; i <= N; i++) {
      cin >> vals[i];
    }
    vector<int> arr1(N+1);
    for (int i = 1; i <= N; i++) {
      cin >> arr1[i];
    }
    vector<int> arr2(N+1);
    for (int i = 1; i <= N; i++) {
      cin >> arr2[i];
    }

    cout << solve(vals, arr1, arr2, N) << endl;
  }

  return 0;
}