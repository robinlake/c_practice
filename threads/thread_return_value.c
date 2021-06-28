// https://www.youtube.com/watch?v=ln3el6PR__Q&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2&index=6
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

void* roll_dice() {
    int value = (rand() % 6) + 1;
    int* result = malloc(sizeof(int));
    *result = value;
    // printf("%d\n", value);
    printf("Thread result: %p\n", result);
    return (void*) result;
}

int main(int argc, char* argv[]) {
    int* res;
    int* res2;
    srand(time(NULL));
    pthread_t th, th2;
    if (pthread_create(&th, NULL, &roll_dice, NULL) != 0) {
        return 1;
    }
    if (pthread_create(&th2, NULL, &roll_dice, NULL) != 0) {
        return 3;
    }
    if (pthread_join(th, (void**) &res) != 0) {
        return 2;
    }
    if (pthread_join(th2, (void**) &res2) != 0) {
        return 4;
    }
    printf("Main res: %p\n", res);
    printf("Result: %d\n", *res);
    printf("Main res 2: %p\n", res2);
    printf("Result 2: %d\n", *res2);
    free(res);
    free(res2);
    return 0;
}