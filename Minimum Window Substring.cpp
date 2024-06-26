class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        unordered_map<char, int> mp;
        
        //Storing the occurence of char of String t
        for(char &ch : t) {
            mp[ch]++;
        }
        
        int requiredCount = t.length();
        int left = 0, right  = 0;
        int minStart  = 0;
        int minWindow = INT_MAX;

        while( right < n) {
            char ch_j = s[right];
            if(mp[ch_j] > 0)
                requiredCount--;
            mp[ch_j]--;
            
            while(requiredCount == 0) { // shrink the window

                if(minWindow > ( right - left + 1) ) {
                    minWindow = right - left + 1;
                    minStart  = left ;
                }
                
                char ch_i = s[left];
                mp[ch_i]++;

                if(mp[ch_i] > 0)
                    requiredCount++;
                left++;
            }
            
            right++; 
        }
        
        return minWindow == INT_MAX ? "" : s.substr(minStart, minWindow);
    }
};
