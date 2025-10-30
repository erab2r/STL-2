#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<ll,ll>> fnd(vector<pair<ll,ll>>& hii) {
    vector<pair<ll,ll>> src;
    if (hii.empty()) 
        return src;
    sort(hii.begin(), hii.end());
    ll L = hii[0].first, R = hii[0].second;
    for (size_t i = 1; i<hii.size(); i++) {
        if (hii[i].first <= R + 1) {
            R = max(R, hii[i].second);
        } else {
            src.emplace_back(L,R);
            L = hii[i].first;
            R = hii[i].second;
        }
    }
    src.emplace_back(L,R);
    return src;
}
bool valuable(ll m, const vector<ll>& a, ll x, ll k) {

    if (m == 0) {
        return (x + 1) >= k;
    }
    ll r = m - 1;
    vector<pair<ll,ll>> segs;
    for (ll ai : a) {
        ll L = max(0LL, ai - r);
        ll R = min(x, ai + r); 
        if (L <= R) segs.emplace_back(L, R);
    }
    if (segs.empty()) return (x + 1) >= k;
    auto merged = fnd(segs);
    ll forbidden = 0;
    for (auto &p : merged) {
        forbidden += (p.second - p.first + 1);
        if (forbidden > x + 1) { forbidden = x + 1; break; }
    }
    ll allowed = (x + 1) - forbidden;
    return allowed >= k;
}

vector<ll> construct_positions(ll m, const vector<ll>& a, ll x, ll k) {
    vector<ll> ans;
    if (k == 0) return ans;
    unordered_set<ll> used; used.reserve((size_t)k*2);
    if (m == 0) {
        for (ll p = 0; p <= x && (ll)ans.size() < k; ++p) {
            ans.push_back(p);
            used.insert(p);
        }
        return ans;
    }
    ll r = m - 1;
    vector<pair<ll,ll>> segs;
    for (ll ai : a) {
        ll L = max(0LL, ai - r);
        ll R = min(x, ai + r);
        if (L <= R) segs.emplace_back(L, R);
    }
    auto merged = fnd(segs);
    ll pos = 0;
    for (auto &iv : merged) {
        if (pos <= iv.first - 1) {
            ll start = pos;
            ll end = iv.first - 1;
            for (ll p = start; p <= end && (ll)ans.size() < k; ++p) {
                ans.push_back(p);
                used.insert(p);
            }
        }
        pos = iv.second + 1;
        if ((ll)ans.size() >= k) break;
    }
    for (ll p = pos; p <= x && (ll)ans.size() < k; ++p) {
        if (used.find(p) == used.end()) {
            ans.push_back(p);
            used.insert(p);
        }
    }
    if ((ll)ans.size() < k) {
        for (ll p = 0; p <= x && (ll)ans.size() < k; ++p) {
            if (used.find(p) == used.end()) {
                ans.push_back(p);
                used.insert(p);
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int test_case;
    if (!(cin >> test_case)) return 0;
    while (test_case--) {
        ll n, k, x;
        cin >> n >> k >> x;
        vector<ll> a(n);
        for (int i = 0; i < (int)n; ++i) cin >> a[i];
        ll lo = 0, hi = x;
        while (lo < hi) {
            ll mid = lo + (hi - lo + 1) / 2;
            if (valuable(mid, a, x, k)) lo = mid;
            else hi = mid - 1;
        }
        ll best = lo;
        auto ans = construct_positions(best, a, x, k);
        for (int i = 0; i < (int)k; ++i) {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << '\n';
    }
    return 0;
}
