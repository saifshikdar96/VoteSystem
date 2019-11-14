#ifndef VOTE_H
#define VOTE_H
#include <vector>

typedef unsigned int candidate;

class vote {
	
	vote(const std::vector<candidate>& prefs);
public:
	const bool spent();
	const candidate first_preference();
	void discard(candidate c);
};

#endif