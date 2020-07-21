# Statistics module


This module implements 3 functions of statistical computations.
They are:

* mean
* median
* mode

You can try it by getting a shell inside a container:

```bash
$> docker run -it --rm cpython:local
/cpython #
```

> Make sure to build the docker image as shown in the Readme.md file from the root directory

Once you get a shell on the container, go to `stats` directory to compile the module:

```bash
/cpython # cd stats/
/cpython/stats # python setup.py install
running install
running build
running build_ext
building 'stats' extension
creating build/temp.linux-x86_64-3.8
gcc -Wno-unused-result -Wsign-compare -DNDEBUG -g -fwrapv -O3 -Wall -DTHREAD_STACK_SIZE=0x100000 -fPIC -I/usr/local/include/python3.8 -c stats.c -o build/temp.linux-x86_64-3.8/stats.o
creating build/lib.linux-x86_64-3.8
gcc -shared -Wl,--strip-all build/temp.linux-x86_64-3.8/stats.o -L/usr/local/lib -o build/lib.linux-x86_64-3.8/stats.cpython-38-x86_64-linux-gnu.so
running install_lib
copying build/lib.linux-x86_64-3.8/stats.cpython-38-x86_64-linux-gnu.so -> /usr/local/lib/python3.8/site-packages
running install_egg_info
Writing /usr/local/lib/python3.8/site-packages/stats-0.1-py3.8.egg-info
```

Great, once the module is compiled you can now open a interactive Python shell
and try using the function from the builded module:

```bash
/cpython/stats # ipython
Python 3.8.4 (default, Jul 14 2020, 03:18:03)
Type 'copyright', 'credits' or 'license' for more information
IPython 7.16.1 -- An enhanced Interactive Python. Type '?' for help.

In [1]: from stats import mean

In [2]: mean([20, 42, 1, 84, 55, 0, 38, 77, 5, 23, 46])
Out[2]: 35

In [3]: from stats import mode

In [4]: mode([1,2,2,2,2,2,3,4,5,6,7])
Out[4]: 2

In [5]: from stats import median

In [6]: median([1,2,3,4,5])
Out[6]: 3
```

## Recap

* You saw how to create a stats module
* You learned how to compile the module
* You understood how to use functions from the module
* You saw that functions from the module return Python types
