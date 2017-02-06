#ifndef DATAMODEL_H
#define DATAMODEL_H
#include <iostream>
#include <stdio.h>
#include <vector>
#include <fstream>
using namespace std;
typedef struct{
	float x;
	float y;
	float z;
	float r;
	float g;
	float b;
} vertex;

class datamodel
{
public:
	datamodel();
	datamodel(std::string path);
	~datamodel();
	void setPath(string path);
	bool plyRead();
	void plyWrite();
	bool clear();
	int  getTotalVertex();
	int  getTotalFace();
	int  getTotalFaceVertex3();
	const char* getPath();
	ifstream fin;
	string path;
	int m_totalVertexProperty;	//顶点属性数量
	int m_colorFlag;			//顶点颜色标记,0:无，3:RGB，4:RGBA
	int m_colorPropertyPos;		//颜色属性位置，顶点第几个属性为RGB值
	int m_totalVertex;			//顶点数量
	int m_totalFace;			//面数量

public:
	vector<vertex> vecVertex;			//顶点数组，存储模型所有顶点坐标。
	vector<float> vecTriangleColor;		//颜色数组，存储顶点颜色数据。
	vector<float> vecFaceTriangle;		//面数组，存储组成面的各个顶点坐标。
	vector<int>   vecFaceTriangleIndex;	//面索引数组，存储组成面的各顶点的索引。

};

#endif //DATAMODEL