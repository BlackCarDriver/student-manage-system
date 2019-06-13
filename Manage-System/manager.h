#pragma once
class Manager : private SqlPackage{
private:
	void printfFunction();
	string id;
public:
	void setId(string id);
	void test();
	int run();
	void addAccount();
	void checkStatic();
};