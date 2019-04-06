#include "app_listener_py_wrappers.h"
#include <Python.h>

static PyObject* onCreate;
static PyObject* onDispose;
static PyObject* onPause;
static PyObject* onResume;
static PyObject* onRender;

static PyObject* FindPyFunction(const char* name, PyObject* pModule) {
  PyObject* func = PyObject_GetAttrString(pModule, name);
  if (!func || !PyCallable_Check(func)) {
    if (PyErr_Occurred()) PyErr_Print();
    fprintf(stderr, "Cannot find function '%s'\n", name);
    return NULL;
  } else {
    printf("Found function '%s'\n", name);
    return func;
  }
}

void RegisterWrappers(PyObject* pModule) {
  onCreate = FindPyFunction("on_create", pModule);
  onDispose = FindPyFunction("on_dispose", pModule);
  onPause = FindPyFunction("on_pause", pModule);
  onResume = FindPyFunction("on_resume", pModule);
  onRender = FindPyFunction("on_render", pModule);
}

void UnregisterWrappers(void) {
  Py_XDECREF(onCreate);
  Py_XDECREF(onDispose);
  Py_XDECREF(onPause);
  Py_XDECREF(onResume);
  Py_XDECREF(onRender);
}

void OnCreate(void) {
  if (!onCreate) return;
  PyObject* args = PyTuple_New(0);
  PyObject_CallObject(onCreate, args);
  if (PyErr_Occurred()) PyErr_Print();
}
void OnDispose(void) {
  if (!onDispose) return;
  PyObject* args = PyTuple_New(0);
  PyObject_CallObject(onDispose, args);
  if (PyErr_Occurred()) PyErr_Print();
}
void OnPause(void) {
  if (!onPause) return;
  PyObject* args = PyTuple_New(0);
  PyObject_CallObject(onPause, args);
  if (PyErr_Occurred()) PyErr_Print();
}
void OnResume(void) {
  if (!onResume) return;
  PyObject* args = PyTuple_New(0);
  PyObject_CallObject(onResume, args);
  if (PyErr_Occurred()) PyErr_Print();
}
void OnRender(void) {
  if (!onRender) return;
  PyObject* args = PyTuple_New(0);
  PyObject_CallObject(onRender, args);
  if (PyErr_Occurred()) PyErr_Print();
}