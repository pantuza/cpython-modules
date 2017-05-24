import gc
from sys import stdout
from time import clock
from statistics import mean as py_mean

from stats import mean
from inputs import inputs


logs = {
    "mean": "mean.log",
    "mode": "mode.log",
    "median": "median.log"
}

def save_times(times, file_name):
    """ Writes the computed times in given file """

    with open(file_name, "a") as file:
        file.write(times)

    print >> stdout, times

def format_times(t0, t1):
    """ Formats the computed times """

    return "%f %f\n" % (abs(t0), abs(t1))

def compute_mean(input_list):
   """ Compute time execution of each module """

    begin_py_mean = clock()
    py_mean(input_list)
    end_py_mean = clock()

    begin_mean = clock()
    mean(input_list)
    end_mean = clock()

    times = format_times(end_py_mean - begin_py_mean, begin_mean - end_mean)
    save_times(times, logs['mean'])

def compute():
    """ Function to run computation experiment """

    gc_ref = gc.isenabled()
    gc.disable()

    try:

        for input_list in inputs:
            compute_mean(input_list)

    except Exception as e:
        raise e

    finally:
        if gc_ref:
            gc.enable()


if __name__ == "__main__":

    compute()
