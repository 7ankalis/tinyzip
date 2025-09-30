#include <stdio.h>
#include <string.h>
#include "compress.h"
#include "decompress.h"
#include "optimize.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <command> <file>\n", argv[0]);
        printf("Commands: compress, decompress, optimize\n");
        return 1;
    }

    if (strcmp(argv[1], "compress") == 0) {
        char out[256];
        optimize_compression();
        snprintf(out, sizeof(out), "%s.gz", argv[2]);
        if (compress_file(argv[2], out) == 0)
            printf("[+] File compressed to %s\n", out);
    }
    else if (strcmp(argv[1], "decompress") == 0) {
        char out[256];
        optimize_compression();
        snprintf(out, sizeof(out), "%s.out", argv[2]);
        if (decompress_file(argv[2], out) == 0)
            printf("[+] File decompressed to %s\n", out);
    }
    else if (strcmp(argv[1], "optimize") == 0) {
        optimize_compression();
    }
    else {
        printf("Unknown command\n");
    }
    //optimize_compression();
    return 0;
}
