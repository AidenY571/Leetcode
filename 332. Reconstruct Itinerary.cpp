class Solution {
private:
    unordered_map<string, multiset<string>> mymap;
    vector<string> res;
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) 
    {
        for (auto i : tickets)
        {
            mymap[i.first].insert(i.second);
        }

        visit("JFK");

        return vector<string>(res.rbegin(), res.rend());
    }
    

    void visit(string airport) 
    {
        while (!mymap[airport].empty()) 
        {
            string next = *mymap[airport].begin();
            mymap[airport].erase(mymap[airport].begin());
            visit(next);
        }

        res.push_back(airport);
    }
};


class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) 
    {
        unordered_map<string, multiset<string>> mymap;

        vector<string> res;

        for (auto i : tickets)
            mymap[i.first].insert(i.second);
    

        stack<string> s;

        s.push("JFK");

        while(!s.empty())
        {
            string tmp = s.top();
            if (!mymap[tmp].size()) 
            {
                res.push_back(tmp);
                s.pop();
            }
            else
            {
                s.push(*mymap[tmp].begin());
                mymap[tmp].erase(mymap[tmp].begin());

            }
        }
        return vector<string>(res.rbegin(), res.rend());
    }
};