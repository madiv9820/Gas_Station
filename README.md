## ⚡ Greedy O(n) Approach
### 🧠 Key Insight
Before choosing *where* to start, we first answer a more important question: <br>
*Is completing the circuit even possible?*

If the **total gas available** is less than the **total cost required**, then no starting station can ever work — no matter how clever the strategy 🚫⛽.

### 💡 Strategy Explaination

This solution uses a **single-pass greedy approach** that efficiently finds the valid starting station.

- #### 🔍 Step 1: Global Feasibility Check
    We compare:
    - ⛽ `totalGas = sum(gas)`
    - 💸 `totalCost = sum(cost)`
    - If: `totalGas < totalCost`, ➡️ return `-1` immediately.

    This eliminates impossible cases early and saves computation time.

- #### 🚗 Step 2: Single-Pass Traversal
    Once feasibility is confirmed, we simulate the journey **only once**.

    We maintain:
    - 🚦 `startPosition` — the current candidate starting station
    - 🔋 `currentFuel` — fuel left while traveling from `startPosition`

    As we move station by station:
    1. ⛽ Add gas from the current station
    2. 💸 Check if we can reach the next station
    3. ❌ If fuel drops below zero:
        - The current segment is invalid
        - All stations between the previous start and this station are discarded
        - The next station becomes the new candidate start
        - Fuel is reset

    This greedy reset works because:
    
    If you cannot reach station `i + 1` from your current start, then **no station before** `i` **can be a valid start either**.

### 🎯 Why the Greedy Reset Works
- Any fuel gained before the failure point is already insufficient
- Starting earlier would only make the fuel situation worse
- Skipping ahead is safe and optimal

This guarantees correctness while keeping the solution fast.

### 📊 Complexity Analysis
- **⏱️ Time Complexity:** `O(n)`
    - Why?
        - One pass to check feasibility
        - One pass to find the valid starting station

- **📦 Space Complexity:** `O(1)`
    - Why? 
        - No extra data structures
        - Only constant variables used

### 🆚 Comparison with Brute-Force
| **Approach**      | **Time Complexity** | **Space Complexity** | **Notes**                    |
| ------------- | --------------- | ---------------- | ------------------------ |
| Brute-force   | O(n²)           | O(1)             | Easy to understand, slow |
| Greedy (this) | O(n)            | O(1)             | Optimal, interview-ready |

### 🏁 Final Thoughts
This greedy solution:
- 🚀 Scales efficiently for large inputs
- 🧠 Demonstrates strong problem-solving intuition
- ✅ Is the optimal approach expected in interviews

Think of it as: *Fail fast, skip smart, and finish strong.*

--- 