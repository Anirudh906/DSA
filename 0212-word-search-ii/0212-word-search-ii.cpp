class TrieNode {
   public: 
   vector<TrieNode*> child;
    bool isEnd;
    TrieNode(){
        child.resize(26, NULL);
        isEnd = false;
    }
};

class Trie {
    TrieNode *root;
    public:
    TrieNode* getRoot(){
        return root;
    }
    Trie(vector<string> &words){
        root = new TrieNode();
        for(int i = 0; i < words.size(); i++){
            addWord(words[i]);
        }
    }
    void addWord(string s){
        TrieNode *cur = root;
        for(int i =0; i < s.length(); i++){
            if(!cur -> child[s[i] - 'a']) cur -> child[s[i] - 'a'] = new TrieNode();
            cur = cur -> child[s[i] - 'a'];
        }
        cur -> isEnd = true;
    }
    
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie* t = new Trie(words);
        TrieNode *root = t -> getRoot();
        set<string> res;
        for(int i = 0; i < board.size(); i++){
            for(int j = 0; j < board[0].size(); j++){
                find(board, i, j, res, root, ""); 
            }
        }
        
        vector<string> ans;
        for(auto &w: res) ans.push_back(w);
        return ans;
    }
    
    void find(vector<vector<char>> &board, int i, int j, set<string> &res, TrieNode* root, string word){
        if(i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == ' ') return;
        
        if(root -> child[board[i][j] - 'a']){
            word += board[i][j];
            root = root -> child[board[i][j] - 'a'];
            if(root -> isEnd) res.insert(word);
            char c = board[i][j];
            board[i][j] = ' ';
            find(board, i + 1, j, res, root, word);
            find(board, i, j + 1, res, root, word);
            find(board, i - 1, j, res, root, word);
            find(board, i, j - 1, res, root, word);
            
            board[i][j] = c;
        }
    }
};