from libc.stdlib cimport free, malloc
from cython cimport sizeof

# ============================================================
# 🔗 External C function declaration
# ============================================================
# This tells Cython:
# - The function is implemented in solution.h / solution.c
# - We are only declaring the signature here
# ============================================================
cdef extern from "solution.h":
    int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)

# ============================================================
# 🧩 Cython wrapper class for the C solution
# ============================================================
cdef class cSolution:
    def c_canCompleteCircuit(self, gas, cost):
        # 📏 Number of gas stations
        cdef int n = len(gas)
        cdef int i

        # ❌ Input validation
        if n != len(cost):
            raise ValueError("gas and cost must be of same length")

        # ====================================================
        # 🧠 Manual memory allocation (C-style)
        # ====================================================
        # Allocate memory for gas and cost arrays
        # sizeof(int) ensures correct byte allocation
        cdef int* gasArray = <int*> malloc(sizeof(int) * n)
        cdef int* costArray = <int*> malloc(sizeof(int) * n)

        # ❌ Check for allocation failure
        if gasArray == NULL or costArray == NULL:
            if gasArray != NULL:
                free(gasArray)
            if costArray != NULL:
                free(costArray)
            raise MemoryError("Memory Allocation Failed")

        try:
            # ====================================================
            # 🔄 Copy Python list → C array
            # ====================================================
            for i in range(n):
                gasArray[i] = <int> gas[i]
                costArray[i] = <int> cost[i]

            # 🚀 Call the C implementation
            return canCompleteCircuit(gasArray, n, costArray, n)

        finally:
            # ====================================================
            # 🧹 Free allocated memory (VERY IMPORTANT)
            # ====================================================
            free(gasArray)
            free(costArray)