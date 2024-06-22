class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0 , right = 0 ;
        int n = s.size();
        int len = 0;

        vector<int> mpp(256,-1); //map with char , with index

        while ( right < n ){
            //if it's already there in map --> left++
            if(mpp[s[right]] != -1){
                left = max(left,mpp[s[right]] + 1);
            }
          //move the right 
            len = max(len, right - left + 1 ); //for the maxLen
            mpp[s[right]] = right;
            right++;
        }
        return len;
    }
};
