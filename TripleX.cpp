#include <iostream>
#include <ctime>

void printIntroduction(int Difficulty)
{
	std::cout << "I am the gatekeeper, enter the level " << Difficulty << " code\n";
	std::cout << "to pass through my gate...\n\n";
}

bool playGame(int Difficulty)
{
	printIntroduction(Difficulty);

	const int CodeA = rand() % Difficulty + 1;
	const int CodeB = rand() % Difficulty + 1;
	const int CodeC = rand() % Difficulty + 1;

	const int CodeSum = CodeA + CodeB + CodeC;
	const int CodeProduct = CodeA * CodeB * CodeC;

	std::cout << "There are 3 numbers in the code..." << std::endl;
	std::cout << "The numbers add up to " << CodeSum << std::endl;
	std::cout << "The numbers multiply to be " << CodeProduct << std::endl;
	std::cout << std::endl << "Enter your guess... ";

	int GuessA, GuessB, GuessC;

	std::cin >> GuessA;
	std::cin >> GuessB;
	std::cin >> GuessC;

	int GuessSum = GuessA + GuessB + GuessC;
	int GuessProduct = GuessA * GuessB * GuessC;

	if (GuessSum == CodeSum && GuessProduct == CodeProduct)
	{
		std::cout << "Congratulations, you guessed the correct code!\n";
		std::cout << "----------------------------------------------\n";
		return true;
	}
	else
	{
		std::cout << "BZZZZZZZZZZ! You did not guess correctly!\n\n";
		std::cout << "----------------------------------------------\n";
		return false;
	}
}

int main()
{
	srand(time(NULL));

	int Difficulty = 2;
	const int MaxDifficulty = 10;

	while (Difficulty <= MaxDifficulty)
	{
		if (playGame(Difficulty) == true)
		{
			Difficulty++;
		}

		std::cin.clear();
		std::cin.ignore();
	}

	std::cout << "\n****Congratulations on getting through my gate!****";

	return 0;
}