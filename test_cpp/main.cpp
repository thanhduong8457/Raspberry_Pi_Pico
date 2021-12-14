#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


string ltrim(const string &);
string rtrim(const string &);

int main()
{
	string temp;
	getline(cin, temp);
	int n = stoi(ltrim(rtrim(temp)));
	int array[n];

	for(int i=0;i<n-1;i++)
	{
		array[i] = 0;
	}

    string string_temp;

    getline(cin, string_temp);


	int pos = 0;

	int last = 0;

	for(int i=0;i<string_temp.length()+1;i++)
	{
		if(string_temp[i]==' ')
		{
			array[pos] = stoi(ltrim(rtrim(string_temp.substr(last, i))));
			last = i;
			pos++;
		}
	}

	array[n-1] = stoi(ltrim(rtrim(string_temp.substr(last, n))));

	for(int i=n-1;i>=0;i--)
	{
		cout<<array[i];
		if(i>0)
		{
			cout<<" ";
		}
	}

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
