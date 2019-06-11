#include<string>
#include<iostream>
using namespace std;

class SqlPackage {
private:
	MYSQL conn;
	MYSQL_RES *res_set;
	MYSQL_ROW row;
	int init();
public:
	SqlPackage();
	~SqlPackage();
	void test();
	int login(string id, string password);
};