#ifndef EX7_23_24_27_H
#define EX7_23_24_27_H

#include <string>
#include <iostream>
using std::string;

class Screen {
public:
	//type member:
	typedef string::size_type pos;
	
	//constructors:
	Screen() = default;
	Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') { }
	Screen(pos ht, pos wd, char c) : height(ht), width(wd), contents(ht * wd, c) { }

	//member functions:
	char get() const { return contents[cursor]; }
	inline char get(pos ht, pos wd) const;
	inline Screen &move(pos r, pos c);
	inline Screen &set(char);
	inline Screen &set(pos, pos, char);
	Screen &display(std::ostream &os) { do_display(os); return *this; }
	const Screen &display(std::ostream &os) const { do_display(os); return *this; }

private:
	//data memebers:
	pos cursor = 0;
	pos height = 0, width = 0;
	string contents;

	//private function member:
	void do_display(std::ostream &os) const { os << contents; }
};

inline Screen &Screen::move(pos r, pos c) {
	pos row = r * width;
	cursor = row + c;
	return *this;
}

char Screen::get(pos r, pos c) const {
	pos row = r * width;
	return contents[row + c];
}

inline Screen &Screen::set(char c) {
	contents[cursor] = c;
	return *this;
}

inline Screen &Screen::set(pos r, pos col, char ch) {
	contents[r * width + col] = ch;
	return *this;
}

#endif
