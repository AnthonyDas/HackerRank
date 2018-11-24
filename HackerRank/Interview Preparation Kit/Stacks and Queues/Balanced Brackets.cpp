#include <string>
#include <stack>

// Complete the isBalanced function below.
std::string isBalanced(std::string s) {
	std::stack<char> stk;

	for (auto it = s.begin(); it != s.end(); ++it) {
		if (*it == '{' || *it == '[' || *it == '(') {
			stk.push(*it);
		}
		else { // Must be closing bracket
			if (stk.empty() ||
				(*it == '}' && stk.top() != '{') ||
				(*it == ']' && stk.top() != '[') ||
				(*it == ')' && stk.top() != '(')) {
				return "NO";
			}
			stk.pop();
		}
	}

	return stk.empty() ? "YES" : "NO";
}