/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: model manager types
 */
#ifndef HIAI_MODEL_MANAGER_MODEL_EXECUTE_TYPES_H
#define HIAI_MODEL_MANAGER_MODEL_EXECUTE_TYPES_H
#include <string>
#include <map>
#include "model_builder_types.h"
namespace hiai {
enum ModelPriority {
    PRIORITY_HIGH = 5,
    PRIORITY_MIDDLE,
    PRIORITY_LOW,
};

enum class PerfMode {
    LOW = 1,
    MIDDLE,
    HIGH,
    EXTREME_HIGH,
};

struct ModelInitOptions {
    PerfMode perfMode = PerfMode::MIDDLE;
    ModelBuildOptions buildOptions;
};

class Context {
public:
    std::string GetValue(const std::string& key) const;
    void SetValue(const std::string& key, const std::string& value);
    void RemoveValue(const std::string& key);
    const std::map<std::string, std::string>& GetContent() const;

private:
    std::map<std::string, std::string> paras_;
};

inline std::string Context::GetValue(const std::string& key) const
{
    auto it = paras_.find(key);
    return it != paras_.end() ? it->second : "";
}

inline void Context::SetValue(const std::string& key, const std::string& value)
{
    paras_[key] = value;
}

inline void Context::RemoveValue(const std::string& key)
{
    paras_.erase(key);
}

inline const std::map<std::string, std::string>& Context::GetContent() const
{
    return paras_;
}
} // namespace hiai
#endif
