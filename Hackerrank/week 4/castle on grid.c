#define MAX 100

typedef struct {
    int x, y, moves;
} Point;

int visited[MAX][MAX];

int minimumMoves(int grid_count, char** grid, int startX, int startY, int goalX, int goalY) {
    Point queue[MAX * MAX];
    int front = 0, rear = 0;

    queue[rear++] = (Point){startX, startY, 0};
    visited[startX][startY] = 1;

    while (front < rear) {
        Point curr = queue[front++];

        if (curr.x == goalX && curr.y == goalY) {
            return curr.moves;
        }

        // Move Up
        for (int i = curr.x - 1; i >= 0 && grid[i][curr.y] == '.'; i--) {
            if (!visited[i][curr.y]) {
                visited[i][curr.y] = 1;
                queue[rear++] = (Point){i, curr.y, curr.moves + 1};
            }
        }

        
        for (int i = curr.x + 1; i < grid_count && grid[i][curr.y] == '.'; i++) {
            if (!visited[i][curr.y]) {
                visited[i][curr.y] = 1;
                queue[rear++] = (Point){i, curr.y, curr.moves + 1};
            }
        }

        
        for (int j = curr.y - 1; j >= 0 && grid[curr.x][j] == '.'; j--) {
            if (!visited[curr.x][j]) {
                visited[curr.x][j] = 1;
                queue[rear++] = (Point){curr.x, j, curr.moves + 1};
            }
        }


        for (int j = curr.y + 1; j < grid_count && grid[curr.x][j] == '.'; j++) {
            if (!visited[curr.x][j]) {
                visited[curr.x][j] = 1;
                queue[rear++] = (Point){curr.x, j, curr.moves + 1};
            }
        }
    }

    return -1; 


