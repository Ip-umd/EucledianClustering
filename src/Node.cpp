/**
 *  @file      Node.cpp
 *  @author    Ishan Patel
 *  @brief     Implementation of Node Class
 *
 * 	It represents a node of KdTree
 */

#include <iostream>
#include <vector>
#include "Node.hpp"

Node::Node() {}

Node::Node(std::vector<float> setPoint, int setId) {
	point = setPoint;
	id = setId;
	left = NULL;
	right = NULL;
}

Node::~Node() {}