class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char, int> freq;

        for(auto i : s){
            freq[i]++;
        }

        for(auto j : t){
            if(freq.find(j) == freq.end()) return false;

            else{
                freq[j]--;
                if(freq[j] == 0) freq.erase(j);
            }
        }
        return true;
    }
};
