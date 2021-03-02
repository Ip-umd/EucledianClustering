/**
 *  @file      KdTree.cpp
 *  @author    Ishan Patel
 *  @brief     Implementation of KdTree Class
 */

#include <iostream>
#include <vector>
#include <math.h>
#include "KdTree.hpp"

KdTree::KdTree() {
	root = NULL;
}

KdTree::~KdTree() {}

void KdTree::insertHelper( Node*& node, uint depth, std::vector<float> point, int id) {
	if(node == NULL) {
		node = new Node(point, id);
	}

	else {
		uint cd = depth%3;
		if(node->point[cd] > point[cd]) insertHelper(node->left, depth+1, point, id);
		else insertHelper(node->right, depth+1, point, id);
	}
}
	

void KdTree::insert(std::vector<float> point, int id) {
		
	insertHelper(root, 0, point, id);

}

void KdTree::searchHelper(std::vector<float> target, Node* node, uint depth, float distanceTol, std::vector<int> &ids) {
	if(node != NULL) {
		if(node->point[0]>=(target[0]-distanceTol) && node->point[0]<=(target[0]+distanceTol) && node->point[1]>=(target[1]-distanceTol) && node->point[1]<=(target[1]+distanceTol) && node->point[2]>=(target[2]-distanceTol) && node->point[2]<=(target[2]+distanceTol)) {
			float distance = sqrt((node->point[0] - target[0])*(node->point[0] - target[0]) + (node->point[1] - target[1])*(node->point[1] - target[1]) + (node->point[2] - target[2])*(node->point[2] - target[2]));
			if(distance <= distanceTol) ids.push_back(node->id);
		}

		if(node->point[depth%3] > (target[depth%3]-distanceTol)) searchHelper(target, node->left, depth+1, distanceTol, ids);

		if(node->point[depth%3] < (target[depth%3]+distanceTol)) searchHelper(target, node->right, depth+1, distanceTol, ids);
	}
}


std::vector<int> KdTree::search(std::vector<float> target, float distanceTol) {
	std::vector<int> ids;
	searchHelper(target, root, 0, distanceTol, ids);
	return ids;
}


void KdTree::clusterHelper(int indices, std::vector<bool>& processed, const std::vector<std::vector<float>>& points, KdTree* tree, std::vector<int>& cluster, float distanceTol) {
	processed[indices] = true;
	cluster.push_back(indices);
	std::vector<int> nearest = search(points[indices], distanceTol);
	for(auto i : nearest) {
		if(!processed[i]) clusterHelper(i, processed, points, tree, cluster, distanceTol);
	}

}

std::vector<std::vector<int>> KdTree::euclideanCluster(const std::vector<std::vector<float>>& points, KdTree* tree, float distanceTol)
{

	std::vector<std::vector<int>> clusters;
	std::vector<bool> processed(points.size(), false);

	for(int i=0; i<points.size(); i++) {
		if(!processed[i]){
		  std::vector<int> cluster;
		  clusterHelper(i, processed, points, tree, cluster, distanceTol);
		  clusters.push_back(cluster);
		}

	}
	return clusters;

}
