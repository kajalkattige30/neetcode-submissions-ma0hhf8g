class PrefixTree {
public:
    struct trieNode {
        bool isEndOfWord;
        trieNode *children[26];
    };

    trieNode* root;

    trieNode* getNode() {
        trieNode* newNode = new trieNode();

        newNode->isEndOfWord = false;

        for(int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    PrefixTree() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawler = root;
        for(char ch: word) {
            int idx = ch - 'a';
            if(crawler->children[idx] == NULL) {
                crawler->children[idx] = getNode();
            }
            crawler = crawler->children[idx];
        }
        crawler->isEndOfWord = true;
    }
    
    bool search(string word) {
        trieNode* crawler = root;
        for(char ch: word) {
            int idx = ch - 'a';
            if(crawler->children[idx] == NULL) {
                return false;
            }
            crawler = crawler->children[idx];
        }
        if(crawler != NULL && crawler->isEndOfWord == true) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawler = root;
        int i = 0;
        for(i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            int idx = ch - 'a';

            if(crawler->children[idx] == NULL) {
                return false;
            }
            crawler = crawler->children[idx];
        }

        if(i == prefix.length()) {
            return true;
        }
        return false;
    }
};
