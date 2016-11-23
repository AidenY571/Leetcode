class Solution {
public:
    void reverseWords(string &s) 
    {
        reverse(s.begin(),s.end());

        for (int i = 0; i < s.size(); ++i)
        {
            int start = i;

            while(s[i] != ' ' && i < s.size())++i;

            if(s[i]==' ')reverse(s.begin()+start,s.begin()+i-1);
            else
                reverse(s.begin()+start,s.begin()+i);
        }

        return;
    }
};