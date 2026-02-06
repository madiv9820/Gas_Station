from setuptools import setup, Extension
from Cython.Build import cythonize

# ============================================================
# 🧩 Define a C++ / Cython extension module
# ============================================================
# 🔹 name:
#     - Name of the compiled Python module
#     - Import example: `from solution import cppSolution`
#
# 🔹 sources:
#     - Cython source file(s) (.pyx)
#     - These will be translated to C++ by Cython
#
# 🔹 language:
#     - 'c++' tells the compiler to use a C++ compiler
#     - Required when wrapping C++ classes (e.g., std::vector)
# ============================================================
ext = Extension(
    name='solution',
    sources=['solution.pyx'],
    language='c++'
)

# ============================================================
# ⚙️ Build & Install Configuration
# ============================================================
# 🛠️ cythonize:
#     - Converts `.pyx` → `.cpp`
#     - Compiles the C++ code into a shared library (.so / .pyd)
#
# 🐍 language_level=3:
#     - Enforces Python 3 syntax in Cython
#     - Recommended for all modern Cython projects
# ============================================================
setup(
    ext_modules=cythonize(
        ext,
        language_level=3
    )
)