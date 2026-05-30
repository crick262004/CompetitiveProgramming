# DIJKSTRA’S ALGO:


Question asking: 
Given a weighted, undirected (or directed) and connected graph where you have given <u>[adjacency list](https://www.geeksforgeeks.org/adjacency-list-meaning-definition-in-dsa/)</u> **adj.** You have to find the shortest distance of all the vertices from the source vertex **src**, and return a list of integers denoting the shortest distance between **each node** and source vertex **src**.
**Note:** The Graph doesn't contain any negative weight edge.


# SET:
*const* int N = 2e5 + 5; 
*vpi* adjL[N];
ll n, m;
void solve(){
    cin >> n >> m;
    f(i,n+1){
        adjL[i].clear();
    }
    f(i,m){
        ll u, v, w; cin >> u >> v >> w;
        adjL[u].pb({v, w});
    }
     <span style="font-size: 19.0;">
     **set<pair<int,int>> st; 
    vector<int> dist(n+1, 1e18);**
 </span> <span style="font-size: 19.0;">
      ***// 1e18 represents not possible to reach this node from source***
 </span>
    
 <span style="font-size: 19.0;">
         ***// assuming source node to be 1***
 </span> <span style="font-size: 19.0;">
     
    **int S = 1;
    st.insert({0, S}); 
    dist[S] = 0;**


 </span> <span style="font-size: 19.0;">
         ***// Now, erase the minimum distance node first from the set***
 </span>
 <span style="font-size: 19.0;">
         ***// and traverse for all its adjacent nodes.***
 </span> <span style="font-size: 19.0;">
     
    **while(!st.empty()){
        auto it = *(st.begin()); 
        int node = it.second; 
        int dis = it.first; 
        st.erase(it);** 
        

 </span> <span style="font-size: 19.0;">
             ***// Check for all adjacent nodes of the erased***
 </span>
 <span style="font-size: 19.0;">
             ***// element whether the prev dist is larger than current or not.***
 </span> <span style="font-size: 19.0;">
     
        **for(auto it : adjL[node]){
            int adjNode = it.first; 
            int edgW = it.second;
            
            if(dis + edgW < dist[adjNode]){**

 </span> <span style="font-size: 19.0;">
                     ***// erase if it was visited previously at*** 
 </span>
 <span style="font-size: 19.0;">
                     ***// a greater cost.***
 </span> <span style="font-size: 19.0;">
     
                **if(dist[adjNode] != 1e18) 
                    st.erase({dist[adjNode], adjNode});** 
                    

 </span> <span style="font-size: 19.0;">
                     ***// If current distance is smaller,***
 </span>
 <span style="font-size: 19.0;">
                     ***// push it into the queue***
 </span> <span style="font-size: 19.0;">
     
                **dist[adjNode] = dis + edgW; 
                st.insert({dist[adjNode], adjNode}); 
            }
        }
    }**
 </span>
    for(int i = 1; i<=n; i++)
        cout << dist[i] << " ";
    cout << endl;
}

# PQ:
class Solution
{
public:
    *// Function to find the shortest distance of all the vertices*
    *// from the source vertex S.*
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {

        *// Create a priority queue for storing the nodes as a pair {dist,node}*
        *// where dist is the distance from source to the node.* 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        *// Initialising distTo list with a large number to*
        *// indicate the nodes are unvisited initially.*
        *// This list contains distance from source to the nodes.*
        vector<int> distTo(V, INT_MAX);

        *// Source initialised with dist=0.*
        distTo[S] = 0;
        pq.push({0, S});

        *// Now, pop the minimum distance node first from the min-heap*
        *// and traverse for all its adjacent nodes.*
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            *// Check for all adjacent nodes of the popped out*
            *// element whether the prev dist is larger than current or not.*
            for (auto it : adj[node])
            {
                int v = it[0];
                int w = it[1];
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
    
                    *// If current distance is smaller,*
                    *// push it into the queue.*
                    pq.push({dis + w, v});
                }
            }
        }
        *// Return the list containing shortest distances*
        *// from source to all the nodes.*
        return distTo;
    }
};

# STATE DIJKSTRA: 
# (VERY SIMILAR TO STAGE DP)

    set<vi> st; 

    vvi dist(n+1, vi(2, 1e18)); 
    
    st.insert({0, 0, 1}); 
    st.insert({0, 1, 1}); 
    dist[0][0] = 0;
    dist[0][1] = 0;
    
    while(!st.empty()) {
        auto it = *(st.begin()); 
        int node = it[2]; 
        int dis = it[0]; 
        int type = it[1];
        st.erase(it);
        
        for(auto it : adjL[node]) {
            int adjNode = it.ff;
            int edgW = it.ss;
            if(type == 0 && dist[adjNode][0] > (dis + edgW)){
                if(dist[adjNode][0] != 1e18) 
                    st.erase({dist[adjNode][0], 0, adjNode}); 
                dist[adjNode][0] = dis + edgW;
                st.insert({dist[adjNode][0], 0, adjNode});
            }
            if(type == 0 && dist[adjNode][1] > (dis + (edgW/2))){
                if(dist[adjNode][1] != 1e18) 
                    st.erase({dist[adjNode][1], 1, adjNode}); 
                dist[adjNode][1] = dis + (edgW/2);
                st.insert({dist[adjNode][1], 1, adjNode});
            }
            if(dist[adjNode][1] > (dis + edgW)){
                if(dist[adjNode][1] != 1e18) 
                    st.erase({dist[adjNode][1], 1, adjNode}); 
                dist[adjNode][1] = dis + edgW;
                st.insert({dist[adjNode][1], 1, adjNode});
            }
        }
    }
    cout << dist[n][1] << endl;

# DIJKSTRA WITH EXTRA VALUES CALCULATED ALONG THE WAY 
# (ALL ARE BASICALLY DP IDEAS)
    set<*vi*> st; 
    *vvi* dist(n+1, *vi*(4, 1e18)); 
    for(int i= 2; i<=n; i++){
        dist[i][1] = 0;
        dist[i][3] = 0;
    }
    st.insert({0, 1,  1, 0, 0}); 
    dist[1] = {0, 1, 0, 0};
    
    while(!st.empty()){
        auto it = *(st.begin()); 
        int node = it[1]; 
        int dis = it[0]; 
        int count = it[2];
        int minlen = it[3];
        int maxlen = it[4];
        st.erase(it);
        
        for(auto it : adjL[node]) {
            int adjNode = it.ff;
            int edgW = it.ss;
            if(dist[adjNode][0] == (dis + edgW)){
                if(dist[adjNode][0] != 1e18){
                    st.erase({dist[adjNode][0], adjNode, dist[adjNode][1], dist[adjNode][2], dist[adjNode][3]});
                }
                dist[adjNode][1] += count;
                dist[adjNode][1] %= mod;
                dist[adjNode][2] = min(minlen + 1, dist[adjNode][2]);
                dist[adjNode][3] = max(maxlen + 1, dist[adjNode][3]);
                st.insert({dist[adjNode][0], adjNode , dist[adjNode][1], dist[adjNode][2], dist[adjNode][3]});
            } 
            else if(dist[adjNode][0] > dis + edgW){
                if(dist[adjNode][0] != 1e18){
                    st.erase({dist[adjNode][0], adjNode,dist[adjNode][1], dist[adjNode][2], dist[adjNode][3]});
                }
                dist[adjNode][0] = dis + edgW;
                dist[adjNode][1] = count;
                dist[adjNode][2] = minlen + 1;
                dist[adjNode][3] = maxlen + 1;
                st.insert({dist[adjNode][0], adjNode ,dist[adjNode][1], dist[adjNode][2], dist[adjNode][3]});
            }
        }
    }
    cout << dist[n] << endl;