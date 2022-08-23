class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int res = 0;
        int i = 0, j = people.size() - 1;
        while(i <= j){
                res++;
            
            if(people[i] + people[j--] <= limit){
                i++;
            }
        }
        return res;
    }
};