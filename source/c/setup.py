from setuptools import setup, Extension
from Cython.Build import cythonize

# ============================================================
# 🧩 Define a C/Cython extension module
# ============================================================
# 🔹 name:
#     - Module name used for importing in Python
#     - Example: `from solution import cSolution`
#
# 🔹 sources:
#     - Cython source file(s) (.pyx)
#     - These will be converted to C automatically
#
# 🔹 language:
#     - 'c'   ➜ Generate C code
#     - 'c++' ➜ Use this when wrapping C++ code
# ============================================================
ext = Extension(
    name='solution',
    sources=['solution.pyx'],
    language='c'
)

# ============================================================
# ⚙️ Build & Install Configuration
# ============================================================
# 🛠️ cythonize:
#     - Translates `.pyx` → `.c`
#     - Compiles C code into a shared library (.so / .pyd)
#
# 🐍 language_level=3:
#     - Enforces Python 3 syntax in Cython
#     - Best practice for all modern projects
# ============================================================
setup(
    ext_modules=cythonize(
        ext,
        language_level=3
    )
)