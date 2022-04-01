#include <iostream>
#include <vector>
using namespace std;

class rectangle
{
protected:
	int height = 0;
	int width = 0;
public:
	virtual void set_height(int temp)
	{
		cout<<"set rectangle height"<<endl;
		height = temp;
	}

	virtual void set_width(int temp)
	{
		cout<<"set rectangle width"<<endl;
		width = temp;
	}

	int areas(void)
	{
		return height * width;
	}
};

class square:public rectangle
{
public:
	void set_height(int temp)
	{
		height = temp;
		width = temp;
	}

	void set_width(int temp)
	{
		height = temp;
		width = temp;
	}
};

int main(void)
{

	// rectangle *a = NULL;
	// a = new rectangle;

	class rectangle *a;
	a = new(square);

	a->set_height(5);
	a->set_width(10);

	cout<<a->areas()<<endl;

	return 0;
}