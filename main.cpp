#include "election.h"
#include "vote.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	fstream in("votes.txt");
	election _election = read_votes(in);
	vector<pair<candidate, int>> rankedcandidate = _election.ranked_candidates();
	int round = 1;

	while (_election.vote_count() != 0) {
		cout << "Round " << round++ << ": " << _election.vote_count() << " votes";
		cout << "\nFirst preferences:";
		for (int i = 0; i < rankedcandidate.size(); ++i) {
			if (rankedcandidate[i].second != 0) {
				cout << '\n' << "  Candidate " << rankedcandidate[i].first << ": " << rankedcandidate[i].second;
			}
			else {
				rankedcandidate.erase(rankedcandidate.begin() + (i--));
			}
		}
		if (rankedcandidate[0].second > (_election.vote_count() / 2)) {
			cout << '\n' << "Candidate " << rankedcandidate[0].first << " is selected." << '\n';
			break;
		}
		else {
			cout << '\n' << "Candidate " << rankedcandidate.back().first << " is eliminated." << "\n\n";
			_election.eliminate(rankedcandidate.back().first);
			rankedcandidate = _election.ranked_candidates();
		}
	}
}