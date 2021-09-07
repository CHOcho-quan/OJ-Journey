class TrieNode {
public:
    TrieNode* child[26];
    TrieNode() {
        for (int i = 0; i < 26; ++i) child[i] = nullptr;
    }
};

class Trie {
public:
    Trie() { root_ = new TrieNode(); }
    
    void insert(const string& w) {
        auto tmp = root_;
        int cnt = 0;
        for (int i = 0; i < w.length(); ++i) {
            if (!tmp->child[w[i] - 'a'])
                tmp->child[w[i] - 'a'] = new TrieNode();
            else ++cnt;
            tmp = tmp->child[w[i] - 'a'];
        }
        if (!first_) re_ = min(cnt, re_);
        first_ = false;
    }
    
    int result() { return re_; }
    
private:
    TrieNode* root_;
    bool first_ = true;
    int re_ = 201;
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 1) return strs[0];
        Trie t;
        for (auto& str : strs) {
            t.insert(str);
        }
        return strs[0].substr(0, t.result());
    }
};
