#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

class AubgAcademicProgramme
{
private:
	string language;
	string accreditation;
	string typeOfEducation;

public:
	int choice;
	
	virtual void input()
	{
		cout<<"Please choose a desired degree. Enter 1 for a Bachelor Degree or 2 for a Master's Degree: \n";
		cin >> choice;
	}
	virtual void output()
	{
		cout<<language;
		cout<<accreditation;
		cout<<typeOfEducation;
	}
};

class BachelorDegree: public AubgAcademicProgramme
{
private:
	string admission;
	string degreeRequirements;
	int yearsOfStudy;
	string foundationCourses;

public:
	int program;

	virtual void input()
	{
		AubgAcademicProgramme::input();
		cout<<"Please select 1 if you are interested in a major program or 2 if interested in a minor program: \n";
		cin>>program;
	}
	virtual void output()
	{
		AubgAcademicProgramme::output();
		cout<<admission;
		cout<<degreeRequirements;
		cout<<foundationCourses;
	}
};

class MasterDegree: public AubgAcademicProgramme
{
	

public:
	string admissionMaster;
	string requirementsMaster;

	virtual void output()
	{
		AubgAcademicProgramme::output();
		cout<<"Currently we are offering a MBA program \n";
		cout<<admissionMaster;
		cout<<requirementsMaster;
	}
};

class Speciality: public BachelorDegree
{
private:
	string majorType;
	int requiredCourses;
	int electiveCourses;
	int requiredCredits;
	string name;
	string code;


public:
	int majorSelected;

	virtual void input()
	{
		BachelorDegree::input();
		cout<<"Please select one of the listed majors: \n";
		cin>>majorSelected;
	}

	virtual void output()
	{
		BachelorDegree::output();
		cout<<"You have selected "<<majorType<< " major \n";
		cout<<requiredCourses;
		cout<<electiveCourses;
	}

};

//class Minor: private BachelorDegree
//{
//private:
//	string minorType;
//	int numberOfRequiredCourses;
//	int numberOfElectiveCourses;
//	
//
//public:
//	int minorSelected;
//
//	virtual void input()
//	{
//		BachelorDegree::input();
//		cout<<"Please select one of the listed minor programs: \n";
//		cin>>minorSelected;
//	}
//
//	virtual void output()
//	{
//		BachelorDegree::output();
//		cout<<"You have selected "<<minorType<< " minor \n";
//		cout<<numberOfRequiredCourses;
//		cout<<numberOfElectiveCourses;
//	}
//};

class ComputerScience: public Speciality
{
private:
	string description;
	string offeredCourses;
	string professors;
	string suggestedSchedule;

public:
	char willContinue;

	virtual void input()
	{
		Major::input();
		cout<<"Would you like to see description for another course? (y/n) \n";
		cin>>willContinue;
	}

	virtual void output()
	{
		Major::output();
		cout<<description;
		cout<<offeredCourses;
		cout<<professors;
		cout<<suggestedSchedule;
	}

};

class Economics: public Major
{
private:
	string description;
	string offeredCourses;
	string professors;
	string suggestedSchedule;
public:
	char willContinue;

	virtual void input()
	{
		Major::input();
		cout<<"Would you like to see description for another course? (y/n) \n";
		cin>>willContinue;
	}

	virtual void output()
	{
		Major::output();
		cout<<description;
		cout<<offeredCourses;
		cout<<professors;
		cout<<suggestedSchedule;
	}
};

class BusinessAdministration: public Major
{
private:
	string description;
	string offeredCourses;
	string professors;
	string suggestedSchedule;

public:
	char willContinue;

	virtual void input()
	{
		Major::input();
		cout<<"Would you like to see description for another course? (y/n) \n";
		cin>>willContinue;
	}

	virtual void output()
	{
		Major::output();
		cout<<description;
		cout<<offeredCourses;
		cout<<professors;
		cout<<suggestedSchedule;
	}
};

class ComputerScience: public Minor
{
	private:
	string description;
	string offeredCourses;
	string professors;

public:
	char willContinue;

	virtual void input()
	{
		Minor::input();
		cout<<"Would you like to see description for another course? (y/n) \n";
		cin>>willContinue;
	}

	virtual void output()
	{
		Minor::output();
		cout<<description;
		cout<<offeredCourses;
		cout<<professors;
	}
};

class InformationSystems: public Minor
{
private:
	string description;
	string offeredCourses;
	string professors;

public:
	char willContinue;

	virtual void input()
	{
		Minor::input();
		cout<<"Would you like to see description for another course? (y/n) \n";
		cin>>willContinue;
	}

	virtual void output()
	{
		Minor::output();
		cout<<description;
		cout<<offeredCourses;
		cout<<professors;
	}
};

class Economics: public Minor
{
	private:
	string description;
	string offeredCourses;
	string professors;

public:
	char willContinue;

	virtual void input()
	{
		Minor::input();
		cout<<"Would you like to see description for another course? (y/n) \n";
		cin>>willContinue;
	}

	virtual void output()
	{
		Minor::output();
		cout<<description;
		cout<<offeredCourses;
		cout<<professors;
	}

};

enum MajorMinor

int degreeSelect(AubgAcademicProgramme* majors[20]) // Definition of a function where the user will be prompted to choose
												   // a major to be described
{
	int currentChoice = 0;
	char continueOrNot = ' ';
	int choice;

	enum Degree 
	{
		bachelor = 1,
		master = 2,
	};

	enum Majors 
	{
		computerScienceMajor = 3,
		economicsMajor = 4,
		businessAdministrationMajor = 5,

	};

	enum Minors
	{
		computerScienceMinor = 6,
		informationSystemsMinor = 7,
		economicsMinor = 8,
	};

	cout<<"Please enter the degree of education you would like to receive information for: "<<endl;
	cout<<"Please choose 1 for a bachelor degree or 2 for a master degree:"<<endl;
	cin>>choice;

	switch (choice)
	{
	case bachelor: majors[currentChoice] = new BachelorDegree;
		cout<<"You chose a bachelor degree."<<endl;
		cout<<"Available description of AUBG courses exist for Computer Science, Business Administration and Economics majors"<<endl;
		cout<<"Please select 3 for Computer Science, 4 for Business Administration and 5 for Economics major:"<<endl;
		majors[currentChoice]->input();
		//currentChoice++;
		cout<<"Would you like to see description for another major? y/n: "<<endl;
		cin>>continueOrNot;
		if (continueOrNot=='y')
		{
		cout<<"Enter a major from the list above"<<endl;
		cin>>choice;
		}
	else
	{
		break;
	}

	default:
		break;
	}
}

int minorSelect(AubgAcademicProgramme* minors[20]) // Definition of a function where the user will be prompted to choose
												   // a minor to be described
{

}



template <class T> void listInsertionSort(vector<T> & v)  //Linked List data structure
{
	// declare an ordered list of the correct type
	//orderedList<T> sorter;

	// copy the entire vector into the ordered list
	// the following generates a string g++ error
	vectorIterator<T> vitr(v);
	for (vitr.init(); ! vitr; ++vitr) {
		sorter.add(vitr()); 
		}

	// now copy the values back into the array
	int i = 0;
	listIterator<T> itr(sorter);
	for (itr.init(); ! itr; ++itr)
		v[i++] = itr();
}



vector<string> insertionSort(vector<string> collection, int length) //insertion sort
 {
    int i, j;
	string tmp;
	long int counter=0; 
    for (i = 1; i < length; i++)
	{
        j = i;
        while (j > 0 && collection[j - 1] > collection[j]) 	
		{	
            tmp = collection[j];
            collection[j] = collection[j - 1];
            collection[j - 1] = tmp;
            j--;
			counter++; 
        }	
    }
	return collection;
}

void main()
{
}
