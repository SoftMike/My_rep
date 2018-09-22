#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <random>

int account = 1000;

struct DECK
{
	std::string card_name;
	int card_score;
};

void check(int user_score, int diller_skore, int *bet)
{
	if (diller_skore < user_score && user_score <= 21)
	{
		std::cout << "" << std::endl;
		std::cout << "        __     __          __          _______ _   _   _ " << std::endl;
		std::cout << "        \\ \\   / /          \\ \\        / /_   _| \\ | | | |" << std::endl;
		std::cout << "         \\ \\_/ /__  _   _   \\ \\  /\\  / /  | | |  \\| | | |" << std::endl;
		std::cout << "          \\   / _ \\| | | |   \\ \\/  \\/ /   | | | . ` | | |" << std::endl;
		std::cout << "           | | (_) | |_| |    \\  /\\  /   _| |_| |\\  | |_|" << std::endl;
		std::cout << "           |_|\\___/ \\__,_|     \\/  \\/   |_____|_| \\_| (_)" << std::endl;
		std::cout << "" << std::endl;
		account = account + *bet;
	}
	if (user_score > diller_skore && user_score > 21 && diller_skore <= 21)
	{
		std::cout << "" << std::endl;
		std::cout << "       __     __           _      ____   _____ ______ _ " << std::endl;
		std::cout << "       \\ \\   / /          | |    / __ \\ / ____|  ____| |" << std::endl;
		std::cout << "        \\ \\_/ /__  _   _  | |   | |  | | (___ | |__  | |" << std::endl;
		std::cout << "         \\   / _ \\| | | | | |   | |  | |\\___ \\|  __| | |" << std::endl;
		std::cout << "          | | (_) | |_| | | |___| |__| |____) | |____|_|" << std::endl;
		std::cout << "          |_|\\___/ \\__,_| |______\\____/|_____/|______(_)" << std::endl;
		std::cout << "" << std::endl;
		account = account - *bet;
	}
	if (diller_skore > user_score && user_score <= 21 && diller_skore > 21)
	{
		std::cout << "" << std::endl;
		std::cout << "          __     __          __          _______ _   _   _ " << std::endl;
		std::cout << "          \\ \\   / /          \\ \\        / /_   _| \\ | | | |" << std::endl;
		std::cout << "           \\ \\_/ /__  _   _   \\ \\  /\\  / /  | | |  \\| | | |" << std::endl;
		std::cout << "            \\   / _ \\| | | |   \\ \\/  \\/ /   | | | . ` | | |" << std::endl;
		std::cout << "             | | (_) | |_| |    \\  /\\  /   _| |_| |\\  | |_|" << std::endl;
		std::cout << "             |_|\\___/ \\__,_|     \\/  \\/   |_____|_| \\_| (_)" << std::endl;
		std::cout << "" << std::endl;
		account = account + *bet;
	}
	if ((diller_skore > 21 && user_score > 21) || (diller_skore == user_score))
	{
		std::cout << "" << std::endl;
		std::cout << "              $$$$$____$$$$$_____$$$$____$$___$$_______$$$" << std::endl;
		std::cout << "              $$__$$___$$__$$___$$__$$___$$___$$_______$$$" << std::endl;
		std::cout << "              $$__$$___$$$$$____$$$$$$___$$_$_$$_______$$$" << std::endl;
		std::cout << "              $$__$$___$$__$$___$$__$$___$$$$$$$" << std::endl;
		std::cout << "              $$$$$____$$__$$___$$__$$____$$_$$________$$$" << std::endl;
		std::cout << "" << std::endl;
	}
	if (diller_skore > user_score && user_score <= 21 && diller_skore <= 21)
	{
		std::cout << "" << std::endl;
		std::cout << "          __     __           _      ____   _____ ______ _ " << std::endl;
		std::cout << "          \\ \\   / /          | |    / __ \\ / ____|  ____| |" << std::endl;
		std::cout << "           \\ \\_/ /__  _   _  | |   | |  | | (___ | |__  | |" << std::endl;
		std::cout << "            \\   / _ \\| | | | | |   | |  | |\\___ \\|  __| | |" << std::endl;
		std::cout << "             | | (_) | |_| | | |___| |__| |____) | |____|_|" << std::endl;
		std::cout << "             |_|\\___/ \\__,_| |______\\____/|_____/|______(_)" << std::endl;
		std::cout << "" << std::endl;
		account = account - *bet;
	}
}

void display_results(DECK *diller, DECK *user, int user_score, int user_kards, int diller_kards, std::string player_name, int *bet)
{
	//formatting header
	std::cout << "" << std::endl;
	std::cout << "           " << player_name << " CARDS:";
	std::cout << " ";
	std::cout << "                       DILLER CARDS:" << std::endl;
	std::cout << "______________________________________";
	std::cout << " ";
	std::cout << "_____________________________________" << std::endl;
	int n = 0;
	//formatting of table
	for (int i = 0, k = 0; i < user_kards || k < diller_kards; i++, k++)
	{
		n++;
		if (user_kards < n)
		{
			user[i].card_name = "pass";
			user[i].card_score = 0;
		}

		int l = user[i].card_name.length();
		std::cout << "  #" << i + 1 << " card:  " << user[i].card_name;
		std::cout << "     ";
		for (l; l != 5; l++)
			std::cout << " ";
		std::cout << "card score:  " << user[i].card_score;

		if (user[i].card_score <0 || user[i].card_score > 9)
			std::cout << " ";
		else
			std::cout << "  ";

		std::cout << "|";
		std::cout << " ";

		if (n > diller_kards)
			diller[k].card_name = "-";

		int m = diller[k].card_name.length();
		if (k == 0)
		{
			std::cout << "#" << k + 1 << " card:  hidden ";
			std::cout << "   ";
			std::cout << "card score:  -";
			std::cout << "  ";
			std::cout << "|" << std::endl;
		}
		else
		{
			std::cout << "#" << k + 1 << " card:  " << diller[k].card_name;
			std::cout << "     ";
			for (m; m != 5; m++)
				std::cout << " ";
			if (n > diller_kards)
				diller[k].card_score = 0;
			std::cout << "card score:  " << diller[k].card_score;
			if (diller[k].card_score < 0 || diller[k].card_score > 9)
				std::cout << " ";
			else
				std::cout << "  ";
			std::cout << "|" << std::endl;
		}

	}
	//formatting bottom
	std::cout << "//////////////////////////////////////|";
	std::cout << " ";
	std::cout << "////////////////////////////////////|" << std::endl;
	std::cout << "////////    Total score: " << user_score;

	if (user_score < 1 || user_score > 9)
		std::cout << " ";
	else
		std::cout << "  ";

	std::cout << "    //////|";
	std::cout << " ";
	std::cout << "////////    Total score: ?  ";
	std::cout << "    ////|" << std::endl;
	std::cout << "//////////////////////////////////////|";
	std::cout << " ";
	std::cout << "////////////////////////////////////|" << std::endl;
	std::cout << "Money: " << account;

	if (account < 1000000 && account >99999)
		std::cout << "";
	else if (account < 100000 && account >9999)
		std::cout << " ";
	else if (account < 10000 && account >999)
		std::cout << "  ";
	else if (account < 1000 && account >99)
		std::cout << "   ";
	else if (account < 100 && account >9)
		std::cout << "    ";
	else if (account < 10 && account >= 0)
		std::cout << "     ";

	std::cout << " /     \\ Your bet: " << *bet;

	if (*bet >= 10000)
		std::cout << " ";
	if (*bet < 10000 && *bet > 999)
		std::cout << "  ";
	else if (*bet <= 1000 && *bet > 99)
		std::cout << "   ";
	else if (*bet <= 100 && *bet > 9)
		std::cout << "    ";
	else if (*bet <= 10 && *bet >= 0)
		std::cout << "     ";

	std::cout << "| ////////////////////////////////////|" << std::endl;

	std::cout << "_____________/       \\________________|_____________________________________|" << std::endl;
}

void display_ALLresults(DECK *diller, DECK *user, int user_score, int user_kards, int diller_score, int diller_kards, std::string player_name, int *bet)
{
	//formatting header
	std::cout << "" << std::endl;
	std::cout << "           " << player_name << " CARDS:";
	std::cout << " ";
	std::cout << "                       DILLER CARDS:" << std::endl;
	std::cout << "______________________________________";
	std::cout << " ";
	std::cout << "_____________________________________" << std::endl;
	int n = 0;
	//formatting of table
	for (int i = 0, k = 0; i < user_kards || k < diller_kards; i++, k++)
	{
		n++;
		if (user_kards < n)
		{
			user[i].card_name = "pass";
			user[i].card_score = 0;
		}

		int l = user[i].card_name.length();

		std::cout << "  #" << i + 1 << " card:  " << user[i].card_name;
		std::cout << "     ";

		for (l; l != 5; l++)
			std::cout << " ";

		std::cout << "card score:  " << user[i].card_score;

		if (user[i].card_score <0 || user[i].card_score > 9)
			std::cout << " ";
		else
			std::cout << "  ";

		std::cout << "|";
		std::cout << " ";

		if (n > diller_kards)
			diller[k].card_name = "-";

		int m = diller[k].card_name.length();

		std::cout << "#" << k + 1 << " card:  " << diller[k].card_name;
		std::cout << "     ";

		for (m; m != 5; m++)
			std::cout << " ";

		if (n > diller_kards)
			diller[k].card_score = 0;

		std::cout << "card score:  " << diller[k].card_score;

		if (diller[k].card_score <0 || diller[k].card_score > 9)
			std::cout << " ";
		else
			std::cout << "  ";

		std::cout << "|" << std::endl;
	}
	//formatting bottom
	std::cout << "//////////////////////////////////////|";
	std::cout << " ";
	std::cout << "////////////////////////////////////|" << std::endl;

	std::cout << "////////    Total score: " << user_score;

	if (user_score < 1 || user_score > 9)
		std::cout << " ";
	else
		std::cout << "  ";

	std::cout << "    //////|";
	std::cout << " ";
	std::cout << "////////    Total score: " << diller_score;
	if (diller_score < 1 || diller_score > 9)
		std::cout << " ";
	else
		std::cout << "  ";

	std::cout << "    ////|" << std::endl;
	std::cout << "//////////////////////////////////////|";
	std::cout << " ";
	std::cout << "////////////////////////////////////|" << std::endl;
	std::cout << "Money: " << account;

	if (account < 1000000 && account >99999)
		std::cout << "";
	else if (account < 100000 && account >9999)
		std::cout << " ";
	else if (account < 10000 && account >999)
		std::cout << "  ";
	else if (account < 1000 && account >99)
		std::cout << "   ";
	else if (account < 100 && account >9)
		std::cout << "    ";
	else if (account < 10 && account >= 0)
		std::cout << "     ";

	std::cout << " /     \\ Your bet: " << *bet;

	if (*bet >= 10000)
		std::cout << " ";
	if (*bet < 10000 && *bet > 999)
		std::cout << "  ";
	else if (*bet <= 1000 && *bet > 99)
		std::cout << "   ";
	else if (*bet <= 100 && *bet > 9)
		std::cout << "    ";
	else if (*bet <= 10 && *bet >= 0)
		std::cout << "     ";

	std::cout << "| ////////////////////////////////////|" << std::endl;

	std::cout << "_____________/       \\________________|_____________________________________|" << std::endl;
}

int gameplay(DECK *deck, std::string player_name)
{
	const int n = 21;
	int diller_score = 0;
	int diller_kards = 2;
	int user_score = 0;
	int user_kards = 2;
	DECK diller[n];
	DECK user[n];
	//bet making

	std::cout << "Please choose your bet:" << std::endl;
	std::cout << "" << std::endl;
	int bet;
	std::cin >> bet;
	do
	{
		if (bet > account)
		{
			std::cout << "You have no enough money!" << std::endl;
			std::cout << "Please choose the right bet:" << std::endl;
			std::cin >> bet;
		}
	} while (bet > account);

	srand((unsigned)time(NULL));
	int diller_start_card;
	int user_start_card;
	diller_start_card = rand() % 52;
	diller[0].card_name = deck[diller_start_card].card_name;
	diller[0].card_score = deck[diller_start_card].card_score;
	deck[diller_start_card].card_name = "0";
	deck[diller_start_card].card_score = 0;

	do
		diller_start_card = rand() % 52;
	while (deck[diller_start_card].card_name == "0");

	diller[1].card_name = deck[diller_start_card].card_name;
	diller[1].card_score = deck[diller_start_card].card_score;
	deck[diller_start_card].card_name = "0";
	deck[diller_start_card].card_score = 0;

	do
		user_start_card = rand() % 52;
	while (deck[user_start_card].card_name == "0");

	user[0].card_name = deck[user_start_card].card_name;
	user[0].card_score = deck[user_start_card].card_score;
	deck[user_start_card].card_name = "0";
	deck[user_start_card].card_score = 0;

	do
		user_start_card = rand() % 52;
	while (deck[user_start_card].card_name == "0");

	user[1].card_name = deck[user_start_card].card_name;
	user[1].card_score = deck[user_start_card].card_score;
	deck[user_start_card].card_name = "0";
	deck[user_start_card].card_score = 0;

	diller_score = diller[0].card_score + diller[1].card_score;
	user_score = user[0].card_score + user[1].card_score;
	// displaying
	display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet);
	std::cout << "" << std::endl;
	// question
	std::cout << "" << std::endl;
	std::cout << "Do you need one more card...?" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "2 - PASS!" << std::endl;
	std::cout << "" << std::endl;

	int choise;
	std::cin >> choise;
	do
	{
		if (choise < 1 || choise >2)
		{
			std::cout << "Unknown command..." << std::endl;
			std::cout << "Please try again:" << std::endl;
			std::cin >> choise;
		}
	} while (choise < 1 || choise >2);

	switch (choise)
	{
	case 1:
		break;
	case 2:
		do
		{
			int next_rand;

			do
				next_rand = rand() % 52;
			while (deck[next_rand].card_name == "0");

			diller[diller_kards].card_name = deck[next_rand].card_name;
			diller[diller_kards].card_score = deck[next_rand].card_score;
			deck[next_rand].card_name = "0";
			deck[next_rand].card_score = 0;
			diller_score += diller[diller_kards].card_score;
			diller_kards++;

		} while (diller_score <= 16);

		check(user_score, diller_score, &bet);
		display_ALLresults(diller, user, user_score, user_kards, diller_score, diller_kards, player_name, &bet);
		return 0;
	default:
		break;
	}

	for (int i = 2; i < 18; i++)
	{
		//USER TURN
		int next_rand;
		do
			next_rand = rand() % 52;
		while (deck[next_rand].card_name == "0");

		user[i].card_name = deck[next_rand].card_name;
		user[i].card_score = deck[next_rand].card_score;
		deck[next_rand].card_name = "0";
		deck[next_rand].card_score = 0;
		user_score += user[i].card_score;
		user_kards++;
		if (user_score > 21)
		{
			check(user_score, diller_score, &bet);
			display_ALLresults(diller, user, user_score, user_kards, diller_score, diller_kards, player_name, &bet);
			break;
		}
		//displaying
		display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet);
		//question
		std::cout << "" << std::endl;
		std::cout << "Do you need one more...?" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1 - yes" << std::endl;
		std::cout << "2 - PASS!" << std::endl;
		std::cout << "" << std::endl;

		int choise;
		std::cin >> choise;
		do
		{
			if (choise < 1 || choise >2)
			{
				std::cout << "Unknown command..." << std::endl;
				std::cout << "Please try again:" << std::endl;
				std::cin >> choise;
			}
		} while (choise < 1 || choise >2);

		switch (choise)
		{
		case 1:
			break;
		case 2:
			do
			{
				int rand1;
			onemor10:
				rand1 = rand() % 52;
				if (deck[rand1].card_name == "0")
					goto onemor10;
				diller[diller_kards].card_name = deck[rand1].card_name;
				diller[diller_kards].card_score = deck[rand1].card_score;
				deck[rand1].card_name = "0";
				deck[next_rand].card_score = 0;
				diller_score += diller[diller_kards].card_score;
				diller_kards++;

			} while (diller_score <= 16);
			check(user_score, diller_score, &bet);
			display_ALLresults(diller, user, user_score, user_kards, diller_score, diller_kards, player_name, &bet);
			return 0;
		default:
			break;
		}
	}
	return 0;
}

void new_deck(DECK *deck)
{
	deck[0].card_name = "2 :3";
	deck[0].card_score = 2;
	deck[1].card_name = "2 B";
	deck[1].card_score = 2;
	deck[2].card_name = "2 K";
	deck[2].card_score = 2;
	deck[3].card_name = "2 P";
	deck[3].card_score = 2;
	deck[4].card_name = "3 :3";
	deck[4].card_score = 3;
	deck[5].card_name = "3 B";
	deck[5].card_score = 3;
	deck[6].card_name = "3 K";
	deck[6].card_score = 3;
	deck[7].card_name = "3 P";
	deck[7].card_score = 3;
	deck[8].card_name = "4 :3";
	deck[8].card_score = 4;
	deck[9].card_name = "4 B";
	deck[9].card_score = 4;
	deck[10].card_name = "4 K";
	deck[10].card_score = 4;
	deck[11].card_name = "4 P";
	deck[11].card_score = 4;
	deck[12].card_name = "5 :3";
	deck[12].card_score = 5;
	deck[13].card_name = "5 B";
	deck[13].card_score = 5;
	deck[14].card_name = "5 K";
	deck[14].card_score = 5;
	deck[15].card_name = "5 P";
	deck[15].card_score = 5;
	deck[16].card_name = "6 :3";
	deck[16].card_score = 6;
	deck[17].card_name = "6 B";
	deck[17].card_score = 6;
	deck[18].card_name = "6 K";
	deck[18].card_score = 6;
	deck[19].card_name = "6 P";
	deck[19].card_score = 6;
	deck[20].card_name = "7 :3";
	deck[20].card_score = 7;
	deck[21].card_name = "7 B";
	deck[21].card_score = 7;
	deck[22].card_name = "7 K";
	deck[22].card_score = 7;
	deck[23].card_name = "7 P";
	deck[23].card_score = 7;
	deck[24].card_name = "8 :3";
	deck[24].card_score = 8;
	deck[25].card_name = "8 B";
	deck[25].card_score = 8;
	deck[26].card_name = "8 K";
	deck[26].card_score = 8;
	deck[27].card_name = "8 P";
	deck[27].card_score = 8;
	deck[28].card_name = "9 :3";
	deck[28].card_score = 9;
	deck[29].card_name = "9 B";
	deck[29].card_score = 9;
	deck[30].card_name = "9 K";
	deck[30].card_score = 9;
	deck[31].card_name = "9 P";
	deck[31].card_score = 9;
	deck[32].card_name = "10 :3";
	deck[32].card_score = 10;
	deck[33].card_name = "10 B";
	deck[33].card_score = 10;
	deck[34].card_name = "10 K";
	deck[34].card_score = 10;
	deck[35].card_name = "10 P";
	deck[35].card_score = 10;
	deck[36].card_name = "V :3";
	deck[36].card_score = 10;
	deck[37].card_name = "V B";
	deck[37].card_score = 10;
	deck[38].card_name = "V K";
	deck[38].card_score = 10;
	deck[39].card_name = "V P";
	deck[39].card_score = 10;
	deck[40].card_name = "D :3";
	deck[40].card_score = 10;
	deck[41].card_name = "D B";
	deck[41].card_score = 10;
	deck[42].card_name = "D K";
	deck[42].card_score = 10;
	deck[43].card_name = "D P";
	deck[43].card_score = 10;
	deck[44].card_name = "K :3";
	deck[44].card_score = 10;
	deck[45].card_name = "K B";
	deck[45].card_score = 10;
	deck[46].card_name = "K K";
	deck[46].card_score = 10;
	deck[47].card_name = "K P";
	deck[47].card_score = 10;
	deck[48].card_name = "T :3";
	deck[48].card_score = 1;
	deck[49].card_name = "T B";
	deck[49].card_score = 1;
	deck[50].card_name = "T K";
	deck[50].card_score = 1;
	deck[51].card_name = "T P";
	deck[51].card_score = 1;
}

int main()
{
	DECK deck[52];
	new_deck(deck);
	std::string player_name;
	std::cout << "" << std::endl;
	std::cout << "$$$$$___$$_______$$$$____$$$$___$$__$$__$$$$$$___$$$$____$$$$___$$__$$" << std::endl;
	std::cout << "$$__$$__$$______$$__$$__$$__$$__$$_$$_______$$__$$__$$__$$__$$__$$_$$" << std::endl;
	std::cout << "$$$$$___$$______$$$$$$__$$______$$$$________$$__$$$$$$__$$______$$$$" << std::endl;
	std::cout << "$$__$$__$$______$$__$$__$$__$$__$$_$$___$$__$$__$$__$$__$$__$$__$$_$$" << std::endl;
	std::cout << "$$$$$___$$$$$$__$$__$$___$$$$___$$__$$___$$$$___$$__$$___$$$$___$$__$$" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "_________$$$$____$$$$___$$___$$__$$$$$" << std::endl;
	std::cout << "________$$______$$__$$__$$$_$$$__$$" << std::endl;
	std::cout << "________$$_$$$__$$$$$$__$$_$_$$__$$$$" << std::endl;
	std::cout << "________$$__$$__$$__$$__$$___$$__$$" << std::endl;
	std::cout << "_________$$$$___$$__$$__$$___$$__$$$$$" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "Please enter your name:" << std::endl;
	std::cout << "" << std::endl;

	int player_name_size = player_name.length();
	do
	{
		if (player_name_size > 20)
		{
			std::cout << "Your name is too long..." << std::endl;
			std::cout << "Please try again:" << std::endl;
		}
		std::getline(std::cin, player_name);
		player_name_size = player_name.length();
	} while (player_name_size > 20);

	std::cout << "" << std::endl;
	std::cout << "Your money is: " << account << std::endl;

	for (int i = 0; ; i++)
	{
		if (account == 0)
		{
			std::cout << "|" << std::endl;
			std::cout << "|" << std::endl;
			std::cout << "|" << std::endl;
			std::cout << "|" << std::endl;
			std::cout << "|   ///////////////////////////////////" << std::endl;
			std::cout << "|  ///// Sory you have no money! /////" << std::endl;
			std::cout << "| /////   Your game is over!    /////" << std::endl;
			std::cout << "|///////////////////////////////////" << std::endl;
			std::cout << "" << std::endl;
			break;
		}
		gameplay(deck, player_name);
		system("PAUSE");
		if (account != 0)
		{
			for (int i = 0; i<40; i++)
				std::cout << "" << std::endl;
		}
	}
	return 0;
}