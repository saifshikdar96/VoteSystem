#ifndef VOTE_H
#define VOTE_H
#include <vector>
#include <iostream>

typedef unsigned int candidate;

class vote {
	std::vector<candidate> prefs;

public:
	vote(const std::vector<candidate>& prefs);
	bool spent() const;
	candidate first_preference() const;
	void discard(candidate c);
};
#endif
