using PII = pair<int, int>;

class LinkNode {
public:
    LinkNode(PII kv) : k_v(kv), prev(nullptr), next(nullptr) {}
    LinkNode(PII kv, LinkNode* pr) : k_v(kv), prev(pr), next(nullptr) {}
    
    LinkNode* prev;
    LinkNode* next;
    PII k_v;
};

class LRUCache {
public:
    LRUCache(int capacity) : cap_(capacity), first(nullptr), last(nullptr) {
        
    }
    
    int get(int key) {
        if (!rem_.count(key)) return -1;
        else {
            auto cur = rem_[key];
            if (cur != last) {
                if (cur->prev) {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    last->next = cur;
                    cur->prev = last;
                    last = cur;
                } else {
                    first = cur->next;
                    cur->next->prev = cur->prev;
                    cur->next = nullptr;
                    last->next = cur;
                    cur->prev = last;
                    last = cur;
                }
            }
            return cur->k_v.second;
        }
    }
    
    void put(int key, int value) {
        if (rem_.count(key)) {
            auto cur = rem_[key];
            if (cur != last) {
                if (cur->prev) {
                    cur->prev->next = cur->next;
                    cur->next->prev = cur->prev;
                    last->next = cur;
                    cur->prev = last;
                    cur->next = nullptr;
                    last = cur;
                } else {
                    first = cur->next;
                    first->prev = nullptr;
                    last->next = cur;
                    cur->prev = last;
                    cur->next = nullptr;
                    last = cur;
                }
            }
            rem_[key]->k_v = {key, value};
        } else {
            if (rem_.size() == 0) {
                rem_[key] = new LinkNode({key, value});
                first = rem_[key];
                last = rem_[key];
            } else if (rem_.size() < cap_) {
                rem_[key] = new LinkNode({key, value}, last);
                last->next = rem_[key];
                last = rem_[key];
            } else {
                rem_[key] = new LinkNode({key, value}, last);
                last->next = rem_[key];
                last = rem_[key];
                first = first->next;
                auto tmp = first->prev;
                // cout << tmp->k_v.first << '\n';
                rem_.erase(tmp->k_v.first);
                first->prev = nullptr;
                delete tmp;
            }
        }
    }
    
private:
    LinkNode* first, *last;
    map<int, LinkNode*> rem_;
    int cap_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
