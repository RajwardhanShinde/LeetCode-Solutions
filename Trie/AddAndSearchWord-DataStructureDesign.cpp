struct TrieNode {
    bool end;
    TrieNode* children[26];
    TrieNode() {
        end = false;
        memset(children, NULL, sizeof(children));
    }
};
class WordDictionary {
    TrieNode *root;
    bool search(const char* word, TrieNode *node) {
        for(int i = 0; word[i] && node; i++) {
            if(word[i] != '.')
                node = node->children[word[i] - 'a'];
            else {
                TrieNode *tmp = node;
                for(int j = 0; j < 26; j++) {
                    node = tmp->children[j];
                    if(search(word + i + 1, node))
                        return true;
                }
            }
        }
        return node && node->end;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TrieNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode *dummy = root;
        for(char c: word) {
            if(!dummy->children[c - 'a'])
                dummy->children[c - 'a'] = new TrieNode();
            dummy = dummy->children[c - 'a'];
        }
        dummy->end = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return search(word.c_str(), root);
    }
};
