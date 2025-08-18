void sortRow(char* row) {
    int len = strlen(row);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (row[i] > row[j]) {
                char temp = row[i];
                row[i] = row[j];
                row[j] = temp;
            }
        }
    }
}

char* gridChallenge(int grid_count, char** grid) {
    for (int i = 0; i < grid_count; i++) {
        sortRow(grid[i]);
    }

    // Step 2: Check columns
    int len = strlen(grid[0]);
    for (int col = 0; col < len; col++) {
        for (int row = 1; row < grid_count; row++) {
            if (grid[row][col] < grid[row - 1][col]) {
                return "NO";
            }
        }
    }

    return "YES";
}