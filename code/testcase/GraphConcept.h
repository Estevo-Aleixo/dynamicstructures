#ifndef GRAPHCONCEPT_H
#define GRAPHCONCEPT_H

#include "BaseHeaders.h"

#include <boost/config.hpp>

#include "boost/graph/graph_traits.hpp"
#include "boost/graph/adjacency_list.hpp"
#include "boost/graph/topological_sort.hpp"
#include <boost/property_map.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/tokenizer.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <boost/graph/kruskal_min_spanning_tree.hpp>

class QtVertexItem;
class QtEdgeItem;

  using namespace boost;

enum VertexFPSType{VISUAL_OBJECT, PATH_VERTEX , LFP_VERTEX};
enum EdgeFPSType{HORIZONTAL_CONNECTION,VERTICAL_CONNECTION};


  //GraphWidget Graphs



 struct TreeNode
  {
    unsigned int layer;
    double x,y,z;
    VertexFPSType type;
    QtVertexItem* vertexItem;
  };

  /* * connection types
  **Connections can be of the types:
  **Bridges
  **Stairs
  **
  **both of these connectiontypes can be constructed using horizontal and vertical 'jumps' respectively
  ** a 'jump' is an element that shoots the player through space.
  */
 /*

*/
  struct Connection
  {
      std::string name;
      double distance;
      int traverseRate;
      EdgeFPSType type;
      QtEdgeItem* edgeItem;
  };

  //typedef std::pair<int, int> Edge;

//  typedef adjacency_list<vecS, vecS, undirectedS, TreeNode, property < edge_weight_t, int > > Graph;
  typedef adjacency_list<listS, vecS, undirectedS, TreeNode, Connection> Graph;


  typedef graph_traits<Graph>::vertex_descriptor vertex_descriptor;
  typedef graph_traits<Graph>::vertex_iterator vertex_iterator;
  typedef graph_traits<Graph>::edge_iterator edge_iterator;
  typedef graph_traits<Graph>::adjacency_iterator adjacency_iterator;

  typedef graph_traits<Graph>::edge_descriptor edge_descriptor;
  typedef std::pair<Graph::edge_descriptor, bool> edge_c;

  typedef std::pair<vertex_iterator, vertex_iterator> vertex_range;

  typedef std::pair<edge_iterator, edge_iterator> edge_range;

 //lijsten
    typedef  std::list<vertex_descriptor> vd_list;
    typedef  std::list<edge_descriptor> ed_list;
    typedef  std::vector<vertex_descriptor> vd_vector;
    typedef  std::vector<edge_descriptor> ed_vector;





#endif // GRAPHCONCEPT_H
