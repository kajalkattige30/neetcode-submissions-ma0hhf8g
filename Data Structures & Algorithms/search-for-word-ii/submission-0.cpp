class Solution {
public:
    struct TrieNode {
        string word;
        bool endOfWord;
        TrieNode* children[26];
    };

    TrieNode* getNode() {
        TrieNode* newNode = new TrieNode();

        newNode->endOfWord = false;
        newNode->word = "";
        for(int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void insert(TrieNode* root, string &word) {
        TrieNode* crawler = root;

        for(char &ch: word) {
            if(crawler->children[ch-'a'] == NULL) {
                crawler->children[ch-'a'] = getNode();
            }
            crawler = crawler->children[ch-'a'];
        }

        crawler->endOfWord = true;
        crawler->word = word;
    }

    void findWordsinTrie(vector<vector<char>>& board, int i, int j, int m, int n, TrieNode* root, vector<string> &result) {
        if(i < 0 || i >= m || j < 0 || j >= n) {
            return;
        }

        if(board[i][j] == (char)36 || root->children[board[i][j]-'a'] == NULL) {
            return;
        }

        root = root->children[board[i][j]-'a'];

        if(root->endOfWord == true) {
            result.push_back(root->word);
            root->endOfWord = false;
        }

        char temp = board[i][j];
        board[i][j] = (char)36;
        findWordsinTrie(board, i, j-1, m, n, root, result);
        findWordsinTrie(board, i, j+1, m, n, root, result);
        findWordsinTrie(board, i-1, j, m, n, root, result);
        findWordsinTrie(board, i+1, j, m, n, root, result);

        board[i][j] = temp;
    }


    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int m = board.size();
        int n = board[0].size();
        vector<string> result;

        TrieNode* root = getNode();

        for(string &word: words) {
            insert(root, word);
        }

        for(int i = 0; i<m; i++) {
            for(int j = 0; j <n; j++) {
                char ch = board[i][j];

                if(root->children[ch-'a'] != NULL) {
                    findWordsinTrie(board, i, j, m, n, root, result);
                }
            }
        }

        return result;
    }
};
