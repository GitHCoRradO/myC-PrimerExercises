#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <string>
#include <stdexcept>
using std::runtime_error;
using std::ifstream;
using std::istringstream;
using std::string;
using std::endl;
using std::cout;
using std::unordered_map;

const string &transform(const string &s, const unordered_map<string, string> &m) {
	auto map_it = m.find(s);
	if (map_it != m.cend())
		return map_it->second;
	else
		return s;
}

unordered_map<string, string> buildMap(ifstream &map_file) {
	unordered_map<string, string> trans_map;
	string key, value;
	while (map_file >> key && getline(map_file, value)) {
		if (value.size() > 1)
			trans_map[key] = value.substr(1);
		else
			throw runtime_error("no rule for " + key);
	}
	return trans_map;
}

void word_transform(ifstream &map_file, ifstream &input) {
	auto trans_map = buildMap(map_file);
	string text;
	while (getline(input, text)) {
		istringstream stream(text);
		string word;
		bool firstword = true;
		while (stream >> word) {
			if (firstword)
				firstword = false;
			else
				cout << " ";
			cout << transform(word, trans_map);
		}
		cout << endl;
	}
}

int main(int argc, char *argv[]) {
	ifstream ifstrm1(argv[1]), ifstrm2(argv[2]);
	if (ifstrm1 && ifstrm2)
		word_transform(ifstrm1, ifstrm2);
	return 0;
}
