/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: hiai foundation dl helper
 */
#ifndef FRAMEWORK_C_HIAI_FOUNDATION_DL_HELPER_H
#define FRAMEWORK_C_HIAI_FOUNDATION_DL_HELPER_H
#include <stdint.h>

#include "hiai_c_api_export.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    HIAI_NOT_SUPPORT_NPU = 0,
    HIAI_SUPPORT_NPU
} HIAI_NPU_SUPPORT_STATE;

AICP_C_API_EXPORT void HIAI_Foundation_Init();
AICP_C_API_EXPORT void HIAI_Foundation_Deinit();

AICP_C_API_EXPORT void* HIAI_Foundation_GetSymbol(const char* symbolName);

AICP_C_API_EXPORT HIAI_NPU_SUPPORT_STATE HIAI_Foundation_IsNpuSupport();

#ifdef __cplusplus
}
#endif

#endif
