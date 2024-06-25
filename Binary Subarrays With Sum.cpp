class Solution {
public:

    // Here , atMost(nums,goal) - atMost(nums, goal - 1)  ==> which gives Sum == Goal
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return atMost(nums,goal) - atMost(nums, goal - 1);
    }


    int atMost(vector<int>& nums, int goal){
        if( goal < 0 ) return 0;
        int left = 0 , right = 0 , count = 0 , n = nums.size() , sum = 0;

        while ( right < n ){
            sum += nums[right];
            // Trim down if sum is more than goal
            while( sum > goal ){
                sum -= nums[left];
                left++;
            }
            // Typical SW template 
            count = count +  (right - left + 1);
            right++;
        }
        return count;
    }
};


// Suppose : goal = 2 
//           atmost(nums , goal) --> count subaaray sum of 0 ,1 , 2
//           atmost(nums , goal - 1 ) --> counts the subarray sum of 0 ,1 .
//           So differencve gives Count of subarray sum == K ( exactly)
