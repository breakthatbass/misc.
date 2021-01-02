/***
* ultra basic framework to work off of for object oriented
* programming in c++. it's pretty similar to structs in C
* but sort of...nicer in some situations.
* 
* ...i still don't like C++ though!
* C for the win.
*
* this is from https://www.youtube.com/watch?v=1v_4dL8l8pQ
* */

#include <iostream>

using namespace std;

class Car {
private:
	string Color;
	double Price;
protected:
	// protected keeps the class private, but lets the 
	// inherited classes access these
	string Name;
	bool IsBroken;

public:
	/**
	 * below is an a eample of encapsulation
	 * which is the concept of the variables of a class 
	 * are private, we can't change them from the main function directly
	 * but we can change them through the public functions below
	 *
	 ***/

	// this function is called a Constructor
	// it define the object of the class and sets the variables
	// basically def __init__() from python
	Car(string name, string color, double price) {
		Name = name;
		Color = color;
		Price = price;
		IsBroken = false;
	}

	void getinfo() {
		cout << Name << endl;
		cout << Color << endl;
		cout << "$" << Price << endl;
		string state = IsBroken ? "busted!" : "running just fine";
		cout << state << endl;
	}

	void crashcar() {
		cout << Name << " crashed" << endl;
		IsBroken = true;
	}

	void repaircar(){
		cout << Name << " repaired" << endl;
		IsBroken = false;
	}

	void move() {
		if (IsBroken) 
			cout << Name << " is broken" << endl;
		 else 
			cout << Name << " is driving" << endl;
	}
};

/** 
 * this is an example of INHERITANCE
 * it is a seperate class but it inherits everything from the Car class
 * after the semi-colons, having 'public' means it also inherits all
 * the public aspects (the public functions) of the Car class
 * **/
class FlyingCar: public Car {
public:
	// below takes in all the construcrs of Car and puts them into
	// the FlyingCar class
	FlyingCar(string name, string color, double price):Car(name, color, price) {
	}

	void move() {
		if (IsBroken)
			cout << Name << " is broken" << endl;
		else
			cout << Name << " is flying" << endl;
	}
};

class UnderwaterCar: public Car {
public:
	UnderwaterCar(string name, string color, double price):Car(name, color, price) {
	}
	void move() {
		if (IsBroken) 
			cout << Name << " is broken" << endl;
		 else 
			cout << Name << " is swimming" << endl;
	}
};

int main()
{
	Car my_car("ford", "red", 50000);
	//Car my_car2("volvo", "black", 75000);
	my_car.getinfo();
	my_car.crashcar();
	my_car.getinfo();
	my_car.move();
	my_car.repaircar();
	my_car.move();
	cout << "\n\n";
	FlyingCar fc("sky fury", "black", 500000);
	fc.getinfo();
	fc.move();
	UnderwaterCar uc("Sea Storm", "blue", 600000);
	uc.getinfo();
	uc.crashcar();
	uc.move();

	// pointers
	// same as with C struct pointers
	Car *car1 = &fc;
	Car *car2 = &uc;
	car1->crashcar();
	car2->crashcar();
}