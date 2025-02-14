#include <iostream>

struct Suit {
public:
	bool ModInvisible;
	bool ModSilence;
	bool ModInfra;
	bool ModRadio;
	bool ModEnergo;

	Suit() : ModInvisible(false), ModSilence(false), ModInfra(false), ModRadio(false), ModEnergo(false) {}
	Suit(bool p1, bool p2, bool p3, bool p4, bool p5): ModInvisible(p1), ModSilence(p2), ModInfra(p3), ModRadio(p4), ModEnergo(p5) {}
};

void changeMod(Suit& suit, int num); // меняем состояние режима костбма под номером num
bool checkMod(const Suit& suit, int num); // проверка активности режима 
int countMod(const Suit& suit); // подсчёт активных режимов костюма
bool alarm(const Suit& suit); // проверяем опасность обнаружения

int main() {
	Suit suit(true, true, false, false, false);
	bool isalarm = alarm(suit);
	int activeInvisible = checkMod(suit, 1);
	changeMod(suit, 1);
	isalarm = alarm(suit);
	for (int i = 1; i <= 5; ++i) {
		changeMod(suit, i);
	}
	isalarm = alarm(suit);
}

void changeMod(Suit& suit, int num) {
	switch (num) {
	case 1: suit.ModInvisible = !suit.ModInvisible;
		break;
	case 2: suit.ModSilence = !suit.ModSilence;
		break;
	case 3: suit.ModInfra = !suit.ModInfra;
		break;
	case 4: suit.ModRadio = !suit.ModRadio;
		break;
	case 5: suit.ModEnergo = !suit.ModEnergo;
		break;
	}
}

bool checkMod(const Suit& suit, int num) {
	switch (num) {
	case 1: if (suit.ModInvisible)
		return true;
	case 2: if (suit.ModSilence)
		return true;
	case 3: if (suit.ModInfra)
		return true;
	case 4: if (suit.ModRadio)
		return true;
	case 5: if (suit.ModEnergo)
		return true;
	}
	return false;
}

int countMod(const Suit& suit) {
	return suit.ModInvisible + suit.ModSilence + suit.ModInfra + suit.ModRadio + suit.ModEnergo;
}

bool alarm(const Suit& suit) {
	if (!suit.ModInvisible and !suit.ModSilence or countMod(suit) > 3) {
		return true;
	}
	else {
		return false;
	}
}
