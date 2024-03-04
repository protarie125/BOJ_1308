#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll yy0, m0, d0;
ll yy1, m1, d1;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> yy0 >> m0 >> d0;
  cin >> yy1 >> m1 >> d1;

  const auto& dyy = yy1 - yy0;
  const auto& dm = m1 - m0;
  const auto& dd = d1 - d0;

  if (1000 < dyy || (1000 == dyy && 0 < dm) ||
      (1000 == dyy && 0 == dm && 0 <= dd)) {
    cout << "gg";
    return 0;
  }

  auto ans = 0LL;
  while (yy0 != yy1 || m0 != m1 || d0 != d1) {
    //cout << yy0 << ',' << m0 << ',' << d0 << '\n';

    if (2 == m0) {
      if (0 == yy0 % 400 || (0 != yy0 % 100 && 0 == yy0 % 4)) {
        if (d0 < 29) {
          ++d0;
          ++ans;
          continue;
        }
      } else {
        if (d0 < 28) {
          ++d0;
          ++ans;
          continue;
        }
      }

      d0 = 1;
      ++m0;
      ++ans;
      continue;
    } else if (4 == m0 || 6 == m0 || 9 == m0 || 11 == m0) {
      if (d0 < 30) {
        ++d0;
        ++ans;
        continue;
      }

      d0 = 1;
      ++m0;
      ++ans;
      continue;
    } else {
      if (d0 < 31) {
        ++d0;
        ++ans;
        continue;
      }

      d0 = 1;
      ++m0;
      if (13 == m0) {
        m0 = 1;
        ++yy0;
      }
      ++ans;
      continue;
    }
  }

  cout << "D-" << ans;

  return 0;
}