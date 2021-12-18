/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: init
 */
#ifndef FRAMEWORK_C_HIAI_INIT_H
#define FRAMEWORK_C_HIAI_INIT_H
#include <stdint.h>

#include "hiai_c_api_export.h"
#include "hiai_error_types.h"

#ifdef __cplusplus
extern "C" {
#endif

AICP_C_API_EXPORT HIAI_Status HIAI_Init();
AICP_C_API_EXPORT void HIAI_Deinit();

#ifdef __cplusplus
}
#endif

#endif
