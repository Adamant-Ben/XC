#include "stdafx.h"
#include "Point2.h"
#include "math.h"
Point2* Caculate:: guihua1(float l1,float miu1,float z1,float l2,float miu2,float z2,unsigned int len1)
{
	
	point = new Point2(len1);
	for(int i=0;i < len1+1;i++)
	{
		point->p[0][i]=(i)*(l2-l1)/len1+l1;
		point->p[1][i]=(i)*(miu2-miu1)/len1+miu1;//直线规划经度和纬度数据
		point->p[2][i]=(z2-z1)*i*i/(len1*len1)+z1;//抛物线规划深度数据
		point->p[4][i]=0;//纵倾角数据
		point->p[5][i]=0;//横滚角数据
	}
	for(int j=0;j < len1;j++)
	{
	point->p[3][j]=atan2((point->p[0][j+1]-point->p[0][j]),(point->p[1][j+1]-point->p[1][j]));
	}
	point->p[3][len1]=0;
	return point;

}

Point2* Caculate:: guihua2(float l3,float miu3,float z3,float l4,float miu4,float z4,unsigned int len2)
{
	point = new Point2(len2);
	for(int i=0;i < len2+1;i++)
	{
		point->p[0][i]=(i)*(l4-l3)/len2+l3;
		point->p[1][i]=(i)*(miu4-miu3)/len2+miu3;
		point->p[2][i]=z3;
		point->p[4][i]=0;//纵倾角数据
		point->p[5][i]=0;//横滚角数据
	}
	for(int j=0;j < len2;j++)
	{
	point->p[3][j]=atan2((point->p[0][j+1]-point->p[0][j]),(point->p[1][j+1]-point->p[1][j]));
	}
	point->p[3][len2]=0;
	return point;
}

Point2* Caculate:: guihua3(float l5,float miu5,float z5,float l6,float miu6,float z6,unsigned int len3)
{
	point = new Point2(len3);
	for(int i=0;i < len3+1;i++)
	{
		point->p[0][i]=(i)*(l6-l5)/len3+l5;
		point->p[1][i]=(i)*(miu6-miu5)/len3+miu5;
		point->p[2][i]=(z6-z5)*i*i/(len3*len3)+z5;//抛物线规划深度数据
		point->p[4][i]=0;//纵倾角数据
		point->p[5][i]=0;//横滚角数据
	}
	for(int j=0;j < len3;j++)
	{
	point->p[3][j]=atan2((point->p[0][j+1]-point->p[0][j]),(point->p[1][j+1]-point->p[1][j]));
	}
	point->p[3][len3]=0;
	return point;
}