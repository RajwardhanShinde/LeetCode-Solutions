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
    TrieNode *root;
    Trie(vector<string>& dict) {
        root = new TrieNode();
        for(int i = 0; i < dict.size(); i++)
            addWord(dict[i]);
    }
    void addWord(const string& s) {
        TrieNode *dummy = root;
        for(int i = 0; i < s.length(); i++) {
            if(!dummy->children[s[i] - 'a'])
                dummy->children[s[i] - 'a'] = new TrieNode;
            dummy = dummy->children[s[i] - 'a'];
        }
        dummy->end = true;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        Trie *trie = new Trie(dict);
        TrieNode *root = trie->root;
        stringstream ss(sentence);
        string res, word;
        while(ss >> word) {
            res += search(root, word) + " ";
        }
        if(res != "") 
            res.pop_back();
        return res;
    }
    
    string search(TrieNode *root, string& word){
        TrieNode* t = root;
        for(int i=0;i<word.length();i++){
            if(t->end)  
                return word.substr(0,i);
            if(t->children[word[i]-'a'])   
                t=t->children[word[i]-'a'];
            else   
                return word;            
        }
        return word;
    }
};
