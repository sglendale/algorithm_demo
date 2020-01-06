#include <iostream>
#include <vector>
#include <string>

using namespace std;

int menu();
int goodbye(); // returns 0
void construct_vector();
void display_vector();
void selection_sort();
void binary_search();
void linear_search();


vector<int> values; //To store user-inputed values. 

int main() {

	int option = 0;

	cout << "Welcome to the algorithm demo! Before we begin, let us construct a vector to perform operations on." << endl;
	construct_vector();

	cout<<"Please select an option : "<<endl;
	
	do {
		option = menu();
		if (option == 1)
			selection_sort();
		else if (option == 2)
			linear_search();
		else if (option == 3)
			binary_search();
	} while (option != 4); 
		
	return goodbye();

}

int menu() {

	int selection = 0;

	do {
		cout <<endl<< "1) Selection Sort an array of numbers" << endl
			<< "2) Perform a Linear Search on an array of numbers" << endl
			<< "3) Perform a binary search on an array of numbers" << endl
			<< "4) Quit demo" << endl;
		cin >> selection;

		if (selection < 1 || selection > 4)
		{
			cout << "Please enter valid input (numerical digits 1, 2, 3, or 4)"<<endl;
			selection = 0;
		}
	} while (selection == 0);

	return selection;
}

int goodbye() {

	cout << "Goodbye!";
	return 0;
}


void construct_vector() {

	int vector_size;
	int curr_number;
	char response;

	
	do {
			cout<< "Please specify a vector size greater than 1, and less than 10: ";
			cin >> vector_size;
			if (vector_size <= 1 || vector_size > 10)
				cout << "Invalid input detected." << endl; 
	} while (vector_size <= 1 || vector_size > 10); 

	cout << "Now please specify each value to be entered in the vector by entering the" << endl
		<< "numeric value, and then pressing enter (numbers may be between 1 and 9999):" << endl;
	

	for (int i = 0; i < vector_size; i++)
	{
		
		do {
			cin >> curr_number;
			if (curr_number < 1 || curr_number >9999)
				cout << "Invalid input detected. Please enter a number between 1 and 9999." << endl;
			else
				values.push_back(curr_number);

		} while (curr_number < 1 || curr_number >9999);	
	
	}

	display_vector();

	return; 
}

void display_vector() {

	cout << "Vector now has the following elements in the order displayed:" << endl
		<< "< ";

	for (int j = 0; j < values.size() -1; j++)
		cout << values[j] << ", ";

	cout << values[values.size() - 1] << " >" << endl;

	return;

}

void selection_sort() {

	int smallPos = 0;
	int smallest = 0;

	//1. Assume that the first value is the smallest
	for (int i = 0; i < values.size(); i++)
	{
		smallPos = i;
		smallest = values[smallPos]; 

		//2. Then compare it to all other values in the vector
		for (int j = i + 1; j < values.size(); j++)
		{
			//3. If a value is smaller, save it to placeholder "smallPos" and "smallest" value. 
			if (values[j] < smallest) 
			{
				smallPos = j;
				smallest = values[smallPos]; 

			}

		}
		//4. Once all other values have been compared, complete the swap. 
		values[smallPos] = values[i];
		values[i] = smallest;

	}
	
	display_vector(); 

	return;
}
void linear_search() {

	bool found = false; 
	int location = 0;
	int item = 0; 

	cout <<endl<< "Please input the number you would like to search for:" << endl;
	cin >> item;

	while (location < values.size() && found == false)
	{
		if (item == values[location]) {
			found == true;
			cout << "Your number is located at index value " << location <<"."<< endl;
			break;
			
		}
		location++;
	}

	return;
}
void binary_search() {

	int item = 0;
	bool found = false;
	int first = 0;
	int location;

	cout << "Note that binary search, works only on sorted vectors and the values you have entered will now be sorted using selection sort." << endl;
	selection_sort();
	cout << endl << "Next, please input the number you would like to search for:" << endl;
	cin >> item;

	int last = values.size() - 1;

	while (first <= last && !found) {

		location = (first + last) / 2;
		if (item < values[location])
			last = location - 1;
		else if (item > values[location])
			first = location + 1;
		else
		{
			found = true;
			cout << "Your number is in the vector and is located at index value " << location << "." << endl;
		}
	}
	if (found == false)
		cout << "Your number is not in the vector." << endl;

	return; 

}
