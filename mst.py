import heapq
from collections import defaultdict


class Graph:

    def __init__(self,Vertices):
        self.V = Vertices
        self.Graph = defaultdict(list)

    def add_edges(self,u,v,weight):
        self.Graph[u].append((v,weight))
        self.Graph[v].append((u,weight))

    def mst(self):
        visited = [False]*self.V
        min_heap = [(0,0,-1)]
        mst_edges = []
        mst_weight = 0

        while min_heap:
            weight,u,parent = heapq.heappop(min_heap)
            if(visited[u]):
                continue

            visited[u] = True
            mst_weight += weight
            if(parent != -1):
                mst_edges.append((weight,u,parent))

            for v,w in self.Graph[u]:
                if not visited[v]:
                    heapq.heappush(min_heap,(w,v,u))

                
        print("Edges in mst: ")
        for u,v,w in mst_edges:
            print(f"{u}---{v}: {w}")

        print(f"Total weight is: {mst_weight}")

g = Graph(5)  # Create a graph with 5 vertices
g.add_edges(0, 1, 2)  # Add edges with weights
g.add_edges(0, 3, 6)
g.add_edges(1, 2, 3)
g.add_edges(1, 3, 8)
g.add_edges(1, 4, 5)
g.add_edges(2, 4, 7)
g.add_edges(3, 4, 9)

g.mst()



