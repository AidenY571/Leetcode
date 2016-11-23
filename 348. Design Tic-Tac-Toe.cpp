class TicTacToe {
public:
    /** Initialize your data structure here. */
    int sum = 0;
    vector<pair<int,int>>row;
    vector<pair<int,int>>col;
    
    pair<int,int> diag = make_pair(0,0), anti_diag = make_pair(0,0);
    
    TicTacToe(int n) 
    {
        sum = n;
        row = vector<pair<int,int>>(n,make_pair(0,0));
        col = vector<pair<int,int>>(n,make_pair(0,0));
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int r, int c, int player) 
    {
        if(row[r].first == 0)
        {
            row[r].first = player;
            row[r].second++;
        }
        else if(row[r].first == player)row[r].second++;
        
        
        if(col[c].first == 0)
        {
            col[c].first = player;
            col[c].second++;
        }
        else if(col[c].first == player)col[c].second++;
        
        if(r == c)
        {
            if(diag.first == 0)
            {
                diag.first = player;
                diag.second++;
            }
            else if(diag.first == player)diag.second++;
        }
        
        if(r == sum-1-c)
        {
            if(anti_diag.first == 0)
            {
                anti_diag.first = player;
                anti_diag.second++;
            }
            else if(anti_diag.first == player)anti_diag.second++;
        }
        
        if(row[r].second == sum || col[c].second == sum || diag.second == sum || anti_diag.second == sum) return player;
        
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */