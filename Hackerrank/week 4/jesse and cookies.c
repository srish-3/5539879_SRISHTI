#define MAX_SIZE 100000

int heap[MAX_SIZE];
int heap_size = 0;

void swap(int *a, int *b) {
    int temp = *a; *a = *b; *b = temp;
}

void heapify_up(int index) {
    while (index > 0 && heap[index] < heap[(index - 1) / 2]) {
        swap(&heap[index], &heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void heapify_down(int index) {
    int smallest = index;
    int left = 2 * index + 1, right = 2 * index + 2;

    if (left < heap_size && heap[left] < heap[smallest]) smallest = left;
    if (right < heap_size && heap[right] < heap[smallest]) smallest = right;

    if (smallest != index) {
        swap(&heap[index], &heap[smallest]);
        heapify_down(smallest);
    }
}

void insert(int val) {
    heap[heap_size++] = val;
    heapify_up(heap_size - 1);
}

int extract_min() {
    if (heap_size == 0) return -1;
    int min = heap[0];
    heap[0] = heap[--heap_size];
    heapify_down(0);
    return min;
}


int cookies(int k, int A_count, int* A) {
    for (int i = 0; i < A_count; i++) insert(A[i]);

    int operations = 0;
    while (heap_size >= 2 && heap[0] < k) {
        int least = extract_min();
        int second_least = extract_min();
        int new_cookie = least + 2 * second_least;
        insert(new_cookie);
        operations++;
    }

    return (heap[0] >= k) ? operations : -1;
}

