#include <stdio.h>
#include <stdlib.h>
#include <zlib.h>
#include "decompress.h"

#define CHUNK 16384

int decompress_file(const char *infile, const char *outfile) {
    gzFile source = gzopen(infile, "rb");
    if (!source) return -1;

    FILE *dest = fopen(outfile, "wb");
    if (!dest) { gzclose(source); return -2; }

    unsigned char buffer[CHUNK];
    int bytes_read;
    while ((bytes_read = gzread(source, buffer, CHUNK)) > 0) {
        if (fwrite(buffer, 1, bytes_read, dest) != bytes_read) {
            fclose(dest);
            gzclose(source);
            return -3;
        }
    }

    fclose(dest);
    gzclose(source);
    return 0;
}
