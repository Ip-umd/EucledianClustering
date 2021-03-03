/**
 *  @file      KdTree.hpp
 *  @author    Ishan Patel
 *  @brief     Header file for KdTree.cpp
 *  Declaration of the member variables and functions in the KdTree class.
 */

#ifndef INCLUDE_KDTREE_HPP_
#define INCLUDE_KDTREE_HPP_

#include <vector>
#include "Node.hpp"

class KdTree
{	
	private:
		// Object of Node class
		Node* root;

		// Helper function for insert function
		void insertHelper( Node*& node, uint depth, std::vector<float> point, int id);

		// Helper function for search function
		void searchHelper(std::vector<float> target, Node* node, uint depth, float distanceTol, std::vector<int> &ids);

		// Helper function for eucledianCluster function
		void clusterHelper(int indices, std::vector<bool>& processed, const std::vector<std::vector<float>>& points, std::vector<int>& cluster, float distanceTol);

	public:

		KdTree();

		~KdTree();

		//Function to insert new point into the tree
		void insert(std::vector<float> point, int id);

		// Function to obtain a list of point ids in the tree that are within distance of target
		std::vector<int> search(std::vector<float> target, float distanceTol);

		// Function to obtain list of indices for each cluster based on their proximity
		std::vector<std::vector<int>> euclideanCluster(const std::vector<std::vector<float>>& points, float distanceTol);

};

#endif  // INCLUDE_KDTREE_HPP_