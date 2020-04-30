#include"SMS.h"
#include<cstdlib>
#include<string>
#include<fstream>
#include<cstring>
#include<vector>

void addRecords()
{
	system("cls");
	ofstream Sfile("D:\\Sfile.txt", ios::app);
	char add;
	student aa;
	do {
		if (!Sfile)
		{
			cout << "error Cannot open file Sfile!" << endl;
			exit(1);
		}
		cout << "Please input first name : ";
		cin >> aa.first_name;
		cout << "Please input last name: ";
		cin >> aa.last_name;
		cout << "Please input ID: ";
		cin >> aa.id;
		cout << "Please input gender: ";
		cin >> aa.gender;
		cout << "Please input age: ";
		cin >> aa.age;
		cout << "Please input math mark: ";
		cin >> aa.math_mark;
		cout << "Please input English mark: ";
		cin >> aa.eng_mark;
		cout << "Please input computer mark: ";
		cin >> aa.cmp_mark;
		if (Sfile)
		{
			Sfile << "Name: " << aa.first_name << " " << aa.last_name << endl;
			Sfile << "ID: " << aa.id << endl;
			Sfile << "Gender: " << aa.gender << endl;
			Sfile << "Age: " << aa.age << endl;
			Sfile << "Math: " << aa.math_mark << endl;
			Sfile << "English: " << aa.eng_mark << endl;
			Sfile << "Computer: " << aa.cmp_mark << endl;
		}
		fflush(stdin);
		cout << "Add Another Record(Y/N):" << endl;
		cin >> add;
	} while (add == 'Y' || add == 'y');
	Sfile.close();
}

char str[20];
char* browseFil(fstream& Sfile)
{
	if (Sfile)Sfile.getline(str, 20);
	return str;
}

void listRecord()
{
	system("cls");
	fstream Sfile("D:\\Sfile.txt");
	while (Sfile)
		cout << browseFil(Sfile) << endl;
	if (Sfile)
	{
		Sfile.close();
	}
	system("pause");
}

void individualRecords()
{
	system("cls");
	fstream Sfile("D:\\Sfile.txt");
	char findStr[10];
	int check = 0;
	cout << "Please input who you want to find (eg: the person's last name/ the person's first name): ";
	cin >> findStr;
	while (Sfile)
	{
		char* filestr = browseFil(Sfile);
		char* str = strstr(filestr, findStr);
		if (str != NULL && str != findStr)
		{
			cout << filestr << endl;
			filestr = browseFil(Sfile);
			while (Sfile && strstr(filestr, "Name") == NULL)
			{
				cout << filestr << endl;
				filestr = browseFil(Sfile);
			}
			check = 1;
			break;
		}
	}
	if(check==0)cout << "format error, cannot find!" << endl;
	if (Sfile)
	{
		Sfile.close();
	}
	system("pause");
}

void modifyRecorts(fstream& Sfile, fstream& Tfile)
{
	char findOne[10];
	cout << "Please input who you want to modify (eg: the person's last name/ the person's first name): ";
	cin >> findOne;
	char mod[10];
	cout << "Please input the course you want to modify (eg: Math / English / Computer): ";
	cin >> mod;
	char modto[10];
	cout << "Please input the mark you want to modify (eg: 98): ";
	cin >> modto;
	char Case = '0';
	while (Sfile)
	{
		char* filestr = browseFil(Sfile);
		char* str = strstr(filestr, findOne);
		char* strmod = strstr(filestr, mod);
		if (str != NULL && str != findOne) Case = '1';
		else if (Case == '1' && strmod != NULL && strmod != mod)
		{
			char aa[3] = ": ";
			char bb[100]="\0";
			strcat_s(bb, strlen(mod)+1, mod);
			strcat_s(bb, strlen(bb) + strlen(aa) + 1, aa);
			strcat_s(bb,strlen(bb)+strlen(modto)+1,modto);
			filestr = bb;
			Case = '0';
		}
		Tfile << filestr << endl;
	}
}

void removeRecorts(fstream& Sfile, fstream& Tfile)
{
	char findOne[10];
	cout << "Please input who you want to remove (eg: the person's last name/ the person's first name ): ";
	cin >> findOne;
	int Case = 0;
	while (Sfile)
	{
		char* filestr = browseFil(Sfile);
		char* str = strstr(filestr, findOne);
		if (str != NULL && str != findOne)Case = 1;
		else if (Case >= 1&&Case<=6 && strstr(filestr, "Name") == NULL)Case += 1;
		else Tfile << filestr << endl;
	}
}
void mod_rem(int choice)
{
	system("cls");
	fstream Sfile("D:\\Sfile.txt");
	fstream Tfile("D:\\Tfile.txt", ios::out);
	if (!Tfile)
	{
		cout << "error Cannot open file Sfile!" << endl;
		exit(1);
	}
	if (choice == 4)modifyRecorts(Sfile, Tfile);
	else if (choice == 5)removeRecorts(Sfile, Tfile);
	Tfile.close();
	Sfile.close();
	system("del D:\\\Sfile.txt");
	char oldname[] = "D:\\Tfile.txt";
	char newname[] = "D:\\Sfile.txt";
	int ret = rename(oldname, newname);
	if (ret == 0)cout << "Success." << endl;
	else cout << "something error, please open file Tfile.txt for checking.";
	system("pause");
}
void generalScores()
{
	system("cls");
	fstream Sfile("D:\\Sfile.txt");
	int ii;
	int math=0, english=0, computer=0;
	int count = 0;
	string i,j,k;
	cout << "Course      " << "Average Score      " << "Evaluation"<<endl;
	while (Sfile)
	{
		Sfile >> i>>j>>k;
		if (i == "Name:")
		{
			Sfile >> i >> j;
			Sfile >> i >> j;
			Sfile >> i >> j;
			Sfile >> i >> ii;
			math+=ii;
			Sfile >> i >> ii;
			english += ii;
			Sfile >> i >> ii;
			computer += ii;
			count++;
		}
		else break;
		
	}
	cout << "Math             ";
	cout << math / count << "             ";
	if (math / count >=85) cout << "Excellent" << endl;
	else if (math / count >= 70 && math / count < 85) cout << "Good" << endl;
	else if (math / count < 70 && math / count >= 60) cout << "Pass" << endl;
	else cout << "Fail" << endl;

	cout << "English          ";
	cout << english / count << "             ";
	if (english / count >= 85) cout << "Excellent" << endl;
	else if (english / count >= 70 && english / count < 85) cout << "Good" << endl;
	else if (english / count < 70 && english / count >= 60) cout << "Pass" << endl;
	else cout << "Fail" << endl;

	cout << "Computer         ";
	cout << computer / count << "             ";
	if (computer / count >= 85) cout << "Excellent" << endl;
	else if (computer / count >= 70 && computer / count < 85) cout << "Good" << endl;
	else if (computer / count < 70 && computer / count >= 60) cout << "Pass" << endl;
	else cout << "Fail" << endl;
	if (Sfile)
	{
		Sfile.close();
	}
	system("pause");
}

void individalEvaluation()
{
	system("cls");
	fstream Sfile("D:\\Sfile.txt");
	int ii;
	string i, j, k;
	cout << "Name           " << "Percentage of totle scores     " << "Evaluation" << endl;
	while (Sfile)
	{
		Sfile >> i >> j >> k;
		if (i == "Name:")
		{
			cout << j << " " << k << "                ";
			Sfile >> i >> j;
			Sfile >> i >> j;
			Sfile >> i >> j;

			int tot = 0;
			Sfile >> i >> ii;
			tot = ii;
			Sfile >> i >> ii;
			tot += ii;
			Sfile >> i >> ii;
			tot += ii;
			cout << tot / 3 << "%                          ";
			if (tot >= 255) cout << "Excellent" << endl;
			else if (tot >= 210 && tot < 255) cout << "Good" << endl;
			else if (tot < 210 && tot >= 180) cout << "Pass" << endl;
			else cout << "Fail" << endl;
		}
		else break;
	}
	if (Sfile)
	{
		Sfile.close();
	}
	system("pause");
}