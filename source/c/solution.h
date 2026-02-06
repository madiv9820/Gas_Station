#ifndef SOLUTION_H
#define SOLUTION_H

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int totalGas = 0;       // ⛽ totalGas: total fuel available across all stations
    int totalCost = 0;      // 💸 totalCost: total fuel required to complete the entire circuit
    int currentFuel = 0;    // 🔋 currentFuel: fuel left while simulating the journey
    int n = gasSize;        // 🧮 Number of gas stations
    int index;              // 🔁 Loop variable
    int startPosition = 0;  // 🚦 startPosition: candidate starting station

    // ===============================
    // 🔍 Step 1: Global feasibility check
    // ===============================
    // If total gas available is less than total cost required,
    // completing the circuit is IMPOSSIBLE from any station.
    for(index = 0; index < n; ++index) {
        totalGas += gas[index];
        totalCost += cost[index];
    }

    // 🚫 Early exit if the journey is mathematically impossible
    if(totalGas < totalCost) { return -1; }

    // ===============================
    // 🚗 Step 2: Greedy single-pass traversal
    // ===============================
    // We try to find a valid starting station by tracking fuel balance.
    // If we fail at station `index`, then NONE of the stations between
    // the previous startPosition and `index` can be a valid start.
    for(index = 0; index < n; ++index) {
        currentFuel += gas[index];  // ⛽ Add gas from the current station

        // 💸 Check if we can travel to the next station
        if(currentFuel < cost[index]) {
            // ❌ Cannot proceed from here
            // So, the next station becomes the new candidate start
            startPosition = index + 1;
            
            // 🔄 Reset fuel since we are restarting the journey
            currentFuel = 0;
        } else {
            // 🔥 Spend fuel to reach the next station
            currentFuel -= cost[index];
        }
    }

    return startPosition;   // 🏁 If totalGas >= totalCost, this startPosition is guaranteed to work
}


#endif