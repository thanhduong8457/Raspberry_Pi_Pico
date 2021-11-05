#include <iostream>
#include <vector>
using namespace std;

typedef struct my_data
{
	int red;
	int green;
}my_data_t;

std::vector<my_data_t *> m_my_data;

void create_data(int a, int b)
{
	my_data_t *data = NULL;
	data = new my_data_t;
	data->red = a;
	data->green = b;
	m_my_data.push_back(data);
}

int main(void)
{

	cout<<"Hola"<<endl;

	return 0;
}