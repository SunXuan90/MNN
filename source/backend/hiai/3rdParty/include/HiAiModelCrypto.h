/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2019. All rights reserved.
 * Description: gcm key generate
 */
#ifndef _HIAI_MODEL_CRYPTO_H_
#define _HIAI_MODEL_CRYPTO_H_

#include "compatible/hiai_base_types_cpt.h"

namespace hiai {
class HiAiModelCryptoImpl;
class HiAiModelCrypto {
public:
    static AIStatus GetEncryptedModelSize(const uint32_t inputModelSize, uint32_t* encryptedModelSize);

    static AIStatus EncryptModel(
        const char* password, const uint8_t* inputModelBuf, uint32_t inputModelLen, uint8_t* outputModelBuf);

    static AIStatus GetDecryptedModelSize(const uint32_t inputModelSize, uint32_t* encryptedModelSize);

    static AIStatus DecryptModel(
        const char* password, const uint8_t* inputModelBuf, uint32_t inputModelLen, uint8_t* outputModelBuf);

private:
    friend class HiAiModelCryptoImpl;
    static HiAiModelCryptoImpl modelCryptoImpl_;
};
}; // namespace hiai

#endif
