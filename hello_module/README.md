# Hello Module

This module is a simple function `hello` that returns a `string` saying "Hello Pythonista".
You can try it by getting a shell inside a container:

```bash
$> docker run -it --rm cpython:local
```

> Make sure to build the docker image as shown in the Readme.md file from the root directory

Once you get a shell on the container, go to `hello_module` directory to compile the module:

```bash
/cpython # cd hello_module/
/cpython/hello_module # python setup.py install
running install
running build
running build_ext
running install_lib
copying build/lib.linux-x86_64-3.8/module.cpython-38-x86_64-linux-gnu.so -> /usr/local/lib/python3.8/site-packages
running install_egg_info
Writing /usr/local/lib/python3.8/site-packages/module-1.0-py3.8.egg-info
```

Now the module is installed on the Python path. Thus, open a python shell to try using it:

```bash
/cpython/hello_module # ipython
Python 3.8.4 (default, Jul 14 2020, 03:18:03)
Type 'copyright', 'credits' or 'license' for more information
IPython 7.16.1 -- An enhanced Interactive Python. Type '?' for help.

In [1]: from module import hello

In [2]: hello()
Out[2]: 'Hello Pythonista'

In [3]: type(hello())
Out[3]: str

In [4]: help(hello)
Help on built-in function hello in module module:

hello(...)
    Hello world module for Python written in C


In [5]: dir(hello)
Out[5]:
['__call__',
 '__class__',
 '__delattr__',
 '__dir__',
 '__doc__',
 '__eq__',
 '__format__',
 '__ge__',
 '__getattribute__',
 '__gt__',
 '__hash__',
 '__init__',
 '__init_subclass__',
 '__le__',
 '__lt__',
 '__module__',
 '__name__',
 '__ne__',
 '__new__',
 '__qualname__',
 '__reduce__',
 '__reduce_ex__',
 '__repr__',
 '__self__',
 '__setattr__',
 '__sizeof__',
 '__str__',
 '__subclasshook__',
 '__text_signature__']
```

## Recap

* You saw how to create a simple module
* You learned how to compile the module
* You understood how to use functions from the module
* You saw that functions from the module return Python types
