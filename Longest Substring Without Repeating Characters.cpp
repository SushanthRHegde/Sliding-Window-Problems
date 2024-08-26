// Approach 1 : 

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0 , right = 0;
        int n = s.size();
        int len = 0;
        unordered_map<int,int> mp;
        while( right < n){
            mp[s[right]]++;
            // coz no duplication is allowed --> mp [nums[right]] == 1 only
            while(mp[s[right]] > 1){
                mp[s[left]]--;
                if(mp[s[left]] == 0) mp.erase(s[left]);
                left++;
            }
            len = max(len, right - left + 1);
            right++;
        }
        return len;
    }
};



// Approach 2 : 

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
