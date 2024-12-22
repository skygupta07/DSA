#include <bits/stdc++.h>
using namespace std;


    // Function to find the shortest distance of all vertices from the source vertex S.
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S){
        // Create a distance array to store the shortest distance to each vertex.
        // Initialize all distances to a very large number (like infinity).
        vector<int> dist(V, 1e9);
        dist[S] = 0;  // Distance from the source to itself is always 0.

        // Min-heap (priority queue) to always pick the node with the smallest distance.
        // We store pairs of (distance, node) in the priority queue.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        //                             ^^^    ^^^^^^^^^^^^^^^^^    ^^^^^^^^^^^^^^^^^^
        //                            pair      vector of pairs     min-heap structure

        // Start by pushing the source node into the priority queue with a distance of 0.
        pq.push({0, S});  // Initially, the distance from source to source is 0.

        // Loop while there are still nodes to process in the priority queue.
        while (!pq.empty()){
            // Get the node with the smallest distance so far.
            int dis = pq.top().first;  // The distance to reach this node *** 
            int node = pq.top().second;  // The current node itself.
            pq.pop();  // Remove this node from the queue since we are processing it.

            // Now, process all the neighbors of the current node.
            for (auto neighbour : adj[node]){  // Loop through all neighbors of the current node.
                int edgeWeight = neighbour[1];  // The weight of the edge to this neighbor.
                int adjNode = neighbour[0];  // The neighbor node itself.

                // Check if going to this neighbor via the current node gives a shorter path.
                if (dis + edgeWeight < dist[adjNode]){
                    // If yes, update the shortest distance to this neighbor.
                    dist[adjNode] = dis + edgeWeight;
                    // And push this neighbor into the priority queue for further processing.
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        // Finally, return the array of shortest distances from the source to all nodes.
        return dist;
    }




/*


time - complexity: ElogV
source node se har node tak ka shortest path find karte hai....

0 se zero tak ka distance zero...
aur distances ko philal infinity rakha.....

min heap mai {distance , node } store kara....


dijakstra's not valid for negative edge weights....
it will fall in infinite loop decreasing the value in each go...

ek cheej dhyan rakhna question mai chahe details jis marji tareeke se de rakhi
ho aap variable apni marji se bana sakte ho....

aur ha har question ko banaya isliye hi jaata h ko wo solve ho sake...simple 
*/