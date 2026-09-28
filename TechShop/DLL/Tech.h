#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

class Item {
public:
	string Name;
	double Price;
	int Amount;
	Item(string n, double p, int a) {
		Name = n;
		Price = p;
		Amount = a;
	}
	Item() {};
	virtual ~Item() {};
	virtual string GetTextOut() {
		return Name + ", " + to_string(Price) + "р., на складе: " + to_string(Amount) + ".";
	}
	virtual string GetTextFile() {
		return "i," + Name + "," + to_string(Price) + "," + to_string(Amount) + ",";
	}
};

class Tech : public Item {
public:
	string Producer;
	Tech(string n, double p, int a, string pr) {
		Name = n;
		Price = p;
		Amount = a;
		Producer = pr;
	}
	~Tech() {};
	virtual string GetTextOut() {
		return Name + " от " + Producer + ", " + to_string(Price) + "р., на складе : " + to_string(Amount) + ".";
	}
	virtual string GetTextFile() {
		return "t," + Name + "," + to_string(Price) + "," + to_string(Amount) + ",";
	}
};

class DataBase {
public:
	vector<Item*> All;
	map<string, set<Item*>> TypesAndItems;
	set<string> Types;
	void ReadFile() {
		Types.clear();
		Types.insert("Items");
		Types.insert("Tech");
		for (set<string>::iterator it = Types.begin(); it != Types.end(); it++) {
			TypesAndItems[*it].clear();
		}
		for (int i = 0; i < All.size(); i++) {
			delete All[i];
		}
		All.clear();
		ifstream file("Items.txt");
		string line;
		if (file) {
			while (!file.eof()) {
				getline(file, line);
				string Title = "", Producer = "", buf = "";
				int amount;
				double price;
				int i = 2;
				for (; i < line.size() - 1; i++) {
					Title += line[i];
					if (line[i + 1] == ',') {
						i += 2;
						break;
					}
				}
				for (; i < line.size() - 1; i++) {
					buf += line[i];
					if (line[i + 1] == ',') {
						price = stod(buf.c_str());
						buf = "";
						i += 2;
						break;
					}
				}
				for (; i < line.size() - 1; i++) {
					buf += line[i];
					if (line[i + 1] == ',') {
						amount = stoi(buf.c_str());
						buf = "";
						i += 2;
						break;
					}
				}
				if (line[0] == 'i') {
					TypesAndItems["Items"].insert(new Item(Title, price, amount));
				}
				if (line[0] == 't') {
					for (; i < line.size() - 1; i++) {
						Producer += line[i];
						if (line[i + 1] == ',') {
							break;
						}
					}
					TypesAndItems["Tech"].insert(new Tech(Title, price, amount, Producer));
				}
			}
		}
		file.close();
		set_union(TypesAndItems["Items"].begin(), TypesAndItems["Items"].end(), TypesAndItems["Tech"].begin(), TypesAndItems["Tech"].end(), back_inserter(All));
	}
	void WriteFile() {
		ofstream out("Items.txt");
		for (vector<Item*>::iterator it = All.begin(); it != All.end(); it++) {
			if (it == All.begin()) {
				out << (*it)->GetTextFile();
			}
			else {
				out << "\n" << (*it)->GetTextFile();
			}
		}
		out.close();
	}
	DataBase() {
		Types.insert("Items");
		Types.insert("Tech");
		ReadFile();
	}
	~DataBase() {
		WriteFile();
		for (set<string>::iterator it = Types.begin(); it != Types.end(); it++) {
			TypesAndItems[*it].clear();
		}
		for (int i = 0; i < All.size(); i++) {
			delete All[i];
		}
		All.clear();
	}
	string ShowAll() {
		string str = "";
		int i = 0;
		for (vector<Item*>::iterator it = All.begin(); it != All.end(); it++) {
			i++;
			if (it == All.begin()) {
				str += "[" + to_string(i) + "] ";
				str += (*it)->GetTextOut();
			}
			else {
				str += '\t';
				str += "[" + to_string(i) + "] ";
				str += (*it)->GetTextOut();
			}
		}
		return str;
	}

	void Sort() {
		sort(All.begin(), All.end(), [](Item* a, Item* b) {
			return a->Name > b->Name;
			});
	}
	void Reverse() {
		reverse(All.begin(), All.end());
	}
	void Swap(int a, int b) {
		iter_swap(All.begin() + a - 1, All.begin() + a - 1);
	}
	void Unique() {
		unique(All.begin(), All.end());
	}
	void Add(string Title, double price, int amount) {
		Item* n = new Item(Title, price, amount);
		pair<vector<Item*>::iterator, vector<Item*>::iterator> p = equal_range(All.begin(), All.end(), n);
		All.insert(p.first, n);
		WriteFile();
		ReadFile();
	}
	void Add(string Title, double price, int amount, string producer) {
		Tech* n = new Tech(Title, price, amount, producer);
		pair<vector<Item*>::iterator, vector<Item*>::iterator> p = equal_range(All.begin(), All.end(), n);
		All.insert(p.first, n);
		WriteFile();
		ReadFile();
	}
};