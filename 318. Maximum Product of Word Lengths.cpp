class Solution {
public:
    int maxProduct(vector<string>& words) 
    {
    	vector<int> v;

    	int len = words.size(),res=0;

    	for (int i = 0; i < len; i++)
    	{
    	    int tmp = 0;

		    for (int j = 0; j < words[i].size(); ++j)
		    {
			    tmp |= 1 << (words[i][j] -'a');
		    }
		    
    		v.push_back(tmp);

    		for (int j = i - 1 ; j >= 0; j--)
        	{       		
        		if ((v[i] & v[j]) == 0) 
        		{
        		    int length = words[i].size() * words[j].size();
        		    
        		    if(length > res) res = length;
        		} 		
        	}
    	}

        return res;
    }
};

