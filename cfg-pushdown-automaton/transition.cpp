#include "transition.h"

bool Transition::isDigit(char c) const {
	return c >= '0' && c <= '9';
}

Transition::Transition(char state1, char inputSym, char stackSym,
											char state2, int stateId, const char* toPush)
											: state1(state1), inputSym(inputSym), stackSym(stackSym),
											state2(state2), stateId(stateId),
											toPush(toPush, strlen(toPush)) {}

char Transition::getInputSym() const {
	return inputSym;
}

char Transition::getStackSym() const {
	return stackSym;
}

int Transition::getStateId() const {
	return stateId;
}

const LinkedList<char>& Transition::getToPush() const {
	return toPush;
}

bool Transition::operator<(const Transition& other) const {
	if (!toPush.getHead()) return false; // epsilon
	if (!other.toPush.getHead()) return false; // epsilon
	if (isDigit(toPush.getHead()->data)) {
		return toPush.getHead()->data < other.toPush.getHead()->data;
	}
	return toPush.getHead()->data > other.toPush.getHead()->data;
}

void Transition::swap(Transition& tran1, Transition& tran2) {
	Transition& temp = tran1;
	tran1 = tran2;
	tran2 = temp;
}

std::ostream& operator<<(std::ostream& os, const Transition& transition) {
	return os << '('<< transition.state1 << ", "
						<< transition.inputSym << ", "
						<< transition.stackSym << ", "
						<< transition.state2 << ", "
						<< transition.toPush << ')';
}
