#ifdef TOWPOINT_EXPORTS
#define TOWPOINT_API __declspec(dllexport)
#else
#define TOWPOINT_API __declspec(dllimport)


class Point2
{
public:
	Point2( int item,  int row = 4) : row_(row), item_(item)
	{
		p = new float *[row];
		for(int i = 0; i < row_;++i)
			p[i] = new float[item_];
	}

	~Point2()
	{
		if(!p)
		{
			for(int i = 0;i < item_; ++i)
				delete  []p[i];
			delete []p;
		}
	}

	unsigned int GetRow()
	{
		return row_;
	}

	unsigned int GetItem()
	{
		return item_;
	}

private:
	 int row_;
	 int item_;
public:
	float **p;
};

class Caculate
{
public:
	~Caculate()
	{
		if(!point)
		{
			delete point;
		}
	}
public:
	Point2 TOWPOINT_API *guihua1(float l1,float miu1,float z1,float l2,float miu2,float z2,unsigned int len1);
	Point2 TOWPOINT_API *guihua2(float l3,float miu3,float z3,float l4,float miu4,float z4,unsigned int len2);
	Point2 TOWPOINT_API *guihua3(float l5,float miu5,float z5,float l6,float miu6,float z6,unsigned int len3);
private:
	Point2 *point;
};

#endif