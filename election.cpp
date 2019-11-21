#include "election.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

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

vector<pair<candidate, int>> election::ranked_candidates() const {
	vector<pair<candidate, int>> candidates;
	vector<candidate> firstpref;


	return candidates;
}

election read_votes(istream& in){
	string line;
	vector<candidate> tempCandidate;
	vector<vote> tempvote;
	election Election = election(tempvote);
	while (getline(in, line)) {
		stringstream s(line);
		candidate z;
		while (s >> z) {
			tempCandidate.push_back(z);
		}
		vote inputVotes = vote(tempCandidate);
		Election.add_vote(inputVotes);
	}
	return Election;
}
