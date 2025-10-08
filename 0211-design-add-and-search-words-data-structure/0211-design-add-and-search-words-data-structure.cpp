class Node {
public:
    vector<Node*> children;
    bool is_leaf_node;
    Node() {
        children = vector<Node*>(26, NULL);
        is_leaf_node = false;
    }
};
class WordDictionary {
    Node* root;

public:
    WordDictionary() : root(new Node()) {}
    void addWord(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); ++i) {
            char ch = word[i];
            if (!node->children[ch - 'a'])
                node->children[ch - 'a'] = new Node();
            node = node->children[ch - 'a'];
        }
        node->is_leaf_node = true;
    }
    bool search_helper(string& s, int i, Node* node) {
        if (!node)
            return s.length() == i;
        if (i >= s.length())
            return node->is_leaf_node;
        if (s[i] == '.') {
            for (int j = 0; j < 26; j++) {
                if (node->children[j] && search_helper(s, i + 1, node->children[j])) 
                    return true;
            }
            return false;
        }
        if (!node->children[s[i] - 'a'])
            return false;
        return search_helper(s, i + 1, node->children[s[i] - 'a']);
    }
    bool search(string word) { return search_helper(word, 0, root); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */