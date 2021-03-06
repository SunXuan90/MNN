/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: mem buffer(deprecated)
 */
#ifndef FRAMEWORK_C_LEGACY_HIAI_MEM_BUFFER_H
#define FRAMEWORK_C_LEGACY_HIAI_MEM_BUFFER_H

#include "c/hiai_c_api_export.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
    HIAI_FRAMEWORK_NONE = 0,
    HIAI_FRAMEWORK_TENSORFLOW = 1,
    HIAI_FRAMEWORK_CAFFE = 3,
    HIAI_FRAMEWORK_TENSORFLOW_8BIT,
    HIAI_FRAMEWORK_CAFFE_8BIT,
    HIAI_FRAMEWORK_OFFLINE,
    HIAI_FRAMEWORK_IR,
    HIAI_FRAMEWORK_INVALID,
} HIAI_Framework;

struct HIAI_MemBuffer {
    unsigned int size;
    void* data;
};

// ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//      read an onlineModel file into a MemBuffer
// Params
//      @path: an onlineModel file. (eg: xxx.prototxt / xxx.caffemodel / tf_param.txt)
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
AICP_C_API_EXPORT HIAI_MemBuffer* HIAI_MemBuffer_create_from_file(const char* path);

// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//      read an onlineModel buffer into a MemBuffer
// Params
//      @buffer: a buffer stores an onlineModel file content.
//      @size: buffer size.
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
AICP_C_API_EXPORT HIAI_MemBuffer* HIAI_MemBuffer_create_from_buffer(void* buffer, const unsigned int size);

// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//      read a tensorflow pb file, covnert it to a GraphDef-format MemBuffer
// Params
//      @path: tensorflow pb file. (eg: xxx.pb)
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
AICP_C_API_EXPORT HIAI_MemBuffer* HIAI_ReadBinaryProto_from_file(const char* path);

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//      read a tensorflow pb buffer, covnert it to a GraphDef-format MemBuffer
// Params
//      @buffer: a buffer stores a tensorflow pb file content.
//      @size: buffer size
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
AICP_C_API_EXPORT HIAI_MemBuffer* HIAI_ReadBinaryProto_from_buffer(void* buffer, const unsigned int size);

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//      create an offlineModel MemBuffer through an onlineModel
// Params
//      @frameworkType: frameworkType. (eg: CAFFE / TENSORFLOW)
//      @inputModelBuffers: a full-onlineModel
//      @inputModelBuffersNum: the number of inputModelBuffers
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
AICP_C_API_EXPORT HIAI_MemBuffer* HIAI_MemBuffer_create(
    HIAI_Framework frameworkType, HIAI_MemBuffer* inputModelBuffers[], const unsigned int inputModelBuffersNum);

// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//      create an offlineModel MemBuffer through an onlineModel
// Params
//      @frameworkType: frameworkType. (eg: CAFFE / TENSORFLOW)
//      @inputModelBuffers: a full-onlineModel
//      @inputModelBuffersNum: the number of inputModelBuffers
//      @inputModelSize: set it zero to auto compute buffer size or set it positive number which allocate directly
// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
AICP_C_API_EXPORT HIAI_MemBuffer* HIAI_MemBuffer_createV2(HIAI_Framework frameworkType,
    HIAI_MemBuffer* inputModelBuffers[], unsigned int inputModelBuffersNum, unsigned int inputModelSize);

// ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//      destroy a MemBuffer
// Params
//      @membuf: MemBuffer
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
AICP_C_API_EXPORT void HIAI_MemBuffer_destroy(HIAI_MemBuffer* membuf);

// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Description
//      export a offlineModel file through offlineModel MemBuffer
// Params
//      @membuf: offlineModel MemBuffer
//      @buildSize: the actual offlineModel size.
//      @buildPath: the path of to-export offlineModel.
// //////////////////////////////////////////////////////////////////////////////////////////////////////////////
AICP_C_API_EXPORT bool HIAI_MemBuffer_export_file(
    HIAI_MemBuffer* membuf, const unsigned int buildSize, const char* buildPath);

#ifdef __cplusplus
} // extern "C"
#endif

#endif // FRAMEWORK_C_LEGACY_HIAI_MEM_BUFFER_H
