class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) 
    {
        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if(check(board,word,i,j,0)) return true;
            }
        }

        return false;
    }

    bool check(vector<vector<char>>&b, string &s, int i, int j, int index)
    {
        if(index == s.size()) return true;

        if(i < 0 || j < 0 || i == b.size() || 
           j == b[0].size() || b[i][j] != s[index]) return false;

        b[i][j] = '+';

        if(check(b, s, i-1, j, index+1) ||
           check(b, s, i, j-1, index+1) ||
           check(b, s, i+1, j, index+1) ||
           check(b, s, i, j+1, index+1)) return true;

        b[i][j] = s[index];
    
        return false;
    }
};