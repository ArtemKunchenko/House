/*Create a program simulating an apartment building.It is necessary to have classes �Person�, �Apartment�, �House�.Class �Apartment� contains a dynamic array of objects of class �Person�.Class �House� contains an array of objects of class �Apartment�.Each class contains the member variablesand member functions that are required for the class domain.Please note that memory is dynamically allocated to string values.For example, for name in class �Human�.Do not forget to provide classes with different constructors(copy constructor is required), destructors.In main, test the work of the received set of classes.*/
#include<iostream>
#include<string>;
using namespace std;

class Person
{
public:
	Person(); //constructor default
	Person(const char* name, const char* surname, int age);//constructor with params
	Person(const Person& initial);//copy constructor
	~Person();//distructor
	void DisplayPerson();//print whole information about person
	//Setters
	void SetName();//after inputing name push "Enter" 2 times
	void SetSurname();//after inputing surname push "Enter" 2 times
	void SetAge();//after inputing age push "Enter" 2 times
	void SetName(const char* name);
	void SetSurname(const char* surname);
	void SetAge(int age);
	//Getters
	string GetName();
	string GetSurname();
	int GetAge();
private:
	string _name;
	string _surname;
	int _age;
	int _size;
};

class Apartment
{
public:
	Apartment();//constructor default
	Apartment(Person resident, int rooms, double square);//constructor with params
	Apartment(int rooms, double square);//constructor with params
	Apartment(const Apartment& initial);//copy constructor
	~Apartment();//distructor
	void DisplayApartment();
	void AddResident(Person resident_new);
	//Setters
	void SetRooms();
	void SetSquare();
	//Getters
	int GetRooms();
	double GetSquare();
	int GetResidents();

private:
	Person* _residents;
	int _quantity_residents;
	int _rooms;
	double _square;
};

int main()
{
	setlocale(LC_CTYPE, "ru");
	Person person1("Marry", "Dobby", 21);
	/*person1.SetName();
	person1.SetSurname();
	person1.SetAge();*/
	Person person2("Alex", "Smit", 25);
	Person person3(person1);
	/*person1.DisplayPerson();
	person2.DisplayPerson();*/
	person3.SetName("Peg");
	/*person3.DisplayPerson();*/
	Apartment apartment1;
	apartment1.AddResident(person2);
	apartment1.AddResident(person3);
	Apartment apartment2(person1, 3, 57.5);
	Apartment apartment3(2, 46.1);
	Apartment apartment4(apartment3);
	apartment1.DisplayApartment();
	apartment2.DisplayApartment();
	apartment3.DisplayApartment();
	apartment4.DisplayApartment();
	system("pause");
	return 0;
}

Person::Person()
{
	_age = 0;
	_size = 20;
	_name = "";
	_surname = "";

}

Person::Person(const char* name, const char* surname, int age)
{
	_age = age;
	_size = 20;
	_name = name;
	_surname = surname;
}

Person::Person(const Person& initial)
{
	this->_size = initial._size;
	this->_age = initial._age;
	this->_name = initial._name;
	this->_surname = initial._surname;
	
}

Person::~Person(){}


void Person::DisplayPerson()
{
	cout << "____________________________________\n";
	cout << "Name: " << GetName() << endl;
	cout << "Surname: " << GetSurname() << endl;
	cout << "Age: " << GetAge() << endl;
	cout << "____________________________________\n";
}

void Person::SetName()
{
	/*gets_s(_name);
	cin.ignore();*/
}

void Person::SetSurname()
{
	/*gets_s(_surname, _size);
	cin.ignore();*/
}

void Person::SetAge()
{
	cin >> _age;
	cin.ignore();
}

void Person::SetName(const char* name){_name = name;}

void Person::SetSurname(const char* surname) { _surname = surname; }

void Person::SetAge(int age) { _age = age; }

string Person::GetName() { return _name; }
string Person::GetSurname() { return _surname; }

int Person::GetAge() { return _age; }

Apartment::Apartment()
{
	_residents = nullptr;
	_quantity_residents = 0;
	_rooms = 0;
	_square = 0;
}

Apartment::Apartment(Person resident, int rooms, double square)
{
	_rooms = rooms;
	_square = square;
	_quantity_residents = 1;
	_residents = new Person[_quantity_residents];
	if (_residents == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	_residents[0] = resident;
}

Apartment::Apartment(int rooms, double square)
{
	_rooms = rooms;
	_square = square;
	_quantity_residents = 0;
	_residents = nullptr;
}

Apartment::Apartment(const Apartment& initial)
{
	if (initial._quantity_residents == 0)
	{
		this->_rooms = initial._rooms;
		this->_square = initial._square;
		this->_quantity_residents = initial._quantity_residents;
		this->_residents = nullptr;
	}
	else
	{
		this->_rooms = initial._rooms;
		this->_square = initial._square;
		this->_quantity_residents = initial._quantity_residents;
		this->_residents = new Person[_quantity_residents];
		if (_residents == NULL)
		{
			cout << "Error\n";
			exit(-1);
		}
		for (int i = 0; i < _quantity_residents; i++)
		{
			_residents[i] = initial._residents[i];
		}
	}
}

Apartment::~Apartment()
{
	if (_residents != nullptr) delete[]_residents;
}

void Apartment::DisplayApartment()
{
	cout << "Rooms: " << GetRooms() << "\tSquare: " << GetSquare() <<"\tResidents: " << GetResidents()<<endl;
	if (_quantity_residents != 0)
	{
		for (int i = 0; i < _quantity_residents; i++)
		{
			cout << _residents[i].GetName() << " " << _residents[i].GetSurname() << " - " << _residents[i].GetAge() << " years\n";
		}

	}
	else
	{
		cout << "Apartment is empty\n";
	}

}

void Apartment::AddResident(Person resident_new)
{
	if (_quantity_residents != 0)
	{
	
		Person* tempResident = new Person[_quantity_residents];
		for (int i = 0; i < _quantity_residents; i++)
			tempResident[i] = _residents[i];
		if (_residents != nullptr)
			delete[] _residents;
		_residents = new Person[_quantity_residents + 1];
		for (int i = 0; i < _quantity_residents; i++)
			_residents[i] = tempResident[i];
		_residents[_quantity_residents] = resident_new;
		_quantity_residents++;
		delete[] tempResident;

	}
	else
	{
		_quantity_residents++;
		_residents = new Person[_quantity_residents];
		if (_residents == NULL)
		{
			cout << "Error\n";
			exit(-1);
		}
		_residents[0] = resident_new;
	}
	
}

void Apartment::SetRooms() { cin >> _rooms; }

void Apartment::SetSquare() { cin >> _square; }

int Apartment::GetRooms() { return _rooms; }

double Apartment::GetSquare() { return _square; }

int Apartment::GetResidents(){return _quantity_residents;}
