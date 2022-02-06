#include "Doll.h"

	Doll::Doll(DollState state, int dollSize) : dollState(state), dollSize(dollSize) { }

	Doll::Doll(const Doll& doll) {
		dollState = doll.dollState;

		if (doll.nestedDoll != nullptr) {
			nestedDoll = doll.nestedDoll;
		}
		dollSize = doll.dollSize;
	}

	Doll& Doll::operator=(const Doll& copy) {
		dollState = copy.dollState;
		if (copy.nestedDoll != nullptr) {
			nestedDoll = nestedDoll;
		}
		dollSize = copy.dollSize;
		return *this;
	}

	int Doll::availableDollSize()
	{
		if (nestedDoll != nullptr) {
			return nestedDoll->dollSize;
		}
		return dollSize;
	}
