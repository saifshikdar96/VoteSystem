#ifndef ELECTION_H
#define ELECTION_H
#include "vote.h"
#include <vector>
#include <iostream>
#include <sstream>

class election {
	std::vector<vote> sel;

public:
	election(const std::vector<vote>& sel);
	void add_vote(const vote& v);
	int vote_count() const;
	void eliminate(candidate c);
	std::vector < std::pair<candidate, int >> ranked_candidates() const;
};

election read_votes(std::istream& in);

#endif