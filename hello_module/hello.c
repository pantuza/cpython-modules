/*
 * ============================================================================
 *
 *       Filename:  hello.c
 *
 *    Description:  Basic hello world of a C module for Python language
 *
 *        Version:  0.1
 *        Created:  05/15/2017 12:49:00
 *       Compiler:  gcc
 *
 *         Author:  Gustavo Pantuza (gustavopantuza@gmail.com)
 *   Organization:  Computer Science community
 *
 * ============================================================================
 */


#include <Python.h>


/**
 * Hello world function that returns a reference to a str Python object
 */
static PyObject *
hello (PyObject *self)
{
    return Py_BuildValue("s", "Hello Pythonista");
}


static char hello_docstring[] = "Hello world module for Python written in C";

static PyMethodDef module_methods[] = {
    {"hello", (PyCFunction) hello, METH_NOARGS, hello_docstring},
    {NULL, NULL, 0, NULL}
};


PyMODINIT_FUNC
initmodule(void)
{
    Py_InitModule("module", module_methods);
}
