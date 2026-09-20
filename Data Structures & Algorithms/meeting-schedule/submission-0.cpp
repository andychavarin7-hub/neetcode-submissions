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
    struct {
        bool operator()(const Interval& lhs, const Interval& rhs) { return rhs.end > lhs.end; };
    } IntervalSorter;

   public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        std::sort(intervals.begin(), intervals.end(), IntervalSorter);
        //above sort will be of order 

        for(auto ii =1; ii < intervals.size(); ++ii){

            Interval& before = intervals[ii-1];
            Interval& after = intervals[ii];
            
            
            if(after.start < before.end){
                return false;
            }
        }
        return true;
    }
};
