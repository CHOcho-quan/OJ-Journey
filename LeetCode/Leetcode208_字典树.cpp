class TrieNode {
public:
    TrieNode* childs_[26];
    bool val_ = false;
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            childs_[i] = nullptr;
        }
    }
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root_ = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto tmp = root_;
        for (int i = 0; i < word.length(); ++i) {
            if (tmp->childs_[word[i] - 'a'] == nullptr)
                tmp->childs_[word[i] - 'a'] = new TrieNode();
            tmp = tmp->childs_[word[i] - 'a'];
        }
        tmp->val_ = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto tmp = root_;
        for (int i = 0; i < word.length(); ++i) {
            if (tmp->childs_[word[i] - 'a']) tmp = tmp->childs_[word[i] - 'a'];
            else return false;
        }
        return tmp->val_;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto tmp = root_;
        for (int i = 0; i < prefix.length(); ++i) {
            if (tmp->childs_[prefix[i] - 'a']) tmp = tmp->childs_[prefix[i] - 'a'];
            else return false;
        }
        return true;
    }
    
private:
    TrieNode* root_;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
