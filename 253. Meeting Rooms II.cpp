/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        int len = intervals.size();
        
        if (len <= 1) return len;
    
        sort(intervals.begin(), intervals.end(), 
            [](Interval& x, Interval& y){return x.start < y.start;});

        vector<int> rooms;

        for (int i = 0; i < len; i++) 
        {
            int j = 0;

            for (; j < rooms.size(); ++j) 
            {
                if (intervals[i].start >= rooms[j]) 
                {
                    rooms[j] = intervals[i].end;
                    break;
                }
            }

            if(j == rooms.size())rooms.push_back(intervals[i].end);
        }
        return rooms.size();
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        vector<pair<int,int>> rooms;

        for(auto i : intervals)
        {
            rooms.push_back(make_pair(i.start,1));
            rooms.push_back(make_pair(i.end,-1));
        }

        sort(rooms.begin(),rooms.end());

        int num = 0,sum = 0;

        for (int i = 0; i < rooms.size(); ++i) 
        {
            
            sum += rooms[i].second;

            num = max(num,sum);
        }
        return num;
    }
};