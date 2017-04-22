#include <iostream>
#include <string>
using namespace std;

struct Professor{
	string name;
	string course_name;
	string textbook;
};

struct Student{
	string name;
	int age;
	double weight;
	string couses[10];
	int course_size;
	bool is_female;
	Professor best_professor;

};

int Create_Student(Student&);
void Display_Student(const Student);


int main() {
	Student classroom[35];
	int class_size = 0, sentinel = 0;
	do{
		if (class_size != 0)
			cin.ignore();
		sentinel = Create_Student(classroom[class_size]);
		class_size++;
	} while (sentinel != -1);

	for (int i = 0; i < class_size; ++i){
		cout << "Student #" << i + 1 << " is ";
		Display_Student(classroom[i]);
		cout << endl << endl;
	}

	system("pause");
	return 0;
}

int Create_Student(Student& cur_student){
	char female_check;
	int sentinel;

	cout << "\nPlease enter your name: ";
	
	getline(cin,cur_student.name);

	cout << "\nPlease enter your age: ";
	cin >> cur_student.age;

	cout << "\nPlease enter your weight: ";
	cin >> cur_student.weight;

	do{
		cout << "\nAre you female?(Y/N)";
		cin >> female_check;
		female_check = toupper(female_check);
	} while (female_check != 'N' && female_check != 'Y');
	if (female_check == 'N')
		cur_student.is_female = false;
	else
		cur_student.is_female = true;

	cur_student.course_size = 0;
	for (int i = 0, q = 0; i != -1; q++){
		cout << "\nPlease enter course #" << q + 1 << ": ";
		cin.ignore();
		getline(cin, cur_student.couses[q]);
		cur_student.course_size++;
		cout << "\nType \"-1\" when you have finished adding all your courses. Otherwise, press any other keys +enter to continue";
		cin >> i;
	}
	cout << "\nWhat is your favorite professors name?";
	cin.ignore();	
	getline(cin, cur_student.best_professor.name);

	cout << "\nWhat is your favorite professors course that s/he is teaching?";
	getline(cin, cur_student.best_professor.course_name);

	cout << "\nWhat is your favorite professors textbook name that he is using?";
	getline(cin, cur_student.best_professor.textbook);

	cout << "\nType \"-1\" when you have finished adding all your students. Otherwise, press any other number + enter to continue";
	cin >> sentinel;

	return sentinel;
}

void Display_Student(const Student cur_student) {
	cout << "Name: " << cur_student.name;
	cout << "\nAge: " << cur_student.age;
	cout << "\nWeight: " << cur_student.weight;
	cout << "\nFemale?(1=y,0=n): " << cur_student.is_female;
	for (int i = 0; i < cur_student.course_size; i++)
	{
		cout << "\nCourse #" << i + 1 << ": " << cur_student.couses[i];
	}
	cout << "\nBest Professors Name: " << cur_student.best_professor.name;
	cout << "\nBest Professors course name: " << cur_student.best_professor.course_name;
	cout << "\nBest Professors textbook name: " << cur_student.best_professor.textbook;
}






