class Vector2D {
public:
    vector<vector<int>> vec;
    int row = 0,col = 0;
    Vector2D(vector<vector<int>>& vec2d) 
    {
        vec = vec2d;
        if(vec.empty())row++;
        while(row < vec.size() && vec[row].empty()) row++;
    }

    int next() 
    {
        int res = vec[row][col++];

        if(col == vec[row].size()) {col = 0;row++;}

        while(col == 0 && row < vec.size() && vec[row].empty())
        {
            row++;
        }

        return res;
    }

    bool hasNext() 
    {
        if(row < vec.size()) return true;

        return false;
    }
};

class Vector2D {
public:
    vector<vector<int>>* vec;
    vector<vector<int>>::iterator row;
    vector<int>::iterator col;

    Vector2D(vector<vector<int>>& vec2d) 
    {
        vec = &vec2d;
        row = vec->begin();
        if(row != vec->end()) col = row->begin();
    }

    int next() 
    {
        return *col++;
    }

    bool hasNext() 
    {
        while(row != vec->end() && col == row->end())
        {
            row++;
            col = row->begin();
        }
        
        return row != vec->end() ;
    }
};