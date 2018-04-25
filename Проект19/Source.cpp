
#include <iostream>
#include <iomanip>
#include <memory> // for auto_ptr, shared_ptr, unique_ptr
#include <string>
#include <vector>

using namespace std;
#define Line 	cout << setfill('-') << setw(40) << "\n";

class Person {
public:
	string name;
	shared_ptr<Person> mother;
	shared_ptr<Person> father;
	vector<shared_ptr<Person>> kids;
	Person(const string& n,
		shared_ptr<Person> m = nullptr,
		shared_ptr<Person> f = nullptr)
		: name(n), mother(m), father(f) {
	}
	~Person() {
		cout << "delete " << name << endl;
	}
};




shared_ptr<Person> initFamily(const string& name)
{
	cout << "Create family for " << name << endl;
	shared_ptr<Person> mom(new Person(name + "'s mom"));
	cout << "mom is shared " << mom.use_count() << " times" << endl;
	shared_ptr<Person> dad(new Person(name + "'s dad"));
	cout << "dad is shared " << dad.use_count() << " times" << endl << endl;

	shared_ptr<Person> kid(new Person(name, mom, dad));
	cout << "kid is shared " << kid.use_count() << " times" << endl;

	cout << "mom is shared " << mom.use_count() << " times" << endl;
	cout << "dad is shared " << dad.use_count() << " times" << endl << endl;

	mom->kids.push_back(kid);
	cout << "kid is shared " << kid.use_count() << " times" << endl;

	dad->kids.push_back(kid);
	cout << "kid is shared " << kid.use_count() << " times" << endl;
	Line
		return kid;
}
void printFamily(const shared_ptr <Person>  p) // зніметься копія обєкту p
{
	cout << "\nFamily:\n";
	cout << p->mother->name << endl << p->father->name << endl;
	cout << p->mother->kids[0]->name << endl;; //   for shared
											   //cout << p->mother->kids[0].lock()->name << endl;  // for  weak
	cout << "counters(mother, father, child) :" << p->mother.use_count() << " " << p->father.use_count() << " " << p.use_count() << endl;
}


int main()
{
	{
		shared_ptr<Person> p = initFamily("Nico");
		cout << "Nico's family exists" << endl;
		cout << "- Nico is shared " << p.use_count() << " times" << endl;
		//printFamily(p);

		cout << "\n- Family:\n";
		cout << p->mother->name << endl << p->father->name << endl;
		cout << p->mother->kids[0]->name << endl;; //   for shared
												   //	cout << p->mother->kids[0].lock()->name << endl;  // for  weak
		cout << "counters(mother, father, child) :" << p->mother.use_count() << " " << p->father.use_count() << " " << p.use_count() << endl;

		Line
			p.reset();
		p = initFamily("Jim");
		cout << "\nJim's family exists" << endl;
		printFamily(p);
		Line
	}
	return 0;
}