/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: model tensor info(deprecated)
 */
#ifndef FRAMEWORK_C_LEGACY_HIAI_MODEL_TENSOR_INFO_H
#define FRAMEWORK_C_LEGACY_HIAI_MODEL_TENSOR_INFO_H

#include "c/hiai_c_api_export.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int inputCnt;
    int outputCnt;
    int* inputShape;
    int* outputShape;
} HIAI_ModelTensorInfo;

AICP_C_API_EXPORT void HIAI_ModelManager_releaseModelTensorInfo(HIAI_ModelTensorInfo* modelTensor);

// v2
typedef enum {
    HIAI_IO_INPUT = 0,
    HIAI_IO_OUTPUT = 1,

    HIAI_IO_INVALID = 255,
} HIAI_IO_TYPE;

typedef struct HIAI_TensorDescriptionV2 HIAI_TensorDescriptionV2;
typedef struct HIAI_ModelTensorInfoV2 HIAI_ModelTensorInfoV2;

AICP_C_API_EXPORT void HIAI_ModelManager_releaseModelTensorInfoV2(HIAI_ModelTensorInfoV2* modelTensor);

AICP_C_API_EXPORT int HIAI_ModelTensorInfoV2_getIOCount(const HIAI_ModelTensorInfoV2* tensorInfo, HIAI_IO_TYPE type);

AICP_C_API_EXPORT HIAI_TensorDescriptionV2* HIAI_ModelTensorInfoV2_getTensorDescription(
    const HIAI_ModelTensorInfoV2* tensorInfo, HIAI_IO_TYPE type, int index);

AICP_C_API_EXPORT HIAI_TensorBuffer* HIAI_TensorBuffer_createFromTensorDescV2(HIAI_TensorDescriptionV2* tensor);

AICP_C_API_EXPORT int HIAI_TensorDescriptionV2_getDimensions(
    const HIAI_TensorDescriptionV2* tensorDesc, int* n, int* c, int* h, int* w);
AICP_C_API_EXPORT const char* HIAI_TensorDescriptionV2_getName(const HIAI_TensorDescriptionV2* tensorDesc);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // FRAMEWORK_C_LEGACY_HIAI_MODEL_TENSOR_INFO_H
