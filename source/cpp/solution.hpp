#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
#include <numeric>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // Uses STL accumulate for clean and expressive code
        int totalGas = accumulate(gas.begin(), gas.end(), 0);       // ⛽ totalGas: sum of gas available across all stations
        int totalCost = accumulate(cost.begin(), cost.end(), 0);    // 💸 totalCost: total fuel required to travel the entire circuit

        // 🚫 Global feasibility check:
        // If total gas is less than total cost, completing the circuit
        // is impossible from any starting station
        if(totalGas < totalCost) { return -1; }

        
        int startPosition = 0;  // 🚦 startPosition: candidate index to start the journey
        int currentFuel = 0;    // 🔋 currentFuel: fuel left while traversing from startPosition

        // 🔁 Single-pass greedy traversal
        for(int index = 0; index < gas.size(); ++index) {
            currentFuel += gas[index];  // ⛽ Collect gas at the current station

            // 💸 Check if we can reach the next station
            if(currentFuel < cost[index]) {
                // ❌ Cannot proceed further from this segment
                // All stations between startPosition and index
                // are invalid starting points
                startPosition = index + 1;

                // 🔄 Reset fuel since we restart from a new candidate
                currentFuel = 0;
            }
            else {
                // 🔥 Spend fuel to move to the next station
                currentFuel -= cost[index];
            }
        }

        // 🏁 Since totalGas >= totalCost, this startPosition
        // is guaranteed to complete the circuit
        return startPosition;
    }
};

#endif