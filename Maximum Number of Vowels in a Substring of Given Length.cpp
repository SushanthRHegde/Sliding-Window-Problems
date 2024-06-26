class Solution {
public:
    bool isVowel(char ch){
        if(ch == 'a' || ch == 'e' ||ch == 'i' ||ch == 'o' ||ch == 'u' ){
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int left = 0 , right = 0 , count = 0 , n = s.size() , maxV = 0;

        while( right < n ){
            char ch = s[right];
            // Count the number of vowels 
            if(isVowel(ch)){
                count++;
            }
            // Shrink the window if substring length is more than k
            while( (right - left + 1) > k){
                if(isVowel(s[left])) count--;
                left++;
            }
            // Count the max number of vowels in substring
            maxV = max(count,maxV);
            right++;
        }
        return maxV;
    }
};
