from typing import List

class pySolution(object):
    def py_canCompleteCircuit(self, gas: List[int], cost: List[int]) -> int:
        n: int = len(gas)   # 🧮 Number of gas stations (aka number of times hope can be crushed)

        # 🔁 Try starting the journey from EVERY station (brute-force but honest)
        for startPosition in range(n):
            tankCapacity: int = gas[startPosition]              # ⛽ Start by filling gas from the chosen station
            currentPosition: int = (startPosition + 1) % n      # 🚗 Move to the next station immediately (journey begins!)
            previousPosition: int = currentPosition - 1         # 👈 Will track the station we just left
            isCircuitCompleted: bool = True                     # 😇 Assume the circuit is completable (optimism max)

            # 🌀 Keep driving until we either come back home or run out of fuel
            while currentPosition != startPosition:

                # 🔄 Identify the previous station
                # Normal case → currentPosition - 1
                # Edge case → wrap around to last station (circle things 🎡)
                previousPosition = currentPosition - 1 if currentPosition > 0 else n - 1

                # 💸 Reality check: enough fuel to leave the previous station?
                if tankCapacity < cost[previousPosition]:
                    # 🚨 Nope. Journey ends here.
                    isCircuitCompleted = False
                    break

                tankCapacity -= cost[previousPosition]          # 🔥 Spend fuel to travel
                tankCapacity += gas[currentPosition]            # 🎁 Collect gas at the current station
                currentPosition = (currentPosition + 1) % n     # ➡️ Move to the next station (no stopping, no U-turns)

            # 🏁 Final boss check:
            # Can we travel from the last station back to startPosition?
            previousPosition = currentPosition - 1 if currentPosition > 0 else n - 1
            if tankCapacity < cost[previousPosition]:
                # ❌ Almost made it… but petrol said NO
                isCircuitCompleted = False

            # 🎉 If the full circle is completed, return the winning station
            if isCircuitCompleted: return startPosition

        # ❌ Tried all stations. Circuit is impossible.
        # This route is emotionally unavailable.
        return -1