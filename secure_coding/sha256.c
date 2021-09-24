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
