#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "compress.h"

#define CHUNK 16384

int compress_file(const char *infile, const char *outfile) {
    FILE *source = fopen(infile, "rb");
    if (!source) return -1;

    gzFile dest = gzopen(outfile, "wb");
    if (!dest) { fclose(source); return -2; }

    unsigned char buffer[CHUNK];
    int bytes_read;
    while ((bytes_read = fread(buffer, 1, CHUNK, source)) > 0) {
        if (gzwrite(dest, buffer, bytes_read) != bytes_read) {
            fclose(source);
            gzclose(dest);
            return -3;
        }
    }

    fclose(source);
    gzclose(dest);
    return 0;
}
