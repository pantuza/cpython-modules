from os import remove
from os.path import exists

from statistics import mean
from statistics import stdev


input_logs = {
    "mean": "mean.log",
    "mode": "mode.log",
    "median": "median.log"
}


output_logs = {
    "mean": "summary_mean.log",
    "mode": "summary_mode.log",
    "median": "summary_median.log"
}


def check_files():
    """ Checks if log files exists """
    print("Checking input files..")
    for file_name in input_logs.values():
        if not exists(file_name):
            raise FileNotFoundError("Missing log file: %s" % file_name)


def clear_logs():
    """ Clear logs from previous executions """

    print("Cleaning output log files..")
    for file_name in output_logs.values():
        try:
            remove(file_name)
        except FileNotFoundError:
            pass


def calculate(input, output):
    """ Loads log files data and calculates mean and standard deviation """
    t0_values = []
    t1_values = []

    for line in input:
        t0, t1 = line.split()

        t0_values.append(float(t0))
        t1_values.append(float(t1))

    calc_mean(t0_values, t1_values, output)
    calc_stddev(t0_values, t1_values, output)


def calc_mean(t0_values, t1_values, output):
    """ Calculates mean of the values """

    t0_mean = mean(t0_values)
    t1_mean = mean(t1_values)

    output.write("%.2f %.2f " % (t0_mean, t1_mean))


def calc_stddev(t0_values, t1_values, output):
    """ Calculates standard deviation of the values """

    t0_stddev = stdev(t0_values)
    t1_stddev = stdev(t1_values)

    output.write("%.2f %.2f\n" % (t0_stddev, t1_stddev))


def compute():
    """ Compute mean of the given values """

    for key in input_logs:

        print("Starting calculation for %s.." % key)
        input = open(input_logs[key], "r")
        output = open(output_logs[key], "a")

        calculate(input, output)
    print("Calculation done!")


if __name__ == "__main__":
    check_files()
    clear_logs()
    compute()
