#include<iostream>
#include<iomanip>
using namespace std;
class Books
{
private:
	string isbnNo, title, author;
	float price, discountedprice, discountperc;
public:
	Books();
	Books(string, string, string, float, float);
	void set_Data();
	void calcDiscountedPrice();
	void print();
	float getDiscountedPrice();
	~Books();
};

Books::Books()
{
	isbnNo = "";
	title = "";
	author = "";
	price = 0.00;
	discountedprice = 0;
}

Books::Books(string n, string t, string a, float p, float d)
{
	isbnNo = n;
	title = t;
	author = a;
	price = p;
	discountedprice = d;
}

Books::~Books()
{
	cout<<"\nEnjoy reading "<<title<<endl;
}	

void Books::set_Data()
{
	fflush(stdin);
	cout<<"\nEnter ISBN\t\t: ";
	getline(cin, isbnNo);
	cout<<"Enter Title\t\t: ";
	getline(cin, title);
	cout<<"Enter Author's name\t: ";
	getline(cin, author);
	cout<<"Enter price\t\t: RM ";
	cin>>price;
	cout<<"Enter discount (%)\t: ";
	cin>>discountperc;
}

void Books::calcDiscountedPrice()
{
	discountedprice = price*(100-discountperc)/100;
}

void Books::print()
{
	cout<<"\n-------------------------------------------------"<<endl;
	cout<<"\t\tBooks Details"<<endl;
	cout<<"\n-------------------------------------------------"<<endl;
	cout<<"ISBN\t\t: "<<isbnNo<<endl;
	cout<<"Title\t\t: "<<title<<endl;
	cout<<"Author\t\t: "<<author<<endl;
	cout<<"Original Price\t: RM "<<fixed<<setprecision(2)<<price<<endl;
	cout<<"Discounted Price: RM "<<discountedprice<<endl;	
}

float Books::getDiscountedPrice()
{
	return discountedprice;
}


void func(Books &B)
{
	B.set_Data();
	B.calcDiscountedPrice();
	B.print();
}

int main()
{
	int count;
	Books B1("10200912", "7 Habits of Highly Effective People", "Stephen Covey", 400.00, 30);
	B1.calcDiscountedPrice();
	B1.print();
	
	Books B2[3];
	float expensive = 0.00;
	int countBook = 0;
	for(int i=0; i<3; i++)
	{
		func(B2[i]);
		if(expensive<B2[i].getDiscountedPrice())
			expensive = B2[i].getDiscountedPrice();
		if(B2[i].getDiscountedPrice()<30.00)
			count++;
	}
	
	cout<<"The most expensive books: RM "<<expensive<<endl;
	cout<<"The number of books that are below RM 30 are : "<<count<<endl;
	return 0;
}




