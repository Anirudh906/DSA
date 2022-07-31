class NumArray {
public:
    vector<int> tr; int n;
    NumArray(vector<int>& nums) {
         n = nums.size();
        tr = vector<int>(n<<1);                   
     
        for(int i=0 ; i<n ; i++)                     
            tr[i+n] = nums[i];
        for(int i = n-1 ; i>=1 ; i--)              
            tr[i] = tr[i<<1] + tr[(i<<1) +1];
    }
    
    void update(int i, int val) {
         i += n;                        
        tr[i] = val;              
        while(i>1)
        {
            i/=2;
            tr[i] = tr[i<<1] + tr[(i<<1)+1];
        }
    }
    
    int sumRange(int i, int j) {
        i+=n , j+=n+1;
        int sum = 0;
        while(i<j)
        {
            if(i&1)                         
                sum+=tr[i++];   
            if(j&1)
                sum+=tr[--j];
            i/=2 , j/=2;
        }
        return sum;   
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */