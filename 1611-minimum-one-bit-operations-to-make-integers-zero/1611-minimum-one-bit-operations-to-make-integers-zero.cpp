class Solution {
public:
    int minimumOneBitOperations(int n) {
          if (n <= 1) return n;
        int l = 32 - __builtin_clz(n);
        int mask = (1 << (l - 1)) ^ n;
        return (1 << l) - 1 - minimumOneBitOperations(mask);
    }
};