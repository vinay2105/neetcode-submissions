class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size())
            return false;
        vector<int> f1(26,0);
        vector<int> f2(26,0);

        for(auto it : s1){
            int index = it - 'a';
            f1[index]++;
        }

        int n1 = s1.size();

        for(int i=0;i<n1;i++){
            int index = s2[i]-'a';
            f2[index]++;
        }
        if(f1==f2) return true;

        int i=0;
        int j=n1;
        int n2 = s2.size();

        while(j<n2){

            int index1 = s2[j]-'a';
            int index2 = s2[i]-'a';
            f2[index1]++;
            f2[index2]--;
            if(f2 == f1) return true;
            j++;
            i++;
        }
        return false;
    }
};
