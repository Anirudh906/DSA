class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        
        int i = 0, m = 0, h = n - 1;
        
        while(m <= h){
              if(nums[m] == 0){
                  swap(nums[m++], nums[i++]);
                  
              }
          else if(nums[m] == 2){
               swap(nums[m], nums[h]);
               h--;
               
           }else{
              m++;
          }
        
        }
        
    }
};