#include<string>
#include<iostream>
#include<vector>

using namespace std;

class SqlPackage {
private:
	MYSQL		conn;				
	MYSQL_RES	*res_set;		
	MYSQL_ROW	row;	
	MYSQL_FIELD *field;
	int init(); 
	string getTableHead(MYSQL_RES* res, int interval);
	string query(string ope, int interval);
	int exec(string ope); 
	string makeSql(string format, vector<string> strVec);
public:
	SqlPackage();
	~SqlPackage();
	void testQuery();
	void testExec();
	void testOther();
	int login(string id, string password);
};

