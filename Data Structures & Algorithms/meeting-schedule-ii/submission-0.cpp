/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<int> start;
        vector<int> end;

        for(int i = 0; i < n; i++) {
            start.push_back(intervals[i].start);
            end.push_back(intervals[i].end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int startI = 0;
        int endI = 0;
        int cnt = 0;
        int maxi = 0;

        while(startI < n) {
            if(start[startI] < end[endI]) {
                cnt++;
                startI++;
            } 
            else {
                cnt--;
                endI++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};
