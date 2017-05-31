# CPython Modules
This project aims to show examples of how to wrap C libraries into Python modules


### Installation
Each directory has it own ```setup.py``` file. You can install it using:

```bash
$> python setup.py install
```

## Modules

In this project we present two modules:

* Hello world module (python 2.7)
* Statistics module  (python 3.x)

### Hello world module
This module creates only one function that prints a 'hello world' message. 
After installing the module you can use it by:

```python
from module import hello

# Prints the hello message
hello()

# Shows the type of returning value
type(hello())

# Prints docstring
help(hello)

# Prints names in the function namespace
dir(hello)
```

### Statistics module
This module calculates **mean**, **mode** and **median** of a given list of integers.
After installing the module you can use it by:

```python
from stats import mean
from stats import mode
from stats import median

# Calculates mean
mean([20, 42, 1, 84, 55, 0, 38, 77, 5, 23, 46])

# Calculates mode
mode([1,2,2,2,2,2,3,4,5,6,7])

# Calculates median
median([1,2,3,4,5])
```

### Experiments

As an experiment we write a program ```stats/collect.py``` to generate 1000 lists with 1000 integers each.
Then we compute the time execution in microseconds, for each list, of the Pythoo stardard library *statistics* and the stats C module. Finally, we compute through ```stats/compute.py``` the mean and the stardard deviation of computed times and plot histogram with this values.

```python
for i, input_list in enumerate(inputs):
    print("input[%d]" % i)
    collect_mean(input_list)
    collect_mode(input_list)
    collect_median(input_list)
```

### Analysis



### Author

Gustavo Pantuza [https://blog.pantuza.com](https://blog.pantuza.com)

### License
This project is under [GNU Lesser General Public License v3.0](https://github.com/pantuza/cpython-modules/blob/master/LICENSE).
