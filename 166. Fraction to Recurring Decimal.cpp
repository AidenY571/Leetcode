class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator1) 
    {
        string res;
        
        long numerator = numerator1,denominator = denominator1;
        
        if(numerator==0) return "0";
        
        unordered_map<long,int> mymap;
        
        if (denominator*numerator< 0)
        {
            res.push_back('-');
            numerator = abs(numerator);
            denominator = abs(denominator);
        }

        res = res+to_string(numerator/denominator);
        
        numerator %= denominator;

        if (numerator) res.push_back('.');
        
        while(numerator != 0)
        {
            if (mymap.find(numerator) != mymap.end())break;

            mymap[numerator] = res.size();
                
            res.push_back(numerator*10/denominator + '0');
                
            numerator = numerator*10 % denominator;
        }
        
        if(numerator) res = res.substr(0,mymap[numerator]) + "(" + res.substr(mymap[numerator],res.size())+")";

        return res;
    }
};
class Solution {
public:
    string fractionToDecimal(int n, int d) 
    {
        long long numerator = n, denominator = d;
        string a, b;
        if(numerator*denominator < 0) {numerator = abs(numerator); denominator =abs(denominator);a.push_back('-');}
        
        a += to_string(numerator/denominator);
        unordered_map<long long,long long> m;

        numerator = numerator%denominator;
        m[numerator] = 0;
        numerator *= 10;
        if(!numerator) return a;

        while(numerator)
        {
            if(m.count(numerator))
            {
                int tmp = m[numerator];
                b = b.substr(0,tmp) + "("+b.substr(tmp)+")";
                break;
            }
                
            b.push_back(numerator/denominator+'0');
            m[numerator] = b.size()-1;
            numerator = numerator%denominator * 10;

        }
        return a +"."+b;
    }
};