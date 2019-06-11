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
};