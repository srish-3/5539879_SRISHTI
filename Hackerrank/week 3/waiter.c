bool is_prime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0) return false;
    return true;
}

void generate_primes(int* primes, int q) {
    int count = 0, num = 2;
    while (count < q) {
        if (is_prime(num)) {
            primes[count++] = num;
        }
        num++;
    }
}

typedef struct {
    int* data;
    int top;
} Stack;

void push(Stack* s, int val) {
    s->data[++(s->top)] = val;
}

int pop(Stack* s) {
    return s->data[(s->top)--];
}

bool is_empty(Stack* s) {
    return s->top == -1;
}


int* waiter(int number_count, int* number, int q, int* result_count) {
    int* primes = malloc(q * sizeof(int));
    generate_primes(primes, q);

    Stack* A = malloc(sizeof(Stack));
    A->data = malloc(number_count * sizeof(int));
    A->top = -1;

    for (int i = 0; i < number_count; i++)
        push(A, number[i]);

    int* answers = malloc(number_count * sizeof(int));
    int ans_index = 0;

    for (int i = 0; i < q; i++) {
        Stack* B = malloc(sizeof(Stack));
        B->data = malloc(number_count * sizeof(int));
        B->top = -1;

        Stack* next_A = malloc(sizeof(Stack));
        next_A->data = malloc(number_count * sizeof(int));
        next_A->top = -1;

        while (!is_empty(A)) {
            int val = pop(A);
            if (val % primes[i] == 0)
                push(B, val);
            else
                push(next_A, val);
        }

        while (!is_empty(B))
            answers[ans_index++] = pop(B);

        free(A->data);
        free(A);
        free(B->data);
        free(B);

        A = next_A;
    }

    while (!is_empty(A))
        answers[ans_index++] = pop(A);

    free(A->data);
    free(A);
    free(primes);

    *result_count = ans_index;
    return answers;
}

