from typing import List

class pySolution(object):
    def py_canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        totalGas: int = sum(gas)    # ⛽ totalGas: total fuel available across all stations
        totalCost: int = sum(cost)  # 💸 totalCost: total fuel required to complete the full circuit

        # 🚫 Global feasibility check
        # If total gas is less than total cost, no solution exists
        if totalGas < totalCost: return -1

        startPosition: int = 0  # 🚦 startPosition: candidate index to start the journey
        currentFuel: int = 0    # 🔋 currentFuel: fuel left while traversing from startPosition

        # 🔁 Single-pass greedy traversal
        for index in range(len(gas)):
            currentFuel += gas[index]   # ⛽ Collect gas at the current station

            # 💸 Check if we can reach the next station
            if currentFuel < cost[index]:
                # ❌ Cannot proceed from here
                # All stations between startPosition and index
                # are invalid starting points
                currentFuel = 0

                # ➡️ Next station becomes the new candidate start
                startPosition = index + 1
            else:
                # 🔥 Spend fuel to move to the next station
                currentFuel -= cost[index]

        # 🏁 Since totalGas >= totalCost,
        # this startPosition is guaranteed to work
        return startPosition