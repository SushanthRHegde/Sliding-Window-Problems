class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0 , right = 0 , n = nums.size(), minLen = INT_MAX , sum = 0;

        while( right < n ){
            sum += nums[right];
            //shifting window if sum is more then or equal to target
            while( sum >= target){
                minLen = min(minLen , right - left + 1 );
                sum -= nums[left];
                left++;
            }   

            right++;
        }
        //if ele doesnt satisy the sum , then return 0
        if(minLen == INT_MAX) return 0;
        return minLen;
    }
};
