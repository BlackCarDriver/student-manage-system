#include<iostream>
#include<string>
#include<vector>
using namespace std;

typedef vector<string> res_row;

class SqlPackage {
private:
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

