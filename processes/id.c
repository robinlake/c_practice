// https://www.youtube.com/watch?v=PZrQ4eGm-hM&list=PLfqABt5AS4FkW5mOn2Tn9ZZLLDwA3kZUY&index=4
/*
If a parent process returns before the child process terminates, 
it is assigned a new parent process.
In any programs that use the fork function, you must wait
until the child processes terminate to terminate the parent
process. Failure to do so will result in a memory leak.
*/
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int id = fork();
    if (id == 0)
    {
        sleep(1);
    }
    printf("Current ID: %d, parent ID: %d\n", getpid(), getppid());
    // wait(NULL);
    int res = wait(NULL);
    if (res == -1)
    {
        printf("No children to wait for\n");
    }
    else
    {
        printf("%d finished execution\n", res);
    }
    return 0;
}