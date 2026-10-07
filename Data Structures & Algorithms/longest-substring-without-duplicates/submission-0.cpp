class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> freq;

        int i=0;
        int j=0;
        int ans = 0;

        while(j<s.size()){
            freq[s[j]]++;

            while(freq[s[j]] > 1){
                freq[s[i]]--;
                if(freq[s[i]] == 0) freq.erase(s[i]);
                i++;
            }

            ans = max(ans, j-i+1);
            j++;
        }
        return ans;
    }
};
