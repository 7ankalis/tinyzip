//
// Created by salamnki on 8/17/25.
//

#ifndef TINYZIP_DECOMPRESS_H
#define TINYZIP_DECOMPRESS_H

// Decompress a file from 'infile' to 'outfile'. Returns 0 on success, negative on error.
int decompress_file(const char *infile, const char *outfile);

#endif // TINYZIP_DECOMPRESS_H