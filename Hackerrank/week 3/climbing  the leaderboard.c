int* climbingLeaderboard(int ranked_count, int* ranked, int player_count, int* player, int* result_count) {
    int* unique = malloc(ranked_count * sizeof(int));
    int u_count = 0;

    unique[u_count++] = ranked[0];
    for (int i = 1; i < ranked_count; i++) {
        if (ranked[i] != ranked[i - 1]) {
            unique[u_count++] = ranked[i];
        }
    }

    int* result = malloc(player_count * sizeof(int));
    *result_count = player_count;

    int i = u_count - 1; 
    for (int j = 0; j < player_count; j++) {
        while (i >= 0 && player[j] >= unique[i]) {
            i--;
        }
        result[j] = i + 2; 
    }

    return result;
}