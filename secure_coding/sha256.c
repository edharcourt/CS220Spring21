#include <openssl/sha.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sha256.h"

// create a static library 
//  ar -rcs libsha256.a sha256.o

// Modified from https://stackoverflow.com/a/63397742
// buff must be at least 65 bytes, enough room for the hash and
// a null terminating byte.
// return buff
char *sha256(const char *str, char buff[]) {
  SHA256_CTX c;
  unsigned char digest[ SHA256_DIGEST_LENGTH ];
  SHA256_Init(&c);
  SHA256_Update(&c, str, strlen(str));
  SHA256_Final (digest, &c );

  // fill in two hex characters at a time converting the byte
  // to hex.
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++ )
    sprintf( buff + (i << 1), "%02x", digest[ i ] );

  buff[64] = 0;  // null terminate
  return buff;
}

//int main() {
//    const char *s = "caddyshack";
//    char buff[65];
//    printf("%s\n", sha256(s, buff));
//}

/*
 
   void sha256_hash_string (unsigned char hash[SHA256_DIGEST_LENGTH], char outputBuffer[65])
{
    int i = 0;

    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }

    outputBuffer[64] = 0;
}


void sha256_string(char *string, char outputBuffer[65])
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, string, strlen(string));
    SHA256_Final(hash, &sha256);
    int i = 0;
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(outputBuffer + (i * 2), "%02x", hash[i]);
    }
    outputBuffer[64] = 0;
}

int sha256_file(char *path, char outputBuffer[65])
{
    FILE *file = fopen(path, "rb");
    if(!file) return -534;

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    const int bufSize = 32768;
    unsigned char *buffer = malloc(bufSize);
    int bytesRead = 0;
    if(!buffer) return ENOMEM;
    while((bytesRead = fread(buffer, 1, bufSize, file)))
    {
        SHA256_Update(&sha256, buffer, bytesRead);
    }
    SHA256_Final(hash, &sha256);

    sha256_hash_string(hash, outputBuffer);
    fclose(file);
    free(buffer);
    return 0;
}

 */
