#!/bin/bash
cmake ../../../ \
-DCMAKE_GENERATOR="Ninja" \
-DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
-DCMAKE_BUILD_TYPE=Release \
-DANDROID_ABI="arm64-v8a" \
-DANDROID_STL=c++_static \
-DMNN_USE_LOGCAT=true \
-DMNN_BUILD_BENCHMARK=OFF \
-DMNN_USE_SSE=OFF \
-DMNN_SUPPORT_BF16=ON \
-DMNN_BUILD_TEST=OFF \
-DANDROID_NATIVE_API_LEVEL=android-21  \
-DMNN_BUILD_FOR_ANDROID_COMMAND=true \
-DMNN_OPENCL=ON \
-DMNN_NPU=ON \
-DMNN_VULKAN=ON \
-DNATIVE_LIBRARY_OUTPUT=. -DNATIVE_INCLUDE_OUTPUT=. $1 $2 $3

ninja -j8
