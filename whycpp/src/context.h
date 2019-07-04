#pragma once

#include <memory>
#include <typeindex>
#include <unordered_map>
#include <utility>
#include "logger.h"

class IObject;
/**
 * @addtogroup ApplicationInternals
 * @ingroup Internals
 *
 * @{
 */

/**
 * @class Context
 *
 * Context implementation is hidden from the users, because it contains some low-level logic.
 * Users are supposed to use a forward declaration of the context and functions
 * which receives Context as a parameter.
 *
 * @see WHYCPP_PublicAPI
 */
class Context {
  std::unordered_map<std::type_index, std::unique_ptr<IObject>> memory;

 public:
  Context() {
    LOG_DEBUG("Context created");
  }
  virtual ~Context() {
    LOG_DEBUG("Context destroyed");
  }
  template<typename TObject, typename... Args>
  TObject* Put(Args&&... args) {
    memory[typeid(TObject)] = std::make_unique<TObject>(std::forward<Args>(args)...);
    return Get<TObject>();
  }

  template<typename TObject, typename TAsObject, typename... Args>
  TAsObject* PutAs(Args&&... args) {
    memory[typeid(TAsObject)] = std::make_unique<TObject>(std::forward<Args>(args)...);
    return Get<TAsObject>();
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

/** @} */
