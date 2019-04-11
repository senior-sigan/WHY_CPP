#include "whycpp_wrapper.h"
#include <whycpp_c/palette.h>
#include "py_btns.h"
#include "py_drawing.h"
#include "py_import_sprite.h"
#include "py_input.h"
#include "py_lifecycle.h"
#include "py_log.h"
#include "py_text.h"
#include "py_time.h"

static PyMethodDef WhycppMethods[] = {{"get_display_width", py_GetDisplayWidth, METH_VARARGS, NULL},
                                      {"get_display_height", py_GetDisplayHeight, METH_VARARGS, NULL},
                                      {"PALETTE", py_Palette, METH_VARARGS, NULL},
                                      {"num_as_rgba", py_NumAsRgba, METH_VARARGS, NULL},
                                      {"rgba_as_num", py_RgbaAsNum, METH_VARARGS, NULL},
                                      {"set_pixel", py_SetPixel, METH_VARARGS, NULL},
                                      {"get_pixel", py_GetPixel, METH_VARARGS, NULL},
                                      {"draw_clear_screen", py_DrawClearScreen, METH_VARARGS, NULL},
                                      {"draw_line", py_DrawLine, METH_VARARGS, NULL},
                                      {"draw_rect_fill", py_DrawRectFill, METH_VARARGS, NULL},
                                      {"draw_rect", py_DrawRect, METH_VARARGS, NULL},
                                      {"draw_circle", py_DrawCircle, METH_VARARGS, NULL},
                                      {"draw_circle_fill", py_DrawCircleFill, METH_VARARGS, NULL},
                                      {"draw_sprite", py_DrawSprite, METH_VARARGS, NULL},
                                      {"get_delta", py_GetDelta, METH_VARARGS, NULL},
                                      {"get_time", py_GetTime, METH_VARARGS, NULL},
                                      {"print", py_PrintStr, METH_VARARGS, NULL},
                                      {"import_sprite", py_ImportSprite, METH_VARARGS, NULL},
                                      {"log_info", py_LogInfo, METH_VARARGS, NULL},
                                      {"is_pressed", py_IsPressed, METH_VARARGS, NULL},
                                      {"is_clicked", py_IsClicked, METH_VARARGS, NULL},
                                      {"get_mouse", py_GetMouse, METH_VARARGS, NULL},
                                      {"exit", py_ExitApp, METH_VARARGS, NULL},
                                      {NULL, NULL, 0, NULL}};

static PyModuleDef WhycppModule = {PyModuleDef_HEAD_INIT, "whycpp", NULL, -1, WhycppMethods, NULL, NULL, NULL, NULL};

PyObject *PyInit_whycpp(void) {
  PyObject *module = PyModule_Create(&WhycppModule);
  PyModule_AddIntConstant(module, "PALETTE_LEN", PALETTE_LEN);
  RegisterButtons(module);
  return module;
}