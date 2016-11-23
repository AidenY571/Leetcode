int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int i = 0,step=0;
        
        while(i < n) 
        {
            step = read4(buf+i);
            i += step;
            if(step < 4) break;
        }
        
        if(i>n) buf[n]='\n';
        
        return min(i,n);
    }
};