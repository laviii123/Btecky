/*   Time Complexity : O(max(N, D))    Space Complexity: O((N + M) ^ 2)

    Where 'D' is the number of days oxygen is supplied 'M' is the number of paths and 'N' is the number of trucks.

*/
#include <algorithm>

// Take array of list to create graph.
vector<int> graph[1002];

// Take 2D array to store capacity of each edge.
int capacity[1003][1003];

// Take two array to store road and capacity reduction for each day. 
int R[1003], C[1003];

// Take array to mark whether 'i'th node is visited or not.
int visited[1004];

// Take array to store the parent of each node
int parent[1004];

/*   Utility function to find whether augmented path is present or not     and if present then also find the parent of each node */

bool getAugumentedpath(int s, int t)
{
	// Make node 's' visited   
	visited[s] = 1;

	// Run a loop to move all node adjacent to 's'   
	for (int i = 0; i < graph[s].size(); i++)
	{
		// Store the adjacent node in variable 'adj'       
		int adj = graph[s][i];

		// If node 'adj' is node visited and capacity of edge 's' -> 'adj' is greater than 0      
		if (visited[adj] == 0 && capacity[s][adj] > 0)
		{
			// Make 's' as parent of 'adj'           
			parent[adj] = s;	// If 'adj' is equal to targeted node 't' (sink) return true          
			if (adj == t)
			{
				return true;
			}

			// Call recursively on node 'adj', If augmented path is found return 'true'          
			if (getAugumentedpath(adj, t))
			{
				return true;
			}

			// If augmented path is not found, unmark parent of 'adj' (backtrack)          
			parent[adj] = -1;
		}
	}

	// Return false   
	return false;
}

// Utility function to find max flow from current augmented path 
int updateAugumentedPath(int N, int M)
{
	/*       Take a variable 'minCap' initialize it to infinity        It stores the minimum edge (bottle neck of augmented path) from augumented path    */
	int minCap = 100000000;

	// Take a variable 'node' initialize it to sink node  
	int node = N + M + 1;

	// Run a loop while parent of node is 'node' equal to -1, to find the minimum edge node   
	while (parent[node] != -1)
	{
		// Store parent of 'node' in varible 'temp'       
		int temp = parent[node];

		// Update 'minCap'        
		minCap = min(minCap, capacity[temp][node]);

		// Make 'temp' as current node      
		node = temp;
	}

	// Reinitialize node to sink node 
	node = N + M + 1;

	// Run a loop while parent of node is 'node' equal to -1, to find update edges of augmented path  
	while (parent[node] != -1)
	{
		// Store parent of 'node' in 'temp'       
		int temp = parent[node];

		// Decrease the residual capacity of edge     
		capacity[temp][node] -= minCap;

		// Increase the flow capacity     
		capacity[node][temp] += minCap;

		// Make 'node' equal to 'temp'    
		node = temp;
	}

	// Return 'minCap', the flow from current augmented path    
	return minCap;
}

// Utility function to find the max flow
int maxFlow(int s, int t, int N, int M)
{
	// Let the initial answer be 0   
	int ans = 0;

	// Take a flag 'f', initialize it to 0   
	int f = 0;

	// Run a loop while 'f' is equal to 0 (till augmented path is found)  
	while (f == 0)
	{
		// Run a loop to initialize parent and visited array      
		for (int i = 0; i < 1003; i++)
		{
			visited[i] = 0;
			parent[i] = -1;
		}

		// Check whether augmented path is present or not      
		if (getAugumentedpath(s, t))
		{
			// Update the max-flow value            
			ans += updateAugumentedPath(N, M);
		}
		else
		{
			// Make flag equal to 1 (termination condition)          
			f = 1;
		}
	}

	// Return 'ans'  
	return ans;
}

// Let maxTruck(N, M, P, D, permits, cap, reduction) 
vector<int> maxTrucks(int N, int M, int P, int D, vector<vector<int> > &permits, vector< int > &cap, vector< vector< int >> &reduction)
{
	// Run a loop from 1 to 'N' and create an undirected edge between source node(0) and all trucks  
	for (int i = 1; i <= N; i++)
	{
		graph[0].push_back(i);

		graph[i].push_back(0);

		// Mark capacity of edge equal to 1      
		capacity[0][i] = 1;
	}

	// Run a loop from 1 to 'P' and create an undirected edge between trucks and permitted path    
	for (int i = 1; i <= P; i++)
	{
		int u, v;	// Store 'truck' in 'u'      
		u = permits[i - 1][0];

		// Store 'path' in 'v'      
		v = permits[i - 1][1];

		// Truck --- path edge     
		graph[u].push_back(v + N);
		graph[v + N].push_back(u);

		// Mark capacity of the edge equal to 1    
		capacity[u][v + N] = 1;
	}

	// Run a loop from 'N' + 1 to 'N' + 'M' and create an undirected edge between path and destination (sink)  
	for (int i = N + 1; i <= N + M; i++)
	{
		// path --- sink      
		graph[i].push_back(N + M + 1);       
		graph[N + M + 1].push_back(i);

		// Store capacity of this adge equal to given capacity        
		capacity[i][N + M + 1] = cap[i - N - 1];
	}

	// Run a loop from 1 to 'D' reduce the capacity of each path for 'D' days    
	for (int i = 1; i <= D; i++)
	{
		R[i] = reduction[i - 1][0];
		C[i] = reduction[i - 1][1];

		capacity[N + R[i]][N + M + 1] -= C[i];
	}

	// Call maxFlow function and store the initial flow in 'initialMaxFlow' variable  
	int initialMaxFlow = maxFlow(0, N + M + 1, N, M);	// Take an array to store answer   
	vector<int> ans;	// Run a loop from 'D' to 1   
	while (D > 0)
	{
		// Increament the capacity of path 'R[D]'      
		capacity[N + R[D]][N + M + 1] += C[D];	// Update the flow in graph by calling function 'maxFlow'      
		initialMaxFlow += maxFlow(0, N + M + 1, N, M);

		// Push back into 'ans'        
		ans.push_back(initialMaxFlow);

		D--;
	}	// Revese the 'ans' array    
	reverse(ans.begin(), ans.end());

	// Return 'ans'   
	return ans;
}
