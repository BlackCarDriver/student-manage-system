class Student : private SqlPackage{
private:
	void printfFunction();
	string id;
public:
	void setId(string id);
	void checkGrade();
	void checkSource();
	void setPassword();
	void addSource();
	void test();
	int run();
};