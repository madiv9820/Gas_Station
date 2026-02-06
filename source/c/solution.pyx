from libc.stdlib cimport free, malloc

cdef extern from "solution.h":
    int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)

cdef class cSolution:
    def c_canCompleteCircuit(self, gas, cost):
        cdef int n = len(gas)
        cdef int i
        
        if n != len(cost):
            raise ValueError("gas and cost must be of same length")

        cdef int *gasArray = <int*> malloc(sizeof(int) * n)
        cdef int *costArray = <int*> malloc(sizeof(int) * n)

        if not gasArray or not costArray:
            raise MemoryError("Memory Allocation Failed")

        try:
            for i in range(n):
                gasArray[i] = <int> gas[i]
                costArray[i] = <int> cost[i]

            return canCompleteCircuit(gasArray, n, costArray, n)
        finally:
            free(gasArray)
            free(costArray)