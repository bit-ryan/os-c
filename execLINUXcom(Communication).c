#include <stdlib.h>

int main() {
    // Input-output redirection
    system("echo 'Hello' > output.txt"); // Redirect output to a file

    // Pipe
    system("echo 'Hello' | wc"); // Pipe the output of one command to another

    return 0;
}
