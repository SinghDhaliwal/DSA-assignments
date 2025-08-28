#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    vector<string> strings(n);
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; ++i)
    {
        getline(cin, strings[i]);
    }

    sort(strings.begin(), strings.end());

    cout << "Strings in alphabetical order:\n";
    for (const string &s : strings)
    {
        cout << s << endl;
    }

    return 0;
}