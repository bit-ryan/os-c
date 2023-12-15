#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("Memory Information Reporter\n");

    // Display memory information using the free command
    system("free -h");

    return 0;
}
