#include <iostream>    
#include <fstream>     //for handling files
#include <sstream>     //for converting string to double
#include <iomanip>     //only to use setw() function
#include <string.h>    //only to use .size() function
//to files just to keep everything aligned.. what a waste of memory
//my OCD, are you happy now..?

using namespace std;

const int num_of_students = 9;
const int num_of_subjects = 5;

class Subject
{
public:
	string name;
	double grade = 0;
	float A_counter = 0, B_p_counter = 0, B_counter = 0, C_p_counter = 0, C_counter = 0, D_p_counter = 0, D_counter = 0, F_counter = 0;
	//the counter should be int, yes, but later we are going to divide it by the num_of_students to get the grade_perventage,
	//so, it needs to be float in order to get a float percentage (or to get a percentage at all)
	//try making it int and see the result if you don't get it yet.
	
	string symbol;     //A, B+, B, ...

	//how many got A, B+ , B , ....
	float  A_percentage = 0, B_p_percentage = 0, B_percentage = 0, C_p_percentage = 0, C_percentage = 0, D_p_percentage = 0, D_percentage = 0, F_percentage = 0;

	string get_symbol()
	{
		if (grade < 60)
		{
			symbol = "F";
		}
		else if (grade < 65 && grade >= 60)
		{
			symbol = "D";
		}
		else if (grade < 70 && grade >= 65)
		{
			symbol = "D+";
		}
		else if (grade < 75 && grade >= 70)
		{
			symbol = "C";
		}
		else if (grade < 80 && grade >= 75)
		{
			symbol = "C+";
		}
		else if (grade < 85 && grade >= 80)
		{
			symbol = "B";
		}
		else if (grade < 90 && grade >= 85)
		{
			symbol = "B+";
		}
		else if (grade >= 90)
		{
			symbol = "A";
		}

		return symbol;
	}
	
};

Subject subjects[num_of_subjects];    //an array of subjects;

class Student
{
public:
	string name;
	string ID;
	int age = 0;
	string gender;
	string GPA;
	string GPA_symbol;

	const int num_of_subjects = 5;

	Subject subjects[5] ;

	double grade = 0;
	double grade_percentage = 0;

	void print_info()
	{
		//printing all student info
		cout << endl;
		cout << "printing student info: " << endl;
		cout << "student name:        " << name << endl;
		cout << "student ID:          " << ID << endl;
		cout << "student age:         " << age << endl;
		cout << "student gender:      " << gender << endl;
		cout << "student GPA:         " << GPA << endl;
		cout << "student GPA symbol:  " << GPA_symbol << endl;
		cout << "student total grade: " << grade << " out of " << (num_of_subjects * 100) << endl;
		cout << "student grade percentage: " << grade_percentage << " %" << endl;
		//printing student grade for each subject.
		cout << endl;
		cout << "Detailed subjects grade for " << name << ":" << endl;

		int width = 0;   //not important.. it's just that I have OCD, which forces me to make everything aligned 
		for (int sub = 0; sub < num_of_subjects; sub++)
		{
			width = subjects[sub].name.size();  //for the same OCD reason.. you can just print the grades. 
			cout << subjects[sub].name << " grade " << setw(23 - (width + 7)) <<" = "<< subjects[sub].grade << endl;
		}
		cout <<"------------------------------"<< endl;
	}

	void print_subjects_grade()  
	{
		cout << endl;
		cout << "printing student's subjects grade: " << endl;
		int width = 0;
		for (int sub = 0; sub < num_of_subjects; sub++)
		{
			width = subjects[sub].name.size();
			cout << subjects[sub].name << " grade " << setw(23 - (width + 7)) << " = " << subjects[sub].grade << endl;
		}
		cout << endl;
	}
	
	void print_subjects_name() 
	{
		cout << endl;
		cout << "printing student's subjects name: " << endl;
		for (int sub = 0; sub < num_of_subjects; sub++)
		{
			cout << endl<< subjects[sub].name << endl;
		}
		cout << endl;
	}
};

Student students[num_of_students];	//an array of students

//function to calculate the grade symbol of the student, given his grade percentage.
string calc_symbol(double grade_percentage)
{
	string symbol;

	if (grade_percentage < 60)
	{
		symbol = "F";
	}
	else if (grade_percentage < 65 && grade_percentage >= 60)
	{
		symbol = "D";
	}
	else if (grade_percentage < 70 && grade_percentage >= 65)
	{
		symbol = "D+";
	}
	else if (grade_percentage < 75 && grade_percentage >= 70)
	{
		symbol = "C";
	}
	else if (grade_percentage < 80 && grade_percentage >= 75)
	{
		symbol = "C+";
	}
	else if (grade_percentage < 85 && grade_percentage >= 80)
	{
		symbol = "B";
	}
	else if (grade_percentage < 90 && grade_percentage >= 85)
	{
		symbol = "B+";
	}
	else if (grade_percentage >= 90)
	{
		symbol = "A";
	}

	return symbol;
}

//function to calculate the GPA of the student, given his grade percentage.
string calc_GPA(double grade_percentage)
{
	string GPA;

	if (grade_percentage < 60)
	{
		GPA = "0.0";
	}
	else if (grade_percentage < 64 && grade_percentage >= 60)
	{
		GPA = "1.0";
	}
	else if (grade_percentage < 67 && grade_percentage >= 64)
	{
		GPA = "1.3";
	}
	else if (grade_percentage < 70 && grade_percentage >= 67)
	{
		GPA = "1.7";
	}
	else if (grade_percentage < 73 && grade_percentage >= 70)
	{
		GPA = "2.0";
	}
	else if (grade_percentage < 76 && grade_percentage >= 73)
	{
		GPA = "2.3";
	}
	else if (grade_percentage < 80 && grade_percentage >= 76)
	{
		GPA = "2.7";
	}
	else if (grade_percentage < 84 && grade_percentage >= 80)
	{
		GPA = "3.0";
	}
	else if (grade_percentage < 89 && grade_percentage >= 84)
	{
		GPA = "3.3";
	}
	else if (grade_percentage < 93 && grade_percentage >= 89)
	{
		GPA = "3.7";
	}
	else if (grade_percentage >= 93)
	{
		GPA = "4.0";
	}
	return GPA;
}

void export_students_data(Student students[])
{
	string file_name;
	cout << endl << "please enter a new \"fileName.csv\" to create and export data to :" << endl;
	cin >> file_name;
	ofstream file;
	file.open(file_name);

	if (file.is_open())
	{

		file << "Code" << ',' << "Name" << ',' << "Age" << ',' << "Gender" << ',' << "grade" << ',' << "GPA" << ',' << "GPA symbol" << endl;

		for (int st = 0; st < num_of_students; st++)
		{
			file << students[st].ID << ',' << students[st].name << ',' << students[st].age << ',' << students[st].gender << ',' << students[st].grade << ',' << students[st].GPA << ',' << students[st].GPA_symbol << endl;
		}
	}
	file.close();
	cout << endl;
	cout << "Data exported successfully to " << file_name << " in the same folder of this project's folder" << endl;

}

void export_students_grade(Student students[], int num_of_students, Subject subjects[] , int num_of_subjects)
{
	string file_name;
	cout << endl << "please enter a new \"fileName.csv\" to create and export data to :" << endl;
	cin >> file_name;
	ofstream file;
	file.open(file_name);

	if (file.is_open())
	{

		file << "Code" << ',';

		for (int sub = 0; sub < num_of_subjects; sub++)
			file << students[1].subjects[sub].name << ',';

		file << endl;

		for (int st = 0; st < num_of_students; st++)
		{
			file << students[st].ID << ',';       //parse the Student ID at the first column
			//then parse all the subjects grade
			for (int sub = 0; sub < num_of_subjects; sub++)
			{
				file << students[st].subjects[sub].grade << ',';
			}
			file << endl;         //then move to the next line
		}
	}
	file.close();
	cout << endl;
	cout << "Grades exported successfully to " << file_name << " in the same folder of this project's folder" << endl;

}

void export_students_grade_symbols(Student students[], int num_of_students, Subject subjects[], int num_of_subjects)
{
	string file_name;
	cout << endl << "please enter a new \"fileName.csv\" to create and export data to :" << endl;
	cin >> file_name;
	ofstream file;
	file.open(file_name);

	if (file.is_open())
	{

		file << "Code" << ',';

		for (int sub = 0; sub < num_of_subjects; sub++)
			file << students[1].subjects[sub].name << ',';

		file << endl;

		for (int st = 0; st < num_of_students; st++)
		{
			file << students[st].ID << ',';       //parse the Student ID at the first column
			//then parse all the subjects grade
			for (int sub = 0; sub < num_of_subjects; sub++)
			{
				students[st].subjects[sub].symbol = students[st].subjects[sub].get_symbol();
				file << students[st].subjects[sub].symbol << ',';
			}
			file << endl;         //then move to the next line
		}
	}
	file.close();
	cout << endl;
	cout << "Grades exported successfully to " << file_name << " in the same folder of this project's folder" << endl;

}

void export_GPAs(Student students[])
{
	string file_name;
	cout << endl << "please enter a new \"fileName.csv\" to create and export data to :" << endl;
	cin >> file_name;
	ofstream file;
	file.open(file_name);

	if (file.is_open())
	{

		file << "Code" << ',' << "Name" << ',' << "Age" << ',' << "Gender" << ',' << "Grade" << ',' << "GPA" << ',' << "GPA symbol" << endl;

		for (int st = 0; st < num_of_students; st++)   //started with 1 because line zero is the labeling line
		{
			file << students[st].ID << ',' << students[st].name << ',' << students[st].age << ',' << students[st].gender << ',' << students[st].grade << ',' << students[st].GPA << ',' << students[st].GPA_symbol << endl;
		}
	}
	file.close();
	cout << endl;
	cout << "GPAs exported successfully to " << file_name << " in the same folder of this project's folder" << endl;
	cout << endl;
}

//this function allows the user to choose which data would he likes to export.
void export_data(Student students[])
{
	cout << endl
		<< "please select:" << endl
		<< "1 to export students Data  " << endl
		<< "2 to export students grades" << endl
		<< "3 to export students grade symbols" << endl
		<< "4 to export students GPAs  " << endl;

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		export_students_data(students);
		break;
	case 2:
		export_students_grade(students, num_of_students, subjects, num_of_subjects);
		break;
	case 3:
		export_students_grade_symbols(students, num_of_students, subjects, num_of_subjects);
		break;
	case 4:
		export_GPAs(students);
		break;
	default:
		cout << endl << "invalid input!" << endl;
		break;
	}
}

void display_student_data(Student students[], int sz)
{
	string ID;
	cout << endl << "please enter the ID of the student: " << endl;
	cin >> ID;
	bool found = false;
	int index;
	for (int i = 0; i < num_of_students; i++)
	{
		if (students[i].ID == ID)
		{
			found = true;
			index = i;
		}
	}
	if (found == true)
	{
		cout << endl << "student found" << endl;
		students[index].print_info();
	}
	else
	{
		cout << endl << "student with ID: " << ID << " was not found" << endl;
	}
}

void display_all_students_data(Student students[], int sz)
{
	cout << endl << "printing all students data:" << endl;
	for (int i = 0; i < sz; i++)
	{
		//if (i == 0) continue;   //this is the labling line in the CSV file
		students[i].print_info();
	}
	cout << endl;
}

//this function shows how many students got each GPA, (i.e 20% got A, 30% got B+, ...)
void get_statistics(Student students[], int num_of_student, Subject subjects[], int num_of_subjects)
{
	for (int sub = 0; sub < num_of_subjects; sub++)
	{
		for (int st = 0; st < num_of_student; st++)
		{
			if (students[st].subjects[sub].get_symbol() == "F")
				subjects[sub].F_counter++;

			if (students[st].subjects[sub].get_symbol() == "D")
				subjects[sub].D_counter++;

			if (students[st].subjects[sub].get_symbol() == "D+")
				subjects[sub].D_p_counter++;

			if (students[st].subjects[sub].get_symbol() == "C")
				subjects[sub].C_counter++;

			if (students[st].subjects[sub].get_symbol() == "C+")
				subjects[sub].C_p_counter++;

			if (students[st].subjects[sub].get_symbol() == "B")
				subjects[sub].B_counter++;

			if (students[st].subjects[sub].get_symbol() == "B+")
				subjects[sub].B_p_counter++;

			if (students[st].subjects[sub].get_symbol() == "A")
				subjects[sub].A_counter++;
		}

		subjects[sub].A_percentage = subjects[sub].A_counter / num_of_students;
		subjects[sub].B_percentage = subjects[sub].B_counter / num_of_students;
		subjects[sub].B_p_percentage = subjects[sub].B_p_counter / num_of_students;
		subjects[sub].C_percentage = subjects[sub].C_counter / num_of_students;
		subjects[sub].C_p_percentage = subjects[sub].C_p_counter / num_of_students;
		subjects[sub].D_percentage = subjects[sub].D_counter / num_of_students;
		subjects[sub].D_p_percentage = subjects[sub].D_p_counter / num_of_students;
		subjects[sub].F_percentage = subjects[sub].F_counter / num_of_students;

		cout << endl;
		cout << "for subject: " << students[1].subjects[sub].name << endl;               //student[1] can be replaced with any student
		cout << subjects[sub].A_percentage   *100  << " % of students got A " << endl;
		cout << subjects[sub].B_p_percentage * 100 << " % of students got B+" << endl;
		cout << subjects[sub].B_percentage   * 100 << " % of students got B " << endl;
		cout << subjects[sub].C_p_percentage * 100 << " % of students got C+" << endl;
		cout << subjects[sub].C_percentage   * 100 << " % of students got C " << endl;
		cout << subjects[sub].D_p_percentage * 100 << " % of students got D+" << endl;
		cout << subjects[sub].D_percentage   * 100 << " % of students got D " << endl;
		cout << subjects[sub].F_percentage   * 100 << " % of students got F " << endl;
		cout << endl;
	}
}

void import_students_grades()
{
	string file_name;
	cout << endl << "please enter \"fileName.csv\" (case sensitive, and make sure it's in the code folder):" << endl;
	cin >> file_name;
	ifstream file;
	file.open(file_name);
	if (file.is_open())
	{
		string ID;
		string subs_string_grade[num_of_subjects];			  //grades imported as string
		string temp;  //to store useless data
		getline(file, temp, ',');    //the first cell value is "code" which is useless here, so ,store it in a temp, then neglect it.


		string subjects_name[num_of_subjects];   //store subjects names to a string array, then assign it to students subject name

		for (int sub = 0; sub < num_of_subjects-1; sub++)
		{
			getline(file, subjects_name[sub], ',');
		}
		getline(file, subjects_name[num_of_subjects-1], '\n');

		int st = 0; //a counter to loop over all students and name their subjects.
		for (int st = 0  ; st < num_of_students ; st++)
		{
			for (int sub = 0 ; sub < num_of_subjects ; sub++)
				students[st].subjects[sub].name = subjects_name[sub];
		}
	//	getline(file, students[st].subjects[num_of_subjects - 1].name, '\n');   // the last subject is the last item on the line
	//	cout << endl << "imported subject name is: " << students[st].subjects[num_of_subjects - 1].name << endl;

		int i = 0;  //just a counter to loop over all students;
		while (file.good())
		{
			//students[i].print_subjects_name();   //I was just testing the import function if it imports the subjects name correctly
			//get the data from the CSV file
			//note that getline takes the data as a string, we'll convert it to int/double later.

			getline(file, ID, ',');   //the item in the first column is the ID
			students[i].ID = ID;

			//then take the grades (as a string) and store it (temporary) in the subs array ;
			for (int sub = 0; sub < num_of_subjects - 1; sub++)
			{
				getline(file, subs_string_grade[sub], ',');
			}
			getline(file, subs_string_grade[num_of_subjects - 1], '\n');

			//to convert string to double or double:
			for (int sub = 0; sub < num_of_subjects; sub++)      //loop over all subjects
			{
				stringstream conveted(subs_string_grade[sub]);  //temporary variable to store the converted grade (from string to double), then assign it to the students subject grade.
				conveted >> students[i].subjects[sub].grade;
				students[i].grade += students[i].subjects[sub].grade;        //make the best use of the loop, and calculate the total grade of each student (= sum of subjects grade)
			}

			//calculate student total grade. (according to the grades of all the subjects.
			students[i].grade_percentage = (students[i].grade / students[i].num_of_subjects);

			//calculate GPA symbol (A, B+, B, C, ...)
			students[i].GPA_symbol = calc_symbol(students[i].grade_percentage);

			students[i].GPA = calc_GPA(students[i].grade_percentage);
			i++;  //move on to the next student
		}
	}
	cout << endl << "students grades imported successfully" << endl;
	file.close();
}

void import_students_data()
{
	string file_name;
	cout << endl << "please enter \"fileName.csv\" (case sensitive, and make sure it's in the code folder):" << endl;
	cin >> file_name;
	ifstream file;
	file.open(file_name);    

	if (file.is_open())
	{
		string ID;
		string name;
		string age;
		string gender;
		string lables;   //temporary variable to stores the labels (may be needed later)

		//the data in the first line is just for labeling, so, no need to keep it
		//so, store it in a temporary variable, then neglect it
		getline(file, lables, '\n');

		int i = 0;
		while (file.good()) {

			getline(file, ID, ',');
			getline(file, name, ',');
			getline(file, age, ',');
			getline(file, gender, '\n');

			//to convert string to double or int:
			stringstream int_age(age);    //age as integer
			students[i].ID = ID;
			students[i].name = name;
			int_age >> students[i].age;
			students[i].gender = gender;
			i++;
		}
	}
	cout << endl << "students data imported successfully" << endl;
	file.close();
}

//this function allows the user to choose which data would he likes to import.
void import_data()
{
	cout << endl
		<< "please select:" << endl
		<< "1 to import students Data  " << endl
		<< "2 to import students grades" << endl;

	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		import_students_data();
		break;
	case 2:
		import_students_grades();
		break;
	default:
		cout << endl << "invalid input!" << endl;
		break;
	}
}

//let the user choose what to do (for the main menu)
int get_what_user_wants()
{
	cout << endl << endl << "Please enter: " << endl <<
		"1 to import data" << endl <<
		"2 to export data" << endl <<
		"3 to display student info" << endl <<
		"4 to display all students data" << endl <<
		"5 to display statistics" << endl <<
		"6 to quit" << endl << endl;
	int choice;
	cin >> choice;
	return choice;
}

//execute what the user wants
int main_menu()
{
	int choice = get_what_user_wants();
	if (choice == 6)
		return 0;
	else
	{
		switch (choice)
		{
		case 1:
			import_data();
			break;
		case 2:
			export_data(students);
			break;
		case 3:
			display_student_data(students, num_of_students);
			break;
		case 4:
			display_all_students_data(students, num_of_students);
			break;
		case 5:
			get_statistics(students, num_of_students, subjects, num_of_subjects);
			break;
		case 6:
			return 0;
		default:
			cout << endl << "invalid input!";
			get_what_user_wants();
			break;
		}
	}
	main_menu();
}

int main()
{
	main_menu();
}
