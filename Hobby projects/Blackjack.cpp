#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <random>

/*
- Do next ideas...
*/

int account = 1000;

struct DECK
{
	std::string card_name;
	int card_score;
};

int char_int(char *array)
{
	/*
	- Number no more than 999999999;
	- Quantity of characters no more than 9;
	- Error code: -1.
	*/
	int out_int = 0;
	int l = strlen(array);
	int check = 0;
	char *n;
	n = array;

	if (l >= 9)
		return -1;

	for (int i = 0; i < l; i++)
	{
		if (*n != '1' && *n != '2' && *n != '3' && *n != '4' && *n != '5' && *n != '6' && *n != '7' && *n != '8' && *n != '9' && *n != '0')
		{
			check++;
		}
		n++;
	}

	n = array;


	if (check == 0)
	{
		for (int i = 0; i < l; i++, n++)
		{
			if (i == 0)
			{
				if (*n == '1')
					out_int = 1;
				if (*n == '2')
					out_int = 2;
				if (*n == '3')
					out_int = 3;
				if (*n == '4')
					out_int = 4;
				if (*n == '5')
					out_int = 5;
				if (*n == '6')
					out_int = 6;
				if (*n == '7')
					out_int = 7;
				if (*n == '8')
					out_int = 8;
				if (*n == '9')
					out_int = 9;
				if (*n == '0')
					return -1;
			}
			else
			{
				if (*n == '1')
					out_int = out_int * 10 + 10 - 9;
				if (*n == '2')
					out_int = out_int * 10 + 10 - 8;
				if (*n == '3')
					out_int = out_int * 10 + 10 - 7;
				if (*n == '4')
					out_int = out_int * 10 + 10 - 6;
				if (*n == '5')
					out_int = out_int * 10 + 10 - 5;
				if (*n == '6')
					out_int = out_int * 10 + 10 - 4;
				if (*n == '7')
					out_int = out_int * 10 + 10 - 3;
				if (*n == '8')
					out_int = out_int * 10 + 10 - 2;
				if (*n == '9')
					out_int = out_int * 10 + 10 - 1;
				if (*n == '0')
					out_int = out_int * 10;
			}
		}
		return out_int;
	}
	else
		return -1;
}

int ace_check(DECK *deck, int *n_cards)
{
	int score = 0;

	for (int k = 0; k <= *n_cards; k++)
		score = score + deck[k].card_score;

	for (int i = 0; i <= *n_cards; i++)
		if (deck[i].card_name == "T :3" || deck[i].card_name == "T B" || deck[i].card_name == "T K" || deck[i].card_name == "T P")
		{
			if (score > 21)
			{
				deck[i].card_score = 1;
			}
		}

	score = 0;

	for (int k = 0; k <= *n_cards; k++)
		score = score + deck[k].card_score;

	return score;
}

void check(int user_score, int diller_skore, int *bet, int user2_score = 0, int *bet2 = 0, int double_game = 0)
{
	if (double_game != 0)
	{
		if ((diller_skore < user_score && user_score <= 21) || (diller_skore < user2_score && user2_score <= 21))
		{
			std::cout << "" << std::endl;
			std::cout << "        __     __          __          _______ _   _   _ " << std::endl;
			std::cout << "        \\ \\   / /          \\ \\        / /_   _| \\ | | | |" << std::endl;
			std::cout << "         \\ \\_/ /__  _   _   \\ \\  /\\  / /  | | |  \\| | | |" << std::endl;
			std::cout << "          \\   / _ \\| | | |   \\ \\/  \\/ /   | | | . ` | | |" << std::endl;
			std::cout << "           | | (_) | |_| |    \\  /\\  /   _| |_| |\\  | |_|" << std::endl;
			std::cout << "           |_|\\___/ \\__,_|     \\/  \\/   |_____|_| \\_| (_)" << std::endl;
			std::cout << "" << std::endl;
			if (user_score > diller_skore && user2_score > diller_skore && user_score <= 21 && user2_score <= 21)
				account += *bet + *bet2;
			return;
		}
		if ((diller_skore > user_score && user_score <= 21 && diller_skore > 21) || (diller_skore > user2_score && user2_score <= 21 && diller_skore > 21))
		{
			std::cout << "" << std::endl;
			std::cout << "          __     __          __          _______ _   _   _ " << std::endl;
			std::cout << "          \\ \\   / /          \\ \\        / /_   _| \\ | | | |" << std::endl;
			std::cout << "           \\ \\_/ /__  _   _   \\ \\  /\\  / /  | | |  \\| | | |" << std::endl;
			std::cout << "            \\   / _ \\| | | |   \\ \\/  \\/ /   | | | . ` | | |" << std::endl;
			std::cout << "             | | (_) | |_| |    \\  /\\  /   _| |_| |\\  | |_|" << std::endl;
			std::cout << "             |_|\\___/ \\__,_|     \\/  \\/   |_____|_| \\_| (_)" << std::endl;
			std::cout << "" << std::endl;
			if (diller_skore > user_score && diller_skore > user2_score && diller_skore > 21)
				account += *bet + *bet2;
			return;
		}


		if ((user_score > diller_skore && user_score > 21 && diller_skore <= 21) && (user2_score > diller_skore && user2_score > 21 && diller_skore <= 21))
		{
			std::cout << "" << std::endl;
			std::cout << "       __     __           _      ____   _____ ______ _ " << std::endl;
			std::cout << "       \\ \\   / /          | |    / __ \\ / ____|  ____| |" << std::endl;
			std::cout << "        \\ \\_/ /__  _   _  | |   | |  | | (___ | |__  | |" << std::endl;
			std::cout << "         \\   / _ \\| | | | | |   | |  | |\\___ \\|  __| | |" << std::endl;
			std::cout << "          | | (_) | |_| | | |___| |__| |____) | |____|_|" << std::endl;
			std::cout << "          |_|\\___/ \\__,_| |______\\____/|_____/|______(_)" << std::endl;
			std::cout << "" << std::endl;
			account = account - *bet - *bet2;
			return;
		}
		if ((diller_skore > user_score && diller_skore <= 21) || (diller_skore > user2_score && diller_skore <= 21))
		{
			std::cout << "" << std::endl;
			std::cout << "          __     __           _      ____   _____ ______ _ " << std::endl;
			std::cout << "          \\ \\   / /          | |    / __ \\ / ____|  ____| |" << std::endl;
			std::cout << "           \\ \\_/ /__  _   _  | |   | |  | | (___ | |__  | |" << std::endl;
			std::cout << "            \\   / _ \\| | | | | |   | |  | |\\___ \\|  __| | |" << std::endl;
			std::cout << "             | | (_) | |_| | | |___| |__| |____) | |____|_|" << std::endl;
			std::cout << "             |_|\\___/ \\__,_| |______\\____/|_____/|______(_)" << std::endl;
			std::cout << "" << std::endl;
			account = account - *bet - *bet2;
			return;
		}


		if (((diller_skore == user_score) && (diller_skore <= 21)) || ((diller_skore == user2_score) && (diller_skore <= 21)) || ((diller_skore == user2_score == user_score) && diller_skore <= 21))
		{
			std::cout << "" << std::endl;
			std::cout << "              $$$$$____$$$$$_____$$$$____$$___$$_______$$$" << std::endl;
			std::cout << "              $$__$$___$$__$$___$$__$$___$$___$$_______$$$" << std::endl;
			std::cout << "              $$__$$___$$$$$____$$$$$$___$$_$_$$_______$$$" << std::endl;
			std::cout << "              $$__$$___$$__$$___$$__$$___$$$$$$$" << std::endl;
			std::cout << "              $$$$$____$$__$$___$$__$$____$$_$$________$$$" << std::endl;
			std::cout << "" << std::endl;
			return;
		}
	}
	else
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
		if (diller_skore == user_score)
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
}

void display_results(DECK *diller, DECK *user, int user_score, int user_kards, int diller_kards, std::string player_name, int *bet, int double_game = 0, DECK *user2 = 0, int *bet2 = 0, int user2_score = 0, int user2_kards = 0, int hidden = 0, int diller_score = 0)
{
	// DOUBLE_CHECK:

	if (double_game)                                                             //<---- if double_game == 1 -----> THIS doing!
	{
		//formatting header
		std::cout << "" << std::endl;
		std::cout << "           " << player_name << " 1 BET:";
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
			if (user[i].card_name == "0")
				std::cout << "                                      | ";
			else
			{

				int l = user[i].card_name.length();
				std::cout << "  #" << i + 1 << " card:  " << user[i].card_name;
				std::cout << "     ";
				for (l; l != 5; l++)
					std::cout << " ";
				std::cout << "card score:  " << user[i].card_score;

				if (user[i].card_score < 0 || user[i].card_score > 9)
					std::cout << " ";
				else
					std::cout << "  ";

				std::cout << "|";
				std::cout << " ";
			}

			if (diller[i].card_name == "0")
				std::cout << "                                    |" << std::endl;
			else
			{

				int m = diller[k].card_name.length();
				if (hidden == 0)
				{
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
		std::cout << "////////    Total score: ";
		if (hidden == 0)
			std::cout << "?  ";
		else
		{
			std::cout << diller_score;
			if (diller_score < 1 || diller_score > 9)
				std::cout << " ";
			else
				std::cout << "  ";
		}

		std::cout << "    ////|" << std::endl;
		std::cout << "//////////////////////////////////////|";
		std::cout << " ";
		std::cout << "////////////////////////////////////|" << std::endl;
		std::cout << "Money: " << account - *bet - *bet2;

		if ((account - *bet - *bet2) < 1000000 && (account - *bet - *bet2) >99999)
			std::cout << "";
		else if ((account - *bet - *bet2) < 100000 && (account - *bet - *bet2) >9999)
			std::cout << " ";
		else if ((account - *bet - *bet2) < 10000 && (account - *bet - *bet2) >999)
			std::cout << "  ";
		else if ((account - *bet - *bet2) < 1000 && (account - *bet - *bet2) >99)
			std::cout << "   ";
		else if ((account - *bet - *bet2) < 100 && (account - *bet - *bet2) >9)
			std::cout << "    ";
		else if ((account - *bet - *bet2) < 10 && (account - *bet - *bet2) >= 0)
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




		//////////////////////////////////////////////////////////// 2 CARDS:



		std::cout << "" << std::endl;
		std::cout << "           " << player_name << " 2 BET:" << std::endl;


		std::cout << "______________________________________" << std::endl;


		//formatting of table
		for (int i = 0; i < user2_kards; i++)
		{
			int l = user2[i].card_name.length();
			std::cout << "  #" << i + 1 << " card:  " << user2[i].card_name;
			std::cout << "     ";
			for (l; l != 5; l++)
				std::cout << " ";
			std::cout << "card score:  " << user2[i].card_score;
			if (user2[i].card_score < 0 || user2[i].card_score > 9)
				std::cout << " ";
			else
				std::cout << "  ";

			std::cout << "|" << std::endl;
		}
		//formatting bottom
		std::cout << "//////////////////////////////////////|" << std::endl;
		std::cout << "////////    Total score: " << user2_score;

		if (user2_score < 1 || user2_score > 9)
			std::cout << " ";
		else
			std::cout << "  ";

		std::cout << "    //////|" << std::endl;
		std::cout << "//////////////////////////////////////|" << std::endl;

		std::cout << "Money: " << account - *bet - *bet2;

		if ((account - *bet - *bet2) < 1000000 && (account - *bet - *bet2) >99999)
			std::cout << "";
		else if ((account - *bet - *bet2) < 100000 && (account - *bet - *bet2) >9999)
			std::cout << " ";
		else if ((account - *bet - *bet2) < 10000 && (account - *bet - *bet2) >999)
			std::cout << "  ";
		else if ((account - *bet - *bet2) < 1000 && (account - *bet - *bet2) >99)
			std::cout << "   ";
		else if ((account - *bet - *bet2) < 100 && (account - *bet - *bet2) >9)
			std::cout << "    ";
		else if ((account - *bet - *bet2) < 10 && (account - *bet - *bet2) >= 0)
			std::cout << "     ";

		std::cout << " /     \\ Your bet: " << *bet;

		if (*bet2 >= 10000)
			std::cout << " ";
		if (*bet2 < 10000 && *bet > 999)
			std::cout << "  ";
		else if (*bet2 <= 1000 && *bet > 99)
			std::cout << "   ";
		else if (*bet2 <= 100 && *bet > 9)
			std::cout << "    ";
		else if (*bet2 <= 10 && *bet >= 0)
			std::cout << "     ";

		std::cout << "|" << std::endl;

		std::cout << "_____________/       \\________________|" << std::endl;


		//////////////////////////////////////////
	}
	else
	{
		//formatting header
		std::cout << "" << std::endl;
		std::cout << "           " << player_name << " CARDS:";
		std::cout << " ";
		std::cout << "                       DILLER CARDS:" << std::endl;
		std::cout << "______________________________________";
		std::cout << " ";
		std::cout << "_____________________________________" << std::endl;
		//formatting of table
		for (int i = 0, k = 0; i < user_kards || k < diller_kards; i++, k++)
		{
			if (user[i].card_name == "0")
				std::cout << "                                      | ";
			else
			{

				int l = user[i].card_name.length();
				std::cout << "  #" << i + 1 << " card:  " << user[i].card_name;
				std::cout << "     ";
				for (l; l != 5; l++)
					std::cout << " ";
				std::cout << "card score:  " << user[i].card_score;

				if (user[i].card_score < 0 || user[i].card_score > 9)
					std::cout << " ";
				else
					std::cout << "  ";

				std::cout << "|";
				std::cout << " ";
			}

			if (diller[i].card_name == "0")
				std::cout << "                                    |" << std::endl;
			else
			{

				int m = diller[k].card_name.length();
				if (hidden == 0)
				{
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
						std::cout << "card score:  " << diller[k].card_score;
						if (diller[k].card_score < 0 || diller[k].card_score > 9)
							std::cout << " ";
						else
							std::cout << "  ";
						std::cout << "|" << std::endl;
					}
				}
				else
				{
					std::cout << "#" << k + 1 << " card:  " << diller[k].card_name;
					std::cout << "     ";
					for (m; m != 5; m++)
						std::cout << " ";
					std::cout << "card score:  " << diller[k].card_score;
					if (diller[k].card_score < 0 || diller[k].card_score > 9)
						std::cout << " ";
					else
						std::cout << "  ";
					std::cout << "|" << std::endl;
				}
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
		std::cout << "////////    Total score: ";
		if (hidden == 0)
			std::cout << "?  ";
		else
		{
			std::cout << diller_score;
			if (diller_score < 1 || diller_score > 9)
				std::cout << " ";
			else
				std::cout << "  ";
		}

		std::cout << "    ////|" << std::endl;
		std::cout << "//////////////////////////////////////|";
		std::cout << " ";
		std::cout << "////////////////////////////////////|" << std::endl;
		std::cout << "Money: " << account - *bet - *bet2;

		if ((account - *bet - *bet2) < 1000000 && (account - *bet - *bet2) >99999)
			std::cout << "";
		else if ((account - *bet - *bet2) < 100000 && (account - *bet - *bet2) >9999)
			std::cout << " ";
		else if ((account - *bet - *bet2) < 10000 && (account - *bet - *bet2) >999)
			std::cout << "  ";
		else if ((account - *bet - *bet2) < 1000 && (account - *bet - *bet2) >99)
			std::cout << "   ";
		else if ((account - *bet - *bet2) < 100 && (account - *bet - *bet2) >9)
			std::cout << "    ";
		else if ((account - *bet - *bet2) < 10 && (account - *bet - *bet2) >= 0)
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

}

int gameplay(DECK *deck, std::string player_name)
{
	const int n = 21;
	int diller_score = 0;
	int diller_kards = 2;
	int user_score = 0;
	int user_kards = 2;

	DECK diller[n];
	for (int i = 0; i < n; i++)
		diller[i].card_name = "0";
	for (int i = 0; i < n; i++)
		diller[i].card_score = 0;

	DECK user[n];
	for (int i = 0; i < n; i++)
		user[i].card_name = "0";
	for (int i = 0; i < n; i++)
		user[i].card_score = 0;

	int double_game = 0;
	int hidden = 0;

	DECK user2[n];
	for (int i = 0; i < n; i++)
		user2[i].card_name = "0";
	for (int i = 0; i < n; i++)
		user2[i].card_score = 0;

	int bet2 = 0;
	int user2_score = 0;
	int user2_kards = 0;

	//bet making

	int bet;
	char char_bet[10];
	std::cout << "" << std::endl;
	std::cout << "Your money is: " << account << std::endl;
	std::cout << "Please make your bet:" << std::endl;
	std::cout << "" << std::endl;


	gets_s(char_bet);

	if (char_int(char_bet) > account || char_int(char_bet) == -1 || char_int(char_bet) == 0)
	{
		do
		{
			if (char_int(char_bet) > account)
			{
				std::cout << "" << std::endl;
				std::cout << "This bet is too much. You have no enough money!" << std::endl;
				std::cout << "Change your bet, please..." << std::endl;
				std::cout << "" << std::endl;
			}
			if (char_int(char_bet) == -1 || char_int(char_bet) == 0)
			{

				std::cout << "" << std::endl;
				std::cout << "Enter bet correctly:" << std::endl;
				std::cout << "" << std::endl;
			}
			gets_s(char_bet);
		} while (char_int(char_bet) > account || char_int(char_bet) == -1 || char_int(char_bet) == 0);
	}

	bet = char_int(char_bet);

	srand((unsigned)time(NULL));
	int diller_start_card = 0;
	int user_start_card = 0;
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

	/////////////////////////////////////////////////////////Double cards by a hand

	/*
	user[0].card_name = deck[44].card_name;
	user[0].card_score = deck[44].card_score;
	deck[44].card_name = "0";
	deck[44].card_score = 0;

	do
	user_start_card = rand() % 52;
	while (deck[user_start_card].card_name == "0");

	user[1].card_name = deck[45].card_name;
	user[1].card_score = deck[45].card_score;
	deck[45].card_name = "0";
	deck[45].card_score = 0;
	*/
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

	/////////////////////////////////////////////////////////Double cards by a hand

	diller_score = diller[0].card_score + diller[1].card_score;
	user_score = user[0].card_score + user[1].card_score;
	// displaying
	display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
	std::cout << "" << std::endl;
	// question
	std::cout << "" << std::endl;
	std::cout << "Do you need one more card...?" << std::endl;
	std::cout << "" << std::endl;
	std::cout << "1 - yes" << std::endl;
	std::cout << "2 - PASS!" << std::endl;
	std::cout << "" << std::endl;
	if (user[0].card_score == user[1].card_score)
	{
		if ((account - bet * 2) < 0)
		{
			std::cout << "You have no money for SPLIT..." << std::endl;
			std::cout << "" << std::endl;
		}
		else
		{
			std::cout << "3 - SPLIT!" << std::endl;
			std::cout << "" << std::endl;
		}
	}

	int choise;
	char char_choise[100];

	gets_s(char_choise);

	if ((user[0].card_score == user[1].card_score) && ((account - 2 * bet) >= 0))
	{
		if (char_int(char_choise) != 1 && char_int(char_choise) != 2 && char_int(char_choise) != 3)
		{
			do
			{
				std::cout << "Please make your choice correctly!" << std::endl;
				std::cout << std::endl;

				gets_s(char_choise);

			} while (char_int(char_choise) != 1 && char_int(char_choise) != 2 && char_int(char_choise) != 3);
		}
	}
	else
	{
		if (char_int(char_choise) != 1 && char_int(char_choise) != 2)
		{
			do
			{
				std::cout << "Please make your choice correctly!" << std::endl;
				std::cout << std::endl;

				gets_s(char_choise);

			} while (char_int(char_choise) != 1 && char_int(char_choise) != 2);
		}
	}

	choise = char_int(char_choise);

	switch (choise)
	{
	case 1:
		break;
	case 2:
		if (diller_score >= 17)
		{
			hidden = 1;
			display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
			check(user_score, diller_score, &bet, user2_score, &bet2, double_game);
			return 0;
		}
		else
		{
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
				diller_score = ace_check(diller, &diller_kards);
				diller_kards++;
			} while (diller_score <= 16);

			hidden = 1;
			display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
			check(user_score, diller_score, &bet, user2_score, &bet2, double_game);
			return 0;
		}

		if ((user[0].card_score == user[1].card_score) && ((account - 2 * bet) >= 0))
		{
	case 3:
		double_game = 1;
		break;
		}
	}

	for (int i = 2; i < 18; i++)
	{
		if (double_game)
			break;
		//USER TURN
		int next_rand;
		do
			next_rand = rand() % 52;
		while (deck[next_rand].card_name == "0");

		user[i].card_name = deck[next_rand].card_name;
		user[i].card_score = deck[next_rand].card_score;
		deck[next_rand].card_name = "0";
		deck[next_rand].card_score = 0;
		user_score = ace_check(user, &user_kards);
		user_kards++;
		if (user_score > 21)
		{
			hidden = 1;
			display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
			check(user_score, diller_score, &bet);
			break;
		}
		//displaying
		display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
		//question
		std::cout << "" << std::endl;
		std::cout << "Do you need one more...?" << std::endl;
		std::cout << "" << std::endl;
		std::cout << "1 - yes" << std::endl;
		std::cout << "2 - PASS!" << std::endl;
		std::cout << "" << std::endl;

		int choise;
		char char_choise[100];

		gets_s(char_choise);

		if (char_int(char_choise) != 1 && char_int(char_choise) != 2)
		{
			do
			{
				std::cout << "Please make your choice correctly!" << std::endl;
				std::cout << std::endl;

				gets_s(char_choise);

			} while (char_int(char_choise) != 1 && char_int(char_choise) != 2);
		}

		choise = char_int(char_choise);

		switch (choise)
		{
		case 1:
			break;
		case 2:
			if (diller_score >= 17)
			{
				hidden = 1;
				display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
				check(user_score, diller_score, &bet);
				return 0;
			}
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
				diller_score = ace_check(diller, &diller_kards);
				diller_kards++;
			} while (diller_score <= 16);

			hidden = 1;
			display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
			check(user_score, diller_score, &bet);
			return 0;
		}
	}

	// DOUBLE game starts://////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (double_game)
	{
		bet2 = bet;
		user2[0].card_name = user[1].card_name;
		user2[0].card_score = user[1].card_score;
		user[1].card_name = '0';
		user[1].card_score = 0;
		user2_score = user2[0].card_score;
		user_score = user[0].card_score;
		user2_kards = 1;
		user_kards = 1;
		int first_bet_status = 0;


		//USER 1 BET TURN

		for (int i = 0; i < 18; i++)
		{
			if (i != 0)
			{
				int next_rand;
				do
					next_rand = rand() % 52;
				while (deck[next_rand].card_name == "0");

				user[i].card_name = deck[next_rand].card_name;
				user[i].card_score = deck[next_rand].card_score;
				deck[next_rand].card_name = "0";
				deck[next_rand].card_score = 0;
				user_score = ace_check(user, &user_kards);
				user_kards++;
				if (user_score > 21)
				{
					display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
					std::cout << "\\" << std::endl;
					std::cout << " \\" << std::endl;
					std::cout << "  \\" << std::endl;
					std::cout << " __\\________________________________" << std::endl;
					std::cout << "|                                   |" << std::endl;
					std::cout << "|     Your FIRST bet has lost!      |" << std::endl;
					std::cout << "|    Please play with another bet   |" << std::endl;
					std::cout << "|___________________________________|" << std::endl;
					std::cout << "" << std::endl;
					system("PAUSE");
					break;
				}
			}
			//displaying
			display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
			//question
			std::cout << "" << std::endl;
			std::cout << "Do you need one more card...? (for 1 BET)" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "1 - yes" << std::endl;
			std::cout << "2 - PASS!" << std::endl;
			std::cout << "" << std::endl;

			int choise;
			char char_choise[100];

			gets_s(char_choise);

			if (char_int(char_choise) != 1 && char_int(char_choise) != 2)
			{
				do
				{
					std::cout << "Please make your choice correctly!" << std::endl;
					std::cout << std::endl;

					gets_s(char_choise);

				} while (char_int(char_choise) != 1 && char_int(char_choise) != 2);
			}

			choise = char_int(char_choise);

			switch (choise)
			{
			case 1:
				break;
			case 2:
				first_bet_status = 1;
			}
			if (choise == 2)
				break;
		}


		//////////////////////////2 BET


		for (int i = 0; i < 18; i++)
		{
			if (i != 0)
			{
				int next_rand;
				do
					next_rand = rand() % 52;
				while (deck[next_rand].card_name == "0");

				user2[i].card_name = deck[next_rand].card_name;
				user2[i].card_score = deck[next_rand].card_score;
				deck[next_rand].card_name = "0";
				deck[next_rand].card_score = 0;
				user2_score = ace_check(user2, &user2_kards);
				user2_kards++;
				if (user2_score > 21)
				{
					if (!first_bet_status)
					{
						hidden = 1;
						display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
						check(user_score, diller_score, &bet, user2_score, &bet2, double_game);
						break;
					}
					else
					{
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
							diller_score = ace_check(diller, &diller_kards);
							diller_kards++;
						} while (diller_score <= 16);

						hidden = 1;
						display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
						check(user_score, diller_score, &bet, user2_score, &bet2, double_game);
						return 0;
					}
				}
			}
			//displaying
			display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
			//question
			std::cout << "" << std::endl;
			std::cout << "Do you need one more card...? (for 2 BET)" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "1 - yes" << std::endl;
			std::cout << "2 - PASS!" << std::endl;
			std::cout << "" << std::endl;

			int choise;
			char char_choise[100];

			gets_s(char_choise);

			if (char_int(char_choise) != 1 && char_int(char_choise) != 2)
			{
				do
				{
					std::cout << "Please make your choice correctly!" << std::endl;
					std::cout << std::endl;

					gets_s(char_choise);

				} while (char_int(char_choise) != 1 && char_int(char_choise) != 2);
			}

			choise = char_int(char_choise);

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
					diller_score = ace_check(diller, &diller_kards);
					diller_kards++;
				} while (diller_score <= 16);

				hidden = 1;
				display_results(diller, user, user_score, user_kards, diller_kards, player_name, &bet, double_game, user2, &bet2, user2_score, user2_kards, hidden, diller_score);
				check(user_score, diller_score, &bet, user2_score, &bet2, double_game);
				return 0;
			}
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
	deck[48].card_score = 11;
	deck[49].card_name = "T B";
	deck[49].card_score = 11;
	deck[50].card_name = "T K";
	deck[50].card_score = 11;
	deck[51].card_name = "T P";
	deck[51].card_score = 11;
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


	for (int i = 0; ; i++)
	{
		new_deck(deck);

		if (account == 0)
		{
			std::cout << "|" << std::endl;
			std::cout << "|" << std::endl;
			std::cout << "|" << std::endl;
			std::cout << "|" << std::endl;
			std::cout << "|   ///////////////////////////////////" << std::endl;
			std::cout << "|  ///// Sorry you have no money! /////" << std::endl;
			std::cout << "| ///// Could you invest more?  /////" << std::endl;
			std::cout << "|///////////////////////////////////" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "" << std::endl;
			std::cout << "1 - yes" << std::endl;
			std::cout << "2 - EXIT game" << std::endl;
			std::cout << "" << std::endl;

			int choise = 0;
			char char_choise[20];
			gets_s(char_choise);

			if (char_int(char_choise) < 1 || char_int(char_choise) > 2)
			{
				do
				{
					std::cout << "" << std::endl;
					std::cout << "Please enter your choise correctly:" << std::endl;
					std::cout << "" << std::endl;
					gets_s(char_choise);
					std::cout << "" << std::endl;
				} while (char_int(char_choise) < 1 || char_int(char_choise) > 2);
			}

			choise = char_int(char_choise);

			switch (choise)
			{
			case 1:
				char char_account[20];

				std::cout << "" << std::endl;
				std::cout << "Please enter the size of your investing:" << std::endl;
				std::cout << "" << std::endl;

				gets_s(char_account);

				if (char_int(char_account) > 10000 || char_int(char_account) == -1)
				{
					do
					{
						if (char_int(char_account) > 10000)
						{
							std::cout << "" << std::endl;
							std::cout << "Sorry but one invest can't be more than 10 000" << std::endl;
							std::cout << "Please try again:" << std::endl;
							std::cout << "" << std::endl;
							gets_s(char_account);
							std::cout << "" << std::endl;
						}
						if (char_int(char_account) == -1)
						{
							std::cout << "Please enter your investing correctly..." << std::endl;
							std::cout << "" << std::endl;
							gets_s(char_account);
							std::cout << "" << std::endl;
						}
					} while (char_int(char_account) > 10000 || char_int(char_account) == -1);
				}
				account = char_int(char_account);
				break;
			case 2:
				return 0;
			}
		}
		gameplay(deck, player_name);
		system("PAUSE");

		std::cout << '\n';
		if (account != 0)
		{
			for (int i = 0; i<40; i++)
				std::cout << "" << std::endl;
		}
	}
	return 0;
}