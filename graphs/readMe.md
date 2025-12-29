# Graph Algorithms
## 1. General Traversal Algorithms
## Depth-First Search
Uses a Stack or Recursion, Good for calculating Height, Branch-by-branch traversal

## Breadth-First Search
Uses a Queue, Layer by Layer traversal 

## 2. Minimum Spanning Tree
A minimum Spanning tree is a subgraph of a given graph with minimum weight that forms a valid tree

## Prim Algorithm
Uses Priority Queue, Expands the subgraph by adding a new node in the current MST via the minimum possible edgeWeight going out from the current MST and adding all the edges going out from the new node in the priority queue.

## Kruskal Algorithm
Uses Union-Find, Starting with a forest of n-trees with single node and adding the minimum edgeWeight that connects two disjoint trees into our MST

## 3. Shortest Distance Algorithm

## Dijkstra
Starts from the source and adds a single edge with minimum weight in the graph and updates the distance 
Won't work on negative edges, Single Source


## 4. Smart Moves

## MultiSource 
Simply assume a virtual node.. Node -1 that is connected to all your source and search starting from this node

## 5. Other techniques/methods

## Topological Sort