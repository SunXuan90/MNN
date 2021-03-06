/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: tensor buffer(deprecated)
 */
#ifndef FRAMEWORK_C_LEGACY_HIAI_TENSOR_BUFFER_H
#define FRAMEWORK_C_LEGACY_HIAI_TENSOR_BUFFER_H

#include "c/hiai_c_api_export.h"
#include "c/hiai_base_types.h"
#include "HiAiModelManagerType.h"

#ifdef __cplusplus
extern "C" {
#endif

struct native_handle;
typedef const native_handle* buffer_handle_t;
struct PrivateHandleInfo;

AICP_C_API_EXPORT HIAI_TensorBuffer* HIAI_TensorBuffer_create(int n, int c, int h, int w);
AICP_C_API_EXPORT HIAI_TensorBuffer* HIAI_TensorBuffer_CreateWithDataType(
    int n, int c, int h, int w, HIAI_DataType DataType);
AICP_C_API_EXPORT HIAI_TensorBuffer* HIAI_ImageBuffer_create(int n, int h, int w, HIAI_ImageFormat imageFormat);

AICP_C_API_EXPORT HIAI_TensorBuffer* HIAI_TensorBuffer_createFromTensorDesc(HIAI_TensorDescription* tensor);

AICP_C_API_EXPORT HIAI_TensorDescription HIAI_TensorBuffer_getTensorDesc(HIAI_TensorBuffer* b);

AICP_C_API_EXPORT void* HIAI_TensorBuffer_getRawBuffer(HIAI_TensorBuffer* b);

AICP_C_API_EXPORT int HIAI_TensorBuffer_getBufferSize(HIAI_TensorBuffer* b);

AICP_C_API_EXPORT void HIAI_TensorBuffer_destroy(HIAI_TensorBuffer* b);

AICP_C_API_EXPORT HIAI_TensorBuffer* HIAI_TensorBuffer_create_v2(int n, int c, int h, int w, int size);

#ifdef DYNAMIC_BATCH
HIAI_LEGACY_API_EXPORT int HIAI_TensorBuffer_setDynamicBatch(
    HIAI_TensorBuffer* input[], int nInput, int inputIndex, int batchNumber);
#endif

#ifdef DEVICE_SUPPORT_LITENN
AICP_C_API_EXPORT HIAI_TensorBuffer* HIAI_TensorBuffer_createTensorFromNativeHandle(
    HIAI_TensorDescription* tensor, hiai::NativeHandle* nativeHandle);

AICP_C_API_EXPORT hiai::PrivateHandleInfo* HIAI_GetHandleInfo_From_BufferHandle(buffer_handle_t handle);

AICP_C_API_EXPORT void HIAI_DestroyPrivateHandle(hiai::PrivateHandleInfo* handle);
#endif

#ifdef __cplusplus
} // extern "C"
#endif

#endif // FRAMEWORK_C_LEGACY_HIAI_TENSOR_BUFFER_H
