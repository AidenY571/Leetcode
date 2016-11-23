class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        for (int i = 0; i < board.size(); ++i)
        {
            int v[9]={0};
            for (int j = 0; j < board[0].size(); ++j)
            {
                if(board[i][j] =='.') continue;
                int tmp = board[i][j]-'0'-1;
                if(v[tmp]) return false;
                v[tmp]++;
            }
        }

        for (int i = 0; i < board[0].size(); ++i)
        {
            int v[9]={0};
            for (int j = 0; j < board.size(); ++j)
            {
                if(board[j][i] =='.') continue;
                int tmp = board[j][i]-'0'-1;
                if(v[tmp]) return false;
                v[tmp]++;
            }
        }

        for (int i = 0; i < board.size(); i += 3)
        {
            for (int j = 0; j < board[0].size(); j += 3)
            {
                int v[9]={0};
                for (int m = i; m <= i+2; ++m)
                {
                    for (int n = j; n <= j+2; ++n)
                    {
                        if(board[m][n] =='.') continue;
                        int tmp = board[m][n]-'0'-1;
                        if(v[tmp]) return false;
                        v[tmp]++;
                    }
                }               
            }
        }
        return true;
    }
};