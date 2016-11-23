class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m =board.size(),n =board[0].size();
        
        for (int i = 0; i < m; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
        		check(i,j,board,m-1,n-1);
        	}
        }
        
        for (int i = 0; i < m; ++i)
        {
        	for (int j = 0; j < n; ++j)
        	{
        		if(board[i][j] < 0) board[i][j] *= -0.5;
        	}
        }
        return;
    }

    void check(int x, int y,vector<vector<int>>& board,int m,int n)
    {
    	int sum = -board[x][y];

    	for (int i = max(x-1,0); i <= min(m,x+1); ++i)
    	{
    		for (int j = max(y-1,0); j <= min(n,y+1); ++j)
    		{
    			sum += abs(board[i][j])%2;
    		}
    	}

    	if (board[x][y]==1 && sum/2 != 1) board[x][y] = -1;

    	if (board[x][y] == 0 && sum==3) board[x][y] = -2;
    }
};

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size(), n = m ? board[0].size() : 0;
        for (int i=0; i<m; ++i) 
        {
            for (int j=0; j<n; ++j) 
            {
                int count = 0;
                for (int I=max(i-1, 0); I<min(i+2, m); ++I)
                    for (int J=max(j-1, 0); J<min(j+2, n); ++J)
                        count += board[I][J] & 1;

                if (count == 3 || count - board[i][j] == 3)
                    board[i][j] |= 2;
            }
        }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] >>= 1;
    }
};