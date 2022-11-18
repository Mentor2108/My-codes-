from collections import defaultdict
class Graph:
    def __init__(self):
        self.graph = defaultdict(list)

    def addEdge(self,u,v):
        self.graph[u].append(v)

    def BFS(self, s):
        visited = [False] * (max(self.graph) + 1)
        queue = []
        queue.append(s)
        visited[s] = True
        while queue:
            s = queue.pop(0)
            print (s, end = " ")
            for i in self.graph[s]:
                if visited[i] == False:
                    queue.append(i)
                    visited[i] = True

n = int(input("Enter vertices: "))
e = int(input("Enter edges: "))

g = Graph()
for i in range(e):
    a, b = map(int, input("Enter the two vertices where edge is located: ").split())
    g.addEdge(a, b)

print ("Following is Breadth First Traversal: ", end = "")
g.BFS(0)