#pragma once

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <utility>
#include "logger.h"

class IObject;

class Container {
  std::unordered_map<std::type_index, std::unique_ptr<IObject>> memory;

 public:
  template<typename TObject, typename... Args>
  void Put(Args&&... args) {
    memory[typeid(TObject)] = std::make_unique<TObject>(std::forward<Args>(args)...);
  }

  template<typename TObject>
  TObject* Get() const {
    if (memory.count(typeid(TObject)) == 0) {
      LOG_ERROR("<%s> not found in the Container", typeid(TObject).name());
      return nullptr;
    }
    return dynamic_cast<TObject*>(memory.at(typeid(TObject)).get());
  }
};
