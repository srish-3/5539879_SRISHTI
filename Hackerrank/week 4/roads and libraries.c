long roadsAndLibraries(int n, int c_lib, int c_road, int cities_rows, int cities_columns, int** cities) {
if (c_lib <= c_road) {
        return (long)n * c_lib;
    }

    // Build adjacency list
    int** adj = (int*)malloc((n + 1) * sizeof(int));
    int* adj_size = (int*)calloc(n + 1, sizeof(int));
    for (int i = 0; i <= n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int)); // Max possible connections
    }

    for (int i = 0; i < cities_rows; i++) {
        int u = cities[i][0];
        int v = cities[i][1];
        adj[u][adj_size[u]++] = v;
        adj[v][adj_size[v]++] = u;
    }

    // DFS to find connected components
    int* visited = (int*)calloc(n + 1, sizeof(int));
    int components = 0;

    void dfs(int node) {
        visited[node] = 1;
        for (int i = 0; i < adj_size[node]; i++) {
            int neighbor = adj[node][i];
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    // Cleanup
    for (int i = 0; i <= n; i++) {
        free(adj[i]);
    }
    free(adj);
    free(adj_size);
    free(visited);

    return (long)components * c_lib + (long)(n - components) * c_road;
}