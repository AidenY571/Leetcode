class Solution {
public:
    vector<string> readBinaryWatch(int num) 
    {
        vector<string> times;
        for (int i = 0; i < 12; ++i)
        {
            for (int j = 0; j < 60; ++j)
            {
                bitset<32> t(i*64 + j);
                if(t.count() == num)
                {
                    if(j < 10) times.push_back(to_string(i)+":0"+to_string(j));
                    else times.push_back(to_string(i)+":"+to_string(j));
                }
            }
        }
        return times;
    }
};