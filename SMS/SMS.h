#pragma once
#ifndef SMS
#define SMS
#include<iostream>
using namespace std;
struct student {
	char id[10];
	char first_name[10], last_name[10];
	char gender[10];
	int age;
	int math_mark;
	int cmp_mark;
	int eng_mark;
};
void addRecords();
char* browseFil(fstream& Sfile);
void listRecord();
void individualRecords();
void modifyRecorts(fstream& Sfile,fstream&Tfile);
void removeRecorts(fstream& Sfile, fstream& Tfile);
void mod_rem(int choice);
void generalScores();
void individalEvaluation();
#endif // !SMS