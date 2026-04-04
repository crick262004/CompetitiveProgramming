# SHORTEST DISTANCE WHEN ONLY K STOPS

# : UNDIRECTED, WEIGHTED GRAPH 
# 
# ALGO’S CRUX :  MINIMISE DISTANCE WIHTIIN MINIMUM STOPS. SO WITHIN MIN STEPS(BFS), MINIMISE DISTANCE(EDGE REALISATION). AND THEN INCREMENT STEP.
# 
# BFS(SO THAT WE SEARCH IN INCREASING ORDER OF STOPS) , AND USKE UPAR APPLY REALISATION OF EDGES AND MINIMIZATION OF DISTANCE AND GREEDY APPROACH OF ONLY CONSIDERING FURTHER PATHS IF IT IS MINIMUM DISTANCE YET(THE BFS ORDER WILL IMPLICITLY MAKE SURE IT IS ALSO MINIMUM STOPS ALSO).


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, 
    int src, int dst, int k) 
    {
        // just for simplicity sake, ill make a adjacency list.
        vector<vector<int>> adj[n];
        for(auto v : flights)
        {
            adj[v[0]].push_back({v[1], v[2]});
        }

        vector<int> distance(n, 1e8);
        distance[src] = 0;


        // STRIVER SOLUTION
        // do a dijkstra, but with different set up
        // effecively, the only change is that instead of looking at the min distnace node first, we look at the smallest stops first.

        // and we can use a queue instead of a pq because using a q would just mean we are doing something like a bfs, and stops are always gonna be in increasing order while traversing through the queue.

        // so basically, this is a bfs on an undirected, weighted graph. Where we also use the edge realisation logic

        queue<pair<int, pair<int,int>>>q;
        // {stops, {node, dist}}
        q.push({0, {src, 0}});

        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            // if(stops>k)
            //     continue;
            int node = it.second.first;
            int dist = it.second.second;

            for(auto v : adj[node]){
                if(dist + v[1] < distance[v[0]])
                {
                    distance[v[0]] = dist + v[1];
                    if(stops + 1 <= k)
                        q.push({stops + 1, {v[0] ,dist + v[1]}});

                }
            }
        }
        return distance[dst] == 1e8? -1 : distance[dst];
    }
};

