#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'isBalanced' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

bool isMatching(char a, char b)
{
    if ((a == '{' && b == '}') || (a == '[' && b == ']') || (a == '(' && b == ')'))
    {
        return true;
    }
    else return false;
}

bool isOpenBracket(char bracket)
{
    return (bracket == '(' || bracket == '[' || bracket == '{');
}

string isBalanced(string s)
{
    stack<char> stack;
    stack.push(s[0]);
    for (int i = 1; i < s.length(); i++)
    {
        char c = s.at(i);
        if (isOpenBracket(c)) {
            stack.push(c);
        } else {
            if (stack.empty()) {
                return "NO";
            }
            else if (!isMatching(stack.top(), c)) {
                return "NO";
            }
            else {
                stack.pop();
            }
        }
    }

    if (stack.empty())
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}

int main()
{
    int n;
    cin >> n;
    string s[n];
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << isBalanced(s[i]) << endl;
    }
}