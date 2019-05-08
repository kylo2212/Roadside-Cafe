/*Kirstie O'Connell FINAL ROADSIDE CAFE PROJECT 12092017
This program will greet customers to the roadside cafe and find out
when they would like to visit and takes the customer through the diner
menus options, a visit to the jukebox and then to the gift shop
depending on where they want to go on the visit. The outcome will be
a description of services for the diner and shop they purchased and the total.
If visiting the diner there will be a survey and if shopping from the gift shop
an order will also be created to restock items purchased.
Added since the midterm are the candy bins and the structure of the code has changed.*/


#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>


using namespace std;

const float GIFTSHOP_TAX_RATE = .0725; //gift shop tax rate on items purchased	by customer
const float FUEL_SURCHARGE = 50.00; //fuel charge for delivery of merchandise to store
const float DELIVERY_FEE = 100.00; //delivery fee for merchandise to restock store
const float FOOD_TAX_RATE = .04125; //food tax rate on food purchased
const float TIP_10 = .10; //tip percent for highest satisfaction
const float TIP_15 = .15; //tip percent for average satisfaction 
const float TIP_20 = .20; //tip percent for lowest satisfaction

const float OMLETTECOST = 4.50; // cost of omlette 
const float BSANDCOST = 4.50; // cost of breakfast sandwich 
const float PCAKECOST = 4.00; // cost of pancakes
const float BGRAVYCOST = 3.75; // cost of biscuits and gravy 
const float FTOASTCOST = 3.00; // cost of french toast 
const float COFFEECOST = 1.00; // cost of coffee
const float OJUICECOST = 1.00; // cost of orange juice 
const float SODACOST = 1.00; // cost of soda 
const float TEACOST = 1.00; // cost of tea
const float CBURGERCOST = 5.75; // cost of cheeseburger
const float PHILLYCOST = 5.75; // cost of Philly cheesesteak
const float CHILICOST = 4.25; // cost of chili
const float CHEFSALADCOST = 4.50; // cost of chef salad
const float CLUBSALADCOST = 4.75; // cost of club sandwich and salad

const float SHIRTCOST = 20.00;//cost of shirt
const float GLOBECOST = 15.00;//cost of snow globe
const float HATCOST = 10.00; //cost of hat
const float KEYCHAINCOST = 5.00; //cost of keychain
const float POSTCARDCOST = 2.00; //cost of postcard package


void printWelcome();//prototype for function to display welcome banner
void visitInput(int& day, float& time);//function to gather visit input	
char choice(char a);//function to return choice of where to visit	
void displayBkfstMenu();//function to display breakfast menu	
void displayDinnerMenu();//function to display dinner menu
//void dinerVisit();//function for the whole diner option for visit
void dinerOrder();//function to return menu choice
void jukebox();//function to play music
void giftShop();//function for the giftshop
void candy();//funtion for candy

int main()
{
	int visitDay = 1; //corresponding number for day of visit: Mon=1
	float visitTime = 0; //time of day for planned visit using 24 hour clock format
	char visitChoice = ' '; //choice for the diner, jukebox, gift store or candy bins
	bool stillVisiting = true;//boolean for if visiting

	printWelcome();//call to print banner function 
	visitInput(visitDay, visitTime);//call to input of visit information
	visitChoice = (choice(visitChoice));//calls for the choice function for area of diner visitint and puts it in visit choice variable
	do//do..while loop while stillvisiting is true
	{
		switch (visitChoice)//switch statement based on choice of visit area
		{
		case 'D':
		case'd'://the d/D cases select the diner
		{
			if ((visitTime >= 0500) && (visitTime <= 2300)) // start if statement for breakfast menu based on the time and visit day
			{
				displayBkfstMenu();//calls function to show breakfast menu
				if ((visitTime >= 1100) && (visitTime <= 2000)) //nested if for lunch/dinner menu based on time 
				{
					displayDinnerMenu();//calls function to show dinner menu
				}
				dinerOrder();//calls function for menu ordering in diner
			}
			else
				cout << "Closed, please come again when open 7 days - 5am to 11pm" << endl;
			cout << "Check out out new wall of Candy!" << endl;
			candy();
			cout << endl << endl;
			visitChoice = (choice(visitChoice));//calls to choose an area option again by function call 
			break;
		}
		//dinerVisit();//function for the whole diner choice

		case 'J':
		case 'j'://the choices of J/j are for the jukebox
		{
			if ((visitTime >= 0500) && (visitTime <= 2300))//it can only be open if the diner is open
			{
				jukebox();//function call to visit jukebox
			}
			else
				cout << "Closed, please come again when open 7 days - 5am to 11pm" << endl;
			visitChoice = (choice(visitChoice));//calls for funtion to choose area to visit 
			break;
		}
		case 'G':
		case 'g'://the choices for G/g are for the giftshop
		{
			if (((visitDay >= 1) && (visitDay <= 5)) && ((visitTime >= 800) && (visitTime <= 2000)))//this if statement is based on the time and days in the brackets 
			{
				giftShop();//calls function to visit gift shop
			}
			visitChoice = (choice(visitChoice));//calls for function to choose area to visit
			break;
		}
		case 'X':
		case 'x'://the X/x choices are for exiting the diner
		{
			cout << endl;
			cout << "Thank you for visiting! Please come again!" << endl << endl;
			stillVisiting = false;//changes the boolean to false as not visiting
			//break;//If i use this break to try to stop the default from printing then it just loops the above statement endlessly, not sure why it don't work using it 
		}
		default://does the following if something other than the above case choices are entered
		{
			cout << "Please enter D/d, J/j, G/g or X/x: ";
			visitChoice = (choice(visitChoice));
			break;

		}
		}


	} while (stillVisiting = true);//when still visiting turns false the do..while loop is exited

		
	
	system("Pause");
	return 0;
}
//function header and definition to print welcome
void printWelcome()
{
	//the banner to welcome customer
	cout << endl;
	cout << "*************************************************************************" << endl;
	cout << "*                                                                       *" << endl;
	cout << "*                                 Welcome to                            *" << endl;
	cout << "*                           NAMELESS ROADSIDE CAFE!                     *" << endl;
	cout << "*                                                                       *" << endl;
	cout << "*************************************************************************" << endl;
	cout << endl;

}
//function header and definition to gather visit input
void visitInput(int& day, float& time)
{
	day = 1; //corresponding number for day of visit: Mon=1
	time = 0; //time of day for planned visit using 24 hour clock format
		
	//the following section asks customer for information of visit plans and inputs them
	cout << "We are excited to have you for a visit!" << endl;
	cout << "Let us know when you plan to see us on your trip." << endl << endl;
	cout << "Please enter day of your visit using a number 1 - 7 with Monday as day 1: ";
	cin >> day;
	switch (day)//switch statement based on the day chosen 
	{
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		break;
	default://if not day 1-7 then asks for new input
		{
			cout << "Invalid day entry, please select again: ";
			cin >> day;
			break;
		}
	}
	cout << endl;
	cout << "Please enter the time of day you will visit" << endl;
	cout << "using 24 hour time format (military time): ";
	cin >> time;//iputs time in military fashion
	if ((time < 0000) || (time > 2359))//does the following if time entered out of bounds of 24 hours 
	{
		cout << "Invalid time entry, please try again: ";
		cin >> time;
	}
	cout << endl << endl;
}
char choice(char a)
{
	a = ' ';
	cout << "Please choose to visit the diner (D/d), the jukebox for music(J/j)" << endl;
	cout << " or the giftshop (G/g) or enter X/x to exit: ";
	cin >> a; //customer input for where they want to go 
	cout << endl << endl;
	cout << "______________________________________________________________" << endl << endl;
	return a;
}
void displayBkfstMenu()
{

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~BREAKFAST MENU~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;
	cout << "a. Omelette                                                  " << endl;
	cout << "               -ham, mushroom, green pepper, onion and cheese" << endl;
	cout << "                               served with side of hashbrowns" << endl;
	cout << "                                                        $4.50" << endl << endl;
	cout << "b. Breakfast Sandwich                                        " << endl;
	cout << "               -bacon, egg, cheese on toast                  " << endl;
	cout << "                                                        $4.50" << endl << endl;
	cout << "c. Pancakes                                                  " << endl;
	cout << "               -served with side of hashbrowns and bacon     " << endl;
	cout << "                                                        $4.00" << endl << endl;
	cout << "d. Biscuits and Gravy                                        " << endl;
	cout << "               -served with side of hashbrowns               " << endl;
	cout << "                                                        $3.75" << endl << endl;
	cout << "e. French Toast                                              " << endl;
	cout << "               -served with side of hashbrowns and bacon     " << endl;
	cout << "                                                        $4.00" << endl << endl;
	cout << "f. Coffee                                                    " << endl;
	cout << "               -fresh ground and fresh brewed                " << endl;
	cout << "                                                        $1.00" << endl << endl;
	cout << "g. Orange Juice                                              " << endl;
	cout << "               -homemade fresh squeezed                      " << endl;
	cout << "                                                        $1.00" << endl << endl;
	cout << "h. Soda                                                      " << endl;
	cout << "               -Pepsi, Mountain Dew, Sprite or Root Beer     " << endl;
	cout << "                                                        $1.00" << endl << endl;
	cout << "i. Tea                                                       " << endl;
	cout << "               -homebrewed tea                               " << endl;
	cout << "                                                        $1.00" << endl << endl;
}
void displayDinnerMenu()
{

	cout << "~~~~~~~~~~~~~~~~~~~~~~~~LUNCH AND DINNER MENU~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl << endl;
	cout << "j. Cheeseburger                                                     " << endl;
	cout << "           -fresh ground beef patty, cheese, lettuce, tomato,       " << endl;
	cout << "            onion on a bun served with side of french fries         " << endl;
	cout << "                                                             $5.75  " << endl << endl;
	cout << "k. Philly Cheesesteak                                               " << endl;
	cout << "           -fried pork tenderloin, lettuce, tomato on a bun         " << endl;
	cout << "            served with side of french fries                        " << endl;
	cout << "                                                             $5.75  " << endl << endl;
	cout << "l. Chili                                                            " << endl;
	cout << "           -homemade chili served with cheese and crackers          " << endl;
	cout << "                                                             $4.25  " << endl << endl;
	cout << "m. Chef Salad                                                       " << endl;
	cout << "           -iceburg lettuce with tomato, onion, mushrooms,          " << endl;
	cout << "            cheese and croutons with ranch dressing                 " << endl;
	cout << "                                                             $4.50  " << endl << endl;
	cout << "n. Club Sandwich and Salad                                          " << endl;
	cout << "           -triple layer sandwich with ham, turkey, salami          " << endl;
	cout << "            bacon, cheese, lettuce, and tomato with side salad      " << endl;
	cout << "                                                             $4.50  " << endl << endl;
	cout << "h. Soda                                                             " << endl;
	cout << "           -Pepsi, Mountain Dew, Sprite or Root Beer                " << endl;
	cout << "                                                             $1.00  " << endl << endl;
	cout << "i. Tea                                                              " << endl;
	cout << "           -homebrewed tea                                          " << endl;
	cout << "                                                             $1.00  " << endl << endl;
}
/*void dinerVisit()
{
	
}*/
void dinerOrder()
{
	bool keepOrdering = true; //logical expression for ordering food
	char menuItem; //choice of menu to purchase from menu
	float totalFood = 0; //total cost of food ordered before taxes
	float totalFoodBill = 0; //total of food order with taxes before the tip
	float totalFoodTax = 0; //total of tax on food order

	int surveyLevel = 0; //for selection of satisfaction in survey
	float billTip = 0;//amount of tip for food order after tax
	float finalBill = 0; //the final amount to be paid for food order

	//float totalFood = 0;
	//bool keepOrdering = true; //boolean for still ordering food
	//char a1 = ' '; //menu choice
	int nbrOmsOrd = 0; //number of omlettes ordered
	float omCost = 0; //cost of omlette order
	int	nbrBSandsOrd = 0;//number of breakfast sandwiches ordered
	float bSandsCost = 0; //cost of breakfast sandwich order
	int	nbrPCakesOrd = 0;//number of pancakes ordered
	float pCakeCost = 0; //cost of pancake order
	int	nbrBGravyOrd = 0;//number of biscuits and gravy ordered
	float bGravyCost = 0; //cost of biscuits and gravy order
	int	nbrFToastOrd = 0;//number of french toast ordered
	float fToastCost = 0; //cost of french toast order
	int nbrCoffeeOrd = 0;//number of coffee ordered
	float coffeeCost = 0; //cost of coffee order
	int	nbrOJuiceOrd = 0;//number of orange juice ordered
	float oJuiceCost = 0; //cost of orange juice order
	int	nbrSodaOrd = 0;//number of soda ordered
	float sodaCost = 0; //cost of soda order
	int nbrTeaOrd = 0;//number of tea ordered
	float teaCost = 0; //cost of tea order

	int nbrCBurgerOrd = 0;//number of cheeseburgers ordered
	float cBurgerCost = 0; //cost of cheeseburgers order
	int nbrCBurger = 5; //nbr cheeseburgers on hand
	int nbrPhillyOrd = 0;//number of philly cheesesteak ordered
	float phillyCost = 0; //cost of philly cheesesteak order
	int nbrPhilly = 5;//nbr of Philly on hand
	int nbrChiliOrd = 0;//number of chili ordered
	float chiliCost = 0; //cost of chili order
	int nbrChili = 5; //number of chili on hand
	int nbrChefSaladOrd = 0;//number of chef salad ordered
	float chefSaladCost = 0; //cost of chef salad order
	int nbrSalad = 5;//number of salad on hand
	int nbrClubSaladOrd = 0;//number of club and salad ordered
	float ClubSaladCost = 0; //cost of club and salad order
	int nbrClub = 5; //number of club and salad on hand
	
	while (keepOrdering) //while loop order as long as this value is true
	{
		cout << "Please enter the letter to the menu item you would like to enjoy." << endl;
		cout << "If you are done ordering enter X/x to exit ordering:  ";
		cin >> menuItem;
		cout << endl << endl;
		//start of switch statement based on menu items orderd and then takes a count 
		switch (menuItem)
		{
		case 'A':                              //each of these blocks of cases takes the order by selection and the number of orders by input of number
		case 'a':
			cout << "How many omlettes would you like? ";
			cin >> nbrOmsOrd;
			cout << endl;
			break;
		case 'B':
		case 'b':
			cout << "How many breakfast sandwiches would you like? ";
			cin >> nbrBSandsOrd;
			cout << endl;
			break;
		case 'C':
		case 'c':
			cout << "How many orders of pancakes would you like? ";
			cin >> nbrPCakesOrd;
			cout << endl;
			break;
		case 'D':
		case 'd':
			cout << "How many biscuits and gravy would you like? ";
			cin >> nbrBGravyOrd;
			cout << endl;
			break;
		case 'E':
		case 'e':
			cout << "How many French Toast would you like? ";
			cin >> nbrFToastOrd;
			cout << endl;
			break;
		case 'F':
		case 'f':
			cout << "How many orders of coffee would you like? ";
			cin >> nbrCoffeeOrd;
			cout << endl;
			break;
		case 'G':
		case 'g':
			cout << "How many orders of orange juice would you like? ";
			cin >> nbrOJuiceOrd;
			cout << endl;
			break;
		case 'H':
		case 'h':
			cout << "How many orders of soda would you like? ";
			cin >> nbrSodaOrd;
			cout << endl;
			break;
		case 'I':
		case 'i':
			cout << "How many orders of tea would you like? ";
			cin >> nbrTeaOrd;
			cout << endl;
			break;
		case 'J':
		case 'j':
		{
			cout << "How many orders of Cheeseburger would you like? ";
			cin >> nbrCBurgerOrd;

			/*nbrCBurger -= (nbrCBurger - nbrCBurgerOrd);//this was a beginning attempt to try out the keeping track of lunch orders 
			if (nbrCBurger > 0)//went to an if statement to decrement number of cheeseburgers from what was available.
			{
				nbrCBurger--;
			}
			if (nbrCBurger < 0)//if out of food item was suppose to print this
			{
				cout << "Not enough for this meal please select less: " << endl;
				cin >> nbrCBurgerOrd;
			}*/
			cout << endl;
			break;
		}
		case 'K':
		case 'k':
			cout << "How many orders of philly cheesesteak would you like? ";
			cin >> nbrPhillyOrd;
			cout << endl;
			break;
		case 'L':
		case 'l':
			cout << "How many orders of chili would you like? ";
			cin >> nbrChiliOrd;
			cout << endl;
			break;
		case 'M':
		case 'm':
			cout << "How many orders of chef salad would you like? ";
			cin >> nbrChefSaladOrd;
			cout << endl;
			break;
		case 'N':
		case 'n':
			cout << "How many orders of club sandwich and salad would you like? ";
			cin >> nbrClubSaladOrd;
			cout << endl;
			break;
		case 'X':
		case 'x':
			keepOrdering = false;//breaks the switch statement
		}
	}
	//the following gathers information for the bill based on what was ordered and prints out the bill 
	if (nbrOmsOrd > 0)//each of the several similar following if statements compares amount of item ordered if it will execute
	{
		omCost = nbrOmsOrd * OMLETTECOST;//each block contains a calculation for the cost of the order based on the price constant of the item and the number of orders
		cout << "You ordered " << nbrOmsOrd << " omlette(s) costing $" << omCost << endl;//this part is suppose to print out to the receipt or bill for each item
		totalFood += (totalFood + omCost);//this is suppose to add the cost of the order to the grand total of food cost for the bill and add multiple menu items 
	}
	if (nbrBSandsOrd > 0)
	{
		bSandsCost = nbrBSandsOrd * BSANDCOST;
		cout << "You ordered " << nbrBSandsOrd << " breakfast sandwich(es) costing $" << bSandsCost << endl;
		totalFood += (totalFood + bSandsCost);
	}
	if (nbrPCakesOrd > 0)
	{
		pCakeCost = nbrPCakesOrd * PCAKECOST;
		cout << "You ordered " << nbrPCakesOrd << " pancakes costing $" << pCakeCost << endl;
		totalFood += (totalFood + pCakeCost);
	}
	if (nbrBGravyOrd > 0)
	{
		bGravyCost = nbrBGravyOrd * BGRAVYCOST;
		cout << "You ordered " << nbrBGravyOrd << " biscuits and gravy costing $" << bGravyCost << endl;
		totalFood += (totalFood + bGravyCost);
	}
	if (nbrFToastOrd > 0)
	{
		fToastCost = nbrFToastOrd * FTOASTCOST;
		cout << "You ordered " << nbrFToastOrd << " French toast(s) costing $" << fToastCost << endl;
		totalFood += (totalFood + fToastCost);
	}
	if (nbrCoffeeOrd > 0)
	{
		coffeeCost = nbrCoffeeOrd * COFFEECOST;
		cout << "You ordered " << nbrCoffeeOrd << " coffee(s) costing $" << coffeeCost << endl;
		totalFood += (totalFood + coffeeCost);
	}
	if (nbrOJuiceOrd > 0)
	{
		oJuiceCost = nbrOJuiceOrd * OJUICECOST;
		cout << "You ordered " << nbrOJuiceOrd << " orange juice(s) costing $" << oJuiceCost << endl;
		totalFood += (totalFood + oJuiceCost);
	}
	if (nbrSodaOrd > 0)
	{
		sodaCost = nbrSodaOrd * SODACOST;
		cout << "You ordered " << nbrSodaOrd << " soda(s) costing $" << sodaCost << endl;
		totalFood += (totalFood + sodaCost);
	}
	if (nbrTeaOrd > 0)
	{
		cout << showpoint << fixed << setprecision(2);//was using this one in playing with and trying to get the numeric information to print out right before changing all these like this 
		teaCost = nbrTeaOrd * TEACOST;
		cout << "You ordered " << nbrTeaOrd << " tea(s) costing $" << teaCost << endl;
		totalFood += (totalFood + teaCost);
		
	}
	//somewhere in here put some kind of counter for items 
	//it is not calculating things right. may take out drinks
	if ((nbrCBurgerOrd > 0) && (nbrCBurgerOrd <= nbrCBurger))
	{
		//cout << showpoint << fixed << setprecision(2);
		cBurgerCost = nbrCBurgerOrd * CBURGERCOST;
		cout << "You ordered " << nbrCBurgerOrd << "cheeseburger(s) costing $" << cBurgerCost << endl;
		totalFood += (totalFood + cBurgerCost);//I keep trying to figure out whether to use += or just the longer way to get the totals to add together for the whole order
		
	}
	if (nbrPhillyOrd > 0)
	{
		phillyCost = nbrPhillyOrd * PHILLYCOST;
		cout << "You ordered " << nbrPhillyOrd << " Philly Cheesesteak(s)costing $" << phillyCost << endl;
		totalFood += (totalFood + phillyCost);
	}
	if (nbrChiliOrd > 0)
	{
		chiliCost = nbrChiliOrd * CHILICOST;
		cout << "You ordered " << nbrChiliOrd << " chili(s) costing $" << chiliCost << endl;
		totalFood += (totalFood + chiliCost);
	}
	if (nbrChefSaladOrd > 0)
	{
		chefSaladCost = nbrChefSaladOrd * CHEFSALADCOST;
		cout << "You ordered " << nbrChefSaladOrd << " chef salad(s) costing $" << chefSaladCost << endl;
		totalFood += (totalFood + chefSaladCost);
	}
	if (nbrClubSaladOrd > 0)
	{

		ClubSaladCost = nbrClubSaladOrd * CLUBSALADCOST;
		cout << "You ordered " << nbrClubSaladOrd << " club sandwich and salad(s) costing $" << ClubSaladCost << endl;
		totalFood += (totalFood + ClubSaladCost);
	}
	//the beginning of the bill 
	cout << "++++++++++++++++++++++++++YOUR BILL+++++++++++++++++++++++" << endl << endl;
	cout << showpoint << fixed << setprecision(2);//to try and output the numeric parts to come out as two decimal places each time
	cout << setw(30) << left << setfill('.') << "The total cost of food " << setw(7) << right << setfill('.') << "$" << totalFood << endl;//shows cost of food 
	cout << setw(30) << left << setfill('.') << "The tax rate for food " << setw(7) << right << setfill('.') << "%" << (FOOD_TAX_RATE * 100) << endl;//shows tax rate
	totalFoodTax = (totalFood * FOOD_TAX_RATE);//calculates the food tax amount
	cout << setw(30) << left << "The total tax " << setw(7) << right << setfill('.') << "$" << totalFoodTax << endl;//shows the tax amount
	totalFoodBill = totalFoodTax + totalFood;//calculates the total bill of food cost and tax amount added
	cout << setw(30) << right << "TOTAL FOOD AND TAX " << setw(7) << "$" << totalFoodBill << endl << endl;
	//starts the survey
	cout << "Please take a little survey to calculate suggested tip on this bill." << endl;
	cout << "Select 1 for best, 2 for average or 3 for worst.  ";
	cin >> surveyLevel;//inputs the survey level
	cout << endl;
	//starts the switch based on the survey level input
	switch (surveyLevel)
	{
	case 1:								//each of the cases has the following similar statements
		billTip = (totalFoodBill * TIP_10);//calculation for amount of tip based on the 10 percent rate
		finalBill = billTip + totalFoodBill;//calculates the final bill plus the tip amount
		cout << right << "FINAL BILL WITH $" << billTip << " TIP AMOUNT ADDED FOR LEVEL 1" << setw(7) << "$" << finalBill << endl << endl;
		break;
	case 2:

		billTip = (totalFoodBill * TIP_15);
		finalBill = billTip + totalFoodBill;//calculation based on the 15% tip rate
		cout << right << "FINAL BILL WITH $" << billTip << " TIP AMOUNT ADDED FOR LEVEL 2" << setw(7) << "$" << finalBill << endl << endl;
		break;
	case 3:

		billTip = (totalFoodBill * TIP_20);
		finalBill = billTip + totalFoodBill;//calculation based on the 20% tip rate
		cout << right << "FINAL BILL WITH $" << billTip << " TIP AMOUNT ADDED FOR LEVEL 3" << setw(7) << "$" << finalBill << endl << endl;
		break;
	}

	cout << "-------THANK YOU FOR DINING WITH US!-------" << endl << endl;//departure message 
}

void jukebox()
{
	int quarters = 0; //number of quarters for play of music
	float musicTime = 0; //time bought to play music
	string songName; //song name 
	float songTime = 0; //time song plays

	
		cout << "Welcome to the Jukebox! Three minutes of music costs one quarter." << endl;
		cout << "How many quarters would you like to play? An entry of 0 will exit the Jukebox: ";
		cin >> quarters;//inputs how many quarters they want to play
		cout << endl << endl;
		musicTime = quarters * 3.00;//calculates the amount of time purchased

		ifstream inFileJuke;//in file identifier for the song list
		ofstream outFileJuke;//out file identifier for the song played list

		inFileJuke.open("SongList.txt");//opens the in file 
		outFileJuke.open("SongsPlayed.txt");//opens the outfile
		do
		{
			do 
			{
				do 
				{
					inFileJuke >> songName >> songTime;//reads the in file again for next song if more time left
					outFileJuke << left << setw(15) << songName << right << setw(5) << songTime << endl;
					cout << left << setw(30) << songName << right << setw(5) << songTime << endl;
					musicTime -= songTime;//calculates the purchased music time left
					cout << endl;//asks if want to purchase more time and takes input 
				} while ((musicTime > songTime) && (inFileJuke));
				cout << "For more time please enter number of quarters: ";
				cin >> quarters;
				musicTime = quarters * 3.00;//calculates time purchased based on quarters played
				cout << endl;
			} while (songTime <= musicTime);//if statement to play music as long as there is time purchased left 
		} while (quarters != 0);//(inFileJuke);//starts while loop based on end of file			
		
	inFileJuke.close();//closes the infile
	outFileJuke.close();//closes the out file

}

void giftShop()
{
	bool giftOrdering = true; //logical expression for gift ordering
	float totalGifts = 0; //total cost of gift store purchase
	char giftItem; //selection for item in gift store
	float totalGiftTax = 0; //total tax on merchandise
	float totalGiftBill = 0; //total of merchandise with tax included

	int nbrShirtOrd = 0; //number of shirts selected
	float shirtCost = 0; //cost of shirts ordered
	int nbrGlobeOrd = 0; //number of snow globes selected
	float globeCost = 0; //cost of snow globes ordered
	int nbrHatOrd = 0;	//number of hats selected
	float hatCost = 0;//cost of hats ordered
	int nbrKeychainsOrd = 0; //number of keychains selected
	float keychainCost = 0; //cost of keychains ordered
	int nbrPostcardsOrd = 0; //number of postcards selected
	float postcardCost = 0; //cost of postcards ordered

	int shirt = 0; //number of shirts needed to restock
	int globe = 0; //number of snow globes needed to restock
	int hat = 0; //number of hats needed to restock
	int keychain = 0; //number of keychains to restock
	int postcards = 0; //number of postcards to restock

	float giftRestockCost = 0; //total restock cost of gift shop items for reordering
	float totalReorder = 0;//total reorder plus fees and fuel 

	cout << endl;//banner for the gift shop 
	cout << "*************************************************************************" << endl;
	cout << "*                                 Welcome to                            *" << endl;
	cout << "*                             NAMELESS ROADSIDE                         *" << endl;
	cout << "*                                 Gift Shop!                            *" << endl;
	cout << "*************************************************************************" << endl;
	cout << endl;//the items for sale 
	cout << "~~~~~~~~~~~~We have the following items for sale!~~~~~~~~~~~~" << endl << endl;
	cout << "a. T-Shirt                                            $20.00 " << endl;
	cout << "            -with Nameless Roadside Cafe logo                " << endl;
	cout << "b. Snow Globe                                         $15.00 " << endl;
	cout << "            -colectable snow globe with our store inside!    " << endl;
	cout << "c. Hat                                                $10.00 " << endl;
	cout << "            -with the Nameless Roadside cafe logo!           " << endl;
	cout << "d. Keychain                                            $5.00 " << endl;
	cout << "            -a minature Nameless Roadside Cafe               " << endl;
	cout << "e. Postcards                                           $2.00 " << endl;
	cout << "            -package of 4 postcards with different           " << endl;
	cout << "             roadside cafe designs to collect                " << endl;
	cout << endl << endl;

	while (giftOrdering) //while loop for ordering as long as this value is true
	{
		cout << "Please enter the letter to the gift item you would like to purchase." << endl;
		cout << "If you are done ordering enter X/x to exit ordering:  ";
		cin >> giftItem;//input of the items to purchase 
		cout << endl << endl;
		switch (giftItem)//switch statements to choose what to purchase and how many of each 
		{
		case 'A':						//each of the following similar cases each gather information for purchases 
		case 'a':
			cout << "How many T-Shirts would you like? ";
			cin >> nbrShirtOrd;
			cout << endl;
			break;
		case 'B':
		case 'b':
			cout << "How many snowglobes would you like? ";
			cin >> nbrGlobeOrd;
			cout << endl;
			break;
		case 'C':
		case 'c':
			cout << "How many hats would you like? ";
			cin >> nbrHatOrd;
			cout << endl;
			break;
		case 'D':
		case 'd':
			cout << "How many keychains would you like? ";
			cin >> nbrKeychainsOrd;
			cout << endl;
			break;
		case 'E':
		case 'e':
			cout << "How many postcards would you like? ";
			cin >> nbrPostcardsOrd;
			cout << endl;
			break;
		case 'X':
		case 'x':
			giftOrdering = false;//this statement exits the loop
		}
	}
	if (nbrShirtOrd > 0)//these silimar if statements execute when the respective item is purchased
	{
		shirtCost = nbrShirtOrd * SHIRTCOST;//calculates cost of items based on quantity and the constant of the item price
		cout << "You ordered " << nbrShirtOrd << " shirt(s) costing $" << shirtCost << endl;
		totalGifts += ((totalGifts) + shirtCost);//adds a total to the running item total to figure bill at the end
		shirt++;//adds number of items sold to counter to make a reorder after items are purchased by customer
	}
	if (nbrGlobeOrd > 0)
	{
		globeCost = nbrGlobeOrd * GLOBECOST;
		cout << "You ordered " << nbrGlobeOrd << " snow globes(s) costing $" << globeCost << endl;
		totalGifts += ((totalGifts) + globeCost);
		globe++;
	}
	if (nbrHatOrd > 0)
	{
		hatCost = nbrHatOrd * HATCOST;
		cout << "You ordered " << nbrHatOrd << " hat(s) costing $" << hatCost << endl;
		totalGifts += ((totalGifts) + hatCost);
		hat++;
	}
	if (nbrKeychainsOrd > 0)
	{
		keychainCost = nbrKeychainsOrd * KEYCHAINCOST;
		cout << "You ordered " << nbrKeychainsOrd << " keychain(s) costing $" << keychainCost << endl;
		totalGifts += ((totalGifts) + keychainCost);
		keychain++;
	}
	if (nbrPostcardsOrd > 0)
	{
		postcardCost = nbrPostcardsOrd * POSTCARDCOST;
		cout << "You ordered " << nbrPostcardsOrd << " postcards costing $" << postcardCost << endl;
		totalGifts += ((totalGifts) + postcardCost);
		postcards++;
	}
	//trying to manipulate the output to look like monetary values 
	cout << endl;
	cout << showpoint << fixed << setprecision(2);
	cout << setw(30) << left << setfill('.') << "The total cost of merchandise " << setw(7) << right << setfill('.') << "$" << totalGifts << endl; //shows total cost of items bought 
	cout << setw(30) << left << setfill('.') << "The tax rate for merchandise " << setw(7) << right << setfill('.') << "%" << (GIFTSHOP_TAX_RATE * 100) << endl;//shows the tax rate for merchandise 
	totalGiftTax = (totalGifts * GIFTSHOP_TAX_RATE);//calculates tax amount for merchandise
	cout << setw(30) << left << "The total tax " << setw(7) << right << setfill('.') << "$" << totalGiftTax << endl;//shows the total tax
	totalGiftBill = totalGiftTax + totalGifts;//calculates the total cost of items sold plus the tax
	cout << setw(30) << right << "TOTAL MERCHANDISE AND TAX " << setw(7) << "$" << totalGiftBill << endl << endl;
	cout << "*****************RESTOCKING REPORT****************" << endl;
	if (shirt > 0)//these following if statements execute when there are purchases made 
	{
		cout << "Shirts needed: " << nbrShirtOrd << " for $" << (SHIRTCOST / 2) << " totals $" << ((SHIRTCOST / 2)*nbrShirtOrd) << endl;//shows the output of the items needed and cost of item 
		giftRestockCost += ((SHIRTCOST / 2)*nbrShirtOrd);//calculates the restock cost amount total of items 
	}
	if (globe > 0)
	{
		cout << "Globes needed: " << nbrGlobeOrd << " for $" << (GLOBECOST / 2) << " totals $" << ((GLOBECOST / 2)*nbrGlobeOrd) << endl;
		giftRestockCost += ((GLOBECOST / 2)*nbrGlobeOrd);
	}
	if (hat > 0)
	{
		cout << "Hats needed: " << nbrHatOrd << " for $" << (HATCOST / 2) << " totals $" << ((HATCOST / 2)*nbrHatOrd) << endl;
		giftRestockCost += ((HATCOST / 2)*nbrHatOrd);
	}
	if (keychain > 0)
	{
		cout << "Keychains needed: " << nbrKeychainsOrd << " for $" << (KEYCHAINCOST / 2) << " totals $" << ((KEYCHAINCOST / 2)*nbrKeychainsOrd) << endl;
		giftRestockCost += ((KEYCHAINCOST / 2)*nbrKeychainsOrd);
	}
	if (postcards > 0)
	{
		cout << "Postcards needed: " << nbrPostcardsOrd << " for $" << (POSTCARDCOST / 2) << " totals $" << ((POSTCARDCOST / 2)*nbrPostcardsOrd) << endl;
		giftRestockCost += ((POSTCARDCOST / 2)*nbrPostcardsOrd);
	}
	
	totalReorder = (giftRestockCost + FUEL_SURCHARGE + DELIVERY_FEE);
	cout << endl;
	cout << "Final cost of reordering items for restocking: $" << totalReorder << endl;
	cout << "  This includes $100 delivery fee and $50 fuel charge." << endl << endl << endl;
	
}
void candy() //candy bin function header and definition 
{
		string candyName = " ";//gets candy name
		string candy[20];//candy string 

						 //initialize the array for candy
		for (int i = 0; i < 20; i++)
			candy[i] = " ";

		//input and output files declared
		ifstream input;
		ofstream output;

		//open input file and output file 
		input.open("CandyBins.txt");
		output.open("CandySorted.txt");


		//inputs the candy into the array	
		for (int i = 0; i < 20; i++)
		{
			input >> candy[i];
		}

		cout << "un-sorted" << endl;
		for (int i = 0; i < 20; i++)
			cout << candy[i] << " ";

		//starts the sorting into abc order
		//string smallest = " ";//holding the string for the location of the smallest string 
		//void sort(string arr[20])
	/*	{
			int i = 0; //for the counting or location in the array
			string temp = " "; //temporary holding for location of string for the swapping
			string str1 = " "; //holding for the first string to compare to the next str
			string str2 = " "; // holding for the second string to compare to the first str

			for (i = 0; i < 20 - 1; i++)
			{
				int index = 0;
				string::size_type smallestStr = 0;
				int location = 0;
				int tempLoc = 0;
				string::size_type tempStr = 0;

				for (index = 0; index < 20 - 1; index++)
				{
					smallestStr = candy[index];
					for (location = index + 1; location < 20; location++)
					{
						candy[location] = tempStr;
						if (smallestStr.compare(tempStr) < 0)
							index = location;
						tempStr = candy[location];
						candy[location] = candy[index];
						candy[index] = tempStr;
					}
				}
			}
		}
		cout << "sorted" << endl;
		for (int i = 0; i < 20; i++)
			cout << candy[i] << " ";
		input.close();
		output.close();
	}
	*/
	}