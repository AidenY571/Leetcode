class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) 
    {
        vector<int>num;
        root = vector<int>(m*n, -1);
        int move[4][2] ={{-1,0},{1,0},{0,-1},{0,1}};
        int num_islands = 0;
        for (auto pos : positions)
        {
            int cur_pos = n*pos.first + pos.second;
            ++num_islands;
            root[cur_pos] = cur_pos;
            for (auto i : move)
            {
                int row = pos.first+i[0], col = pos.second+i[1], index = n*row + col;
                
                if (row < 0 || row >= m || col < 0 || col >= n || root[index] == -1) continue;
                    
                int tmp_root = find_root(index);

                if(cur_pos != tmp_root)
                {
                    root[tmp_root] = cur_pos;
                    --num_islands;
                }
            }
            num.push_back(num_islands);
        }
        return num;
    }

private:
    vector<int> root;

    int find_root(int id)
    {
        while(id != root[id]) 
        {
            root[id] = root[root[id]];
            id = root[id];
        }

        return id;
    }
};