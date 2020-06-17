#define PY_SSIZE_T_CLEAN
#include "Python.h"
#ifndef Py_PYTHON_H
    #error Python headers needed to compile C extensions, please install development version of Python.
#elif PY_VERSION_HEX < 0x02060000 || (0x03000000 <= PY_VERSION_HEX && PY_VERSION_HEX < 0x03030000)
    #error Cython requires Python 2.6+ or Python 3.3+.
#else
#define CYTHON_ABI "0_29_20"
#define CYTHON_HEX_VERSION 0x001D14F0
#define CYTHON_FUTURE_DIVISION 1
#include <stddef.h>
#ifndef offsetof
  #define offsetof(type, member) ( (size_t) & ((type*)0) -> member )
#endif
#if !defined(WIN32) && !defined(MS_WINDOWS)
  #ifndef __stdcall
    #define __stdcall
  #endif
  #ifndef __cdecl
    #define __cdecl
  #endif
  #ifndef __fastcall
    #define __fastcall
  #endif
#endif
#ifndef DL_IMPORT
  #define DL_IMPORT(t) t
#endif
#ifndef DL_EXPORT
  #define DL_EXPORT(t) t
#endif
#define __PYX_COMMA ,
#ifndef HAVE_LONG_LONG
  #if PY_VERSION_HEX >= 0x02070000
    #define HAVE_LONG_LONG
  #endif
#endif
#ifndef PY_LONG_LONG
  #define PY_LONG_LONG LONG_LONG
#endif
#ifndef Py_HUGE_VAL
  #define Py_HUGE_VAL HUGE_VAL
#endif
#ifdef PYPY_VERSION
  #define CYTHON_COMPILING_IN_PYPY 1
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #undef CYTHON_USE_TYPE_SLOTS
  #define CYTHON_USE_TYPE_SLOTS 0
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #if PY_VERSION_HEX < 0x03050000
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #undef CYTHON_USE_UNICODE_INTERNALS
  #define CYTHON_USE_UNICODE_INTERNALS 0
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #undef CYTHON_AVOID_BORROWED_REFS
  #define CYTHON_AVOID_BORROWED_REFS 1
  #undef CYTHON_ASSUME_SAFE_MACROS
  #define CYTHON_ASSUME_SAFE_MACROS 0
  #undef CYTHON_UNPACK_METHODS
  #define CYTHON_UNPACK_METHODS 0
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#elif defined(PYSTON_VERSION)
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 1
  #define CYTHON_COMPILING_IN_CPYTHON 0
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #undef CYTHON_USE_PYTYPE_LOOKUP
  #define CYTHON_USE_PYTYPE_LOOKUP 0
  #undef CYTHON_USE_ASYNC_SLOTS
  #define CYTHON_USE_ASYNC_SLOTS 0
  #undef CYTHON_USE_PYLIST_INTERNALS
  #define CYTHON_USE_PYLIST_INTERNALS 0
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #undef CYTHON_USE_UNICODE_WRITER
  #define CYTHON_USE_UNICODE_WRITER 0
  #undef CYTHON_USE_PYLONG_INTERNALS
  #define CYTHON_USE_PYLONG_INTERNALS 0
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #undef CYTHON_FAST_THREAD_STATE
  #define CYTHON_FAST_THREAD_STATE 0
  #undef CYTHON_FAST_PYCALL
  #define CYTHON_FAST_PYCALL 0
  #undef CYTHON_PEP489_MULTI_PHASE_INIT
  #define CYTHON_PEP489_MULTI_PHASE_INIT 0
  #undef CYTHON_USE_TP_FINALIZE
  #define CYTHON_USE_TP_FINALIZE 0
  #undef CYTHON_USE_DICT_VERSIONS
  #define CYTHON_USE_DICT_VERSIONS 0
  #undef CYTHON_USE_EXC_INFO_STACK
  #define CYTHON_USE_EXC_INFO_STACK 0
#else
  #define CYTHON_COMPILING_IN_PYPY 0
  #define CYTHON_COMPILING_IN_PYSTON 0
  #define CYTHON_COMPILING_IN_CPYTHON 1
  #ifndef CYTHON_USE_TYPE_SLOTS
    #define CYTHON_USE_TYPE_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYTYPE_LOOKUP
    #define CYTHON_USE_PYTYPE_LOOKUP 0
  #elif !defined(CYTHON_USE_PYTYPE_LOOKUP)
    #define CYTHON_USE_PYTYPE_LOOKUP 1
  #endif
  #if PY_MAJOR_VERSION < 3
    #undef CYTHON_USE_ASYNC_SLOTS
    #define CYTHON_USE_ASYNC_SLOTS 0
  #elif !defined(CYTHON_USE_ASYNC_SLOTS)
    #define CYTHON_USE_ASYNC_SLOTS 1
  #endif
  #if PY_VERSION_HEX < 0x02070000
    #undef CYTHON_USE_PYLONG_INTERNALS
    #define CYTHON_USE_PYLONG_INTERNALS 0
  #elif !defined(CYTHON_USE_PYLONG_INTERNALS)
    #define CYTHON_USE_PYLONG_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_PYLIST_INTERNALS
    #define CYTHON_USE_PYLIST_INTERNALS 1
  #endif
  #ifndef CYTHON_USE_UNICODE_INTERNALS
    #define CYTHON_USE_UNICODE_INTERNALS 1
  #endif
  #if PY_VERSION_HEX < 0x030300F0
    #undef CYTHON_USE_UNICODE_WRITER
    #define CYTHON_USE_UNICODE_WRITER 0
  #elif !defined(CYTHON_USE_UNICODE_WRITER)
    #define CYTHON_USE_UNICODE_WRITER 1
  #endif
  #ifndef CYTHON_AVOID_BORROWED_REFS
    #define CYTHON_AVOID_BORROWED_REFS 0
  #endif
  #ifndef CYTHON_ASSUME_SAFE_MACROS
    #define CYTHON_ASSUME_SAFE_MACROS 1
  #endif
  #ifndef CYTHON_UNPACK_METHODS
    #define CYTHON_UNPACK_METHODS 1
  #endif
  #ifndef CYTHON_FAST_THREAD_STATE
    #define CYTHON_FAST_THREAD_STATE 1
  #endif
  #ifndef CYTHON_FAST_PYCALL
    #define CYTHON_FAST_PYCALL 1
  #endif
  #ifndef CYTHON_PEP489_MULTI_PHASE_INIT
    #define CYTHON_PEP489_MULTI_PHASE_INIT (PY_VERSION_HEX >= 0x03050000)
  #endif
  #ifndef CYTHON_USE_TP_FINALIZE
    #define CYTHON_USE_TP_FINALIZE (PY_VERSION_HEX >= 0x030400a1)
  #endif
  #ifndef CYTHON_USE_DICT_VERSIONS
    #define CYTHON_USE_DICT_VERSIONS (PY_VERSION_HEX >= 0x030600B1)
  #endif
  #ifndef CYTHON_USE_EXC_INFO_STACK
    #define CYTHON_USE_EXC_INFO_STACK (PY_VERSION_HEX >= 0x030700A3)
  #endif
#endif
#if !defined(CYTHON_FAST_PYCCALL)
#define CYTHON_FAST_PYCCALL  (CYTHON_FAST_PYCALL && PY_VERSION_HEX >= 0x030600B1)
#endif
#if CYTHON_USE_PYLONG_INTERNALS
  #include "longintrepr.h"
  #undef SHIFT
  #undef BASE
  #undef MASK
  #ifdef SIZEOF_VOID_P
    enum { __pyx_check_sizeof_voidp = 1 / (int)(SIZEOF_VOID_P == sizeof(void*)) };
  #endif
#endif
#ifndef __has_attribute
  #define __has_attribute(x) 0
#endif
#ifndef __has_cpp_attribute
  #define __has_cpp_attribute(x) 0
#endif
#ifndef CYTHON_RESTRICT
  #if defined(__GNUC__)
    #define CYTHON_RESTRICT __restrict__
  #elif defined(_MSC_VER) && _MSC_VER >= 1400
    #define CYTHON_RESTRICT __restrict
  #elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define CYTHON_RESTRICT restrict
  #else
    #define CYTHON_RESTRICT
  #endif
#endif
#ifndef CYTHON_UNUSED
# if defined(__GNUC__)
#   if !(defined(__cplusplus)) || (__GNUC__ > 3 || (__GNUC__ == 3 && __GNUC_MINOR__ >= 4))
#     define CYTHON_UNUSED __attribute__ ((__unused__))
#   else
#     define CYTHON_UNUSED
#   endif
# elif defined(__ICC) || (defined(__INTEL_COMPILER) && !defined(_MSC_VER))
#   define CYTHON_UNUSED __attribute__ ((__unused__))
# else
#   define CYTHON_UNUSED
# endif
#endif
#ifndef CYTHON_MAYBE_UNUSED_VAR
#  if defined(__cplusplus)
     template<class T> void CYTHON_MAYBE_UNUSED_VAR( const T& ) { }
#  else
#    define CYTHON_MAYBE_UNUSED_VAR(x) (void)(x)
#  endif
#endif
#ifndef CYTHON_NCP_UNUSED
# if CYTHON_COMPILING_IN_CPYTHON
#  define CYTHON_NCP_UNUSED
# else
#  define CYTHON_NCP_UNUSED CYTHON_UNUSED
# endif
#endif
#define __Pyx_void_to_None(void_result) ((void)(void_result), Py_INCREF(Py_None), Py_None)
#ifdef _MSC_VER
    #ifndef _MSC_STDINT_H_
        #if _MSC_VER < 1300
           typedef unsigned char     uint8_t;
           typedef unsigned int      uint32_t;
        #else
           typedef unsigned __int8   uint8_t;
           typedef unsigned __int32  uint32_t;
        #endif
    #endif
#else
   #include <stdint.h>
#endif
#ifndef CYTHON_FALLTHROUGH
  #if defined(__cplusplus) && __cplusplus >= 201103L
    #if __has_cpp_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH [[fallthrough]]
    #elif __has_cpp_attribute(clang::fallthrough)
      #define CYTHON_FALLTHROUGH [[clang::fallthrough]]
    #elif __has_cpp_attribute(gnu::fallthrough)
      #define CYTHON_FALLTHROUGH [[gnu::fallthrough]]
    #endif
  #endif
  #ifndef CYTHON_FALLTHROUGH
    #if __has_attribute(fallthrough)
      #define CYTHON_FALLTHROUGH __attribute__((fallthrough))
    #else
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
  #if defined(__clang__ ) && defined(__apple_build_version__)
    #if __apple_build_version__ < 7000000
      #undef  CYTHON_FALLTHROUGH
      #define CYTHON_FALLTHROUGH
    #endif
  #endif
#endif

#ifndef __cplusplus
  #error "Cython files generated with the C++ option must be compiled with a C++ compiler."
#endif
#ifndef CYTHON_INLINE
  #if defined(__clang__)
    #define CYTHON_INLINE __inline__ __attribute__ ((__unused__))
  #else
    #define CYTHON_INLINE inline
  #endif
#endif
template<typename T>
void __Pyx_call_destructor(T& x) {
    x.~T();
}
template<typename T>
class __Pyx_FakeReference {
  public:
    __Pyx_FakeReference() : ptr(NULL) { }
    __Pyx_FakeReference(const T& ref) : ptr(const_cast<T*>(&ref)) { }
    T *operator->() { return ptr; }
    T *operator&() { return ptr; }
    operator T&() { return *ptr; }
    template<typename U> bool operator ==(U other) { return *ptr == other; }
    template<typename U> bool operator !=(U other) { return *ptr != other; }
  private:
    T *ptr;
};

#if CYTHON_COMPILING_IN_PYPY && PY_VERSION_HEX < 0x02070600 && !defined(Py_OptimizeFlag)
  #define Py_OptimizeFlag 0
#endif
#define __PYX_BUILD_PY_SSIZE_T "n"
#define CYTHON_FORMAT_SSIZE_T "z"
#if PY_MAJOR_VERSION < 3
  #define __Pyx_BUILTIN_MODULE_NAME "__builtin__"
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a+k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
  #define __Pyx_DefaultClassType PyClass_Type
#else
  #define __Pyx_BUILTIN_MODULE_NAME "builtins"
#if PY_VERSION_HEX >= 0x030800A4 && PY_VERSION_HEX < 0x030800B2
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, 0, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#else
  #define __Pyx_PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)\
          PyCode_New(a, k, l, s, f, code, c, n, v, fv, cell, fn, name, fline, lnos)
#endif
  #define __Pyx_DefaultClassType PyType_Type
#endif
#ifndef Py_TPFLAGS_CHECKTYPES
  #define Py_TPFLAGS_CHECKTYPES 0
#endif
#ifndef Py_TPFLAGS_HAVE_INDEX
  #define Py_TPFLAGS_HAVE_INDEX 0
#endif
#ifndef Py_TPFLAGS_HAVE_NEWBUFFER
  #define Py_TPFLAGS_HAVE_NEWBUFFER 0
#endif
#ifndef Py_TPFLAGS_HAVE_FINALIZE
  #define Py_TPFLAGS_HAVE_FINALIZE 0
#endif
#ifndef METH_STACKLESS
  #define METH_STACKLESS 0
#endif
#if PY_VERSION_HEX <= 0x030700A3 || !defined(METH_FASTCALL)
  #ifndef METH_FASTCALL
     #define METH_FASTCALL 0x80
  #endif
  typedef PyObject *(*__Pyx_PyCFunctionFast) (PyObject *self, PyObject *const *args, Py_ssize_t nargs);
  typedef PyObject *(*__Pyx_PyCFunctionFastWithKeywords) (PyObject *self, PyObject *const *args,
                                                          Py_ssize_t nargs, PyObject *kwnames);
#else
  #define __Pyx_PyCFunctionFast _PyCFunctionFast
  #define __Pyx_PyCFunctionFastWithKeywords _PyCFunctionFastWithKeywords
#endif
#if CYTHON_FAST_PYCCALL
#define __Pyx_PyFastCFunction_Check(func)\
    ((PyCFunction_Check(func) && (METH_FASTCALL == (PyCFunction_GET_FLAGS(func) & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)))))
#else
#define __Pyx_PyFastCFunction_Check(func) 0
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Malloc)
  #define PyObject_Malloc(s)   PyMem_Malloc(s)
  #define PyObject_Free(p)     PyMem_Free(p)
  #define PyObject_Realloc(p)  PyMem_Realloc(p)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX < 0x030400A1
  #define PyMem_RawMalloc(n)           PyMem_Malloc(n)
  #define PyMem_RawRealloc(p, n)       PyMem_Realloc(p, n)
  #define PyMem_RawFree(p)             PyMem_Free(p)
#endif
#if CYTHON_COMPILING_IN_PYSTON
  #define __Pyx_PyCode_HasFreeVars(co)  PyCode_HasFreeVars(co)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno) PyFrame_SetLineNumber(frame, lineno)
#else
  #define __Pyx_PyCode_HasFreeVars(co)  (PyCode_GetNumFree(co) > 0)
  #define __Pyx_PyFrame_SetLineNumber(frame, lineno)  (frame)->f_lineno = (lineno)
#endif
#if !CYTHON_FAST_THREAD_STATE || PY_VERSION_HEX < 0x02070000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#elif PY_VERSION_HEX >= 0x03060000
  #define __Pyx_PyThreadState_Current _PyThreadState_UncheckedGet()
#elif PY_VERSION_HEX >= 0x03000000
  #define __Pyx_PyThreadState_Current PyThreadState_GET()
#else
  #define __Pyx_PyThreadState_Current _PyThreadState_Current
#endif
#if PY_VERSION_HEX < 0x030700A2 && !defined(PyThread_tss_create) && !defined(Py_tss_NEEDS_INIT)
#include "pythread.h"
#define Py_tss_NEEDS_INIT 0
typedef int Py_tss_t;
static CYTHON_INLINE int PyThread_tss_create(Py_tss_t *key) {
  *key = PyThread_create_key();
  return 0;
}
static CYTHON_INLINE Py_tss_t * PyThread_tss_alloc(void) {
  Py_tss_t *key = (Py_tss_t *)PyObject_Malloc(sizeof(Py_tss_t));
  *key = Py_tss_NEEDS_INIT;
  return key;
}
static CYTHON_INLINE void PyThread_tss_free(Py_tss_t *key) {
  PyObject_Free(key);
}
static CYTHON_INLINE int PyThread_tss_is_created(Py_tss_t *key) {
  return *key != Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE void PyThread_tss_delete(Py_tss_t *key) {
  PyThread_delete_key(*key);
  *key = Py_tss_NEEDS_INIT;
}
static CYTHON_INLINE int PyThread_tss_set(Py_tss_t *key, void *value) {
  return PyThread_set_key_value(*key, value);
}
static CYTHON_INLINE void * PyThread_tss_get(Py_tss_t *key) {
  return PyThread_get_key_value(*key);
}
#endif
#if CYTHON_COMPILING_IN_CPYTHON || defined(_PyDict_NewPresized)
#define __Pyx_PyDict_NewPresized(n)  ((n <= 8) ? PyDict_New() : _PyDict_NewPresized(n))
#else
#define __Pyx_PyDict_NewPresized(n)  PyDict_New()
#endif
#if PY_MAJOR_VERSION >= 3 || CYTHON_FUTURE_DIVISION
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_TrueDivide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceTrueDivide(x,y)
#else
  #define __Pyx_PyNumber_Divide(x,y)         PyNumber_Divide(x,y)
  #define __Pyx_PyNumber_InPlaceDivide(x,y)  PyNumber_InPlaceDivide(x,y)
#endif
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1 && CYTHON_USE_UNICODE_INTERNALS
#define __Pyx_PyDict_GetItemStr(dict, name)  _PyDict_GetItem_KnownHash(dict, name, ((PyASCIIObject *) name)->hash)
#else
#define __Pyx_PyDict_GetItemStr(dict, name)  PyDict_GetItem(dict, name)
#endif
#if PY_VERSION_HEX > 0x03030000 && defined(PyUnicode_KIND)
  #define CYTHON_PEP393_ENABLED 1
  #define __Pyx_PyUnicode_READY(op)       (likely(PyUnicode_IS_READY(op)) ?\
                                              0 : _PyUnicode_Ready((PyObject *)(op)))
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_LENGTH(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) PyUnicode_READ_CHAR(u, i)
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   PyUnicode_MAX_CHAR_VALUE(u)
  #define __Pyx_PyUnicode_KIND(u)         PyUnicode_KIND(u)
  #define __Pyx_PyUnicode_DATA(u)         PyUnicode_DATA(u)
  #define __Pyx_PyUnicode_READ(k, d, i)   PyUnicode_READ(k, d, i)
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  PyUnicode_WRITE(k, d, i, ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != (likely(PyUnicode_IS_READY(u)) ? PyUnicode_GET_LENGTH(u) : PyUnicode_GET_SIZE(u)))
#else
  #define CYTHON_PEP393_ENABLED 0
  #define PyUnicode_1BYTE_KIND  1
  #define PyUnicode_2BYTE_KIND  2
  #define PyUnicode_4BYTE_KIND  4
  #define __Pyx_PyUnicode_READY(op)       (0)
  #define __Pyx_PyUnicode_GET_LENGTH(u)   PyUnicode_GET_SIZE(u)
  #define __Pyx_PyUnicode_READ_CHAR(u, i) ((Py_UCS4)(PyUnicode_AS_UNICODE(u)[i]))
  #define __Pyx_PyUnicode_MAX_CHAR_VALUE(u)   ((sizeof(Py_UNICODE) == 2) ? 65535 : 1114111)
  #define __Pyx_PyUnicode_KIND(u)         (sizeof(Py_UNICODE))
  #define __Pyx_PyUnicode_DATA(u)         ((void*)PyUnicode_AS_UNICODE(u))
  #define __Pyx_PyUnicode_READ(k, d, i)   ((void)(k), (Py_UCS4)(((Py_UNICODE*)d)[i]))
  #define __Pyx_PyUnicode_WRITE(k, d, i, ch)  (((void)(k)), ((Py_UNICODE*)d)[i] = ch)
  #define __Pyx_PyUnicode_IS_TRUE(u)      (0 != PyUnicode_GET_SIZE(u))
#endif
#if CYTHON_COMPILING_IN_PYPY
  #define __Pyx_PyUnicode_Concat(a, b)      PyNumber_Add(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  PyNumber_Add(a, b)
#else
  #define __Pyx_PyUnicode_Concat(a, b)      PyUnicode_Concat(a, b)
  #define __Pyx_PyUnicode_ConcatSafe(a, b)  ((unlikely((a) == Py_None) || unlikely((b) == Py_None)) ?\
      PyNumber_Add(a, b) : __Pyx_PyUnicode_Concat(a, b))
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyUnicode_Contains)
  #define PyUnicode_Contains(u, s)  PySequence_Contains(u, s)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyByteArray_Check)
  #define PyByteArray_Check(obj)  PyObject_TypeCheck(obj, &PyByteArray_Type)
#endif
#if CYTHON_COMPILING_IN_PYPY && !defined(PyObject_Format)
  #define PyObject_Format(obj, fmt)  PyObject_CallMethod(obj, "__format__", "O", fmt)
#endif
#define __Pyx_PyString_FormatSafe(a, b)   ((unlikely((a) == Py_None || (PyString_Check(b) && !PyString_CheckExact(b)))) ? PyNumber_Remainder(a, b) : __Pyx_PyString_Format(a, b))
#define __Pyx_PyUnicode_FormatSafe(a, b)  ((unlikely((a) == Py_None || (PyUnicode_Check(b) && !PyUnicode_CheckExact(b)))) ? PyNumber_Remainder(a, b) : PyUnicode_Format(a, b))
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyString_Format(a, b)  PyUnicode_Format(a, b)
#else
  #define __Pyx_PyString_Format(a, b)  PyString_Format(a, b)
#endif
#if PY_MAJOR_VERSION < 3 && !defined(PyObject_ASCII)
  #define PyObject_ASCII(o)            PyObject_Repr(o)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBaseString_Type            PyUnicode_Type
  #define PyStringObject               PyUnicodeObject
  #define PyString_Type                PyUnicode_Type
  #define PyString_Check               PyUnicode_Check
  #define PyString_CheckExact          PyUnicode_CheckExact
#ifndef PyObject_Unicode
  #define PyObject_Unicode             PyObject_Str
#endif
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyBaseString_Check(obj) PyUnicode_Check(obj)
  #define __Pyx_PyBaseString_CheckExact(obj) PyUnicode_CheckExact(obj)
#else
  #define __Pyx_PyBaseString_Check(obj) (PyString_Check(obj) || PyUnicode_Check(obj))
  #define __Pyx_PyBaseString_CheckExact(obj) (PyString_CheckExact(obj) || PyUnicode_CheckExact(obj))
#endif
#ifndef PySet_CheckExact
  #define PySet_CheckExact(obj)        (Py_TYPE(obj) == &PySet_Type)
#endif
#if PY_VERSION_HEX >= 0x030900A4
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_SET_REFCNT(obj, refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SET_SIZE(obj, size)
#else
  #define __Pyx_SET_REFCNT(obj, refcnt) Py_REFCNT(obj) = (refcnt)
  #define __Pyx_SET_SIZE(obj, size) Py_SIZE(obj) = (size)
#endif
#if CYTHON_ASSUME_SAFE_MACROS
  #define __Pyx_PySequence_SIZE(seq)  Py_SIZE(seq)
#else
  #define __Pyx_PySequence_SIZE(seq)  PySequence_Size(seq)
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyIntObject                  PyLongObject
  #define PyInt_Type                   PyLong_Type
  #define PyInt_Check(op)              PyLong_Check(op)
  #define PyInt_CheckExact(op)         PyLong_CheckExact(op)
  #define PyInt_FromString             PyLong_FromString
  #define PyInt_FromUnicode            PyLong_FromUnicode
  #define PyInt_FromLong               PyLong_FromLong
  #define PyInt_FromSize_t             PyLong_FromSize_t
  #define PyInt_FromSsize_t            PyLong_FromSsize_t
  #define PyInt_AsLong                 PyLong_AsLong
  #define PyInt_AS_LONG                PyLong_AS_LONG
  #define PyInt_AsSsize_t              PyLong_AsSsize_t
  #define PyInt_AsUnsignedLongMask     PyLong_AsUnsignedLongMask
  #define PyInt_AsUnsignedLongLongMask PyLong_AsUnsignedLongLongMask
  #define PyNumber_Int                 PyNumber_Long
#endif
#if PY_MAJOR_VERSION >= 3
  #define PyBoolObject                 PyLongObject
#endif
#if PY_MAJOR_VERSION >= 3 && CYTHON_COMPILING_IN_PYPY
  #ifndef PyUnicode_InternFromString
    #define PyUnicode_InternFromString(s) PyUnicode_FromString(s)
  #endif
#endif
#if PY_VERSION_HEX < 0x030200A4
  typedef long Py_hash_t;
  #define __Pyx_PyInt_FromHash_t PyInt_FromLong
  #define __Pyx_PyInt_AsHash_t   PyInt_AsLong
#else
  #define __Pyx_PyInt_FromHash_t PyInt_FromSsize_t
  #define __Pyx_PyInt_AsHash_t   PyInt_AsSsize_t
#endif
#if PY_MAJOR_VERSION >= 3
  #define __Pyx_PyMethod_New(func, self, klass) ((self) ? PyMethod_New(func, self) : (Py_INCREF(func), func))
#else
  #define __Pyx_PyMethod_New(func, self, klass) PyMethod_New(func, self, klass)
#endif
#if CYTHON_USE_ASYNC_SLOTS
  #if PY_VERSION_HEX >= 0x030500B1
    #define __Pyx_PyAsyncMethodsStruct PyAsyncMethods
    #define __Pyx_PyType_AsAsync(obj) (Py_TYPE(obj)->tp_as_async)
  #else
    #define __Pyx_PyType_AsAsync(obj) ((__Pyx_PyAsyncMethodsStruct*) (Py_TYPE(obj)->tp_reserved))
  #endif
#else
  #define __Pyx_PyType_AsAsync(obj) NULL
#endif
#ifndef __Pyx_PyAsyncMethodsStruct
    typedef struct {
        unaryfunc am_await;
        unaryfunc am_aiter;
        unaryfunc am_anext;
    } __Pyx_PyAsyncMethodsStruct;
#endif

#if defined(WIN32) || defined(MS_WINDOWS)
  #define _USE_MATH_DEFINES
#endif
#include <math.h>
#ifdef NAN
#define __PYX_NAN() ((float) NAN)
#else
static CYTHON_INLINE float __PYX_NAN() {
  float value;
  memset(&value, 0xFF, sizeof(value));
  return value;
}
#endif
#if defined(__CYGWIN__) && defined(_LDBL_EQ_DBL)
#define __Pyx_truncl trunc
#else
#define __Pyx_truncl truncl
#endif

#define __PYX_MARK_ERR_POS(f_index, lineno) \
    { __pyx_filename = __pyx_f[f_index]; (void)__pyx_filename; __pyx_lineno = lineno; (void)__pyx_lineno; __pyx_clineno = __LINE__; (void)__pyx_clineno; }
#define __PYX_ERR(f_index, lineno, Ln_error) \
    { __PYX_MARK_ERR_POS(f_index, lineno) goto Ln_error; }

#ifndef __PYX_EXTERN_C
  #ifdef __cplusplus
    #define __PYX_EXTERN_C extern "C"
  #else
    #define __PYX_EXTERN_C extern
  #endif
#endif

#define __PYX_HAVE__mmmovie__detector__persondet__modules__core__ops__nms__soft_nms_cpu
#define __PYX_HAVE_API__mmmovie__detector__persondet__modules__core__ops__nms__soft_nms_cpu
/* Early includes */
#include <string.h>
#include <stdio.h>
#include "numpy/arrayobject.h"
#include "numpy/ufuncobject.h"
#ifdef _OPENMP
#include <omp.h>
#endif /* _OPENMP */

#if defined(PYREX_WITHOUT_ASSERTIONS) && !defined(CYTHON_WITHOUT_ASSERTIONS)
#define CYTHON_WITHOUT_ASSERTIONS
#endif

typedef struct {PyObject **p; const char *s; const Py_ssize_t n; const char* encoding;
                const char is_unicode; const char is_str; const char intern; } __Pyx_StringTabEntry;

#define __PYX_DEFAULT_STRING_ENCODING_IS_ASCII 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_UTF8 0
#define __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT (PY_MAJOR_VERSION >= 3 && __PYX_DEFAULT_STRING_ENCODING_IS_UTF8)
#define __PYX_DEFAULT_STRING_ENCODING ""
#define __Pyx_PyObject_FromString __Pyx_PyBytes_FromString
#define __Pyx_PyObject_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#define __Pyx_uchar_cast(c) ((unsigned char)c)
#define __Pyx_long_cast(x) ((long)x)
#define __Pyx_fits_Py_ssize_t(v, type, is_signed)  (\
    (sizeof(type) < sizeof(Py_ssize_t))  ||\
    (sizeof(type) > sizeof(Py_ssize_t) &&\
          likely(v < (type)PY_SSIZE_T_MAX ||\
                 v == (type)PY_SSIZE_T_MAX)  &&\
          (!is_signed || likely(v > (type)PY_SSIZE_T_MIN ||\
                                v == (type)PY_SSIZE_T_MIN)))  ||\
    (sizeof(type) == sizeof(Py_ssize_t) &&\
          (is_signed || likely(v < (type)PY_SSIZE_T_MAX ||\
                               v == (type)PY_SSIZE_T_MAX)))  )
static CYTHON_INLINE int __Pyx_is_valid_index(Py_ssize_t i, Py_ssize_t limit) {
    return (size_t) i < (size_t) limit;
}
#if defined (__cplusplus) && __cplusplus >= 201103L
    #include <cstdlib>
    #define __Pyx_sst_abs(value) std::abs(value)
#elif SIZEOF_INT >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) abs(value)
#elif SIZEOF_LONG >= SIZEOF_SIZE_T
    #define __Pyx_sst_abs(value) labs(value)
#elif defined (_MSC_VER)
    #define __Pyx_sst_abs(value) ((Py_ssize_t)_abs64(value))
#elif defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define __Pyx_sst_abs(value) llabs(value)
#elif defined (__GNUC__)
    #define __Pyx_sst_abs(value) __builtin_llabs(value)
#else
    #define __Pyx_sst_abs(value) ((value<0) ? -value : value)
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject*);
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject*, Py_ssize_t* length);
#define __Pyx_PyByteArray_FromString(s) PyByteArray_FromStringAndSize((const char*)s, strlen((const char*)s))
#define __Pyx_PyByteArray_FromStringAndSize(s, l) PyByteArray_FromStringAndSize((const char*)s, l)
#define __Pyx_PyBytes_FromString        PyBytes_FromString
#define __Pyx_PyBytes_FromStringAndSize PyBytes_FromStringAndSize
static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char*);
#if PY_MAJOR_VERSION < 3
    #define __Pyx_PyStr_FromString        __Pyx_PyBytes_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyBytes_FromStringAndSize
#else
    #define __Pyx_PyStr_FromString        __Pyx_PyUnicode_FromString
    #define __Pyx_PyStr_FromStringAndSize __Pyx_PyUnicode_FromStringAndSize
#endif
#define __Pyx_PyBytes_AsWritableString(s)     ((char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableSString(s)    ((signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsWritableUString(s)    ((unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsString(s)     ((const char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsSString(s)    ((const signed char*) PyBytes_AS_STRING(s))
#define __Pyx_PyBytes_AsUString(s)    ((const unsigned char*) PyBytes_AS_STRING(s))
#define __Pyx_PyObject_AsWritableString(s)    ((char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableSString(s)    ((signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsWritableUString(s)    ((unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsSString(s)    ((const signed char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_AsUString(s)    ((const unsigned char*) __Pyx_PyObject_AsString(s))
#define __Pyx_PyObject_FromCString(s)  __Pyx_PyObject_FromString((const char*)s)
#define __Pyx_PyBytes_FromCString(s)   __Pyx_PyBytes_FromString((const char*)s)
#define __Pyx_PyByteArray_FromCString(s)   __Pyx_PyByteArray_FromString((const char*)s)
#define __Pyx_PyStr_FromCString(s)     __Pyx_PyStr_FromString((const char*)s)
#define __Pyx_PyUnicode_FromCString(s) __Pyx_PyUnicode_FromString((const char*)s)
static CYTHON_INLINE size_t __Pyx_Py_UNICODE_strlen(const Py_UNICODE *u) {
    const Py_UNICODE *u_end = u;
    while (*u_end++) ;
    return (size_t)(u_end - u - 1);
}
#define __Pyx_PyUnicode_FromUnicode(u)       PyUnicode_FromUnicode(u, __Pyx_Py_UNICODE_strlen(u))
#define __Pyx_PyUnicode_FromUnicodeAndLength PyUnicode_FromUnicode
#define __Pyx_PyUnicode_AsUnicode            PyUnicode_AsUnicode
#define __Pyx_NewRef(obj) (Py_INCREF(obj), obj)
#define __Pyx_Owned_Py_None(b) __Pyx_NewRef(Py_None)
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b);
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject*);
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject*);
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x);
#define __Pyx_PySequence_Tuple(obj)\
    (likely(PyTuple_CheckExact(obj)) ? __Pyx_NewRef(obj) : PySequence_Tuple(obj))
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject*);
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t);
#if CYTHON_ASSUME_SAFE_MACROS
#define __pyx_PyFloat_AsDouble(x) (PyFloat_CheckExact(x) ? PyFloat_AS_DOUBLE(x) : PyFloat_AsDouble(x))
#else
#define __pyx_PyFloat_AsDouble(x) PyFloat_AsDouble(x)
#endif
#define __pyx_PyFloat_AsFloat(x) ((float) __pyx_PyFloat_AsDouble(x))
#if PY_MAJOR_VERSION >= 3
#define __Pyx_PyNumber_Int(x) (PyLong_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Long(x))
#else
#define __Pyx_PyNumber_Int(x) (PyInt_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Int(x))
#endif
#define __Pyx_PyNumber_Float(x) (PyFloat_CheckExact(x) ? __Pyx_NewRef(x) : PyNumber_Float(x))
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
static int __Pyx_sys_getdefaultencoding_not_ascii;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    PyObject* ascii_chars_u = NULL;
    PyObject* ascii_chars_b = NULL;
    const char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    if (strcmp(default_encoding_c, "ascii") == 0) {
        __Pyx_sys_getdefaultencoding_not_ascii = 0;
    } else {
        char ascii_chars[128];
        int c;
        for (c = 0; c < 128; c++) {
            ascii_chars[c] = c;
        }
        __Pyx_sys_getdefaultencoding_not_ascii = 1;
        ascii_chars_u = PyUnicode_DecodeASCII(ascii_chars, 128, NULL);
        if (!ascii_chars_u) goto bad;
        ascii_chars_b = PyUnicode_AsEncodedString(ascii_chars_u, default_encoding_c, NULL);
        if (!ascii_chars_b || !PyBytes_Check(ascii_chars_b) || memcmp(ascii_chars, PyBytes_AS_STRING(ascii_chars_b), 128) != 0) {
            PyErr_Format(
                PyExc_ValueError,
                "This module compiled with c_string_encoding=ascii, but default encoding '%.200s' is not a superset of ascii.",
                default_encoding_c);
            goto bad;
        }
        Py_DECREF(ascii_chars_u);
        Py_DECREF(ascii_chars_b);
    }
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    Py_XDECREF(ascii_chars_u);
    Py_XDECREF(ascii_chars_b);
    return -1;
}
#endif
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT && PY_MAJOR_VERSION >= 3
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_DecodeUTF8(c_str, size, NULL)
#else
#define __Pyx_PyUnicode_FromStringAndSize(c_str, size) PyUnicode_Decode(c_str, size, __PYX_DEFAULT_STRING_ENCODING, NULL)
#if __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
static char* __PYX_DEFAULT_STRING_ENCODING;
static int __Pyx_init_sys_getdefaultencoding_params(void) {
    PyObject* sys;
    PyObject* default_encoding = NULL;
    char* default_encoding_c;
    sys = PyImport_ImportModule("sys");
    if (!sys) goto bad;
    default_encoding = PyObject_CallMethod(sys, (char*) (const char*) "getdefaultencoding", NULL);
    Py_DECREF(sys);
    if (!default_encoding) goto bad;
    default_encoding_c = PyBytes_AsString(default_encoding);
    if (!default_encoding_c) goto bad;
    __PYX_DEFAULT_STRING_ENCODING = (char*) malloc(strlen(default_encoding_c) + 1);
    if (!__PYX_DEFAULT_STRING_ENCODING) goto bad;
    strcpy(__PYX_DEFAULT_STRING_ENCODING, default_encoding_c);
    Py_DECREF(default_encoding);
    return 0;
bad:
    Py_XDECREF(default_encoding);
    return -1;
}
#endif
#endif


/* Test for GCC > 2.95 */
#if defined(__GNUC__)     && (__GNUC__ > 2 || (__GNUC__ == 2 && (__GNUC_MINOR__ > 95)))
  #define likely(x)   __builtin_expect(!!(x), 1)
  #define unlikely(x) __builtin_expect(!!(x), 0)
#else /* !__GNUC__ or GCC < 2.95 */
  #define likely(x)   (x)
  #define unlikely(x) (x)
#endif /* __GNUC__ */
static CYTHON_INLINE void __Pyx_pretend_to_initialize(void* ptr) { (void)ptr; }

static PyObject *__pyx_m = NULL;
static PyObject *__pyx_d;
static PyObject *__pyx_b;
static PyObject *__pyx_cython_runtime = NULL;
static PyObject *__pyx_empty_tuple;
static PyObject *__pyx_empty_bytes;
static PyObject *__pyx_empty_unicode;
static int __pyx_lineno;
static int __pyx_clineno = 0;
static const char * __pyx_cfilenm= __FILE__;
static const char *__pyx_filename;

/* Header.proto */
#if !defined(CYTHON_CCOMPLEX)
  #if defined(__cplusplus)
    #define CYTHON_CCOMPLEX 1
  #elif defined(_Complex_I)
    #define CYTHON_CCOMPLEX 1
  #else
    #define CYTHON_CCOMPLEX 0
  #endif
#endif
#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    #include <complex>
  #else
    #include <complex.h>
  #endif
#endif
#if CYTHON_CCOMPLEX && !defined(__cplusplus) && defined(__sun__) && defined(__GNUC__)
  #undef _Complex_I
  #define _Complex_I 1.0fj
#endif


static const char *__pyx_f[] = {
  "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx",
  "__init__.pxd",
  "type.pxd",
};
/* BufferFormatStructs.proto */
#define IS_UNSIGNED(type) (((type) -1) > 0)
struct __Pyx_StructField_;
#define __PYX_BUF_FLAGS_PACKED_STRUCT (1 << 0)
typedef struct {
  const char* name;
  struct __Pyx_StructField_* fields;
  size_t size;
  size_t arraysize[8];
  int ndim;
  char typegroup;
  char is_unsigned;
  int flags;
} __Pyx_TypeInfo;
typedef struct __Pyx_StructField_ {
  __Pyx_TypeInfo* type;
  const char* name;
  size_t offset;
} __Pyx_StructField;
typedef struct {
  __Pyx_StructField* field;
  size_t parent_offset;
} __Pyx_BufFmt_StackElem;
typedef struct {
  __Pyx_StructField root;
  __Pyx_BufFmt_StackElem* head;
  size_t fmt_offset;
  size_t new_count, enc_count;
  size_t struct_alignment;
  int is_complex;
  char enc_type;
  char new_packmode;
  char enc_packmode;
  char is_valid_array;
} __Pyx_BufFmt_Context;


/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":775
 * # in Cython to enable them only on the right systems.
 *
 * ctypedef npy_int8       int8_t             # <<<<<<<<<<<<<<
 * ctypedef npy_int16      int16_t
 * ctypedef npy_int32      int32_t
 */
typedef npy_int8 __pyx_t_5numpy_int8_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":776
 *
 * ctypedef npy_int8       int8_t
 * ctypedef npy_int16      int16_t             # <<<<<<<<<<<<<<
 * ctypedef npy_int32      int32_t
 * ctypedef npy_int64      int64_t
 */
typedef npy_int16 __pyx_t_5numpy_int16_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":777
 * ctypedef npy_int8       int8_t
 * ctypedef npy_int16      int16_t
 * ctypedef npy_int32      int32_t             # <<<<<<<<<<<<<<
 * ctypedef npy_int64      int64_t
 * #ctypedef npy_int96      int96_t
 */
typedef npy_int32 __pyx_t_5numpy_int32_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":778
 * ctypedef npy_int16      int16_t
 * ctypedef npy_int32      int32_t
 * ctypedef npy_int64      int64_t             # <<<<<<<<<<<<<<
 * #ctypedef npy_int96      int96_t
 * #ctypedef npy_int128     int128_t
 */
typedef npy_int64 __pyx_t_5numpy_int64_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":782
 * #ctypedef npy_int128     int128_t
 *
 * ctypedef npy_uint8      uint8_t             # <<<<<<<<<<<<<<
 * ctypedef npy_uint16     uint16_t
 * ctypedef npy_uint32     uint32_t
 */
typedef npy_uint8 __pyx_t_5numpy_uint8_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":783
 *
 * ctypedef npy_uint8      uint8_t
 * ctypedef npy_uint16     uint16_t             # <<<<<<<<<<<<<<
 * ctypedef npy_uint32     uint32_t
 * ctypedef npy_uint64     uint64_t
 */
typedef npy_uint16 __pyx_t_5numpy_uint16_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":784
 * ctypedef npy_uint8      uint8_t
 * ctypedef npy_uint16     uint16_t
 * ctypedef npy_uint32     uint32_t             # <<<<<<<<<<<<<<
 * ctypedef npy_uint64     uint64_t
 * #ctypedef npy_uint96     uint96_t
 */
typedef npy_uint32 __pyx_t_5numpy_uint32_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":785
 * ctypedef npy_uint16     uint16_t
 * ctypedef npy_uint32     uint32_t
 * ctypedef npy_uint64     uint64_t             # <<<<<<<<<<<<<<
 * #ctypedef npy_uint96     uint96_t
 * #ctypedef npy_uint128    uint128_t
 */
typedef npy_uint64 __pyx_t_5numpy_uint64_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":789
 * #ctypedef npy_uint128    uint128_t
 *
 * ctypedef npy_float32    float32_t             # <<<<<<<<<<<<<<
 * ctypedef npy_float64    float64_t
 * #ctypedef npy_float80    float80_t
 */
typedef npy_float32 __pyx_t_5numpy_float32_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":790
 *
 * ctypedef npy_float32    float32_t
 * ctypedef npy_float64    float64_t             # <<<<<<<<<<<<<<
 * #ctypedef npy_float80    float80_t
 * #ctypedef npy_float128   float128_t
 */
typedef npy_float64 __pyx_t_5numpy_float64_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":799
 * # The int types are mapped a bit surprising --
 * # numpy.int corresponds to 'l' and numpy.long to 'q'
 * ctypedef npy_long       int_t             # <<<<<<<<<<<<<<
 * ctypedef npy_longlong   long_t
 * ctypedef npy_longlong   longlong_t
 */
typedef npy_long __pyx_t_5numpy_int_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":800
 * # numpy.int corresponds to 'l' and numpy.long to 'q'
 * ctypedef npy_long       int_t
 * ctypedef npy_longlong   long_t             # <<<<<<<<<<<<<<
 * ctypedef npy_longlong   longlong_t
 *
 */
typedef npy_longlong __pyx_t_5numpy_long_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":801
 * ctypedef npy_long       int_t
 * ctypedef npy_longlong   long_t
 * ctypedef npy_longlong   longlong_t             # <<<<<<<<<<<<<<
 *
 * ctypedef npy_ulong      uint_t
 */
typedef npy_longlong __pyx_t_5numpy_longlong_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":803
 * ctypedef npy_longlong   longlong_t
 *
 * ctypedef npy_ulong      uint_t             # <<<<<<<<<<<<<<
 * ctypedef npy_ulonglong  ulong_t
 * ctypedef npy_ulonglong  ulonglong_t
 */
typedef npy_ulong __pyx_t_5numpy_uint_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":804
 *
 * ctypedef npy_ulong      uint_t
 * ctypedef npy_ulonglong  ulong_t             # <<<<<<<<<<<<<<
 * ctypedef npy_ulonglong  ulonglong_t
 *
 */
typedef npy_ulonglong __pyx_t_5numpy_ulong_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":805
 * ctypedef npy_ulong      uint_t
 * ctypedef npy_ulonglong  ulong_t
 * ctypedef npy_ulonglong  ulonglong_t             # <<<<<<<<<<<<<<
 *
 * ctypedef npy_intp       intp_t
 */
typedef npy_ulonglong __pyx_t_5numpy_ulonglong_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":807
 * ctypedef npy_ulonglong  ulonglong_t
 *
 * ctypedef npy_intp       intp_t             # <<<<<<<<<<<<<<
 * ctypedef npy_uintp      uintp_t
 *
 */
typedef npy_intp __pyx_t_5numpy_intp_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":808
 *
 * ctypedef npy_intp       intp_t
 * ctypedef npy_uintp      uintp_t             # <<<<<<<<<<<<<<
 *
 * ctypedef npy_double     float_t
 */
typedef npy_uintp __pyx_t_5numpy_uintp_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":810
 * ctypedef npy_uintp      uintp_t
 *
 * ctypedef npy_double     float_t             # <<<<<<<<<<<<<<
 * ctypedef npy_double     double_t
 * ctypedef npy_longdouble longdouble_t
 */
typedef npy_double __pyx_t_5numpy_float_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":811
 *
 * ctypedef npy_double     float_t
 * ctypedef npy_double     double_t             # <<<<<<<<<<<<<<
 * ctypedef npy_longdouble longdouble_t
 *
 */
typedef npy_double __pyx_t_5numpy_double_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":812
 * ctypedef npy_double     float_t
 * ctypedef npy_double     double_t
 * ctypedef npy_longdouble longdouble_t             # <<<<<<<<<<<<<<
 *
 * ctypedef npy_cfloat      cfloat_t
 */
typedef npy_longdouble __pyx_t_5numpy_longdouble_t;
/* Declarations.proto */
#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    typedef ::std::complex< float > __pyx_t_float_complex;
  #else
    typedef float _Complex __pyx_t_float_complex;
  #endif
#else
    typedef struct { float real, imag; } __pyx_t_float_complex;
#endif
static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float, float);

/* Declarations.proto */
#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    typedef ::std::complex< double > __pyx_t_double_complex;
  #else
    typedef double _Complex __pyx_t_double_complex;
  #endif
#else
    typedef struct { double real, imag; } __pyx_t_double_complex;
#endif
static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double, double);


/*--- Type declarations ---*/

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":814
 * ctypedef npy_longdouble longdouble_t
 *
 * ctypedef npy_cfloat      cfloat_t             # <<<<<<<<<<<<<<
 * ctypedef npy_cdouble     cdouble_t
 * ctypedef npy_clongdouble clongdouble_t
 */
typedef npy_cfloat __pyx_t_5numpy_cfloat_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":815
 *
 * ctypedef npy_cfloat      cfloat_t
 * ctypedef npy_cdouble     cdouble_t             # <<<<<<<<<<<<<<
 * ctypedef npy_clongdouble clongdouble_t
 *
 */
typedef npy_cdouble __pyx_t_5numpy_cdouble_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":816
 * ctypedef npy_cfloat      cfloat_t
 * ctypedef npy_cdouble     cdouble_t
 * ctypedef npy_clongdouble clongdouble_t             # <<<<<<<<<<<<<<
 *
 * ctypedef npy_cdouble     complex_t
 */
typedef npy_clongdouble __pyx_t_5numpy_clongdouble_t;

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":818
 * ctypedef npy_clongdouble clongdouble_t
 *
 * ctypedef npy_cdouble     complex_t             # <<<<<<<<<<<<<<
 *
 * cdef inline object PyArray_MultiIterNew1(a):
 */
typedef npy_cdouble __pyx_t_5numpy_complex_t;

/* --- Runtime support code (head) --- */
/* Refnanny.proto */
#ifndef CYTHON_REFNANNY
  #define CYTHON_REFNANNY 0
#endif
#if CYTHON_REFNANNY
  typedef struct {
    void (*INCREF)(void*, PyObject*, int);
    void (*DECREF)(void*, PyObject*, int);
    void (*GOTREF)(void*, PyObject*, int);
    void (*GIVEREF)(void*, PyObject*, int);
    void* (*SetupContext)(const char*, int, const char*);
    void (*FinishContext)(void**);
  } __Pyx_RefNannyAPIStruct;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNanny = NULL;
  static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname);
  #define __Pyx_RefNannyDeclarations void *__pyx_refnanny = NULL;
#ifdef WITH_THREAD
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          if (acquire_gil) {\
              PyGILState_STATE __pyx_gilstate_save = PyGILState_Ensure();\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
              PyGILState_Release(__pyx_gilstate_save);\
          } else {\
              __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__);\
          }
#else
  #define __Pyx_RefNannySetupContext(name, acquire_gil)\
          __pyx_refnanny = __Pyx_RefNanny->SetupContext((name), __LINE__, __FILE__)
#endif
  #define __Pyx_RefNannyFinishContext()\
          __Pyx_RefNanny->FinishContext(&__pyx_refnanny)
  #define __Pyx_INCREF(r)  __Pyx_RefNanny->INCREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_DECREF(r)  __Pyx_RefNanny->DECREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GOTREF(r)  __Pyx_RefNanny->GOTREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_GIVEREF(r) __Pyx_RefNanny->GIVEREF(__pyx_refnanny, (PyObject *)(r), __LINE__)
  #define __Pyx_XINCREF(r)  do { if((r) != NULL) {__Pyx_INCREF(r); }} while(0)
  #define __Pyx_XDECREF(r)  do { if((r) != NULL) {__Pyx_DECREF(r); }} while(0)
  #define __Pyx_XGOTREF(r)  do { if((r) != NULL) {__Pyx_GOTREF(r); }} while(0)
  #define __Pyx_XGIVEREF(r) do { if((r) != NULL) {__Pyx_GIVEREF(r);}} while(0)
#else
  #define __Pyx_RefNannyDeclarations
  #define __Pyx_RefNannySetupContext(name, acquire_gil)
  #define __Pyx_RefNannyFinishContext()
  #define __Pyx_INCREF(r) Py_INCREF(r)
  #define __Pyx_DECREF(r) Py_DECREF(r)
  #define __Pyx_GOTREF(r)
  #define __Pyx_GIVEREF(r)
  #define __Pyx_XINCREF(r) Py_XINCREF(r)
  #define __Pyx_XDECREF(r) Py_XDECREF(r)
  #define __Pyx_XGOTREF(r)
  #define __Pyx_XGIVEREF(r)
#endif
#define __Pyx_XDECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_XDECREF(tmp);\
    } while (0)
#define __Pyx_DECREF_SET(r, v) do {\
        PyObject *tmp = (PyObject *) r;\
        r = v; __Pyx_DECREF(tmp);\
    } while (0)
#define __Pyx_CLEAR(r)    do { PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);} while(0)
#define __Pyx_XCLEAR(r)   do { if((r) != NULL) {PyObject* tmp = ((PyObject*)(r)); r = NULL; __Pyx_DECREF(tmp);}} while(0)

/* PyObjectGetAttrStr.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name);
#else
#define __Pyx_PyObject_GetAttrStr(o,n) PyObject_GetAttr(o,n)
#endif

/* GetBuiltinName.proto */
static PyObject *__Pyx_GetBuiltinName(PyObject *name);

/* RaiseArgTupleInvalid.proto */
static void __Pyx_RaiseArgtupleInvalid(const char* func_name, int exact,
    Py_ssize_t num_min, Py_ssize_t num_max, Py_ssize_t num_found);

/* RaiseDoubleKeywords.proto */
static void __Pyx_RaiseDoubleKeywordsError(const char* func_name, PyObject* kw_name);

/* ParseKeywords.proto */
static int __Pyx_ParseOptionalKeywords(PyObject *kwds, PyObject **argnames[],\
    PyObject *kwds2, PyObject *values[], Py_ssize_t num_pos_args,\
    const char* function_name);

/* ArgTypeTest.proto */
#define __Pyx_ArgTypeTest(obj, type, none_allowed, name, exact)\
    ((likely((Py_TYPE(obj) == type) | (none_allowed && (obj == Py_None)))) ? 1 :\
        __Pyx__ArgTypeTest(obj, type, name, exact))
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact);

/* IsLittleEndian.proto */
static CYTHON_INLINE int __Pyx_Is_Little_Endian(void);

/* BufferFormatCheck.proto */
static const char* __Pyx_BufFmt_CheckString(__Pyx_BufFmt_Context* ctx, const char* ts);
static void __Pyx_BufFmt_Init(__Pyx_BufFmt_Context* ctx,
                              __Pyx_BufFmt_StackElem* stack,
                              __Pyx_TypeInfo* type);

/* BufferGetAndValidate.proto */
#define __Pyx_GetBufferAndValidate(buf, obj, dtype, flags, nd, cast, stack)\
    ((obj == Py_None || obj == NULL) ?\
    (__Pyx_ZeroBuffer(buf), 0) :\
    __Pyx__GetBufferAndValidate(buf, obj, dtype, flags, nd, cast, stack))
static int  __Pyx__GetBufferAndValidate(Py_buffer* buf, PyObject* obj,
    __Pyx_TypeInfo* dtype, int flags, int nd, int cast, __Pyx_BufFmt_StackElem* stack);
static void __Pyx_ZeroBuffer(Py_buffer* buf);
static CYTHON_INLINE void __Pyx_SafeReleaseBuffer(Py_buffer* info);
static Py_ssize_t __Pyx_minusones[] = { -1, -1, -1, -1, -1, -1, -1, -1 };
static Py_ssize_t __Pyx_zeros[] = { 0, 0, 0, 0, 0, 0, 0, 0 };

/* PyFunctionFastCall.proto */
#if CYTHON_FAST_PYCALL
#define __Pyx_PyFunction_FastCall(func, args, nargs)\
    __Pyx_PyFunction_FastCallDict((func), (args), (nargs), NULL)
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs);
#else
#define __Pyx_PyFunction_FastCallDict(func, args, nargs, kwargs) _PyFunction_FastCallDict(func, args, nargs, kwargs)
#endif
#define __Pyx_BUILD_ASSERT_EXPR(cond)\
    (sizeof(char [1 - 2*!(cond)]) - 1)
#ifndef Py_MEMBER_SIZE
#define Py_MEMBER_SIZE(type, member) sizeof(((type *)0)->member)
#endif
  static size_t __pyx_pyframe_localsplus_offset = 0;
  #include "frameobject.h"
  #define __Pxy_PyFrame_Initialize_Offsets()\
    ((void)__Pyx_BUILD_ASSERT_EXPR(sizeof(PyFrameObject) == offsetof(PyFrameObject, f_localsplus) + Py_MEMBER_SIZE(PyFrameObject, f_localsplus)),\
     (void)(__pyx_pyframe_localsplus_offset = ((size_t)PyFrame_Type.tp_basicsize) - Py_MEMBER_SIZE(PyFrameObject, f_localsplus)))
  #define __Pyx_PyFrame_GetLocalsplus(frame)\
    (assert(__pyx_pyframe_localsplus_offset), (PyObject **)(((char *)(frame)) + __pyx_pyframe_localsplus_offset))
#endif

/* PyObjectCall.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw);
#else
#define __Pyx_PyObject_Call(func, arg, kw) PyObject_Call(func, arg, kw)
#endif

/* PyObjectCallMethO.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg);
#endif

/* PyObjectCallNoArg.proto */
#if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func);
#else
#define __Pyx_PyObject_CallNoArg(func) __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL)
#endif

/* PyCFunctionFastCall.proto */
#if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject *__Pyx_PyCFunction_FastCall(PyObject *func, PyObject **args, Py_ssize_t nargs);
#else
#define __Pyx_PyCFunction_FastCall(func, args, nargs)  (assert(0), NULL)
#endif

/* PyObjectCallOneArg.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg);

/* GetItemInt.proto */
#define __Pyx_GetItemInt(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Fast(o, (Py_ssize_t)i, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL) :\
               __Pyx_GetItemInt_Generic(o, to_py_func(i))))
#define __Pyx_GetItemInt_List(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_List_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "list index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
#define __Pyx_GetItemInt_Tuple(o, i, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_GetItemInt_Tuple_Fast(o, (Py_ssize_t)i, wraparound, boundscheck) :\
    (PyErr_SetString(PyExc_IndexError, "tuple index out of range"), (PyObject*)NULL))
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              int wraparound, int boundscheck);
static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j);
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i,
                                                     int is_list, int wraparound, int boundscheck);

/* PyDictVersioning.proto */
#if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
#define __PYX_DICT_VERSION_INIT  ((PY_UINT64_T) -1)
#define __PYX_GET_DICT_VERSION(dict)  (((PyDictObject*)(dict))->ma_version_tag)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)\
    (version_var) = __PYX_GET_DICT_VERSION(dict);\
    (cache_var) = (value);
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP) {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    if (likely(__PYX_GET_DICT_VERSION(DICT) == __pyx_dict_version)) {\
        (VAR) = __pyx_dict_cached_value;\
    } else {\
        (VAR) = __pyx_dict_cached_value = (LOOKUP);\
        __pyx_dict_version = __PYX_GET_DICT_VERSION(DICT);\
    }\
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj);
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj);
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version);
#else
#define __PYX_GET_DICT_VERSION(dict)  (0)
#define __PYX_UPDATE_DICT_CACHE(dict, value, cache_var, version_var)
#define __PYX_PY_DICT_LOOKUP_IF_MODIFIED(VAR, DICT, LOOKUP)  (VAR) = (LOOKUP);
#endif

/* GetModuleGlobalName.proto */
#if CYTHON_USE_DICT_VERSIONS
#define __Pyx_GetModuleGlobalName(var, name)  {\
    static PY_UINT64_T __pyx_dict_version = 0;\
    static PyObject *__pyx_dict_cached_value = NULL;\
    (var) = (likely(__pyx_dict_version == __PYX_GET_DICT_VERSION(__pyx_d))) ?\
        (likely(__pyx_dict_cached_value) ? __Pyx_NewRef(__pyx_dict_cached_value) : __Pyx_GetBuiltinName(name)) :\
        __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
#define __Pyx_GetModuleGlobalNameUncached(var, name)  {\
    PY_UINT64_T __pyx_dict_version;\
    PyObject *__pyx_dict_cached_value;\
    (var) = __Pyx__GetModuleGlobalName(name, &__pyx_dict_version, &__pyx_dict_cached_value);\
}
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value);
#else
#define __Pyx_GetModuleGlobalName(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
#define __Pyx_GetModuleGlobalNameUncached(var, name)  (var) = __Pyx__GetModuleGlobalName(name)
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name);
#endif

/* PyObjectCall2Args.proto */
static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2);

/* ObjectGetItem.proto */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key);
#else
#define __Pyx_PyObject_GetItem(obj, key)  PyObject_GetItem(obj, key)
#endif

/* PyIntBinop.proto */
#if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, long intval, int inplace, int zerodivision_check);
#else
#define __Pyx_PyInt_AddObjC(op1, op2, intval, inplace, zerodivision_check)\
    (inplace ? PyNumber_InPlaceAdd(op1, op2) : PyNumber_Add(op1, op2))
#endif

/* SetItemInt.proto */
#define __Pyx_SetItemInt(o, i, v, type, is_signed, to_py_func, is_list, wraparound, boundscheck)\
    (__Pyx_fits_Py_ssize_t(i, type, is_signed) ?\
    __Pyx_SetItemInt_Fast(o, (Py_ssize_t)i, v, is_list, wraparound, boundscheck) :\
    (is_list ? (PyErr_SetString(PyExc_IndexError, "list assignment index out of range"), -1) :\
               __Pyx_SetItemInt_Generic(o, to_py_func(i), v)))
static int __Pyx_SetItemInt_Generic(PyObject *o, PyObject *j, PyObject *v);
static CYTHON_INLINE int __Pyx_SetItemInt_Fast(PyObject *o, Py_ssize_t i, PyObject *v,
                                               int is_list, int wraparound, int boundscheck);

/* SliceObject.proto */
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetSlice(
        PyObject* obj, Py_ssize_t cstart, Py_ssize_t cstop,
        PyObject** py_start, PyObject** py_stop, PyObject** py_slice,
        int has_cstart, int has_cstop, int wraparound);

/* PyThreadStateGet.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyThreadState_declare  PyThreadState *__pyx_tstate;
#define __Pyx_PyThreadState_assign  __pyx_tstate = __Pyx_PyThreadState_Current;
#define __Pyx_PyErr_Occurred()  __pyx_tstate->curexc_type
#else
#define __Pyx_PyThreadState_declare
#define __Pyx_PyThreadState_assign
#define __Pyx_PyErr_Occurred()  PyErr_Occurred()
#endif

/* PyErrFetchRestore.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_Clear() __Pyx_ErrRestore(NULL, NULL, NULL)
#define __Pyx_ErrRestoreWithState(type, value, tb)  __Pyx_ErrRestoreInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)    __Pyx_ErrFetchInState(PyThreadState_GET(), type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  __Pyx_ErrRestoreInState(__pyx_tstate, type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)    __Pyx_ErrFetchInState(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_PyErr_SetNone(exc) (Py_INCREF(exc), __Pyx_ErrRestore((exc), NULL, NULL))
#else
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#endif
#else
#define __Pyx_PyErr_Clear() PyErr_Clear()
#define __Pyx_PyErr_SetNone(exc) PyErr_SetNone(exc)
#define __Pyx_ErrRestoreWithState(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchWithState(type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestoreInState(tstate, type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetchInState(tstate, type, value, tb)  PyErr_Fetch(type, value, tb)
#define __Pyx_ErrRestore(type, value, tb)  PyErr_Restore(type, value, tb)
#define __Pyx_ErrFetch(type, value, tb)  PyErr_Fetch(type, value, tb)
#endif

/* RaiseException.proto */
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause);

/* DictGetItem.proto */
#if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key);
#define __Pyx_PyObject_Dict_GetItem(obj, name)\
    (likely(PyDict_CheckExact(obj)) ?\
     __Pyx_PyDict_GetItem(obj, name) : PyObject_GetItem(obj, name))
#else
#define __Pyx_PyDict_GetItem(d, key) PyObject_GetItem(d, key)
#define __Pyx_PyObject_Dict_GetItem(obj, name)  PyObject_GetItem(obj, name)
#endif

/* RaiseTooManyValuesToUnpack.proto */
static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected);

/* RaiseNeedMoreValuesToUnpack.proto */
static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index);

/* RaiseNoneIterError.proto */
static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void);

/* ExtTypeTest.proto */
static CYTHON_INLINE int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type);

/* GetTopmostException.proto */
#if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem * __Pyx_PyErr_GetTopmostException(PyThreadState *tstate);
#endif

/* SaveResetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_ExceptionSave(type, value, tb)  __Pyx__ExceptionSave(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#define __Pyx_ExceptionReset(type, value, tb)  __Pyx__ExceptionReset(__pyx_tstate, type, value, tb)
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb);
#else
#define __Pyx_ExceptionSave(type, value, tb)   PyErr_GetExcInfo(type, value, tb)
#define __Pyx_ExceptionReset(type, value, tb)  PyErr_SetExcInfo(type, value, tb)
#endif

/* PyErrExceptionMatches.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_PyErr_ExceptionMatches(err) __Pyx_PyErr_ExceptionMatchesInState(__pyx_tstate, err)
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err);
#else
#define __Pyx_PyErr_ExceptionMatches(err)  PyErr_ExceptionMatches(err)
#endif

/* GetException.proto */
#if CYTHON_FAST_THREAD_STATE
#define __Pyx_GetException(type, value, tb)  __Pyx__GetException(__pyx_tstate, type, value, tb)
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb);
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb);
#endif

/* TypeImport.proto */
#ifndef __PYX_HAVE_RT_ImportType_proto
#define __PYX_HAVE_RT_ImportType_proto
enum __Pyx_ImportType_CheckSize {
   __Pyx_ImportType_CheckSize_Error = 0,
   __Pyx_ImportType_CheckSize_Warn = 1,
   __Pyx_ImportType_CheckSize_Ignore = 2
};
static PyTypeObject *__Pyx_ImportType(PyObject* module, const char *module_name, const char *class_name, size_t size, enum __Pyx_ImportType_CheckSize check_size);
#endif

/* Import.proto */
static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level);

/* CLineInTraceback.proto */
#ifdef CYTHON_CLINE_IN_TRACEBACK
#define __Pyx_CLineForTraceback(tstate, c_line)  (((CYTHON_CLINE_IN_TRACEBACK)) ? c_line : 0)
#else
static int __Pyx_CLineForTraceback(PyThreadState *tstate, int c_line);
#endif

/* CodeObjectCache.proto */
typedef struct {
    PyCodeObject* code_object;
    int code_line;
} __Pyx_CodeObjectCacheEntry;
struct __Pyx_CodeObjectCache {
    int count;
    int max_count;
    __Pyx_CodeObjectCacheEntry* entries;
};
static struct __Pyx_CodeObjectCache __pyx_code_cache = {0,0,NULL};
static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line);
static PyCodeObject *__pyx_find_code_object(int code_line);
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object);

/* AddTraceback.proto */
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename);

/* BufferStructDeclare.proto */
typedef struct {
  Py_ssize_t shape, strides, suboffsets;
} __Pyx_Buf_DimInfo;
typedef struct {
  size_t refcount;
  Py_buffer pybuffer;
} __Pyx_Buffer;
typedef struct {
  __Pyx_Buffer *rcbuffer;
  char *data;
  __Pyx_Buf_DimInfo diminfo[8];
} __Pyx_LocalBuf_ND;

#if PY_MAJOR_VERSION < 3
    static int __Pyx_GetBuffer(PyObject *obj, Py_buffer *view, int flags);
    static void __Pyx_ReleaseBuffer(Py_buffer *view);
#else
    #define __Pyx_GetBuffer PyObject_GetBuffer
    #define __Pyx_ReleaseBuffer PyBuffer_Release
#endif


/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value);

/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_unsigned_int(unsigned int value);

/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_int(int value);

/* RealImag.proto */
#if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    #define __Pyx_CREAL(z) ((z).real())
    #define __Pyx_CIMAG(z) ((z).imag())
  #else
    #define __Pyx_CREAL(z) (__real__(z))
    #define __Pyx_CIMAG(z) (__imag__(z))
  #endif
#else
    #define __Pyx_CREAL(z) ((z).real)
    #define __Pyx_CIMAG(z) ((z).imag)
#endif
#if defined(__cplusplus) && CYTHON_CCOMPLEX\
        && (defined(_WIN32) || defined(__clang__) || (defined(__GNUC__) && (__GNUC__ >= 5 || __GNUC__ == 4 && __GNUC_MINOR__ >= 4 )) || __cplusplus >= 201103)
    #define __Pyx_SET_CREAL(z,x) ((z).real(x))
    #define __Pyx_SET_CIMAG(z,y) ((z).imag(y))
#else
    #define __Pyx_SET_CREAL(z,x) __Pyx_CREAL(z) = (x)
    #define __Pyx_SET_CIMAG(z,y) __Pyx_CIMAG(z) = (y)
#endif

/* Arithmetic.proto */
#if CYTHON_CCOMPLEX
    #define __Pyx_c_eq_float(a, b)   ((a)==(b))
    #define __Pyx_c_sum_float(a, b)  ((a)+(b))
    #define __Pyx_c_diff_float(a, b) ((a)-(b))
    #define __Pyx_c_prod_float(a, b) ((a)*(b))
    #define __Pyx_c_quot_float(a, b) ((a)/(b))
    #define __Pyx_c_neg_float(a)     (-(a))
  #ifdef __cplusplus
    #define __Pyx_c_is_zero_float(z) ((z)==(float)0)
    #define __Pyx_c_conj_float(z)    (::std::conj(z))
    #if 1
        #define __Pyx_c_abs_float(z)     (::std::abs(z))
        #define __Pyx_c_pow_float(a, b)  (::std::pow(a, b))
    #endif
  #else
    #define __Pyx_c_is_zero_float(z) ((z)==0)
    #define __Pyx_c_conj_float(z)    (conjf(z))
    #if 1
        #define __Pyx_c_abs_float(z)     (cabsf(z))
        #define __Pyx_c_pow_float(a, b)  (cpowf(a, b))
    #endif
 #endif
#else
    static CYTHON_INLINE int __Pyx_c_eq_float(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_sum_float(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_diff_float(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_prod_float(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_quot_float(__pyx_t_float_complex, __pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_neg_float(__pyx_t_float_complex);
    static CYTHON_INLINE int __Pyx_c_is_zero_float(__pyx_t_float_complex);
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_conj_float(__pyx_t_float_complex);
    #if 1
        static CYTHON_INLINE float __Pyx_c_abs_float(__pyx_t_float_complex);
        static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_pow_float(__pyx_t_float_complex, __pyx_t_float_complex);
    #endif
#endif

/* Arithmetic.proto */
#if CYTHON_CCOMPLEX
    #define __Pyx_c_eq_double(a, b)   ((a)==(b))
    #define __Pyx_c_sum_double(a, b)  ((a)+(b))
    #define __Pyx_c_diff_double(a, b) ((a)-(b))
    #define __Pyx_c_prod_double(a, b) ((a)*(b))
    #define __Pyx_c_quot_double(a, b) ((a)/(b))
    #define __Pyx_c_neg_double(a)     (-(a))
  #ifdef __cplusplus
    #define __Pyx_c_is_zero_double(z) ((z)==(double)0)
    #define __Pyx_c_conj_double(z)    (::std::conj(z))
    #if 1
        #define __Pyx_c_abs_double(z)     (::std::abs(z))
        #define __Pyx_c_pow_double(a, b)  (::std::pow(a, b))
    #endif
  #else
    #define __Pyx_c_is_zero_double(z) ((z)==0)
    #define __Pyx_c_conj_double(z)    (conj(z))
    #if 1
        #define __Pyx_c_abs_double(z)     (cabs(z))
        #define __Pyx_c_pow_double(a, b)  (cpow(a, b))
    #endif
 #endif
#else
    static CYTHON_INLINE int __Pyx_c_eq_double(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_sum_double(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_diff_double(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_prod_double(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_quot_double(__pyx_t_double_complex, __pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_neg_double(__pyx_t_double_complex);
    static CYTHON_INLINE int __Pyx_c_is_zero_double(__pyx_t_double_complex);
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_conj_double(__pyx_t_double_complex);
    #if 1
        static CYTHON_INLINE double __Pyx_c_abs_double(__pyx_t_double_complex);
        static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_pow_double(__pyx_t_double_complex, __pyx_t_double_complex);
    #endif
#endif

/* CIntToPy.proto */
static CYTHON_INLINE PyObject* __Pyx_PyInt_From_enum__NPY_TYPES(enum NPY_TYPES value);

/* CIntFromPy.proto */
static CYTHON_INLINE unsigned int __Pyx_PyInt_As_unsigned_int(PyObject *);

/* CIntFromPy.proto */
static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *);

/* CIntFromPy.proto */
static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *);

/* FastTypeChecks.proto */
#if CYTHON_COMPILING_IN_CPYTHON
#define __Pyx_TypeCheck(obj, type) __Pyx_IsSubtype(Py_TYPE(obj), (PyTypeObject *)type)
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject *type);
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *type1, PyObject *type2);
#else
#define __Pyx_TypeCheck(obj, type) PyObject_TypeCheck(obj, (PyTypeObject *)type)
#define __Pyx_PyErr_GivenExceptionMatches(err, type) PyErr_GivenExceptionMatches(err, type)
#define __Pyx_PyErr_GivenExceptionMatches2(err, type1, type2) (PyErr_GivenExceptionMatches(err, type1) || PyErr_GivenExceptionMatches(err, type2))
#endif
#define __Pyx_PyException_Check(obj) __Pyx_TypeCheck(obj, PyExc_Exception)

/* CheckBinaryVersion.proto */
static int __Pyx_check_binary_version(void);

/* InitStrings.proto */
static int __Pyx_InitStrings(__Pyx_StringTabEntry *t);


/* Module declarations from 'cpython.buffer' */

/* Module declarations from 'libc.string' */

/* Module declarations from 'libc.stdio' */

/* Module declarations from '__builtin__' */

/* Module declarations from 'cpython.type' */
static PyTypeObject *__pyx_ptype_7cpython_4type_type = 0;

/* Module declarations from 'cpython' */

/* Module declarations from 'cpython.object' */

/* Module declarations from 'cpython.ref' */

/* Module declarations from 'cpython.mem' */

/* Module declarations from 'numpy' */

/* Module declarations from 'numpy' */
static PyTypeObject *__pyx_ptype_5numpy_dtype = 0;
static PyTypeObject *__pyx_ptype_5numpy_flatiter = 0;
static PyTypeObject *__pyx_ptype_5numpy_broadcast = 0;
static PyTypeObject *__pyx_ptype_5numpy_ndarray = 0;
static PyTypeObject *__pyx_ptype_5numpy_ufunc = 0;
static CYTHON_INLINE char *__pyx_f_5numpy__util_dtypestring(PyArray_Descr *, char *, char *, int *); /*proto*/

/* Module declarations from 'mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu' */
static CYTHON_INLINE __pyx_t_5numpy_float32_t __pyx_f_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_max(__pyx_t_5numpy_float32_t, __pyx_t_5numpy_float32_t); /*proto*/
static CYTHON_INLINE __pyx_t_5numpy_float32_t __pyx_f_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_min(__pyx_t_5numpy_float32_t, __pyx_t_5numpy_float32_t); /*proto*/
static __Pyx_TypeInfo __Pyx_TypeInfo_float = { "float", NULL, sizeof(float), { 0 }, 0, 'R', 0, 0 };
#define __Pyx_MODULE_NAME "mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu"
extern int __pyx_module_is_main_mmmovie__detector__persondet__modules__core__ops__nms__soft_nms_cpu;
int __pyx_module_is_main_mmmovie__detector__persondet__modules__core__ops__nms__soft_nms_cpu = 0;

/* Implementation of 'mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu' */
static PyObject *__pyx_builtin_range;
static PyObject *__pyx_builtin_ValueError;
static PyObject *__pyx_builtin_RuntimeError;
static PyObject *__pyx_builtin_ImportError;
static const char __pyx_k_N[] = "N";
static const char __pyx_k_i[] = "i";
static const char __pyx_k_s[] = "s";
static const char __pyx_k_ih[] = "ih";
static const char __pyx_k_iw[] = "iw";
static const char __pyx_k_np[] = "np";
static const char __pyx_k_ov[] = "ov";
static const char __pyx_k_ti[] = "ti";
static const char __pyx_k_ts[] = "ts";
static const char __pyx_k_ua[] = "ua";
static const char __pyx_k_x1[] = "x1";
static const char __pyx_k_x2[] = "x2";
static const char __pyx_k_y1[] = "y1";
static const char __pyx_k_y2[] = "y2";
static const char __pyx_k_exp[] = "exp";
static const char __pyx_k_pos[] = "pos";
static const char __pyx_k_tx1[] = "tx1";
static const char __pyx_k_tx2[] = "tx2";
static const char __pyx_k_ty1[] = "ty1";
static const char __pyx_k_ty2[] = "ty2";
static const char __pyx_k_area[] = "area";
static const char __pyx_k_copy[] = "copy";
static const char __pyx_k_inds[] = "inds";
static const char __pyx_k_main[] = "__main__";
static const char __pyx_k_name[] = "__name__";
static const char __pyx_k_test[] = "__test__";
static const char __pyx_k_boxes[] = "boxes";
static const char __pyx_k_numpy[] = "numpy";
static const char __pyx_k_range[] = "range";
static const char __pyx_k_shape[] = "shape";
static const char __pyx_k_sigma[] = "sigma";
static const char __pyx_k_arange[] = "arange";
static const char __pyx_k_import[] = "__import__";
static const char __pyx_k_maxpos[] = "maxpos";
static const char __pyx_k_method[] = "method";
static const char __pyx_k_weight[] = "weight";
static const char __pyx_k_iou_thr[] = "iou_thr";
static const char __pyx_k_box_area[] = "box_area";
static const char __pyx_k_boxes_in[] = "boxes_in";
static const char __pyx_k_maxscore[] = "maxscore";
static const char __pyx_k_min_score[] = "min_score";
static const char __pyx_k_ValueError[] = "ValueError";
static const char __pyx_k_ImportError[] = "ImportError";
static const char __pyx_k_RuntimeError[] = "RuntimeError";
static const char __pyx_k_soft_nms_cpu[] = "soft_nms_cpu";
static const char __pyx_k_cline_in_traceback[] = "cline_in_traceback";
static const char __pyx_k_ndarray_is_not_C_contiguous[] = "ndarray is not C contiguous";
static const char __pyx_k_numpy_core_multiarray_failed_to[] = "numpy.core.multiarray failed to import";
static const char __pyx_k_unknown_dtype_code_in_numpy_pxd[] = "unknown dtype code in numpy.pxd (%d)";
static const char __pyx_k_Format_string_allocated_too_shor[] = "Format string allocated too short, see comment in numpy.pxd";
static const char __pyx_k_Non_native_byte_order_not_suppor[] = "Non-native byte order not supported";
static const char __pyx_k_mmmovie_detector_persondet_modul[] = "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx";
static const char __pyx_k_ndarray_is_not_Fortran_contiguou[] = "ndarray is not Fortran contiguous";
static const char __pyx_k_numpy_core_umath_failed_to_impor[] = "numpy.core.umath failed to import";
static const char __pyx_k_Format_string_allocated_too_shor_2[] = "Format string allocated too short.";
static const char __pyx_k_mmmovie_detector_persondet_modul_2[] = "mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu";
static PyObject *__pyx_kp_u_Format_string_allocated_too_shor;
static PyObject *__pyx_kp_u_Format_string_allocated_too_shor_2;
static PyObject *__pyx_n_s_ImportError;
static PyObject *__pyx_n_s_N;
static PyObject *__pyx_kp_u_Non_native_byte_order_not_suppor;
static PyObject *__pyx_n_s_RuntimeError;
static PyObject *__pyx_n_s_ValueError;
static PyObject *__pyx_n_s_arange;
static PyObject *__pyx_n_s_area;
static PyObject *__pyx_n_s_box_area;
static PyObject *__pyx_n_s_boxes;
static PyObject *__pyx_n_s_boxes_in;
static PyObject *__pyx_n_s_cline_in_traceback;
static PyObject *__pyx_n_s_copy;
static PyObject *__pyx_n_s_exp;
static PyObject *__pyx_n_s_i;
static PyObject *__pyx_n_s_ih;
static PyObject *__pyx_n_s_import;
static PyObject *__pyx_n_s_inds;
static PyObject *__pyx_n_s_iou_thr;
static PyObject *__pyx_n_s_iw;
static PyObject *__pyx_n_s_main;
static PyObject *__pyx_n_s_maxpos;
static PyObject *__pyx_n_s_maxscore;
static PyObject *__pyx_n_s_method;
static PyObject *__pyx_n_s_min_score;
static PyObject *__pyx_kp_s_mmmovie_detector_persondet_modul;
static PyObject *__pyx_n_s_mmmovie_detector_persondet_modul_2;
static PyObject *__pyx_n_s_name;
static PyObject *__pyx_kp_u_ndarray_is_not_C_contiguous;
static PyObject *__pyx_kp_u_ndarray_is_not_Fortran_contiguou;
static PyObject *__pyx_n_s_np;
static PyObject *__pyx_n_s_numpy;
static PyObject *__pyx_kp_u_numpy_core_multiarray_failed_to;
static PyObject *__pyx_kp_u_numpy_core_umath_failed_to_impor;
static PyObject *__pyx_n_s_ov;
static PyObject *__pyx_n_s_pos;
static PyObject *__pyx_n_s_range;
static PyObject *__pyx_n_s_s;
static PyObject *__pyx_n_s_shape;
static PyObject *__pyx_n_s_sigma;
static PyObject *__pyx_n_s_soft_nms_cpu;
static PyObject *__pyx_n_s_test;
static PyObject *__pyx_n_s_ti;
static PyObject *__pyx_n_s_ts;
static PyObject *__pyx_n_s_tx1;
static PyObject *__pyx_n_s_tx2;
static PyObject *__pyx_n_s_ty1;
static PyObject *__pyx_n_s_ty2;
static PyObject *__pyx_n_s_ua;
static PyObject *__pyx_kp_u_unknown_dtype_code_in_numpy_pxd;
static PyObject *__pyx_n_s_weight;
static PyObject *__pyx_n_s_x1;
static PyObject *__pyx_n_s_x2;
static PyObject *__pyx_n_s_y1;
static PyObject *__pyx_n_s_y2;
static PyObject *__pyx_pf_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_soft_nms_cpu(CYTHON_UNUSED PyObject *__pyx_self, PyArrayObject *__pyx_v_boxes_in, float __pyx_v_iou_thr, unsigned int __pyx_v_method, float __pyx_v_sigma, float __pyx_v_min_score); /* proto */
static int __pyx_pf_5numpy_7ndarray___getbuffer__(PyArrayObject *__pyx_v_self, Py_buffer *__pyx_v_info, int __pyx_v_flags); /* proto */
static void __pyx_pf_5numpy_7ndarray_2__releasebuffer__(PyArrayObject *__pyx_v_self, Py_buffer *__pyx_v_info); /* proto */
static PyObject *__pyx_int_0;
static PyObject *__pyx_int_1;
static PyObject *__pyx_int_2;
static PyObject *__pyx_int_3;
static PyObject *__pyx_int_4;
static PyObject *__pyx_tuple_;
static PyObject *__pyx_tuple__2;
static PyObject *__pyx_tuple__3;
static PyObject *__pyx_tuple__4;
static PyObject *__pyx_tuple__5;
static PyObject *__pyx_tuple__6;
static PyObject *__pyx_tuple__7;
static PyObject *__pyx_tuple__8;
static PyObject *__pyx_codeobj__9;
/* Late includes */

/* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":15
 *
 *
 * cdef inline np.float32_t max(np.float32_t a, np.float32_t b):             # <<<<<<<<<<<<<<
 *     return a if a >= b else b
 *
 */

static CYTHON_INLINE __pyx_t_5numpy_float32_t __pyx_f_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_max(__pyx_t_5numpy_float32_t __pyx_v_a, __pyx_t_5numpy_float32_t __pyx_v_b) {
  __pyx_t_5numpy_float32_t __pyx_r;
  __Pyx_RefNannyDeclarations
  __pyx_t_5numpy_float32_t __pyx_t_1;
  __Pyx_RefNannySetupContext("max", 0);

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":16
 *
 * cdef inline np.float32_t max(np.float32_t a, np.float32_t b):
 *     return a if a >= b else b             # <<<<<<<<<<<<<<
 *
 * cdef inline np.float32_t min(np.float32_t a, np.float32_t b):
 */
  if (((__pyx_v_a >= __pyx_v_b) != 0)) {
    __pyx_t_1 = __pyx_v_a;
  } else {
    __pyx_t_1 = __pyx_v_b;
  }
  __pyx_r = __pyx_t_1;
  goto __pyx_L0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":15
 *
 *
 * cdef inline np.float32_t max(np.float32_t a, np.float32_t b):             # <<<<<<<<<<<<<<
 *     return a if a >= b else b
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":18
 *     return a if a >= b else b
 *
 * cdef inline np.float32_t min(np.float32_t a, np.float32_t b):             # <<<<<<<<<<<<<<
 *     return a if a <= b else b
 *
 */

static CYTHON_INLINE __pyx_t_5numpy_float32_t __pyx_f_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_min(__pyx_t_5numpy_float32_t __pyx_v_a, __pyx_t_5numpy_float32_t __pyx_v_b) {
  __pyx_t_5numpy_float32_t __pyx_r;
  __Pyx_RefNannyDeclarations
  __pyx_t_5numpy_float32_t __pyx_t_1;
  __Pyx_RefNannySetupContext("min", 0);

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":19
 *
 * cdef inline np.float32_t min(np.float32_t a, np.float32_t b):
 *     return a if a <= b else b             # <<<<<<<<<<<<<<
 *
 *
 */
  if (((__pyx_v_a <= __pyx_v_b) != 0)) {
    __pyx_t_1 = __pyx_v_a;
  } else {
    __pyx_t_1 = __pyx_v_b;
  }
  __pyx_r = __pyx_t_1;
  goto __pyx_L0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":18
 *     return a if a >= b else b
 *
 * cdef inline np.float32_t min(np.float32_t a, np.float32_t b):             # <<<<<<<<<<<<<<
 *     return a if a <= b else b
 *
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":22
 *
 *
 * def soft_nms_cpu(             # <<<<<<<<<<<<<<
 *     np.ndarray[float, ndim=2] boxes_in,
 *     float iou_thr,
 */

/* Python wrapper */
static PyObject *__pyx_pw_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_1soft_nms_cpu(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds); /*proto*/
static PyMethodDef __pyx_mdef_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_1soft_nms_cpu = {"soft_nms_cpu", (PyCFunction)(void*)(PyCFunctionWithKeywords)__pyx_pw_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_1soft_nms_cpu, METH_VARARGS|METH_KEYWORDS, 0};
static PyObject *__pyx_pw_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_1soft_nms_cpu(PyObject *__pyx_self, PyObject *__pyx_args, PyObject *__pyx_kwds) {
  PyArrayObject *__pyx_v_boxes_in = 0;
  float __pyx_v_iou_thr;
  unsigned int __pyx_v_method;
  float __pyx_v_sigma;
  float __pyx_v_min_score;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  PyObject *__pyx_r = 0;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("soft_nms_cpu (wrapper)", 0);
  {
    static PyObject **__pyx_pyargnames[] = {&__pyx_n_s_boxes_in,&__pyx_n_s_iou_thr,&__pyx_n_s_method,&__pyx_n_s_sigma,&__pyx_n_s_min_score,0};
    PyObject* values[5] = {0,0,0,0,0};
    if (unlikely(__pyx_kwds)) {
      Py_ssize_t kw_args;
      const Py_ssize_t pos_args = PyTuple_GET_SIZE(__pyx_args);
      switch (pos_args) {
        case  5: values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
        CYTHON_FALLTHROUGH;
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        CYTHON_FALLTHROUGH;
        case  1: values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        CYTHON_FALLTHROUGH;
        case  0: break;
        default: goto __pyx_L5_argtuple_error;
      }
      kw_args = PyDict_Size(__pyx_kwds);
      switch (pos_args) {
        case  0:
        if (likely((values[0] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_boxes_in)) != 0)) kw_args--;
        else goto __pyx_L5_argtuple_error;
        CYTHON_FALLTHROUGH;
        case  1:
        if (likely((values[1] = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_iou_thr)) != 0)) kw_args--;
        else {
          __Pyx_RaiseArgtupleInvalid("soft_nms_cpu", 0, 2, 5, 1); __PYX_ERR(0, 22, __pyx_L3_error)
        }
        CYTHON_FALLTHROUGH;
        case  2:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_method);
          if (value) { values[2] = value; kw_args--; }
        }
        CYTHON_FALLTHROUGH;
        case  3:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_sigma);
          if (value) { values[3] = value; kw_args--; }
        }
        CYTHON_FALLTHROUGH;
        case  4:
        if (kw_args > 0) {
          PyObject* value = __Pyx_PyDict_GetItemStr(__pyx_kwds, __pyx_n_s_min_score);
          if (value) { values[4] = value; kw_args--; }
        }
      }
      if (unlikely(kw_args > 0)) {
        if (unlikely(__Pyx_ParseOptionalKeywords(__pyx_kwds, __pyx_pyargnames, 0, values, pos_args, "soft_nms_cpu") < 0)) __PYX_ERR(0, 22, __pyx_L3_error)
      }
    } else {
      switch (PyTuple_GET_SIZE(__pyx_args)) {
        case  5: values[4] = PyTuple_GET_ITEM(__pyx_args, 4);
        CYTHON_FALLTHROUGH;
        case  4: values[3] = PyTuple_GET_ITEM(__pyx_args, 3);
        CYTHON_FALLTHROUGH;
        case  3: values[2] = PyTuple_GET_ITEM(__pyx_args, 2);
        CYTHON_FALLTHROUGH;
        case  2: values[1] = PyTuple_GET_ITEM(__pyx_args, 1);
        values[0] = PyTuple_GET_ITEM(__pyx_args, 0);
        break;
        default: goto __pyx_L5_argtuple_error;
      }
    }
    __pyx_v_boxes_in = ((PyArrayObject *)values[0]);
    __pyx_v_iou_thr = __pyx_PyFloat_AsFloat(values[1]); if (unlikely((__pyx_v_iou_thr == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 24, __pyx_L3_error)
    if (values[2]) {
      __pyx_v_method = __Pyx_PyInt_As_unsigned_int(values[2]); if (unlikely((__pyx_v_method == (unsigned int)-1) && PyErr_Occurred())) __PYX_ERR(0, 25, __pyx_L3_error)
    } else {
      __pyx_v_method = ((unsigned int)1);
    }
    if (values[3]) {
      __pyx_v_sigma = __pyx_PyFloat_AsFloat(values[3]); if (unlikely((__pyx_v_sigma == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 26, __pyx_L3_error)
    } else {
      __pyx_v_sigma = ((float)0.5);
    }
    if (values[4]) {
      __pyx_v_min_score = __pyx_PyFloat_AsFloat(values[4]); if (unlikely((__pyx_v_min_score == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 27, __pyx_L3_error)
    } else {
      __pyx_v_min_score = ((float)0.001);
    }
  }
  goto __pyx_L4_argument_unpacking_done;
  __pyx_L5_argtuple_error:;
  __Pyx_RaiseArgtupleInvalid("soft_nms_cpu", 0, 2, 5, PyTuple_GET_SIZE(__pyx_args)); __PYX_ERR(0, 22, __pyx_L3_error)
  __pyx_L3_error:;
  __Pyx_AddTraceback("mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu.soft_nms_cpu", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __Pyx_RefNannyFinishContext();
  return NULL;
  __pyx_L4_argument_unpacking_done:;
  if (unlikely(!__Pyx_ArgTypeTest(((PyObject *)__pyx_v_boxes_in), __pyx_ptype_5numpy_ndarray, 1, "boxes_in", 0))) __PYX_ERR(0, 23, __pyx_L1_error)
  __pyx_r = __pyx_pf_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_soft_nms_cpu(__pyx_self, __pyx_v_boxes_in, __pyx_v_iou_thr, __pyx_v_method, __pyx_v_sigma, __pyx_v_min_score);

  /* function exit code */
  goto __pyx_L0;
  __pyx_L1_error:;
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyObject *__pyx_pf_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_soft_nms_cpu(CYTHON_UNUSED PyObject *__pyx_self, PyArrayObject *__pyx_v_boxes_in, float __pyx_v_iou_thr, unsigned int __pyx_v_method, float __pyx_v_sigma, float __pyx_v_min_score) {
  PyObject *__pyx_v_boxes = NULL;
  unsigned int __pyx_v_N;
  float __pyx_v_iw;
  float __pyx_v_ih;
  float __pyx_v_ua;
  int __pyx_v_pos;
  float __pyx_v_maxscore;
  int __pyx_v_maxpos;
  float __pyx_v_x1;
  float __pyx_v_x2;
  float __pyx_v_y1;
  float __pyx_v_y2;
  float __pyx_v_tx1;
  float __pyx_v_tx2;
  float __pyx_v_ty1;
  float __pyx_v_ty2;
  float __pyx_v_ts;
  float __pyx_v_area;
  float __pyx_v_weight;
  float __pyx_v_ov;
  PyObject *__pyx_v_inds = NULL;
  PyObject *__pyx_v_i = NULL;
  PyObject *__pyx_v_ti = NULL;
  CYTHON_UNUSED PyObject *__pyx_v_s = NULL;
  __Pyx_LocalBuf_ND __pyx_pybuffernd_boxes_in;
  __Pyx_Buffer __pyx_pybuffer_boxes_in;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  unsigned int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  Py_ssize_t __pyx_t_6;
  PyObject *(*__pyx_t_7)(PyObject *);
  float __pyx_t_8;
  int __pyx_t_9;
  int __pyx_t_10;
  PyObject *__pyx_t_11 = NULL;
  long __pyx_t_12;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("soft_nms_cpu", 0);
  __pyx_pybuffer_boxes_in.pybuffer.buf = NULL;
  __pyx_pybuffer_boxes_in.refcount = 0;
  __pyx_pybuffernd_boxes_in.data = NULL;
  __pyx_pybuffernd_boxes_in.rcbuffer = &__pyx_pybuffer_boxes_in;
  {
    __Pyx_BufFmt_StackElem __pyx_stack[1];
    if (unlikely(__Pyx_GetBufferAndValidate(&__pyx_pybuffernd_boxes_in.rcbuffer->pybuffer, (PyObject*)__pyx_v_boxes_in, &__Pyx_TypeInfo_float, PyBUF_FORMAT| PyBUF_STRIDES, 2, 0, __pyx_stack) == -1)) __PYX_ERR(0, 22, __pyx_L1_error)
  }
  __pyx_pybuffernd_boxes_in.diminfo[0].strides = __pyx_pybuffernd_boxes_in.rcbuffer->pybuffer.strides[0]; __pyx_pybuffernd_boxes_in.diminfo[0].shape = __pyx_pybuffernd_boxes_in.rcbuffer->pybuffer.shape[0]; __pyx_pybuffernd_boxes_in.diminfo[1].strides = __pyx_pybuffernd_boxes_in.rcbuffer->pybuffer.strides[1]; __pyx_pybuffernd_boxes_in.diminfo[1].shape = __pyx_pybuffernd_boxes_in.rcbuffer->pybuffer.shape[1];

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":29
 *     float min_score=0.001,
 * ):
 *     boxes = boxes_in.copy()             # <<<<<<<<<<<<<<
 *     cdef unsigned N = boxes.shape[0]
 *     cdef float iw, ih, box_area
 */
  __pyx_t_2 = __Pyx_PyObject_GetAttrStr(((PyObject *)__pyx_v_boxes_in), __pyx_n_s_copy); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = NULL;
  if (CYTHON_UNPACK_METHODS && likely(PyMethod_Check(__pyx_t_2))) {
    __pyx_t_3 = PyMethod_GET_SELF(__pyx_t_2);
    if (likely(__pyx_t_3)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_2);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_2, function);
    }
  }
  __pyx_t_1 = (__pyx_t_3) ? __Pyx_PyObject_CallOneArg(__pyx_t_2, __pyx_t_3) : __Pyx_PyObject_CallNoArg(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
  if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 29, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_boxes = __pyx_t_1;
  __pyx_t_1 = 0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":30
 * ):
 *     boxes = boxes_in.copy()
 *     cdef unsigned N = boxes.shape[0]             # <<<<<<<<<<<<<<
 *     cdef float iw, ih, box_area
 *     cdef float ua
 */
  __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_v_boxes, __pyx_n_s_shape); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_2 = __Pyx_GetItemInt(__pyx_t_1, 0, long, 1, __Pyx_PyInt_From_long, 0, 0, 0); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_4 = __Pyx_PyInt_As_unsigned_int(__pyx_t_2); if (unlikely((__pyx_t_4 == (unsigned int)-1) && PyErr_Occurred())) __PYX_ERR(0, 30, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  __pyx_v_N = __pyx_t_4;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":33
 *     cdef float iw, ih, box_area
 *     cdef float ua
 *     cdef int pos = 0             # <<<<<<<<<<<<<<
 *     cdef float maxscore = 0
 *     cdef int maxpos = 0
 */
  __pyx_v_pos = 0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":34
 *     cdef float ua
 *     cdef int pos = 0
 *     cdef float maxscore = 0             # <<<<<<<<<<<<<<
 *     cdef int maxpos = 0
 *     cdef float x1, x2, y1, y2, tx1, tx2, ty1, ty2, ts, area, weight, ov
 */
  __pyx_v_maxscore = 0.0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":35
 *     cdef int pos = 0
 *     cdef float maxscore = 0
 *     cdef int maxpos = 0             # <<<<<<<<<<<<<<
 *     cdef float x1, x2, y1, y2, tx1, tx2, ty1, ty2, ts, area, weight, ov
 *     inds = np.arange(N)
 */
  __pyx_v_maxpos = 0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":37
 *     cdef int maxpos = 0
 *     cdef float x1, x2, y1, y2, tx1, tx2, ty1, ty2, ts, area, weight, ov
 *     inds = np.arange(N)             # <<<<<<<<<<<<<<
 *
 *     for i in range(N):
 */
  __Pyx_GetModuleGlobalName(__pyx_t_1, __pyx_n_s_np); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 37, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_3 = __Pyx_PyObject_GetAttrStr(__pyx_t_1, __pyx_n_s_arange); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 37, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = __Pyx_PyInt_From_unsigned_int(__pyx_v_N); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 37, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = NULL;
  if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_3))) {
    __pyx_t_5 = PyMethod_GET_SELF(__pyx_t_3);
    if (likely(__pyx_t_5)) {
      PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_5);
      __Pyx_INCREF(function);
      __Pyx_DECREF_SET(__pyx_t_3, function);
    }
  }
  __pyx_t_2 = (__pyx_t_5) ? __Pyx_PyObject_Call2Args(__pyx_t_3, __pyx_t_5, __pyx_t_1) : __Pyx_PyObject_CallOneArg(__pyx_t_3, __pyx_t_1);
  __Pyx_XDECREF(__pyx_t_5); __pyx_t_5 = 0;
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 37, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  __pyx_v_inds = __pyx_t_2;
  __pyx_t_2 = 0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":39
 *     inds = np.arange(N)
 *
 *     for i in range(N):             # <<<<<<<<<<<<<<
 *         maxscore = boxes[i, 4]
 *         maxpos = i
 */
  __pyx_t_2 = __Pyx_PyInt_From_unsigned_int(__pyx_v_N); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_range, __pyx_t_2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 39, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_3);
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;
  if (likely(PyList_CheckExact(__pyx_t_3)) || PyTuple_CheckExact(__pyx_t_3)) {
    __pyx_t_2 = __pyx_t_3; __Pyx_INCREF(__pyx_t_2); __pyx_t_6 = 0;
    __pyx_t_7 = NULL;
  } else {
    __pyx_t_6 = -1; __pyx_t_2 = PyObject_GetIter(__pyx_t_3); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 39, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_2);
    __pyx_t_7 = Py_TYPE(__pyx_t_2)->tp_iternext; if (unlikely(!__pyx_t_7)) __PYX_ERR(0, 39, __pyx_L1_error)
  }
  __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
  for (;;) {
    if (likely(!__pyx_t_7)) {
      if (likely(PyList_CheckExact(__pyx_t_2))) {
        if (__pyx_t_6 >= PyList_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyList_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_3); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 39, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 39, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      } else {
        if (__pyx_t_6 >= PyTuple_GET_SIZE(__pyx_t_2)) break;
        #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
        __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_2, __pyx_t_6); __Pyx_INCREF(__pyx_t_3); __pyx_t_6++; if (unlikely(0 < 0)) __PYX_ERR(0, 39, __pyx_L1_error)
        #else
        __pyx_t_3 = PySequence_ITEM(__pyx_t_2, __pyx_t_6); __pyx_t_6++; if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 39, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        #endif
      }
    } else {
      __pyx_t_3 = __pyx_t_7(__pyx_t_2);
      if (unlikely(!__pyx_t_3)) {
        PyObject* exc_type = PyErr_Occurred();
        if (exc_type) {
          if (likely(__Pyx_PyErr_GivenExceptionMatches(exc_type, PyExc_StopIteration))) PyErr_Clear();
          else __PYX_ERR(0, 39, __pyx_L1_error)
        }
        break;
      }
      __Pyx_GOTREF(__pyx_t_3);
    }
    __Pyx_XDECREF_SET(__pyx_v_i, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":40
 *
 *     for i in range(N):
 *         maxscore = boxes[i, 4]             # <<<<<<<<<<<<<<
 *         maxpos = i
 *
 */
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 40, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_4);
    __Pyx_GIVEREF(__pyx_int_4);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_4);
    __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 40, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_1); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 40, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_v_maxscore = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":41
 *     for i in range(N):
 *         maxscore = boxes[i, 4]
 *         maxpos = i             # <<<<<<<<<<<<<<
 *
 *         tx1 = boxes[i, 0]
 */
    __pyx_t_9 = __Pyx_PyInt_As_int(__pyx_v_i); if (unlikely((__pyx_t_9 == (int)-1) && PyErr_Occurred())) __PYX_ERR(0, 41, __pyx_L1_error)
    __pyx_v_maxpos = __pyx_t_9;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":43
 *         maxpos = i
 *
 *         tx1 = boxes[i, 0]             # <<<<<<<<<<<<<<
 *         ty1 = boxes[i, 1]
 *         tx2 = boxes[i, 2]
 */
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 43, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 43, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 43, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_tx1 = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":44
 *
 *         tx1 = boxes[i, 0]
 *         ty1 = boxes[i, 1]             # <<<<<<<<<<<<<<
 *         tx2 = boxes[i, 2]
 *         ty2 = boxes[i, 3]
 */
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_1);
    __Pyx_GIVEREF(__pyx_int_1);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_1);
    __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_1); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 44, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_v_ty1 = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":45
 *         tx1 = boxes[i, 0]
 *         ty1 = boxes[i, 1]
 *         tx2 = boxes[i, 2]             # <<<<<<<<<<<<<<
 *         ty2 = boxes[i, 3]
 *         ts = boxes[i, 4]
 */
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 45, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_2);
    __Pyx_GIVEREF(__pyx_int_2);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_2);
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 45, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 45, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_tx2 = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":46
 *         ty1 = boxes[i, 1]
 *         tx2 = boxes[i, 2]
 *         ty2 = boxes[i, 3]             # <<<<<<<<<<<<<<
 *         ts = boxes[i, 4]
 *         ti = inds[i]
 */
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_3);
    __Pyx_GIVEREF(__pyx_int_3);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_3);
    __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_1); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 46, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_v_ty2 = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":47
 *         tx2 = boxes[i, 2]
 *         ty2 = boxes[i, 3]
 *         ts = boxes[i, 4]             # <<<<<<<<<<<<<<
 *         ti = inds[i]
 *
 */
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 47, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_4);
    __Pyx_GIVEREF(__pyx_int_4);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_4);
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 47, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 47, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_ts = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":48
 *         ty2 = boxes[i, 3]
 *         ts = boxes[i, 4]
 *         ti = inds[i]             # <<<<<<<<<<<<<<
 *
 *         pos = i + 1
 */
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_inds, __pyx_v_i); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 48, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_XDECREF_SET(__pyx_v_ti, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":50
 *         ti = inds[i]
 *
 *         pos = i + 1             # <<<<<<<<<<<<<<
 *         # get max box
 *         while pos < N:
 */
    __pyx_t_3 = __Pyx_PyInt_AddObjC(__pyx_v_i, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_9 = __Pyx_PyInt_As_int(__pyx_t_3); if (unlikely((__pyx_t_9 == (int)-1) && PyErr_Occurred())) __PYX_ERR(0, 50, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_pos = __pyx_t_9;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":52
 *         pos = i + 1
 *         # get max box
 *         while pos < N:             # <<<<<<<<<<<<<<
 *             if maxscore < boxes[pos, 4]:
 *                 maxscore = boxes[pos, 4]
 */
    while (1) {
      __pyx_t_10 = ((__pyx_v_pos < __pyx_v_N) != 0);
      if (!__pyx_t_10) break;

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":53
 *         # get max box
 *         while pos < N:
 *             if maxscore < boxes[pos, 4]:             # <<<<<<<<<<<<<<
 *                 maxscore = boxes[pos, 4]
 *                 maxpos = pos
 */
      __pyx_t_3 = PyFloat_FromDouble(__pyx_v_maxscore); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 53, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_1 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 53, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GIVEREF(__pyx_t_1);
      PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1);
      __Pyx_INCREF(__pyx_int_4);
      __Pyx_GIVEREF(__pyx_int_4);
      PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_4);
      __pyx_t_1 = 0;
      __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 53, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_1);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_5 = PyObject_RichCompare(__pyx_t_3, __pyx_t_1, Py_LT); __Pyx_XGOTREF(__pyx_t_5); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 53, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
      __pyx_t_10 = __Pyx_PyObject_IsTrue(__pyx_t_5); if (unlikely(__pyx_t_10 < 0)) __PYX_ERR(0, 53, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      if (__pyx_t_10) {

        /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":54
 *         while pos < N:
 *             if maxscore < boxes[pos, 4]:
 *                 maxscore = boxes[pos, 4]             # <<<<<<<<<<<<<<
 *                 maxpos = pos
 *             pos = pos + 1
 */
        __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 54, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 54, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_1);
        __Pyx_GIVEREF(__pyx_t_5);
        PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
        __Pyx_INCREF(__pyx_int_4);
        __Pyx_GIVEREF(__pyx_int_4);
        PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_4);
        __pyx_t_5 = 0;
        __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 54, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_5);
        __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
        __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_5); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 54, __pyx_L1_error)
        __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
        __pyx_v_maxscore = __pyx_t_8;

        /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":55
 *             if maxscore < boxes[pos, 4]:
 *                 maxscore = boxes[pos, 4]
 *                 maxpos = pos             # <<<<<<<<<<<<<<
 *             pos = pos + 1
 *
 */
        __pyx_v_maxpos = __pyx_v_pos;

        /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":53
 *         # get max box
 *         while pos < N:
 *             if maxscore < boxes[pos, 4]:             # <<<<<<<<<<<<<<
 *                 maxscore = boxes[pos, 4]
 *                 maxpos = pos
 */
      }

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":56
 *                 maxscore = boxes[pos, 4]
 *                 maxpos = pos
 *             pos = pos + 1             # <<<<<<<<<<<<<<
 *
 *         # add max box as a detection
 */
      __pyx_v_pos = (__pyx_v_pos + 1);
    }

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":59
 *
 *         # add max box as a detection
 *         boxes[i, 0] = boxes[maxpos, 0]             # <<<<<<<<<<<<<<
 *         boxes[i, 1] = boxes[maxpos, 1]
 *         boxes[i, 2] = boxes[maxpos, 2]
 */
    __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 59, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 59, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
    __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 59, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 59, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_0);
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_1, __pyx_t_5) < 0)) __PYX_ERR(0, 59, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":60
 *         # add max box as a detection
 *         boxes[i, 0] = boxes[maxpos, 0]
 *         boxes[i, 1] = boxes[maxpos, 1]             # <<<<<<<<<<<<<<
 *         boxes[i, 2] = boxes[maxpos, 2]
 *         boxes[i, 3] = boxes[maxpos, 3]
 */
    __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 60, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
    __Pyx_INCREF(__pyx_int_1);
    __Pyx_GIVEREF(__pyx_int_1);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_1);
    __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 60, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 60, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_1);
    __Pyx_GIVEREF(__pyx_int_1);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_1);
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_1, __pyx_t_5) < 0)) __PYX_ERR(0, 60, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":61
 *         boxes[i, 0] = boxes[maxpos, 0]
 *         boxes[i, 1] = boxes[maxpos, 1]
 *         boxes[i, 2] = boxes[maxpos, 2]             # <<<<<<<<<<<<<<
 *         boxes[i, 3] = boxes[maxpos, 3]
 *         boxes[i, 4] = boxes[maxpos, 4]
 */
    __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
    __Pyx_INCREF(__pyx_int_2);
    __Pyx_GIVEREF(__pyx_int_2);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_2);
    __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_2);
    __Pyx_GIVEREF(__pyx_int_2);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_2);
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_1, __pyx_t_5) < 0)) __PYX_ERR(0, 61, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":62
 *         boxes[i, 1] = boxes[maxpos, 1]
 *         boxes[i, 2] = boxes[maxpos, 2]
 *         boxes[i, 3] = boxes[maxpos, 3]             # <<<<<<<<<<<<<<
 *         boxes[i, 4] = boxes[maxpos, 4]
 *         inds[i] = inds[maxpos]
 */
    __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 62, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 62, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
    __Pyx_INCREF(__pyx_int_3);
    __Pyx_GIVEREF(__pyx_int_3);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_3);
    __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 62, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 62, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_3);
    __Pyx_GIVEREF(__pyx_int_3);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_3);
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_1, __pyx_t_5) < 0)) __PYX_ERR(0, 62, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":63
 *         boxes[i, 2] = boxes[maxpos, 2]
 *         boxes[i, 3] = boxes[maxpos, 3]
 *         boxes[i, 4] = boxes[maxpos, 4]             # <<<<<<<<<<<<<<
 *         inds[i] = inds[maxpos]
 *
 */
    __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 63, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_5);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_5);
    __Pyx_INCREF(__pyx_int_4);
    __Pyx_GIVEREF(__pyx_int_4);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_4);
    __pyx_t_5 = 0;
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 63, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 63, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_4);
    __Pyx_GIVEREF(__pyx_int_4);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_4);
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_1, __pyx_t_5) < 0)) __PYX_ERR(0, 63, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":64
 *         boxes[i, 3] = boxes[maxpos, 3]
 *         boxes[i, 4] = boxes[maxpos, 4]
 *         inds[i] = inds[maxpos]             # <<<<<<<<<<<<<<
 *
 *         # swap ith box with position of max box
 */
    __pyx_t_5 = __Pyx_GetItemInt(__pyx_v_inds, __pyx_v_maxpos, int, 1, __Pyx_PyInt_From_int, 0, 1, 0); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 64, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    if (unlikely(PyObject_SetItem(__pyx_v_inds, __pyx_v_i, __pyx_t_5) < 0)) __PYX_ERR(0, 64, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":67
 *
 *         # swap ith box with position of max box
 *         boxes[maxpos, 0] = tx1             # <<<<<<<<<<<<<<
 *         boxes[maxpos, 1] = ty1
 *         boxes[maxpos, 2] = tx2
 */
    __pyx_t_5 = PyFloat_FromDouble(__pyx_v_tx1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 67, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 67, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 67, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_0);
    __pyx_t_1 = 0;
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_3, __pyx_t_5) < 0)) __PYX_ERR(0, 67, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":68
 *         # swap ith box with position of max box
 *         boxes[maxpos, 0] = tx1
 *         boxes[maxpos, 1] = ty1             # <<<<<<<<<<<<<<
 *         boxes[maxpos, 2] = tx2
 *         boxes[maxpos, 3] = ty2
 */
    __pyx_t_5 = PyFloat_FromDouble(__pyx_v_ty1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 68, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 68, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 68, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
    __Pyx_INCREF(__pyx_int_1);
    __Pyx_GIVEREF(__pyx_int_1);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_1);
    __pyx_t_3 = 0;
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_1, __pyx_t_5) < 0)) __PYX_ERR(0, 68, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":69
 *         boxes[maxpos, 0] = tx1
 *         boxes[maxpos, 1] = ty1
 *         boxes[maxpos, 2] = tx2             # <<<<<<<<<<<<<<
 *         boxes[maxpos, 3] = ty2
 *         boxes[maxpos, 4] = ts
 */
    __pyx_t_5 = PyFloat_FromDouble(__pyx_v_tx2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
    __Pyx_INCREF(__pyx_int_2);
    __Pyx_GIVEREF(__pyx_int_2);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_2);
    __pyx_t_1 = 0;
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_3, __pyx_t_5) < 0)) __PYX_ERR(0, 69, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":70
 *         boxes[maxpos, 1] = ty1
 *         boxes[maxpos, 2] = tx2
 *         boxes[maxpos, 3] = ty2             # <<<<<<<<<<<<<<
 *         boxes[maxpos, 4] = ts
 *         inds[maxpos] = ti
 */
    __pyx_t_5 = PyFloat_FromDouble(__pyx_v_ty2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 70, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 70, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_1 = PyTuple_New(2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 70, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __Pyx_GIVEREF(__pyx_t_3);
    PyTuple_SET_ITEM(__pyx_t_1, 0, __pyx_t_3);
    __Pyx_INCREF(__pyx_int_3);
    __Pyx_GIVEREF(__pyx_int_3);
    PyTuple_SET_ITEM(__pyx_t_1, 1, __pyx_int_3);
    __pyx_t_3 = 0;
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_1, __pyx_t_5) < 0)) __PYX_ERR(0, 70, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":71
 *         boxes[maxpos, 2] = tx2
 *         boxes[maxpos, 3] = ty2
 *         boxes[maxpos, 4] = ts             # <<<<<<<<<<<<<<
 *         inds[maxpos] = ti
 *
 */
    __pyx_t_5 = PyFloat_FromDouble(__pyx_v_ts); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 71, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __pyx_t_1 = __Pyx_PyInt_From_int(__pyx_v_maxpos); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 71, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_1);
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 71, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_GIVEREF(__pyx_t_1);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
    __Pyx_INCREF(__pyx_int_4);
    __Pyx_GIVEREF(__pyx_int_4);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_4);
    __pyx_t_1 = 0;
    if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_3, __pyx_t_5) < 0)) __PYX_ERR(0, 71, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":72
 *         boxes[maxpos, 3] = ty2
 *         boxes[maxpos, 4] = ts
 *         inds[maxpos] = ti             # <<<<<<<<<<<<<<
 *
 *         tx1 = boxes[i, 0]
 */
    if (unlikely(__Pyx_SetItemInt(__pyx_v_inds, __pyx_v_maxpos, __pyx_v_ti, int, 1, __Pyx_PyInt_From_int, 0, 1, 0) < 0)) __PYX_ERR(0, 72, __pyx_L1_error)

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":74
 *         inds[maxpos] = ti
 *
 *         tx1 = boxes[i, 0]             # <<<<<<<<<<<<<<
 *         ty1 = boxes[i, 1]
 *         tx2 = boxes[i, 2]
 */
    __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 74, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_0);
    __Pyx_GIVEREF(__pyx_int_0);
    PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_0);
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 74, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 74, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_tx1 = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":75
 *
 *         tx1 = boxes[i, 0]
 *         ty1 = boxes[i, 1]             # <<<<<<<<<<<<<<
 *         tx2 = boxes[i, 2]
 *         ty2 = boxes[i, 3]
 */
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 75, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_1);
    __Pyx_GIVEREF(__pyx_int_1);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_1);
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 75, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_5); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 75, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_v_ty1 = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":76
 *         tx1 = boxes[i, 0]
 *         ty1 = boxes[i, 1]
 *         tx2 = boxes[i, 2]             # <<<<<<<<<<<<<<
 *         ty2 = boxes[i, 3]
 *         ts = boxes[i, 4]
 */
    __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 76, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_2);
    __Pyx_GIVEREF(__pyx_int_2);
    PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_2);
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 76, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 76, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_tx2 = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":77
 *         ty1 = boxes[i, 1]
 *         tx2 = boxes[i, 2]
 *         ty2 = boxes[i, 3]             # <<<<<<<<<<<<<<
 *         ts = boxes[i, 4]
 *
 */
    __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_3);
    __Pyx_GIVEREF(__pyx_int_3);
    PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_3);
    __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_5); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 77, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_v_ty2 = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":78
 *         tx2 = boxes[i, 2]
 *         ty2 = boxes[i, 3]
 *         ts = boxes[i, 4]             # <<<<<<<<<<<<<<
 *
 *         pos = i + 1
 */
    __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 78, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_5);
    __Pyx_INCREF(__pyx_v_i);
    __Pyx_GIVEREF(__pyx_v_i);
    PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_v_i);
    __Pyx_INCREF(__pyx_int_4);
    __Pyx_GIVEREF(__pyx_int_4);
    PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_4);
    __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 78, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
    __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 78, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_ts = __pyx_t_8;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":80
 *         ts = boxes[i, 4]
 *
 *         pos = i + 1             # <<<<<<<<<<<<<<
 *         # NMS iterations, note that N changes if detection boxes fall below
 *         # threshold
 */
    __pyx_t_3 = __Pyx_PyInt_AddObjC(__pyx_v_i, __pyx_int_1, 1, 0, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 80, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __pyx_t_9 = __Pyx_PyInt_As_int(__pyx_t_3); if (unlikely((__pyx_t_9 == (int)-1) && PyErr_Occurred())) __PYX_ERR(0, 80, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_v_pos = __pyx_t_9;

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":83
 *         # NMS iterations, note that N changes if detection boxes fall below
 *         # threshold
 *         while pos < N:             # <<<<<<<<<<<<<<
 *             x1 = boxes[pos, 0]
 *             y1 = boxes[pos, 1]
 */
    while (1) {
      __pyx_t_10 = ((__pyx_v_pos < __pyx_v_N) != 0);
      if (!__pyx_t_10) break;

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":84
 *         # threshold
 *         while pos < N:
 *             x1 = boxes[pos, 0]             # <<<<<<<<<<<<<<
 *             y1 = boxes[pos, 1]
 *             x2 = boxes[pos, 2]
 */
      __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 84, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 84, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
      __Pyx_INCREF(__pyx_int_0);
      __Pyx_GIVEREF(__pyx_int_0);
      PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_0);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 84, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 84, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_x1 = __pyx_t_8;

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":85
 *         while pos < N:
 *             x1 = boxes[pos, 0]
 *             y1 = boxes[pos, 1]             # <<<<<<<<<<<<<<
 *             x2 = boxes[pos, 2]
 *             y2 = boxes[pos, 3]
 */
      __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 85, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 85, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
      __Pyx_INCREF(__pyx_int_1);
      __Pyx_GIVEREF(__pyx_int_1);
      PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_1);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 85, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 85, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_y1 = __pyx_t_8;

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":86
 *             x1 = boxes[pos, 0]
 *             y1 = boxes[pos, 1]
 *             x2 = boxes[pos, 2]             # <<<<<<<<<<<<<<
 *             y2 = boxes[pos, 3]
 *             s = boxes[pos, 4]
 */
      __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 86, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 86, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
      __Pyx_INCREF(__pyx_int_2);
      __Pyx_GIVEREF(__pyx_int_2);
      PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_2);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 86, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 86, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_x2 = __pyx_t_8;

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":87
 *             y1 = boxes[pos, 1]
 *             x2 = boxes[pos, 2]
 *             y2 = boxes[pos, 3]             # <<<<<<<<<<<<<<
 *             s = boxes[pos, 4]
 *
 */
      __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 87, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 87, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
      __Pyx_INCREF(__pyx_int_3);
      __Pyx_GIVEREF(__pyx_int_3);
      PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_3);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 87, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 87, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_v_y2 = __pyx_t_8;

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":88
 *             x2 = boxes[pos, 2]
 *             y2 = boxes[pos, 3]
 *             s = boxes[pos, 4]             # <<<<<<<<<<<<<<
 *
 *             area = (x2 - x1 + 1) * (y2 - y1 + 1)
 */
      __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 88, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 88, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GIVEREF(__pyx_t_3);
      PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
      __Pyx_INCREF(__pyx_int_4);
      __Pyx_GIVEREF(__pyx_int_4);
      PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_4);
      __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 88, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
      __Pyx_XDECREF_SET(__pyx_v_s, __pyx_t_3);
      __pyx_t_3 = 0;

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":90
 *             s = boxes[pos, 4]
 *
 *             area = (x2 - x1 + 1) * (y2 - y1 + 1)             # <<<<<<<<<<<<<<
 *             iw = (min(tx2, x2) - max(tx1, x1) + 1)
 *             if iw > 0:
 */
      __pyx_v_area = (((__pyx_v_x2 - __pyx_v_x1) + 1.0) * ((__pyx_v_y2 - __pyx_v_y1) + 1.0));

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":91
 *
 *             area = (x2 - x1 + 1) * (y2 - y1 + 1)
 *             iw = (min(tx2, x2) - max(tx1, x1) + 1)             # <<<<<<<<<<<<<<
 *             if iw > 0:
 *                 ih = (min(ty2, y2) - max(ty1, y1) + 1)
 */
      __pyx_v_iw = ((__pyx_f_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_min(__pyx_v_tx2, __pyx_v_x2) - __pyx_f_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_max(__pyx_v_tx1, __pyx_v_x1)) + 1.0);

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":92
 *             area = (x2 - x1 + 1) * (y2 - y1 + 1)
 *             iw = (min(tx2, x2) - max(tx1, x1) + 1)
 *             if iw > 0:             # <<<<<<<<<<<<<<
 *                 ih = (min(ty2, y2) - max(ty1, y1) + 1)
 *                 if ih > 0:
 */
      __pyx_t_10 = ((__pyx_v_iw > 0.0) != 0);
      if (__pyx_t_10) {

        /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":93
 *             iw = (min(tx2, x2) - max(tx1, x1) + 1)
 *             if iw > 0:
 *                 ih = (min(ty2, y2) - max(ty1, y1) + 1)             # <<<<<<<<<<<<<<
 *                 if ih > 0:
 *                     ua = float((tx2 - tx1 + 1) * (ty2 - ty1 + 1) + area - iw * ih)
 */
        __pyx_v_ih = ((__pyx_f_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_min(__pyx_v_ty2, __pyx_v_y2) - __pyx_f_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_max(__pyx_v_ty1, __pyx_v_y1)) + 1.0);

        /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":94
 *             if iw > 0:
 *                 ih = (min(ty2, y2) - max(ty1, y1) + 1)
 *                 if ih > 0:             # <<<<<<<<<<<<<<
 *                     ua = float((tx2 - tx1 + 1) * (ty2 - ty1 + 1) + area - iw * ih)
 *                     ov = iw * ih / ua  # iou between max box and detection box
 */
        __pyx_t_10 = ((__pyx_v_ih > 0.0) != 0);
        if (__pyx_t_10) {

          /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":95
 *                 ih = (min(ty2, y2) - max(ty1, y1) + 1)
 *                 if ih > 0:
 *                     ua = float((tx2 - tx1 + 1) * (ty2 - ty1 + 1) + area - iw * ih)             # <<<<<<<<<<<<<<
 *                     ov = iw * ih / ua  # iou between max box and detection box
 *
 */
          __pyx_v_ua = ((double)(((((__pyx_v_tx2 - __pyx_v_tx1) + 1.0) * ((__pyx_v_ty2 - __pyx_v_ty1) + 1.0)) + __pyx_v_area) - (__pyx_v_iw * __pyx_v_ih)));

          /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":96
 *                 if ih > 0:
 *                     ua = float((tx2 - tx1 + 1) * (ty2 - ty1 + 1) + area - iw * ih)
 *                     ov = iw * ih / ua  # iou between max box and detection box             # <<<<<<<<<<<<<<
 *
 *                     if method == 1:  # linear
 */
          __pyx_t_8 = (__pyx_v_iw * __pyx_v_ih);
          if (unlikely(__pyx_v_ua == 0)) {
            PyErr_SetString(PyExc_ZeroDivisionError, "float division");
            __PYX_ERR(0, 96, __pyx_L1_error)
          }
          __pyx_v_ov = (__pyx_t_8 / __pyx_v_ua);

          /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":98
 *                     ov = iw * ih / ua  # iou between max box and detection box
 *
 *                     if method == 1:  # linear             # <<<<<<<<<<<<<<
 *                         if ov > iou_thr:
 *                             weight = 1 - ov
 */
          switch (__pyx_v_method) {
            case 1:

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":99
 *
 *                     if method == 1:  # linear
 *                         if ov > iou_thr:             # <<<<<<<<<<<<<<
 *                             weight = 1 - ov
 *                         else:
 */
            __pyx_t_10 = ((__pyx_v_ov > __pyx_v_iou_thr) != 0);
            if (__pyx_t_10) {

              /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":100
 *                     if method == 1:  # linear
 *                         if ov > iou_thr:
 *                             weight = 1 - ov             # <<<<<<<<<<<<<<
 *                         else:
 *                             weight = 1
 */
              __pyx_v_weight = (1.0 - __pyx_v_ov);

              /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":99
 *
 *                     if method == 1:  # linear
 *                         if ov > iou_thr:             # <<<<<<<<<<<<<<
 *                             weight = 1 - ov
 *                         else:
 */
              goto __pyx_L12;
            }

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":102
 *                             weight = 1 - ov
 *                         else:
 *                             weight = 1             # <<<<<<<<<<<<<<
 *                     elif method == 2:  # gaussian
 *                         weight = np.exp(-(ov * ov) / sigma)
 */
            /*else*/ {
              __pyx_v_weight = 1.0;
            }
            __pyx_L12:;

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":98
 *                     ov = iw * ih / ua  # iou between max box and detection box
 *
 *                     if method == 1:  # linear             # <<<<<<<<<<<<<<
 *                         if ov > iou_thr:
 *                             weight = 1 - ov
 */
            break;
            case 2:

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":104
 *                             weight = 1
 *                     elif method == 2:  # gaussian
 *                         weight = np.exp(-(ov * ov) / sigma)             # <<<<<<<<<<<<<<
 *                     else:  # original NMS
 *                         if ov > iou_thr:
 */
            __Pyx_GetModuleGlobalName(__pyx_t_5, __pyx_n_s_np); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 104, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_1 = __Pyx_PyObject_GetAttrStr(__pyx_t_5, __pyx_n_s_exp); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 104, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_8 = (-(__pyx_v_ov * __pyx_v_ov));
            if (unlikely(__pyx_v_sigma == 0)) {
              PyErr_SetString(PyExc_ZeroDivisionError, "float division");
              __PYX_ERR(0, 104, __pyx_L1_error)
            }
            __pyx_t_5 = PyFloat_FromDouble((__pyx_t_8 / __pyx_v_sigma)); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 104, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_11 = NULL;
            if (CYTHON_UNPACK_METHODS && unlikely(PyMethod_Check(__pyx_t_1))) {
              __pyx_t_11 = PyMethod_GET_SELF(__pyx_t_1);
              if (likely(__pyx_t_11)) {
                PyObject* function = PyMethod_GET_FUNCTION(__pyx_t_1);
                __Pyx_INCREF(__pyx_t_11);
                __Pyx_INCREF(function);
                __Pyx_DECREF_SET(__pyx_t_1, function);
              }
            }
            __pyx_t_3 = (__pyx_t_11) ? __Pyx_PyObject_Call2Args(__pyx_t_1, __pyx_t_11, __pyx_t_5) : __Pyx_PyObject_CallOneArg(__pyx_t_1, __pyx_t_5);
            __Pyx_XDECREF(__pyx_t_11); __pyx_t_11 = 0;
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 104, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
            __pyx_t_8 = __pyx_PyFloat_AsFloat(__pyx_t_3); if (unlikely((__pyx_t_8 == (float)-1) && PyErr_Occurred())) __PYX_ERR(0, 104, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __pyx_v_weight = __pyx_t_8;

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":103
 *                         else:
 *                             weight = 1
 *                     elif method == 2:  # gaussian             # <<<<<<<<<<<<<<
 *                         weight = np.exp(-(ov * ov) / sigma)
 *                     else:  # original NMS
 */
            break;
            default:

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":106
 *                         weight = np.exp(-(ov * ov) / sigma)
 *                     else:  # original NMS
 *                         if ov > iou_thr:             # <<<<<<<<<<<<<<
 *                             weight = 0
 *                         else:
 */
            __pyx_t_10 = ((__pyx_v_ov > __pyx_v_iou_thr) != 0);
            if (__pyx_t_10) {

              /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":107
 *                     else:  # original NMS
 *                         if ov > iou_thr:
 *                             weight = 0             # <<<<<<<<<<<<<<
 *                         else:
 *                             weight = 1
 */
              __pyx_v_weight = 0.0;

              /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":106
 *                         weight = np.exp(-(ov * ov) / sigma)
 *                     else:  # original NMS
 *                         if ov > iou_thr:             # <<<<<<<<<<<<<<
 *                             weight = 0
 *                         else:
 */
              goto __pyx_L13;
            }

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":109
 *                             weight = 0
 *                         else:
 *                             weight = 1             # <<<<<<<<<<<<<<
 *
 *                     boxes[pos, 4] = weight * boxes[pos, 4]
 */
            /*else*/ {
              __pyx_v_weight = 1.0;
            }
            __pyx_L13:;
            break;
          }

          /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":111
 *                             weight = 1
 *
 *                     boxes[pos, 4] = weight * boxes[pos, 4]             # <<<<<<<<<<<<<<
 *
 *                     # if box score falls below threshold, discard the box by
 */
          __pyx_t_3 = PyFloat_FromDouble(__pyx_v_weight); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 111, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_1 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 111, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 111, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          __Pyx_GIVEREF(__pyx_t_1);
          PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1);
          __Pyx_INCREF(__pyx_int_4);
          __Pyx_GIVEREF(__pyx_int_4);
          PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_4);
          __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 111, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
          __pyx_t_5 = PyNumber_Multiply(__pyx_t_3, __pyx_t_1); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 111, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          __pyx_t_1 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 111, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_1);
          __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 111, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GIVEREF(__pyx_t_1);
          PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
          __Pyx_INCREF(__pyx_int_4);
          __Pyx_GIVEREF(__pyx_int_4);
          PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_4);
          __pyx_t_1 = 0;
          if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_3, __pyx_t_5) < 0)) __PYX_ERR(0, 111, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;

          /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":115
 *                     # if box score falls below threshold, discard the box by
 *                     # swapping with last box update N
 *                     if boxes[pos, 4] < min_score:             # <<<<<<<<<<<<<<
 *                         boxes[pos, 0] = boxes[N-1, 0]
 *                         boxes[pos, 1] = boxes[N-1, 1]
 */
          __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 115, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 115, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __Pyx_GIVEREF(__pyx_t_5);
          PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_5);
          __Pyx_INCREF(__pyx_int_4);
          __Pyx_GIVEREF(__pyx_int_4);
          PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_4);
          __pyx_t_5 = 0;
          __pyx_t_5 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 115, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_5);
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_3 = PyFloat_FromDouble(__pyx_v_min_score); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 115, __pyx_L1_error)
          __Pyx_GOTREF(__pyx_t_3);
          __pyx_t_1 = PyObject_RichCompare(__pyx_t_5, __pyx_t_3, Py_LT); __Pyx_XGOTREF(__pyx_t_1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 115, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
          __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
          __pyx_t_10 = __Pyx_PyObject_IsTrue(__pyx_t_1); if (unlikely(__pyx_t_10 < 0)) __PYX_ERR(0, 115, __pyx_L1_error)
          __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
          if (__pyx_t_10) {

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":116
 *                     # swapping with last box update N
 *                     if boxes[pos, 4] < min_score:
 *                         boxes[pos, 0] = boxes[N-1, 0]             # <<<<<<<<<<<<<<
 *                         boxes[pos, 1] = boxes[N-1, 1]
 *                         boxes[pos, 2] = boxes[N-1, 2]
 */
            __pyx_t_1 = __Pyx_PyInt_From_long((__pyx_v_N - 1)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 116, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 116, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
            __Pyx_INCREF(__pyx_int_0);
            __Pyx_GIVEREF(__pyx_int_0);
            PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_0);
            __pyx_t_1 = 0;
            __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 116, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 116, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 116, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __Pyx_GIVEREF(__pyx_t_3);
            PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
            __Pyx_INCREF(__pyx_int_0);
            __Pyx_GIVEREF(__pyx_int_0);
            PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_0);
            __pyx_t_3 = 0;
            if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_5, __pyx_t_1) < 0)) __PYX_ERR(0, 116, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":117
 *                     if boxes[pos, 4] < min_score:
 *                         boxes[pos, 0] = boxes[N-1, 0]
 *                         boxes[pos, 1] = boxes[N-1, 1]             # <<<<<<<<<<<<<<
 *                         boxes[pos, 2] = boxes[N-1, 2]
 *                         boxes[pos, 3] = boxes[N-1, 3]
 */
            __pyx_t_1 = __Pyx_PyInt_From_long((__pyx_v_N - 1)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 117, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 117, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1);
            __Pyx_INCREF(__pyx_int_1);
            __Pyx_GIVEREF(__pyx_int_1);
            PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_1);
            __pyx_t_1 = 0;
            __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 117, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 117, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 117, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GIVEREF(__pyx_t_5);
            PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_5);
            __Pyx_INCREF(__pyx_int_1);
            __Pyx_GIVEREF(__pyx_int_1);
            PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_1);
            __pyx_t_5 = 0;
            if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_3, __pyx_t_1) < 0)) __PYX_ERR(0, 117, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":118
 *                         boxes[pos, 0] = boxes[N-1, 0]
 *                         boxes[pos, 1] = boxes[N-1, 1]
 *                         boxes[pos, 2] = boxes[N-1, 2]             # <<<<<<<<<<<<<<
 *                         boxes[pos, 3] = boxes[N-1, 3]
 *                         boxes[pos, 4] = boxes[N-1, 4]
 */
            __pyx_t_1 = __Pyx_PyInt_From_long((__pyx_v_N - 1)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 118, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 118, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
            __Pyx_INCREF(__pyx_int_2);
            __Pyx_GIVEREF(__pyx_int_2);
            PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_2);
            __pyx_t_1 = 0;
            __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 118, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 118, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 118, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __Pyx_GIVEREF(__pyx_t_3);
            PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
            __Pyx_INCREF(__pyx_int_2);
            __Pyx_GIVEREF(__pyx_int_2);
            PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_2);
            __pyx_t_3 = 0;
            if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_5, __pyx_t_1) < 0)) __PYX_ERR(0, 118, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":119
 *                         boxes[pos, 1] = boxes[N-1, 1]
 *                         boxes[pos, 2] = boxes[N-1, 2]
 *                         boxes[pos, 3] = boxes[N-1, 3]             # <<<<<<<<<<<<<<
 *                         boxes[pos, 4] = boxes[N-1, 4]
 *                         inds[pos] = inds[N - 1]
 */
            __pyx_t_1 = __Pyx_PyInt_From_long((__pyx_v_N - 1)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 119, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_1);
            __Pyx_INCREF(__pyx_int_3);
            __Pyx_GIVEREF(__pyx_int_3);
            PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_3);
            __pyx_t_1 = 0;
            __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_5); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 119, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __pyx_t_5 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 119, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 119, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GIVEREF(__pyx_t_5);
            PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_5);
            __Pyx_INCREF(__pyx_int_3);
            __Pyx_GIVEREF(__pyx_int_3);
            PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_3);
            __pyx_t_5 = 0;
            if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_3, __pyx_t_1) < 0)) __PYX_ERR(0, 119, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":120
 *                         boxes[pos, 2] = boxes[N-1, 2]
 *                         boxes[pos, 3] = boxes[N-1, 3]
 *                         boxes[pos, 4] = boxes[N-1, 4]             # <<<<<<<<<<<<<<
 *                         inds[pos] = inds[N - 1]
 *                         N = N - 1
 */
            __pyx_t_1 = __Pyx_PyInt_From_long((__pyx_v_N - 1)); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 120, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __pyx_t_3 = PyTuple_New(2); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 120, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __Pyx_GIVEREF(__pyx_t_1);
            PyTuple_SET_ITEM(__pyx_t_3, 0, __pyx_t_1);
            __Pyx_INCREF(__pyx_int_4);
            __Pyx_GIVEREF(__pyx_int_4);
            PyTuple_SET_ITEM(__pyx_t_3, 1, __pyx_int_4);
            __pyx_t_1 = 0;
            __pyx_t_1 = __Pyx_PyObject_GetItem(__pyx_v_boxes, __pyx_t_3); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 120, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
            __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_pos); if (unlikely(!__pyx_t_3)) __PYX_ERR(0, 120, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_3);
            __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 120, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_5);
            __Pyx_GIVEREF(__pyx_t_3);
            PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_3);
            __Pyx_INCREF(__pyx_int_4);
            __Pyx_GIVEREF(__pyx_int_4);
            PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_int_4);
            __pyx_t_3 = 0;
            if (unlikely(PyObject_SetItem(__pyx_v_boxes, __pyx_t_5, __pyx_t_1) < 0)) __PYX_ERR(0, 120, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_5); __pyx_t_5 = 0;
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":121
 *                         boxes[pos, 3] = boxes[N-1, 3]
 *                         boxes[pos, 4] = boxes[N-1, 4]
 *                         inds[pos] = inds[N - 1]             # <<<<<<<<<<<<<<
 *                         N = N - 1
 *                         pos = pos - 1
 */
            __pyx_t_12 = (__pyx_v_N - 1);
            __pyx_t_1 = __Pyx_GetItemInt(__pyx_v_inds, __pyx_t_12, long, 1, __Pyx_PyInt_From_long, 0, 1, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 121, __pyx_L1_error)
            __Pyx_GOTREF(__pyx_t_1);
            if (unlikely(__Pyx_SetItemInt(__pyx_v_inds, __pyx_v_pos, __pyx_t_1, int, 1, __Pyx_PyInt_From_int, 0, 1, 0) < 0)) __PYX_ERR(0, 121, __pyx_L1_error)
            __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":122
 *                         boxes[pos, 4] = boxes[N-1, 4]
 *                         inds[pos] = inds[N - 1]
 *                         N = N - 1             # <<<<<<<<<<<<<<
 *                         pos = pos - 1
 *
 */
            __pyx_v_N = (__pyx_v_N - 1);

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":123
 *                         inds[pos] = inds[N - 1]
 *                         N = N - 1
 *                         pos = pos - 1             # <<<<<<<<<<<<<<
 *
 *             pos = pos + 1
 */
            __pyx_v_pos = (__pyx_v_pos - 1);

            /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":115
 *                     # if box score falls below threshold, discard the box by
 *                     # swapping with last box update N
 *                     if boxes[pos, 4] < min_score:             # <<<<<<<<<<<<<<
 *                         boxes[pos, 0] = boxes[N-1, 0]
 *                         boxes[pos, 1] = boxes[N-1, 1]
 */
          }

          /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":94
 *             if iw > 0:
 *                 ih = (min(ty2, y2) - max(ty1, y1) + 1)
 *                 if ih > 0:             # <<<<<<<<<<<<<<
 *                     ua = float((tx2 - tx1 + 1) * (ty2 - ty1 + 1) + area - iw * ih)
 *                     ov = iw * ih / ua  # iou between max box and detection box
 */
        }

        /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":92
 *             area = (x2 - x1 + 1) * (y2 - y1 + 1)
 *             iw = (min(tx2, x2) - max(tx1, x1) + 1)
 *             if iw > 0:             # <<<<<<<<<<<<<<
 *                 ih = (min(ty2, y2) - max(ty1, y1) + 1)
 *                 if ih > 0:
 */
      }

      /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":125
 *                         pos = pos - 1
 *
 *             pos = pos + 1             # <<<<<<<<<<<<<<
 *
 *     return boxes[:N], inds[:N]
 */
      __pyx_v_pos = (__pyx_v_pos + 1);
    }

    /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":39
 *     inds = np.arange(N)
 *
 *     for i in range(N):             # <<<<<<<<<<<<<<
 *         maxscore = boxes[i, 4]
 *         maxpos = i
 */
  }
  __Pyx_DECREF(__pyx_t_2); __pyx_t_2 = 0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":127
 *             pos = pos + 1
 *
 *     return boxes[:N], inds[:N]             # <<<<<<<<<<<<<<
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_2 = __Pyx_PyObject_GetSlice(__pyx_v_boxes, 0, __pyx_v_N, NULL, NULL, NULL, 0, 1, 1); if (unlikely(!__pyx_t_2)) __PYX_ERR(0, 127, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_2);
  __pyx_t_1 = __Pyx_PyObject_GetSlice(__pyx_v_inds, 0, __pyx_v_N, NULL, NULL, NULL, 0, 1, 1); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 127, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_t_5 = PyTuple_New(2); if (unlikely(!__pyx_t_5)) __PYX_ERR(0, 127, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_5);
  __Pyx_GIVEREF(__pyx_t_2);
  PyTuple_SET_ITEM(__pyx_t_5, 0, __pyx_t_2);
  __Pyx_GIVEREF(__pyx_t_1);
  PyTuple_SET_ITEM(__pyx_t_5, 1, __pyx_t_1);
  __pyx_t_2 = 0;
  __pyx_t_1 = 0;
  __pyx_r = __pyx_t_5;
  __pyx_t_5 = 0;
  goto __pyx_L0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":22
 *
 *
 * def soft_nms_cpu(             # <<<<<<<<<<<<<<
 *     np.ndarray[float, ndim=2] boxes_in,
 *     float iou_thr,
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_2);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_11);
  { PyObject *__pyx_type, *__pyx_value, *__pyx_tb;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&__pyx_type, &__pyx_value, &__pyx_tb);
    __Pyx_SafeReleaseBuffer(&__pyx_pybuffernd_boxes_in.rcbuffer->pybuffer);
  __Pyx_ErrRestore(__pyx_type, __pyx_value, __pyx_tb);}
  __Pyx_AddTraceback("mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu.soft_nms_cpu", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  goto __pyx_L2;
  __pyx_L0:;
  __Pyx_SafeReleaseBuffer(&__pyx_pybuffernd_boxes_in.rcbuffer->pybuffer);
  __pyx_L2:;
  __Pyx_XDECREF(__pyx_v_boxes);
  __Pyx_XDECREF(__pyx_v_inds);
  __Pyx_XDECREF(__pyx_v_i);
  __Pyx_XDECREF(__pyx_v_ti);
  __Pyx_XDECREF(__pyx_v_s);
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":258
 *         # experimental exception made for __getbuffer__ and __releasebuffer__
 *         # -- the details of this may change.
 *         def __getbuffer__(ndarray self, Py_buffer* info, int flags):             # <<<<<<<<<<<<<<
 *             # This implementation of getbuffer is geared towards Cython
 *             # requirements, and does not yet fulfill the PEP.
 */

/* Python wrapper */
static CYTHON_UNUSED int __pyx_pw_5numpy_7ndarray_1__getbuffer__(PyObject *__pyx_v_self, Py_buffer *__pyx_v_info, int __pyx_v_flags); /*proto*/
static CYTHON_UNUSED int __pyx_pw_5numpy_7ndarray_1__getbuffer__(PyObject *__pyx_v_self, Py_buffer *__pyx_v_info, int __pyx_v_flags) {
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__getbuffer__ (wrapper)", 0);
  __pyx_r = __pyx_pf_5numpy_7ndarray___getbuffer__(((PyArrayObject *)__pyx_v_self), ((Py_buffer *)__pyx_v_info), ((int)__pyx_v_flags));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static int __pyx_pf_5numpy_7ndarray___getbuffer__(PyArrayObject *__pyx_v_self, Py_buffer *__pyx_v_info, int __pyx_v_flags) {
  int __pyx_v_i;
  int __pyx_v_ndim;
  int __pyx_v_endian_detector;
  int __pyx_v_little_endian;
  int __pyx_v_t;
  char *__pyx_v_f;
  PyArray_Descr *__pyx_v_descr = 0;
  int __pyx_v_offset;
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  int __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  int __pyx_t_5;
  int __pyx_t_6;
  PyArray_Descr *__pyx_t_7;
  PyObject *__pyx_t_8 = NULL;
  char *__pyx_t_9;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  if (__pyx_v_info == NULL) {
    PyErr_SetString(PyExc_BufferError, "PyObject_GetBuffer: view==NULL argument is obsolete");
    return -1;
  }
  __Pyx_RefNannySetupContext("__getbuffer__", 0);
  __pyx_v_info->obj = Py_None; __Pyx_INCREF(Py_None);
  __Pyx_GIVEREF(__pyx_v_info->obj);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":265
 *
 *             cdef int i, ndim
 *             cdef int endian_detector = 1             # <<<<<<<<<<<<<<
 *             cdef bint little_endian = ((<char*>&endian_detector)[0] != 0)
 *
 */
  __pyx_v_endian_detector = 1;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":266
 *             cdef int i, ndim
 *             cdef int endian_detector = 1
 *             cdef bint little_endian = ((<char*>&endian_detector)[0] != 0)             # <<<<<<<<<<<<<<
 *
 *             ndim = PyArray_NDIM(self)
 */
  __pyx_v_little_endian = ((((char *)(&__pyx_v_endian_detector))[0]) != 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":268
 *             cdef bint little_endian = ((<char*>&endian_detector)[0] != 0)
 *
 *             ndim = PyArray_NDIM(self)             # <<<<<<<<<<<<<<
 *
 *             if ((flags & pybuf.PyBUF_C_CONTIGUOUS == pybuf.PyBUF_C_CONTIGUOUS)
 */
  __pyx_v_ndim = PyArray_NDIM(__pyx_v_self);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":270
 *             ndim = PyArray_NDIM(self)
 *
 *             if ((flags & pybuf.PyBUF_C_CONTIGUOUS == pybuf.PyBUF_C_CONTIGUOUS)             # <<<<<<<<<<<<<<
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_C_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not C contiguous")
 */
  __pyx_t_2 = (((__pyx_v_flags & PyBUF_C_CONTIGUOUS) == PyBUF_C_CONTIGUOUS) != 0);
  if (__pyx_t_2) {
  } else {
    __pyx_t_1 = __pyx_t_2;
    goto __pyx_L4_bool_binop_done;
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":271
 *
 *             if ((flags & pybuf.PyBUF_C_CONTIGUOUS == pybuf.PyBUF_C_CONTIGUOUS)
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_C_CONTIGUOUS)):             # <<<<<<<<<<<<<<
 *                 raise ValueError(u"ndarray is not C contiguous")
 *
 */
  __pyx_t_2 = ((!(PyArray_CHKFLAGS(__pyx_v_self, NPY_ARRAY_C_CONTIGUOUS) != 0)) != 0);
  __pyx_t_1 = __pyx_t_2;
  __pyx_L4_bool_binop_done:;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":270
 *             ndim = PyArray_NDIM(self)
 *
 *             if ((flags & pybuf.PyBUF_C_CONTIGUOUS == pybuf.PyBUF_C_CONTIGUOUS)             # <<<<<<<<<<<<<<
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_C_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not C contiguous")
 */
  if (unlikely(__pyx_t_1)) {

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":272
 *             if ((flags & pybuf.PyBUF_C_CONTIGUOUS == pybuf.PyBUF_C_CONTIGUOUS)
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_C_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not C contiguous")             # <<<<<<<<<<<<<<
 *
 *             if ((flags & pybuf.PyBUF_F_CONTIGUOUS == pybuf.PyBUF_F_CONTIGUOUS)
 */
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_ValueError, __pyx_tuple_, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 272, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_Raise(__pyx_t_3, 0, 0, 0);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __PYX_ERR(1, 272, __pyx_L1_error)

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":270
 *             ndim = PyArray_NDIM(self)
 *
 *             if ((flags & pybuf.PyBUF_C_CONTIGUOUS == pybuf.PyBUF_C_CONTIGUOUS)             # <<<<<<<<<<<<<<
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_C_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not C contiguous")
 */
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":274
 *                 raise ValueError(u"ndarray is not C contiguous")
 *
 *             if ((flags & pybuf.PyBUF_F_CONTIGUOUS == pybuf.PyBUF_F_CONTIGUOUS)             # <<<<<<<<<<<<<<
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_F_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not Fortran contiguous")
 */
  __pyx_t_2 = (((__pyx_v_flags & PyBUF_F_CONTIGUOUS) == PyBUF_F_CONTIGUOUS) != 0);
  if (__pyx_t_2) {
  } else {
    __pyx_t_1 = __pyx_t_2;
    goto __pyx_L7_bool_binop_done;
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":275
 *
 *             if ((flags & pybuf.PyBUF_F_CONTIGUOUS == pybuf.PyBUF_F_CONTIGUOUS)
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_F_CONTIGUOUS)):             # <<<<<<<<<<<<<<
 *                 raise ValueError(u"ndarray is not Fortran contiguous")
 *
 */
  __pyx_t_2 = ((!(PyArray_CHKFLAGS(__pyx_v_self, NPY_ARRAY_F_CONTIGUOUS) != 0)) != 0);
  __pyx_t_1 = __pyx_t_2;
  __pyx_L7_bool_binop_done:;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":274
 *                 raise ValueError(u"ndarray is not C contiguous")
 *
 *             if ((flags & pybuf.PyBUF_F_CONTIGUOUS == pybuf.PyBUF_F_CONTIGUOUS)             # <<<<<<<<<<<<<<
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_F_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not Fortran contiguous")
 */
  if (unlikely(__pyx_t_1)) {

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":276
 *             if ((flags & pybuf.PyBUF_F_CONTIGUOUS == pybuf.PyBUF_F_CONTIGUOUS)
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_F_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not Fortran contiguous")             # <<<<<<<<<<<<<<
 *
 *             info.buf = PyArray_DATA(self)
 */
    __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_ValueError, __pyx_tuple__2, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 276, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_Raise(__pyx_t_3, 0, 0, 0);
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __PYX_ERR(1, 276, __pyx_L1_error)

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":274
 *                 raise ValueError(u"ndarray is not C contiguous")
 *
 *             if ((flags & pybuf.PyBUF_F_CONTIGUOUS == pybuf.PyBUF_F_CONTIGUOUS)             # <<<<<<<<<<<<<<
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_F_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not Fortran contiguous")
 */
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":278
 *                 raise ValueError(u"ndarray is not Fortran contiguous")
 *
 *             info.buf = PyArray_DATA(self)             # <<<<<<<<<<<<<<
 *             info.ndim = ndim
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):
 */
  __pyx_v_info->buf = PyArray_DATA(__pyx_v_self);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":279
 *
 *             info.buf = PyArray_DATA(self)
 *             info.ndim = ndim             # <<<<<<<<<<<<<<
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):
 *                 # Allocate new buffer for strides and shape info.
 */
  __pyx_v_info->ndim = __pyx_v_ndim;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":280
 *             info.buf = PyArray_DATA(self)
 *             info.ndim = ndim
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):             # <<<<<<<<<<<<<<
 *                 # Allocate new buffer for strides and shape info.
 *                 # This is allocated as one block, strides first.
 */
  __pyx_t_1 = (((sizeof(npy_intp)) != (sizeof(Py_ssize_t))) != 0);
  if (__pyx_t_1) {

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":283
 *                 # Allocate new buffer for strides and shape info.
 *                 # This is allocated as one block, strides first.
 *                 info.strides = <Py_ssize_t*>PyObject_Malloc(sizeof(Py_ssize_t) * 2 * <size_t>ndim)             # <<<<<<<<<<<<<<
 *                 info.shape = info.strides + ndim
 *                 for i in range(ndim):
 */
    __pyx_v_info->strides = ((Py_ssize_t *)PyObject_Malloc((((sizeof(Py_ssize_t)) * 2) * ((size_t)__pyx_v_ndim))));

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":284
 *                 # This is allocated as one block, strides first.
 *                 info.strides = <Py_ssize_t*>PyObject_Malloc(sizeof(Py_ssize_t) * 2 * <size_t>ndim)
 *                 info.shape = info.strides + ndim             # <<<<<<<<<<<<<<
 *                 for i in range(ndim):
 *                     info.strides[i] = PyArray_STRIDES(self)[i]
 */
    __pyx_v_info->shape = (__pyx_v_info->strides + __pyx_v_ndim);

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":285
 *                 info.strides = <Py_ssize_t*>PyObject_Malloc(sizeof(Py_ssize_t) * 2 * <size_t>ndim)
 *                 info.shape = info.strides + ndim
 *                 for i in range(ndim):             # <<<<<<<<<<<<<<
 *                     info.strides[i] = PyArray_STRIDES(self)[i]
 *                     info.shape[i] = PyArray_DIMS(self)[i]
 */
    __pyx_t_4 = __pyx_v_ndim;
    __pyx_t_5 = __pyx_t_4;
    for (__pyx_t_6 = 0; __pyx_t_6 < __pyx_t_5; __pyx_t_6+=1) {
      __pyx_v_i = __pyx_t_6;

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":286
 *                 info.shape = info.strides + ndim
 *                 for i in range(ndim):
 *                     info.strides[i] = PyArray_STRIDES(self)[i]             # <<<<<<<<<<<<<<
 *                     info.shape[i] = PyArray_DIMS(self)[i]
 *             else:
 */
      (__pyx_v_info->strides[__pyx_v_i]) = (PyArray_STRIDES(__pyx_v_self)[__pyx_v_i]);

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":287
 *                 for i in range(ndim):
 *                     info.strides[i] = PyArray_STRIDES(self)[i]
 *                     info.shape[i] = PyArray_DIMS(self)[i]             # <<<<<<<<<<<<<<
 *             else:
 *                 info.strides = <Py_ssize_t*>PyArray_STRIDES(self)
 */
      (__pyx_v_info->shape[__pyx_v_i]) = (PyArray_DIMS(__pyx_v_self)[__pyx_v_i]);
    }

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":280
 *             info.buf = PyArray_DATA(self)
 *             info.ndim = ndim
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):             # <<<<<<<<<<<<<<
 *                 # Allocate new buffer for strides and shape info.
 *                 # This is allocated as one block, strides first.
 */
    goto __pyx_L9;
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":289
 *                     info.shape[i] = PyArray_DIMS(self)[i]
 *             else:
 *                 info.strides = <Py_ssize_t*>PyArray_STRIDES(self)             # <<<<<<<<<<<<<<
 *                 info.shape = <Py_ssize_t*>PyArray_DIMS(self)
 *             info.suboffsets = NULL
 */
  /*else*/ {
    __pyx_v_info->strides = ((Py_ssize_t *)PyArray_STRIDES(__pyx_v_self));

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":290
 *             else:
 *                 info.strides = <Py_ssize_t*>PyArray_STRIDES(self)
 *                 info.shape = <Py_ssize_t*>PyArray_DIMS(self)             # <<<<<<<<<<<<<<
 *             info.suboffsets = NULL
 *             info.itemsize = PyArray_ITEMSIZE(self)
 */
    __pyx_v_info->shape = ((Py_ssize_t *)PyArray_DIMS(__pyx_v_self));
  }
  __pyx_L9:;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":291
 *                 info.strides = <Py_ssize_t*>PyArray_STRIDES(self)
 *                 info.shape = <Py_ssize_t*>PyArray_DIMS(self)
 *             info.suboffsets = NULL             # <<<<<<<<<<<<<<
 *             info.itemsize = PyArray_ITEMSIZE(self)
 *             info.readonly = not PyArray_ISWRITEABLE(self)
 */
  __pyx_v_info->suboffsets = NULL;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":292
 *                 info.shape = <Py_ssize_t*>PyArray_DIMS(self)
 *             info.suboffsets = NULL
 *             info.itemsize = PyArray_ITEMSIZE(self)             # <<<<<<<<<<<<<<
 *             info.readonly = not PyArray_ISWRITEABLE(self)
 *
 */
  __pyx_v_info->itemsize = PyArray_ITEMSIZE(__pyx_v_self);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":293
 *             info.suboffsets = NULL
 *             info.itemsize = PyArray_ITEMSIZE(self)
 *             info.readonly = not PyArray_ISWRITEABLE(self)             # <<<<<<<<<<<<<<
 *
 *             cdef int t
 */
  __pyx_v_info->readonly = (!(PyArray_ISWRITEABLE(__pyx_v_self) != 0));

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":296
 *
 *             cdef int t
 *             cdef char* f = NULL             # <<<<<<<<<<<<<<
 *             cdef dtype descr = <dtype>PyArray_DESCR(self)
 *             cdef int offset
 */
  __pyx_v_f = NULL;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":297
 *             cdef int t
 *             cdef char* f = NULL
 *             cdef dtype descr = <dtype>PyArray_DESCR(self)             # <<<<<<<<<<<<<<
 *             cdef int offset
 *
 */
  __pyx_t_7 = PyArray_DESCR(__pyx_v_self);
  __pyx_t_3 = ((PyObject *)__pyx_t_7);
  __Pyx_INCREF(__pyx_t_3);
  __pyx_v_descr = ((PyArray_Descr *)__pyx_t_3);
  __pyx_t_3 = 0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":300
 *             cdef int offset
 *
 *             info.obj = self             # <<<<<<<<<<<<<<
 *
 *             if not PyDataType_HASFIELDS(descr):
 */
  __Pyx_INCREF(((PyObject *)__pyx_v_self));
  __Pyx_GIVEREF(((PyObject *)__pyx_v_self));
  __Pyx_GOTREF(__pyx_v_info->obj);
  __Pyx_DECREF(__pyx_v_info->obj);
  __pyx_v_info->obj = ((PyObject *)__pyx_v_self);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":302
 *             info.obj = self
 *
 *             if not PyDataType_HASFIELDS(descr):             # <<<<<<<<<<<<<<
 *                 t = descr.type_num
 *                 if ((descr.byteorder == c'>' and little_endian) or
 */
  __pyx_t_1 = ((!(PyDataType_HASFIELDS(__pyx_v_descr) != 0)) != 0);
  if (__pyx_t_1) {

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":303
 *
 *             if not PyDataType_HASFIELDS(descr):
 *                 t = descr.type_num             # <<<<<<<<<<<<<<
 *                 if ((descr.byteorder == c'>' and little_endian) or
 *                     (descr.byteorder == c'<' and not little_endian)):
 */
    __pyx_t_4 = __pyx_v_descr->type_num;
    __pyx_v_t = __pyx_t_4;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":304
 *             if not PyDataType_HASFIELDS(descr):
 *                 t = descr.type_num
 *                 if ((descr.byteorder == c'>' and little_endian) or             # <<<<<<<<<<<<<<
 *                     (descr.byteorder == c'<' and not little_endian)):
 *                     raise ValueError(u"Non-native byte order not supported")
 */
    __pyx_t_2 = ((__pyx_v_descr->byteorder == '>') != 0);
    if (!__pyx_t_2) {
      goto __pyx_L15_next_or;
    } else {
    }
    __pyx_t_2 = (__pyx_v_little_endian != 0);
    if (!__pyx_t_2) {
    } else {
      __pyx_t_1 = __pyx_t_2;
      goto __pyx_L14_bool_binop_done;
    }
    __pyx_L15_next_or:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":305
 *                 t = descr.type_num
 *                 if ((descr.byteorder == c'>' and little_endian) or
 *                     (descr.byteorder == c'<' and not little_endian)):             # <<<<<<<<<<<<<<
 *                     raise ValueError(u"Non-native byte order not supported")
 *                 if   t == NPY_BYTE:        f = "b"
 */
    __pyx_t_2 = ((__pyx_v_descr->byteorder == '<') != 0);
    if (__pyx_t_2) {
    } else {
      __pyx_t_1 = __pyx_t_2;
      goto __pyx_L14_bool_binop_done;
    }
    __pyx_t_2 = ((!(__pyx_v_little_endian != 0)) != 0);
    __pyx_t_1 = __pyx_t_2;
    __pyx_L14_bool_binop_done:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":304
 *             if not PyDataType_HASFIELDS(descr):
 *                 t = descr.type_num
 *                 if ((descr.byteorder == c'>' and little_endian) or             # <<<<<<<<<<<<<<
 *                     (descr.byteorder == c'<' and not little_endian)):
 *                     raise ValueError(u"Non-native byte order not supported")
 */
    if (unlikely(__pyx_t_1)) {

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":306
 *                 if ((descr.byteorder == c'>' and little_endian) or
 *                     (descr.byteorder == c'<' and not little_endian)):
 *                     raise ValueError(u"Non-native byte order not supported")             # <<<<<<<<<<<<<<
 *                 if   t == NPY_BYTE:        f = "b"
 *                 elif t == NPY_UBYTE:       f = "B"
 */
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_ValueError, __pyx_tuple__3, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 306, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_Raise(__pyx_t_3, 0, 0, 0);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __PYX_ERR(1, 306, __pyx_L1_error)

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":304
 *             if not PyDataType_HASFIELDS(descr):
 *                 t = descr.type_num
 *                 if ((descr.byteorder == c'>' and little_endian) or             # <<<<<<<<<<<<<<
 *                     (descr.byteorder == c'<' and not little_endian)):
 *                     raise ValueError(u"Non-native byte order not supported")
 */
    }

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":307
 *                     (descr.byteorder == c'<' and not little_endian)):
 *                     raise ValueError(u"Non-native byte order not supported")
 *                 if   t == NPY_BYTE:        f = "b"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_UBYTE:       f = "B"
 *                 elif t == NPY_SHORT:       f = "h"
 */
    switch (__pyx_v_t) {
      case NPY_BYTE:
      __pyx_v_f = ((char *)"b");
      break;
      case NPY_UBYTE:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":308
 *                     raise ValueError(u"Non-native byte order not supported")
 *                 if   t == NPY_BYTE:        f = "b"
 *                 elif t == NPY_UBYTE:       f = "B"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_SHORT:       f = "h"
 *                 elif t == NPY_USHORT:      f = "H"
 */
      __pyx_v_f = ((char *)"B");
      break;
      case NPY_SHORT:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":309
 *                 if   t == NPY_BYTE:        f = "b"
 *                 elif t == NPY_UBYTE:       f = "B"
 *                 elif t == NPY_SHORT:       f = "h"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_USHORT:      f = "H"
 *                 elif t == NPY_INT:         f = "i"
 */
      __pyx_v_f = ((char *)"h");
      break;
      case NPY_USHORT:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":310
 *                 elif t == NPY_UBYTE:       f = "B"
 *                 elif t == NPY_SHORT:       f = "h"
 *                 elif t == NPY_USHORT:      f = "H"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_INT:         f = "i"
 *                 elif t == NPY_UINT:        f = "I"
 */
      __pyx_v_f = ((char *)"H");
      break;
      case NPY_INT:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":311
 *                 elif t == NPY_SHORT:       f = "h"
 *                 elif t == NPY_USHORT:      f = "H"
 *                 elif t == NPY_INT:         f = "i"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_UINT:        f = "I"
 *                 elif t == NPY_LONG:        f = "l"
 */
      __pyx_v_f = ((char *)"i");
      break;
      case NPY_UINT:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":312
 *                 elif t == NPY_USHORT:      f = "H"
 *                 elif t == NPY_INT:         f = "i"
 *                 elif t == NPY_UINT:        f = "I"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_LONG:        f = "l"
 *                 elif t == NPY_ULONG:       f = "L"
 */
      __pyx_v_f = ((char *)"I");
      break;
      case NPY_LONG:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":313
 *                 elif t == NPY_INT:         f = "i"
 *                 elif t == NPY_UINT:        f = "I"
 *                 elif t == NPY_LONG:        f = "l"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_ULONG:       f = "L"
 *                 elif t == NPY_LONGLONG:    f = "q"
 */
      __pyx_v_f = ((char *)"l");
      break;
      case NPY_ULONG:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":314
 *                 elif t == NPY_UINT:        f = "I"
 *                 elif t == NPY_LONG:        f = "l"
 *                 elif t == NPY_ULONG:       f = "L"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_LONGLONG:    f = "q"
 *                 elif t == NPY_ULONGLONG:   f = "Q"
 */
      __pyx_v_f = ((char *)"L");
      break;
      case NPY_LONGLONG:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":315
 *                 elif t == NPY_LONG:        f = "l"
 *                 elif t == NPY_ULONG:       f = "L"
 *                 elif t == NPY_LONGLONG:    f = "q"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_ULONGLONG:   f = "Q"
 *                 elif t == NPY_FLOAT:       f = "f"
 */
      __pyx_v_f = ((char *)"q");
      break;
      case NPY_ULONGLONG:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":316
 *                 elif t == NPY_ULONG:       f = "L"
 *                 elif t == NPY_LONGLONG:    f = "q"
 *                 elif t == NPY_ULONGLONG:   f = "Q"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_FLOAT:       f = "f"
 *                 elif t == NPY_DOUBLE:      f = "d"
 */
      __pyx_v_f = ((char *)"Q");
      break;
      case NPY_FLOAT:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":317
 *                 elif t == NPY_LONGLONG:    f = "q"
 *                 elif t == NPY_ULONGLONG:   f = "Q"
 *                 elif t == NPY_FLOAT:       f = "f"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_DOUBLE:      f = "d"
 *                 elif t == NPY_LONGDOUBLE:  f = "g"
 */
      __pyx_v_f = ((char *)"f");
      break;
      case NPY_DOUBLE:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":318
 *                 elif t == NPY_ULONGLONG:   f = "Q"
 *                 elif t == NPY_FLOAT:       f = "f"
 *                 elif t == NPY_DOUBLE:      f = "d"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_LONGDOUBLE:  f = "g"
 *                 elif t == NPY_CFLOAT:      f = "Zf"
 */
      __pyx_v_f = ((char *)"d");
      break;
      case NPY_LONGDOUBLE:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":319
 *                 elif t == NPY_FLOAT:       f = "f"
 *                 elif t == NPY_DOUBLE:      f = "d"
 *                 elif t == NPY_LONGDOUBLE:  f = "g"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_CFLOAT:      f = "Zf"
 *                 elif t == NPY_CDOUBLE:     f = "Zd"
 */
      __pyx_v_f = ((char *)"g");
      break;
      case NPY_CFLOAT:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":320
 *                 elif t == NPY_DOUBLE:      f = "d"
 *                 elif t == NPY_LONGDOUBLE:  f = "g"
 *                 elif t == NPY_CFLOAT:      f = "Zf"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_CDOUBLE:     f = "Zd"
 *                 elif t == NPY_CLONGDOUBLE: f = "Zg"
 */
      __pyx_v_f = ((char *)"Zf");
      break;
      case NPY_CDOUBLE:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":321
 *                 elif t == NPY_LONGDOUBLE:  f = "g"
 *                 elif t == NPY_CFLOAT:      f = "Zf"
 *                 elif t == NPY_CDOUBLE:     f = "Zd"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_CLONGDOUBLE: f = "Zg"
 *                 elif t == NPY_OBJECT:      f = "O"
 */
      __pyx_v_f = ((char *)"Zd");
      break;
      case NPY_CLONGDOUBLE:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":322
 *                 elif t == NPY_CFLOAT:      f = "Zf"
 *                 elif t == NPY_CDOUBLE:     f = "Zd"
 *                 elif t == NPY_CLONGDOUBLE: f = "Zg"             # <<<<<<<<<<<<<<
 *                 elif t == NPY_OBJECT:      f = "O"
 *                 else:
 */
      __pyx_v_f = ((char *)"Zg");
      break;
      case NPY_OBJECT:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":323
 *                 elif t == NPY_CDOUBLE:     f = "Zd"
 *                 elif t == NPY_CLONGDOUBLE: f = "Zg"
 *                 elif t == NPY_OBJECT:      f = "O"             # <<<<<<<<<<<<<<
 *                 else:
 *                     raise ValueError(u"unknown dtype code in numpy.pxd (%d)" % t)
 */
      __pyx_v_f = ((char *)"O");
      break;
      default:

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":325
 *                 elif t == NPY_OBJECT:      f = "O"
 *                 else:
 *                     raise ValueError(u"unknown dtype code in numpy.pxd (%d)" % t)             # <<<<<<<<<<<<<<
 *                 info.format = f
 *                 return
 */
      __pyx_t_3 = __Pyx_PyInt_From_int(__pyx_v_t); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 325, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_8 = PyUnicode_Format(__pyx_kp_u_unknown_dtype_code_in_numpy_pxd, __pyx_t_3); if (unlikely(!__pyx_t_8)) __PYX_ERR(1, 325, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_3 = __Pyx_PyObject_CallOneArg(__pyx_builtin_ValueError, __pyx_t_8); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 325, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __Pyx_Raise(__pyx_t_3, 0, 0, 0);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __PYX_ERR(1, 325, __pyx_L1_error)
      break;
    }

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":326
 *                 else:
 *                     raise ValueError(u"unknown dtype code in numpy.pxd (%d)" % t)
 *                 info.format = f             # <<<<<<<<<<<<<<
 *                 return
 *             else:
 */
    __pyx_v_info->format = __pyx_v_f;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":327
 *                     raise ValueError(u"unknown dtype code in numpy.pxd (%d)" % t)
 *                 info.format = f
 *                 return             # <<<<<<<<<<<<<<
 *             else:
 *                 info.format = <char*>PyObject_Malloc(_buffer_format_string_len)
 */
    __pyx_r = 0;
    goto __pyx_L0;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":302
 *             info.obj = self
 *
 *             if not PyDataType_HASFIELDS(descr):             # <<<<<<<<<<<<<<
 *                 t = descr.type_num
 *                 if ((descr.byteorder == c'>' and little_endian) or
 */
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":329
 *                 return
 *             else:
 *                 info.format = <char*>PyObject_Malloc(_buffer_format_string_len)             # <<<<<<<<<<<<<<
 *                 info.format[0] = c'^' # Native data types, manual alignment
 *                 offset = 0
 */
  /*else*/ {
    __pyx_v_info->format = ((char *)PyObject_Malloc(0xFF));

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":330
 *             else:
 *                 info.format = <char*>PyObject_Malloc(_buffer_format_string_len)
 *                 info.format[0] = c'^' # Native data types, manual alignment             # <<<<<<<<<<<<<<
 *                 offset = 0
 *                 f = _util_dtypestring(descr, info.format + 1,
 */
    (__pyx_v_info->format[0]) = '^';

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":331
 *                 info.format = <char*>PyObject_Malloc(_buffer_format_string_len)
 *                 info.format[0] = c'^' # Native data types, manual alignment
 *                 offset = 0             # <<<<<<<<<<<<<<
 *                 f = _util_dtypestring(descr, info.format + 1,
 *                                       info.format + _buffer_format_string_len,
 */
    __pyx_v_offset = 0;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":332
 *                 info.format[0] = c'^' # Native data types, manual alignment
 *                 offset = 0
 *                 f = _util_dtypestring(descr, info.format + 1,             # <<<<<<<<<<<<<<
 *                                       info.format + _buffer_format_string_len,
 *                                       &offset)
 */
    __pyx_t_9 = __pyx_f_5numpy__util_dtypestring(__pyx_v_descr, (__pyx_v_info->format + 1), (__pyx_v_info->format + 0xFF), (&__pyx_v_offset)); if (unlikely(__pyx_t_9 == ((char *)NULL))) __PYX_ERR(1, 332, __pyx_L1_error)
    __pyx_v_f = __pyx_t_9;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":335
 *                                       info.format + _buffer_format_string_len,
 *                                       &offset)
 *                 f[0] = c'\0' # Terminate format string             # <<<<<<<<<<<<<<
 *
 *         def __releasebuffer__(ndarray self, Py_buffer* info):
 */
    (__pyx_v_f[0]) = '\x00';
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":258
 *         # experimental exception made for __getbuffer__ and __releasebuffer__
 *         # -- the details of this may change.
 *         def __getbuffer__(ndarray self, Py_buffer* info, int flags):             # <<<<<<<<<<<<<<
 *             # This implementation of getbuffer is geared towards Cython
 *             # requirements, and does not yet fulfill the PEP.
 */

  /* function exit code */
  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("numpy.ndarray.__getbuffer__", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = -1;
  if (__pyx_v_info->obj != NULL) {
    __Pyx_GOTREF(__pyx_v_info->obj);
    __Pyx_DECREF(__pyx_v_info->obj); __pyx_v_info->obj = 0;
  }
  goto __pyx_L2;
  __pyx_L0:;
  if (__pyx_v_info->obj == Py_None) {
    __Pyx_GOTREF(__pyx_v_info->obj);
    __Pyx_DECREF(__pyx_v_info->obj); __pyx_v_info->obj = 0;
  }
  __pyx_L2:;
  __Pyx_XDECREF((PyObject *)__pyx_v_descr);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":337
 *                 f[0] = c'\0' # Terminate format string
 *
 *         def __releasebuffer__(ndarray self, Py_buffer* info):             # <<<<<<<<<<<<<<
 *             if PyArray_HASFIELDS(self):
 *                 PyObject_Free(info.format)
 */

/* Python wrapper */
static CYTHON_UNUSED void __pyx_pw_5numpy_7ndarray_3__releasebuffer__(PyObject *__pyx_v_self, Py_buffer *__pyx_v_info); /*proto*/
static CYTHON_UNUSED void __pyx_pw_5numpy_7ndarray_3__releasebuffer__(PyObject *__pyx_v_self, Py_buffer *__pyx_v_info) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__releasebuffer__ (wrapper)", 0);
  __pyx_pf_5numpy_7ndarray_2__releasebuffer__(((PyArrayObject *)__pyx_v_self), ((Py_buffer *)__pyx_v_info));

  /* function exit code */
  __Pyx_RefNannyFinishContext();
}

static void __pyx_pf_5numpy_7ndarray_2__releasebuffer__(PyArrayObject *__pyx_v_self, Py_buffer *__pyx_v_info) {
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  __Pyx_RefNannySetupContext("__releasebuffer__", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":338
 *
 *         def __releasebuffer__(ndarray self, Py_buffer* info):
 *             if PyArray_HASFIELDS(self):             # <<<<<<<<<<<<<<
 *                 PyObject_Free(info.format)
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):
 */
  __pyx_t_1 = (PyArray_HASFIELDS(__pyx_v_self) != 0);
  if (__pyx_t_1) {

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":339
 *         def __releasebuffer__(ndarray self, Py_buffer* info):
 *             if PyArray_HASFIELDS(self):
 *                 PyObject_Free(info.format)             # <<<<<<<<<<<<<<
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):
 *                 PyObject_Free(info.strides)
 */
    PyObject_Free(__pyx_v_info->format);

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":338
 *
 *         def __releasebuffer__(ndarray self, Py_buffer* info):
 *             if PyArray_HASFIELDS(self):             # <<<<<<<<<<<<<<
 *                 PyObject_Free(info.format)
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):
 */
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":340
 *             if PyArray_HASFIELDS(self):
 *                 PyObject_Free(info.format)
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):             # <<<<<<<<<<<<<<
 *                 PyObject_Free(info.strides)
 *                 # info.shape was stored after info.strides in the same block
 */
  __pyx_t_1 = (((sizeof(npy_intp)) != (sizeof(Py_ssize_t))) != 0);
  if (__pyx_t_1) {

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":341
 *                 PyObject_Free(info.format)
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):
 *                 PyObject_Free(info.strides)             # <<<<<<<<<<<<<<
 *                 # info.shape was stored after info.strides in the same block
 *
 */
    PyObject_Free(__pyx_v_info->strides);

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":340
 *             if PyArray_HASFIELDS(self):
 *                 PyObject_Free(info.format)
 *             if sizeof(npy_intp) != sizeof(Py_ssize_t):             # <<<<<<<<<<<<<<
 *                 PyObject_Free(info.strides)
 *                 # info.shape was stored after info.strides in the same block
 */
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":337
 *                 f[0] = c'\0' # Terminate format string
 *
 *         def __releasebuffer__(ndarray self, Py_buffer* info):             # <<<<<<<<<<<<<<
 *             if PyArray_HASFIELDS(self):
 *                 PyObject_Free(info.format)
 */

  /* function exit code */
  __Pyx_RefNannyFinishContext();
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":820
 * ctypedef npy_cdouble     complex_t
 *
 * cdef inline object PyArray_MultiIterNew1(a):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(1, <void*>a)
 *
 */

static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew1(PyObject *__pyx_v_a) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew1", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":821
 *
 * cdef inline object PyArray_MultiIterNew1(a):
 *     return PyArray_MultiIterNew(1, <void*>a)             # <<<<<<<<<<<<<<
 *
 * cdef inline object PyArray_MultiIterNew2(a, b):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(1, ((void *)__pyx_v_a)); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 821, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":820
 * ctypedef npy_cdouble     complex_t
 *
 * cdef inline object PyArray_MultiIterNew1(a):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(1, <void*>a)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew1", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":823
 *     return PyArray_MultiIterNew(1, <void*>a)
 *
 * cdef inline object PyArray_MultiIterNew2(a, b):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(2, <void*>a, <void*>b)
 *
 */

static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew2(PyObject *__pyx_v_a, PyObject *__pyx_v_b) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew2", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":824
 *
 * cdef inline object PyArray_MultiIterNew2(a, b):
 *     return PyArray_MultiIterNew(2, <void*>a, <void*>b)             # <<<<<<<<<<<<<<
 *
 * cdef inline object PyArray_MultiIterNew3(a, b, c):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(2, ((void *)__pyx_v_a), ((void *)__pyx_v_b)); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 824, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":823
 *     return PyArray_MultiIterNew(1, <void*>a)
 *
 * cdef inline object PyArray_MultiIterNew2(a, b):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(2, <void*>a, <void*>b)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew2", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":826
 *     return PyArray_MultiIterNew(2, <void*>a, <void*>b)
 *
 * cdef inline object PyArray_MultiIterNew3(a, b, c):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(3, <void*>a, <void*>b, <void*> c)
 *
 */

static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew3(PyObject *__pyx_v_a, PyObject *__pyx_v_b, PyObject *__pyx_v_c) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew3", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":827
 *
 * cdef inline object PyArray_MultiIterNew3(a, b, c):
 *     return PyArray_MultiIterNew(3, <void*>a, <void*>b, <void*> c)             # <<<<<<<<<<<<<<
 *
 * cdef inline object PyArray_MultiIterNew4(a, b, c, d):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(3, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c)); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 827, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":826
 *     return PyArray_MultiIterNew(2, <void*>a, <void*>b)
 *
 * cdef inline object PyArray_MultiIterNew3(a, b, c):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(3, <void*>a, <void*>b, <void*> c)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew3", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":829
 *     return PyArray_MultiIterNew(3, <void*>a, <void*>b, <void*> c)
 *
 * cdef inline object PyArray_MultiIterNew4(a, b, c, d):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(4, <void*>a, <void*>b, <void*>c, <void*> d)
 *
 */

static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew4(PyObject *__pyx_v_a, PyObject *__pyx_v_b, PyObject *__pyx_v_c, PyObject *__pyx_v_d) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew4", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":830
 *
 * cdef inline object PyArray_MultiIterNew4(a, b, c, d):
 *     return PyArray_MultiIterNew(4, <void*>a, <void*>b, <void*>c, <void*> d)             # <<<<<<<<<<<<<<
 *
 * cdef inline object PyArray_MultiIterNew5(a, b, c, d, e):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(4, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c), ((void *)__pyx_v_d)); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 830, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":829
 *     return PyArray_MultiIterNew(3, <void*>a, <void*>b, <void*> c)
 *
 * cdef inline object PyArray_MultiIterNew4(a, b, c, d):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(4, <void*>a, <void*>b, <void*>c, <void*> d)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew4", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":832
 *     return PyArray_MultiIterNew(4, <void*>a, <void*>b, <void*>c, <void*> d)
 *
 * cdef inline object PyArray_MultiIterNew5(a, b, c, d, e):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(5, <void*>a, <void*>b, <void*>c, <void*> d, <void*> e)
 *
 */

static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyArray_MultiIterNew5(PyObject *__pyx_v_a, PyObject *__pyx_v_b, PyObject *__pyx_v_c, PyObject *__pyx_v_d, PyObject *__pyx_v_e) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("PyArray_MultiIterNew5", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":833
 *
 * cdef inline object PyArray_MultiIterNew5(a, b, c, d, e):
 *     return PyArray_MultiIterNew(5, <void*>a, <void*>b, <void*>c, <void*> d, <void*> e)             # <<<<<<<<<<<<<<
 *
 * cdef inline tuple PyDataType_SHAPE(dtype d):
 */
  __Pyx_XDECREF(__pyx_r);
  __pyx_t_1 = PyArray_MultiIterNew(5, ((void *)__pyx_v_a), ((void *)__pyx_v_b), ((void *)__pyx_v_c), ((void *)__pyx_v_d), ((void *)__pyx_v_e)); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 833, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_r = __pyx_t_1;
  __pyx_t_1 = 0;
  goto __pyx_L0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":832
 *     return PyArray_MultiIterNew(4, <void*>a, <void*>b, <void*>c, <void*> d)
 *
 * cdef inline object PyArray_MultiIterNew5(a, b, c, d, e):             # <<<<<<<<<<<<<<
 *     return PyArray_MultiIterNew(5, <void*>a, <void*>b, <void*>c, <void*> d, <void*> e)
 *
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_AddTraceback("numpy.PyArray_MultiIterNew5", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = 0;
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":835
 *     return PyArray_MultiIterNew(5, <void*>a, <void*>b, <void*>c, <void*> d, <void*> e)
 *
 * cdef inline tuple PyDataType_SHAPE(dtype d):             # <<<<<<<<<<<<<<
 *     if PyDataType_HASSUBARRAY(d):
 *         return <tuple>d.subarray.shape
 */

static CYTHON_INLINE PyObject *__pyx_f_5numpy_PyDataType_SHAPE(PyArray_Descr *__pyx_v_d) {
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  __Pyx_RefNannySetupContext("PyDataType_SHAPE", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":836
 *
 * cdef inline tuple PyDataType_SHAPE(dtype d):
 *     if PyDataType_HASSUBARRAY(d):             # <<<<<<<<<<<<<<
 *         return <tuple>d.subarray.shape
 *     else:
 */
  __pyx_t_1 = (PyDataType_HASSUBARRAY(__pyx_v_d) != 0);
  if (__pyx_t_1) {

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":837
 * cdef inline tuple PyDataType_SHAPE(dtype d):
 *     if PyDataType_HASSUBARRAY(d):
 *         return <tuple>d.subarray.shape             # <<<<<<<<<<<<<<
 *     else:
 *         return ()
 */
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(((PyObject*)__pyx_v_d->subarray->shape));
    __pyx_r = ((PyObject*)__pyx_v_d->subarray->shape);
    goto __pyx_L0;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":836
 *
 * cdef inline tuple PyDataType_SHAPE(dtype d):
 *     if PyDataType_HASSUBARRAY(d):             # <<<<<<<<<<<<<<
 *         return <tuple>d.subarray.shape
 *     else:
 */
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":839
 *         return <tuple>d.subarray.shape
 *     else:
 *         return ()             # <<<<<<<<<<<<<<
 *
 * cdef inline char* _util_dtypestring(dtype descr, char* f, char* end, int* offset) except NULL:
 */
  /*else*/ {
    __Pyx_XDECREF(__pyx_r);
    __Pyx_INCREF(__pyx_empty_tuple);
    __pyx_r = __pyx_empty_tuple;
    goto __pyx_L0;
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":835
 *     return PyArray_MultiIterNew(5, <void*>a, <void*>b, <void*>c, <void*> d, <void*> e)
 *
 * cdef inline tuple PyDataType_SHAPE(dtype d):             # <<<<<<<<<<<<<<
 *     if PyDataType_HASSUBARRAY(d):
 *         return <tuple>d.subarray.shape
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":841
 *         return ()
 *
 * cdef inline char* _util_dtypestring(dtype descr, char* f, char* end, int* offset) except NULL:             # <<<<<<<<<<<<<<
 *     # Recursive utility function used in __getbuffer__ to get format
 *     # string. The new location in the format string is returned.
 */

static CYTHON_INLINE char *__pyx_f_5numpy__util_dtypestring(PyArray_Descr *__pyx_v_descr, char *__pyx_v_f, char *__pyx_v_end, int *__pyx_v_offset) {
  PyArray_Descr *__pyx_v_child = 0;
  int __pyx_v_endian_detector;
  int __pyx_v_little_endian;
  PyObject *__pyx_v_fields = 0;
  PyObject *__pyx_v_childname = NULL;
  PyObject *__pyx_v_new_offset = NULL;
  PyObject *__pyx_v_t = NULL;
  char *__pyx_r;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  Py_ssize_t __pyx_t_2;
  PyObject *__pyx_t_3 = NULL;
  PyObject *__pyx_t_4 = NULL;
  int __pyx_t_5;
  int __pyx_t_6;
  int __pyx_t_7;
  long __pyx_t_8;
  char *__pyx_t_9;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("_util_dtypestring", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":846
 *
 *     cdef dtype child
 *     cdef int endian_detector = 1             # <<<<<<<<<<<<<<
 *     cdef bint little_endian = ((<char*>&endian_detector)[0] != 0)
 *     cdef tuple fields
 */
  __pyx_v_endian_detector = 1;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":847
 *     cdef dtype child
 *     cdef int endian_detector = 1
 *     cdef bint little_endian = ((<char*>&endian_detector)[0] != 0)             # <<<<<<<<<<<<<<
 *     cdef tuple fields
 *
 */
  __pyx_v_little_endian = ((((char *)(&__pyx_v_endian_detector))[0]) != 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":850
 *     cdef tuple fields
 *
 *     for childname in descr.names:             # <<<<<<<<<<<<<<
 *         fields = descr.fields[childname]
 *         child, new_offset = fields
 */
  if (unlikely(__pyx_v_descr->names == Py_None)) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
    __PYX_ERR(1, 850, __pyx_L1_error)
  }
  __pyx_t_1 = __pyx_v_descr->names; __Pyx_INCREF(__pyx_t_1); __pyx_t_2 = 0;
  for (;;) {
    if (__pyx_t_2 >= PyTuple_GET_SIZE(__pyx_t_1)) break;
    #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    __pyx_t_3 = PyTuple_GET_ITEM(__pyx_t_1, __pyx_t_2); __Pyx_INCREF(__pyx_t_3); __pyx_t_2++; if (unlikely(0 < 0)) __PYX_ERR(1, 850, __pyx_L1_error)
    #else
    __pyx_t_3 = PySequence_ITEM(__pyx_t_1, __pyx_t_2); __pyx_t_2++; if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 850, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    #endif
    __Pyx_XDECREF_SET(__pyx_v_childname, __pyx_t_3);
    __pyx_t_3 = 0;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":851
 *
 *     for childname in descr.names:
 *         fields = descr.fields[childname]             # <<<<<<<<<<<<<<
 *         child, new_offset = fields
 *
 */
    if (unlikely(__pyx_v_descr->fields == Py_None)) {
      PyErr_SetString(PyExc_TypeError, "'NoneType' object is not subscriptable");
      __PYX_ERR(1, 851, __pyx_L1_error)
    }
    __pyx_t_3 = __Pyx_PyDict_GetItem(__pyx_v_descr->fields, __pyx_v_childname); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 851, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    if (!(likely(PyTuple_CheckExact(__pyx_t_3))||((__pyx_t_3) == Py_None)||(PyErr_Format(PyExc_TypeError, "Expected %.16s, got %.200s", "tuple", Py_TYPE(__pyx_t_3)->tp_name), 0))) __PYX_ERR(1, 851, __pyx_L1_error)
    __Pyx_XDECREF_SET(__pyx_v_fields, ((PyObject*)__pyx_t_3));
    __pyx_t_3 = 0;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":852
 *     for childname in descr.names:
 *         fields = descr.fields[childname]
 *         child, new_offset = fields             # <<<<<<<<<<<<<<
 *
 *         if (end - f) - <int>(new_offset - offset[0]) < 15:
 */
    if (likely(__pyx_v_fields != Py_None)) {
      PyObject* sequence = __pyx_v_fields;
      Py_ssize_t size = __Pyx_PySequence_SIZE(sequence);
      if (unlikely(size != 2)) {
        if (size > 2) __Pyx_RaiseTooManyValuesError(2);
        else if (size >= 0) __Pyx_RaiseNeedMoreValuesError(size);
        __PYX_ERR(1, 852, __pyx_L1_error)
      }
      #if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
      __pyx_t_3 = PyTuple_GET_ITEM(sequence, 0);
      __pyx_t_4 = PyTuple_GET_ITEM(sequence, 1);
      __Pyx_INCREF(__pyx_t_3);
      __Pyx_INCREF(__pyx_t_4);
      #else
      __pyx_t_3 = PySequence_ITEM(sequence, 0); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 852, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PySequence_ITEM(sequence, 1); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 852, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      #endif
    } else {
      __Pyx_RaiseNoneNotIterableError(); __PYX_ERR(1, 852, __pyx_L1_error)
    }
    if (!(likely(((__pyx_t_3) == Py_None) || likely(__Pyx_TypeTest(__pyx_t_3, __pyx_ptype_5numpy_dtype))))) __PYX_ERR(1, 852, __pyx_L1_error)
    __Pyx_XDECREF_SET(__pyx_v_child, ((PyArray_Descr *)__pyx_t_3));
    __pyx_t_3 = 0;
    __Pyx_XDECREF_SET(__pyx_v_new_offset, __pyx_t_4);
    __pyx_t_4 = 0;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":854
 *         child, new_offset = fields
 *
 *         if (end - f) - <int>(new_offset - offset[0]) < 15:             # <<<<<<<<<<<<<<
 *             raise RuntimeError(u"Format string allocated too short, see comment in numpy.pxd")
 *
 */
    __pyx_t_4 = __Pyx_PyInt_From_int((__pyx_v_offset[0])); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 854, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_4);
    __pyx_t_3 = PyNumber_Subtract(__pyx_v_new_offset, __pyx_t_4); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 854, __pyx_L1_error)
    __Pyx_GOTREF(__pyx_t_3);
    __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
    __pyx_t_5 = __Pyx_PyInt_As_int(__pyx_t_3); if (unlikely((__pyx_t_5 == (int)-1) && PyErr_Occurred())) __PYX_ERR(1, 854, __pyx_L1_error)
    __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
    __pyx_t_6 = ((((__pyx_v_end - __pyx_v_f) - ((int)__pyx_t_5)) < 15) != 0);
    if (unlikely(__pyx_t_6)) {

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":855
 *
 *         if (end - f) - <int>(new_offset - offset[0]) < 15:
 *             raise RuntimeError(u"Format string allocated too short, see comment in numpy.pxd")             # <<<<<<<<<<<<<<
 *
 *         if ((child.byteorder == c'>' and little_endian) or
 */
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_RuntimeError, __pyx_tuple__4, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 855, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_Raise(__pyx_t_3, 0, 0, 0);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __PYX_ERR(1, 855, __pyx_L1_error)

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":854
 *         child, new_offset = fields
 *
 *         if (end - f) - <int>(new_offset - offset[0]) < 15:             # <<<<<<<<<<<<<<
 *             raise RuntimeError(u"Format string allocated too short, see comment in numpy.pxd")
 *
 */
    }

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":857
 *             raise RuntimeError(u"Format string allocated too short, see comment in numpy.pxd")
 *
 *         if ((child.byteorder == c'>' and little_endian) or             # <<<<<<<<<<<<<<
 *             (child.byteorder == c'<' and not little_endian)):
 *             raise ValueError(u"Non-native byte order not supported")
 */
    __pyx_t_7 = ((__pyx_v_child->byteorder == '>') != 0);
    if (!__pyx_t_7) {
      goto __pyx_L8_next_or;
    } else {
    }
    __pyx_t_7 = (__pyx_v_little_endian != 0);
    if (!__pyx_t_7) {
    } else {
      __pyx_t_6 = __pyx_t_7;
      goto __pyx_L7_bool_binop_done;
    }
    __pyx_L8_next_or:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":858
 *
 *         if ((child.byteorder == c'>' and little_endian) or
 *             (child.byteorder == c'<' and not little_endian)):             # <<<<<<<<<<<<<<
 *             raise ValueError(u"Non-native byte order not supported")
 *             # One could encode it in the format string and have Cython
 */
    __pyx_t_7 = ((__pyx_v_child->byteorder == '<') != 0);
    if (__pyx_t_7) {
    } else {
      __pyx_t_6 = __pyx_t_7;
      goto __pyx_L7_bool_binop_done;
    }
    __pyx_t_7 = ((!(__pyx_v_little_endian != 0)) != 0);
    __pyx_t_6 = __pyx_t_7;
    __pyx_L7_bool_binop_done:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":857
 *             raise RuntimeError(u"Format string allocated too short, see comment in numpy.pxd")
 *
 *         if ((child.byteorder == c'>' and little_endian) or             # <<<<<<<<<<<<<<
 *             (child.byteorder == c'<' and not little_endian)):
 *             raise ValueError(u"Non-native byte order not supported")
 */
    if (unlikely(__pyx_t_6)) {

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":859
 *         if ((child.byteorder == c'>' and little_endian) or
 *             (child.byteorder == c'<' and not little_endian)):
 *             raise ValueError(u"Non-native byte order not supported")             # <<<<<<<<<<<<<<
 *             # One could encode it in the format string and have Cython
 *             # complain instead, BUT: < and > in format strings also imply
 */
      __pyx_t_3 = __Pyx_PyObject_Call(__pyx_builtin_ValueError, __pyx_tuple__3, NULL); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 859, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __Pyx_Raise(__pyx_t_3, 0, 0, 0);
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __PYX_ERR(1, 859, __pyx_L1_error)

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":857
 *             raise RuntimeError(u"Format string allocated too short, see comment in numpy.pxd")
 *
 *         if ((child.byteorder == c'>' and little_endian) or             # <<<<<<<<<<<<<<
 *             (child.byteorder == c'<' and not little_endian)):
 *             raise ValueError(u"Non-native byte order not supported")
 */
    }

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":869
 *
 *         # Output padding bytes
 *         while offset[0] < new_offset:             # <<<<<<<<<<<<<<
 *             f[0] = 120 # "x"; pad byte
 *             f += 1
 */
    while (1) {
      __pyx_t_3 = __Pyx_PyInt_From_int((__pyx_v_offset[0])); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 869, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_t_3, __pyx_v_new_offset, Py_LT); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 869, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 869, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (!__pyx_t_6) break;

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":870
 *         # Output padding bytes
 *         while offset[0] < new_offset:
 *             f[0] = 120 # "x"; pad byte             # <<<<<<<<<<<<<<
 *             f += 1
 *             offset[0] += 1
 */
      (__pyx_v_f[0]) = 0x78;

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":871
 *         while offset[0] < new_offset:
 *             f[0] = 120 # "x"; pad byte
 *             f += 1             # <<<<<<<<<<<<<<
 *             offset[0] += 1
 *
 */
      __pyx_v_f = (__pyx_v_f + 1);

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":872
 *             f[0] = 120 # "x"; pad byte
 *             f += 1
 *             offset[0] += 1             # <<<<<<<<<<<<<<
 *
 *         offset[0] += child.itemsize
 */
      __pyx_t_8 = 0;
      (__pyx_v_offset[__pyx_t_8]) = ((__pyx_v_offset[__pyx_t_8]) + 1);
    }

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":874
 *             offset[0] += 1
 *
 *         offset[0] += child.itemsize             # <<<<<<<<<<<<<<
 *
 *         if not PyDataType_HASFIELDS(child):
 */
    __pyx_t_8 = 0;
    (__pyx_v_offset[__pyx_t_8]) = ((__pyx_v_offset[__pyx_t_8]) + __pyx_v_child->elsize);

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":876
 *         offset[0] += child.itemsize
 *
 *         if not PyDataType_HASFIELDS(child):             # <<<<<<<<<<<<<<
 *             t = child.type_num
 *             if end - f < 5:
 */
    __pyx_t_6 = ((!(PyDataType_HASFIELDS(__pyx_v_child) != 0)) != 0);
    if (__pyx_t_6) {

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":877
 *
 *         if not PyDataType_HASFIELDS(child):
 *             t = child.type_num             # <<<<<<<<<<<<<<
 *             if end - f < 5:
 *                 raise RuntimeError(u"Format string allocated too short.")
 */
      __pyx_t_4 = __Pyx_PyInt_From_int(__pyx_v_child->type_num); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 877, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __Pyx_XDECREF_SET(__pyx_v_t, __pyx_t_4);
      __pyx_t_4 = 0;

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":878
 *         if not PyDataType_HASFIELDS(child):
 *             t = child.type_num
 *             if end - f < 5:             # <<<<<<<<<<<<<<
 *                 raise RuntimeError(u"Format string allocated too short.")
 *
 */
      __pyx_t_6 = (((__pyx_v_end - __pyx_v_f) < 5) != 0);
      if (unlikely(__pyx_t_6)) {

        /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":879
 *             t = child.type_num
 *             if end - f < 5:
 *                 raise RuntimeError(u"Format string allocated too short.")             # <<<<<<<<<<<<<<
 *
 *             # Until ticket #99 is fixed, use integers to avoid warnings
 */
        __pyx_t_4 = __Pyx_PyObject_Call(__pyx_builtin_RuntimeError, __pyx_tuple__5, NULL); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 879, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_Raise(__pyx_t_4, 0, 0, 0);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
        __PYX_ERR(1, 879, __pyx_L1_error)

        /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":878
 *         if not PyDataType_HASFIELDS(child):
 *             t = child.type_num
 *             if end - f < 5:             # <<<<<<<<<<<<<<
 *                 raise RuntimeError(u"Format string allocated too short.")
 *
 */
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":882
 *
 *             # Until ticket #99 is fixed, use integers to avoid warnings
 *             if   t == NPY_BYTE:        f[0] =  98 #"b"             # <<<<<<<<<<<<<<
 *             elif t == NPY_UBYTE:       f[0] =  66 #"B"
 *             elif t == NPY_SHORT:       f[0] = 104 #"h"
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_BYTE); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 882, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 882, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 882, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 98;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":883
 *             # Until ticket #99 is fixed, use integers to avoid warnings
 *             if   t == NPY_BYTE:        f[0] =  98 #"b"
 *             elif t == NPY_UBYTE:       f[0] =  66 #"B"             # <<<<<<<<<<<<<<
 *             elif t == NPY_SHORT:       f[0] = 104 #"h"
 *             elif t == NPY_USHORT:      f[0] =  72 #"H"
 */
      __pyx_t_3 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_UBYTE); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 883, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 883, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 883, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 66;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":884
 *             if   t == NPY_BYTE:        f[0] =  98 #"b"
 *             elif t == NPY_UBYTE:       f[0] =  66 #"B"
 *             elif t == NPY_SHORT:       f[0] = 104 #"h"             # <<<<<<<<<<<<<<
 *             elif t == NPY_USHORT:      f[0] =  72 #"H"
 *             elif t == NPY_INT:         f[0] = 105 #"i"
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_SHORT); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 884, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 884, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 884, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 0x68;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":885
 *             elif t == NPY_UBYTE:       f[0] =  66 #"B"
 *             elif t == NPY_SHORT:       f[0] = 104 #"h"
 *             elif t == NPY_USHORT:      f[0] =  72 #"H"             # <<<<<<<<<<<<<<
 *             elif t == NPY_INT:         f[0] = 105 #"i"
 *             elif t == NPY_UINT:        f[0] =  73 #"I"
 */
      __pyx_t_3 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_USHORT); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 885, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 885, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 885, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 72;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":886
 *             elif t == NPY_SHORT:       f[0] = 104 #"h"
 *             elif t == NPY_USHORT:      f[0] =  72 #"H"
 *             elif t == NPY_INT:         f[0] = 105 #"i"             # <<<<<<<<<<<<<<
 *             elif t == NPY_UINT:        f[0] =  73 #"I"
 *             elif t == NPY_LONG:        f[0] = 108 #"l"
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_INT); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 886, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 886, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 886, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 0x69;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":887
 *             elif t == NPY_USHORT:      f[0] =  72 #"H"
 *             elif t == NPY_INT:         f[0] = 105 #"i"
 *             elif t == NPY_UINT:        f[0] =  73 #"I"             # <<<<<<<<<<<<<<
 *             elif t == NPY_LONG:        f[0] = 108 #"l"
 *             elif t == NPY_ULONG:       f[0] = 76  #"L"
 */
      __pyx_t_3 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_UINT); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 887, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 887, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 887, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 73;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":888
 *             elif t == NPY_INT:         f[0] = 105 #"i"
 *             elif t == NPY_UINT:        f[0] =  73 #"I"
 *             elif t == NPY_LONG:        f[0] = 108 #"l"             # <<<<<<<<<<<<<<
 *             elif t == NPY_ULONG:       f[0] = 76  #"L"
 *             elif t == NPY_LONGLONG:    f[0] = 113 #"q"
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_LONG); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 888, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 888, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 888, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 0x6C;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":889
 *             elif t == NPY_UINT:        f[0] =  73 #"I"
 *             elif t == NPY_LONG:        f[0] = 108 #"l"
 *             elif t == NPY_ULONG:       f[0] = 76  #"L"             # <<<<<<<<<<<<<<
 *             elif t == NPY_LONGLONG:    f[0] = 113 #"q"
 *             elif t == NPY_ULONGLONG:   f[0] = 81  #"Q"
 */
      __pyx_t_3 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_ULONG); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 889, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 889, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 889, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 76;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":890
 *             elif t == NPY_LONG:        f[0] = 108 #"l"
 *             elif t == NPY_ULONG:       f[0] = 76  #"L"
 *             elif t == NPY_LONGLONG:    f[0] = 113 #"q"             # <<<<<<<<<<<<<<
 *             elif t == NPY_ULONGLONG:   f[0] = 81  #"Q"
 *             elif t == NPY_FLOAT:       f[0] = 102 #"f"
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_LONGLONG); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 890, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 890, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 890, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 0x71;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":891
 *             elif t == NPY_ULONG:       f[0] = 76  #"L"
 *             elif t == NPY_LONGLONG:    f[0] = 113 #"q"
 *             elif t == NPY_ULONGLONG:   f[0] = 81  #"Q"             # <<<<<<<<<<<<<<
 *             elif t == NPY_FLOAT:       f[0] = 102 #"f"
 *             elif t == NPY_DOUBLE:      f[0] = 100 #"d"
 */
      __pyx_t_3 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_ULONGLONG); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 891, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 891, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 891, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 81;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":892
 *             elif t == NPY_LONGLONG:    f[0] = 113 #"q"
 *             elif t == NPY_ULONGLONG:   f[0] = 81  #"Q"
 *             elif t == NPY_FLOAT:       f[0] = 102 #"f"             # <<<<<<<<<<<<<<
 *             elif t == NPY_DOUBLE:      f[0] = 100 #"d"
 *             elif t == NPY_LONGDOUBLE:  f[0] = 103 #"g"
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_FLOAT); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 892, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 892, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 892, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 0x66;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":893
 *             elif t == NPY_ULONGLONG:   f[0] = 81  #"Q"
 *             elif t == NPY_FLOAT:       f[0] = 102 #"f"
 *             elif t == NPY_DOUBLE:      f[0] = 100 #"d"             # <<<<<<<<<<<<<<
 *             elif t == NPY_LONGDOUBLE:  f[0] = 103 #"g"
 *             elif t == NPY_CFLOAT:      f[0] = 90; f[1] = 102; f += 1 # Zf
 */
      __pyx_t_3 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_DOUBLE); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 893, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 893, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 893, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 0x64;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":894
 *             elif t == NPY_FLOAT:       f[0] = 102 #"f"
 *             elif t == NPY_DOUBLE:      f[0] = 100 #"d"
 *             elif t == NPY_LONGDOUBLE:  f[0] = 103 #"g"             # <<<<<<<<<<<<<<
 *             elif t == NPY_CFLOAT:      f[0] = 90; f[1] = 102; f += 1 # Zf
 *             elif t == NPY_CDOUBLE:     f[0] = 90; f[1] = 100; f += 1 # Zd
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_LONGDOUBLE); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 894, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 894, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 894, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 0x67;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":895
 *             elif t == NPY_DOUBLE:      f[0] = 100 #"d"
 *             elif t == NPY_LONGDOUBLE:  f[0] = 103 #"g"
 *             elif t == NPY_CFLOAT:      f[0] = 90; f[1] = 102; f += 1 # Zf             # <<<<<<<<<<<<<<
 *             elif t == NPY_CDOUBLE:     f[0] = 90; f[1] = 100; f += 1 # Zd
 *             elif t == NPY_CLONGDOUBLE: f[0] = 90; f[1] = 103; f += 1 # Zg
 */
      __pyx_t_3 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_CFLOAT); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 895, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 895, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 895, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 90;
        (__pyx_v_f[1]) = 0x66;
        __pyx_v_f = (__pyx_v_f + 1);
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":896
 *             elif t == NPY_LONGDOUBLE:  f[0] = 103 #"g"
 *             elif t == NPY_CFLOAT:      f[0] = 90; f[1] = 102; f += 1 # Zf
 *             elif t == NPY_CDOUBLE:     f[0] = 90; f[1] = 100; f += 1 # Zd             # <<<<<<<<<<<<<<
 *             elif t == NPY_CLONGDOUBLE: f[0] = 90; f[1] = 103; f += 1 # Zg
 *             elif t == NPY_OBJECT:      f[0] = 79 #"O"
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_CDOUBLE); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 896, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 896, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 896, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 90;
        (__pyx_v_f[1]) = 0x64;
        __pyx_v_f = (__pyx_v_f + 1);
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":897
 *             elif t == NPY_CFLOAT:      f[0] = 90; f[1] = 102; f += 1 # Zf
 *             elif t == NPY_CDOUBLE:     f[0] = 90; f[1] = 100; f += 1 # Zd
 *             elif t == NPY_CLONGDOUBLE: f[0] = 90; f[1] = 103; f += 1 # Zg             # <<<<<<<<<<<<<<
 *             elif t == NPY_OBJECT:      f[0] = 79 #"O"
 *             else:
 */
      __pyx_t_3 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_CLONGDOUBLE); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 897, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_3);
      __pyx_t_4 = PyObject_RichCompare(__pyx_v_t, __pyx_t_3, Py_EQ); __Pyx_XGOTREF(__pyx_t_4); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 897, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_4); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 897, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      if (__pyx_t_6) {
        (__pyx_v_f[0]) = 90;
        (__pyx_v_f[1]) = 0x67;
        __pyx_v_f = (__pyx_v_f + 1);
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":898
 *             elif t == NPY_CDOUBLE:     f[0] = 90; f[1] = 100; f += 1 # Zd
 *             elif t == NPY_CLONGDOUBLE: f[0] = 90; f[1] = 103; f += 1 # Zg
 *             elif t == NPY_OBJECT:      f[0] = 79 #"O"             # <<<<<<<<<<<<<<
 *             else:
 *                 raise ValueError(u"unknown dtype code in numpy.pxd (%d)" % t)
 */
      __pyx_t_4 = __Pyx_PyInt_From_enum__NPY_TYPES(NPY_OBJECT); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 898, __pyx_L1_error)
      __Pyx_GOTREF(__pyx_t_4);
      __pyx_t_3 = PyObject_RichCompare(__pyx_v_t, __pyx_t_4, Py_EQ); __Pyx_XGOTREF(__pyx_t_3); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 898, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
      __pyx_t_6 = __Pyx_PyObject_IsTrue(__pyx_t_3); if (unlikely(__pyx_t_6 < 0)) __PYX_ERR(1, 898, __pyx_L1_error)
      __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
      if (likely(__pyx_t_6)) {
        (__pyx_v_f[0]) = 79;
        goto __pyx_L15;
      }

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":900
 *             elif t == NPY_OBJECT:      f[0] = 79 #"O"
 *             else:
 *                 raise ValueError(u"unknown dtype code in numpy.pxd (%d)" % t)             # <<<<<<<<<<<<<<
 *             f += 1
 *         else:
 */
      /*else*/ {
        __pyx_t_3 = __Pyx_PyUnicode_FormatSafe(__pyx_kp_u_unknown_dtype_code_in_numpy_pxd, __pyx_v_t); if (unlikely(!__pyx_t_3)) __PYX_ERR(1, 900, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_3);
        __pyx_t_4 = __Pyx_PyObject_CallOneArg(__pyx_builtin_ValueError, __pyx_t_3); if (unlikely(!__pyx_t_4)) __PYX_ERR(1, 900, __pyx_L1_error)
        __Pyx_GOTREF(__pyx_t_4);
        __Pyx_DECREF(__pyx_t_3); __pyx_t_3 = 0;
        __Pyx_Raise(__pyx_t_4, 0, 0, 0);
        __Pyx_DECREF(__pyx_t_4); __pyx_t_4 = 0;
        __PYX_ERR(1, 900, __pyx_L1_error)
      }
      __pyx_L15:;

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":901
 *             else:
 *                 raise ValueError(u"unknown dtype code in numpy.pxd (%d)" % t)
 *             f += 1             # <<<<<<<<<<<<<<
 *         else:
 *             # Cython ignores struct boundary information ("T{...}"),
 */
      __pyx_v_f = (__pyx_v_f + 1);

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":876
 *         offset[0] += child.itemsize
 *
 *         if not PyDataType_HASFIELDS(child):             # <<<<<<<<<<<<<<
 *             t = child.type_num
 *             if end - f < 5:
 */
      goto __pyx_L13;
    }

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":905
 *             # Cython ignores struct boundary information ("T{...}"),
 *             # so don't output it
 *             f = _util_dtypestring(child, f, end, offset)             # <<<<<<<<<<<<<<
 *     return f
 *
 */
    /*else*/ {
      __pyx_t_9 = __pyx_f_5numpy__util_dtypestring(__pyx_v_child, __pyx_v_f, __pyx_v_end, __pyx_v_offset); if (unlikely(__pyx_t_9 == ((char *)NULL))) __PYX_ERR(1, 905, __pyx_L1_error)
      __pyx_v_f = __pyx_t_9;
    }
    __pyx_L13:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":850
 *     cdef tuple fields
 *
 *     for childname in descr.names:             # <<<<<<<<<<<<<<
 *         fields = descr.fields[childname]
 *         child, new_offset = fields
 */
  }
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":906
 *             # so don't output it
 *             f = _util_dtypestring(child, f, end, offset)
 *     return f             # <<<<<<<<<<<<<<
 *
 *
 */
  __pyx_r = __pyx_v_f;
  goto __pyx_L0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":841
 *         return ()
 *
 * cdef inline char* _util_dtypestring(dtype descr, char* f, char* end, int* offset) except NULL:             # <<<<<<<<<<<<<<
 *     # Recursive utility function used in __getbuffer__ to get format
 *     # string. The new location in the format string is returned.
 */

  /* function exit code */
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_XDECREF(__pyx_t_3);
  __Pyx_XDECREF(__pyx_t_4);
  __Pyx_AddTraceback("numpy._util_dtypestring", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = NULL;
  __pyx_L0:;
  __Pyx_XDECREF((PyObject *)__pyx_v_child);
  __Pyx_XDECREF(__pyx_v_fields);
  __Pyx_XDECREF(__pyx_v_childname);
  __Pyx_XDECREF(__pyx_v_new_offset);
  __Pyx_XDECREF(__pyx_v_t);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1021
 *     int _import_umath() except -1
 *
 * cdef inline void set_array_base(ndarray arr, object base):             # <<<<<<<<<<<<<<
 *     Py_INCREF(base) # important to do this before stealing the reference below!
 *     PyArray_SetBaseObject(arr, base)
 */

static CYTHON_INLINE void __pyx_f_5numpy_set_array_base(PyArrayObject *__pyx_v_arr, PyObject *__pyx_v_base) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("set_array_base", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1022
 *
 * cdef inline void set_array_base(ndarray arr, object base):
 *     Py_INCREF(base) # important to do this before stealing the reference below!             # <<<<<<<<<<<<<<
 *     PyArray_SetBaseObject(arr, base)
 *
 */
  Py_INCREF(__pyx_v_base);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1023
 * cdef inline void set_array_base(ndarray arr, object base):
 *     Py_INCREF(base) # important to do this before stealing the reference below!
 *     PyArray_SetBaseObject(arr, base)             # <<<<<<<<<<<<<<
 *
 * cdef inline object get_array_base(ndarray arr):
 */
  (void)(PyArray_SetBaseObject(__pyx_v_arr, __pyx_v_base));

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1021
 *     int _import_umath() except -1
 *
 * cdef inline void set_array_base(ndarray arr, object base):             # <<<<<<<<<<<<<<
 *     Py_INCREF(base) # important to do this before stealing the reference below!
 *     PyArray_SetBaseObject(arr, base)
 */

  /* function exit code */
  __Pyx_RefNannyFinishContext();
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1025
 *     PyArray_SetBaseObject(arr, base)
 *
 * cdef inline object get_array_base(ndarray arr):             # <<<<<<<<<<<<<<
 *     base = PyArray_BASE(arr)
 *     if base is NULL:
 */

static CYTHON_INLINE PyObject *__pyx_f_5numpy_get_array_base(PyArrayObject *__pyx_v_arr) {
  PyObject *__pyx_v_base;
  PyObject *__pyx_r = NULL;
  __Pyx_RefNannyDeclarations
  int __pyx_t_1;
  __Pyx_RefNannySetupContext("get_array_base", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1026
 *
 * cdef inline object get_array_base(ndarray arr):
 *     base = PyArray_BASE(arr)             # <<<<<<<<<<<<<<
 *     if base is NULL:
 *         return None
 */
  __pyx_v_base = PyArray_BASE(__pyx_v_arr);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1027
 * cdef inline object get_array_base(ndarray arr):
 *     base = PyArray_BASE(arr)
 *     if base is NULL:             # <<<<<<<<<<<<<<
 *         return None
 *     return <object>base
 */
  __pyx_t_1 = ((__pyx_v_base == NULL) != 0);
  if (__pyx_t_1) {

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1028
 *     base = PyArray_BASE(arr)
 *     if base is NULL:
 *         return None             # <<<<<<<<<<<<<<
 *     return <object>base
 *
 */
    __Pyx_XDECREF(__pyx_r);
    __pyx_r = Py_None; __Pyx_INCREF(Py_None);
    goto __pyx_L0;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1027
 * cdef inline object get_array_base(ndarray arr):
 *     base = PyArray_BASE(arr)
 *     if base is NULL:             # <<<<<<<<<<<<<<
 *         return None
 *     return <object>base
 */
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1029
 *     if base is NULL:
 *         return None
 *     return <object>base             # <<<<<<<<<<<<<<
 *
 * # Versions of the import_* functions which are more suitable for
 */
  __Pyx_XDECREF(__pyx_r);
  __Pyx_INCREF(((PyObject *)__pyx_v_base));
  __pyx_r = ((PyObject *)__pyx_v_base);
  goto __pyx_L0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1025
 *     PyArray_SetBaseObject(arr, base)
 *
 * cdef inline object get_array_base(ndarray arr):             # <<<<<<<<<<<<<<
 *     base = PyArray_BASE(arr)
 *     if base is NULL:
 */

  /* function exit code */
  __pyx_L0:;
  __Pyx_XGIVEREF(__pyx_r);
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1033
 * # Versions of the import_* functions which are more suitable for
 * # Cython code.
 * cdef inline int import_array() except -1:             # <<<<<<<<<<<<<<
 *     try:
 *         _import_array()
 */

static CYTHON_INLINE int __pyx_f_5numpy_import_array(void) {
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("import_array", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1034
 * # Cython code.
 * cdef inline int import_array() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_array()
 *     except Exception:
 */
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_t_2);
    __Pyx_XGOTREF(__pyx_t_3);
    /*try:*/ {

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1035
 * cdef inline int import_array() except -1:
 *     try:
 *         _import_array()             # <<<<<<<<<<<<<<
 *     except Exception:
 *         raise ImportError("numpy.core.multiarray failed to import")
 */
      __pyx_t_4 = _import_array(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(1, 1035, __pyx_L3_error)

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1034
 * # Cython code.
 * cdef inline int import_array() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_array()
 *     except Exception:
 */
    }
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1036
 *     try:
 *         _import_array()
 *     except Exception:             # <<<<<<<<<<<<<<
 *         raise ImportError("numpy.core.multiarray failed to import")
 *
 */
    __pyx_t_4 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
    if (__pyx_t_4) {
      __Pyx_AddTraceback("numpy.import_array", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(1, 1036, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_7);

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1037
 *         _import_array()
 *     except Exception:
 *         raise ImportError("numpy.core.multiarray failed to import")             # <<<<<<<<<<<<<<
 *
 * cdef inline int import_umath() except -1:
 */
      __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_ImportError, __pyx_tuple__6, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(1, 1037, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_Raise(__pyx_t_8, 0, 0, 0);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __PYX_ERR(1, 1037, __pyx_L5_except_error)
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1034
 * # Cython code.
 * cdef inline int import_array() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_array()
 *     except Exception:
 */
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    goto __pyx_L1_error;
    __pyx_L8_try_end:;
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1033
 * # Versions of the import_* functions which are more suitable for
 * # Cython code.
 * cdef inline int import_array() except -1:             # <<<<<<<<<<<<<<
 *     try:
 *         _import_array()
 */

  /* function exit code */
  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("numpy.import_array", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = -1;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1039
 *         raise ImportError("numpy.core.multiarray failed to import")
 *
 * cdef inline int import_umath() except -1:             # <<<<<<<<<<<<<<
 *     try:
 *         _import_umath()
 */

static CYTHON_INLINE int __pyx_f_5numpy_import_umath(void) {
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("import_umath", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1040
 *
 * cdef inline int import_umath() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_umath()
 *     except Exception:
 */
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_t_2);
    __Pyx_XGOTREF(__pyx_t_3);
    /*try:*/ {

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1041
 * cdef inline int import_umath() except -1:
 *     try:
 *         _import_umath()             # <<<<<<<<<<<<<<
 *     except Exception:
 *         raise ImportError("numpy.core.umath failed to import")
 */
      __pyx_t_4 = _import_umath(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(1, 1041, __pyx_L3_error)

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1040
 *
 * cdef inline int import_umath() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_umath()
 *     except Exception:
 */
    }
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1042
 *     try:
 *         _import_umath()
 *     except Exception:             # <<<<<<<<<<<<<<
 *         raise ImportError("numpy.core.umath failed to import")
 *
 */
    __pyx_t_4 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
    if (__pyx_t_4) {
      __Pyx_AddTraceback("numpy.import_umath", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(1, 1042, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_7);

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1043
 *         _import_umath()
 *     except Exception:
 *         raise ImportError("numpy.core.umath failed to import")             # <<<<<<<<<<<<<<
 *
 * cdef inline int import_ufunc() except -1:
 */
      __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_ImportError, __pyx_tuple__7, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(1, 1043, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_Raise(__pyx_t_8, 0, 0, 0);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __PYX_ERR(1, 1043, __pyx_L5_except_error)
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1040
 *
 * cdef inline int import_umath() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_umath()
 *     except Exception:
 */
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    goto __pyx_L1_error;
    __pyx_L8_try_end:;
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1039
 *         raise ImportError("numpy.core.multiarray failed to import")
 *
 * cdef inline int import_umath() except -1:             # <<<<<<<<<<<<<<
 *     try:
 *         _import_umath()
 */

  /* function exit code */
  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("numpy.import_umath", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = -1;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

/* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1045
 *         raise ImportError("numpy.core.umath failed to import")
 *
 * cdef inline int import_ufunc() except -1:             # <<<<<<<<<<<<<<
 *     try:
 *         _import_umath()
 */

static CYTHON_INLINE int __pyx_f_5numpy_import_ufunc(void) {
  int __pyx_r;
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  PyObject *__pyx_t_2 = NULL;
  PyObject *__pyx_t_3 = NULL;
  int __pyx_t_4;
  PyObject *__pyx_t_5 = NULL;
  PyObject *__pyx_t_6 = NULL;
  PyObject *__pyx_t_7 = NULL;
  PyObject *__pyx_t_8 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("import_ufunc", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1046
 *
 * cdef inline int import_ufunc() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_umath()
 *     except Exception:
 */
  {
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ExceptionSave(&__pyx_t_1, &__pyx_t_2, &__pyx_t_3);
    __Pyx_XGOTREF(__pyx_t_1);
    __Pyx_XGOTREF(__pyx_t_2);
    __Pyx_XGOTREF(__pyx_t_3);
    /*try:*/ {

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1047
 * cdef inline int import_ufunc() except -1:
 *     try:
 *         _import_umath()             # <<<<<<<<<<<<<<
 *     except Exception:
 *         raise ImportError("numpy.core.umath failed to import")
 */
      __pyx_t_4 = _import_umath(); if (unlikely(__pyx_t_4 == ((int)-1))) __PYX_ERR(1, 1047, __pyx_L3_error)

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1046
 *
 * cdef inline int import_ufunc() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_umath()
 *     except Exception:
 */
    }
    __Pyx_XDECREF(__pyx_t_1); __pyx_t_1 = 0;
    __Pyx_XDECREF(__pyx_t_2); __pyx_t_2 = 0;
    __Pyx_XDECREF(__pyx_t_3); __pyx_t_3 = 0;
    goto __pyx_L8_try_end;
    __pyx_L3_error:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1048
 *     try:
 *         _import_umath()
 *     except Exception:             # <<<<<<<<<<<<<<
 *         raise ImportError("numpy.core.umath failed to import")
 */
    __pyx_t_4 = __Pyx_PyErr_ExceptionMatches(((PyObject *)(&((PyTypeObject*)PyExc_Exception)[0])));
    if (__pyx_t_4) {
      __Pyx_AddTraceback("numpy.import_ufunc", __pyx_clineno, __pyx_lineno, __pyx_filename);
      if (__Pyx_GetException(&__pyx_t_5, &__pyx_t_6, &__pyx_t_7) < 0) __PYX_ERR(1, 1048, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_5);
      __Pyx_GOTREF(__pyx_t_6);
      __Pyx_GOTREF(__pyx_t_7);

      /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1049
 *         _import_umath()
 *     except Exception:
 *         raise ImportError("numpy.core.umath failed to import")             # <<<<<<<<<<<<<<
 */
      __pyx_t_8 = __Pyx_PyObject_Call(__pyx_builtin_ImportError, __pyx_tuple__7, NULL); if (unlikely(!__pyx_t_8)) __PYX_ERR(1, 1049, __pyx_L5_except_error)
      __Pyx_GOTREF(__pyx_t_8);
      __Pyx_Raise(__pyx_t_8, 0, 0, 0);
      __Pyx_DECREF(__pyx_t_8); __pyx_t_8 = 0;
      __PYX_ERR(1, 1049, __pyx_L5_except_error)
    }
    goto __pyx_L5_except_error;
    __pyx_L5_except_error:;

    /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1046
 *
 * cdef inline int import_ufunc() except -1:
 *     try:             # <<<<<<<<<<<<<<
 *         _import_umath()
 *     except Exception:
 */
    __Pyx_XGIVEREF(__pyx_t_1);
    __Pyx_XGIVEREF(__pyx_t_2);
    __Pyx_XGIVEREF(__pyx_t_3);
    __Pyx_ExceptionReset(__pyx_t_1, __pyx_t_2, __pyx_t_3);
    goto __pyx_L1_error;
    __pyx_L8_try_end:;
  }

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1045
 *         raise ImportError("numpy.core.umath failed to import")
 *
 * cdef inline int import_ufunc() except -1:             # <<<<<<<<<<<<<<
 *     try:
 *         _import_umath()
 */

  /* function exit code */
  __pyx_r = 0;
  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_5);
  __Pyx_XDECREF(__pyx_t_6);
  __Pyx_XDECREF(__pyx_t_7);
  __Pyx_XDECREF(__pyx_t_8);
  __Pyx_AddTraceback("numpy.import_ufunc", __pyx_clineno, __pyx_lineno, __pyx_filename);
  __pyx_r = -1;
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  return __pyx_r;
}

static PyMethodDef __pyx_methods[] = {
  {0, 0, 0, 0}
};

#if PY_MAJOR_VERSION >= 3
#if CYTHON_PEP489_MULTI_PHASE_INIT
static PyObject* __pyx_pymod_create(PyObject *spec, PyModuleDef *def); /*proto*/
static int __pyx_pymod_exec_soft_nms_cpu(PyObject* module); /*proto*/
static PyModuleDef_Slot __pyx_moduledef_slots[] = {
  {Py_mod_create, (void*)__pyx_pymod_create},
  {Py_mod_exec, (void*)__pyx_pymod_exec_soft_nms_cpu},
  {0, NULL}
};
#endif

static struct PyModuleDef __pyx_moduledef = {
    PyModuleDef_HEAD_INIT,
    "soft_nms_cpu",
    0, /* m_doc */
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    0, /* m_size */
  #else
    -1, /* m_size */
  #endif
    __pyx_methods /* m_methods */,
  #if CYTHON_PEP489_MULTI_PHASE_INIT
    __pyx_moduledef_slots, /* m_slots */
  #else
    NULL, /* m_reload */
  #endif
    NULL, /* m_traverse */
    NULL, /* m_clear */
    NULL /* m_free */
};
#endif
#ifndef CYTHON_SMALL_CODE
#if defined(__clang__)
    #define CYTHON_SMALL_CODE
#elif defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 3))
    #define CYTHON_SMALL_CODE __attribute__((cold))
#else
    #define CYTHON_SMALL_CODE
#endif
#endif

static __Pyx_StringTabEntry __pyx_string_tab[] = {
  {&__pyx_kp_u_Format_string_allocated_too_shor, __pyx_k_Format_string_allocated_too_shor, sizeof(__pyx_k_Format_string_allocated_too_shor), 0, 1, 0, 0},
  {&__pyx_kp_u_Format_string_allocated_too_shor_2, __pyx_k_Format_string_allocated_too_shor_2, sizeof(__pyx_k_Format_string_allocated_too_shor_2), 0, 1, 0, 0},
  {&__pyx_n_s_ImportError, __pyx_k_ImportError, sizeof(__pyx_k_ImportError), 0, 0, 1, 1},
  {&__pyx_n_s_N, __pyx_k_N, sizeof(__pyx_k_N), 0, 0, 1, 1},
  {&__pyx_kp_u_Non_native_byte_order_not_suppor, __pyx_k_Non_native_byte_order_not_suppor, sizeof(__pyx_k_Non_native_byte_order_not_suppor), 0, 1, 0, 0},
  {&__pyx_n_s_RuntimeError, __pyx_k_RuntimeError, sizeof(__pyx_k_RuntimeError), 0, 0, 1, 1},
  {&__pyx_n_s_ValueError, __pyx_k_ValueError, sizeof(__pyx_k_ValueError), 0, 0, 1, 1},
  {&__pyx_n_s_arange, __pyx_k_arange, sizeof(__pyx_k_arange), 0, 0, 1, 1},
  {&__pyx_n_s_area, __pyx_k_area, sizeof(__pyx_k_area), 0, 0, 1, 1},
  {&__pyx_n_s_box_area, __pyx_k_box_area, sizeof(__pyx_k_box_area), 0, 0, 1, 1},
  {&__pyx_n_s_boxes, __pyx_k_boxes, sizeof(__pyx_k_boxes), 0, 0, 1, 1},
  {&__pyx_n_s_boxes_in, __pyx_k_boxes_in, sizeof(__pyx_k_boxes_in), 0, 0, 1, 1},
  {&__pyx_n_s_cline_in_traceback, __pyx_k_cline_in_traceback, sizeof(__pyx_k_cline_in_traceback), 0, 0, 1, 1},
  {&__pyx_n_s_copy, __pyx_k_copy, sizeof(__pyx_k_copy), 0, 0, 1, 1},
  {&__pyx_n_s_exp, __pyx_k_exp, sizeof(__pyx_k_exp), 0, 0, 1, 1},
  {&__pyx_n_s_i, __pyx_k_i, sizeof(__pyx_k_i), 0, 0, 1, 1},
  {&__pyx_n_s_ih, __pyx_k_ih, sizeof(__pyx_k_ih), 0, 0, 1, 1},
  {&__pyx_n_s_import, __pyx_k_import, sizeof(__pyx_k_import), 0, 0, 1, 1},
  {&__pyx_n_s_inds, __pyx_k_inds, sizeof(__pyx_k_inds), 0, 0, 1, 1},
  {&__pyx_n_s_iou_thr, __pyx_k_iou_thr, sizeof(__pyx_k_iou_thr), 0, 0, 1, 1},
  {&__pyx_n_s_iw, __pyx_k_iw, sizeof(__pyx_k_iw), 0, 0, 1, 1},
  {&__pyx_n_s_main, __pyx_k_main, sizeof(__pyx_k_main), 0, 0, 1, 1},
  {&__pyx_n_s_maxpos, __pyx_k_maxpos, sizeof(__pyx_k_maxpos), 0, 0, 1, 1},
  {&__pyx_n_s_maxscore, __pyx_k_maxscore, sizeof(__pyx_k_maxscore), 0, 0, 1, 1},
  {&__pyx_n_s_method, __pyx_k_method, sizeof(__pyx_k_method), 0, 0, 1, 1},
  {&__pyx_n_s_min_score, __pyx_k_min_score, sizeof(__pyx_k_min_score), 0, 0, 1, 1},
  {&__pyx_kp_s_mmmovie_detector_persondet_modul, __pyx_k_mmmovie_detector_persondet_modul, sizeof(__pyx_k_mmmovie_detector_persondet_modul), 0, 0, 1, 0},
  {&__pyx_n_s_mmmovie_detector_persondet_modul_2, __pyx_k_mmmovie_detector_persondet_modul_2, sizeof(__pyx_k_mmmovie_detector_persondet_modul_2), 0, 0, 1, 1},
  {&__pyx_n_s_name, __pyx_k_name, sizeof(__pyx_k_name), 0, 0, 1, 1},
  {&__pyx_kp_u_ndarray_is_not_C_contiguous, __pyx_k_ndarray_is_not_C_contiguous, sizeof(__pyx_k_ndarray_is_not_C_contiguous), 0, 1, 0, 0},
  {&__pyx_kp_u_ndarray_is_not_Fortran_contiguou, __pyx_k_ndarray_is_not_Fortran_contiguou, sizeof(__pyx_k_ndarray_is_not_Fortran_contiguou), 0, 1, 0, 0},
  {&__pyx_n_s_np, __pyx_k_np, sizeof(__pyx_k_np), 0, 0, 1, 1},
  {&__pyx_n_s_numpy, __pyx_k_numpy, sizeof(__pyx_k_numpy), 0, 0, 1, 1},
  {&__pyx_kp_u_numpy_core_multiarray_failed_to, __pyx_k_numpy_core_multiarray_failed_to, sizeof(__pyx_k_numpy_core_multiarray_failed_to), 0, 1, 0, 0},
  {&__pyx_kp_u_numpy_core_umath_failed_to_impor, __pyx_k_numpy_core_umath_failed_to_impor, sizeof(__pyx_k_numpy_core_umath_failed_to_impor), 0, 1, 0, 0},
  {&__pyx_n_s_ov, __pyx_k_ov, sizeof(__pyx_k_ov), 0, 0, 1, 1},
  {&__pyx_n_s_pos, __pyx_k_pos, sizeof(__pyx_k_pos), 0, 0, 1, 1},
  {&__pyx_n_s_range, __pyx_k_range, sizeof(__pyx_k_range), 0, 0, 1, 1},
  {&__pyx_n_s_s, __pyx_k_s, sizeof(__pyx_k_s), 0, 0, 1, 1},
  {&__pyx_n_s_shape, __pyx_k_shape, sizeof(__pyx_k_shape), 0, 0, 1, 1},
  {&__pyx_n_s_sigma, __pyx_k_sigma, sizeof(__pyx_k_sigma), 0, 0, 1, 1},
  {&__pyx_n_s_soft_nms_cpu, __pyx_k_soft_nms_cpu, sizeof(__pyx_k_soft_nms_cpu), 0, 0, 1, 1},
  {&__pyx_n_s_test, __pyx_k_test, sizeof(__pyx_k_test), 0, 0, 1, 1},
  {&__pyx_n_s_ti, __pyx_k_ti, sizeof(__pyx_k_ti), 0, 0, 1, 1},
  {&__pyx_n_s_ts, __pyx_k_ts, sizeof(__pyx_k_ts), 0, 0, 1, 1},
  {&__pyx_n_s_tx1, __pyx_k_tx1, sizeof(__pyx_k_tx1), 0, 0, 1, 1},
  {&__pyx_n_s_tx2, __pyx_k_tx2, sizeof(__pyx_k_tx2), 0, 0, 1, 1},
  {&__pyx_n_s_ty1, __pyx_k_ty1, sizeof(__pyx_k_ty1), 0, 0, 1, 1},
  {&__pyx_n_s_ty2, __pyx_k_ty2, sizeof(__pyx_k_ty2), 0, 0, 1, 1},
  {&__pyx_n_s_ua, __pyx_k_ua, sizeof(__pyx_k_ua), 0, 0, 1, 1},
  {&__pyx_kp_u_unknown_dtype_code_in_numpy_pxd, __pyx_k_unknown_dtype_code_in_numpy_pxd, sizeof(__pyx_k_unknown_dtype_code_in_numpy_pxd), 0, 1, 0, 0},
  {&__pyx_n_s_weight, __pyx_k_weight, sizeof(__pyx_k_weight), 0, 0, 1, 1},
  {&__pyx_n_s_x1, __pyx_k_x1, sizeof(__pyx_k_x1), 0, 0, 1, 1},
  {&__pyx_n_s_x2, __pyx_k_x2, sizeof(__pyx_k_x2), 0, 0, 1, 1},
  {&__pyx_n_s_y1, __pyx_k_y1, sizeof(__pyx_k_y1), 0, 0, 1, 1},
  {&__pyx_n_s_y2, __pyx_k_y2, sizeof(__pyx_k_y2), 0, 0, 1, 1},
  {0, 0, 0, 0, 0, 0, 0}
};
static CYTHON_SMALL_CODE int __Pyx_InitCachedBuiltins(void) {
  __pyx_builtin_range = __Pyx_GetBuiltinName(__pyx_n_s_range); if (!__pyx_builtin_range) __PYX_ERR(0, 39, __pyx_L1_error)
  __pyx_builtin_ValueError = __Pyx_GetBuiltinName(__pyx_n_s_ValueError); if (!__pyx_builtin_ValueError) __PYX_ERR(1, 272, __pyx_L1_error)
  __pyx_builtin_RuntimeError = __Pyx_GetBuiltinName(__pyx_n_s_RuntimeError); if (!__pyx_builtin_RuntimeError) __PYX_ERR(1, 855, __pyx_L1_error)
  __pyx_builtin_ImportError = __Pyx_GetBuiltinName(__pyx_n_s_ImportError); if (!__pyx_builtin_ImportError) __PYX_ERR(1, 1037, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitCachedConstants(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_InitCachedConstants", 0);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":272
 *             if ((flags & pybuf.PyBUF_C_CONTIGUOUS == pybuf.PyBUF_C_CONTIGUOUS)
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_C_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not C contiguous")             # <<<<<<<<<<<<<<
 *
 *             if ((flags & pybuf.PyBUF_F_CONTIGUOUS == pybuf.PyBUF_F_CONTIGUOUS)
 */
  __pyx_tuple_ = PyTuple_Pack(1, __pyx_kp_u_ndarray_is_not_C_contiguous); if (unlikely(!__pyx_tuple_)) __PYX_ERR(1, 272, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple_);
  __Pyx_GIVEREF(__pyx_tuple_);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":276
 *             if ((flags & pybuf.PyBUF_F_CONTIGUOUS == pybuf.PyBUF_F_CONTIGUOUS)
 *                 and not PyArray_CHKFLAGS(self, NPY_ARRAY_F_CONTIGUOUS)):
 *                 raise ValueError(u"ndarray is not Fortran contiguous")             # <<<<<<<<<<<<<<
 *
 *             info.buf = PyArray_DATA(self)
 */
  __pyx_tuple__2 = PyTuple_Pack(1, __pyx_kp_u_ndarray_is_not_Fortran_contiguou); if (unlikely(!__pyx_tuple__2)) __PYX_ERR(1, 276, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__2);
  __Pyx_GIVEREF(__pyx_tuple__2);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":306
 *                 if ((descr.byteorder == c'>' and little_endian) or
 *                     (descr.byteorder == c'<' and not little_endian)):
 *                     raise ValueError(u"Non-native byte order not supported")             # <<<<<<<<<<<<<<
 *                 if   t == NPY_BYTE:        f = "b"
 *                 elif t == NPY_UBYTE:       f = "B"
 */
  __pyx_tuple__3 = PyTuple_Pack(1, __pyx_kp_u_Non_native_byte_order_not_suppor); if (unlikely(!__pyx_tuple__3)) __PYX_ERR(1, 306, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__3);
  __Pyx_GIVEREF(__pyx_tuple__3);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":855
 *
 *         if (end - f) - <int>(new_offset - offset[0]) < 15:
 *             raise RuntimeError(u"Format string allocated too short, see comment in numpy.pxd")             # <<<<<<<<<<<<<<
 *
 *         if ((child.byteorder == c'>' and little_endian) or
 */
  __pyx_tuple__4 = PyTuple_Pack(1, __pyx_kp_u_Format_string_allocated_too_shor); if (unlikely(!__pyx_tuple__4)) __PYX_ERR(1, 855, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__4);
  __Pyx_GIVEREF(__pyx_tuple__4);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":879
 *             t = child.type_num
 *             if end - f < 5:
 *                 raise RuntimeError(u"Format string allocated too short.")             # <<<<<<<<<<<<<<
 *
 *             # Until ticket #99 is fixed, use integers to avoid warnings
 */
  __pyx_tuple__5 = PyTuple_Pack(1, __pyx_kp_u_Format_string_allocated_too_shor_2); if (unlikely(!__pyx_tuple__5)) __PYX_ERR(1, 879, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__5);
  __Pyx_GIVEREF(__pyx_tuple__5);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1037
 *         _import_array()
 *     except Exception:
 *         raise ImportError("numpy.core.multiarray failed to import")             # <<<<<<<<<<<<<<
 *
 * cdef inline int import_umath() except -1:
 */
  __pyx_tuple__6 = PyTuple_Pack(1, __pyx_kp_u_numpy_core_multiarray_failed_to); if (unlikely(!__pyx_tuple__6)) __PYX_ERR(1, 1037, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__6);
  __Pyx_GIVEREF(__pyx_tuple__6);

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1043
 *         _import_umath()
 *     except Exception:
 *         raise ImportError("numpy.core.umath failed to import")             # <<<<<<<<<<<<<<
 *
 * cdef inline int import_ufunc() except -1:
 */
  __pyx_tuple__7 = PyTuple_Pack(1, __pyx_kp_u_numpy_core_umath_failed_to_impor); if (unlikely(!__pyx_tuple__7)) __PYX_ERR(1, 1043, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__7);
  __Pyx_GIVEREF(__pyx_tuple__7);

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":22
 *
 *
 * def soft_nms_cpu(             # <<<<<<<<<<<<<<
 *     np.ndarray[float, ndim=2] boxes_in,
 *     float iou_thr,
 */
  __pyx_tuple__8 = PyTuple_Pack(30, __pyx_n_s_boxes_in, __pyx_n_s_iou_thr, __pyx_n_s_method, __pyx_n_s_sigma, __pyx_n_s_min_score, __pyx_n_s_boxes, __pyx_n_s_N, __pyx_n_s_iw, __pyx_n_s_ih, __pyx_n_s_box_area, __pyx_n_s_ua, __pyx_n_s_pos, __pyx_n_s_maxscore, __pyx_n_s_maxpos, __pyx_n_s_x1, __pyx_n_s_x2, __pyx_n_s_y1, __pyx_n_s_y2, __pyx_n_s_tx1, __pyx_n_s_tx2, __pyx_n_s_ty1, __pyx_n_s_ty2, __pyx_n_s_ts, __pyx_n_s_area, __pyx_n_s_weight, __pyx_n_s_ov, __pyx_n_s_inds, __pyx_n_s_i, __pyx_n_s_ti, __pyx_n_s_s); if (unlikely(!__pyx_tuple__8)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_tuple__8);
  __Pyx_GIVEREF(__pyx_tuple__8);
  __pyx_codeobj__9 = (PyObject*)__Pyx_PyCode_New(5, 0, 30, 0, CO_OPTIMIZED|CO_NEWLOCALS, __pyx_empty_bytes, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_tuple__8, __pyx_empty_tuple, __pyx_empty_tuple, __pyx_kp_s_mmmovie_detector_persondet_modul, __pyx_n_s_soft_nms_cpu, 22, __pyx_empty_bytes); if (unlikely(!__pyx_codeobj__9)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_RefNannyFinishContext();
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_InitGlobals(void) {
  if (__Pyx_InitStrings(__pyx_string_tab) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  __pyx_int_0 = PyInt_FromLong(0); if (unlikely(!__pyx_int_0)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_1 = PyInt_FromLong(1); if (unlikely(!__pyx_int_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_2 = PyInt_FromLong(2); if (unlikely(!__pyx_int_2)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_3 = PyInt_FromLong(3); if (unlikely(!__pyx_int_3)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_int_4 = PyInt_FromLong(4); if (unlikely(!__pyx_int_4)) __PYX_ERR(0, 1, __pyx_L1_error)
  return 0;
  __pyx_L1_error:;
  return -1;
}

static CYTHON_SMALL_CODE int __Pyx_modinit_global_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_export_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_init_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_type_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_variable_import_code(void); /*proto*/
static CYTHON_SMALL_CODE int __Pyx_modinit_function_import_code(void); /*proto*/

static int __Pyx_modinit_global_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_global_init_code", 0);
  /*--- Global init code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_variable_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_export_code", 0);
  /*--- Variable export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_export_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_export_code", 0);
  /*--- Function export code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_init_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_init_code", 0);
  /*--- Type init code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_type_import_code(void) {
  __Pyx_RefNannyDeclarations
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannySetupContext("__Pyx_modinit_type_import_code", 0);
  /*--- Type import code ---*/
  __pyx_t_1 = PyImport_ImportModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_t_1)) __PYX_ERR(2, 9, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_ptype_7cpython_4type_type = __Pyx_ImportType(__pyx_t_1, __Pyx_BUILTIN_MODULE_NAME, "type",
  #if defined(PYPY_VERSION_NUM) && PYPY_VERSION_NUM < 0x050B0000
  sizeof(PyTypeObject),
  #else
  sizeof(PyHeapTypeObject),
  #endif
  __Pyx_ImportType_CheckSize_Warn);
   if (!__pyx_ptype_7cpython_4type_type) __PYX_ERR(2, 9, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __pyx_t_1 = PyImport_ImportModule("numpy"); if (unlikely(!__pyx_t_1)) __PYX_ERR(1, 206, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  __pyx_ptype_5numpy_dtype = __Pyx_ImportType(__pyx_t_1, "numpy", "dtype", sizeof(PyArray_Descr), __Pyx_ImportType_CheckSize_Ignore);
   if (!__pyx_ptype_5numpy_dtype) __PYX_ERR(1, 206, __pyx_L1_error)
  __pyx_ptype_5numpy_flatiter = __Pyx_ImportType(__pyx_t_1, "numpy", "flatiter", sizeof(PyArrayIterObject), __Pyx_ImportType_CheckSize_Warn);
   if (!__pyx_ptype_5numpy_flatiter) __PYX_ERR(1, 229, __pyx_L1_error)
  __pyx_ptype_5numpy_broadcast = __Pyx_ImportType(__pyx_t_1, "numpy", "broadcast", sizeof(PyArrayMultiIterObject), __Pyx_ImportType_CheckSize_Warn);
   if (!__pyx_ptype_5numpy_broadcast) __PYX_ERR(1, 233, __pyx_L1_error)
  __pyx_ptype_5numpy_ndarray = __Pyx_ImportType(__pyx_t_1, "numpy", "ndarray", sizeof(PyArrayObject), __Pyx_ImportType_CheckSize_Ignore);
   if (!__pyx_ptype_5numpy_ndarray) __PYX_ERR(1, 242, __pyx_L1_error)
  __pyx_ptype_5numpy_ufunc = __Pyx_ImportType(__pyx_t_1, "numpy", "ufunc", sizeof(PyUFuncObject), __Pyx_ImportType_CheckSize_Warn);
   if (!__pyx_ptype_5numpy_ufunc) __PYX_ERR(1, 917, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;
  __Pyx_RefNannyFinishContext();
  return 0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  __Pyx_RefNannyFinishContext();
  return -1;
}

static int __Pyx_modinit_variable_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_variable_import_code", 0);
  /*--- Variable import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}

static int __Pyx_modinit_function_import_code(void) {
  __Pyx_RefNannyDeclarations
  __Pyx_RefNannySetupContext("__Pyx_modinit_function_import_code", 0);
  /*--- Function import code ---*/
  __Pyx_RefNannyFinishContext();
  return 0;
}


#ifndef CYTHON_NO_PYINIT_EXPORT
#define __Pyx_PyMODINIT_FUNC PyMODINIT_FUNC
#elif PY_MAJOR_VERSION < 3
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" void
#else
#define __Pyx_PyMODINIT_FUNC void
#endif
#else
#ifdef __cplusplus
#define __Pyx_PyMODINIT_FUNC extern "C" PyObject *
#else
#define __Pyx_PyMODINIT_FUNC PyObject *
#endif
#endif


#if PY_MAJOR_VERSION < 3
__Pyx_PyMODINIT_FUNC initsoft_nms_cpu(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC initsoft_nms_cpu(void)
#else
__Pyx_PyMODINIT_FUNC PyInit_soft_nms_cpu(void) CYTHON_SMALL_CODE; /*proto*/
__Pyx_PyMODINIT_FUNC PyInit_soft_nms_cpu(void)
#if CYTHON_PEP489_MULTI_PHASE_INIT
{
  return PyModuleDef_Init(&__pyx_moduledef);
}
static CYTHON_SMALL_CODE int __Pyx_check_single_interpreter(void) {
    #if PY_VERSION_HEX >= 0x030700A1
    static PY_INT64_T main_interpreter_id = -1;
    PY_INT64_T current_id = PyInterpreterState_GetID(PyThreadState_Get()->interp);
    if (main_interpreter_id == -1) {
        main_interpreter_id = current_id;
        return (unlikely(current_id == -1)) ? -1 : 0;
    } else if (unlikely(main_interpreter_id != current_id))
    #else
    static PyInterpreterState *main_interpreter = NULL;
    PyInterpreterState *current_interpreter = PyThreadState_Get()->interp;
    if (!main_interpreter) {
        main_interpreter = current_interpreter;
    } else if (unlikely(main_interpreter != current_interpreter))
    #endif
    {
        PyErr_SetString(
            PyExc_ImportError,
            "Interpreter change detected - this module can only be loaded into one interpreter per process.");
        return -1;
    }
    return 0;
}
static CYTHON_SMALL_CODE int __Pyx_copy_spec_to_module(PyObject *spec, PyObject *moddict, const char* from_name, const char* to_name, int allow_none) {
    PyObject *value = PyObject_GetAttrString(spec, from_name);
    int result = 0;
    if (likely(value)) {
        if (allow_none || value != Py_None) {
            result = PyDict_SetItemString(moddict, to_name, value);
        }
        Py_DECREF(value);
    } else if (PyErr_ExceptionMatches(PyExc_AttributeError)) {
        PyErr_Clear();
    } else {
        result = -1;
    }
    return result;
}
static CYTHON_SMALL_CODE PyObject* __pyx_pymod_create(PyObject *spec, CYTHON_UNUSED PyModuleDef *def) {
    PyObject *module = NULL, *moddict, *modname;
    if (__Pyx_check_single_interpreter())
        return NULL;
    if (__pyx_m)
        return __Pyx_NewRef(__pyx_m);
    modname = PyObject_GetAttrString(spec, "name");
    if (unlikely(!modname)) goto bad;
    module = PyModule_NewObject(modname);
    Py_DECREF(modname);
    if (unlikely(!module)) goto bad;
    moddict = PyModule_GetDict(module);
    if (unlikely(!moddict)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "loader", "__loader__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "origin", "__file__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "parent", "__package__", 1) < 0)) goto bad;
    if (unlikely(__Pyx_copy_spec_to_module(spec, moddict, "submodule_search_locations", "__path__", 0) < 0)) goto bad;
    return module;
bad:
    Py_XDECREF(module);
    return NULL;
}


static CYTHON_SMALL_CODE int __pyx_pymod_exec_soft_nms_cpu(PyObject *__pyx_pyinit_module)
#endif
#endif
{
  PyObject *__pyx_t_1 = NULL;
  int __pyx_lineno = 0;
  const char *__pyx_filename = NULL;
  int __pyx_clineno = 0;
  __Pyx_RefNannyDeclarations
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  if (__pyx_m) {
    if (__pyx_m == __pyx_pyinit_module) return 0;
    PyErr_SetString(PyExc_RuntimeError, "Module 'soft_nms_cpu' has already been imported. Re-initialisation is not supported.");
    return -1;
  }
  #elif PY_MAJOR_VERSION >= 3
  if (__pyx_m) return __Pyx_NewRef(__pyx_m);
  #endif
  #if CYTHON_REFNANNY
__Pyx_RefNanny = __Pyx_RefNannyImportAPI("refnanny");
if (!__Pyx_RefNanny) {
  PyErr_Clear();
  __Pyx_RefNanny = __Pyx_RefNannyImportAPI("Cython.Runtime.refnanny");
  if (!__Pyx_RefNanny)
      Py_FatalError("failed to import 'refnanny' module");
}
#endif
  __Pyx_RefNannySetupContext("__Pyx_PyMODINIT_FUNC PyInit_soft_nms_cpu(void)", 0);
  if (__Pyx_check_binary_version() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pxy_PyFrame_Initialize_Offsets
  __Pxy_PyFrame_Initialize_Offsets();
  #endif
  __pyx_empty_tuple = PyTuple_New(0); if (unlikely(!__pyx_empty_tuple)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_bytes = PyBytes_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_bytes)) __PYX_ERR(0, 1, __pyx_L1_error)
  __pyx_empty_unicode = PyUnicode_FromStringAndSize("", 0); if (unlikely(!__pyx_empty_unicode)) __PYX_ERR(0, 1, __pyx_L1_error)
  #ifdef __Pyx_CyFunction_USED
  if (__pyx_CyFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_FusedFunction_USED
  if (__pyx_FusedFunction_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Coroutine_USED
  if (__pyx_Coroutine_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_Generator_USED
  if (__pyx_Generator_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_AsyncGen_USED
  if (__pyx_AsyncGen_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  #ifdef __Pyx_StopAsyncIteration_USED
  if (__pyx_StopAsyncIteration_init() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  /*--- Library function declarations ---*/
  /*--- Threads initialization code ---*/
  #if defined(__PYX_FORCE_INIT_THREADS) && __PYX_FORCE_INIT_THREADS
  #ifdef WITH_THREAD /* Python build with threading support? */
  PyEval_InitThreads();
  #endif
  #endif
  /*--- Module creation code ---*/
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  __pyx_m = __pyx_pyinit_module;
  Py_INCREF(__pyx_m);
  #else
  #if PY_MAJOR_VERSION < 3
  __pyx_m = Py_InitModule4("soft_nms_cpu", __pyx_methods, 0, 0, PYTHON_API_VERSION); Py_XINCREF(__pyx_m);
  #else
  __pyx_m = PyModule_Create(&__pyx_moduledef);
  #endif
  if (unlikely(!__pyx_m)) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  __pyx_d = PyModule_GetDict(__pyx_m); if (unlikely(!__pyx_d)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_d);
  __pyx_b = PyImport_AddModule(__Pyx_BUILTIN_MODULE_NAME); if (unlikely(!__pyx_b)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_b);
  __pyx_cython_runtime = PyImport_AddModule((char *) "cython_runtime"); if (unlikely(!__pyx_cython_runtime)) __PYX_ERR(0, 1, __pyx_L1_error)
  Py_INCREF(__pyx_cython_runtime);
  if (PyObject_SetAttrString(__pyx_m, "__builtins__", __pyx_b) < 0) __PYX_ERR(0, 1, __pyx_L1_error);
  /*--- Initialize various global constants etc. ---*/
  if (__Pyx_InitGlobals() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #if PY_MAJOR_VERSION < 3 && (__PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT)
  if (__Pyx_init_sys_getdefaultencoding_params() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif
  if (__pyx_module_is_main_mmmovie__detector__persondet__modules__core__ops__nms__soft_nms_cpu) {
    if (PyObject_SetAttr(__pyx_m, __pyx_n_s_name, __pyx_n_s_main) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  }
  #if PY_MAJOR_VERSION >= 3
  {
    PyObject *modules = PyImport_GetModuleDict(); if (unlikely(!modules)) __PYX_ERR(0, 1, __pyx_L1_error)
    if (!PyDict_GetItemString(modules, "mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu")) {
      if (unlikely(PyDict_SetItemString(modules, "mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu", __pyx_m) < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
    }
  }
  #endif
  /*--- Builtin init code ---*/
  if (__Pyx_InitCachedBuiltins() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  /*--- Constants init code ---*/
  if (__Pyx_InitCachedConstants() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  /*--- Global type/function init code ---*/
  (void)__Pyx_modinit_global_init_code();
  (void)__Pyx_modinit_variable_export_code();
  (void)__Pyx_modinit_function_export_code();
  (void)__Pyx_modinit_type_init_code();
  if (unlikely(__Pyx_modinit_type_import_code() < 0)) __PYX_ERR(0, 1, __pyx_L1_error)
  (void)__Pyx_modinit_variable_import_code();
  (void)__Pyx_modinit_function_import_code();
  /*--- Execution code ---*/
  #if defined(__Pyx_Generator_USED) || defined(__Pyx_Coroutine_USED)
  if (__Pyx_patch_abc() < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  #endif

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":11
 * # cython: language_level=3, boundscheck=False
 *
 * import numpy as np             # <<<<<<<<<<<<<<
 * cimport numpy as np
 *
 */
  __pyx_t_1 = __Pyx_Import(__pyx_n_s_numpy, 0, 0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_np, __pyx_t_1) < 0) __PYX_ERR(0, 11, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":22
 *
 *
 * def soft_nms_cpu(             # <<<<<<<<<<<<<<
 *     np.ndarray[float, ndim=2] boxes_in,
 *     float iou_thr,
 */
  __pyx_t_1 = PyCFunction_NewEx(&__pyx_mdef_7mmmovie_8detector_9persondet_7modules_4core_3ops_3nms_12soft_nms_cpu_1soft_nms_cpu, NULL, __pyx_n_s_mmmovie_detector_persondet_modul_2); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_soft_nms_cpu, __pyx_t_1) < 0) __PYX_ERR(0, 22, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "mmmovie/detector/persondet/modules/core/ops/nms/src/soft_nms_cpu.pyx":1
 * # ----------------------------------------------------------             # <<<<<<<<<<<<<<
 * # Soft-NMS: Improving Object Detection With One Line of Code
 * # Copyright (c) University of Maryland, College Park
 */
  __pyx_t_1 = __Pyx_PyDict_NewPresized(0); if (unlikely(!__pyx_t_1)) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_GOTREF(__pyx_t_1);
  if (PyDict_SetItem(__pyx_d, __pyx_n_s_test, __pyx_t_1) < 0) __PYX_ERR(0, 1, __pyx_L1_error)
  __Pyx_DECREF(__pyx_t_1); __pyx_t_1 = 0;

  /* "../../anaconda3/envs/castcoref/lib/python3.7/site-packages/Cython/Includes/numpy/__init__.pxd":1045
 *         raise ImportError("numpy.core.umath failed to import")
 *
 * cdef inline int import_ufunc() except -1:             # <<<<<<<<<<<<<<
 *     try:
 *         _import_umath()
 */

  /*--- Wrapped vars code ---*/

  goto __pyx_L0;
  __pyx_L1_error:;
  __Pyx_XDECREF(__pyx_t_1);
  if (__pyx_m) {
    if (__pyx_d) {
      __Pyx_AddTraceback("init mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu", __pyx_clineno, __pyx_lineno, __pyx_filename);
    }
    Py_CLEAR(__pyx_m);
  } else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_ImportError, "init mmmovie.detector.persondet.modules.core.ops.nms.soft_nms_cpu");
  }
  __pyx_L0:;
  __Pyx_RefNannyFinishContext();
  #if CYTHON_PEP489_MULTI_PHASE_INIT
  return (__pyx_m != NULL) ? 0 : -1;
  #elif PY_MAJOR_VERSION >= 3
  return __pyx_m;
  #else
  return;
  #endif
}

/* --- Runtime support code --- */
/* Refnanny */
#if CYTHON_REFNANNY
static __Pyx_RefNannyAPIStruct *__Pyx_RefNannyImportAPI(const char *modname) {
    PyObject *m = NULL, *p = NULL;
    void *r = NULL;
    m = PyImport_ImportModule(modname);
    if (!m) goto end;
    p = PyObject_GetAttrString(m, "RefNannyAPI");
    if (!p) goto end;
    r = PyLong_AsVoidPtr(p);
end:
    Py_XDECREF(p);
    Py_XDECREF(m);
    return (__Pyx_RefNannyAPIStruct *)r;
}
#endif

/* PyObjectGetAttrStr */
#if CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PyObject* __Pyx_PyObject_GetAttrStr(PyObject* obj, PyObject* attr_name) {
    PyTypeObject* tp = Py_TYPE(obj);
    if (likely(tp->tp_getattro))
        return tp->tp_getattro(obj, attr_name);
#if PY_MAJOR_VERSION < 3
    if (likely(tp->tp_getattr))
        return tp->tp_getattr(obj, PyString_AS_STRING(attr_name));
#endif
    return PyObject_GetAttr(obj, attr_name);
}
#endif

/* GetBuiltinName */
static PyObject *__Pyx_GetBuiltinName(PyObject *name) {
    PyObject* result = __Pyx_PyObject_GetAttrStr(__pyx_b, name);
    if (unlikely(!result)) {
        PyErr_Format(PyExc_NameError,
#if PY_MAJOR_VERSION >= 3
            "name '%U' is not defined", name);
#else
            "name '%.200s' is not defined", PyString_AS_STRING(name));
#endif
    }
    return result;
}

/* RaiseArgTupleInvalid */
static void __Pyx_RaiseArgtupleInvalid(
    const char* func_name,
    int exact,
    Py_ssize_t num_min,
    Py_ssize_t num_max,
    Py_ssize_t num_found)
{
    Py_ssize_t num_expected;
    const char *more_or_less;
    if (num_found < num_min) {
        num_expected = num_min;
        more_or_less = "at least";
    } else {
        num_expected = num_max;
        more_or_less = "at most";
    }
    if (exact) {
        more_or_less = "exactly";
    }
    PyErr_Format(PyExc_TypeError,
                 "%.200s() takes %.8s %" CYTHON_FORMAT_SSIZE_T "d positional argument%.1s (%" CYTHON_FORMAT_SSIZE_T "d given)",
                 func_name, more_or_less, num_expected,
                 (num_expected == 1) ? "" : "s", num_found);
}

/* RaiseDoubleKeywords */
static void __Pyx_RaiseDoubleKeywordsError(
    const char* func_name,
    PyObject* kw_name)
{
    PyErr_Format(PyExc_TypeError,
        #if PY_MAJOR_VERSION >= 3
        "%s() got multiple values for keyword argument '%U'", func_name, kw_name);
        #else
        "%s() got multiple values for keyword argument '%s'", func_name,
        PyString_AsString(kw_name));
        #endif
}

/* ParseKeywords */
static int __Pyx_ParseOptionalKeywords(
    PyObject *kwds,
    PyObject **argnames[],
    PyObject *kwds2,
    PyObject *values[],
    Py_ssize_t num_pos_args,
    const char* function_name)
{
    PyObject *key = 0, *value = 0;
    Py_ssize_t pos = 0;
    PyObject*** name;
    PyObject*** first_kw_arg = argnames + num_pos_args;
    while (PyDict_Next(kwds, &pos, &key, &value)) {
        name = first_kw_arg;
        while (*name && (**name != key)) name++;
        if (*name) {
            values[name-argnames] = value;
            continue;
        }
        name = first_kw_arg;
        #if PY_MAJOR_VERSION < 3
        if (likely(PyString_Check(key))) {
            while (*name) {
                if ((CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**name) == PyString_GET_SIZE(key))
                        && _PyString_Eq(**name, key)) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    if ((**argname == key) || (
                            (CYTHON_COMPILING_IN_PYPY || PyString_GET_SIZE(**argname) == PyString_GET_SIZE(key))
                             && _PyString_Eq(**argname, key))) {
                        goto arg_passed_twice;
                    }
                    argname++;
                }
            }
        } else
        #endif
        if (likely(PyUnicode_Check(key))) {
            while (*name) {
                int cmp = (**name == key) ? 0 :
                #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                    (__Pyx_PyUnicode_GET_LENGTH(**name) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                #endif
                    PyUnicode_Compare(**name, key);
                if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                if (cmp == 0) {
                    values[name-argnames] = value;
                    break;
                }
                name++;
            }
            if (*name) continue;
            else {
                PyObject*** argname = argnames;
                while (argname != first_kw_arg) {
                    int cmp = (**argname == key) ? 0 :
                    #if !CYTHON_COMPILING_IN_PYPY && PY_MAJOR_VERSION >= 3
                        (__Pyx_PyUnicode_GET_LENGTH(**argname) != __Pyx_PyUnicode_GET_LENGTH(key)) ? 1 :
                    #endif
                        PyUnicode_Compare(**argname, key);
                    if (cmp < 0 && unlikely(PyErr_Occurred())) goto bad;
                    if (cmp == 0) goto arg_passed_twice;
                    argname++;
                }
            }
        } else
            goto invalid_keyword_type;
        if (kwds2) {
            if (unlikely(PyDict_SetItem(kwds2, key, value))) goto bad;
        } else {
            goto invalid_keyword;
        }
    }
    return 0;
arg_passed_twice:
    __Pyx_RaiseDoubleKeywordsError(function_name, key);
    goto bad;
invalid_keyword_type:
    PyErr_Format(PyExc_TypeError,
        "%.200s() keywords must be strings", function_name);
    goto bad;
invalid_keyword:
    PyErr_Format(PyExc_TypeError,
    #if PY_MAJOR_VERSION < 3
        "%.200s() got an unexpected keyword argument '%.200s'",
        function_name, PyString_AsString(key));
    #else
        "%s() got an unexpected keyword argument '%U'",
        function_name, key);
    #endif
bad:
    return -1;
}

/* ArgTypeTest */
static int __Pyx__ArgTypeTest(PyObject *obj, PyTypeObject *type, const char *name, int exact)
{
    if (unlikely(!type)) {
        PyErr_SetString(PyExc_SystemError, "Missing type object");
        return 0;
    }
    else if (exact) {
        #if PY_MAJOR_VERSION == 2
        if ((type == &PyBaseString_Type) && likely(__Pyx_PyBaseString_CheckExact(obj))) return 1;
        #endif
    }
    else {
        if (likely(__Pyx_TypeCheck(obj, type))) return 1;
    }
    PyErr_Format(PyExc_TypeError,
        "Argument '%.200s' has incorrect type (expected %.200s, got %.200s)",
        name, type->tp_name, Py_TYPE(obj)->tp_name);
    return 0;
}

/* IsLittleEndian */
static CYTHON_INLINE int __Pyx_Is_Little_Endian(void)
{
  union {
    uint32_t u32;
    uint8_t u8[4];
  } S;
  S.u32 = 0x01020304;
  return S.u8[0] == 4;
}

/* BufferFormatCheck */
static void __Pyx_BufFmt_Init(__Pyx_BufFmt_Context* ctx,
                              __Pyx_BufFmt_StackElem* stack,
                              __Pyx_TypeInfo* type) {
  stack[0].field = &ctx->root;
  stack[0].parent_offset = 0;
  ctx->root.type = type;
  ctx->root.name = "buffer dtype";
  ctx->root.offset = 0;
  ctx->head = stack;
  ctx->head->field = &ctx->root;
  ctx->fmt_offset = 0;
  ctx->head->parent_offset = 0;
  ctx->new_packmode = '@';
  ctx->enc_packmode = '@';
  ctx->new_count = 1;
  ctx->enc_count = 0;
  ctx->enc_type = 0;
  ctx->is_complex = 0;
  ctx->is_valid_array = 0;
  ctx->struct_alignment = 0;
  while (type->typegroup == 'S') {
    ++ctx->head;
    ctx->head->field = type->fields;
    ctx->head->parent_offset = 0;
    type = type->fields->type;
  }
}
static int __Pyx_BufFmt_ParseNumber(const char** ts) {
    int count;
    const char* t = *ts;
    if (*t < '0' || *t > '9') {
      return -1;
    } else {
        count = *t++ - '0';
        while (*t >= '0' && *t <= '9') {
            count *= 10;
            count += *t++ - '0';
        }
    }
    *ts = t;
    return count;
}
static int __Pyx_BufFmt_ExpectNumber(const char **ts) {
    int number = __Pyx_BufFmt_ParseNumber(ts);
    if (number == -1)
        PyErr_Format(PyExc_ValueError,\
                     "Does not understand character buffer dtype format string ('%c')", **ts);
    return number;
}
static void __Pyx_BufFmt_RaiseUnexpectedChar(char ch) {
  PyErr_Format(PyExc_ValueError,
               "Unexpected format string character: '%c'", ch);
}
static const char* __Pyx_BufFmt_DescribeTypeChar(char ch, int is_complex) {
  switch (ch) {
    case '?': return "'bool'";
    case 'c': return "'char'";
    case 'b': return "'signed char'";
    case 'B': return "'unsigned char'";
    case 'h': return "'short'";
    case 'H': return "'unsigned short'";
    case 'i': return "'int'";
    case 'I': return "'unsigned int'";
    case 'l': return "'long'";
    case 'L': return "'unsigned long'";
    case 'q': return "'long long'";
    case 'Q': return "'unsigned long long'";
    case 'f': return (is_complex ? "'complex float'" : "'float'");
    case 'd': return (is_complex ? "'complex double'" : "'double'");
    case 'g': return (is_complex ? "'complex long double'" : "'long double'");
    case 'T': return "a struct";
    case 'O': return "Python object";
    case 'P': return "a pointer";
    case 's': case 'p': return "a string";
    case 0: return "end";
    default: return "unparseable format string";
  }
}
static size_t __Pyx_BufFmt_TypeCharToStandardSize(char ch, int is_complex) {
  switch (ch) {
    case '?': case 'c': case 'b': case 'B': case 's': case 'p': return 1;
    case 'h': case 'H': return 2;
    case 'i': case 'I': case 'l': case 'L': return 4;
    case 'q': case 'Q': return 8;
    case 'f': return (is_complex ? 8 : 4);
    case 'd': return (is_complex ? 16 : 8);
    case 'g': {
      PyErr_SetString(PyExc_ValueError, "Python does not define a standard format string size for long double ('g')..");
      return 0;
    }
    case 'O': case 'P': return sizeof(void*);
    default:
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
}
static size_t __Pyx_BufFmt_TypeCharToNativeSize(char ch, int is_complex) {
  switch (ch) {
    case '?': case 'c': case 'b': case 'B': case 's': case 'p': return 1;
    case 'h': case 'H': return sizeof(short);
    case 'i': case 'I': return sizeof(int);
    case 'l': case 'L': return sizeof(long);
    #ifdef HAVE_LONG_LONG
    case 'q': case 'Q': return sizeof(PY_LONG_LONG);
    #endif
    case 'f': return sizeof(float) * (is_complex ? 2 : 1);
    case 'd': return sizeof(double) * (is_complex ? 2 : 1);
    case 'g': return sizeof(long double) * (is_complex ? 2 : 1);
    case 'O': case 'P': return sizeof(void*);
    default: {
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
  }
}
typedef struct { char c; short x; } __Pyx_st_short;
typedef struct { char c; int x; } __Pyx_st_int;
typedef struct { char c; long x; } __Pyx_st_long;
typedef struct { char c; float x; } __Pyx_st_float;
typedef struct { char c; double x; } __Pyx_st_double;
typedef struct { char c; long double x; } __Pyx_st_longdouble;
typedef struct { char c; void *x; } __Pyx_st_void_p;
#ifdef HAVE_LONG_LONG
typedef struct { char c; PY_LONG_LONG x; } __Pyx_st_longlong;
#endif
static size_t __Pyx_BufFmt_TypeCharToAlignment(char ch, CYTHON_UNUSED int is_complex) {
  switch (ch) {
    case '?': case 'c': case 'b': case 'B': case 's': case 'p': return 1;
    case 'h': case 'H': return sizeof(__Pyx_st_short) - sizeof(short);
    case 'i': case 'I': return sizeof(__Pyx_st_int) - sizeof(int);
    case 'l': case 'L': return sizeof(__Pyx_st_long) - sizeof(long);
#ifdef HAVE_LONG_LONG
    case 'q': case 'Q': return sizeof(__Pyx_st_longlong) - sizeof(PY_LONG_LONG);
#endif
    case 'f': return sizeof(__Pyx_st_float) - sizeof(float);
    case 'd': return sizeof(__Pyx_st_double) - sizeof(double);
    case 'g': return sizeof(__Pyx_st_longdouble) - sizeof(long double);
    case 'P': case 'O': return sizeof(__Pyx_st_void_p) - sizeof(void*);
    default:
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
}
/* These are for computing the padding at the end of the struct to align
   on the first member of the struct. This will probably the same as above,
   but we don't have any guarantees.
 */
typedef struct { short x; char c; } __Pyx_pad_short;
typedef struct { int x; char c; } __Pyx_pad_int;
typedef struct { long x; char c; } __Pyx_pad_long;
typedef struct { float x; char c; } __Pyx_pad_float;
typedef struct { double x; char c; } __Pyx_pad_double;
typedef struct { long double x; char c; } __Pyx_pad_longdouble;
typedef struct { void *x; char c; } __Pyx_pad_void_p;
#ifdef HAVE_LONG_LONG
typedef struct { PY_LONG_LONG x; char c; } __Pyx_pad_longlong;
#endif
static size_t __Pyx_BufFmt_TypeCharToPadding(char ch, CYTHON_UNUSED int is_complex) {
  switch (ch) {
    case '?': case 'c': case 'b': case 'B': case 's': case 'p': return 1;
    case 'h': case 'H': return sizeof(__Pyx_pad_short) - sizeof(short);
    case 'i': case 'I': return sizeof(__Pyx_pad_int) - sizeof(int);
    case 'l': case 'L': return sizeof(__Pyx_pad_long) - sizeof(long);
#ifdef HAVE_LONG_LONG
    case 'q': case 'Q': return sizeof(__Pyx_pad_longlong) - sizeof(PY_LONG_LONG);
#endif
    case 'f': return sizeof(__Pyx_pad_float) - sizeof(float);
    case 'd': return sizeof(__Pyx_pad_double) - sizeof(double);
    case 'g': return sizeof(__Pyx_pad_longdouble) - sizeof(long double);
    case 'P': case 'O': return sizeof(__Pyx_pad_void_p) - sizeof(void*);
    default:
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
}
static char __Pyx_BufFmt_TypeCharToGroup(char ch, int is_complex) {
  switch (ch) {
    case 'c':
        return 'H';
    case 'b': case 'h': case 'i':
    case 'l': case 'q': case 's': case 'p':
        return 'I';
    case '?': case 'B': case 'H': case 'I': case 'L': case 'Q':
        return 'U';
    case 'f': case 'd': case 'g':
        return (is_complex ? 'C' : 'R');
    case 'O':
        return 'O';
    case 'P':
        return 'P';
    default: {
      __Pyx_BufFmt_RaiseUnexpectedChar(ch);
      return 0;
    }
  }
}
static void __Pyx_BufFmt_RaiseExpected(__Pyx_BufFmt_Context* ctx) {
  if (ctx->head == NULL || ctx->head->field == &ctx->root) {
    const char* expected;
    const char* quote;
    if (ctx->head == NULL) {
      expected = "end";
      quote = "";
    } else {
      expected = ctx->head->field->type->name;
      quote = "'";
    }
    PyErr_Format(PyExc_ValueError,
                 "Buffer dtype mismatch, expected %s%s%s but got %s",
                 quote, expected, quote,
                 __Pyx_BufFmt_DescribeTypeChar(ctx->enc_type, ctx->is_complex));
  } else {
    __Pyx_StructField* field = ctx->head->field;
    __Pyx_StructField* parent = (ctx->head - 1)->field;
    PyErr_Format(PyExc_ValueError,
                 "Buffer dtype mismatch, expected '%s' but got %s in '%s.%s'",
                 field->type->name, __Pyx_BufFmt_DescribeTypeChar(ctx->enc_type, ctx->is_complex),
                 parent->type->name, field->name);
  }
}
static int __Pyx_BufFmt_ProcessTypeChunk(__Pyx_BufFmt_Context* ctx) {
  char group;
  size_t size, offset, arraysize = 1;
  if (ctx->enc_type == 0) return 0;
  if (ctx->head->field->type->arraysize[0]) {
    int i, ndim = 0;
    if (ctx->enc_type == 's' || ctx->enc_type == 'p') {
        ctx->is_valid_array = ctx->head->field->type->ndim == 1;
        ndim = 1;
        if (ctx->enc_count != ctx->head->field->type->arraysize[0]) {
            PyErr_Format(PyExc_ValueError,
                         "Expected a dimension of size %zu, got %zu",
                         ctx->head->field->type->arraysize[0], ctx->enc_count);
            return -1;
        }
    }
    if (!ctx->is_valid_array) {
      PyErr_Format(PyExc_ValueError, "Expected %d dimensions, got %d",
                   ctx->head->field->type->ndim, ndim);
      return -1;
    }
    for (i = 0; i < ctx->head->field->type->ndim; i++) {
      arraysize *= ctx->head->field->type->arraysize[i];
    }
    ctx->is_valid_array = 0;
    ctx->enc_count = 1;
  }
  group = __Pyx_BufFmt_TypeCharToGroup(ctx->enc_type, ctx->is_complex);
  do {
    __Pyx_StructField* field = ctx->head->field;
    __Pyx_TypeInfo* type = field->type;
    if (ctx->enc_packmode == '@' || ctx->enc_packmode == '^') {
      size = __Pyx_BufFmt_TypeCharToNativeSize(ctx->enc_type, ctx->is_complex);
    } else {
      size = __Pyx_BufFmt_TypeCharToStandardSize(ctx->enc_type, ctx->is_complex);
    }
    if (ctx->enc_packmode == '@') {
      size_t align_at = __Pyx_BufFmt_TypeCharToAlignment(ctx->enc_type, ctx->is_complex);
      size_t align_mod_offset;
      if (align_at == 0) return -1;
      align_mod_offset = ctx->fmt_offset % align_at;
      if (align_mod_offset > 0) ctx->fmt_offset += align_at - align_mod_offset;
      if (ctx->struct_alignment == 0)
          ctx->struct_alignment = __Pyx_BufFmt_TypeCharToPadding(ctx->enc_type,
                                                                 ctx->is_complex);
    }
    if (type->size != size || type->typegroup != group) {
      if (type->typegroup == 'C' && type->fields != NULL) {
        size_t parent_offset = ctx->head->parent_offset + field->offset;
        ++ctx->head;
        ctx->head->field = type->fields;
        ctx->head->parent_offset = parent_offset;
        continue;
      }
      if ((type->typegroup == 'H' || group == 'H') && type->size == size) {
      } else {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return -1;
      }
    }
    offset = ctx->head->parent_offset + field->offset;
    if (ctx->fmt_offset != offset) {
      PyErr_Format(PyExc_ValueError,
                   "Buffer dtype mismatch; next field is at offset %" CYTHON_FORMAT_SSIZE_T "d but %" CYTHON_FORMAT_SSIZE_T "d expected",
                   (Py_ssize_t)ctx->fmt_offset, (Py_ssize_t)offset);
      return -1;
    }
    ctx->fmt_offset += size;
    if (arraysize)
      ctx->fmt_offset += (arraysize - 1) * size;
    --ctx->enc_count;
    while (1) {
      if (field == &ctx->root) {
        ctx->head = NULL;
        if (ctx->enc_count != 0) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return -1;
        }
        break;
      }
      ctx->head->field = ++field;
      if (field->type == NULL) {
        --ctx->head;
        field = ctx->head->field;
        continue;
      } else if (field->type->typegroup == 'S') {
        size_t parent_offset = ctx->head->parent_offset + field->offset;
        if (field->type->fields->type == NULL) continue;
        field = field->type->fields;
        ++ctx->head;
        ctx->head->field = field;
        ctx->head->parent_offset = parent_offset;
        break;
      } else {
        break;
      }
    }
  } while (ctx->enc_count);
  ctx->enc_type = 0;
  ctx->is_complex = 0;
  return 0;
}
static PyObject *
__pyx_buffmt_parse_array(__Pyx_BufFmt_Context* ctx, const char** tsp)
{
    const char *ts = *tsp;
    int i = 0, number, ndim;
    ++ts;
    if (ctx->new_count != 1) {
        PyErr_SetString(PyExc_ValueError,
                        "Cannot handle repeated arrays in format string");
        return NULL;
    }
    if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
    ndim = ctx->head->field->type->ndim;
    while (*ts && *ts != ')') {
        switch (*ts) {
            case ' ': case '\f': case '\r': case '\n': case '\t': case '\v':  continue;
            default:  break;
        }
        number = __Pyx_BufFmt_ExpectNumber(&ts);
        if (number == -1) return NULL;
        if (i < ndim && (size_t) number != ctx->head->field->type->arraysize[i])
            return PyErr_Format(PyExc_ValueError,
                        "Expected a dimension of size %zu, got %d",
                        ctx->head->field->type->arraysize[i], number);
        if (*ts != ',' && *ts != ')')
            return PyErr_Format(PyExc_ValueError,
                                "Expected a comma in format string, got '%c'", *ts);
        if (*ts == ',') ts++;
        i++;
    }
    if (i != ndim)
        return PyErr_Format(PyExc_ValueError, "Expected %d dimension(s), got %d",
                            ctx->head->field->type->ndim, i);
    if (!*ts) {
        PyErr_SetString(PyExc_ValueError,
                        "Unexpected end of format string, expected ')'");
        return NULL;
    }
    ctx->is_valid_array = 1;
    ctx->new_count = 1;
    *tsp = ++ts;
    return Py_None;
}
static const char* __Pyx_BufFmt_CheckString(__Pyx_BufFmt_Context* ctx, const char* ts) {
  int got_Z = 0;
  while (1) {
    switch(*ts) {
      case 0:
        if (ctx->enc_type != 0 && ctx->head == NULL) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return NULL;
        }
        if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
        if (ctx->head != NULL) {
          __Pyx_BufFmt_RaiseExpected(ctx);
          return NULL;
        }
        return ts;
      case ' ':
      case '\r':
      case '\n':
        ++ts;
        break;
      case '<':
        if (!__Pyx_Is_Little_Endian()) {
          PyErr_SetString(PyExc_ValueError, "Little-endian buffer not supported on big-endian compiler");
          return NULL;
        }
        ctx->new_packmode = '=';
        ++ts;
        break;
      case '>':
      case '!':
        if (__Pyx_Is_Little_Endian()) {
          PyErr_SetString(PyExc_ValueError, "Big-endian buffer not supported on little-endian compiler");
          return NULL;
        }
        ctx->new_packmode = '=';
        ++ts;
        break;
      case '=':
      case '@':
      case '^':
        ctx->new_packmode = *ts++;
        break;
      case 'T':
        {
          const char* ts_after_sub;
          size_t i, struct_count = ctx->new_count;
          size_t struct_alignment = ctx->struct_alignment;
          ctx->new_count = 1;
          ++ts;
          if (*ts != '{') {
            PyErr_SetString(PyExc_ValueError, "Buffer acquisition: Expected '{' after 'T'");
            return NULL;
          }
          if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
          ctx->enc_type = 0;
          ctx->enc_count = 0;
          ctx->struct_alignment = 0;
          ++ts;
          ts_after_sub = ts;
          for (i = 0; i != struct_count; ++i) {
            ts_after_sub = __Pyx_BufFmt_CheckString(ctx, ts);
            if (!ts_after_sub) return NULL;
          }
          ts = ts_after_sub;
          if (struct_alignment) ctx->struct_alignment = struct_alignment;
        }
        break;
      case '}':
        {
          size_t alignment = ctx->struct_alignment;
          ++ts;
          if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
          ctx->enc_type = 0;
          if (alignment && ctx->fmt_offset % alignment) {
            ctx->fmt_offset += alignment - (ctx->fmt_offset % alignment);
          }
        }
        return ts;
      case 'x':
        if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
        ctx->fmt_offset += ctx->new_count;
        ctx->new_count = 1;
        ctx->enc_count = 0;
        ctx->enc_type = 0;
        ctx->enc_packmode = ctx->new_packmode;
        ++ts;
        break;
      case 'Z':
        got_Z = 1;
        ++ts;
        if (*ts != 'f' && *ts != 'd' && *ts != 'g') {
          __Pyx_BufFmt_RaiseUnexpectedChar('Z');
          return NULL;
        }
        CYTHON_FALLTHROUGH;
      case '?': case 'c': case 'b': case 'B': case 'h': case 'H': case 'i': case 'I':
      case 'l': case 'L': case 'q': case 'Q':
      case 'f': case 'd': case 'g':
      case 'O': case 'p':
        if ((ctx->enc_type == *ts) && (got_Z == ctx->is_complex) &&
            (ctx->enc_packmode == ctx->new_packmode) && (!ctx->is_valid_array)) {
          ctx->enc_count += ctx->new_count;
          ctx->new_count = 1;
          got_Z = 0;
          ++ts;
          break;
        }
        CYTHON_FALLTHROUGH;
      case 's':
        if (__Pyx_BufFmt_ProcessTypeChunk(ctx) == -1) return NULL;
        ctx->enc_count = ctx->new_count;
        ctx->enc_packmode = ctx->new_packmode;
        ctx->enc_type = *ts;
        ctx->is_complex = got_Z;
        ++ts;
        ctx->new_count = 1;
        got_Z = 0;
        break;
      case ':':
        ++ts;
        while(*ts != ':') ++ts;
        ++ts;
        break;
      case '(':
        if (!__pyx_buffmt_parse_array(ctx, &ts)) return NULL;
        break;
      default:
        {
          int number = __Pyx_BufFmt_ExpectNumber(&ts);
          if (number == -1) return NULL;
          ctx->new_count = (size_t)number;
        }
    }
  }
}

/* BufferGetAndValidate */
  static CYTHON_INLINE void __Pyx_SafeReleaseBuffer(Py_buffer* info) {
  if (unlikely(info->buf == NULL)) return;
  if (info->suboffsets == __Pyx_minusones) info->suboffsets = NULL;
  __Pyx_ReleaseBuffer(info);
}
static void __Pyx_ZeroBuffer(Py_buffer* buf) {
  buf->buf = NULL;
  buf->obj = NULL;
  buf->strides = __Pyx_zeros;
  buf->shape = __Pyx_zeros;
  buf->suboffsets = __Pyx_minusones;
}
static int __Pyx__GetBufferAndValidate(
        Py_buffer* buf, PyObject* obj,  __Pyx_TypeInfo* dtype, int flags,
        int nd, int cast, __Pyx_BufFmt_StackElem* stack)
{
  buf->buf = NULL;
  if (unlikely(__Pyx_GetBuffer(obj, buf, flags) == -1)) {
    __Pyx_ZeroBuffer(buf);
    return -1;
  }
  if (unlikely(buf->ndim != nd)) {
    PyErr_Format(PyExc_ValueError,
                 "Buffer has wrong number of dimensions (expected %d, got %d)",
                 nd, buf->ndim);
    goto fail;
  }
  if (!cast) {
    __Pyx_BufFmt_Context ctx;
    __Pyx_BufFmt_Init(&ctx, stack, dtype);
    if (!__Pyx_BufFmt_CheckString(&ctx, buf->format)) goto fail;
  }
  if (unlikely((size_t)buf->itemsize != dtype->size)) {
    PyErr_Format(PyExc_ValueError,
      "Item size of buffer (%" CYTHON_FORMAT_SSIZE_T "d byte%s) does not match size of '%s' (%" CYTHON_FORMAT_SSIZE_T "d byte%s)",
      buf->itemsize, (buf->itemsize > 1) ? "s" : "",
      dtype->name, (Py_ssize_t)dtype->size, (dtype->size > 1) ? "s" : "");
    goto fail;
  }
  if (buf->suboffsets == NULL) buf->suboffsets = __Pyx_minusones;
  return 0;
fail:;
  __Pyx_SafeReleaseBuffer(buf);
  return -1;
}

/* PyFunctionFastCall */
  #if CYTHON_FAST_PYCALL
static PyObject* __Pyx_PyFunction_FastCallNoKw(PyCodeObject *co, PyObject **args, Py_ssize_t na,
                                               PyObject *globals) {
    PyFrameObject *f;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    PyObject **fastlocals;
    Py_ssize_t i;
    PyObject *result;
    assert(globals != NULL);
    /* XXX Perhaps we should create a specialized
       PyFrame_New() that doesn't take locals, but does
       take builtins without sanity checking them.
       */
    assert(tstate != NULL);
    f = PyFrame_New(tstate, co, globals, NULL);
    if (f == NULL) {
        return NULL;
    }
    fastlocals = __Pyx_PyFrame_GetLocalsplus(f);
    for (i = 0; i < na; i++) {
        Py_INCREF(*args);
        fastlocals[i] = *args++;
    }
    result = PyEval_EvalFrameEx(f,0);
    ++tstate->recursion_depth;
    Py_DECREF(f);
    --tstate->recursion_depth;
    return result;
}
#if 1 || PY_VERSION_HEX < 0x030600B1
static PyObject *__Pyx_PyFunction_FastCallDict(PyObject *func, PyObject **args, Py_ssize_t nargs, PyObject *kwargs) {
    PyCodeObject *co = (PyCodeObject *)PyFunction_GET_CODE(func);
    PyObject *globals = PyFunction_GET_GLOBALS(func);
    PyObject *argdefs = PyFunction_GET_DEFAULTS(func);
    PyObject *closure;
#if PY_MAJOR_VERSION >= 3
    PyObject *kwdefs;
#endif
    PyObject *kwtuple, **k;
    PyObject **d;
    Py_ssize_t nd;
    Py_ssize_t nk;
    PyObject *result;
    assert(kwargs == NULL || PyDict_Check(kwargs));
    nk = kwargs ? PyDict_Size(kwargs) : 0;
    if (Py_EnterRecursiveCall((char*)" while calling a Python object")) {
        return NULL;
    }
    if (
#if PY_MAJOR_VERSION >= 3
            co->co_kwonlyargcount == 0 &&
#endif
            likely(kwargs == NULL || nk == 0) &&
            co->co_flags == (CO_OPTIMIZED | CO_NEWLOCALS | CO_NOFREE)) {
        if (argdefs == NULL && co->co_argcount == nargs) {
            result = __Pyx_PyFunction_FastCallNoKw(co, args, nargs, globals);
            goto done;
        }
        else if (nargs == 0 && argdefs != NULL
                 && co->co_argcount == Py_SIZE(argdefs)) {
            /* function called with no arguments, but all parameters have
               a default value: use default values as arguments .*/
            args = &PyTuple_GET_ITEM(argdefs, 0);
            result =__Pyx_PyFunction_FastCallNoKw(co, args, Py_SIZE(argdefs), globals);
            goto done;
        }
    }
    if (kwargs != NULL) {
        Py_ssize_t pos, i;
        kwtuple = PyTuple_New(2 * nk);
        if (kwtuple == NULL) {
            result = NULL;
            goto done;
        }
        k = &PyTuple_GET_ITEM(kwtuple, 0);
        pos = i = 0;
        while (PyDict_Next(kwargs, &pos, &k[i], &k[i+1])) {
            Py_INCREF(k[i]);
            Py_INCREF(k[i+1]);
            i += 2;
        }
        nk = i / 2;
    }
    else {
        kwtuple = NULL;
        k = NULL;
    }
    closure = PyFunction_GET_CLOSURE(func);
#if PY_MAJOR_VERSION >= 3
    kwdefs = PyFunction_GET_KW_DEFAULTS(func);
#endif
    if (argdefs != NULL) {
        d = &PyTuple_GET_ITEM(argdefs, 0);
        nd = Py_SIZE(argdefs);
    }
    else {
        d = NULL;
        nd = 0;
    }
#if PY_MAJOR_VERSION >= 3
    result = PyEval_EvalCodeEx((PyObject*)co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, kwdefs, closure);
#else
    result = PyEval_EvalCodeEx(co, globals, (PyObject *)NULL,
                               args, (int)nargs,
                               k, (int)nk,
                               d, (int)nd, closure);
#endif
    Py_XDECREF(kwtuple);
done:
    Py_LeaveRecursiveCall();
    return result;
}
#endif
#endif

/* PyObjectCall */
  #if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_Call(PyObject *func, PyObject *arg, PyObject *kw) {
    PyObject *result;
    ternaryfunc call = func->ob_type->tp_call;
    if (unlikely(!call))
        return PyObject_Call(func, arg, kw);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = (*call)(func, arg, kw);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCallMethO */
  #if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallMethO(PyObject *func, PyObject *arg) {
    PyObject *self, *result;
    PyCFunction cfunc;
    cfunc = PyCFunction_GET_FUNCTION(func);
    self = PyCFunction_GET_SELF(func);
    if (unlikely(Py_EnterRecursiveCall((char*)" while calling a Python object")))
        return NULL;
    result = cfunc(self, arg);
    Py_LeaveRecursiveCall();
    if (unlikely(!result) && unlikely(!PyErr_Occurred())) {
        PyErr_SetString(
            PyExc_SystemError,
            "NULL result without error in PyObject_Call");
    }
    return result;
}
#endif

/* PyObjectCallNoArg */
  #if CYTHON_COMPILING_IN_CPYTHON
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallNoArg(PyObject *func) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, NULL, 0);
    }
#endif
#ifdef __Pyx_CyFunction_USED
    if (likely(PyCFunction_Check(func) || __Pyx_CyFunction_Check(func)))
#else
    if (likely(PyCFunction_Check(func)))
#endif
    {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_NOARGS)) {
            return __Pyx_PyObject_CallMethO(func, NULL);
        }
    }
    return __Pyx_PyObject_Call(func, __pyx_empty_tuple, NULL);
}
#endif

/* PyCFunctionFastCall */
  #if CYTHON_FAST_PYCCALL
static CYTHON_INLINE PyObject * __Pyx_PyCFunction_FastCall(PyObject *func_obj, PyObject **args, Py_ssize_t nargs) {
    PyCFunctionObject *func = (PyCFunctionObject*)func_obj;
    PyCFunction meth = PyCFunction_GET_FUNCTION(func);
    PyObject *self = PyCFunction_GET_SELF(func);
    int flags = PyCFunction_GET_FLAGS(func);
    assert(PyCFunction_Check(func));
    assert(METH_FASTCALL == (flags & ~(METH_CLASS | METH_STATIC | METH_COEXIST | METH_KEYWORDS | METH_STACKLESS)));
    assert(nargs >= 0);
    assert(nargs == 0 || args != NULL);
    /* _PyCFunction_FastCallDict() must not be called with an exception set,
       because it may clear it (directly or indirectly) and so the
       caller loses its exception */
    assert(!PyErr_Occurred());
    if ((PY_VERSION_HEX < 0x030700A0) || unlikely(flags & METH_KEYWORDS)) {
        return (*((__Pyx_PyCFunctionFastWithKeywords)(void*)meth)) (self, args, nargs, NULL);
    } else {
        return (*((__Pyx_PyCFunctionFast)(void*)meth)) (self, args, nargs);
    }
}
#endif

/* PyObjectCallOneArg */
  #if CYTHON_COMPILING_IN_CPYTHON
static PyObject* __Pyx__PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_New(1);
    if (unlikely(!args)) return NULL;
    Py_INCREF(arg);
    PyTuple_SET_ITEM(args, 0, arg);
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
#if CYTHON_FAST_PYCALL
    if (PyFunction_Check(func)) {
        return __Pyx_PyFunction_FastCall(func, &arg, 1);
    }
#endif
    if (likely(PyCFunction_Check(func))) {
        if (likely(PyCFunction_GET_FLAGS(func) & METH_O)) {
            return __Pyx_PyObject_CallMethO(func, arg);
#if CYTHON_FAST_PYCCALL
        } else if (PyCFunction_GET_FLAGS(func) & METH_FASTCALL) {
            return __Pyx_PyCFunction_FastCall(func, &arg, 1);
#endif
        }
    }
    return __Pyx__PyObject_CallOneArg(func, arg);
}
#else
static CYTHON_INLINE PyObject* __Pyx_PyObject_CallOneArg(PyObject *func, PyObject *arg) {
    PyObject *result;
    PyObject *args = PyTuple_Pack(1, arg);
    if (unlikely(!args)) return NULL;
    result = __Pyx_PyObject_Call(func, args, NULL);
    Py_DECREF(args);
    return result;
}
#endif

/* GetItemInt */
  static PyObject *__Pyx_GetItemInt_Generic(PyObject *o, PyObject* j) {
    PyObject *r;
    if (!j) return NULL;
    r = PyObject_GetItem(o, j);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_List_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyList_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyList_GET_SIZE(o)))) {
        PyObject *r = PyList_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Tuple_Fast(PyObject *o, Py_ssize_t i,
                                                              CYTHON_NCP_UNUSED int wraparound,
                                                              CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS
    Py_ssize_t wrapped_i = i;
    if (wraparound & unlikely(i < 0)) {
        wrapped_i += PyTuple_GET_SIZE(o);
    }
    if ((!boundscheck) || likely(__Pyx_is_valid_index(wrapped_i, PyTuple_GET_SIZE(o)))) {
        PyObject *r = PyTuple_GET_ITEM(o, wrapped_i);
        Py_INCREF(r);
        return r;
    }
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
#else
    return PySequence_GetItem(o, i);
#endif
}
static CYTHON_INLINE PyObject *__Pyx_GetItemInt_Fast(PyObject *o, Py_ssize_t i, int is_list,
                                                     CYTHON_NCP_UNUSED int wraparound,
                                                     CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyList_GET_SIZE(o);
        if ((!boundscheck) || (likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o))))) {
            PyObject *r = PyList_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    }
    else if (PyTuple_CheckExact(o)) {
        Py_ssize_t n = ((!wraparound) | likely(i >= 0)) ? i : i + PyTuple_GET_SIZE(o);
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyTuple_GET_SIZE(o)))) {
            PyObject *r = PyTuple_GET_ITEM(o, n);
            Py_INCREF(r);
            return r;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return NULL;
                    PyErr_Clear();
                }
            }
            return m->sq_item(o, i);
        }
    }
#else
    if (is_list || PySequence_Check(o)) {
        return PySequence_GetItem(o, i);
    }
#endif
    return __Pyx_GetItemInt_Generic(o, PyInt_FromSsize_t(i));
}

/* PyDictVersioning */
  #if CYTHON_USE_DICT_VERSIONS && CYTHON_USE_TYPE_SLOTS
static CYTHON_INLINE PY_UINT64_T __Pyx_get_tp_dict_version(PyObject *obj) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    return likely(dict) ? __PYX_GET_DICT_VERSION(dict) : 0;
}
static CYTHON_INLINE PY_UINT64_T __Pyx_get_object_dict_version(PyObject *obj) {
    PyObject **dictptr = NULL;
    Py_ssize_t offset = Py_TYPE(obj)->tp_dictoffset;
    if (offset) {
#if CYTHON_COMPILING_IN_CPYTHON
        dictptr = (likely(offset > 0)) ? (PyObject **) ((char *)obj + offset) : _PyObject_GetDictPtr(obj);
#else
        dictptr = _PyObject_GetDictPtr(obj);
#endif
    }
    return (dictptr && *dictptr) ? __PYX_GET_DICT_VERSION(*dictptr) : 0;
}
static CYTHON_INLINE int __Pyx_object_dict_version_matches(PyObject* obj, PY_UINT64_T tp_dict_version, PY_UINT64_T obj_dict_version) {
    PyObject *dict = Py_TYPE(obj)->tp_dict;
    if (unlikely(!dict) || unlikely(tp_dict_version != __PYX_GET_DICT_VERSION(dict)))
        return 0;
    return obj_dict_version == __Pyx_get_object_dict_version(obj);
}
#endif

/* GetModuleGlobalName */
  #if CYTHON_USE_DICT_VERSIONS
static PyObject *__Pyx__GetModuleGlobalName(PyObject *name, PY_UINT64_T *dict_version, PyObject **dict_cached_value)
#else
static CYTHON_INLINE PyObject *__Pyx__GetModuleGlobalName(PyObject *name)
#endif
{
    PyObject *result;
#if !CYTHON_AVOID_BORROWED_REFS
#if CYTHON_COMPILING_IN_CPYTHON && PY_VERSION_HEX >= 0x030500A1
    result = _PyDict_GetItem_KnownHash(__pyx_d, name, ((PyASCIIObject *) name)->hash);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    } else if (unlikely(PyErr_Occurred())) {
        return NULL;
    }
#else
    result = PyDict_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
#endif
#else
    result = PyObject_GetItem(__pyx_d, name);
    __PYX_UPDATE_DICT_CACHE(__pyx_d, result, *dict_cached_value, *dict_version)
    if (likely(result)) {
        return __Pyx_NewRef(result);
    }
    PyErr_Clear();
#endif
    return __Pyx_GetBuiltinName(name);
}

/* PyObjectCall2Args */
  static CYTHON_UNUSED PyObject* __Pyx_PyObject_Call2Args(PyObject* function, PyObject* arg1, PyObject* arg2) {
    PyObject *args, *result = NULL;
    #if CYTHON_FAST_PYCALL
    if (PyFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyFunction_FastCall(function, args, 2);
    }
    #endif
    #if CYTHON_FAST_PYCCALL
    if (__Pyx_PyFastCFunction_Check(function)) {
        PyObject *args[2] = {arg1, arg2};
        return __Pyx_PyCFunction_FastCall(function, args, 2);
    }
    #endif
    args = PyTuple_New(2);
    if (unlikely(!args)) goto done;
    Py_INCREF(arg1);
    PyTuple_SET_ITEM(args, 0, arg1);
    Py_INCREF(arg2);
    PyTuple_SET_ITEM(args, 1, arg2);
    Py_INCREF(function);
    result = __Pyx_PyObject_Call(function, args, NULL);
    Py_DECREF(args);
    Py_DECREF(function);
done:
    return result;
}

/* ObjectGetItem */
  #if CYTHON_USE_TYPE_SLOTS
static PyObject *__Pyx_PyObject_GetIndex(PyObject *obj, PyObject* index) {
    PyObject *runerr;
    Py_ssize_t key_value;
    PySequenceMethods *m = Py_TYPE(obj)->tp_as_sequence;
    if (unlikely(!(m && m->sq_item))) {
        PyErr_Format(PyExc_TypeError, "'%.200s' object is not subscriptable", Py_TYPE(obj)->tp_name);
        return NULL;
    }
    key_value = __Pyx_PyIndex_AsSsize_t(index);
    if (likely(key_value != -1 || !(runerr = PyErr_Occurred()))) {
        return __Pyx_GetItemInt_Fast(obj, key_value, 0, 1, 1);
    }
    if (PyErr_GivenExceptionMatches(runerr, PyExc_OverflowError)) {
        PyErr_Clear();
        PyErr_Format(PyExc_IndexError, "cannot fit '%.200s' into an index-sized integer", Py_TYPE(index)->tp_name);
    }
    return NULL;
}
static PyObject *__Pyx_PyObject_GetItem(PyObject *obj, PyObject* key) {
    PyMappingMethods *m = Py_TYPE(obj)->tp_as_mapping;
    if (likely(m && m->mp_subscript)) {
        return m->mp_subscript(obj, key);
    }
    return __Pyx_PyObject_GetIndex(obj, key);
}
#endif

/* PyIntBinop */
  #if !CYTHON_COMPILING_IN_PYPY
static PyObject* __Pyx_PyInt_AddObjC(PyObject *op1, PyObject *op2, CYTHON_UNUSED long intval, int inplace, int zerodivision_check) {
    (void)inplace;
    (void)zerodivision_check;
    #if PY_MAJOR_VERSION < 3
    if (likely(PyInt_CheckExact(op1))) {
        const long b = intval;
        long x;
        long a = PyInt_AS_LONG(op1);
            x = (long)((unsigned long)a + b);
            if (likely((x^a) >= 0 || (x^b) >= 0))
                return PyInt_FromLong(x);
            return PyLong_Type.tp_as_number->nb_add(op1, op2);
    }
    #endif
    #if CYTHON_USE_PYLONG_INTERNALS
    if (likely(PyLong_CheckExact(op1))) {
        const long b = intval;
        long a, x;
#ifdef HAVE_LONG_LONG
        const PY_LONG_LONG llb = intval;
        PY_LONG_LONG lla, llx;
#endif
        const digit* digits = ((PyLongObject*)op1)->ob_digit;
        const Py_ssize_t size = Py_SIZE(op1);
        if (likely(__Pyx_sst_abs(size) <= 1)) {
            a = likely(size) ? digits[0] : 0;
            if (size == -1) a = -a;
        } else {
            switch (size) {
                case -2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 2:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        a = (long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 2 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 3:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        a = (long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 3 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case -4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = -(PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                case 4:
                    if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                        a = (long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0]));
                        break;
#ifdef HAVE_LONG_LONG
                    } else if (8 * sizeof(PY_LONG_LONG) - 1 > 4 * PyLong_SHIFT) {
                        lla = (PY_LONG_LONG) (((((((((unsigned PY_LONG_LONG)digits[3]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[2]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[1]) << PyLong_SHIFT) | (unsigned PY_LONG_LONG)digits[0]));
                        goto long_long;
#endif
                    }
                    CYTHON_FALLTHROUGH;
                default: return PyLong_Type.tp_as_number->nb_add(op1, op2);
            }
        }
                x = a + b;
            return PyLong_FromLong(x);
#ifdef HAVE_LONG_LONG
        long_long:
                llx = lla + llb;
            return PyLong_FromLongLong(llx);
#endif


    }
    #endif
    if (PyFloat_CheckExact(op1)) {
        const long b = intval;
        double a = PyFloat_AS_DOUBLE(op1);
            double result;
            PyFPE_START_PROTECT("add", return NULL)
            result = ((double)a) + (double)b;
            PyFPE_END_PROTECT(result)
            return PyFloat_FromDouble(result);
    }
    return (inplace ? PyNumber_InPlaceAdd : PyNumber_Add)(op1, op2);
}
#endif

/* SetItemInt */
  static int __Pyx_SetItemInt_Generic(PyObject *o, PyObject *j, PyObject *v) {
    int r;
    if (!j) return -1;
    r = PyObject_SetItem(o, j, v);
    Py_DECREF(j);
    return r;
}
static CYTHON_INLINE int __Pyx_SetItemInt_Fast(PyObject *o, Py_ssize_t i, PyObject *v, int is_list,
                                               CYTHON_NCP_UNUSED int wraparound, CYTHON_NCP_UNUSED int boundscheck) {
#if CYTHON_ASSUME_SAFE_MACROS && !CYTHON_AVOID_BORROWED_REFS && CYTHON_USE_TYPE_SLOTS
    if (is_list || PyList_CheckExact(o)) {
        Py_ssize_t n = (!wraparound) ? i : ((likely(i >= 0)) ? i : i + PyList_GET_SIZE(o));
        if ((!boundscheck) || likely(__Pyx_is_valid_index(n, PyList_GET_SIZE(o)))) {
            PyObject* old = PyList_GET_ITEM(o, n);
            Py_INCREF(v);
            PyList_SET_ITEM(o, n, v);
            Py_DECREF(old);
            return 1;
        }
    } else {
        PySequenceMethods *m = Py_TYPE(o)->tp_as_sequence;
        if (likely(m && m->sq_ass_item)) {
            if (wraparound && unlikely(i < 0) && likely(m->sq_length)) {
                Py_ssize_t l = m->sq_length(o);
                if (likely(l >= 0)) {
                    i += l;
                } else {
                    if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                        return -1;
                    PyErr_Clear();
                }
            }
            return m->sq_ass_item(o, i, v);
        }
    }
#else
#if CYTHON_COMPILING_IN_PYPY
    if (is_list || (PySequence_Check(o) && !PyDict_Check(o)))
#else
    if (is_list || PySequence_Check(o))
#endif
    {
        return PySequence_SetItem(o, i, v);
    }
#endif
    return __Pyx_SetItemInt_Generic(o, PyInt_FromSsize_t(i), v);
}

/* SliceObject */
  static CYTHON_INLINE PyObject* __Pyx_PyObject_GetSlice(PyObject* obj,
        Py_ssize_t cstart, Py_ssize_t cstop,
        PyObject** _py_start, PyObject** _py_stop, PyObject** _py_slice,
        int has_cstart, int has_cstop, CYTHON_UNUSED int wraparound) {
#if CYTHON_USE_TYPE_SLOTS
    PyMappingMethods* mp;
#if PY_MAJOR_VERSION < 3
    PySequenceMethods* ms = Py_TYPE(obj)->tp_as_sequence;
    if (likely(ms && ms->sq_slice)) {
        if (!has_cstart) {
            if (_py_start && (*_py_start != Py_None)) {
                cstart = __Pyx_PyIndex_AsSsize_t(*_py_start);
                if ((cstart == (Py_ssize_t)-1) && PyErr_Occurred()) goto bad;
            } else
                cstart = 0;
        }
        if (!has_cstop) {
            if (_py_stop && (*_py_stop != Py_None)) {
                cstop = __Pyx_PyIndex_AsSsize_t(*_py_stop);
                if ((cstop == (Py_ssize_t)-1) && PyErr_Occurred()) goto bad;
            } else
                cstop = PY_SSIZE_T_MAX;
        }
        if (wraparound && unlikely((cstart < 0) | (cstop < 0)) && likely(ms->sq_length)) {
            Py_ssize_t l = ms->sq_length(obj);
            if (likely(l >= 0)) {
                if (cstop < 0) {
                    cstop += l;
                    if (cstop < 0) cstop = 0;
                }
                if (cstart < 0) {
                    cstart += l;
                    if (cstart < 0) cstart = 0;
                }
            } else {
                if (!PyErr_ExceptionMatches(PyExc_OverflowError))
                    goto bad;
                PyErr_Clear();
            }
        }
        return ms->sq_slice(obj, cstart, cstop);
    }
#endif
    mp = Py_TYPE(obj)->tp_as_mapping;
    if (likely(mp && mp->mp_subscript))
#endif
    {
        PyObject* result;
        PyObject *py_slice, *py_start, *py_stop;
        if (_py_slice) {
            py_slice = *_py_slice;
        } else {
            PyObject* owned_start = NULL;
            PyObject* owned_stop = NULL;
            if (_py_start) {
                py_start = *_py_start;
            } else {
                if (has_cstart) {
                    owned_start = py_start = PyInt_FromSsize_t(cstart);
                    if (unlikely(!py_start)) goto bad;
                } else
                    py_start = Py_None;
            }
            if (_py_stop) {
                py_stop = *_py_stop;
            } else {
                if (has_cstop) {
                    owned_stop = py_stop = PyInt_FromSsize_t(cstop);
                    if (unlikely(!py_stop)) {
                        Py_XDECREF(owned_start);
                        goto bad;
                    }
                } else
                    py_stop = Py_None;
            }
            py_slice = PySlice_New(py_start, py_stop, Py_None);
            Py_XDECREF(owned_start);
            Py_XDECREF(owned_stop);
            if (unlikely(!py_slice)) goto bad;
        }
#if CYTHON_USE_TYPE_SLOTS
        result = mp->mp_subscript(obj, py_slice);
#else
        result = PyObject_GetItem(obj, py_slice);
#endif
        if (!_py_slice) {
            Py_DECREF(py_slice);
        }
        return result;
    }
    PyErr_Format(PyExc_TypeError,
        "'%.200s' object is unsliceable", Py_TYPE(obj)->tp_name);
bad:
    return NULL;
}

/* PyErrFetchRestore */
  #if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx_ErrRestoreInState(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    tmp_type = tstate->curexc_type;
    tmp_value = tstate->curexc_value;
    tmp_tb = tstate->curexc_traceback;
    tstate->curexc_type = type;
    tstate->curexc_value = value;
    tstate->curexc_traceback = tb;
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
static CYTHON_INLINE void __Pyx_ErrFetchInState(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    *type = tstate->curexc_type;
    *value = tstate->curexc_value;
    *tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
}
#endif

/* RaiseException */
  #if PY_MAJOR_VERSION < 3
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb,
                        CYTHON_UNUSED PyObject *cause) {
    __Pyx_PyThreadState_declare
    Py_XINCREF(type);
    if (!value || value == Py_None)
        value = NULL;
    else
        Py_INCREF(value);
    if (!tb || tb == Py_None)
        tb = NULL;
    else {
        Py_INCREF(tb);
        if (!PyTraceBack_Check(tb)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: arg 3 must be a traceback or None");
            goto raise_error;
        }
    }
    if (PyType_Check(type)) {
#if CYTHON_COMPILING_IN_PYPY
        if (!value) {
            Py_INCREF(Py_None);
            value = Py_None;
        }
#endif
        PyErr_NormalizeException(&type, &value, &tb);
    } else {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto raise_error;
        }
        value = type;
        type = (PyObject*) Py_TYPE(type);
        Py_INCREF(type);
        if (!PyType_IsSubtype((PyTypeObject *)type, (PyTypeObject *)PyExc_BaseException)) {
            PyErr_SetString(PyExc_TypeError,
                "raise: exception class must be a subclass of BaseException");
            goto raise_error;
        }
    }
    __Pyx_PyThreadState_assign
    __Pyx_ErrRestore(type, value, tb);
    return;
raise_error:
    Py_XDECREF(value);
    Py_XDECREF(type);
    Py_XDECREF(tb);
    return;
}
#else
static void __Pyx_Raise(PyObject *type, PyObject *value, PyObject *tb, PyObject *cause) {
    PyObject* owned_instance = NULL;
    if (tb == Py_None) {
        tb = 0;
    } else if (tb && !PyTraceBack_Check(tb)) {
        PyErr_SetString(PyExc_TypeError,
            "raise: arg 3 must be a traceback or None");
        goto bad;
    }
    if (value == Py_None)
        value = 0;
    if (PyExceptionInstance_Check(type)) {
        if (value) {
            PyErr_SetString(PyExc_TypeError,
                "instance exception may not have a separate value");
            goto bad;
        }
        value = type;
        type = (PyObject*) Py_TYPE(value);
    } else if (PyExceptionClass_Check(type)) {
        PyObject *instance_class = NULL;
        if (value && PyExceptionInstance_Check(value)) {
            instance_class = (PyObject*) Py_TYPE(value);
            if (instance_class != type) {
                int is_subclass = PyObject_IsSubclass(instance_class, type);
                if (!is_subclass) {
                    instance_class = NULL;
                } else if (unlikely(is_subclass == -1)) {
                    goto bad;
                } else {
                    type = instance_class;
                }
            }
        }
        if (!instance_class) {
            PyObject *args;
            if (!value)
                args = PyTuple_New(0);
            else if (PyTuple_Check(value)) {
                Py_INCREF(value);
                args = value;
            } else
                args = PyTuple_Pack(1, value);
            if (!args)
                goto bad;
            owned_instance = PyObject_Call(type, args, NULL);
            Py_DECREF(args);
            if (!owned_instance)
                goto bad;
            value = owned_instance;
            if (!PyExceptionInstance_Check(value)) {
                PyErr_Format(PyExc_TypeError,
                             "calling %R should have returned an instance of "
                             "BaseException, not %R",
                             type, Py_TYPE(value));
                goto bad;
            }
        }
    } else {
        PyErr_SetString(PyExc_TypeError,
            "raise: exception class must be a subclass of BaseException");
        goto bad;
    }
    if (cause) {
        PyObject *fixed_cause;
        if (cause == Py_None) {
            fixed_cause = NULL;
        } else if (PyExceptionClass_Check(cause)) {
            fixed_cause = PyObject_CallObject(cause, NULL);
            if (fixed_cause == NULL)
                goto bad;
        } else if (PyExceptionInstance_Check(cause)) {
            fixed_cause = cause;
            Py_INCREF(fixed_cause);
        } else {
            PyErr_SetString(PyExc_TypeError,
                            "exception causes must derive from "
                            "BaseException");
            goto bad;
        }
        PyException_SetCause(value, fixed_cause);
    }
    PyErr_SetObject(type, value);
    if (tb) {
#if CYTHON_COMPILING_IN_PYPY
        PyObject *tmp_type, *tmp_value, *tmp_tb;
        PyErr_Fetch(&tmp_type, &tmp_value, &tmp_tb);
        Py_INCREF(tb);
        PyErr_Restore(tmp_type, tmp_value, tb);
        Py_XDECREF(tmp_tb);
#else
        PyThreadState *tstate = __Pyx_PyThreadState_Current;
        PyObject* tmp_tb = tstate->curexc_traceback;
        if (tb != tmp_tb) {
            Py_INCREF(tb);
            tstate->curexc_traceback = tb;
            Py_XDECREF(tmp_tb);
        }
#endif
    }
bad:
    Py_XDECREF(owned_instance);
    return;
}
#endif

/* DictGetItem */
  #if PY_MAJOR_VERSION >= 3 && !CYTHON_COMPILING_IN_PYPY
static PyObject *__Pyx_PyDict_GetItem(PyObject *d, PyObject* key) {
    PyObject *value;
    value = PyDict_GetItemWithError(d, key);
    if (unlikely(!value)) {
        if (!PyErr_Occurred()) {
            if (unlikely(PyTuple_Check(key))) {
                PyObject* args = PyTuple_Pack(1, key);
                if (likely(args)) {
                    PyErr_SetObject(PyExc_KeyError, args);
                    Py_DECREF(args);
                }
            } else {
                PyErr_SetObject(PyExc_KeyError, key);
            }
        }
        return NULL;
    }
    Py_INCREF(value);
    return value;
}
#endif

/* RaiseTooManyValuesToUnpack */
  static CYTHON_INLINE void __Pyx_RaiseTooManyValuesError(Py_ssize_t expected) {
    PyErr_Format(PyExc_ValueError,
                 "too many values to unpack (expected %" CYTHON_FORMAT_SSIZE_T "d)", expected);
}

/* RaiseNeedMoreValuesToUnpack */
  static CYTHON_INLINE void __Pyx_RaiseNeedMoreValuesError(Py_ssize_t index) {
    PyErr_Format(PyExc_ValueError,
                 "need more than %" CYTHON_FORMAT_SSIZE_T "d value%.1s to unpack",
                 index, (index == 1) ? "" : "s");
}

/* RaiseNoneIterError */
  static CYTHON_INLINE void __Pyx_RaiseNoneNotIterableError(void) {
    PyErr_SetString(PyExc_TypeError, "'NoneType' object is not iterable");
}

/* ExtTypeTest */
  static CYTHON_INLINE int __Pyx_TypeTest(PyObject *obj, PyTypeObject *type) {
    if (unlikely(!type)) {
        PyErr_SetString(PyExc_SystemError, "Missing type object");
        return 0;
    }
    if (likely(__Pyx_TypeCheck(obj, type)))
        return 1;
    PyErr_Format(PyExc_TypeError, "Cannot convert %.200s to %.200s",
                 Py_TYPE(obj)->tp_name, type->tp_name);
    return 0;
}

/* GetTopmostException */
  #if CYTHON_USE_EXC_INFO_STACK
static _PyErr_StackItem *
__Pyx_PyErr_GetTopmostException(PyThreadState *tstate)
{
    _PyErr_StackItem *exc_info = tstate->exc_info;
    while ((exc_info->exc_type == NULL || exc_info->exc_type == Py_None) &&
           exc_info->previous_item != NULL)
    {
        exc_info = exc_info->previous_item;
    }
    return exc_info;
}
#endif

/* SaveResetException */
  #if CYTHON_FAST_THREAD_STATE
static CYTHON_INLINE void __Pyx__ExceptionSave(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb) {
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = __Pyx_PyErr_GetTopmostException(tstate);
    *type = exc_info->exc_type;
    *value = exc_info->exc_value;
    *tb = exc_info->exc_traceback;
    #else
    *type = tstate->exc_type;
    *value = tstate->exc_value;
    *tb = tstate->exc_traceback;
    #endif
    Py_XINCREF(*type);
    Py_XINCREF(*value);
    Py_XINCREF(*tb);
}
static CYTHON_INLINE void __Pyx__ExceptionReset(PyThreadState *tstate, PyObject *type, PyObject *value, PyObject *tb) {
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    #if CYTHON_USE_EXC_INFO_STACK
    _PyErr_StackItem *exc_info = tstate->exc_info;
    tmp_type = exc_info->exc_type;
    tmp_value = exc_info->exc_value;
    tmp_tb = exc_info->exc_traceback;
    exc_info->exc_type = type;
    exc_info->exc_value = value;
    exc_info->exc_traceback = tb;
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = type;
    tstate->exc_value = value;
    tstate->exc_traceback = tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
}
#endif

/* PyErrExceptionMatches */
  #if CYTHON_FAST_THREAD_STATE
static int __Pyx_PyErr_ExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        if (__Pyx_PyErr_GivenExceptionMatches(exc_type, PyTuple_GET_ITEM(tuple, i))) return 1;
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_ExceptionMatchesInState(PyThreadState* tstate, PyObject* err) {
    PyObject *exc_type = tstate->curexc_type;
    if (exc_type == err) return 1;
    if (unlikely(!exc_type)) return 0;
    if (unlikely(PyTuple_Check(err)))
        return __Pyx_PyErr_ExceptionMatchesTuple(exc_type, err);
    return __Pyx_PyErr_GivenExceptionMatches(exc_type, err);
}
#endif

/* GetException */
  #if CYTHON_FAST_THREAD_STATE
static int __Pyx__GetException(PyThreadState *tstate, PyObject **type, PyObject **value, PyObject **tb)
#else
static int __Pyx_GetException(PyObject **type, PyObject **value, PyObject **tb)
#endif
{
    PyObject *local_type, *local_value, *local_tb;
#if CYTHON_FAST_THREAD_STATE
    PyObject *tmp_type, *tmp_value, *tmp_tb;
    local_type = tstate->curexc_type;
    local_value = tstate->curexc_value;
    local_tb = tstate->curexc_traceback;
    tstate->curexc_type = 0;
    tstate->curexc_value = 0;
    tstate->curexc_traceback = 0;
#else
    PyErr_Fetch(&local_type, &local_value, &local_tb);
#endif
    PyErr_NormalizeException(&local_type, &local_value, &local_tb);
#if CYTHON_FAST_THREAD_STATE
    if (unlikely(tstate->curexc_type))
#else
    if (unlikely(PyErr_Occurred()))
#endif
        goto bad;
    #if PY_MAJOR_VERSION >= 3
    if (local_tb) {
        if (unlikely(PyException_SetTraceback(local_value, local_tb) < 0))
            goto bad;
    }
    #endif
    Py_XINCREF(local_tb);
    Py_XINCREF(local_type);
    Py_XINCREF(local_value);
    *type = local_type;
    *value = local_value;
    *tb = local_tb;
#if CYTHON_FAST_THREAD_STATE
    #if CYTHON_USE_EXC_INFO_STACK
    {
        _PyErr_StackItem *exc_info = tstate->exc_info;
        tmp_type = exc_info->exc_type;
        tmp_value = exc_info->exc_value;
        tmp_tb = exc_info->exc_traceback;
        exc_info->exc_type = local_type;
        exc_info->exc_value = local_value;
        exc_info->exc_traceback = local_tb;
    }
    #else
    tmp_type = tstate->exc_type;
    tmp_value = tstate->exc_value;
    tmp_tb = tstate->exc_traceback;
    tstate->exc_type = local_type;
    tstate->exc_value = local_value;
    tstate->exc_traceback = local_tb;
    #endif
    Py_XDECREF(tmp_type);
    Py_XDECREF(tmp_value);
    Py_XDECREF(tmp_tb);
#else
    PyErr_SetExcInfo(local_type, local_value, local_tb);
#endif
    return 0;
bad:
    *type = 0;
    *value = 0;
    *tb = 0;
    Py_XDECREF(local_type);
    Py_XDECREF(local_value);
    Py_XDECREF(local_tb);
    return -1;
}

/* TypeImport */
  #ifndef __PYX_HAVE_RT_ImportType
#define __PYX_HAVE_RT_ImportType
static PyTypeObject *__Pyx_ImportType(PyObject *module, const char *module_name, const char *class_name,
    size_t size, enum __Pyx_ImportType_CheckSize check_size)
{
    PyObject *result = 0;
    char warning[200];
    Py_ssize_t basicsize;
#ifdef Py_LIMITED_API
    PyObject *py_basicsize;
#endif
    result = PyObject_GetAttrString(module, class_name);
    if (!result)
        goto bad;
    if (!PyType_Check(result)) {
        PyErr_Format(PyExc_TypeError,
            "%.200s.%.200s is not a type object",
            module_name, class_name);
        goto bad;
    }
#ifndef Py_LIMITED_API
    basicsize = ((PyTypeObject *)result)->tp_basicsize;
#else
    py_basicsize = PyObject_GetAttrString(result, "__basicsize__");
    if (!py_basicsize)
        goto bad;
    basicsize = PyLong_AsSsize_t(py_basicsize);
    Py_DECREF(py_basicsize);
    py_basicsize = 0;
    if (basicsize == (Py_ssize_t)-1 && PyErr_Occurred())
        goto bad;
#endif
    if ((size_t)basicsize < size) {
        PyErr_Format(PyExc_ValueError,
            "%.200s.%.200s size changed, may indicate binary incompatibility. "
            "Expected %zd from C header, got %zd from PyObject",
            module_name, class_name, size, basicsize);
        goto bad;
    }
    if (check_size == __Pyx_ImportType_CheckSize_Error && (size_t)basicsize != size) {
        PyErr_Format(PyExc_ValueError,
            "%.200s.%.200s size changed, may indicate binary incompatibility. "
            "Expected %zd from C header, got %zd from PyObject",
            module_name, class_name, size, basicsize);
        goto bad;
    }
    else if (check_size == __Pyx_ImportType_CheckSize_Warn && (size_t)basicsize > size) {
        PyOS_snprintf(warning, sizeof(warning),
            "%s.%s size changed, may indicate binary incompatibility. "
            "Expected %zd from C header, got %zd from PyObject",
            module_name, class_name, size, basicsize);
        if (PyErr_WarnEx(NULL, warning, 0) < 0) goto bad;
    }
    return (PyTypeObject *)result;
bad:
    Py_XDECREF(result);
    return NULL;
}
#endif

/* Import */
  static PyObject *__Pyx_Import(PyObject *name, PyObject *from_list, int level) {
    PyObject *empty_list = 0;
    PyObject *module = 0;
    PyObject *global_dict = 0;
    PyObject *empty_dict = 0;
    PyObject *list;
    #if PY_MAJOR_VERSION < 3
    PyObject *py_import;
    py_import = __Pyx_PyObject_GetAttrStr(__pyx_b, __pyx_n_s_import);
    if (!py_import)
        goto bad;
    #endif
    if (from_list)
        list = from_list;
    else {
        empty_list = PyList_New(0);
        if (!empty_list)
            goto bad;
        list = empty_list;
    }
    global_dict = PyModule_GetDict(__pyx_m);
    if (!global_dict)
        goto bad;
    empty_dict = PyDict_New();
    if (!empty_dict)
        goto bad;
    {
        #if PY_MAJOR_VERSION >= 3
        if (level == -1) {
            if ((1) && (strchr(__Pyx_MODULE_NAME, '.'))) {
                module = PyImport_ImportModuleLevelObject(
                    name, global_dict, empty_dict, list, 1);
                if (!module) {
                    if (!PyErr_ExceptionMatches(PyExc_ImportError))
                        goto bad;
                    PyErr_Clear();
                }
            }
            level = 0;
        }
        #endif
        if (!module) {
            #if PY_MAJOR_VERSION < 3
            PyObject *py_level = PyInt_FromLong(level);
            if (!py_level)
                goto bad;
            module = PyObject_CallFunctionObjArgs(py_import,
                name, global_dict, empty_dict, list, py_level, (PyObject *)NULL);
            Py_DECREF(py_level);
            #else
            module = PyImport_ImportModuleLevelObject(
                name, global_dict, empty_dict, list, level);
            #endif
        }
    }
bad:
    #if PY_MAJOR_VERSION < 3
    Py_XDECREF(py_import);
    #endif
    Py_XDECREF(empty_list);
    Py_XDECREF(empty_dict);
    return module;
}

/* CLineInTraceback */
  #ifndef CYTHON_CLINE_IN_TRACEBACK
static int __Pyx_CLineForTraceback(CYTHON_NCP_UNUSED PyThreadState *tstate, int c_line) {
    PyObject *use_cline;
    PyObject *ptype, *pvalue, *ptraceback;
#if CYTHON_COMPILING_IN_CPYTHON
    PyObject **cython_runtime_dict;
#endif
    if (unlikely(!__pyx_cython_runtime)) {
        return c_line;
    }
    __Pyx_ErrFetchInState(tstate, &ptype, &pvalue, &ptraceback);
#if CYTHON_COMPILING_IN_CPYTHON
    cython_runtime_dict = _PyObject_GetDictPtr(__pyx_cython_runtime);
    if (likely(cython_runtime_dict)) {
        __PYX_PY_DICT_LOOKUP_IF_MODIFIED(
            use_cline, *cython_runtime_dict,
            __Pyx_PyDict_GetItemStr(*cython_runtime_dict, __pyx_n_s_cline_in_traceback))
    } else
#endif
    {
      PyObject *use_cline_obj = __Pyx_PyObject_GetAttrStr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback);
      if (use_cline_obj) {
        use_cline = PyObject_Not(use_cline_obj) ? Py_False : Py_True;
        Py_DECREF(use_cline_obj);
      } else {
        PyErr_Clear();
        use_cline = NULL;
      }
    }
    if (!use_cline) {
        c_line = 0;
        PyObject_SetAttr(__pyx_cython_runtime, __pyx_n_s_cline_in_traceback, Py_False);
    }
    else if (use_cline == Py_False || (use_cline != Py_True && PyObject_Not(use_cline) != 0)) {
        c_line = 0;
    }
    __Pyx_ErrRestoreInState(tstate, ptype, pvalue, ptraceback);
    return c_line;
}
#endif

/* CodeObjectCache */
  static int __pyx_bisect_code_objects(__Pyx_CodeObjectCacheEntry* entries, int count, int code_line) {
    int start = 0, mid = 0, end = count - 1;
    if (end >= 0 && code_line > entries[end].code_line) {
        return count;
    }
    while (start < end) {
        mid = start + (end - start) / 2;
        if (code_line < entries[mid].code_line) {
            end = mid;
        } else if (code_line > entries[mid].code_line) {
             start = mid + 1;
        } else {
            return mid;
        }
    }
    if (code_line <= entries[mid].code_line) {
        return mid;
    } else {
        return mid + 1;
    }
}
static PyCodeObject *__pyx_find_code_object(int code_line) {
    PyCodeObject* code_object;
    int pos;
    if (unlikely(!code_line) || unlikely(!__pyx_code_cache.entries)) {
        return NULL;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if (unlikely(pos >= __pyx_code_cache.count) || unlikely(__pyx_code_cache.entries[pos].code_line != code_line)) {
        return NULL;
    }
    code_object = __pyx_code_cache.entries[pos].code_object;
    Py_INCREF(code_object);
    return code_object;
}
static void __pyx_insert_code_object(int code_line, PyCodeObject* code_object) {
    int pos, i;
    __Pyx_CodeObjectCacheEntry* entries = __pyx_code_cache.entries;
    if (unlikely(!code_line)) {
        return;
    }
    if (unlikely(!entries)) {
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Malloc(64*sizeof(__Pyx_CodeObjectCacheEntry));
        if (likely(entries)) {
            __pyx_code_cache.entries = entries;
            __pyx_code_cache.max_count = 64;
            __pyx_code_cache.count = 1;
            entries[0].code_line = code_line;
            entries[0].code_object = code_object;
            Py_INCREF(code_object);
        }
        return;
    }
    pos = __pyx_bisect_code_objects(__pyx_code_cache.entries, __pyx_code_cache.count, code_line);
    if ((pos < __pyx_code_cache.count) && unlikely(__pyx_code_cache.entries[pos].code_line == code_line)) {
        PyCodeObject* tmp = entries[pos].code_object;
        entries[pos].code_object = code_object;
        Py_DECREF(tmp);
        return;
    }
    if (__pyx_code_cache.count == __pyx_code_cache.max_count) {
        int new_max = __pyx_code_cache.max_count + 64;
        entries = (__Pyx_CodeObjectCacheEntry*)PyMem_Realloc(
            __pyx_code_cache.entries, ((size_t)new_max) * sizeof(__Pyx_CodeObjectCacheEntry));
        if (unlikely(!entries)) {
            return;
        }
        __pyx_code_cache.entries = entries;
        __pyx_code_cache.max_count = new_max;
    }
    for (i=__pyx_code_cache.count; i>pos; i--) {
        entries[i] = entries[i-1];
    }
    entries[pos].code_line = code_line;
    entries[pos].code_object = code_object;
    __pyx_code_cache.count++;
    Py_INCREF(code_object);
}

/* AddTraceback */
  #include "compile.h"
#include "frameobject.h"
#include "traceback.h"
static PyCodeObject* __Pyx_CreateCodeObjectForTraceback(
            const char *funcname, int c_line,
            int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyObject *py_srcfile = 0;
    PyObject *py_funcname = 0;
    #if PY_MAJOR_VERSION < 3
    py_srcfile = PyString_FromString(filename);
    #else
    py_srcfile = PyUnicode_FromString(filename);
    #endif
    if (!py_srcfile) goto bad;
    if (c_line) {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #else
        py_funcname = PyUnicode_FromFormat( "%s (%s:%d)", funcname, __pyx_cfilenm, c_line);
        #endif
    }
    else {
        #if PY_MAJOR_VERSION < 3
        py_funcname = PyString_FromString(funcname);
        #else
        py_funcname = PyUnicode_FromString(funcname);
        #endif
    }
    if (!py_funcname) goto bad;
    py_code = __Pyx_PyCode_New(
        0,
        0,
        0,
        0,
        0,
        __pyx_empty_bytes, /*PyObject *code,*/
        __pyx_empty_tuple, /*PyObject *consts,*/
        __pyx_empty_tuple, /*PyObject *names,*/
        __pyx_empty_tuple, /*PyObject *varnames,*/
        __pyx_empty_tuple, /*PyObject *freevars,*/
        __pyx_empty_tuple, /*PyObject *cellvars,*/
        py_srcfile,   /*PyObject *filename,*/
        py_funcname,  /*PyObject *name,*/
        py_line,
        __pyx_empty_bytes  /*PyObject *lnotab*/
    );
    Py_DECREF(py_srcfile);
    Py_DECREF(py_funcname);
    return py_code;
bad:
    Py_XDECREF(py_srcfile);
    Py_XDECREF(py_funcname);
    return NULL;
}
static void __Pyx_AddTraceback(const char *funcname, int c_line,
                               int py_line, const char *filename) {
    PyCodeObject *py_code = 0;
    PyFrameObject *py_frame = 0;
    PyThreadState *tstate = __Pyx_PyThreadState_Current;
    if (c_line) {
        c_line = __Pyx_CLineForTraceback(tstate, c_line);
    }
    py_code = __pyx_find_code_object(c_line ? -c_line : py_line);
    if (!py_code) {
        py_code = __Pyx_CreateCodeObjectForTraceback(
            funcname, c_line, py_line, filename);
        if (!py_code) goto bad;
        __pyx_insert_code_object(c_line ? -c_line : py_line, py_code);
    }
    py_frame = PyFrame_New(
        tstate,            /*PyThreadState *tstate,*/
        py_code,           /*PyCodeObject *code,*/
        __pyx_d,    /*PyObject *globals,*/
        0                  /*PyObject *locals*/
    );
    if (!py_frame) goto bad;
    __Pyx_PyFrame_SetLineNumber(py_frame, py_line);
    PyTraceBack_Here(py_frame);
bad:
    Py_XDECREF(py_code);
    Py_XDECREF(py_frame);
}

#if PY_MAJOR_VERSION < 3
static int __Pyx_GetBuffer(PyObject *obj, Py_buffer *view, int flags) {
    if (PyObject_CheckBuffer(obj)) return PyObject_GetBuffer(obj, view, flags);
        if (__Pyx_TypeCheck(obj, __pyx_ptype_5numpy_ndarray)) return __pyx_pw_5numpy_7ndarray_1__getbuffer__(obj, view, flags);
    PyErr_Format(PyExc_TypeError, "'%.200s' does not have the buffer interface", Py_TYPE(obj)->tp_name);
    return -1;
}
static void __Pyx_ReleaseBuffer(Py_buffer *view) {
    PyObject *obj = view->obj;
    if (!obj) return;
    if (PyObject_CheckBuffer(obj)) {
        PyBuffer_Release(view);
        return;
    }
    if ((0)) {}
        else if (__Pyx_TypeCheck(obj, __pyx_ptype_5numpy_ndarray)) __pyx_pw_5numpy_7ndarray_3__releasebuffer__(obj, view);
    view->obj = NULL;
    Py_DECREF(obj);
}
#endif


  /* CIntFromPyVerify */
  #define __PYX_VERIFY_RETURN_INT(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 0)
#define __PYX_VERIFY_RETURN_INT_EXC(target_type, func_type, func_value)\
    __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, 1)
#define __PYX__VERIFY_RETURN_INT(target_type, func_type, func_value, exc)\
    {\
        func_type value = func_value;\
        if (sizeof(target_type) < sizeof(func_type)) {\
            if (unlikely(value != (func_type) (target_type) value)) {\
                func_type zero = 0;\
                if (exc && unlikely(value == (func_type)-1 && PyErr_Occurred()))\
                    return (target_type) -1;\
                if (is_unsigned && unlikely(value < zero))\
                    goto raise_neg_overflow;\
                else\
                    goto raise_overflow;\
            }\
        }\
        return (target_type) value;\
    }

/* CIntToPy */
  static CYTHON_INLINE PyObject* __Pyx_PyInt_From_long(long value) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(long) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(long) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(long) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(long),
                                     little, !is_unsigned);
    }
}

/* CIntToPy */
  static CYTHON_INLINE PyObject* __Pyx_PyInt_From_unsigned_int(unsigned int value) {
    const unsigned int neg_one = (unsigned int) ((unsigned int) 0 - (unsigned int) 1), const_zero = (unsigned int) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(unsigned int) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(unsigned int) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(unsigned int) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(unsigned int) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(unsigned int) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(unsigned int),
                                     little, !is_unsigned);
    }
}

/* CIntToPy */
  static CYTHON_INLINE PyObject* __Pyx_PyInt_From_int(int value) {
    const int neg_one = (int) ((int) 0 - (int) 1), const_zero = (int) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(int) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(int) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(int) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(int),
                                     little, !is_unsigned);
    }
}

/* Declarations */
  #if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      return ::std::complex< float >(x, y);
    }
  #else
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      return x + y*(__pyx_t_float_complex)_Complex_I;
    }
  #endif
#else
    static CYTHON_INLINE __pyx_t_float_complex __pyx_t_float_complex_from_parts(float x, float y) {
      __pyx_t_float_complex z;
      z.real = x;
      z.imag = y;
      return z;
    }
#endif

/* Arithmetic */
  #if CYTHON_CCOMPLEX
#else
    static CYTHON_INLINE int __Pyx_c_eq_float(__pyx_t_float_complex a, __pyx_t_float_complex b) {
       return (a.real == b.real) && (a.imag == b.imag);
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_sum_float(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real + b.real;
        z.imag = a.imag + b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_diff_float(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real - b.real;
        z.imag = a.imag - b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_prod_float(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        __pyx_t_float_complex z;
        z.real = a.real * b.real - a.imag * b.imag;
        z.imag = a.real * b.imag + a.imag * b.real;
        return z;
    }
    #if 1
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_quot_float(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        if (b.imag == 0) {
            return __pyx_t_float_complex_from_parts(a.real / b.real, a.imag / b.real);
        } else if (fabsf(b.real) >= fabsf(b.imag)) {
            if (b.real == 0 && b.imag == 0) {
                return __pyx_t_float_complex_from_parts(a.real / b.real, a.imag / b.imag);
            } else {
                float r = b.imag / b.real;
                float s = (float)(1.0) / (b.real + b.imag * r);
                return __pyx_t_float_complex_from_parts(
                    (a.real + a.imag * r) * s, (a.imag - a.real * r) * s);
            }
        } else {
            float r = b.real / b.imag;
            float s = (float)(1.0) / (b.imag + b.real * r);
            return __pyx_t_float_complex_from_parts(
                (a.real * r + a.imag) * s, (a.imag * r - a.real) * s);
        }
    }
    #else
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_quot_float(__pyx_t_float_complex a, __pyx_t_float_complex b) {
        if (b.imag == 0) {
            return __pyx_t_float_complex_from_parts(a.real / b.real, a.imag / b.real);
        } else {
            float denom = b.real * b.real + b.imag * b.imag;
            return __pyx_t_float_complex_from_parts(
                (a.real * b.real + a.imag * b.imag) / denom,
                (a.imag * b.real - a.real * b.imag) / denom);
        }
    }
    #endif
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_neg_float(__pyx_t_float_complex a) {
        __pyx_t_float_complex z;
        z.real = -a.real;
        z.imag = -a.imag;
        return z;
    }
    static CYTHON_INLINE int __Pyx_c_is_zero_float(__pyx_t_float_complex a) {
       return (a.real == 0) && (a.imag == 0);
    }
    static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_conj_float(__pyx_t_float_complex a) {
        __pyx_t_float_complex z;
        z.real =  a.real;
        z.imag = -a.imag;
        return z;
    }
    #if 1
        static CYTHON_INLINE float __Pyx_c_abs_float(__pyx_t_float_complex z) {
          #if !defined(HAVE_HYPOT) || defined(_MSC_VER)
            return sqrtf(z.real*z.real + z.imag*z.imag);
          #else
            return hypotf(z.real, z.imag);
          #endif
        }
        static CYTHON_INLINE __pyx_t_float_complex __Pyx_c_pow_float(__pyx_t_float_complex a, __pyx_t_float_complex b) {
            __pyx_t_float_complex z;
            float r, lnr, theta, z_r, z_theta;
            if (b.imag == 0 && b.real == (int)b.real) {
                if (b.real < 0) {
                    float denom = a.real * a.real + a.imag * a.imag;
                    a.real = a.real / denom;
                    a.imag = -a.imag / denom;
                    b.real = -b.real;
                }
                switch ((int)b.real) {
                    case 0:
                        z.real = 1;
                        z.imag = 0;
                        return z;
                    case 1:
                        return a;
                    case 2:
                        return __Pyx_c_prod_float(a, a);
                    case 3:
                        z = __Pyx_c_prod_float(a, a);
                        return __Pyx_c_prod_float(z, a);
                    case 4:
                        z = __Pyx_c_prod_float(a, a);
                        return __Pyx_c_prod_float(z, z);
                }
            }
            if (a.imag == 0) {
                if (a.real == 0) {
                    return a;
                } else if (b.imag == 0) {
                    z.real = powf(a.real, b.real);
                    z.imag = 0;
                    return z;
                } else if (a.real > 0) {
                    r = a.real;
                    theta = 0;
                } else {
                    r = -a.real;
                    theta = atan2f(0.0, -1.0);
                }
            } else {
                r = __Pyx_c_abs_float(a);
                theta = atan2f(a.imag, a.real);
            }
            lnr = logf(r);
            z_r = expf(lnr * b.real - theta * b.imag);
            z_theta = theta * b.real + lnr * b.imag;
            z.real = z_r * cosf(z_theta);
            z.imag = z_r * sinf(z_theta);
            return z;
        }
    #endif
#endif

/* Declarations */
  #if CYTHON_CCOMPLEX
  #ifdef __cplusplus
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      return ::std::complex< double >(x, y);
    }
  #else
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      return x + y*(__pyx_t_double_complex)_Complex_I;
    }
  #endif
#else
    static CYTHON_INLINE __pyx_t_double_complex __pyx_t_double_complex_from_parts(double x, double y) {
      __pyx_t_double_complex z;
      z.real = x;
      z.imag = y;
      return z;
    }
#endif

/* Arithmetic */
  #if CYTHON_CCOMPLEX
#else
    static CYTHON_INLINE int __Pyx_c_eq_double(__pyx_t_double_complex a, __pyx_t_double_complex b) {
       return (a.real == b.real) && (a.imag == b.imag);
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_sum_double(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real + b.real;
        z.imag = a.imag + b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_diff_double(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real - b.real;
        z.imag = a.imag - b.imag;
        return z;
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_prod_double(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        __pyx_t_double_complex z;
        z.real = a.real * b.real - a.imag * b.imag;
        z.imag = a.real * b.imag + a.imag * b.real;
        return z;
    }
    #if 1
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_quot_double(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        if (b.imag == 0) {
            return __pyx_t_double_complex_from_parts(a.real / b.real, a.imag / b.real);
        } else if (fabs(b.real) >= fabs(b.imag)) {
            if (b.real == 0 && b.imag == 0) {
                return __pyx_t_double_complex_from_parts(a.real / b.real, a.imag / b.imag);
            } else {
                double r = b.imag / b.real;
                double s = (double)(1.0) / (b.real + b.imag * r);
                return __pyx_t_double_complex_from_parts(
                    (a.real + a.imag * r) * s, (a.imag - a.real * r) * s);
            }
        } else {
            double r = b.real / b.imag;
            double s = (double)(1.0) / (b.imag + b.real * r);
            return __pyx_t_double_complex_from_parts(
                (a.real * r + a.imag) * s, (a.imag * r - a.real) * s);
        }
    }
    #else
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_quot_double(__pyx_t_double_complex a, __pyx_t_double_complex b) {
        if (b.imag == 0) {
            return __pyx_t_double_complex_from_parts(a.real / b.real, a.imag / b.real);
        } else {
            double denom = b.real * b.real + b.imag * b.imag;
            return __pyx_t_double_complex_from_parts(
                (a.real * b.real + a.imag * b.imag) / denom,
                (a.imag * b.real - a.real * b.imag) / denom);
        }
    }
    #endif
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_neg_double(__pyx_t_double_complex a) {
        __pyx_t_double_complex z;
        z.real = -a.real;
        z.imag = -a.imag;
        return z;
    }
    static CYTHON_INLINE int __Pyx_c_is_zero_double(__pyx_t_double_complex a) {
       return (a.real == 0) && (a.imag == 0);
    }
    static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_conj_double(__pyx_t_double_complex a) {
        __pyx_t_double_complex z;
        z.real =  a.real;
        z.imag = -a.imag;
        return z;
    }
    #if 1
        static CYTHON_INLINE double __Pyx_c_abs_double(__pyx_t_double_complex z) {
          #if !defined(HAVE_HYPOT) || defined(_MSC_VER)
            return sqrt(z.real*z.real + z.imag*z.imag);
          #else
            return hypot(z.real, z.imag);
          #endif
        }
        static CYTHON_INLINE __pyx_t_double_complex __Pyx_c_pow_double(__pyx_t_double_complex a, __pyx_t_double_complex b) {
            __pyx_t_double_complex z;
            double r, lnr, theta, z_r, z_theta;
            if (b.imag == 0 && b.real == (int)b.real) {
                if (b.real < 0) {
                    double denom = a.real * a.real + a.imag * a.imag;
                    a.real = a.real / denom;
                    a.imag = -a.imag / denom;
                    b.real = -b.real;
                }
                switch ((int)b.real) {
                    case 0:
                        z.real = 1;
                        z.imag = 0;
                        return z;
                    case 1:
                        return a;
                    case 2:
                        return __Pyx_c_prod_double(a, a);
                    case 3:
                        z = __Pyx_c_prod_double(a, a);
                        return __Pyx_c_prod_double(z, a);
                    case 4:
                        z = __Pyx_c_prod_double(a, a);
                        return __Pyx_c_prod_double(z, z);
                }
            }
            if (a.imag == 0) {
                if (a.real == 0) {
                    return a;
                } else if (b.imag == 0) {
                    z.real = pow(a.real, b.real);
                    z.imag = 0;
                    return z;
                } else if (a.real > 0) {
                    r = a.real;
                    theta = 0;
                } else {
                    r = -a.real;
                    theta = atan2(0.0, -1.0);
                }
            } else {
                r = __Pyx_c_abs_double(a);
                theta = atan2(a.imag, a.real);
            }
            lnr = log(r);
            z_r = exp(lnr * b.real - theta * b.imag);
            z_theta = theta * b.real + lnr * b.imag;
            z.real = z_r * cos(z_theta);
            z.imag = z_r * sin(z_theta);
            return z;
        }
    #endif
#endif

/* CIntToPy */
  static CYTHON_INLINE PyObject* __Pyx_PyInt_From_enum__NPY_TYPES(enum NPY_TYPES value) {
    const enum NPY_TYPES neg_one = (enum NPY_TYPES) ((enum NPY_TYPES) 0 - (enum NPY_TYPES) 1), const_zero = (enum NPY_TYPES) 0;
    const int is_unsigned = neg_one > const_zero;
    if (is_unsigned) {
        if (sizeof(enum NPY_TYPES) < sizeof(long)) {
            return PyInt_FromLong((long) value);
        } else if (sizeof(enum NPY_TYPES) <= sizeof(unsigned long)) {
            return PyLong_FromUnsignedLong((unsigned long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(enum NPY_TYPES) <= sizeof(unsigned PY_LONG_LONG)) {
            return PyLong_FromUnsignedLongLong((unsigned PY_LONG_LONG) value);
#endif
        }
    } else {
        if (sizeof(enum NPY_TYPES) <= sizeof(long)) {
            return PyInt_FromLong((long) value);
#ifdef HAVE_LONG_LONG
        } else if (sizeof(enum NPY_TYPES) <= sizeof(PY_LONG_LONG)) {
            return PyLong_FromLongLong((PY_LONG_LONG) value);
#endif
        }
    }
    {
        int one = 1; int little = (int)*(unsigned char *)&one;
        unsigned char *bytes = (unsigned char *)&value;
        return _PyLong_FromByteArray(bytes, sizeof(enum NPY_TYPES),
                                     little, !is_unsigned);
    }
}

/* CIntFromPy */
  static CYTHON_INLINE unsigned int __Pyx_PyInt_As_unsigned_int(PyObject *x) {
    const unsigned int neg_one = (unsigned int) ((unsigned int) 0 - (unsigned int) 1), const_zero = (unsigned int) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(unsigned int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(unsigned int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (unsigned int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (unsigned int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(unsigned int, digit, digits[0])
                case 2:
                    if (8 * sizeof(unsigned int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) >= 2 * PyLong_SHIFT) {
                            return (unsigned int) (((((unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(unsigned int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) >= 3 * PyLong_SHIFT) {
                            return (unsigned int) (((((((unsigned int)digits[2]) << PyLong_SHIFT) | (unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(unsigned int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) >= 4 * PyLong_SHIFT) {
                            return (unsigned int) (((((((((unsigned int)digits[3]) << PyLong_SHIFT) | (unsigned int)digits[2]) << PyLong_SHIFT) | (unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (unsigned int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(unsigned int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(unsigned int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(unsigned int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(unsigned int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (unsigned int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(unsigned int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(unsigned int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(unsigned int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) - 1 > 2 * PyLong_SHIFT) {
                            return (unsigned int) (((unsigned int)-1)*(((((unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(unsigned int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) - 1 > 2 * PyLong_SHIFT) {
                            return (unsigned int) ((((((unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(unsigned int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) - 1 > 3 * PyLong_SHIFT) {
                            return (unsigned int) (((unsigned int)-1)*(((((((unsigned int)digits[2]) << PyLong_SHIFT) | (unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(unsigned int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) - 1 > 3 * PyLong_SHIFT) {
                            return (unsigned int) ((((((((unsigned int)digits[2]) << PyLong_SHIFT) | (unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(unsigned int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) - 1 > 4 * PyLong_SHIFT) {
                            return (unsigned int) (((unsigned int)-1)*(((((((((unsigned int)digits[3]) << PyLong_SHIFT) | (unsigned int)digits[2]) << PyLong_SHIFT) | (unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(unsigned int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(unsigned int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(unsigned int) - 1 > 4 * PyLong_SHIFT) {
                            return (unsigned int) ((((((((((unsigned int)digits[3]) << PyLong_SHIFT) | (unsigned int)digits[2]) << PyLong_SHIFT) | (unsigned int)digits[1]) << PyLong_SHIFT) | (unsigned int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(unsigned int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(unsigned int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(unsigned int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(unsigned int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            unsigned int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (unsigned int) -1;
        }
    } else {
        unsigned int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (unsigned int) -1;
        val = __Pyx_PyInt_As_unsigned_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to unsigned int");
    return (unsigned int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to unsigned int");
    return (unsigned int) -1;
}

/* CIntFromPy */
  static CYTHON_INLINE int __Pyx_PyInt_As_int(PyObject *x) {
    const int neg_one = (int) ((int) 0 - (int) 1), const_zero = (int) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(int) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(int, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (int) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case  1: __PYX_VERIFY_RETURN_INT(int, digit, digits[0])
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 2 * PyLong_SHIFT) {
                            return (int) (((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 3 * PyLong_SHIFT) {
                            return (int) (((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) >= 4 * PyLong_SHIFT) {
                            return (int) (((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (int) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(int) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (int) 0;
                case -1: __PYX_VERIFY_RETURN_INT(int, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(int,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(int) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(int) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                            return (int) ((((((int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(int) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(int) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                            return (int) ((((((((int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(int) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) (((int)-1)*(((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(int) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(int, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(int) - 1 > 4 * PyLong_SHIFT) {
                            return (int) ((((((((((int)digits[3]) << PyLong_SHIFT) | (int)digits[2]) << PyLong_SHIFT) | (int)digits[1]) << PyLong_SHIFT) | (int)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(int) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(int) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(int, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            int val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (int) -1;
        }
    } else {
        int val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (int) -1;
        val = __Pyx_PyInt_As_int(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to int");
    return (int) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to int");
    return (int) -1;
}

/* CIntFromPy */
  static CYTHON_INLINE long __Pyx_PyInt_As_long(PyObject *x) {
    const long neg_one = (long) ((long) 0 - (long) 1), const_zero = (long) 0;
    const int is_unsigned = neg_one > const_zero;
#if PY_MAJOR_VERSION < 3
    if (likely(PyInt_Check(x))) {
        if (sizeof(long) < sizeof(long)) {
            __PYX_VERIFY_RETURN_INT(long, long, PyInt_AS_LONG(x))
        } else {
            long val = PyInt_AS_LONG(x);
            if (is_unsigned && unlikely(val < 0)) {
                goto raise_neg_overflow;
            }
            return (long) val;
        }
    } else
#endif
    if (likely(PyLong_Check(x))) {
        if (is_unsigned) {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case  1: __PYX_VERIFY_RETURN_INT(long, digit, digits[0])
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 2 * PyLong_SHIFT) {
                            return (long) (((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 3 * PyLong_SHIFT) {
                            return (long) (((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) >= 4 * PyLong_SHIFT) {
                            return (long) (((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0]));
                        }
                    }
                    break;
            }
#endif
#if CYTHON_COMPILING_IN_CPYTHON
            if (unlikely(Py_SIZE(x) < 0)) {
                goto raise_neg_overflow;
            }
#else
            {
                int result = PyObject_RichCompareBool(x, Py_False, Py_LT);
                if (unlikely(result < 0))
                    return (long) -1;
                if (unlikely(result == 1))
                    goto raise_neg_overflow;
            }
#endif
            if (sizeof(long) <= sizeof(unsigned long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned long, PyLong_AsUnsignedLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(unsigned PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, unsigned PY_LONG_LONG, PyLong_AsUnsignedLongLong(x))
#endif
            }
        } else {
#if CYTHON_USE_PYLONG_INTERNALS
            const digit* digits = ((PyLongObject*)x)->ob_digit;
            switch (Py_SIZE(x)) {
                case  0: return (long) 0;
                case -1: __PYX_VERIFY_RETURN_INT(long, sdigit, (sdigit) (-(sdigit)digits[0]))
                case  1: __PYX_VERIFY_RETURN_INT(long,  digit, +digits[0])
                case -2:
                    if (8 * sizeof(long) - 1 > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 2:
                    if (8 * sizeof(long) > 1 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 2 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                            return (long) ((((((long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -3:
                    if (8 * sizeof(long) - 1 > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 3:
                    if (8 * sizeof(long) > 2 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 3 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                            return (long) ((((((((long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case -4:
                    if (8 * sizeof(long) - 1 > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, long, -(long) (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) (((long)-1)*(((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
                case 4:
                    if (8 * sizeof(long) > 3 * PyLong_SHIFT) {
                        if (8 * sizeof(unsigned long) > 4 * PyLong_SHIFT) {
                            __PYX_VERIFY_RETURN_INT(long, unsigned long, (((((((((unsigned long)digits[3]) << PyLong_SHIFT) | (unsigned long)digits[2]) << PyLong_SHIFT) | (unsigned long)digits[1]) << PyLong_SHIFT) | (unsigned long)digits[0])))
                        } else if (8 * sizeof(long) - 1 > 4 * PyLong_SHIFT) {
                            return (long) ((((((((((long)digits[3]) << PyLong_SHIFT) | (long)digits[2]) << PyLong_SHIFT) | (long)digits[1]) << PyLong_SHIFT) | (long)digits[0])));
                        }
                    }
                    break;
            }
#endif
            if (sizeof(long) <= sizeof(long)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, long, PyLong_AsLong(x))
#ifdef HAVE_LONG_LONG
            } else if (sizeof(long) <= sizeof(PY_LONG_LONG)) {
                __PYX_VERIFY_RETURN_INT_EXC(long, PY_LONG_LONG, PyLong_AsLongLong(x))
#endif
            }
        }
        {
#if CYTHON_COMPILING_IN_PYPY && !defined(_PyLong_AsByteArray)
            PyErr_SetString(PyExc_RuntimeError,
                            "_PyLong_AsByteArray() not available in PyPy, cannot convert large numbers");
#else
            long val;
            PyObject *v = __Pyx_PyNumber_IntOrLong(x);
 #if PY_MAJOR_VERSION < 3
            if (likely(v) && !PyLong_Check(v)) {
                PyObject *tmp = v;
                v = PyNumber_Long(tmp);
                Py_DECREF(tmp);
            }
 #endif
            if (likely(v)) {
                int one = 1; int is_little = (int)*(unsigned char *)&one;
                unsigned char *bytes = (unsigned char *)&val;
                int ret = _PyLong_AsByteArray((PyLongObject *)v,
                                              bytes, sizeof(val),
                                              is_little, !is_unsigned);
                Py_DECREF(v);
                if (likely(!ret))
                    return val;
            }
#endif
            return (long) -1;
        }
    } else {
        long val;
        PyObject *tmp = __Pyx_PyNumber_IntOrLong(x);
        if (!tmp) return (long) -1;
        val = __Pyx_PyInt_As_long(tmp);
        Py_DECREF(tmp);
        return val;
    }
raise_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "value too large to convert to long");
    return (long) -1;
raise_neg_overflow:
    PyErr_SetString(PyExc_OverflowError,
        "can't convert negative value to long");
    return (long) -1;
}

/* FastTypeChecks */
  #if CYTHON_COMPILING_IN_CPYTHON
static int __Pyx_InBases(PyTypeObject *a, PyTypeObject *b) {
    while (a) {
        a = a->tp_base;
        if (a == b)
            return 1;
    }
    return b == &PyBaseObject_Type;
}
static CYTHON_INLINE int __Pyx_IsSubtype(PyTypeObject *a, PyTypeObject *b) {
    PyObject *mro;
    if (a == b) return 1;
    mro = a->tp_mro;
    if (likely(mro)) {
        Py_ssize_t i, n;
        n = PyTuple_GET_SIZE(mro);
        for (i = 0; i < n; i++) {
            if (PyTuple_GET_ITEM(mro, i) == (PyObject *)b)
                return 1;
        }
        return 0;
    }
    return __Pyx_InBases(a, b);
}
#if PY_MAJOR_VERSION == 2
static int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject* exc_type2) {
    PyObject *exception, *value, *tb;
    int res;
    __Pyx_PyThreadState_declare
    __Pyx_PyThreadState_assign
    __Pyx_ErrFetch(&exception, &value, &tb);
    res = exc_type1 ? PyObject_IsSubclass(err, exc_type1) : 0;
    if (unlikely(res == -1)) {
        PyErr_WriteUnraisable(err);
        res = 0;
    }
    if (!res) {
        res = PyObject_IsSubclass(err, exc_type2);
        if (unlikely(res == -1)) {
            PyErr_WriteUnraisable(err);
            res = 0;
        }
    }
    __Pyx_ErrRestore(exception, value, tb);
    return res;
}
#else
static CYTHON_INLINE int __Pyx_inner_PyErr_GivenExceptionMatches2(PyObject *err, PyObject* exc_type1, PyObject *exc_type2) {
    int res = exc_type1 ? __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type1) : 0;
    if (!res) {
        res = __Pyx_IsSubtype((PyTypeObject*)err, (PyTypeObject*)exc_type2);
    }
    return res;
}
#endif
static int __Pyx_PyErr_GivenExceptionMatchesTuple(PyObject *exc_type, PyObject *tuple) {
    Py_ssize_t i, n;
    assert(PyExceptionClass_Check(exc_type));
    n = PyTuple_GET_SIZE(tuple);
#if PY_MAJOR_VERSION >= 3
    for (i=0; i<n; i++) {
        if (exc_type == PyTuple_GET_ITEM(tuple, i)) return 1;
    }
#endif
    for (i=0; i<n; i++) {
        PyObject *t = PyTuple_GET_ITEM(tuple, i);
        #if PY_MAJOR_VERSION < 3
        if (likely(exc_type == t)) return 1;
        #endif
        if (likely(PyExceptionClass_Check(t))) {
            if (__Pyx_inner_PyErr_GivenExceptionMatches2(exc_type, NULL, t)) return 1;
        } else {
        }
    }
    return 0;
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches(PyObject *err, PyObject* exc_type) {
    if (likely(err == exc_type)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        if (likely(PyExceptionClass_Check(exc_type))) {
            return __Pyx_inner_PyErr_GivenExceptionMatches2(err, NULL, exc_type);
        } else if (likely(PyTuple_Check(exc_type))) {
            return __Pyx_PyErr_GivenExceptionMatchesTuple(err, exc_type);
        } else {
        }
    }
    return PyErr_GivenExceptionMatches(err, exc_type);
}
static CYTHON_INLINE int __Pyx_PyErr_GivenExceptionMatches2(PyObject *err, PyObject *exc_type1, PyObject *exc_type2) {
    assert(PyExceptionClass_Check(exc_type1));
    assert(PyExceptionClass_Check(exc_type2));
    if (likely(err == exc_type1 || err == exc_type2)) return 1;
    if (likely(PyExceptionClass_Check(err))) {
        return __Pyx_inner_PyErr_GivenExceptionMatches2(err, exc_type1, exc_type2);
    }
    return (PyErr_GivenExceptionMatches(err, exc_type1) || PyErr_GivenExceptionMatches(err, exc_type2));
}
#endif

/* CheckBinaryVersion */
  static int __Pyx_check_binary_version(void) {
    char ctversion[4], rtversion[4];
    PyOS_snprintf(ctversion, 4, "%d.%d", PY_MAJOR_VERSION, PY_MINOR_VERSION);
    PyOS_snprintf(rtversion, 4, "%s", Py_GetVersion());
    if (ctversion[0] != rtversion[0] || ctversion[2] != rtversion[2]) {
        char message[200];
        PyOS_snprintf(message, sizeof(message),
                      "compiletime version %s of module '%.100s' "
                      "does not match runtime version %s",
                      ctversion, __Pyx_MODULE_NAME, rtversion);
        return PyErr_WarnEx(NULL, message, 1);
    }
    return 0;
}

/* InitStrings */
  static int __Pyx_InitStrings(__Pyx_StringTabEntry *t) {
    while (t->p) {
        #if PY_MAJOR_VERSION < 3
        if (t->is_unicode) {
            *t->p = PyUnicode_DecodeUTF8(t->s, t->n - 1, NULL);
        } else if (t->intern) {
            *t->p = PyString_InternFromString(t->s);
        } else {
            *t->p = PyString_FromStringAndSize(t->s, t->n - 1);
        }
        #else
        if (t->is_unicode | t->is_str) {
            if (t->intern) {
                *t->p = PyUnicode_InternFromString(t->s);
            } else if (t->encoding) {
                *t->p = PyUnicode_Decode(t->s, t->n - 1, t->encoding, NULL);
            } else {
                *t->p = PyUnicode_FromStringAndSize(t->s, t->n - 1);
            }
        } else {
            *t->p = PyBytes_FromStringAndSize(t->s, t->n - 1);
        }
        #endif
        if (!*t->p)
            return -1;
        if (PyObject_Hash(*t->p) == -1)
            return -1;
        ++t;
    }
    return 0;
}

static CYTHON_INLINE PyObject* __Pyx_PyUnicode_FromString(const char* c_str) {
    return __Pyx_PyUnicode_FromStringAndSize(c_str, (Py_ssize_t)strlen(c_str));
}
static CYTHON_INLINE const char* __Pyx_PyObject_AsString(PyObject* o) {
    Py_ssize_t ignore;
    return __Pyx_PyObject_AsStringAndSize(o, &ignore);
}
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
#if !CYTHON_PEP393_ENABLED
static const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    char* defenc_c;
    PyObject* defenc = _PyUnicode_AsDefaultEncodedString(o, NULL);
    if (!defenc) return NULL;
    defenc_c = PyBytes_AS_STRING(defenc);
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    {
        char* end = defenc_c + PyBytes_GET_SIZE(defenc);
        char* c;
        for (c = defenc_c; c < end; c++) {
            if ((unsigned char) (*c) >= 128) {
                PyUnicode_AsASCIIString(o);
                return NULL;
            }
        }
    }
#endif
    *length = PyBytes_GET_SIZE(defenc);
    return defenc_c;
}
#else
static CYTHON_INLINE const char* __Pyx_PyUnicode_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
    if (unlikely(__Pyx_PyUnicode_READY(o) == -1)) return NULL;
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
    if (likely(PyUnicode_IS_ASCII(o))) {
        *length = PyUnicode_GET_LENGTH(o);
        return PyUnicode_AsUTF8(o);
    } else {
        PyUnicode_AsASCIIString(o);
        return NULL;
    }
#else
    return PyUnicode_AsUTF8AndSize(o, length);
#endif
}
#endif
#endif
static CYTHON_INLINE const char* __Pyx_PyObject_AsStringAndSize(PyObject* o, Py_ssize_t *length) {
#if __PYX_DEFAULT_STRING_ENCODING_IS_ASCII || __PYX_DEFAULT_STRING_ENCODING_IS_DEFAULT
    if (
#if PY_MAJOR_VERSION < 3 && __PYX_DEFAULT_STRING_ENCODING_IS_ASCII
            __Pyx_sys_getdefaultencoding_not_ascii &&
#endif
            PyUnicode_Check(o)) {
        return __Pyx_PyUnicode_AsStringAndSize(o, length);
    } else
#endif
#if (!CYTHON_COMPILING_IN_PYPY) || (defined(PyByteArray_AS_STRING) && defined(PyByteArray_GET_SIZE))
    if (PyByteArray_Check(o)) {
        *length = PyByteArray_GET_SIZE(o);
        return PyByteArray_AS_STRING(o);
    } else
#endif
    {
        char* result;
        int r = PyBytes_AsStringAndSize(o, &result, length);
        if (unlikely(r < 0)) {
            return NULL;
        } else {
            return result;
        }
    }
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrue(PyObject* x) {
   int is_true = x == Py_True;
   if (is_true | (x == Py_False) | (x == Py_None)) return is_true;
   else return PyObject_IsTrue(x);
}
static CYTHON_INLINE int __Pyx_PyObject_IsTrueAndDecref(PyObject* x) {
    int retval;
    if (unlikely(!x)) return -1;
    retval = __Pyx_PyObject_IsTrue(x);
    Py_DECREF(x);
    return retval;
}
static PyObject* __Pyx_PyNumber_IntOrLongWrongResultType(PyObject* result, const char* type_name) {
#if PY_MAJOR_VERSION >= 3
    if (PyLong_Check(result)) {
        if (PyErr_WarnFormat(PyExc_DeprecationWarning, 1,
                "__int__ returned non-int (type %.200s).  "
                "The ability to return an instance of a strict subclass of int "
                "is deprecated, and may be removed in a future version of Python.",
                Py_TYPE(result)->tp_name)) {
            Py_DECREF(result);
            return NULL;
        }
        return result;
    }
#endif
    PyErr_Format(PyExc_TypeError,
                 "__%.4s__ returned non-%.4s (type %.200s)",
                 type_name, type_name, Py_TYPE(result)->tp_name);
    Py_DECREF(result);
    return NULL;
}
static CYTHON_INLINE PyObject* __Pyx_PyNumber_IntOrLong(PyObject* x) {
#if CYTHON_USE_TYPE_SLOTS
  PyNumberMethods *m;
#endif
  const char *name = NULL;
  PyObject *res = NULL;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_Check(x) || PyLong_Check(x)))
#else
  if (likely(PyLong_Check(x)))
#endif
    return __Pyx_NewRef(x);
#if CYTHON_USE_TYPE_SLOTS
  m = Py_TYPE(x)->tp_as_number;
  #if PY_MAJOR_VERSION < 3
  if (m && m->nb_int) {
    name = "int";
    res = m->nb_int(x);
  }
  else if (m && m->nb_long) {
    name = "long";
    res = m->nb_long(x);
  }
  #else
  if (likely(m && m->nb_int)) {
    name = "int";
    res = m->nb_int(x);
  }
  #endif
#else
  if (!PyBytes_CheckExact(x) && !PyUnicode_CheckExact(x)) {
    res = PyNumber_Int(x);
  }
#endif
  if (likely(res)) {
#if PY_MAJOR_VERSION < 3
    if (unlikely(!PyInt_Check(res) && !PyLong_Check(res))) {
#else
    if (unlikely(!PyLong_CheckExact(res))) {
#endif
        return __Pyx_PyNumber_IntOrLongWrongResultType(res, name);
    }
  }
  else if (!PyErr_Occurred()) {
    PyErr_SetString(PyExc_TypeError,
                    "an integer is required");
  }
  return res;
}
static CYTHON_INLINE Py_ssize_t __Pyx_PyIndex_AsSsize_t(PyObject* b) {
  Py_ssize_t ival;
  PyObject *x;
#if PY_MAJOR_VERSION < 3
  if (likely(PyInt_CheckExact(b))) {
    if (sizeof(Py_ssize_t) >= sizeof(long))
        return PyInt_AS_LONG(b);
    else
        return PyInt_AsSsize_t(b);
  }
#endif
  if (likely(PyLong_CheckExact(b))) {
    #if CYTHON_USE_PYLONG_INTERNALS
    const digit* digits = ((PyLongObject*)b)->ob_digit;
    const Py_ssize_t size = Py_SIZE(b);
    if (likely(__Pyx_sst_abs(size) <= 1)) {
        ival = likely(size) ? digits[0] : 0;
        if (size == -1) ival = -ival;
        return ival;
    } else {
      switch (size) {
         case 2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -2:
           if (8 * sizeof(Py_ssize_t) > 2 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -3:
           if (8 * sizeof(Py_ssize_t) > 3 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case 4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return (Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
         case -4:
           if (8 * sizeof(Py_ssize_t) > 4 * PyLong_SHIFT) {
             return -(Py_ssize_t) (((((((((size_t)digits[3]) << PyLong_SHIFT) | (size_t)digits[2]) << PyLong_SHIFT) | (size_t)digits[1]) << PyLong_SHIFT) | (size_t)digits[0]));
           }
           break;
      }
    }
    #endif
    return PyLong_AsSsize_t(b);
  }
  x = PyNumber_Index(b);
  if (!x) return -1;
  ival = PyInt_AsSsize_t(x);
  Py_DECREF(x);
  return ival;
}
static CYTHON_INLINE PyObject * __Pyx_PyBool_FromLong(long b) {
  return b ? __Pyx_NewRef(Py_True) : __Pyx_NewRef(Py_False);
}
static CYTHON_INLINE PyObject * __Pyx_PyInt_FromSize_t(size_t ival) {
    return PyInt_FromSize_t(ival);
}


#endif /* Py_PYTHON_H */
