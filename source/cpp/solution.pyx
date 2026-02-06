from libcpp.vector cimport vector

cdef extern from "solution.hpp":
    cdef cppclass Solution:
        Solution() except + 
        int canCompleteCircuit(vector[int]& gas, vector[int]& cost)

cdef class cppSolution:
    cdef Solution *ptr

    def __cinit__(self): self.ptr = new Solution()
    def __dealloc__(self): del(self.ptr)

    def cpp_canCompleteCircuit(self, gas, cost):
        if len(gas) != len(cost):
            raise MemoryError("gas and cost must be of same length")

        cdef vector[int] gasArray
        cdef vector[int] costArray
        cdef int i

        try:
            for i in range(len(gas)):
                gasArray.push_back(gas[i])
                costArray.push_back(cost[i])
            
            if gasArray.empty() or costArray.empty():
                raise MemoryError("Memory Allocation Failed")
            
            return self.ptr.canCompleteCircuit(gas, cost)
        finally:
            vector[int]().swap(gasArray)
            vector[int]().swap(costArray)
        