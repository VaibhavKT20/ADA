#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_CHAR = 256;

void shiftTable(const string &pattern, vector<int> &shift)
{
    int m = pattern.length();
    for (int i = 0; i < MAX_CHAR; ++i)
    {
        shift[i] = m;
    }
    for (int i = 0; i < m - 1; ++i)
    {
        shift[pattern[i]] = m - 1 - i;
    }
}

void horspoolSearch(const string &text, const string &pattern)
{
    int n = text.length();
    int m = pattern.length();
    vector<int> shift(MAX_CHAR, 0);
    shiftTable(pattern, shift);
    int i = 0;
    while (i <= n - m)
    {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[i + j])
        {
            j--;
        }
        if (j < 0)
        {
            cout << "Pattern found at index: " << i << endl;
            i += shift[text[i + m - 1]];
        }
        else
        {
            i += shift[text[i + m - 1]];
        }
    }
}

int main()
{
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    horspoolSearch(text, pattern);

    return 0;
}
