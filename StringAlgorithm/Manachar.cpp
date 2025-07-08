#include <bits/stdc++.h>
using namespace std;

class Manacher {
public:
    // d1[i] = max radius of odd palindrome centered at i
    // d2[i] = max radius of even palindrome centered between i-1 and i
    vector<int> d1, d2;

    void process(const string& s) {
        int n = s.size();
        d1.assign(n, 0);
        d2.assign(n, 0);
        int l = 0, r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r ? 1 : min(d1[l+r-i], r - i + 1));
            while (0 <= i - k && i + k < n && s[i-k] == s[i+k]) k++;
            d1[i] = k--;
            if (i + k > r) { l = i - k; r = i + k; }
        }
        // even‐length
        l = 0; r = -1;
        for (int i = 0; i < n; i++) {
            int k = (i > r ? 0 : min(d2[l+r-i+1], r - i + 1));
            while (0 <= i - k - 1 && i + k < n && s[i-k-1] == s[i+k]) k++;
            d2[i] = k--;
            if (i + k > r) { l = i - k - 1; r = i + k; }
        }
    }

    // Returns true if s[l..r] is a palindrome
    bool is_palindrome(int l, int r) const {
        int len = r - l + 1;
        if (len <= 1) return true;
        if (len % 2 == 1) {
            int center = (l + r) / 2;
            // need radius ≥ (len+1)/2 to cover [l..r]
            return d1[center] >= (len + 1) / 2;
        } else {
            int center = l + len/2;
            // need radius ≥ len/2
            return d2[center] >= len/2;
        }
    }
     string longest_palindrome(const string& s) {
        process(s);
        int n = s.size();
        int best_len = 0, best_center = 0;
        bool is_odd = true;

        // check odd centers
        for (int i = 0; i < n; i++) {
            int len = 2*d1[i] - 1;
            if (len > best_len) {
                best_len = len;
                best_center = i;
                is_odd = true;
            }
        }
        // check even centers
        for (int i = 0; i < n; i++) {
            int len = 2*d2[i];
            if (len > best_len) {
                best_len = len;
                best_center = i;
                is_odd = false;
            }
        }

        if (is_odd) {
            int r = d1[best_center] - 1;
            return s.substr(best_center - r, best_len);
        } else {
            int r = d2[best_center];
            return s.substr(best_center - r, best_len);
        }
    }
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    Manacher M;
    M.process(s);

    // Output radii (for demonstration)
    cout << "Odd radii: ";
    for (int x : M.d1) cout << x << ' ';
    cout << "\nEven radii: ";
    for (int x : M.d2) cout << x << ' ';
    cout << "\n";

    // Example: print the longest palindromic substring
    cout << "Longest palindrome: "
         << M.longest_palindrome(s) << "\n";

    return 0;
}