class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Pattern --> We need subArray of Exactly K distict integer 
        return slidingWndow( nums, k ) - slidingWndow( nums, k - 1 );
    }
    int slidingWndow(vector<int>& nums, int k){

        int left  = 0 , right = 0 , n = nums.size() , count = 0 ;
        unordered_map<int,int> mpp;

        while ( right < n ){
            mpp[nums[right]]++;
            //if distict ele is more then k --> shift the window
            while( mpp.size() > k){

                mpp[nums[left]]--;
                // erasing the ele it has freq 0 
                if(mpp[nums[left]] == 0 ){
                    mpp.erase(nums[left]);
                }
                left++;
            }
            count += right - left + 1 ;
            right++;
        }
        return count;

    }
};
