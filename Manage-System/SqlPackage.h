#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef vector<string> res_row;

class SqlPackage {
private:
	MYSQL		conn;
	MYSQL_RES	*res_set;
	MYSQL_ROW	row;
	MYSQL_FIELD *field;
	int init();
	string getTableHead(MYSQL_RES* res, int interval);
	string query(string ope, int interval);
	res_row queryRow(string ope);
	int exec(string ope);
	string makeSql(string format, vector<string> strVec);
public:
	SqlPackage();
	~SqlPackage();
	void testQuery();
	void testExec();
	void testOther();
	int addNewAccount(string id, string name, string type);
	int login(string id, string password);
};