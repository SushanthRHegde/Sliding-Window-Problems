class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0 , right = 0;
        int n = nums.size();
        int len = 0;
        int zeroes = 0;

        while( right < n ){
            //No of zeroes in binary array
            if(nums[right] == 0) zeroes ++;

            while(zeroes > k){
                //zero should be atmost k only , if it's more then move left pointer
                if(nums[left] == 0) zeroes--; //nums[left] --> left most pointer (starting)
                left++;
            }
            
            len = max(len , right - left + 1);
            right++;
        }
        return len;
    }
};
