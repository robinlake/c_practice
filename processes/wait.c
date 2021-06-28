// https://www.youtube.com/watch?v=tcYo6hipaSA&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=2
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])
{
    int id = fork();
    int n;
    if (id == 0)
    {
        n = 1;
    }
    else
    {
        n = 6;
    }
    if (id != 0)
    {
        wait();
    }

    int i;
    for (i = n; i < n + 5; i++)
    {
        printf("%d", i);
        // fflush(stdout);
    }
    if (id != 0)
    {
        printf("\n");
    }
    return 0;
}