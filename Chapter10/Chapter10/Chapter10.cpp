// Chapter10.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>

class Teacher
{
private:
	std::string m_name;

public:
	Teacher(std::string name)
		: m_name(name)
	{
	}

	std::string getName() { return m_name; }
};

class Department
{
private:
	std::vector<Teacher*> m_teacher;


public:
	Department(Teacher *teacher = nullptr)
	{
		if(teacher!=nullptr)
			m_teacher.push_back(teacher);
	}

	Department& add(Teacher* teacher)
	{
		m_teacher.push_back(teacher);
		return *this;
	}

	friend std::ostream& operator<<(std::ostream &out, Department& dept);
	
};

std::ostream& operator<<(std::ostream &out, Department& dept)
{
	std::cout << "Department: ";
	for (const auto &ref : dept.m_teacher)
	{
		out << ref->getName() << " ";
	}
	std::cout << "\n";
	return out;
}

int main()
{
	// Create a teacher outside the scope of the Department
	Teacher *t1 = new Teacher("Bob"); // create a teacher
	Teacher *t2 = new Teacher("Frank");
	Teacher *t3 = new Teacher("Beth");

	{
		// Create a department and use the constructor parameter to pass
		// the teacher to it.
		Department dept; // create an empty Department
		dept.add(t1);
		dept.add(t2);
		dept.add(t3);

		std::cout << dept;

	} // dept goes out of scope here and is destroyed

	std::cout << t1->getName() << " still exists!\n";
	std::cout << t2->getName() << " still exists!\n";
	std::cout << t3->getName() << " still exists!\n";

	delete t1;
	delete t2;
	delete t3;

	return 0;
}
