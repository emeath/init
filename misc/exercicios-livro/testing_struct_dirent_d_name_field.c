#include <stdio.h>

// take a look at the struct dirent
// you can see that d_name is a string alocated staticaly (!dinamically)
// see at: /usr/include/x86_64-linux-gnu/bits/dirent.h
/*

struct dirent
  {
#ifndef __USE_FILE_OFFSET64
    __ino_t d_ino;
    __off_t d_off;
#else
    __ino64_t d_ino;
    __off64_t d_off;
#endif
    unsigned short int d_reclen;
    unsigned char d_type;
    char d_name[256];       // We must not include limits.h!
  };


*/

int main()
{
    char filename[257];
    int i;
    for(i = 0; i < 256; ++i)
    {
        filename[i] = 'A';
    }
    filename[i] = '\0';
    FILE *file = fopen(filename, "w");
    if (NULL == file) {
        perror("error creating the file...");
        return 1;
    }
    else {
        printf("Success!\n");
        fclose(file);
    }

    return 0;
}
