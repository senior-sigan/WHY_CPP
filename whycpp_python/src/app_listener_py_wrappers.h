#ifndef WHYCPP_ROOTWHYCPP_PYTHON_SRC_APP_LISTENER_PY_WRAPPERS_H_
#define WHYCPP_ROOTWHYCPP_PYTHON_SRC_APP_LISTENER_PY_WRAPPERS_H_

#include <Python.h>

void RegisterWrappers(PyObject* pModule);
void UnregisterWrappers(void);

void OnCreate(void);
void OnDispose(void);
void OnPause(void);
void OnResume(void);
void OnRender(void);

#endif //WHYCPP_C_WHYCPP_PYTHON_SRC_APP_LISTENER_PY_WRAPPERS_H_
