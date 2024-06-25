class Solution {
public:
    // Similar to the Binary Subarray Sum 

    // COUNT with exactly K --> Same Template 
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums, k) - atmost(nums, k - 1);
    }
    int atmost(vector<int>& nums, int k) {
        int left = 0, right = 0, count = 0, n = nums.size(), sum = 0;

        while (right < n) {
            sum += (nums[right] % 2);
            while ( sum > k) {
                sum -= (nums[left] % 2);
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};
