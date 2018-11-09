#include <string>
#include <sstream>
#include <iomanip>

/*
 * Complete the timeConversion function below.
 */
std::string timeConversion(const std::string &s) {
	// hh:mm:ssAM or hh:mm:ssPM
	int hh, mm, ss;
	hh = atoi(s.substr(0, 2).c_str());
	mm = atoi(s.substr(3, 2).c_str());
	ss = atoi(s.substr(6, 2).c_str());

	bool am = s.substr(8, 2) == "AM";

	if (am && hh == 12) {
		hh -= 12;
	}
	else if (!am && hh != 12) {
		hh += 12;
	}

	std::ostringstream sstream;
	sstream << std::setw(2) << std::setfill('0') << hh << ":";
	sstream << std::setw(2) << std::setfill('0') << mm << ":";
	sstream << std::setw(2) << std::setfill('0') << ss;

	return sstream.str();
}