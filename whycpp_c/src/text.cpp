#include <whycpp_c/color.h>
#include <whycpp_c/text.h>

#include <whycpp/text.h>

#include "internal/drawing_int.h"
#include "internal/global_context_int.h"

void PrintChar_C(char ch, int x, int y, RGBA_t color, int size) {
  Print(*GetContext_C(), ch, x, y, to_Cpp(color), size);
}

void PrintStr_C(const char* str, int x, int y, RGBA_t color, int size, int spacing) {
  Print(*GetContext_C(), std::string(str), x, y, to_Cpp(color), size, spacing);
}
