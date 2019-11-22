#include "vote.h"

using namespace std;

vote::vote(const std::vector<candidate>& prefs) : prefs(prefs) {}

const bool vote::spent() {
	if (prefs.empty()) {
		return true;
	}
	else {
		return false;
	}
}

const candidate vote::first_preference() {
	if (spent() == false) {
		return prefs[0];
	}
	else {
		return 0;
	}
}

void vote::discard(candidate c) {
	for (int i = 0; i < prefs.size(); ++i) {
		if (prefs[i] == c) {
			prefs.erase(prefs.begin() + --i);
		}
	}
}