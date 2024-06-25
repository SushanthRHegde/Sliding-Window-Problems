class Solution {
public:
    int numberOfSubstrings(string s) {
        int left = 0 , right = 0 , n = s.size() , count = 0;
        unordered_map<char,int> mpp;

        while( right < n ){

            mpp[s[right]]++;
            while( mpp['a'] >= 1 && mpp['b'] >= 1 && mpp['c'] >= 1){
                count += n - right ;
                //after counting --> shifting the window 
                mpp[s[left]]--;
                left++;
            }
            right++;
        }
        return count;
    }
};
