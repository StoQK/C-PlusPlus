#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // A header for the input validation function transform and toupper

using namespace std;

class Course // Declaration of the class Course
{
public:						// declaration of the public data members
	string Name; 
	string Code;
	int credits;

	Course(string name, string code, int cr) // Constructor
	{
		this->Name = name;	// A pointer to the current instance of the class data member name
		this->Code = code;
		this->credits = cr;
	}
};

class AubgAcademicProgramme // Declaration of the class AubgAcademicProgramme
{
public:
	string language;
	string accreditation;

	virtual void ShowDescription() // Polymorphic function output
	{
		cout << "All programs are taught in: " << language << endl;
		cout << "Accreditation: " << accreditation << endl;
	}

	virtual void DefineDescription(string lang, string accr) // Polymorphic function input
	{
		this->language = lang;
		this->accreditation = accr;
	}
};

class Bachelor : public AubgAcademicProgramme // Declaration of class Bachelor, which inherits all the public data members from AubgAcademicProgramme
{
public:
	string admission;
	int yearsOfStudy;

	void ShowDescription() // Polymorhpic function
	{
		AubgAcademicProgramme::ShowDescription(); // Inheritance of the polymorphic function output from AubgAcademicProgramme

		cout <<"Basic requirements for an admission: " << admission << endl;
		cout <<"Years of study: " << yearsOfStudy << endl << endl;
	}

	void DefineDescription(string lang, string accr, string adm, int yrsOfStudy)
	{
		AubgAcademicProgramme::DefineDescription(lang, accr); // Inheritance of the polymorphic function input from AubgAcademicProgramme

		this->admission = adm;
		this->yearsOfStudy = yrsOfStudy;
	}
};

//class MastersProgramm : public AubgAcademicProgramme        Can include some major programmes as well
//{
//public:
//	string admissionMaster;
//	string requirementsMaster;
//
//	void ShowDescription()
//	{
//		AubgAcademicProgramme::ShowDescription();
//
//		cout << "Admission for a master program: " << admissionMaster << endl;
//		cout << "Requirements for the completion of a master program: " << requirementsMaster << endl;
//	}
//
//	virtual void DefineDescription(string lang, string accr, string admMaster, string reqMaster)
//	{
//		AubgAcademicProgramme::DefineDescription(lang, accr);
//
//		this->admissionMaster = admMaster;
//		this->requirementsMaster = reqMaster;
//	}
//};

class Speciality : public Bachelor // Declaration of the Speciality class, where will declare major and minor programs
{
public:
	string Name;
	vector<Course> RequiredCourses; // A vector used to save all the required courses for a major/minor
	vector<Course> ElectiveCourses; // A vector used to save all the elective courses for a major/minor
	string Code;
	string major_minor;
	double gpa;
	int totalCourses;

	void ShowDescription()
	{
		Bachelor::ShowDescription();
		cout << Name << endl << endl;
		cout << "Description for a: " << major_minor << endl << endl;
		cout << "Required Courses:" << endl;
		for (int i = 0; i < RequiredCourses.size(); i++) // A for loop for outputing the values in the required courses vector
		{
			cout << RequiredCourses[i].Code<< " ";
			cout << RequiredCourses[i].Name << ", ";
			cout << "Credits: " << RequiredCourses[i].credits<< endl;
		}
		cout << endl;

		cout << "Elective Courses:" << endl;
		for (int i = 0; i < ElectiveCourses.size(); i++)
		{
			cout << ElectiveCourses[i].Code<< " ";
			cout << ElectiveCourses[i].Name << endl;
			
		}

		cout << "Code: " << Code << endl;
		cout << "Minimum required GPA for graduation: " << gpa << endl;
		cout << "Total courses required: " << totalCourses << endl << endl << endl;
		
		
	}

	void DefineDescription(string lang, string accr, string adm, int yrsOfStudy, vector<Course> ReqCourses,
		vector<Course> ElecCourses, string code, double gpa, int totalCourses)
	{
		Bachelor::DefineDescription(lang, accr, adm, yrsOfStudy);

		this->RequiredCourses = ReqCourses; // 
		this->ElectiveCourses = ElecCourses;
		this->Code = code;
		this->gpa = gpa;
		this->totalCourses = totalCourses;
	}

};

vector<Speciality*> GenerateBachelors() // Declaration of a vector function with pointer to the class Speciality that will contain all the bachelor major/minors
{
	vector<Speciality*> bachelors; // A vector bachelors pointing to class Speciality containing all the majors/minors

	Speciality* cosMajor =  new Speciality(); // Declaration of an object pointing to the class Speciality
	cosMajor->Name = "COMPUTER SCIENCE"; // A pointer to the data member name from the class Speciality
	cosMajor->accreditation = "EU & US Diploma";
	cosMajor->admission = "High School Diploma, TOEFL & SAT";
	cosMajor->Code = "COS";
	cosMajor->RequiredCourses.push_back(Course("Software Development using C++", "COS 120", 3)); // A declaration for vector required courses pointing to the class Course and initializing the constructor's values
	cosMajor->RequiredCourses.push_back(Course("Discrete structures", "COS 150", 3));
	cosMajor->RequiredCourses.push_back(Course("Data Structures", "COS 221", 3));
	cosMajor->RequiredCourses.push_back(Course("Computer Architecture", "COS 235", 3));
	cosMajor->RequiredCourses.push_back(Course("Object-Oriented Programming", "COS 240", 3));
	cosMajor->RequiredCourses.push_back(Course("Software Engineering", "COS 315", 3));
	cosMajor->RequiredCourses.push_back(Course("Senior Project I", "COS 491", 3));

	cosMajor->ElectiveCourses.push_back(Course("Concepts of Programming Languages", "COS 220", 3));
	cosMajor->ElectiveCourses.push_back(Course("Assembly Language", "COS 260", 3));
	cosMajor->ElectiveCourses.push_back(Course("Compiler Theory", "COS 301", 3));
	cosMajor->ElectiveCourses.push_back(Course("Operating Systems", "COS 331", 3));
	cosMajor->ElectiveCourses.push_back(Course("Computer Networks", "COS 440", 3));
	cosMajor->ElectiveCourses.push_back(Course("Algorithms", "COS 460", 3));
	cosMajor->ElectiveCourses.push_back(Course("Internship", "COS 481", 3));

	cosMajor->language = "English"; // A pointer to the data member language from the class AubgAcademicProgramme
	cosMajor->totalCourses = 12; // A pointer to the data member totalCourses from the class Speciality
	cosMajor->major_minor = "Major";
	cosMajor->yearsOfStudy = 4; // A pointer to the data member yearsOfStudy from the class Bachelor
	cosMajor->gpa = 2.5;

	bachelors.push_back(cosMajor); // Adding all the information into the vector bachelors



	Speciality* busMajor =  new Speciality();		// Declaration of a second major
	busMajor->Name = "BUSINESS ADMINISTRATION";
	busMajor->accreditation = "EU & US Diploma";
	busMajor->admission = "High School Diploma, TOEFL & SAT";
	busMajor->Code = "BUS";
	
	busMajor->RequiredCourses.push_back(Course("Business Law", "BUS 200", 3));
	busMajor->RequiredCourses.push_back(Course("Introductory Accounting I", "BUS 220", 3));
	busMajor->RequiredCourses.push_back(Course("Introductory Accounting II", "BUS 221", 3));
	busMajor->RequiredCourses.push_back(Course("Marketing", "BUS 260", 3));
	busMajor->RequiredCourses.push_back(Course("Management Information Systems", "BUS 201", 3));
	busMajor->RequiredCourses.push_back(Course("Corporate Finance I", "BUS 330", 3));
	busMajor->RequiredCourses.push_back(Course("Organizational Theory and Behavior", "BUS 340", 3));
	busMajor->RequiredCourses.push_back(Course("Business Ethics", "BUS 448", 4));

	busMajor->ElectiveCourses.push_back(Course("Corporate Finance I", "BUS 333", 3));
	busMajor->ElectiveCourses.push_back(Course("Cross-Cultural Management", "SES 360", 3));

	busMajor->language = "English";
	busMajor->totalCourses = 12;
	busMajor->major_minor = "Major";
	busMajor->yearsOfStudy = 4;
	busMajor->gpa = 2.5;
	 
	bachelors.push_back(busMajor);



	Speciality* ecoMajor =  new Speciality();		
	ecoMajor->Name = "ECONOMICS";
	ecoMajor->accreditation = "EU & US Diploma";
	ecoMajor->admission = "High School Diploma, TOEFL & SAT";
	ecoMajor->Code = "ECO";

	ecoMajor->RequiredCourses.push_back(Course("Principles of Microeconomics", "ECO 101", 3));
	ecoMajor->RequiredCourses.push_back(Course("Principles of Macroeconomics", "ECO 102", 3));
	ecoMajor->RequiredCourses.push_back(Course("Quantitative Methods in Economics", "ECO 300", 3));
	ecoMajor->RequiredCourses.push_back(Course("Intermediate Microeconomics", "ECO 301", 3));
	ecoMajor->RequiredCourses.push_back(Course("Intermediate Macroeconomics", "ECO 302", 3));
	ecoMajor->RequiredCourses.push_back(Course("Econometrics", "ECO 310", 4));

	ecoMajor->ElectiveCourses.push_back(Course("Money and Banking", "ECO 220", 3));
	ecoMajor->ElectiveCourses.push_back(Course("International Finance", "ECO 225", 3));
	ecoMajor->ElectiveCourses.push_back(Course("Financial Markets", "ECO 240", 3));
	ecoMajor->ElectiveCourses.push_back(Course("Topics in Econometrics", "ECO 400", 3));
	ecoMajor->ElectiveCourses.push_back(Course("Topics in Advanced Microeconomics", "ECO 401", 3));
	ecoMajor->ElectiveCourses.push_back(Course("Topics in Advanced Macroeconomics", "ECO 402", 3));
	ecoMajor->ElectiveCourses.push_back(Course("Advanced Topics", "ECO 404", 3));

	ecoMajor->totalCourses = 6;
	ecoMajor->language = "English";
	ecoMajor->major_minor = "Major";
	ecoMajor->yearsOfStudy = 4;
	ecoMajor->gpa = 2.5;
	bachelors.push_back(ecoMajor);


	Speciality* cosMinor =  new Speciality(); // Declaration for a minor 
	cosMinor->Name = "COMPUTER SCIENCE";
	cosMinor->accreditation = "EU & US Diploma";
	cosMinor->admission = "High School Diploma, TOEFL & SAT";
	cosMinor->Code = "COS";
	cosMinor->RequiredCourses.push_back(Course("Software Development using C++", "COS 120", 3));
	cosMinor->RequiredCourses.push_back(Course("Discrete structures", "COS 150", 3));
	cosMinor->RequiredCourses.push_back(Course("Data Structures", "COS 221", 3));

	cosMinor->ElectiveCourses.push_back(Course("Concepts of Programming Languages", "COS 220", 3));
	cosMinor->ElectiveCourses.push_back(Course("Algorithms", "COS 460", 3));

	cosMinor->language = "English";
	cosMinor->major_minor = "Minor";
	cosMinor->yearsOfStudy = 2;
	cosMinor->gpa = 2.5;
	cosMinor->totalCourses = 6;
	bachelors.push_back(cosMinor);

	Speciality* infMinor =  new Speciality();
	infMinor->Name = "INFORMATION SYSTEMS";
	infMinor->accreditation = "EU & US Diploma";
	infMinor->admission = "High School Diploma, TOEFL & SAT";
	infMinor->Code = "INF";
	infMinor->RequiredCourses.push_back(Course("Visual Basic Programming", "INF 110", 3));
	infMinor->RequiredCourses.push_back(Course("Principles of Information Systems", "INF 270", 3));
	infMinor->RequiredCourses.push_back(Course("Database Systems", "INF 280", 3));

	infMinor->ElectiveCourses.push_back(Course("Personal Productivity with Information Technologies", "INF 150", 3));
	infMinor->ElectiveCourses.push_back(Course("Web Design", "INF 240", 3));
	infMinor->ElectiveCourses.push_back(Course("Web Client Technologies", "INF 275", 3));
	infMinor->ElectiveCourses.push_back(Course("Information Security", "INF 370", 3));

	infMinor->language = "English";
	infMinor->major_minor = "Minor";
	infMinor->yearsOfStudy = 2;
	infMinor->gpa = 2.5;
	infMinor->totalCourses = 6;
	bachelors.push_back(infMinor);


	return bachelors; // returning all the information from the GenerateBachelors function
}

//vector<MastersProgramm*> GenerateMasters()
//{
//	vector<MastersProgramm*> masters;
//
//	return masters;
//}

vector<Speciality*> insertionSortMajorOrMinor(vector<Speciality*> collection) // Insertion sort that will check if a speciality is a major or a minor and will return the result of the comparison 
 {
    int i, j;
	Speciality* tmp;
	long int counter=0; 
	for (i = 1; i < collection.size(); i++) // For loop that goes through the whole collection that will be compared
	{
        j = i;
		while (j > 0 && collection[j - 1]->major_minor > collection[j]->major_minor) 	// A while loop that sorts the results by checking the value of the string major_minor
		{	
            tmp = collection[j];
            collection[j] = collection[j - 1]; // If the current value is "bigger" than the previous, the previous value become current 
            collection[j - 1] = tmp;
            j--;
			counter++; 
        }	
    }
	return collection;
}

vector<Speciality*> filterByCode(vector<Speciality*> collection, string filterCode) // Declaration of the filterByCode function. My favorite function of the program that returns the information for a speciality by entering its code
{
	vector<Speciality*> results;
	for (int i = 0; i < collection.size(); i++)
	{
		if (collection[i]->Code == filterCode) // A pointer to the code data member from the Speciality class that is compared with the user input
		{
			results.push_back(collection[i]);
		}
	}

	return results;
}

void main()
{
	vector<Speciality*> bachelors;
//	vector<MastersProgramm*> masters;

	bachelors = GenerateBachelors();
//	masters = GenerateMasters();

	int choice;
	vector<Speciality*> results; // A vector that will contain all the results from the sorting
	
	bool exit = false;
	while (true) // An infinite loop that will prompt for a user input, until case 4 is selected
	{
		cout << "Please choose an option:" << endl;
		cout << "1. List of all majors with their description"<< endl;
		cout << "2. List of majors sorted by their code" << endl;
		cout << "3. List of courses sorted by a major or minor program" << endl;
		cout << "4. Exit (Search by entering course code)" << endl;
		cin >> choice;
		
		cout << endl;
		switch (choice)
		{
		case 1:
			for (int i = 0; i < bachelors.size(); i++) // for loop that goes through all the members in the vector bachelors
			{
				bachelors[i]->ShowDescription(); // A pointer to the virtual function ShowDescription() that will output all the information
			}
			cout << endl << endl;
			
			break;
		case 2:
			cout << endl << endl;
			results = filterByCode(bachelors, "INF"); // A call of the filterByCode function with parameters the vector bachelors and a filterCode "INF"

			for (int i = 0; i < results.size(); i++)
			{
				results[i]->ShowDescription(); // A pointer to the virtual function 
			}
			
			cout << endl << endl;
			break;
		case 3:
			cout << endl<<endl;
			results = insertionSortMajorOrMinor(bachelors); // A call of the insertionSortMajorOrMinor that will sort and list all courses compared to the string major_minor

			for (int i = 0; i < results.size(); i++)
			{
				results[i]->ShowDescription();
			}

			cout << endl << endl;
			break;
		case 4:
			exit = true; // If 4 is selected, set the flag exit to true
			break;
			
		default:
			
			break;
			
			
		}
		if (exit)
			{
				break; // If exit == true, break the infinite while loop
			}
	}

	while (true)
	{
		

		cout << "Please enter course code you would like to get information for: (X for exit)" << endl;

		string input = " ";
		getline(cin, input);
		
		transform(input.begin(), input.end(), input.begin(), toupper); // Input validation function that converts the string input toupper for any string entered

		if (input == "X")
		{
			break; // Breaks the loop and closes the program
		}
		else
		{

			results = filterByCode(bachelors, input); // returns the result of the sorting by code that the user has inputed

			for (int i = 0; i < results.size(); i++) // Goes through the whole vector results
			{
				results[i]->ShowDescription(); // a pointer to the virtual function ShowDescription() for every member of the vector
			}
		}
	} 
}


