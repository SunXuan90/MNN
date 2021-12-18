/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: HIAIModelManagerType(deprecated)
 */
#ifndef FRAMEWORK_C_LEGACY_MODEL_MANAGER_TYPE_H
#define FRAMEWORK_C_LEGACY_MODEL_MANAGER_TYPE_H

#include "c/hiai_model_manager.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef HIAI_PerfMode HIAI_DevPerf;

typedef struct HIAI_TensorDescription {
    int number;
    int channel;
    int height;
    int width;
    HIAI_DataType dataType; /* optional */
} HIAI_TensorDescription;

#define HIAI_TENSOR_DESCRIPTION_INIT \
    { \
        0, 0, 0, 0, HIAI_DATATYPE_FLOAT32 \
    }

typedef struct HIAI_TensorBuffer {
    HIAI_TensorDescription desc;
    int size;
    void* data;
    void* impl; /* DON'T MODIFY */
    const char* name;
} HIAI_TensorBuffer;

typedef enum {
    HIAI_MODELTYPE_ONLINE = 0,
    HIAI_MODELTYPE_OFFLINE
} HIAI_ModelType;

#ifdef __cplusplus
}
#endif

#endif
