//
// Created by k.leyfer on 28.03.2019.
//

#include <whycpp_c/time.h>
#include <whycpp/time.h>
#include "internal/global_context_int.h"

double GetTime_C() {
  return GetTime(*GetContext_C());
}

double GetDelta_C() {
  return GetDelta(*GetContext_C());
}
