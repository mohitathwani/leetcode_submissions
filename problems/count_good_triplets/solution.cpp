#include <cmath> 
class Solution {
public:
    int countGoodTriplets(vector<int>& arr, int a, int b, int c) {
        int count = 0;
        int len = arr.size();
        
        for(int i = 0; i < len - 2; i++) {
            for(int j = i + 1; j < len - 1; j++) {
                if(std::abs(arr[i] - arr[j]) <= a) {
                    for(int k = j + 1; k < len; k++) {
                        if (std::abs(arr[j] - arr[k]) <= b && std::abs(arr[i] - arr[k]) <= c) {
                            count++;
                        }
                    }
                }
            }
        }
        
        return count;
    }
};