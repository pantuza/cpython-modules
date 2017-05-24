from distutils.core import setup
from distutils.core import Extension


setup(
    name='module',
    version='1.0',
    ext_modules=[Extension('module', ['hello.c'])]
)
