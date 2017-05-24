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


/**
 * Calculates the mean of a given list of integers
 */
static PyObject *
mean (PyObject *self, PyObject *args)
{
    PyObject* list_obj;
    PyObject* sequence;
    PyObject* item;

    if (!PyArg_ParseTuple(args, "O", &list_obj)) {
        return NULL;
    }

    sequence = PySequence_Fast(list_obj, "Expected a list object");
    int seq_size = PySequence_Size(list_obj);

    long sum = -1;
    for(int i = 0; i < seq_size; i++) {

        item = PySequence_Fast_GET_ITEM(sequence, i);
        sum += _PyLong_AsInt(item);
    }

    Py_DECREF(sequence);

    return Py_BuildValue("i", sum / seq_size);
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
