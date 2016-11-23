class ZigzagIterator {
public:
    queue<int> q;

    ZigzagIterator(vector<int>& v1, vector<int>& v2) 
    {
        for (int i = 0; i < v1.size() || i < v2.size(); ++i)
        {
            if(i < v1.size())q.push(v1[i]);
            if(i < v2.size())q.push(v2[i]);
        }
    }

    int next() 
    {
        int res = q.front();
        q.pop();
        return res;
    }

    bool hasNext() 
    {
        return q.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */