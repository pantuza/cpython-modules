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

/**
 * List of module methods
 */
static PyMethodDef module_methods[] = {
    {"hello", (PyCFunction) hello, METH_NOARGS, hello_docstring},
    {NULL}
};

static struct PyModuleDef module =
{
    PyModuleDef_HEAD_INIT,
    "module",
    "usage: module.create()\n",
    -1,   /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    module_methods
};

/**
 * Module inicialization function
 */
PyMODINIT_FUNC
PyInit_module(void)
{
    return PyModule_Create(&module);
}
