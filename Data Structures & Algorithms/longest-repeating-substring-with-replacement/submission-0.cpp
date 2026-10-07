class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> freq;

        int i=0;
        int j=0;
        int ans = 0;

        while(j<s.size()){
            freq[s[j]]++;

            int mmf = INT_MIN;

            for(auto it : freq){
                mmf = max(mmf, it.second);
            }
            
            while(k < ((j-i+1) - mmf)){
                freq[s[i]]--;
                for(auto it : freq){
                    mmf = max(mmf, it.second);
                }
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans;

        
    }
};
