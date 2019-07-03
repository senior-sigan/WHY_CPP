#pragma once

#include <whycpp/application_config.h>
#include <memory>
#include "container.h"

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
  const ApplicationConfig config_;

 public:
  std::unique_ptr<Container> container;
  explicit Context(const ApplicationConfig &config);
  virtual ~Context();
};

/** @} */
