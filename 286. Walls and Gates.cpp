class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) 
    {
        for (int i = 0; i < rooms.size(); ++i)
        {
            for (int j = 0; j < rooms[0].size(); ++j)
            {
                if (rooms[i][j] == 0)
                {
                    check(rooms,i-1,j,1);
                    check(rooms,i,j-1,1);
                    check(rooms,i+1,j,1);
                    check(rooms,i,j+1,1);
                }
            }
        }
    }

    void check(vector<vector<int>>& room, int i, int j,int val)
    {
        if (i < 0 || j < 0 || i >= room.size() || j >= room[0].size() || room[i][j] <= val) return;
        
        room[i][j] = val;

        check(room,i-1,j,val+1);

        check(room,i,j-1,val+1);

        check(room,i+1,j,val+1);

        check(room,i,j+1,val+1); 
        
        return;
    }
};