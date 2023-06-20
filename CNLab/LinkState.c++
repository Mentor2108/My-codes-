
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

const int INF = numeric_limits<int>::max(); // Represents "infinity"

// Function to find the router with the minimum distance
int findMinDistance(int n, vector<int>& distance, vector<bool>& visited) {
    int minDistance = INF;
    int minRouter = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && distance[i] < minDistance) {
            minDistance = distance[i];
            minRouter = i;
        }
    }
    return minRouter;
}

// Function to compute the shortest paths using Dijkstra's algorithm
void dijkstra(int n, const vector<vector<int>>& matrix, int source, vector<int>& distance) {
    vector<bool> visited(n, false); // Tracks which routers have been visited
    distance[source] = 0;
    for (int i = 0; i < n; i++) {
        int u = findMinDistance(n, distance, visited);
        visited[u] = true;
        for (int v = 0; v < n; v++) {
            if (matrix[u][v] != INF && !visited[v] && distance[u] + matrix[u][v] < distance[v]) {
                distance[v] = distance[u] + matrix[u][v];
            }
        }
    }
}

int main() {
    int n; // Number of routers
    cout << "Enter the number of routers: ";
    cin >> n;

    // Initialize the adjacency matrix
    vector<vector<int>> matrix(n, vector<int>(n, INF));
    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Compute the shortest paths from each router to all others
    for (int i = 0; i < n; i++) {
        vector<int> distance(n, INF);
        dijkstra(n, matrix, i, distance);
        cout << "Shortest paths from router " << i << ":\n";
        for (int j = 0; j < n; j++) {
            if (j != i) {
                if (distance[j] == INF) {
                    cout << "Router " << j << " is not reachable\n";
                } else {
                    cout << "Router " << j << ": " << distance[j] << "\n";
                }
            }
        }
        cout << "\n";
    }

    return 0;
}


