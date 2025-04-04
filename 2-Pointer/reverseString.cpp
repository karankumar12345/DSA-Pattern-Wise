#include<iostream>
#include<vector>
#include<algorithm>  // For reverse
using namespace std;

string reverseWord(string s) {
    int left = 0;
    int right = s.size() - 1;

    // Trim leading spaces
    while (left <= right && s[left] == ' ') left++;
    // Trim trailing spaces
    while (left <= right && s[right] == ' ') right--;

    vector<string> words;
    string word;

    // Extract words from the string
    while (left <= right) {
        char c = s[left];
        if (c != ' ') {
            word += c;  // Add character to current word
        } else if (!word.empty()) {
            words.push_back(word);  // Push word to vector
            word.clear();  // Clear word for the next word
        }

        left++;
    }

    // Push the last word if it exists
    if (!word.empty()) words.push_back(word);

    // Reverse the words in the vector
    reverse(words.begin(), words.end());

    // Join words into a single string with spaces
    string result;
    for (int i = 0; i < words.size(); i++) {
        result += words[i];
        if (i < words.size() - 1) result += " "; // Add space between words
    }

    return result;
}

int main() {
    string s = "karan is a good boy ";

    // Call the reverseWord function
    string result = reverseWord(s);

    // Print the result
    cout << result << endl;

    return 0;
}

