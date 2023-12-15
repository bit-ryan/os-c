#include <stdlib.h>

int main() {
    // Change file mode
    system("chmod 755 file.txt"); // Change file permissions to rwxr-xr-x

    // Change file owner
    system("chown user:group file.txt"); // Change file owner to 'user' and group to 'group'

    // Change file group
    system("chgrp newgroup file.txt"); // Change file group to 'newgroup'

    return 0;
}
