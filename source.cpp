/*probmatic*/
/*Program: Coffee Menu*/

#include <iomanip> //Library for persision
#include <iostream> //Input & Output
using namespace std;


void menu();
void tCupCount(int s, int m, int l);
void tMoneyMade(double m);
void tCoffeeSold(int c);

//Passing coffee cup sizes and costs through function as a constant
void sellCoffee(int& sCupCount, int &mCupCount, int& lCupCount,
	int&  totalCoffeeSold, double& tMoneyMade, const double SCUPCOST, const double MCUPCOST, const double LCUPCOST,
	const double SCUPSIZE, const double MCUPSIZE, const double LCUPSIZE);

int main()
{
	const double SCUPCOST = 1.75; //Small Cup Cost
	const double MCUPCOST = 1.90; //Medium Cup Cost
	const double LCUPCOST = 2.00; //Large Cup Cost

	const int SCUPSIZE = 9; //Small Size in OZ
	const int MCUPSIZE = 12; //Medium Size in OZ
	const int LCUPSIZE = 15; //Large Size in OZ

	int sCC = 0; //small cup count 
	int mCC = 0; //medium cup count
	int lCC = 0; //large cup count

	int tAmountCoffeeSold = 0; //total amount of coffee sold

	double tAmountMoneyMade = 0.0; //total amount of money made

								   //Directions on how to use this program
	cout << "To use this program, enter a number from the menu." << endl;
	cout << "You will either be taken to a submenu or directly back to this main menu." << endl;
	cout << endl;
	cout << endl;
	cout << endl;


	//Code for Menu GUI
	int choice;
	cout << fixed << showpoint << setprecision(2);
	menu();
	cin >> choice;
	cout << endl;

	while (choice != 0)
	{
		switch (choice)
		{
		case 1:
			cout << endl;
			sellCoffee(sCC, mCC, lCC,
				tAmountCoffeeSold, tAmountMoneyMade, SCUPCOST, MCUPCOST, LCUPCOST,
				SCUPSIZE, MCUPSIZE, LCUPSIZE);
			break;
		case 2:
			cout << endl;
			tMoneyMade(tAmountMoneyMade);
			break;
		case 3:
			cout << endl;
			tCoffeeSold(tAmountCoffeeSold);
			break;
		case 4:
			cout << endl;
			tCupCount(sCC, mCC, lCC);
			break;
		case 5:
			cout << endl;
			tCupCount(sCC, mCC, lCC);
			tCoffeeSold(tAmountCoffeeSold);
			tMoneyMade(tAmountMoneyMade);
			cout << endl;
			break;
		default:
			cout << "Invalid input." << endl;
		}

		menu();
		cin >> choice;
		cout << endl;
	}

	system("pause");
	return 0;
}


//Main Menu GUI
void menu()
{
	cout << "1 to order coffee." << endl;
	cout << "2 to view total money." << endl;
	cout << "3 to view total amount of coffee sold." << endl;
	cout << "4 to view number of cups of coffee of each size sold." << endl;
	cout << "5 to print all the information." << endl;
	cout << "0 to exit." << endl;
}


//Function for Total Cup Count
void tCupCount(int s, int m, int l)
{
	cout << "Small cup count: " << s << endl;
	cout << "Medium cup count: " << m << endl;
	cout << "Large cup count: " << l << endl;
}


//Function for Total Money Made
void tMoneyMade(double m)
{
	cout << "Total money made: $" << m << endl;
}

//Function for Total Coffee Sold
void tCoffeeSold(int c)
{
	cout << "Total amount of coffee sold: " << c << "oz" << endl;
}

//Sell Coffee GUI
void coffeeMenu()
{
	cout << "1 Buy coffee in a small cup size (9 oz)" << endl;
	cout << "2 Buy coffee in a medium cup size (12 oz)" << endl;
	cout << "3 Buy coffee in a large cup size (15 oz)" << endl;
	cout << "9 To pay your bill." << endl;
}


//Sell Coffee Code
void sellCoffee(int& sCupCount, int &mCupCount, int& lCupCount,
	int& tCoffeeSold, double& tMoneyMade, const double SCUPCOST, const double MCUPCOST, const double LCUPCOST,
	const double SCUPSIZE, const double MCUPSIZE, const double LCUPSIZE)
{
	int cupSize;
	int numOfCupsOrdered;
	int selection = 0;

	double bill = 0; //Bill person has to pay at the end
					 //Can make another bill negative if person decides they don't want to pay for drinks

	coffeeMenu();
	cin >> cupSize;
	cout << endl;

	while (cupSize != 9)
	{
		switch (cupSize)
		{
		case 1:
			cout << "Enter the number of cups: ";
			cin >> numOfCupsOrdered;
			cout << endl;

			sCupCount = sCupCount + numOfCupsOrdered;
			bill = bill + numOfCupsOrdered * SCUPCOST;
			tCoffeeSold = tCoffeeSold + numOfCupsOrdered * SCUPSIZE;
			break;
		case 2:
			cout << "Enter the number of cups: ";
			cin >> numOfCupsOrdered;
			cout << endl;

			mCupCount = mCupCount + numOfCupsOrdered;
			bill = bill + numOfCupsOrdered * MCUPCOST;
			tCoffeeSold = tCoffeeSold + numOfCupsOrdered * MCUPSIZE;
			break;
		case 3:
			cout << "Enter the number of cups: ";
			cin >> numOfCupsOrdered;
			cout << endl;

			lCupCount = lCupCount + numOfCupsOrdered;
			bill = bill + numOfCupsOrdered * LCUPCOST;
			tCoffeeSold = tCoffeeSold + numOfCupsOrdered * LCUPSIZE;
			break;
		default:
			cout << "Invalid input." << endl;
		}
		coffeeMenu();
		cin >> cupSize;
		cout << endl;
		cout << "\n Please pay $" << bill << endl;
	}
	//Total Money
	tMoneyMade = tMoneyMade + bill;
}
