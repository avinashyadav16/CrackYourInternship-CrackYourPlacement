/**
 *  @file: Print all the duplicate characters in a string.cpp
 *  @author: Avinash Yadav
 *  @brief: https://www.geeksforgeeks.org/print-all-the-duplicates-in-the-input-string
 *  @date: 19-07-2024
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// Using maps:
void printDups(string str)
{
    unordered_map<char, int> mpp;
    for (int i = 0; i < str.length(); i++)
    {
        mpp[str[i]]++;
    }

    for (auto it : mpp)
    {
        // if the count of characters is greater than 1 then duplicate found
        if (it.second > 1)
            cout << it.first << ", count = " << it.second << endl;
    }
}

// Using Sorting:
void printDuplicates(string str)
{
    int len = str.length();
    sort(str.begin(), str.end());

    // Loop through the sorted string
    for (int i = 0; i < len; i++)
    {
        int count = 1;

        // Counting the occurrences of each character
        while (i < len - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }

        if (count > 1)
        {
            cout << str[i] << ", count = " << count << endl;
        }
    }
}

int main()
{
    string str = "phosphorous";

    printDups(str);
    cout << endl;

    printDuplicates(str);

    return 0;
}