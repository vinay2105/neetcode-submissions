class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        for(auto it : freq){
            int ele = it.first;
            int f = it.second;

            if(pq.size() < k){
                pq.push({f,ele});
            }
            else{
                if(f > pq.top().first){
                    pq.pop();
                    pq.push({f,ele});
                }
            }
        }

        vector<int> ans;

        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

        
    }
};
