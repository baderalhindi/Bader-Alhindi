
#include <iostream>
using namespace std;

template <class T1, class T2>

T1 sum(T1 pr, T2 num)
{

	T1 sum = 0.0;
	for (int i = 1; i <= num; i++)
	{
		sum += pr;
	}
	return sum;

}

struct cast
{

	string name1;
	string name2;
	string name3;

};

struct movie
{
	//info
	string name;
	int age;
	string director;
	string genere;
	cast cc;

};

struct date1
{
	int year;
	int month;
	int day;
};

//viewing times
struct viewingtime
{

	int hour;
	int min;

};

//choosing time
struct time1
{

	int hour1;
	int min1;

};



class info
{

public:
	movie r;
	date1 d;
	viewingtime t[4];
	time1 to;


	
	void print()
	{

		cout << "- " << r.cc.name1 << endl;
		cout << "- " << r.cc.name2 << endl;
		cout << "- " << r.cc.name3 << endl;

	}


};


class movietime :public info
{
private:
	int min1;
public:

	void printtime()
	{
		cout << "VIEWING TIMES " << endl;
		for (int i = 0; i <= 3; i++)
		{
			cout << t[i].hour << " : " << t[i].min << endl;
		}
	}
	void  setrt(int minute)
	{
		min1 = minute;
	}
	friend void printrt(movietime x);

};
void printrt(movietime x)
{
	cout << "RUNNING TIME " << x.min1 << " Minutes " << endl;
}


class moviedate :public info
{
public:

	void printdate()
	{
		cout << "RELEASE DATE " << d.year << " - " << d.month << " - " << d.day << endl;
	}

};


class movieinfo :public info
{
private:
	static int ticket;
public:



	movieinfo(movie m)
	{
		r = m;
	}

	//compostion
	movietime u;
	void settime(viewingtime t[])
	{

		for (int i = 0; i <= 3; i++)
		{
			this->u.t[i] = t[i];

		}

	}


	void choosetime(time1 oo)
	{
		to = oo;
	}

	//compostion
	moviedate z;
	void setdate(date1 nn)
	{
		z.d = nn;
	}



	friend ostream& operator<<(ostream& output, movieinfo& D)
	{
		output << "\n\n---------------------------------------" << endl;
		output << "- " << D.r.name << " -" << endl;
		output << "---------------------------------------" << endl << endl;
		output << "AGE RATING " << D.r.age << "+" << endl;
		output << "DIRECTOR " << D.r.director << endl;
		output << "GENERE " << D.r.genere << endl;

		return output;
	}

	//overriding
	void print()
	{

		cout << "CAST " << endl;

		cout << "- " << r.cc.name1 << endl;
		cout << "- " << r.cc.name2 << endl;
		cout << "- " << r.cc.name3 << endl;

		z.printdate();
		u.printtime();
		cout << endl;
	}


	void choosetime(viewingtime t[])
	{

		do
		{
			//customer
			cout << "Enter The Time You Want To Watch The Movie, \nProvided That The Time Is Among The Available Times: ";
			cin >> to.hour1 >> to.min1;

			if ((to.hour1 == t[0].hour && to.min1 == t[0].min) || (to.hour1 == t[1].hour && to.min1 == t[1].min) || (to.hour1 == t[2].hour && to.min1 == t[2].min) || (to.hour1 == t[3].hour && to.min1 == t[3].min))
			{
				if (to.hour1 >= 12 && to.hour1 <= 23)
				{
					cout << "\nShow Time -> " << to.hour1 << " : " << to.min1 << " PM" << endl << endl;
					break;
				}
				else if (to.hour1 == 24)
				{
					cout << "\nShow Time -> " << to.hour1 << " : " << to.min1 << " AM" << endl << endl;
					break;

				}

				else if (to.hour1 >= 1 && to.hour1 <= 11)
				{
					cout << "\nShow Time -> " << to.hour1 << " : " << to.min1 << " AM" << endl << endl;
					break;

				}

			}
			else
			{
				cout << "\n-This Time Is Not Available " << endl;
				cout << "Please Choose One Of The Available Times- " << endl << endl;
			}

		} while ((to.hour1 != t[0].hour && to.min1 != t[0].min) || (to.hour1 != t[1].hour && to.min1 != t[1].min) || (to.hour1 != t[2].hour && to.min1 != t[2].min) || (to.hour1 != t[3].hour && to.min1 != t[3].min));


	}

	//ticket M
	void buyt()
	{
		//no. tickets
		int f = 0;
		int c = 0;
		//$$
		float b = 0.0;
		float t = 0.0;
		int u;
		int* p;
		p = &u;

		do
		{

			cout << "---- Ticket's Menu ---- \n";
			cout << "1- Normal Tickets\n";
			cout << "2- VIP Tickets\n";
			cout << "3- Details\n";
			cout << "4- Exit\n";
			cout << "\nEnter your choice: ";
			cin >> *p;
			cout << endl;

			switch (*p)
			{
			case 1:
				do
				{

					cout << "How Many Tickets Do You Want For The Movie:" << endl;
					cout << "\n------------------\n";
					cin >> f;
					cout << "------------------\n";

					if (f <= 30)
					{
						//without Offer
						if (f < 5)
						{
							//float
							b = sum(9.55, f);

						}
						//With Offer
						else
						{
							//int
							b = sum(8, f);

						}

						cout << endl;

					}
					else
					{
						cout << "\nThe Maximum Number Of The Tickets is 30! \n";
						cout << "Enter a valid number of tickets!\n";
					}
					cout << endl;

				} while (f > 30);
				break;

			case 2:

				do
				{

					cout << "How Many Tickets Do You Want For The Movie: " << endl;
					cout << "\n------------------\n";
					cin >> c;
					cout << "------------------\n";

					if (c <= 10)
					{

						t = sum(14.55, c);

					}
					else
					{
						cout << "\nThe Maximum Number Of The Tickets is 10! \n";
						cout << "Enter a valid number of tickets!\n";
					}
					cout << endl;


				} while (c > 10);
				break;

			case 3:

				cout << "Normal Ticket.\n-----------------\n\n";
				cout << "* Total Price For Single Ticket 9.55 $\n";
				cout << "* There's An Offer, Such As More Than Or Equal 5 Tickets The Total Price Will Be On Single Ticket 8 $\n";
				cout << "* There Is No Features For Normal Tickets.\n\n";

				cout << "VIP Ticket.\n-----------------\n\n";
				cout << "* Total Price For Single Ticket 14.55 $\n";
				cout << "* There Is No Offer For VIP Tickets.\n";
				cout << "* VIP seats feature larger, more comfortable seats with extra legroom and plush cushioning and even personal tables\n";
				cout << "for your convenience. They are designed to provide a luxurious seating experience.\n\n\n";
				break;

			case 4:

				cout << "\n---------------------------------------\n";
				cout << "Your Total Price = " << b + t << "$";
				cout << "\n---------------------------------------\n";
				cout << endl;

				if (f == 0 && c == 0)
				{
					cout << "Tickets Are Left: " << ticket << endl;
				}
				else
				{
					cout << "Tickets Are Left: " << (ticket - (f + c)) << endl;
				}
				break;
			default:
				cout << "Invalid choice. Please try again." << endl << endl;
				break;

			}


		} while (u != 4);



	}

	~movieinfo()
	{

		cout << "\nThank You For Choosing Us !\n";

	}



};
int movieinfo::ticket = 40;


//seats
class Seat
{
private:
	bool isAvailable;
public:

	Seat()
	{
		isAvailable = false;
	}

	Seat(bool available)
	{
		isAvailable = available;
	}

	//get function
	bool isSeatAvailable()
	{
		return isAvailable;
	}
};

class Theater
{
private:
	int numRows;
	int numSeatsPerRow;
	Seat seats[5][10];
public:

	//set
	Theater(int numR, int numSeat)
	{
		numRows = numR;
		numSeatsPerRow = numSeat;


		for (int i = 0; i < numRows; ++i)
		{

			for (int j = 0; j < numSeatsPerRow; ++j)
			{
				seats[i][j] = Seat(true);
			}

		}

	}

	bool isSeatAvailable1(int row, int seat)
	{
		//erroring handling
		try
		{

			if (row <= 5 && seat <= 10)
			{
				return seats[row - 1][seat - 1].isSeatAvailable();
			}
			else
			{
				throw false;
			}

		}

		catch (bool a)
		{
			cout << "\nThe Seats Are Limited To 50! " << endl;
		}

	}

	bool reserveSeat(int row, int seat)
	{

		if (isSeatAvailable1(row, seat))
		{
			seats[row - 1][seat - 1] = Seat(false);
			return true;
		}
		return false;

	}

	//Showing Seats 
	void displaySeats()
	{
		for (int i = 0; i < numRows; ++i)
		{
			for (int j = 0; j < numSeatsPerRow; ++j)
			{
				if (seats[i][j].isSeatAvailable())
				{
					if (i == 0)
						cout << "# ";
					else
						cout << "O ";
				}
				else
					cout << "X ";
			}
			cout << endl;
		}
	}


};


int main()
{

	movie n;
	viewingtime tt[4];
	date1 dd;
	//running time
	int minute;

	cout << "------- Welcome To OU Cinemas -------" << endl << endl;

	cout << "Enter Movie's Name: ";
	cin >> n.name;

	cout << "Enter The Age Ratting: ";
	cin >> n.age;

	cout << "Enter The Director's Name: ";
	cin >> n.director;

	cout << "Enter The Genere: ";
	cin >> n.genere;

	cout << "Enter Movie's Cast : " << endl;
	cin >> n.cc.name1 >> n.cc.name2 >> n.cc.name3;

	cout << "Enter Movie's Release Date: ";
	cin >> dd.year >> dd.month >> dd.day;

	cout << "Enter Movie's Run Time: ";
	cin >> minute;

	cout << "Enter Viewing Times: ";
	for (int i = 0; i <= 3; i++)
	{
		cin >> tt[i].hour >> tt[i].min;
	}

	//n is everything in struct movie
	movieinfo m1(n);
	m1.settime(tt);
	m1.setdate(dd);

	movietime mt;
	mt.setrt(minute);

	//print
	cout << m1;
	printrt(mt);
	//overriding
	m1.print();

	//Customer 
	cout << "\n**********************************************************************************************************" << endl << endl;
	m1.choosetime(tt);
	m1.buyt();


	int numR = 5;
	int numSeat = 10;
	int row, seat;

	Theater th1(numR, numSeat);

	while (true)
	{

		cout << "\n========================" << endl;
		cout << "1. Check seat availability" << endl;
		cout << "2. Reserve a seat" << endl;
		cout << "3. Display available seats" << endl;
		cout << "4. Exit" << endl;

		int choice;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice)
		{

		case 1:
		{

			cout << "Enter row number: ";
			cin >> row;
			cout << "Enter seat number: ";
			cin >> seat;
			if (th1.isSeatAvailable1(row, seat))
				cout << "Seat is available." << endl;
			else
				cout << "Seat is not available." << endl;
			break;

		}

		case 2:
		{

			cout << "Enter row number: ";
			cin >> row;
			cout << "Enter seat number: ";
			cin >> seat;
			if (th1.reserveSeat(row, seat))
				cout << "Seat reserved successfully." << endl;
			else
				cout << "Failed to reserve seat. Please choose another seat." << endl;
			break;

		}
		case 3:
			th1.displaySeats();
			break;

		case 4:
			return 0;

		default:
			cout << "Invalid choice. Please try again." << endl;
			break;

		}

	}

}