#ifndef CRYPTONITE_KDF_H
#define CRYPTONITE_KDF_H

#include "byte_array.h"

#ifdef  __cplusplus
extern "C" {
#endif

typedef enum Pbkdf2HmacId_st {
    PBKDF2_GOST_HMAC_ID = 0,
    PBKDF2_SHA1_HMAC_ID = 1,
    PBKDF2_SHA224_HMAC_ID = 2,
    PBKDF2_SHA256_HMAC_ID = 3,
    PBKDF2_SHA384_HMAC_ID = 4,
    PBKDF2_SHA512_HMAC_ID = 5
} Pbkdf2HmacId;

typedef enum Pbkdf1HashId_st {
    PBKDF1_GOST_HASH_ID = 0,
    PBKDF1_SHA1_HASH_ID = 1,
    PBKDF1_MD5_HASH_ID = 2
} Pbkdf1HashId;

CRYPTONITE_EXPORT int kdf_pbkdf2(const char *pass, const ByteArray *salt, unsigned long iterations,
        size_t key_len, Pbkdf2HmacId id, ByteArray **dk);

CRYPTONITE_EXPORT int kdf_pbkdf1(const char *pass, const ByteArray *salt, unsigned long iterations,
        size_t key_len, Pbkdf1HashId id, ByteArray **dk);

#ifdef  __cplusplus
}
#endif

#endif //CRYPTONITE_KDF_H
