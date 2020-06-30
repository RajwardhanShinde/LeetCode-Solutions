struct TrieNode {
    bool end;
    TrieNode *children[26];
    TrieNode() {
        end = false;
        memset(children, NULL, sizeof(children));
    }
};

class Trie {
public: 
    TrieNode* root;
    Trie(vector<string>& words) {
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++) 
            addWord(words[i]);
    }
    void addWord(const string& s) {
        TrieNode *dummy = root;
        for(char c: s) {
            if(!dummy->children[c - 'a'])
                dummy->children[c - 'a'] = new TrieNode();
            dummy = dummy->children[c - 'a'];
        }
        dummy->end = true;
    }
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* trie = new Trie(words);
        set<string> s;
        TrieNode *root = trie->root;
        for(int x = 0; x < board.size(); x++) {
            for(int y = 0; y < board[0].size(); y++) {
                findWords(board, x, y, root, "", s);
            }
        }
        vector<string> res;
        for(auto it: s) res.push_back(it);
        return res;
    }
    
    void findWords(vector<vector<char>>& board, int x, int y, TrieNode *root, string word, set<string>& s) {
        if(x < 0 || x >= board.size() || y < 0 || y >= board[0].size() || board[x][y] == ' ') return;
        if(root->children[board[x][y] - 'a']) {
            word += board[x][y];
            root = root->children[board[x][y] - 'a'];
            if(root->end) s.insert(word);
            char c = board[x][y];
            board[x][y] = ' ';
            findWords(board, x+1, y, root, word, s);
            findWords(board, x-1, y, root, word, s);
            findWords(board, x, y+1, root, word, s);
            findWords(board, x, y-1, root, word, s);
            board[x][y] = c;
        }
    }
};
