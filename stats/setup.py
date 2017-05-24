from distutils.core import setup
from distutils.core import Extension


setup(
    name='stats',
    version='0.1',
    ext_modules=[Extension('stats', ['stats.c'])]
)
