## KDTree for Euclidean Clustering

A KD-Tree is a binary tree that splits points between alternating axes. By separating space by splitting regions, nearest neighbor search can be made much faster when using an algorithm like Euclidean clustering. 

**Inserting Points into KD-Tree(three dimensions):**

* First Inserted point becomes root of the tree.

* Consecutive points will flow left if less than root x, or right if greater.

* Since we previously split in the x-dimension, the root was at depth 0, and split the x region. The next point became the left child of root and had a depth of 1, and split the y region. 

* A point at depth 2 will split the z region , so the split dimension number can actually be calculated as depth % d, where d is the number of dimensions we are working with. 

* The basic idea is that the tree is traversed until the Node it arrives at is NULL, in which case a new Node is created and replaces the NULL Node.

	
**Searching Points in a KD-Tree:**

The naïve approach of finding nearby neighbors is to go through every single point in the tree and compare their distances with the target, selecting point indices that fall within the distance tolerance of the target. Instead with the KD-Tree you can compare distance within a boxed square that is 2 x `distanceTol` for length, centered around the target point. If the current node point is within this box then you can directly calculate the distance and see if the point id should be added to the list of nearby ids. Then you see if your box crosses over the node division region and if it does compare that next node. You do this recursively, with the advantage being that if the box region is not inside some division region you completely skip that branch.


**Euclidean Clustering:**

Once the KD-Tree method for searching for nearby points is implemented, its not difficult to implement a Euclidean clustering method that groups individual cluster indices based on their proximity.

## Installation

### Ubuntu 

```bash

$> git clone https://github.com/Ip-umd/EucledianClustering.git
$> cd EucledianClustering 
$> mkdir build && cd build
$> cmake ..
$> make
$> ./test
```
