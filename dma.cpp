//Karl Shiu, bkshiu1@myseneca.ca, 131531246, 22-1-2025
//I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
#include <iostream>
#include "dma.h"
using namespace std;
namespace seneca {
	//STEP 2
	void reverse() {
		int num = 0;
		cout << "Enter the number of double values:\n> ";
		cin >> num;
		double* arr = new double[num];

		for (int i = 0; i < num; i++) {
			cout << i+1 << "> ";
			cin >> arr[i];
		}

		for (int i = num - 1; i >= 0; i--){
			cout << arr[i] << endl;
		}
		delete[] arr;
	}
	//STEP3
	Contact* getContact() {
		Contact* CONTACT = new Contact;
		cout << "Name: ";
		cin >> CONTACT->m_name;
		cout << "Last name: " ;
		cin >> CONTACT->m_lastname ;
		cout << "Phone number: ";
		cin >> CONTACT->m_phoneNumber;
		return CONTACT;
	}
	void display(const Contact& C) {
		cout << C.m_name << " " << C.m_lastname << ", +" << C.m_phoneNumber << endl;
	}
	void deallocate(Contact* C) {
		delete C;
	}
	void setEmpty(Contact& C) {
		
		C.m_name[0] = '\0';
		C.m_lastname[0] = '\0';
		C.m_phoneNumber = 0;
	}
}
