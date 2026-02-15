# Program 7: Dijkstra's Algorithm

## 1. Data Structure Definition
The graph is represented using a weighted adjacency matrix. 
Each element graph[i][j] represents the weight of the edge 
between vertex i and vertex j. If there is no edge, the value is 0.

Two arrays are used:
- dist[] to store shortest distances
- visited[] to mark visited vertices

## 2. Description of Functions

- minDistance()  
  Finds the vertex with the minimum distance value 
  that has not been visited.

- dijkstra()  
  Implements Dijkstra’s algorithm to calculate 
  shortest path from the source to all vertices.

## 3. Overview of main()
The main function takes the number of vertices and the weighted adjacency matrix as input. 
It then asks for the source vertex and calls the dijkstra() function to compute shortest paths.

## 4. Sample Output
```
Enter number of vertices: 4
Enter weighted adjacency matrix:
0 1 4 0
1 0 2 6
4 2 0 3
0 6 3 0
Enter source vertex: 0

Shortest distances from vertex 0:
To vertex 0 = 0
To vertex 1 = 1
To vertex 2 = 3
To vertex 3 = 6
```
git add prog_7.c doc_7.md
## 5. Conclusion
This program demonstrates the implementation of Dijkstra’s algorithm 
to find shortest paths in a weighted graph using adjacency matrix representation.




