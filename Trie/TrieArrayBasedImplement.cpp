// trie_template.cpp — Compact Trie template (alphabet: lowercase 'a'..'z')
// - contiguous storage (vector<Node>) to avoid MLE due to allocator overhead
// - minimal per-node footprint: int next[26], int subtreeCount
// - useful methods: insert, insertReversed, sumPrefixSubtreeCounts, countPrefix

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

struct TrieNode {
    int next[26];     // child indices (-1 if none)
    int subtreeCount; // number of inserted strings that pass through this node (i.e. have this prefix)
    TrieNode() {
        subtreeCount = 0;
        for (int i = 0; i < 26; ++i) next[i] = -1;
    }
};

class Trie {
public:
    // Create an empty trie. Optionally reserve 'reserveNodes' nodes to avoid reallocation.
    Trie(size_t reserveNodes = 0) {
        nodes.reserve(reserveNodes ? reserveNodes : 1);
        nodes.emplace_back(); // root at index 0
    }

    // Reserve capacity for nodes (call before many inserts to avoid reallocation)
    void reserve(size_t reserveNodes) {
        nodes.reserve(reserveNodes);
    }

    // Clear the trie (reset to a single root node)
    void clear() {
        nodes.clear();
        nodes.emplace_back();
    }

    // Insert a string. If 'reversed' is true, characters are inserted from back->front.
    // For each visited node (after stepping to the child), subtreeCount++.
    void insert(const string &s, bool reversed = false) {
        int cur = 0;
        if (!reversed) {
            for (char ch : s) {
                int c = ch - 'a';
                if (nodes[cur].next[c] == -1) {
                    nodes[cur].next[c] = (int)nodes.size();
                    nodes.emplace_back();
                }
                cur = nodes[cur].next[c];
                nodes[cur].subtreeCount += 1;
            }
        } else {
            for (int i = (int)s.size() - 1; i >= 0; --i) {
                int c = s[i] - 'a';
                if (nodes[cur].next[c] == -1) {
                    nodes[cur].next[c] = (int)nodes.size();
                    nodes.emplace_back();
                }
                cur = nodes[cur].next[c];
                nodes[cur].subtreeCount += 1;
            }
        }
    }

    // Walk the trie along characters of s (left->right).
    // At each successful step (child exists) add subtreeCount of that child to the sum.
    // Stops when a needed child doesn't exist.
    //
    // This returns sum_{k=1..|s_prefixes|} subtreeCount(node_for_prefix_k)
    // (useful when computing LCP sum against trie of reversed strings).
    long long sumPrefixSubtreeCounts(const string &s) const {
        int cur = 0;
        long long sum = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (nodes[cur].next[c] == -1) break;
            cur = nodes[cur].next[c];
            sum += nodes[cur].subtreeCount;
        }
        return sum;
    }

    // Return how many inserted strings have 's' as a prefix.
    // (i.e., subtreeCount at node representing 's', or 0 if path missing)
    int countStringsWithPrefix(const string &s) const {
        int cur = 0;
        for (char ch : s) {
            int c = ch - 'a';
            if (nodes[cur].next[c] == -1) return 0;
            cur = nodes[cur].next[c];
        }
        return nodes[cur].subtreeCount;
    }

    // number of nodes currently allocated in trie
    size_t nodeCount() const { return nodes.size(); }

private:
    vector<TrieNode> nodes;
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // -----------------------
    // Example usage (comment/uncomment as needed)
    // -----------------------
    /*
     Demo:
     Insert reversed strings: "aba"->"aba", "ab"->"ba", "ba"->"ab"
    vector<string> sample = {"aba", "ab", "ba"};
    Trie trie;
    trie.reserve(10);  optional hint

     Insert reversed versions (so trie holds s' = reverse(s))
    for (auto &str : sample) trie.insert(str, reversed= true);
    /*
    For each original s compute sumPrefixSubtreeCounts(s)
    // (this replicates the LCP-sum step used in the collapse problem)
    long long totalOverlap = 0;
    for (auto &str : sample) {
        long long contrib = trie.sumPrefixSubtreeCounts(str);
        cout << "sumPrefixSubtreeCounts(\"" << str << "\") = " << contrib << "\n";
        totalOverlap += contrib;
    }
    cout << "Total overlap = " << totalOverlap << "\n";
    */

    return 0;
}
