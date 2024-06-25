
// Solution by taking unorederd_map 
class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 , right = 0 , n = s.size() , maxlen = 0 , maxfreq = 0;
        unordered_map<char,int> mpp;
        //Valid --> Maxlen - Maxfreq <= k ( in this case k times replacement can be done)
        while( right < n ){
            mpp[s[right]]++;
            maxfreq = max(maxfreq , mpp[s[right]]);
            //Trim down --> maxlen - maxfreq > k ( NOT VALID )
            while( ( right - left + 1 ) - maxfreq > k){
                mpp[s[left]]--;
                left++;
            }
            maxlen = max(maxlen , right - left + 1);
            right++;
        }
        return maxlen;
    }
};

// Solution by taking Hash as vector of 26 size

class Solution {
public:
    int characterReplacement(string s, int k) {
        int i = 0 , j = 0 , maxlen = 0;
        int n = s.size();
        int maxfreq = 0;
        vector<int> hash(26);
        // Valid --> Maxlen - maxfreq <= k
        while( j < n ){
            hash[s[j] - 'A']++;
            maxfreq = max(maxfreq, hash[s[j] - 'A']);
            while( (j - i + 1) - maxfreq > k){
                hash[s[i] - 'A']--;
                for(int i = 0 ; i < 25; i++){
                    maxfreq = max(maxfreq,hash[i]);
                }
                i++;
            }
            maxlen = max(maxlen, j - i + 1);
            j++;
        }
        return maxlen;
    }
};
