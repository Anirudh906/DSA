#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
  
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
public:
    int numTeams(vector<int>& rating) {
        int n = rating.size();
        vector<int> smallerLeft(n), smallerRight(n), greaterLeft(n), greaterRight(n);
        ordered_set s;
        for(int i = n - 1; i >= 0; i--){
            s.insert(rating[i]);
            smallerRight[i] = s.order_of_key(rating[i]);
            greaterRight[i] = s.size() - 1 - s.order_of_key(rating[i]);
        }
        s.clear();
        for(int i = 0; i < n; i++){
            s.insert(rating[i]);
            smallerLeft[i] = s.order_of_key(rating[i]);
            greaterLeft[i] = s.size() - 1 - s.order_of_key(rating[i]);
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += smallerLeft[i] * greaterRight[i];
            ans += greaterLeft[i] * smallerRight[i];
        }
        return ans;
    }
};