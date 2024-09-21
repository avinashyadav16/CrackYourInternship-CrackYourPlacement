/**
 *  @file: fibonacci.cpp
 *  @author: Avinash Yadav
 *  @brief: Fibonacci codes using Brute force, DP iterative and recursion
 *  @date: 20-09-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// For DP iterative solution, we initialize a vector to store Fibonacci numbers for later reuse
// Stores values in the BOTTOM-UP approach
vector<int> dpi(100, -1);

// For DP recursive solution, we initialize a vector to store Fibonacci numbers as they are computed
// Stores values in the TOP-DOWN approach (Memoization)
vector<int> dpr(100, -1);






// Brute force method (Exponential time)
// Time Complexity: O(2^n), as each call spawns two more recursive calls.
// This approach is very inefficient for larger n because it recalculates the same values multiple times.
int bruteForceFibonacci(int n)
{
    // Base case: Fib(1) = Fib(2) = 1
    if (n <= 2) 
    {
        return 1;
    }


    // Recursively calculate Fib(n-1) and Fib(n-2), and return their sum
    return bruteForceFibonacci(n - 1) + bruteForceFibonacci(n - 2);
}





// Iterative method using Dynamic Programming: BOTTOM-UP (Linear time)
// Time Complexity: O(n), because we calculate each Fibonacci number from Fib(3) to Fib(n) just once.
// Space Complexity: O(n), because we store the Fibonacci numbers in the dpi vector.
int iterativeFibonacci(int n)
{
    dpi[1] = 1; // Initialize the first Fibonacci number
    dpi[2] = 1; // Initialize the second Fibonacci number

    // Start calculating from Fib(3) to Fib(n) iteratively, building up from the base cases
    for (int i = 3; i <= n; i++)
    {
        // Using previously computed values to calculate the current Fibonacci number
        dpi[i] = dpi[i - 1] + dpi[i - 2]; 
    }

    return dpi[n]; 
}







// Recursive method with memoization: TOP-DOWN (Linear time)
// Time Complexity: O(n), because each Fibonacci number is calculated only once and stored in dpr.
// Space Complexity: O(n), because we store the Fibonacci numbers in the dpr vector.
int recursiveFibonacci(int n)
{
    // Base case: Fib(1) = Fib(2) = 1
    if (n <= 2) 
    {
        return 1;
    }

    // If we have already computed Fib(n), return the cached value to avoid recalculating it
    if (dpr[n] != -1)
    {
        return dpr[n];
    }

    // Otherwise, calculate Fib(n) using the recursive formula and store the result for future use
    return dpr[n] = recursiveFibonacci(n - 1) + recursiveFibonacci(n - 2);
}

int main()
{
    int n;

    cout << "Enter the number: ";
    cin >> n;

    cout << "Fibonacci number using Brute Force: " << bruteForceFibonacci(n) << endl;
    cout << "Fibonacci number using DP Iterative: " << iterativeFibonacci(n) << endl;
    cout << "Fibonacci number using DP Recursive: " << recursiveFibonacci(n) << endl;

    return 0;
}
