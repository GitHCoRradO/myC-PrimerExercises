#ifndef BINARYQUERY_H
#define BINARYQUERY_H

#include "./Query_base.h"
#include "./Query_built_in_ptr.h"


class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
	lhs(l), rhs(r), opSym(s) { }
	std::string rep() const { return "(" + lhs.rep() + " " + opSym + " " +  rhs.rep() + ")"; }
	Query lhs, rhs;
	std::string opSym;
};

#endif
