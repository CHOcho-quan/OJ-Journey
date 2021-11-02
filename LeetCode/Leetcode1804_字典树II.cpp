class TrieNode {
public:
    TrieNode() : next(26, nullptr), cur(0), vols(0) {}
    
    vector<TrieNode*> next;
    int cur;
    int vols;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        auto tmp = root;
        for (int i = 0; i < word.length(); ++i) {
            if (tmp->next[word[i] - 'a']) {
                tmp = tmp->next[word[i] - 'a'];
                ++tmp->cur;
            } else {
                tmp->next[word[i] - 'a'] = new TrieNode();
                tmp = tmp->next[word[i] - 'a'];
                ++tmp->cur;
            }
            if (i == word.length() - 1) {
                ++tmp->vols;
            }
        }
    }
    
    int countWordsEqualTo(string word) {
        auto tmp = root;
        int res = 0;
        for (int i = 0; i < word.length(); ++i) {
            if (tmp->next[word[i] - 'a']) {
                tmp = tmp->next[word[i] - 'a'];
            } else {
                return 0;
            }
            if (i == word.length() - 1 && tmp->vols) res = tmp->vols;
        }
        return res;
    }
    
    int countWordsStartingWith(string prefix) {
        auto tmp = root;
        int res = 0;
        for (int i = 0; i < prefix.length(); ++i) {
            if (tmp->next[prefix[i] - 'a']) {
                tmp = tmp->next[prefix[i] - 'a'];
            } else {
                return 0;
            }
            if (i == prefix.length() - 1 && tmp) res = tmp->cur;
        }
        
        return res;
    }
    
    void erase(string word) {
        auto tmp = root;
        TrieNode* now = nullptr;
        for (int i = 0; i < word.length(); ++i) {
            if (tmp->next[word[i] - 'a']) {
                tmp = tmp->next[word[i] - 'a'];
                now = nullptr;
                if (i == word.length() - 1) --tmp->vols;
                if (--tmp->cur) continue;
                now = tmp;
            }
        }
    }
    
private:
    TrieNode* root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * int param_2 = obj->countWordsEqualTo(word);
 * int param_3 = obj->countWordsStartingWith(prefix);
 * obj->erase(word);
 */
