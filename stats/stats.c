/*
 * ============================================================================
 *
 *       Filename:  stats.c
 *
 *    Description:  Statistics module for Python written in C
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


static PyObject *
mean (PyObject *self, PyObject *args)
{
    Py_RETURN_NONE;
}


static PyObject *
mode (PyObject *self, PyObject *args)
{
    Py_RETURN_NONE;
}


static PyObject *
median (PyObject *self, PyObject *args)
{
    Py_RETURN_NONE;
}


static PyMethodDef module_methods[] = {
    {"mean", (PyCFunction) mean, METH_VARARGS, "Calculates mean"},
    {"mode", (PyCFunction) mode, METH_VARARGS, "Calculates mode"},
    {"median", (PyCFunction) median, METH_VARARGS, "Calculates median"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef statsmodule = {
    PyModuleDef_HEAD_INIT,
    "stats",    /* name of module */
    "Statistics module for Python written in C",  /* doc string, may be NULL */
    -1, /* size of per-interpreter state of the module,
           or -1 if the module keeps state in global variables */
    module_methods   /* methods table */
};

PyMODINIT_FUNC
PyInit_stats(void)
{
    return PyModule_Create(&statsmodule);
}
