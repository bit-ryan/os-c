#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    // Process Creation
    pid_t child_pid = fork();

    if (child_pid == 0) {
        // Child process
        printf("Child Process: PID=%d, Parent PID=%d\n", getpid(), getppid());
    } else if (child_pid > 0) {
        // Parent process
        printf("Parent Process: PID=%d\n", getpid());
        wait(NULL); // Wait for the child to finish
    } else {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // List processes
    system("ps aux");

    // Kill a process (replace PID with an actual process ID)
    system("kill -9 PID");

    // Sleep for 5 seconds
    sleep(5);

    return 0;
}
