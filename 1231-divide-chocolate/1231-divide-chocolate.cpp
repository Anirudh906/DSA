class Solution {
public:
   int maximizeSweetness(vector<int> & sweetness, int K) {
         K=K+1;
       int lo = 0, hi = 0;
       int n = sweetness.size();
       for(int i = 0; i < n; i++){
           lo = min(lo, sweetness[i]);
           hi += sweetness[i];
       }
        while (lo <= hi) {
             int mid = lo + (hi - lo)/ 2;
            if (split(sweetness, mid) < K) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return hi;
    }

    int split(vector<int> & arr, int mid) {
        int res = 0;
        int temp = 0;
        for (int val : arr) {
            temp += val;
            if (temp >= mid) {
                res++;
                temp = 0;
            }
        }
        return res;
    }


};



//    K=K+1; // Include yourself.
//         int lo = getMin(sweetness);
//         int hi = getSum(sweetness);
//         while (lo < hi) {
//             int mid = (lo + hi + 1) >>> 1;
//             if (split(sweetness, mid) < K) {
//                 hi = mid - 1;
//             } else {
//                 lo = mid;
//             }
//         }
//         return lo;
//     }

//     private int split(int[] arr, int minSweetness) {
//         int peopleCount = 0;
//         int sweetness = 0;
//         for (int val : arr) {
//             sweetness += val;
//             if (sweetness >= minSweetness) {
//                 peopleCount++;
//                 sweetness = 0;
//             }
//         }
//         return peopleCount;

