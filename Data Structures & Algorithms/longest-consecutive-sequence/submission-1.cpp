class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        int ans = 1;

        unordered_map<int, int> mp;
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i] -1) == mp.end()){
                mp[nums[i]] = 1;
            }
            else{
                mp[nums[i]] = mp[nums[i]-1] + 1;
                ans = max(mp[nums[i]], ans);
            }
        }
        return ans;
        
    }
};
