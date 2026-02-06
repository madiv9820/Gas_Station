import unittest
from timeout_decorator import timeout
from source.python.solution import pySolution

class test_py_Solution(unittest.TestCase):
    def setUp(self):
        self.__testcases = (
            ([1,2,3,4,5], [3,4,5,1,2], 3),
            ([2,3,4], [3,4,3], -1)
        )
        self.__solution = pySolution()
        return super().setUp()
    
    @timeout(1)
    def test(self):
        for gas, cost, expectedOutput in self.__testcases:
            with self.subTest(gas, cost):
                actualOutput = self.__solution.py_canCompleteCircuit(gas, cost)
                self.assertEqual(actualOutput, expectedOutput)