import gc
from time import clock
from statistics import mean as py_mean
from statistics import mean as py_mode
from statistics import mean as py_median

from stats import mean
from stats import mode
from stats import median

from inputs import inputs


MICROSECS = 1000 * 1000


logs = {
    "mean": "mean.log",
    "mode": "mode.log",
    "median": "median.log"
}


def save_times(times, file_name):
    """ Writes the computed times in given file """

    with open(file_name, "a") as file:
        file.write(times)

    print(times)


def format_times(t0, t1):
    """ Formats the computed times """

    return "%.2f %.2f\n" % (t0 * MICROSECS, t1 * MICROSECS)


def compute_mean(input_list):
    """ Compute time execution of mean of each module """

    begin_py_mean = clock()
    py_mean(input_list)
    end_py_mean = clock()

    begin_mean = clock()
    mean(input_list)
    end_mean = clock()

    times = format_times(end_py_mean - begin_py_mean, end_mean - begin_mean)
    save_times(times, logs['mean'])


def compute_mode(input_list):
    """ Compute time execution of mode of each module """

    begin_py_mode = clock()
    py_mode(input_list)
    end_py_mode = clock()

    begin_mode = clock()
    mode(input_list)
    end_mode = clock()

    times = format_times(end_py_mode - begin_py_mode, end_mode - begin_mode)
    save_times(times, logs['mode'])


def compute_median(input_list):
    """ Compute time execution of median of each module """

    begin_py_median = clock()
    py_median(input_list)
    end_py_median = clock()

    begin_median = clock()
    median(input_list)
    end_median = clock()

    times = format_times(end_py_median - begin_py_median,
                         end_median - begin_median)
    save_times(times, logs['median'])


def compute():
    """ Function to run computation experiment """

    gc_ref = gc.isenabled()
    gc.disable()

    try:

        for input_list in inputs:
            compute_mean(input_list)
            compute_mode(input_list)
            compute_median(input_list)

    except Exception as e:
        raise e

    finally:
        if gc_ref:
            gc.enable()


if __name__ == "__main__":

    compute()
