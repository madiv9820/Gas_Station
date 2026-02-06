## Brute-Force Simulation (Baseline Solution) 💡
This solution takes a **straightforward and honest approach**: <br>
*👉 Try starting from every gas station and simulate the full journey.*

### 🔁 How it works
For each station `i`:
1. ⛽ Start with the gas available at station `i`
2. 🚗 Move to the next station in a circular manner
3. 🔄 At every step:
    - Check if there is enough fuel to travel to the next station
    - Deduct the travel cost
    - Add gas from the new station
4. 🛑 If fuel ever drops below zero → abort this start position
5. 🏁 If you return back to the starting station successfully → we found the answer

This process repeats until:
- a valid starting station is found ✅
- or all stations fail ❌

### 🎡 Circular Route Handling
Since the stations form a **circle**, modulo arithmetic is used: <br>
`next_station = (current_station + 1) % n`

This ensures we:
- wrap from the last station back to the first
- never go out of bounds
- keep the traversal clean and intuitive

### 📊 Complexity Analysis
- **⏱️ Time Complexity:** `O(n²)`
    - Why?
        - We try up to `n` starting stations
        - For each start, we may traverse up to n stations in the worst case

    This is acceptable as a baseline but not optimal for large inputs.
- **📦 Space Complexity:** `O(1)`
    - Why?
        - No extra data structures are used
        - Only a few variables to track fuel and positions

### 🧪 Why This Approach Is Useful
Even though it’s not optimal, this solution is valuable because:
- ✅ Easy to understand and reason about
- 🧠 Clearly demonstrates the mechanics of the problem
- 🧪 Acts as a reference implementation
- 🚀 Makes it easier to validate and trust future optimized solutions

Think of it as:
*“First make it work, then make it fast.”*

### 🔜 What’s Next?
An optimized **O(n) greedy solution** exists that:
- skips impossible starting positions
- solves the problem in a single pass

This brute-force solution lays **the conceptual foundation** for that optimization.

### 🏁 Final Thoughts

This implementation focuses on:
- clarity 🧼
- correctness ✅
- learning value 🧠

Perfect for:
- interview preparation
- algorithm understanding
- building intuition before optimization

🚗💨 Onwards to the greedy solution!

---