#include <vector>
#include <list>
#include <stack>
#include <utility> // make_pair

// Complete the poisonousPlants function below.
int poisonousPlants(std::vector<int> &p) {

	typedef std::stack<int, std::list<int> > stack_type;
	typedef std::list<std::pair<stack_type, int> > list_type; // stack and bottom value

	list_type lst;

	// Initial data read
	stack_type s;
	int bottom = -1;
	for (auto it = p.crbegin(); it != p.crend(); ++it) {
		// Maintain stack such that only equal or larger values get added on top
		if (s.empty()) {
			s.push(*it);
			bottom = *it;
		}
		else {
			if (*it >= s.top()) {
				s.push(*it);
			}
			else {
				// Add current stack to list and start a new stack
				// push_front as reading vector in reverse order
				lst.push_front(std::make_pair(s, bottom));
				while (!s.empty()) {
					s.pop();
				}
				s.push(*it);
				bottom = *it;
			}
		}
	}
	lst.push_front(std::make_pair(s, bottom)); // Add final stack

	int count = 0;
	while (lst.size() > 1) {
		for (auto it = ++lst.begin(); it != lst.end(); ++it) {
			// Pop from all the stacks except from the very first, because
			// there is no plant on left hand side of very first plant.
			it->first.pop();
			if (it->first.empty()) {
				auto prv = it;
				--prv;
				lst.erase(it);
				it = prv;
			}

			// Try to merge stacks, e.g. suppose we have stacks {10, 8, 5} and {7, 4, 2}.
			// After 7 has died (as >5), we can merge stacks to get {10, 8, 5, 4, 2}.
			if (it != lst.begin()) {
				auto prv = it;
				--prv;
				if (prv->second >= it->first.top()) {
					stack_type temp;
					while (!prv->first.empty()) {
						temp.push(prv->first.top());
						prv->first.pop();
					}
					while (!temp.empty()) {
						it->first.push(temp.top());
						temp.pop();
					}
					lst.erase(prv);
				}
			}
		}

		++count;
	}

	return count;
}