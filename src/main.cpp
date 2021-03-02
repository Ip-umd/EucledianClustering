/**
 *  @file      main.cpp
 *  @author    Ishan Patel
 *  @brief     main function for testing Eucledian Clustering
 *
 *  This is the main.cpp file that test the search and clustering functionality of the KdTree class
 */


#include <iostream>
#include <vector>
#include "KdTree.hpp"


int main(){
	// Create data
	std::vector<std::vector<float>> points = { {-6.2,7,0}, {-6.3,8.4,0}, {-5.2,7.1,0}, {-5.7,6.3,0}, {7.2,6.1,0}, {8.0,5.3,0}, {7.2,7.1,0}, {0.2,-7.1,0}, {1.7,-6.9,0}, {-1.2,-7.2,0}, {2.2,-8.9,0} };

	KdTree* tree = new KdTree;
  
  for (int i=0; i<points.size(); i++) {
  	tree->insert(points[i],i);
  }

	std::cout << "Test Search" << std::endl;
	std::vector<int> nearby = tree->search({7,5},3.0);
	for(int index : nearby) {
    std::cout << index << ",";
	}
	std::cout << std::endl;

  std::cout << "Test Eucledian Clustering" << std::endl;
  std::vector<std::vector<int>> clusters = tree->euclideanCluster(points, tree, 3.0);
  for(auto index : clusters) {
    for (auto i : index) {
    std::cout << i << ",";
    }
    std::cout << std::endl;
  }
    
}
