from os.path import exists

from statistics import mean


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
    for file_name in input_logs.values():
        if not exists(file_name):
            raise FileNotFoundError("Missing log file: %s" % file_name)


def calculate(input, output):
    pass


def calc_mean():
    pass


def calc_stddev():
    pass


def compute():
    """ Compute mean of the given values """

    for key in input_logs:

        input = open(input_logs[key], "r")
        output = open(output_logs[key], "a")

        calculate(input, output)


if __name__ == "__main__":
    check_files()
    compute()
