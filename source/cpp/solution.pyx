from libcpp.vector cimport vector

# ============================================================
# 🔗 External C++ class declaration
# ============================================================
cdef extern from "solution.hpp":
    cdef cppclass Solution:
        Solution() except +
        int canCompleteCircuit(vector[int]& gas, vector[int]& cost)

# ============================================================
# 🧩 Cython wrapper for the C++ Solution class
# ============================================================
cdef class cppSolution:
    cdef Solution* ptr

    def __cinit__(self):
        # 🏗️ Construct C++ object
        self.ptr = new Solution()

    def __dealloc__(self):
        # 🧹 Destroy C++ object
        del self.ptr

    def cpp_canCompleteCircuit(self, gas, cost):
        # ❌ Input validation
        if len(gas) != len(cost):
            raise ValueError("gas and cost must be of same length")

        # 📦 C++ vectors (RAII-managed)
        cdef vector[int] gasArray
        cdef vector[int] costArray
        cdef Py_ssize_t i, n = len(gas)

        # 🔄 Copy Python list → C++ vector
        for i in range(n):
            gasArray.push_back(<int> gas[i])
            costArray.push_back(<int> cost[i])

        # 🚀 Call C++ implementation
        return self.ptr.canCompleteCircuit(gasArray, costArray)