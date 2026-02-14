# Program 5: Undirected Graph using Adjacency Matrix with BFS and DFS

## 1. Data Structure Definition
In this program, an undirected graph is implemented using an adjacency matrix. The adjacency matrix is a 2D array where each element adj[i][j] represents whether there is an edge between vertex i and vertex j. If the value is 1, an edge exists; otherwise, it does not.

## 2. Description of Functions

- BFS(int start)  
  This function performs Breadth First Search traversal using a queue. It explores all neighboring vertices level by level.

- DFS(int start)  
  This function performs Depth First Search traversal using recursion. It explores vertices deeply before backtracking.

## 3. Overview of main() Function
The main function takes the number of vertices and the adjacency matrix as input from the user. It then asks for the starting vertex and performs BFS and DFS traversal from that vertex.

## 4. Sample Output
```
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 0
0 1 0 0
Enter starting vertex: 0

BFS Traversal: 0 1 2 3
DFS Traversal: 0 1 3 2
```

## 5. Conclusion
This program demonstrates the implementation of an undirected graph using an adjacency matrix. It shows how BFS and DFS traversal techniques are used to visit all vertices of the graph.

