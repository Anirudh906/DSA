/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> res;
        
        int n = schedule.size();
        map<int, int> mp;
        for(int i = 0; i < n; i++){
            auto time = schedule[i];
            for(auto &interval: time){
            mp[interval.start]++;
            mp[interval.end]--;
            }
        }
        
        int tot = 0;
        for(auto &x: mp){
            tot += x.second;
            if(tot == 0){
                res.push_back(Interval(x.first, 0));
            }
            else if(tot > 0 and res.size() > 0 and res.back().end == 0) res.back().end = x.first;
        }
        if(!res.empty()) res.pop_back();
        return res;
     }
};