#include"SMS.h"
int main()
{
	while (1)
	{
		system("cls");
		cout << "\t\t======Student Information System======\n\n";
		cout << "\t\t\t1. Add Records\n";
		cout << "\t\t\t2. List Records\n";
		cout << "\t\t\t3. Individual Records\n";
		cout << "\t\t\t4. Modify Recorts\n";
		cout << "\t\t\t5. Remove Records\n";
		cout << "\t\t\t6. Analysis of general scores\n";
		cout << "\t\t\t7. Analysis of individual scores\n";
		cout << "\t\t\t8. Logout\n\n";
		cout << "\t\t=======================================\n\n";

		char choice;
		cout << "Select your choice :=> ";
		cin >> choice;
		switch (choice)
		{
		case'1':
		{
			addRecords();
			break;
		}
		case'2':
		{
			listRecord();
			break;
		}
		case'3':
		{
			individualRecords();
			break;
		}
		case'4':
		{
			mod_rem(4);
			break;
		}
		case'5':
		{
			mod_rem(5);
			break;
		}
		case'6':
		{
			generalScores();
			break;
		}
		case'7':
		{
			individalEvaluation();
			break;
		}
		case'8':
		{
			return 0;
		}
		}
	}
}