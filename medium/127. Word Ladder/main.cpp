class Solution {
public:
    vector<vector<int>> g;
    int n;
    const int INF = 1e9;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        n = wordList.size();
        g.resize(n);
        unordered_map<string, int> word_map;    
        int end_word_index = -1;
        
        for (int i= 0; i < wordList.size() ; i++){
            if (wordList[i] == endWord)
                end_word_index = i;
            word_map[wordList[i]] = i ;
        }
        if (end_word_index==-1) return 0;
        queue<int> q;
        vector<int> dist(n, INF);
        int u = 0 ;
        for (auto & s: wordList){
            for (auto& c: s){
                auto tmp = c;
                for (int i= 'a' ; i<='z' ; i++){
                    if (i==tmp) continue;
                    c = i;
                    if (word_map.count(s))
                        g[u].push_back(word_map[s]); 
                    if (s == beginWord){
                        q.push(u);
                        dist[u] = 0;
                    }
                } 
                c = tmp;
            }
            u++;
        }
        
        
          
        while (!q.empty() && dist[end_word_index] == INF){
            int u = q.front();
            q.pop();
            
            for (auto&v: g[u]){
                if (dist[v] == INF){
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
            }
            
        }
        
        return dist[end_word_index]!=INF? dist[end_word_index]+2:0;
  
        
    }
};
