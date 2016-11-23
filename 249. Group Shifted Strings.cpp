class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, vector<string> > mp;
        for (string  s : strings)
        {
            mp[shift(s)].push_back(s);
        }
        vector<vector<string> > groups;
        for (auto m : mp) 
        {
            vector<string> group = m.second;
            sort(group.begin(), group.end());
            groups.push_back(group);
        }
        return groups;
    }
private:
    string shift(string& s) {
        string t;
        int n = s.length();
        for (int i = 1; i < n; i++) {
            int diff = s[i] - s[0];
            if (diff < 0) diff += 26;
            t += 'a' + diff;
        }
        return t;
    }
};

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) 
    {
        vector<vector<string>> res;

        unordered_map<string,int> mymap;

        for (auto i : strings)
        {
            int flag = 1;

            for (auto j : mymap)
            {
                if (j.first.size() == i.size())
                {
                    int tmp = i[0] - j.first[0];

                    string s = i;

                    for (int k = 0; k<s.size();k++)
                    {
                        int t= s[k]-tmp;
                        
                        if(t < 'a') t = 'z' - ('a' - t -1);
                        
                        if(t > 'z') t = 'a' + (t - 'z' -1);

                        s[k] = t;
                    }
                    
                    if(s == j.first)
                    {
                        res[j.second].push_back(i);
                        flag = 0;
                        break;
                    }
                }
            }

            if(flag)
            {
                mymap[i] = res.size();
                res.push_back({i});        
            }
        }
        return res;
    }
};