
Task 1:

Summary: This task outlines the minimum movements required to empty a cell in the parking lot. One cell in the parking lot is empty, and one cell is designated for the camera.

- Input: User request: empty cell n (received via console).

- Output: Minimum number of movements, list of movements.

  Solution: Backtracking.

Task 2 - Part 1

Summary: This task determines the shortest path length between two selected points in the city and prints all paths with the shortest length.

Input: Number of roads between destinations, first vertex and second vertex, and the length of the road between these two vertices (repeated for the number of roads), starting point, destination (received via file/console).

Output: Length of the shortest path, paths with the shortest length.

Solution: First, the shortest path length is obtained using Dijkstra's algorithm with a greedy approach. Then, using backtracking and the DFS algorithm, all paths between the source and destination that have this length are printed.

Task 2 - Part 2: 

Summary: Starting from a source, passing through specific vertices, and returning to the source in such a way that the distance is minimized.

Input: Source, waypoints.

Output: Path length, path.

Solution: TSP 

Task 3: Road Reconstruction*

Summary: Display the minimum spanning tree of a graph representing an urban area.

Input: Number of roads between destinations, first vertex and second vertex, and the length of the road between these two vertices (repeated for the number of roads), number of locations (received via file/console).

Output: Length of the minimum spanning tree, list of vertices that need to be connected by roads.

Solution: Greedy algorithm for minimum spanning tree.

