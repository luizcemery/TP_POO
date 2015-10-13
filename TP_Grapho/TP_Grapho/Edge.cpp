#include "stdafx.h"
#include "Edge.h"
#include <time.h>


Edge::Edge(int node1,int node2,int weight)
{
	this->node1 = node1;
	this->node2 = node2;
	this->weight = weight;
}


Edge::~Edge()
{
}
