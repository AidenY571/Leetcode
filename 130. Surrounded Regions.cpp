class Solution {
public:
    int col,row;
    void solve(vector<vector<char>>& board) 
    {
        if(board.empty()) return;
        
        col= board.size();
        row = board[0].size();

        for (int i = 0; i < col; ++i)
        {
            if (board[i][0] =='O')draw(i,0,'1',board);
            if (board[i][row-1] =='O')draw(i,row-1,'1',board);
        }

        for (int i = 0; i < row; ++i)
        {
            if (board[0][i] =='O')draw(0,i,'1',board);
            if (board[col-1][i] =='O')draw(col-1,i,'1',board);
        }
        
        for (int i = 0; i < col; ++i)
        {
            for (int j = 0; j < row; ++j)
            {
                if(board[i][j]=='O')board[i][j]='X';
                if(board[i][j]=='1')board[i][j]='O';
            }
        }

        return;
    }

    void draw(int i, int j, char k,vector<vector<char>>& board)
    {
        queue<pair<int,int> > q;

        q.push({i,j});

        while(!q.empty())
        {
            int a = q.front().first, b = q.front().second;
            
            q.pop();

            board[a][b] = k;

            if (a > 0 && board[a-1][b]=='O') {board[a-1][b] = k;q.push({a-1,b});}

            if (b > 0 && board[a][b-1]=='O') {board[a][b-1] = k;q.push({a,b-1});}

            if (a+1 < col && board[a+1][b]=='O') {board[a+1][b] = k;q.push({a+1,b});}

            if (b+1 < col && board[a][b+1]=='O') {board[a][b+1] = k;q.push({a,b+1});}
        }

        return;
    }
};