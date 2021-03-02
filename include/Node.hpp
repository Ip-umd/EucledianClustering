/**
 *  @file      Node.hpp
 *  @author    Ishan Patel
 *  @brief     Header file for Node.cpp
 *  Declaration of the member variables and functions in the Node class.
 */

#ifndef INCLUDE_NODE_HPP_
#define INCLUDE_NODE_HPP_

#include <vector>

class Node {
	public:
		std::vector<float> point;
		int id;
		Node* left;
		Node* right;

		Node();

		Node(std::vector<float> setPoint, int setId);

		~Node();

};

#endif  // INCLUDE_NODE_HPP_