/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(Node* root) {
        if (!root) return "";
        return serialize_helper(root);
    }

    string serialize_helper(Node* root) {
        string res = "";
        res += to_string(root->val);
        if (root->children.size() != 0) {
            res += "[";
            for (int i = 0; i < root->children.size(); ++i) {
                auto child = root->children[i];
                if (i == root->children.size() - 1) res += serialize_helper(child);
                else res += serialize_helper(child) + " ";
            }
            res += "]";
        }
        return res;
    }

    Node* deserialize_helper(string data) {
        int i = 0;
        stack<Node*> st;
        Node* res = nullptr;
        while (i < data.length()) {
            string cur = "";
            while (i < data.length() && data[i] >= '0' && data[i] <= '9') {
                cur += data[i++];
            }
            // cout << cur << '\n';
            auto node = new Node(stoi(cur));
            if (st.empty()) {
                st.push(node);
                res = node;
                ++i;
                continue;
            } else {
                if (data[i] == ' ') {
                    st.top()->children.push_back(node);
                } else if (data[i] == '[') {
                    st.top()->children.push_back(node);
                    st.push(node);
                } else if (data[i] == ']') {
                    st.top()->children.push_back(node);
                    if (!st.empty()) st.pop();
                }
                ++i;
                while (i < data.length() && data[i] < '0' || data[i] > '9') {
                    if (data[i] == ']' && !st.empty()) st.pop();
                    ++i;
                }
            }
        }

        return res;
    }

    // Decodes your encoded data to tree.
    Node* deserialize(string data) {
        if (data == "") return nullptr;
        // cout << data << '\n';
        
        return deserialize_helper(data);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));