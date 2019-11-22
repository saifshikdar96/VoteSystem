#include "election.h"
#include "vote.h"
#include <fstream>

using namespace std;

int main() {
	fstream in("votes.txt");
	election _election = read_votes(in);
	vector<pair<candidate, int>> rankedcandidate = _election.ranked_candidates();
	int round = 1;

	while (_election.vote_count() != 0) {
		cout << "Round" << round << ": " << /*_election.vote_count <<*/ '\n';
	}

	cout << "First preferences: " << '\n';
	cout << "  Candidate " << /*first pref <<*/ ": " /*<< vote count*/;

	return 0;
}