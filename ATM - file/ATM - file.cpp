#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
#include "ania.h"

using namespace std;


int main()
{
	string cards[5][5] = { {"123456789012","123456789012","123456789012","123456789012","123456789012"},
		{"123456789012","123456789012","123456789012","123456789012","123456789012"},
		{"123456789012","123456789012","123456789012","123456789012","123456789012"},
		{"123456789012","123456789012","123456789012","123456789012","123456789012"},
		{"123456789012","123456789012","123456789012","123456789012","123456789012"} };

	ifstream file("cards.txt");
	string line;
	int card = 0;
	string pin = "xxxx";
	string pin_card = "xxxx";
	char music = '0';
	int choice = 0;
	int amount = 0;
	int data = 0;
	bool exit = false;
	bool exit2 = false;
	string first = "0";
	string second = "0";
	bool OK = false;

	int i = 0, j = 0, k = 0, m = 0;

	while (getline(file, line))
	{
		j = 0;

		for (int l = 0; l < line.length(); l++)
		{

			if (line[l] != ' ')
			{
				cards[i][j][k] = line[l];
				k++;
			}
			else
			{
				cards[i][j].resize(k);
				/*for (int n = k; n < cards[i][j].length(); n++)
				{
					cards[i][j][n] = ' ';
				}*/

				j++;
				k = 0;

			}
		}

		i++;

	}

	file.close();

	while (1)
	{
		system("cls");
		system("Color 07");
		PlaySound(NULL, 0, 0);
		cout << "Insert a card: ";
		cin >> card;

		if (card == 9)break;
		if (card < 0 || card > 4)continue;
		
		if (cards[card][4] != "Blocked")
		{
			int tries = 3;

			for (int i = 0; i < 4; i++)
			{
				pin_card[i] = cards[card][2][i];
			}

			while (tries)
			{
				if (exit)
				{
					exit = false;
					break;
				}

				system("cls");
				system("Color 07");
				cout << "Enter PIN: ";
				cin >> pin;

				if (pin == pin_card)
				{
					system("cls");
					system("Color 09");
					cout << "You are logged in";
					clear_buf();
					system("cls");
					system("Color 07");
					cout << "Do you want to play music(y/n)? ";
					cin >> music;

					if (music == 'Y' || music == 'y')
					{
						PlaySound(L"victory.wav", NULL, SND_ASYNC);

						system("cls");
						system("Color 09");
						cout << "You are logged in";
						clear_buf();
						system("cls");
						system("Color 07");
						cout << "Do you want to stop music(y/n)? ";
						cin >> music;

						if (music == 'Y' || music == 'y')
						{
							PlaySound(NULL, 0, 0);
						}
					}

					system("cls");
					system("Color 09");
					cout << "You are logged in";
					clear_buf();
					int balance = stoi(cards[card][3]);

					while (1)
					{
						if (exit)break;
						system("cls");
						system("Color 09");
						cout << "1. Withdraw money\n2. Deposit money\n3. Check an account balance\n4. Change data\n5. Exit" << endl;
						cin >> choice;

						switch (choice)
						{
							case 1:

								do
								{
									system("cls");
									system("Color 09");
									cout << "Enter the amount: ";
									cin >> amount;

									if (amount % 10 != 0)
									{
										system("cls");
										system("Color 04");
										cout << "The amount must be a multiplication by 10";
										clear_buf();
									}

								} while (amount % 10 != 0);
								
								if (amount <= balance)
								{
									balance -= amount;
									system("cls");
									system("Color 09");
									cout << "You have withdrawn money";
									clear_buf();
								}
								
								else
								{
									system("cls");
									system("Color 04");
									cout << "You have not enough money";
									clear_buf();
								}
					
								cards[card][3] = to_string(balance);

								break;

							case 2:

								do
								{
									system("cls");
									system("Color 09");
									cout << "Enter the amount: ";
									cin >> amount;

									if (amount % 10 != 0)
									{
										system("cls");
										system("Color 04");
										cout << "The amount must be a multiplication by 10";
										clear_buf();
									}
								
								} while (amount % 10 != 0);
									
								balance += amount;
								system("cls");
								system("Color 09");
								cout << "You have deposited money";
								clear_buf();

								cards[card][3] = to_string(balance);
								break;

							case 3:

								system("cls");
								system("Color 09");
								cout << "You have " << balance << " PLN";
								clear_buf();
								break;

							case 4:

								while (1)
								{
									if (exit2)
									{
										exit2 = false;
										break;
									}

									system("cls");
									system("Color 09");
									cout << "What do you want to change? \n1. Name\n2. Surname\n3. PIN\n4. Check your data\n5. Exit\n";
									cin >> data;

									switch (data)
									{
										case 1:

											system("cls");
											cout << "Enter your name: ";
											cin >> cards[card][0];
											system("cls");
											cout << "You have changed your name\n";
											clear_buf();
											break;

										case 2:

											system("cls");
											cout << "Enter your surname: ";
											cin >> cards[card][1];
											system("cls");
											cout << "You have changed your surname";
											clear_buf();
											break;

										case 3:

											do
											{
												system("cls");
												system("Color 09");
												cout << "Enter a new PIN\n";
												cin >> first;
												system("cls");
												cout << "Confirm your PIN\n";
												cin >> second;

												if (first != second)
												{
													system("cls");
													system("Color 04");
													cout << "Your PINs are not the same";
													clear_buf();
												}

											} while (first != second);

											cards[card][2] = first;
											system("cls");
											system("Color 09");
											cout << "You have changed your PIN";
											clear_buf();
											break;

										case 4:

											system("cls");
											system("Color 09");
											cout << "Your name is " << cards[card][0] << endl;
											cout << "Your surname is " << cards[card][1] << endl;
											cout << "Your PIN is " << cards[card][2] << endl;
											clear_buf();
											break;

										case 5:

											exit2 = true;
											break;

										default:

											system("cls");
											system("Color 04");
											cout << "You entered the wrong option";
											clear_buf();
									}
								}

								break;

							case 5:

								exit = true;
								break;

							default:

								system("cls");
								system("Color 04");
								cout << "You have entered the wrong option";
								clear_buf();
						}

					}
					
				}
				else
				{
					system("cls");
					system("Color 04");
					cout << "Wrong PIN";
					clear_buf();
					tries--;

					if (tries == 0)
					{
						system("cls");
						cout << "Your card is blocked";
						cards[card][4] = "Blocked";
						clear_buf();
						system("cls");
						system("Color 07");
						cout << "Do you want to play music(y/n)? ";
						cin >> music;

						if (music == 'Y' || music == 'y')
						{
							PlaySound(L"defeat.wav", NULL, SND_ASYNC);
							system("cls");
							system("Color 04");
							cout << "Your card is blocked";
							clear_buf();
							system("cls");
							system("Color 07");
							cout << "Do you want to stop music(y/n)? ";
							cin >> music;

							if (music == 'Y' || music == 'y')
							{
								PlaySound(NULL, 0, 0);
							}
						}

						system("cls");
						system("Color 04");
						cout << "Your card is blocked";
						clear_buf();
					}
				}
			}
		}
		else
		{
			system("cls");
			system("Color 04");
			cout << "Your card is blocked";
			clear_buf();
			system("cls");
			system("Color 07");
			cout << "Do you want to play music(y/n)? ";
			cin >> music;

			if (music == 'Y' || music == 'y')
			{
				PlaySound(L"defeat.wav", NULL, SND_ASYNC);

				system("cls");
				system("Color 04");
				cout << "Your card is blocked";
				clear_buf();
				system("cls");
				system("Color 07");
				cout << "Do you stop music(y/n)? ";
				cin >> music;

				if (music == 'Y' || music == 'y')
				{
					PlaySound(NULL, 0, 0);
				}

			}

			system("cls");
			system("Color 04");
			cout << "Your card is blocked";
			clear_buf();
		
		}
	}

	ofstream file2("cards.txt");

	for (int i = 0,j=0; i < 5; j++)
	{
		if (j == 5)
		{
			i++;
			j = 0;
			file2 << endl;
		}

		file2 << cards[i][j] << " ";

		
	}
}