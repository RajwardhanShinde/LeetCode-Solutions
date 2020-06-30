struct TrieNode {
    bool end;
    TrieNode *children[26];
    TrieNode() {
        end = false;
        memset(children, NULL, sizeof(children));
    }
};
class Trie {
    TrieNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    // Destructor
    ~Trie() {
        clear(root);
    }
    
    // Clear memory 
    void clear(TrieNode *root) {
        for(int i = 0; i < 26; i++) {
            if(root->children[i]) clear(root->children[i]);
        }
        delete root;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *dummy = root;
        for(char c: word) {
            if(!dummy->children[c - 'a'])
                dummy->children[c - 'a'] = new TrieNode();
            dummy = dummy->children[c - 'a'];
        }
        dummy->end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *dummy = root;
        for(char c: word) {
            if(!dummy->children[c - 'a'])
                return false;
            dummy = dummy->children[c - 'a'];
        }
        return dummy && dummy->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *dummy = root;
        for(char c: prefix) {
            if(!dummy->children[c - 'a'])
                return false;
            dummy = dummy->children[c - 'a'];
        }
        return dummy;
    }
};
