//
// Created by salamnki on 8/17/25.
//

#ifndef TINYZIP_COMPRESS_H
#define TINYZIP_COMPRESS_H

// Compress a file from 'infile' to 'outfile'. Returns 0 on success, negative on error.
int compress_file(const char *infile, const char *outfile);

#endif // TINYZIP_COMPRESS_H