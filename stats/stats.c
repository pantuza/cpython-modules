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


/**
 * Calculates the mode of a given list of integers
 */
static PyObject *
mode (PyObject *self, PyObject *args)
{
    PyObject* list_obj;
    PyObject* sequence;
    PyObject* item_i;
    PyObject* item_j;

    if (!PyArg_ParseTuple(args, "O", &list_obj)) {
        return NULL;
    }

    sequence = PySequence_Fast(list_obj, "Expected a list object");
    int seq_size = PySequence_Size(list_obj);

    long value = -1;
    int max_count = 0;
    for(int i = 0; i < seq_size; i++) {

        int count = 0;
        item_i = PySequence_Fast_GET_ITEM(sequence, i);

        for(int j = 0; j < seq_size; j++) {

            item_j = PySequence_Fast_GET_ITEM(sequence, j);
            if(_PyLong_AsInt(item_i) == _PyLong_AsInt(item_j)) {
                count++;
            }
        }

        if(count > max_count) {
            max_count = count;
            value = _PyLong_AsInt(item_i);
        }
    }
    Py_DECREF(sequence);

    return Py_BuildValue("i", value);
}


/**
 * Calculates the median of a given list of integers
 */
static PyObject *
median (PyObject *self, PyObject *args)
{
    PyObject* list_obj;
    PyObject* sequence;
    PyObject* item;

    if(!PyArg_ParseTuple(args, "O", &list_obj)) {

        return NULL;
    }

    sequence = PySequence_Fast(list_obj, "Expected a list object");
    int seq_size = PySequence_Size(list_obj);

    int median = -1;
    if(seq_size % 2 == 0) {

        int left = seq_size / 2 - 1;
        int right = seq_size / 2 + 1;

        item = PySequence_Fast_GET_ITEM(sequence, left);
        int l_int = _PyLong_AsInt(item);
        item = PySequence_Fast_GET_ITEM(sequence, right);
        int r_int = _PyLong_AsInt(item);

        median = (l_int + r_int) / 2;
    } else {
        int index = (seq_size + 1) / 2 - 1;
        item = PySequence_Fast_GET_ITEM(sequence, index);
        median = _PyLong_AsInt(item);
    }
    Py_DECREF(sequence);

    return Py_BuildValue("i", median);
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
