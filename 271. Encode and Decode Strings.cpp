class Codec {
public:
    string encode(vector<string>& strs) 
    {
        string res="";
        for(string str:strs) res += str+ '\0';
        return res;
    }

    vector<string> decode(string s) 
    {
        stringstream ss(s);
        vector<string> res;
        string temp;
        while(getline(ss,temp,'\0')) res.push_back(temp);
        return res;
    }
};