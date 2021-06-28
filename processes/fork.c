//https://www.youtube.com/watch?v=cex9XrZCU14&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=1
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// int main(int argc, char *argv[])
// {
//     int id = fork();
//     printf("Hello world from id: %d\n", id);
//     if (id == 0)
//     {
//         printf("Hello from child process\n");
//     }
//     else
//     {
//         printf("Hello from the main process\n");
//     }
//     return 0;
// }

// int main(int argc, char *argv[])
// {
//     fork();
//     fork();
//     fork();
//     fork();
//     printf("Hello world\n");
//     return 0;
// }

int main(int argc, char *argv[])
{
    int id = fork();
    if (id != 0)
    {
        fork();
    }
    printf("Hello world\n");
    return 0;
}