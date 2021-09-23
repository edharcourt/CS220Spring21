#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>

// https://stackoverflow.com/a/63397742

char *sha256(const char *str) {

  SHA256_CTX c;
  unsigned char digest[ SHA256_DIGEST_LENGTH ];
  char *buff = (char*) malloc(65);  // 64*4 = 256 bits plus one null terminating byte
  SHA256_Init(&c);
  SHA256_Update(&c, str, strlen(str));
  SHA256_Final (digest, &c );

  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++ )
    sprintf( out + (i << 1), "%02x", digest[ i ] );

  out[64] = 0;  // null terminate
  return out;
}