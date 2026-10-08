class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char, int> mp;

        for(char c : t) {
            mp[c]++;
        }

        int count = t.size();
        int i = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int j = 0; j < s.size(); j++) {

            if(mp.count(s[j]) && mp[s[j]] > 0) {
                count--;
            }

            mp[s[j]]--;

            while(count == 0) {

                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    start = i;
                }

                if(mp.count(s[i]) && mp[s[i]] >= 0) {
                    count++;
                }

                mp[s[i]]++;
                i++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
