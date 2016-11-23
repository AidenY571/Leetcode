class Solution {
public:
    int min_l,max_l;
    
    int numberOfPatterns(int m, int n) 
    {
        int res = 0;
        bool board[3][3] ={false};
        min_l = m; max_l = n;
        check(0, 0, 1, board,res);
        check(0, 1, 1, board,res);
        int tmp = 4*res;
        res = 0;
        check(1, 1, 1, board,res);;
        return tmp + res;
    }
    

    void check(int x, int y, int len, bool board[3][3], int &res) 
    {
        if (len > max_l) return;
        
        if (len >= min_l && len <= max_l) ++res;

        board[x][y] = true;
        
        for (int i = 0; i < 3; i++) 
        {
            for (int j = 0; j < 3; j++) 
            {
                if (board[i][j] 
                    || (i == x && abs(j - y) > 1 && !board[x][1])
                    || (j == y && abs(i - x) > 1 && !board[1][y])
                    || ((i + j == x + y || i - x == j - y) && abs(i - x) > 1 && !board[1][1]))
                {
                    continue;
                }
                
                check(i, j, len+1, board,res);
            }
        }
        
        board[x][y] = false;
    }
    
};