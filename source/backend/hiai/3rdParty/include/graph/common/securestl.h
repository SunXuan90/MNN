/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2017-2021. All rights reserved.
 * Description: securestl
 */

#ifndef __COMMON_SECURESTL_H__
#define __COMMON_SECURESTL_H__
#include <memory>
#include "aicp.h"


namespace hiai {
template <typename T, typename... Ts>
std::shared_ptr<T> make_shared_nothrow(Ts&&... params)
{
    return std::shared_ptr<T>(new (std::nothrow) T(std::forward<Ts>(params)...));
}
}
#endif
