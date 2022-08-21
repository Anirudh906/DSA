class Solution {
public:
  int minimumOneBitOperations(int n){
    for (int i=30; i >= 0; i--) if (n & (1 << i)) {
        return (1 << (i+1)) - minimumOneBitOperations(n & ~(1 << i)) - 1;
    }
    return 0;
}
};