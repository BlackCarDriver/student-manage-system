#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef vector<string> res_row;

/*
SqlPackage is an useful tools for c++ project that use mysql database connection.
It package provide some function that use to operate mysql database, thouse thouse
functions you can easily execue sql commant in c++ code.
All code in it package writen by BlackCarDriver. For more detail please visit: https://github.com/BlackCarDriver/student-manage-system
*/
class SqlPackage {
private:
	/*
	note that it class might be used by other class, which call the constructor will be called 
	more than one times. Inorder to all class use a same database connection, we can make MYSAL
	static and use isInit to prevent other class create an new database connect.
	*/
	static MYSQL conn;
	static bool isInit;
	MYSQL_RES	*res_set;
	MYSQL_ROW	row;
	MYSQL_FIELD *field;
	int init();
	string query(string ope, int interval);
	string getTableHead(MYSQL_RES* res, int interval);
public:
	SqlPackage();
	~SqlPackage();
	void testQuery();
	void testExec();
	void testOther();
	res_row queryRow(string ope);
	int exec(string ope);
	string makeSql(string format, vector<string> strVec);
	int insert(string insertSql);
	int login(string id, string password);
	void printTable(string ope, int interval=20);
};

