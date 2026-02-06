from setuptools import setup, Extension
from Cython.Build import cythonize

ext = Extension(
    name = 'solution',
    sources = ['solution.pyx'],
    language = 'c'
)

setup(
    ext_modules = cythonize(
        ext,
        language_level = 3
    )
)