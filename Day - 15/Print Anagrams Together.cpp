/**
*  @file: Print Anagrams Together.cpp
*  @author: Avinash Yadav
*  @brief: https://www.geeksforgeeks.org/problems/print-anagrams-together/1
*  @level: Medium
*  @date: 01-08-2024

*  @brief: Given an array of strings, return all groups of strings that are anagrams.
           The groups must be created in order of their appearance in the original array. Look at the sample case for clarification.

           Note: The final output will be in lexicographic order.

           Example 1:                                                 Example 2:
           Input:                                                     Input:
           N = 5                                                      N = 3
           words[] = {act,god,cat,dog,tac}                            words[] = {no,on,is}

           Output:                                                    Output:
           act cat tac                                                is
           god dog                                                    no on

           Explanation:                                               Explanation:
           There are 2 groups of                                      There are 2 groups of
           anagrams "god", "dog" make group 1.                        anagrams "is" makes group 1.
           "act", "cat", "tac" make group 2.                          "no", "on" make group 2.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        // For storing sorted string as key and list of anagrams as value
        unordered_map<string, vector<string>> anaMap;

        for (const string &word : string_list)
        {
            // Sort the characters of the word to use as a key
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());

            // Group the original word by its sorted key
            anaMap[sorted_word].push_back(word);
        }

        vector<vector<string>> result;

        // Extracting the grouped anagrams from the map in the order of their first appearance
        for (const string &word : string_list)
        {
            string sorted_word = word;
            sort(sorted_word.begin(), sorted_word.end());

            if (!anaMap[sorted_word].empty())
            {
                result.push_back(anaMap[sorted_word]);

                // Clearing the map entry to ensure each group is added only once
                anaMap[sorted_word].clear();
            }
        }

        return result;
    }
};