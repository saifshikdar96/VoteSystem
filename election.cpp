#include "election.h"
#include "vote.h"
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

election::election(const std::vector<vote>& sel) : sel(sel) {}

void election::add_vote(const vote& v) {
	sel.push_back(v);
}

int election::vote_count() const {
	return sel.size();
}

void election::eliminate(candidate c) {
	for (int i = 0; i < sel.size(); ++i) {
		sel[i].discard(c);
		if (sel[i].spent()) {
			sel.erase(sel.begin() + (i--));
		}
	}
}

vector<pair<candidate, int>> election::ranked_candidates() const {
	vector<pair<candidate, int>> candidates;
	vector<candidate> first_pref;

	for (vote x : sel) {
		first_pref.push_back(x.first_preference());
	}

	candidate highestValue = *max_element(first_pref.begin(), first_pref.end());

	for (int i = 1; i < highestValue + 1; i++) {
		pair<candidate, int> cand;
		cand.first = i;
		cand.second = count(first_pref.begin(), first_pref.end(), i);
		candidates.push_back(cand);
	}

	sort(candidates.begin(), candidates.end(), [](const pair<candidate, int>& x, const pair<candidate, int>& y) {
		return x.second > y.second;
		});

	return candidates;
}

election read_votes(istream& in) {
	string line;
	vector<vote> tempVote;
	while (getline(in, line)) {
		vector<candidate> tempCand;
		stringstream s(line);
		candidate z;
		while (s >> z) {
			tempCand.push_back(z);
		}
		vote inputVotes(tempCand);
		tempVote.push_back(inputVotes);
	}
	election _election(tempVote);
	return _election;
}