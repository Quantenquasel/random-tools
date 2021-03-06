
#ifndef TU01_SHA1_H
#define TU01_SHA1_H
#include "gdef.h"


typedef struct
{
   uint32_t state[5];
   uint32_t count[2];
   unsigned char buffer[64];
} SHA1_CTX;


void SHA1Init (SHA1_CTX * context);
void SHA1Update (SHA1_CTX * context, const unsigned char data[], uint32_t len);
void SHA1Final (unsigned char digest[20], SHA1_CTX * context);

#endif

