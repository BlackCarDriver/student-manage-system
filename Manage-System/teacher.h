class Teacher : private SqlPackage {
private:
	void printfFunction();
	string id;
public:
	void setId(string id);
	void checkStudent();
	void checkSource();
	void setGrade();
	void test();
	int run();
};