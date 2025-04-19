#include <iostream> 
#include <string> 
using namespace std; 

//Base class 
class TouristPlace
{ 
	protected: 
		string name, location, hotel; 
		double price; 
		int adults, children; 
	public: 
	//Default constructor 
		TouristPlace() : name(""), location(""), price(0.0), hotel(""), adults(0), children(0) {} 
		
	//Parameterized constructor 
		TouristPlace(string n, string l, double p, string h, int a, int c) : name(n), location(l), price(p), hotel(h), adults(a), children(c){} 

	//Function to upgrade room 
		virtual void upgradeRoom() 
		{ 
			cout << "\nYou have additional people. Do you want to upgrade the room (+ RM120)?  "<< endl; 
			cout << "1 For Yes, 0 For No : "; 
			int upgradeChoice; 
			cin >> upgradeChoice; 
			if (upgradeChoice == 1) 
			{ 
				price += 100; // room upgrade costs RM 100 
				cout << "Room upgraded! Additional RM 100 added to the total price." << endl; 
			} 
		} 
	//Function to add additional adults and children with price adjustments 
		virtual void addPeople(int additionalAdults, int additionalChildren) = 0; 

	//Friend function declaration 
		friend void showDetails(TouristPlace& place); 
}; 

//Derived class 1 
class Package3D2N : public TouristPlace
{ 
	public:   
	//Parameterized constructor 
		Package3D2N(string l, string h) : TouristPlace("Package 3D2N", l, 1200, h, 2, 2){} 

	//Add additional people price adjustment 
		void addPeople(int additionalAdults, int additionalChildren) override
		{ 
			adults += additionalAdults; 
			children += additionalChildren; 
			price += (additionalAdults * 150) + (additionalChildren * 70); 
			if (additionalAdults > 0 || additionalChildren > 0)
			{ 
				upgradeRoom(); 
			} 
		} 
}; 


//Derived class 2 
class Package5D4N : public TouristPlace
{ 
	public: 
	//Parameterized constructor 
		Package5D4N(string l, string h) : TouristPlace("Package 5D4N", l, 1750, h, 3, 3){} 
	
	//Add additional people with price adjustment 
		void addPeople(int additionalAdults, int additionalChildren) override
		{ 
			adults += additionalAdults; 
			children += additionalChildren; 
			price += (additionalAdults * 150) + (additionalChildren * 70);  
			if (additionalAdults > 0 || additionalChildren > 0)
			{ 
				upgradeRoom(); 
			} 
		} 
}; 

 
//Derived class 3 
class Package7D6N : public TouristPlace
{ 
	public: 
	//Parameterized constructor 
		Package7D6N(string l, string h) : TouristPlace("Package 7D6N", l, 2600, h, 4, 4){} 
	
	//Add additional people with price adjustment 
		void addPeople(int additionalAdults, int additionalChildren) override
		{ 
			adults += additionalAdults; 
			children += additionalChildren; 
			price += (additionalAdults * 150) + (additionalChildren * 70);  
			if (additionalAdults > 0 || additionalChildren > 0) 
			{ 
				upgradeRoom(); 	
	       	} 		
	   	} 
}; 

 

 

//friend function definiton 
void showDetails (TouristPlace& place) 
{ 
	cout << "\nName: " << place.name << endl; 
	cout << "Location: " << place.location << endl;  
	cout << "Hotel: " << place.hotel << endl; 
	cout << "Adults: " << place.adults << endl; 
	cout << "Children: " << place.children << endl; 
	cout << "Price: RM " << place.price << endl; 
	
    cout <<"\n+===================================================================+  "<<endl; 
	cout << "|Your Booking is confirmed                                          |" << endl; 
	cout << "|We will email you the tickets and others detail in 2 working days, |" << endl; 
	cout << "|If you have any question,please do call [0112345678]               |" << endl; 
	cout << "|Thank You :)                                                       |" << endl; 
	cout <<"+===================================================================+  "<<endl;
} 

 

int main()
{ 
	//Array of location and hostels 
		string locations[] = {"Langkawi", "Penang", "Desaru"}; 
		string hotels[][2] =
							{ 
								{"Berjaya Langkawi Resort", "The Danna Langkawi Hotel"}, 
								{"The Light Hotel", "The Prestige Hotel"}, 
								{"Hard Rock Desaru Coast Hotel", "Anantara Desaru Coast Resort and Villas"} 
							}; 
	    int packageChoice, locationChoice, hotelChoice, additionalAdults, additionalChildren; 
	
	//Array of TouristPlace pointers 
		TouristPlace* packages[3]; 
		cout<<"Welcome To IEEE Travel Agency"<< endl;
	
	    cout << "\n***************************************************************" << endl; 
	    cout << "* Package 1 : [3D2N] - RM 1200                                *" << endl; 
	    cout << "* Includes: 1 Room, 1 King Bed, 1 Queen Bed                   *" << endl; 
	    cout << "* Suitable for: 2 Adults, 2 Children                          *" << endl; 
	    cout << "***************************************************************" << endl; 
	
	    cout << "\n***************************************************************" << endl; 
	    cout << "* Package 2 : [5D4N] - RM 1750                                *" << endl; 
	    cout << "* Includes: Main Bedroom: 1 King Bed, 1 Bedroom: 2 Queen Beds *" << endl; 
	    cout << "* Suitable for: 3 Adults, 3 Children                          *" << endl; 
	    cout << "***************************************************************" << endl; 

	    cout << "\n***************************************************************" << endl; 
	    cout << "* Package 3 : [7D6N] - RM 2600                                *" << endl; 
	    cout << "* Includes: Refer to the website                              *" << endl; 
	    cout << "* Suitable for: 4 Adults, 4 Children                          *" << endl; 
	    cout << "***************************************************************\n" << endl; 
	
	//User choose the package 
		cout << "Choose a package (1: 3D2N, 2: 5D4N, 3: 7D6N): "; 
	    cin >> packageChoice; 
	    cin.ignore();	//Ignore the newline character left in the buffer  
	
	//Validate package choice 
		if(packageChoice < 1|| packageChoice > 3) 
		{ 
			cout << "invalid package choice!"<< endl; 
			return 1; 
		} 
	
	//Prompt user to choose a location 
		cout<< "Choose a location (0: Langkawi, 1: Penang, 2: Desaru): " ; 
		cin>>locationChoice; 
		cin.ignore();	// Ignore the newline character left in the buffer 
	
	//Validate location choice 
		if (locationChoice < 0|| locationChoice > 2)
		{ 
			cout << "Invalid location choice!" << endl; 	
			return 1; 
		} 
	
	//Prompt user to choose a hotel 
		cout << "Choose a hotel/resort: \n(0: " <<hotels[locationChoice][0] <<", 1: "<< hotels[locationChoice][1]<<"): "; 
		cin >>hotelChoice; 
		cin.ignore();	// Ignore the newline character left in the buffer 
	
	//Validate hotel choice 
		if (hotelChoice < 0 || hotelChoice > 1)
		{ 
			cout << "Invalid hotel choice!"<<endl; 
			return 1; 
		} 
	
	// Create the selected package based on our user choice 
		
		switch (packageChoice)
		{ 
			case 1: 
			packages[0] = new Package3D2N(locations[locationChoice], hotels[locationChoice][hotelChoice]); 
			break; 
			
			case 2: 
			packages[1] = new Package5D4N(locations[locationChoice],hotels[locationChoice][hotelChoice]); 
			break; 
	
			case 3: 
			packages[2] = new Package7D6N(locations[locationChoice],hotels[locationChoice][hotelChoice]); 
			break; 
		} 
	
	//Prompt user to add addtional adult and children 
		cout << "\nEnter number of addtional adults  (+RM 150) : " ; 
		cin >>additionalAdults; 
		cout << "Enter number of additional children  (+RM 70) : " ; 
		cin >> additionalChildren; 
	
	//Add additional people to the selected package 
		packages[packageChoice - 1]->addPeople(additionalAdults,additionalChildren);
	
	//Use friend function to show details 
		showDetails(*packages[packageChoice - 1]); 
	
	//Free dynamically allocated memory 
		for (int i = 0; i < 3;i++)
		{ 
			if (packages[i]!=NULL)
			{
				delete packages[i]; 
			}	
		} 
	
	return 0; 
} 

