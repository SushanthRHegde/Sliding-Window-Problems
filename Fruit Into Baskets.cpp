class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0 , j = 0 , maxlen = 0 ;
        int n = fruits.size();
        unordered_map<int,int> mpp; //map to count the freq of number

        while( j < n){
            //count the same type of fruit(number)
            mpp[fruits[j]]++;

            //if it has more than two types of fruits --> trim down
            while(mpp.size() > 2){
                mpp[fruits[i]]--;
                if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                i++;
            }
            //typical template of sliding window 
            maxlen = max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};
