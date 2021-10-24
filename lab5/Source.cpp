#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // ���������� �������
#include <cmath>
#include <locale.h>
#include <iostream> // ���������� �����,������
#include <conio.h>
#include < queue >

int** matrix;
using namespace std;

void bfs(int v, int n)
{

	int p = 0, i = 0, u = 0;
	char* NUM;
	NUM = new char[n];
	for (u = 0; u < n; u++)
	{
		NUM[u] = 0;
	}
	cout << v - 1;
	//i = s;
	queue <int> plan; // ���� ��������� � ���� �������
	plan.push(v - 1);   // �� �������� � 0, � �� � 1
	NUM[v - 1] = 1; // ��������, ��� ��� ������� ��� ���������� � ���� 
	//int counter = 1;  // ��������� ��� ���������
	while (!plan.empty()) {
		v = plan.front(); // �������� ��������� �� ����� ������� 
		plan.pop();       // ������� �� �� ����� ���������
		//cout << v;
		for (int i = 0; i < n; i++) { // ���������� �������� � ���
			if ((matrix[v][i] == 1) && (NUM[i] == 0)) { // ���� �����, ��
				plan.push(i);     // ��������� �� � ����
				cout << i;
				NUM[i] = 1; // ��������, ��� ��� �� �����

			}
		}
	}
}


int main()
{
	int p = 0, i = 0, n;
	int v = 0;
	//int s;
	setlocale(LC_ALL, "Russian"); // ����������� ��������
	srand(time(NULL)); // ����� ������ �������

	cout << "n="; // ������� ������
	cin >> n; // �������� ������
	matrix = new int* [n];
	//cout � "n=";
	//cin � n;
	cout << "�������: \n";
	int z;
	for (i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}



	for (i = 0; i < n; i++)
	{
		for (p = 0; p < n; p++)
		{
			matrix[i][p] = rand() % 2;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (p = 0; p < n; p++)
		{

			if (p == i)
			{
				matrix[i][p] = 0;
			}
			else
			{
				matrix[i][p] = matrix[p][i];
			}
		}

	}


	cout << "\n";
	cout << "\n";
	for (i = 0; i < n; i++)
	{
		// used[i] = false;
		for (p = 0; p < n; p++)
			cout << matrix[i][p] << " "; // ������� �������
		cout << endl;
	}

	cout << "��������� ������� � ";
	//cin >> s;
	cin >> v;
	//bool* vis = new bool[n];
	cout << "������� ������: ";
	bfs(v, n);
	//delete[] used;
	_getch();
}