class Solution {
public:
    vector<vector<int>> ret;
    vector<int> a;
    int n;
    vector<bool> visited;
    void generate(int i, vector<int>& cur){
        if (i>=n){
            ret.push_back(cur);
            return;
        }
        
        for (int j = 0; j < a.size() ; j++){
            if (!visited[j]){
                visited[j] = true;
                cur.push_back(a[j]);
                generate(i+1, cur);
                cur.pop_back();
                visited[j] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        this-> a = nums;
        this->n = nums.size();
        visited.resize(n, false);
        vector<int> cur;
        generate(0,cur);
        return ret;
    }
};
