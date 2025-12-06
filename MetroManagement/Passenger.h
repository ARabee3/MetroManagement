#pragma once
#include <iostream>
#include<string>
#include "SmartCard.h"
using namespace std;

class Passenger {
private:
	string Name;
	string NationalId;
	string Email;
protected:
	SmartCard* card; // Aggregation card a Passenger can replace his card
public:
	Passenger(string n, string id, string email)
	{
		SetName(n);
		SetNationalID(id);
		SetEmail(email);
	}

	//Setters and Getters
	void SetName(string _name) {
		if (_name.length() < 6)
			throw invalid_argument("Name must be greater than 6 characters");
		this->Name = _name;
	}
	string GetName() {
		return this->Name;
	}

	void SetNationalID(string _id) {
		if (_id.length() < 6)
			throw invalid_argument("Name must be greater than 6 characters");
		this->NationalId = _id;
	}
	string GetNationalID() {
		return this->NationalId;
	}

	void SetEmail(string _email) {
		if (_email.find('@') != std::string::npos) {
			this->Email = _email;
		}
		return throw invalid_argument("Invalid Email");
	}
	string GetEmail() {
		return this->Email;
	}
	
	// Methods
	void ViewProfile() {
		cout << "Name: " << this->Name << endl;
		cout << "NationalId: " << this->NationalId << endl;
		cout << "Email: " << this->Email << endl;
	}
	~Passenger() {
		cout << "Passenger => " << this->Name << " is being Deleted!" << endl;
	}
};