// BFS for SHORTEST PATH, UG, UNIT EDGES

class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    //Create an adjacency list of size N for storing the undirected graph.
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        //A dist array of size N initialised with a large number to 
        //indicate that initially all the nodes are untraversed.    
    
        int dist[N];
        for(int i = 0;i<N;i++) dist[i] = 1e9;
        // BFS Implementation.
        dist[src] = 0; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        // Updated shortest distances are stored in the resultant array ‘ans’.
        // Unreachable nodes are marked as -1. 
        vector<int> ans(N, -1);
        for(int i = 0;i<N;i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }
        return ans; 
    }
};

// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        int n = N;
        vector<int> dist(n,-1);
        vector<int> adj[n];
        for(int i = 0; i<M;i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        queue<int> q;
        q.push(src);
        dist[src] = 0;
        
        int curdis = 1;
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0;i<size; i++)
            {
                int node = q.front();
                q.pop();
                for(int adjnode : adj[node])
                {
                    if(dist[adjnode] == -1)
                    {
                        dist[adjnode] = curdis;
                        q.push(adjnode);
                    }
                }
            }
            curdis++;
        }
        return dist;
    }
};


// PRINT ALL SHORTEST LENGTH PATHS, UG, UNIT EDGES : 
// BFS - USING QUEUE OF VECTOR OF PATH.
vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
    // code here
    if(count(wordList.begin(), wordList.end(), endWord) == 0)
        return {};

    unordered_map<string, vector<string>> map;
    if(count(wordList.begin(), wordList.end(), beginWord) == 0)
        wordList.push_back(beginWord);
    
    for(string word : wordList)
    {
        for(int j = 0; j<word.length(); j++)
        {
            string pattern = word.substr(0,j) + 
                    "*" + word.substr(j+1, word.length() - j -1);
            map[pattern].push_back(word);
        }
    }
    // graph made.
    
    vector<vector<string>> ans;    
    
    // the queue of list of strings
    // similar to bfs, but now vector of strings are stored in Queue.
    unordered_set<string> st;
    st.insert(beginWord);
    
    queue<vector<string>> q;
    q.push({beginWord});

    bool flag = false; // FOUND endWord

    while(!q.empty() && flag == false)
    {
        vector<string> viswords;
        int k = q.size();
        for(int i = 0; i<k; i++)
        {
            vector<string> words = q.front();
            q.pop();
            string word = words.back();
            if(word == endWord)
            {
                ans.push_back(words);
                flag = true;
                continue;
            }
            for(int j = 0; j<word.length(); j++)
            {
                string pattern = word.substr(0,j) + "*" 
                            + word.substr(j+1, word.length() - j -1);
                            
                for(string nei : map[pattern])
                {
                    if(st.find(nei) == st.end())
                    {
                        viswords.push_back(nei);
                        words.push_back(nei);
                        q.push(words);
                        words.pop_back();
                    }
                }
            }
        }
        for(string str : viswords)
            st.insert(str);
    }
    return ans;
}