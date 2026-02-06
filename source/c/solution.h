#ifndef SOLUTION_H
#define SOLUTION_H

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int startPosition;      // 🚦 startPosition: where we *dream* our journey can begin
    int tankCapacity;       // ⛽ tankCapacity: how much fuel we currently have (spoiler: never enough)    
    int currentPosition;    // 📍 currentPosition: where the car is right now
    int previousPosition;   // ↩️ previousPosition: the station we JUST left (because bills come later)
    int isCircuitCompleted; // ✅ isCircuitCompleted: innocent until proven broke
    
    // 🔁 Try starting from EVERY station (brute-force gang 💪)
    for(startPosition = 0; startPosition < gasSize; ++startPosition) {
        tankCapacity = gas[startPosition];                  // ⛽ Fill gas at the starting station
        currentPosition = (startPosition + 1) % gasSize;    // 🚗 Move to the next station (circular track, no escape 😈)
        isCircuitCompleted = 1;                             // 😇 Assume success… life is good… for now

        // 🌀 Keep driving until we either come back home or cry
        while(currentPosition != startPosition) {
            // 👈 Figure out which station we came from
            // If currentPosition > 0 → normal case
            // Else → wrap around to the last station (circle things 🧠)
            previousPosition = ((currentPosition > 0) ? currentPosition - 1 : gasSize - 1);

            // 💸 Reality check: do we even have enough fuel to leave?
            if(tankCapacity < cost[previousPosition]) {
                isCircuitCompleted = 0;     // 🚨 Mission failed. We’ll get ’em next time.
                break;
            }

            tankCapacity -= cost[previousPosition];             // 🔥 Spend fuel to travel
            tankCapacity += gas[currentPosition];               // 🎁 Collect free gas at the new station
            currentPosition = (currentPosition + 1) % gasSize;  // ➡️ Move to the next station (round and round we go)
        }
        
        // 🏁 Final boss check: can we return to the starting station?
        // (Yes, even victory has paperwork)
        previousPosition = ((currentPosition > 0) ? currentPosition - 1 : gasSize - 1);
        if(tankCapacity < cost[previousPosition]) { isCircuitCompleted = 0; }

        // 🎉 If we survived the full circle — WE HAVE A WINNER
        if(isCircuitCompleted) { return startPosition; }
    }

    // ❌ Tried everything. No valid starting point.
    // This circuit is emotionally unavailable.
    return -1;
}

#endif