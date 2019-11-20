#include "election.h"
#include <sstream>
#include <iostream>

using namespace std;

election::election(const std::vector<vote>& collection) {
collection:collection;
}

void election::add_vote(const vote& v){
	collection.push_back(v);
}

int election::vote_count() const{
	return collection.size();
}

void election::eliminate(candidate c){
	for (int i = 0; i <= collection.size(); ++i) {
		collection[i].discard(c);
	}
}

/*vector<pair<candidate, int>> election::ranked_candidates() const{
	return vector<pair<candidate, int>>();
}

election read_votes(istream& in){
	string line;
	vector<vote> tempvote;
	while (getline(in, line)) {
		stringstream s(line);
		tempvote.push_back(s);
	}
	return ;
}*/