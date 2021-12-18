/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2020-2021. All rights reserved.
 * Description: model debugger client implementation
 */
#ifndef MODEL_DEBUGGER_H
#define MODEL_DEBUGGER_H
#include "graph/graph.h"
#include "graph/graph_api_export.h"

namespace hiai {
class GRAPH_API_EXPORT ModelDumper {
public:
    bool SaveToFile(const ge::Graph& irGraph, std::string& file);

public:
    ModelDumper() = default;
    ~ModelDumper() = default;
};
}  // namespace hiai
#endif  // MODEL_DEBUGGER_H