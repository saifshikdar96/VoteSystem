#ifndef ELECTION_H
#define ELECTION_H
#include "vote.h"
#include <vector>
#include <istream>

class election {

public:

	void add_vote(const vote& v);
	int vote_count() const;
	void eliminate(candidate c);
	vector<pair<candidate, int>> ranked_candidates() const;
	election read_votes(istream& in);
};

#endif // !ELECTION_H
