class Logger {
public:
    unordered_map<string,int>m;

    Logger() 

    bool shouldPrintMessage(int timestamp, string message) 
    {
        if (timestamp < m[message]) return false;
        
        m[message] = timestamp+10;
        
        return true;
    }
};

class Logger {
public:
    unordered_map<string,int>m;

    Logger() 

    bool shouldPrintMessage(int timestamp, string message) 
    {
        if (m.find(message) == m.end() || (timestamp - m[message]) > 9) 
            {m[message] = timestamp;return true;}
        
        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */