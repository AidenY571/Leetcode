class Solution {
public:
    int lengthLongestPath(string input) 
    {
        int length = 0, pre_level = 0, pre_length = 0;
        
        stack<int> s;

        for (int i = 0; i < input.size(); ++i)
        {
            int cur_level = 0, j = i,cur_length = 0, isfile = 0;
            
            for (; j < input.size(); ++j)
            {
                if(input[j] =='\n') break;
                else if(input[j] == '\t') cur_level++;
                else
                {
                    if(input[j] == '.') isfile = 1;
                    cur_length++;
                }
            }
            
            i= j;
           
            while(cur_level < pre_level)
            {
                pre_length -= s.top();
                pre_level--;
                s.pop();
            }
            if(isfile) length = max(length,pre_length + cur_length + cur_level);
            else
            {
                s.push(cur_length);
                pre_level++;
                pre_length += cur_length;
            }
        }

        return length;
    }
};