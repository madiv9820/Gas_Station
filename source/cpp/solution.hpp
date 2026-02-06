#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();     // 🧮 Total number of gas stations (aka number of chances to fail)

        // 🔁 Try starting from EACH station (brute-force era 😤)
        for(int startPosition = 0; startPosition < n; ++startPosition) {
            int tankCapacity = gas[startPosition];          // ⛽ Start with the gas available at the chosen station
            int currentPosition = (startPosition + 1) % n;  // 🚗 Immediately move to the next station (because we start driving)
            int previousPosition;                           // 👈 Will store the station we just came from
            bool isCircuitCompleted = true;                 // 😇 Assume success until reality hits

            // 🌀 Keep moving until we either complete the loop or cry
            while(currentPosition != startPosition) {
                // 🔄 Figure out the station we came from
                // Normal case: currentPosition - 1
                // Edge case: wrap around to last station (circular track 🎡)
                previousPosition = ((currentPosition > 0) ? currentPosition - 1 : n - 1);

                // 💸 Check if we even have enough fuel to leave previous station
                if(tankCapacity < cost[previousPosition]) { 
                    isCircuitCompleted = false;     // 🚨 Out of fuel. Dreams shattered.
                    break; 
                }

                tankCapacity -= cost[previousPosition];         // 🔥 Spend fuel to travel
                tankCapacity += gas[currentPosition];           // 🎁 Refill at the current station
                currentPosition = (currentPosition + 1) % n;    // ➡️ Move forward (no U-turns allowed)
            }

            // 🏁 Final check: can we go back to the starting station?
            // (Yes, even heroes must pay the last toll 😌)
            previousPosition = ((currentPosition > 0) ? currentPosition - 1 : n - 1);
            if(tankCapacity < cost[previousPosition]) {  isCircuitCompleted = false; }

            // 🎉 If the full circle is completed, return the winning station
            if(isCircuitCompleted) { return startPosition; }
        }

        // ❌ No starting station worked
        // This circuit is toxic. Move on.
        return -1;
    }
};

#endif