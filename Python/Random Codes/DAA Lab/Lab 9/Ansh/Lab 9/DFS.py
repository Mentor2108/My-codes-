from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self, u, v):
        self.graph[u].append(v)
 
    def DFSUtil(self, v, visited):
        visited.add(v)
        print(v, end=' ')
        for neighbour in self.graph[v]:
            if neighbour not in visited:
                self.DFSUtil(neighbour, visited)

    def DFS(self, v):
        visited = set()
        self.DFSUtil(v, visited)

n = int(input("Enter vertices: "))
e = int(input("Enter edges: "))

g = Graph()
for i in range(e):
    a, b = map(int, input("Enter the two vertices where edge is located: ").split())
    g.addEdge(a, b)

print ("Following is Depth First Traversal: ", end = "")
g.DFS(0) 