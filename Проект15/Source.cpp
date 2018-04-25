#include<iostream>
#include<list>
#include<string>
#include<algorithm>
#include<iterator>
#include<iomanip>
#include <fstream>
#include"conio.h"

using namespace std;

struct Product
{
	string _name;
	float _price;

	Product(string name, float price) :_name(name), _price(price) {};

};

ostream & operator <<(ostream &os, const Product& prod)
{
	return os << prod._name << ": " << prod._price;
}
istream & operator >> (istream &input, Product& prod)
{
	cout << "Enter name product:";
	input >> prod._name;
	cout << "Enter price:";
	input >> prod._price;
	return input;
}

bool compareByPrice(const Product &a, const Product &b) {
	return a._price < b._price;
}

bool compareByName(const Product &a, const Product &b) {
	return a._name < b._name;
}
bool compareProduct(const Product &a, const Product &b) {
	return ((a._name == b._name) && (a._price == b._price));
}

class Shop
{
public:
	Shop();
	~Shop();

private:

};

Shop::Shop()
{
}

Shop::~Shop()
{
}





int main()
{
	ofstream saver("food.txt");//створення файлового обєкту
	ostream_iterator<Product>  outItFile(saver, "\n");

	//продуктові товари
	list<Product> FdProd = { Product("milk",18.00),Product("cheese",45.00),Product("sausage",151.00),Product("sour cream",25.00),Product("buckwheat",20.00) };
	//непродуктові товари
	//list<Product> NFdProd = { Product("shampoo ",60.00),Product("soap",18.00),Product("shaves",37.00),Product("washing powder",150.00),Product("gel",40.00) };
	list<Product> NFdProd = { Product("shampoo ",60.00),Product("soap",18.00),Product("shaves",37.00),Product("washing powder",150.00),Product("milk",18.00) };
	//всі товари
	list<Product> AllProd;
	list<Product> Temp;

	// вивід продуктових товарів через потоковий ітератор ostream_iterator в консоль
	cout << "Food product:" << endl;
	copy(FdProd.begin(), FdProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;
	
	// вивід непродуктових товарів через потоковий ітератор ostream_iterator в консоль
	cout << "Notfood product:" << endl;
	copy(NFdProd.begin(), NFdProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;


	// вивід через потоковий ітератор ostream_iterator в файл
	//copy(FdProd.begin(), FdProd.end(), outItFile);

	// лямбди для сортування полів
	//auto SortName = [](Product& obj1, Product& obj2) {return obj1._name <= obj2._name; };
	auto SortName = [](Product& obj1, Product& obj2) {
		if (obj1._name == obj2._name)
			return obj1._name < obj2._name;
		return obj1._name < obj2._name; };

	auto SortPrice = [](Product& obj1, Product& obj2) {return obj1._price <= obj2._price; };

	//сортування по імені продуктових товарів
	FdProd.sort(SortName);
	//stable_sort(FdProd.begin(), FdProd.end(), compareByName);
	//сортування по імені непродуктових товарів
	NFdProd.sort(SortName);


	cout << "Sort by name:" << endl;
	copy(FdProd.begin(), FdProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;

	copy(NFdProd.begin(), NFdProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;



	//------------------------------------ MERGE ----------------------------------------------------
	// Merge двох списків товарів в третій список

	cout << "All list:" << endl;

	AllProd.sort(SortName);
	//FdProd.merge(NFdProd);
	merge(FdProd.begin(), FdProd.end(), NFdProd.begin(), NFdProd.end(), back_inserter(AllProd), SortName);

	copy(AllProd.begin(), AllProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;
	_getch();




	//-------------------------------------Set_intersection-------------------------------------------
	//set_intersection Перевірка чи є однакові елементи в обох списках - формуємо третій список
	auto Result1 = set_intersection(FdProd.begin(), FdProd.end(), NFdProd.begin(), NFdProd.end(), back_inserter(Temp), SortName);
	cout << "set_intersection:" << endl;
	if (Temp.empty())
	{
		cout << "Not products occurring in both lists!" << endl;
	}
	else
	{
		copy(Temp.begin(), Temp.end(), ostream_iterator<Product>(cout, "\n"));
		cout << endl;
	}
	Temp.clear();
	_getch();

	//---------------------------------------Set_difference---------------------------------------- 
	//set_difference Перевірка чи є різні елементи в обох списках - формуємо третій список

	auto Result2 = set_difference(FdProd.begin(), FdProd.end(), NFdProd.begin(), NFdProd.end(), back_inserter(Temp), SortName);
	cout << "set_difference:" << endl;
	if (Temp.empty())
	{
		cout << "Not difference products in both lists!" << endl;
	}
	else
	{
		cout << "Difference products:" << Temp.size() << endl;
		copy(Temp.begin(), Temp.end(), ostream_iterator<Product>(cout, "\n"));
		cout << endl;
	}
	Temp.clear();
	_getch();


	//-----------------------------------------------Set_union-------------------------------------
	//set_union Перевірка чи є  елементи в обох списках - формуємо третій список з елементів в одному екземплярі

	auto Result3 = set_union(FdProd.begin(), FdProd.end(), NFdProd.begin(), NFdProd.end(), back_inserter(Temp), SortName);
	cout << "Set_union:" << endl;
	if (Temp.empty())
	{
		cout << "Both lists empty!" << endl;
	}
	else
	{
		cout << "Union products:" << Temp.size() << endl;
		copy(Temp.begin(), Temp.end(), ostream_iterator<Product>(cout, "\n"));
		cout << endl;
	}
	Temp.clear();
	_getch();


	//----------------------------------------------unique -----------------------------------------------

	auto Result4 = unique(AllProd.begin(), AllProd.end(), compareProduct);
	if (Result4 != AllProd.end())
	{
		AllProd.erase(Result4, AllProd.end());
	}
	copy(AllProd.begin(), AllProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;
	_getch();


	//------------------------------------------Sort---------------------------------------------------

	/*
	сортування по ціні
	FdProd.sort(SortPrice);
	NFdProd.sort(SortPrice);

	cout << "Sort by price:" << endl;

	copy(FdProd.begin(), FdProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;

	copy(NFdProd.begin(), NFdProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;
	*/
	
	/*  працює

	//-----------------------------------Transform-----------------------------------------------------
	8) Збільшення ціни товарів
	float PriceIncrease = 1.5;
	cout << "Transform:" << endl;
	transform(FdProd.begin(), FdProd.end(), FdProd.begin(), [PriceIncrease](Product& obj) {obj._price *= PriceIncrease;   return obj; });

	copy(FdProd.begin(), FdProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;
	*/



	/*
	//------------------------------------Erase1-----------------------------------------------------------------
	//видалення по назві
	cout << "Erase of product" << endl;
	string NameEraseProduct;
	cout << "Enter name of product: ";
	cin >> NameEraseProduct;
	auto pos = find_if(AllProd.begin(), AllProd.end(), [NameEraseProduct](Product& obj) {return obj._name == NameEraseProduct; });
	if (pos != AllProd.end())
	{
	cout << "Product " << pos->_name << " erase !" <<endl;
	AllProd.erase(pos);

	copy(AllProd.begin(), AllProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;
	}
	else
	{
	cout << "Product not found for erase!" << endl;
	}

	*/

	//---------------------------------------Erase1---------------------------------------------------------------------------
	/*
	//видалення по ціні
	cout << "Erase of product by price" << endl;
	float PriceEraseProduct;
	cout << "Enter price of product: ";
	cin >> PriceEraseProduct;
	auto pos = find_if(AllProd.begin(), AllProd.end(), [PriceEraseProduct](Product& obj) {return obj._price == PriceEraseProduct; });
	if (pos != AllProd.end())
	{
	cout << "Product " << pos->_name << " with price: " << pos->_price << " erase !" << endl;
	AllProd.erase(pos);

	copy(AllProd.begin(), AllProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;
	}
	else
	{
	cout << "Product with this price not found for erase!" << endl;
	}
	*/



	//-------------------------------------------------find_if--------------------------------------------------------------------
	/*
	// пошук ціни по назві
	cout << "Find price of product by name"<<endl;
	string NameFindProduct;
	cout << "Enter name of product: ";
	cin>> NameFindProduct;
	auto pos = find_if(AllProd.begin(), AllProd.end(), [NameFindProduct](Product& obj) {return obj._name== NameFindProduct; });
	if (pos!= AllProd.end())
	{
	cout << "Price of " << pos->_name << ":" << pos->_price << " grn" << endl;
	}
	else
	{
	cout << "Product not found!" << endl;
	}

	*/

	//---------------------------------------------------------------------------------------------------------------------
	//вставлення в відсортований список

	istream_iterator<Product> InputIter(cin);
	istream_iterator<Product> EndOfStream;

	// вставлення елемента  ?????

    copy(InputIter, EndOfStream, inserter(AllProd, find_if(AllProd.begin(), AllProd.end(), SortName)));
	//Product One("ketchup", 20);
	//auto pos = find_if(AllProd.begin(), AllProd.end(), [=](Product& obj) {return obj._name > One._name; });
	//AllProd.insert(pos, One);
	copy(AllProd.begin(), AllProd.end(), ostream_iterator<Product>(cout, "\n"));
	cout << endl;



	return 0;

}