# [Gas Station ⛽️](https://leetcode.com/problems/gas-station/description/?envType=study-plan-v2&envId=top-interview-150)

You’re driving on a **circular route** with `n` **gas stations**.
- ⛽ `gas[i]` → how much fuel you get at station i
- 🔥 `cost[i]` → fuel needed to go from station i to the next station *(i + 1)*

You:
- Start with an **empty tank**
- Can choose **any one station** as the starting point
- Have an **unlimited tank size**

### 🎯 Goal

Find the **index of the gas station** from which you can complete **one full круг (circle)** without running out of fuel.
- ✅ If it’s possible, return the **starting station index**
- ❌ If it’s not possible from any station, return `-1`
- 🧠 If a solution exists, it’s **guaranteed to be unique**

### 🟢 Example 1
- **Input:** <br>
gas  = `[1,2,3,4,5]`
cost = `[3,4,5,1,2]`
- **Output:** `3`
- **Explanation:** <br>
We start at **station 3 (index 3)** and track the fuel step by step: <br>

    | Step | Action | Fuel in Tank |
    |------|--------|--------------|
    | ⛽ Start | Fill gas at station 3 → +4 | `4` |
    | 🚗 Move to station 4 | Spend 1, get +5 | `4 - 1 + 5 = 8` |
    | 🚗 Move to station 0 | Spend 2, get +1 | `8 - 2 + 1 = 7` |
    | 🚗 Move to station 1 | Spend 3, get +2 | `7 - 3 + 2 = 6` |
    | 🚗 Move to station 2 | Spend 4, get +3 | `6 - 4 + 3 = 5` |
    | 🔁 Return to station 3 | Spend 5 | `0` ✅ |
    
    ✅ The fuel never goes negative, and we successfully complete the circuit. <br>
    **Result:** `3`

### 🔴 Example 2
- **Input:** <br>
gas  = `[2,3,4]` <br>
cost = `[3,4,3]`
- **Output:** `-1`
- **Explanation:** <br>
    - Starting at **station 0 or 1** ❌ — not enough fuel to reach the next station.
    - Try **station 2:**

        | Step | Action | Fuel in Tank |
        |------|--------|--------------|
        | ⛽ Start | Fill gas at station 2 → +4 | `4` |
        | 🚗 Move to station 0 | Spend 3, get +2 | `4 - 3 + 2 = 3` |
        | 🚗 Move to station 1 | Spend 3, get +3 | `3 - 3 + 3 = 3` |
        | 🚫 Return to station 2 | Need 4 gas, have only 3 | ❌ | 

        ❌ The circuit cannot be completed from any station. <br>
        **Result:** `-1`

### 📌 Constraints
- 🔢 `n == gas.length == cost.length`
- 📏 `1 ≤ n ≤ 10⁵`
- ⛽ `0 ≤ gas[i], cost[i] ≤ 10⁴`
- 🎯 The input is generated such that the **answer is unique**