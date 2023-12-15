#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Linux Kernel and CPU Information Reporter\n");

    // Kernel Version and System Information
    system("uname -a");

    // CPU Information
    system("lscpu");

    return 0;
}
