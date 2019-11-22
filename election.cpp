#include "election.h"
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

election::election(const std::vector<vote>& collection) : collection(collection) {}

void election::add_vote(const vote& v) {
	collection.push_back(v);
}

int election::vote_count() const {
	return collection.size();
}

void election::eliminate(candidate c) {
	for (int i = 0; i <= collection.size(); ++i) {
		collection[i].discard(c);
	}
}

vector<pair<candidate, int>> election::ranked_candidates() const {
	vector<pair<candidate, int>> candidates;
	vector<candidate> firstpref;

	for (vote x : collection) {
		firstpref.push_back(x.first_preference());
	}

	candidate highestValue = *max_element(firstpref.begin(), firstpref.end());

	for (int i = 1; i < highestValue; i++) {
		pair<candidate, int> cand;
		cand.first = i;
		cand.second = count(firstpref.begin(), firstpref.end(), i);
		candidates.push_back(cand);
	}

	sort(candidates.begin(), candidates.end(), [](const pair<candidate, int>& a, const pair<candidate, int>& b) {
		return a.second > b.second;
		});

	return candidates;
}

election read_votes(istream& in) {
	string line;
	vector<candidate> tempCandidate;
	vector<vote> tempvote;
	election _election = election(tempvote);
	while (getline(in, line)) {
		stringstream s(line);
		candidate z;
		while (s >> z) {
			tempCandidate.push_back(z);
		}
		vote inputVotes = vote(tempCandidate);
		_election.add_vote(inputVotes);
	}
	return _election;
}