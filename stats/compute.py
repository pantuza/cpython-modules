import gc
from time import clock
from statistics import mean as py_mean

from stats import mean
from inputs import inputs


logs = {
    "mean": "mean.log",
    "mode": "mode.log",
    "median": "median.log"
}

def compute():
    """ Function to run computation experiment """

    gc_ref = gc.isenabled()
    gc.disable()

    try:

        for input_list in inputs:

            begin_py_mean = clock()
            py_mean(input_list)
            end_py_mean = clock()

            begin_mean = clock()
            mean(input_list)
            end_mean = clock()

            with open(logs['mean'], "a") as file:
                file.write("%f %f\n" % (
                        abs(end_py_mean - begin_py_mean),
                        abs(begin_mean - end_mean)
                    )
                )
    except Exception as e:
        raise e

    finally:
        if gc_ref:
            gc.enable()


if __name__ == "__main__":

    compute()
