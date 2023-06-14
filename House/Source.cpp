/*Create a program simulating an apartment building.It is necessary to have classes «Person», «Apartment», «House».Class «Apartment» contains a dynamic array of objects of class «Person».Class «House» contains an array of objects of class «Apartment».Each class contains the member variablesand member functions that are required for the class domain.Please note that memory is dynamically allocated to string values.For example, for name in class «Human».Do not forget to provide classes with different constructors(copy constructor is required), destructors.In main, test the work of the received set of classes.*/
#include<iostream>
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
	void SetName(const char*name);
	void SetSurname(const char* surname);
	void SetAge(int age);
	//Getters
	char* GetName();
	char* GetSurname();
	int GetAge();
private:
	char* _name;
	char* _surname;
	int _age;
	int _size;
};

int main()
{
	Person person1("Marry","Dobby", 21);
	/*person1.SetName();
	person1.SetSurname();
	person1.SetAge();*/
	Person person2("Alex", "Smit", 25);
	Person person3(person1);
	/*person1.DisplayPerson();
	person2.DisplayPerson();*/
	person3.SetName("Peg");
	/*person3.DisplayPerson();*/
	system("pause");
	return 0;
}

Person::Person()
{
	_age = 0;
	_size = 50;
	_name = new char[_size];
	_surname = new char[_size];
	if (_name == NULL|| _surname == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	_name[0] = { '\0' };
	_surname[0] = { '\0' };
	
}

Person::Person(const char* name, const char* surname, int age)
{	
	_age = age;
	_size = 50;
	_name = new char[_size];
	_surname = new char[_size];
	if (_name == NULL || _surname == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	for (int i = 0; ; i++)
	{
		if (name[i] == '\0')
		{
			_name[i] = name[i];
			break;
		}
		_name[i] = name[i];
	}
	for (int i = 0; ; i++)
	{
		if (surname[i] == '\0')
		{
			_surname[i] = surname[i];
			break;
		}
		_surname[i] = surname[i];
	}

}

Person::Person(const Person& initial)
{
	this->_size = initial._size;
	this->_age = initial._age;
	this->_name = new char[_size];
	this->_surname = new char[_size];
	if (_name == NULL || _surname == NULL)
	{
		cout << "Error\n";
		exit(-1);
	}
	for (int i = 0; i < _size; i++)
	{
		this->_name[i] = initial._name[i];
	}
	for (int i = 0; i < _size; i++)
	{
		this->_surname[i] = initial._surname[i];
	}
}

Person::~Person()
{
	delete[]_name;
	delete[]_surname;
}

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
	gets_s(_name, _size);
	cin.ignore();
}

void Person::SetSurname()
{
	gets_s(_surname, _size);
	cin.ignore();
}

void Person::SetAge()
{
	cin >> _age;
	cin.ignore();
}

void Person::SetName(const char* name)
{
	for (int i = 0; ; i++)
	{
		if (name[i] == '\0')
		{
			_name[i] = name[i];
			break;
		}
		_name[i] = name[i];
	}
}

void Person::SetSurname(const char* surname)
{
	for (int i = 0; ; i++)
	{
		if (surname[i] == '\0')
		{
			_surname[i] = surname[i];
			break;
		}
		_surname[i] = surname[i];
	}
}

void Person::SetAge(int age) { _age = age; }

char* Person::GetName(){return _name;}

char* Person::GetSurname(){return _surname;}

int Person::GetAge(){return _age;}
