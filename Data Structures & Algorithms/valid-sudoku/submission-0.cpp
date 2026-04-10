class Solution {
public:
    void traversal(vector<vector<char>>& board, int sr, int er, int sc, int ec, bool& valid) {
        set<int> st;
        for(int i = sr; i <= er; i++) {
            for(int j = sc; j <= ec; j++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) {
                    valid = false;
                }
                st.insert(board[i][j]);
            }
        }
    }

    bool isValidSudoku(vector<vector<char>>& board) {

        // Validate rows
        for(int i = 0; i < 9; i++) {
            set<int> st;
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        // validate columns
        for(int j = 0; j < 9; j++) {
            set<int> st;
            for(int i = 0; i < 9; i++) {
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end()) {
                    return false;
                }
                st.insert(board[i][j]);
            }
        }

        // validate boxes
        for(int sr = 0; sr < 9; sr+=3) {
            int er = sr + 2;
            for(int sc = 0; sc < 9; sc+=3) {
                int ec = sc + 2;
                bool valid = true;
                traversal(board, sr, er, sc, ec, valid);
                if(!valid) return false;
            }
        }
        return true;
    }
};
