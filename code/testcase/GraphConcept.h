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


class QtVertexItem;
class QtEdgeItem;

  using namespace boost;

enum VertexFPSType{VISUAL_OBJECT, PATH_VERTEX , LFP_VERTEX};
enum EdgeFPSType{HORIZONTAL_CONNECTION,VERTICAL_CONNECTION};


  //GraphWidget Graphs

  struct TreeNode_visual
  {
    std::string name;
    VertexFPSType type;
    unsigned int layer;
    double x,y,z;
    QtVertexItem* vertexItem;
  };
 struct TreeNode
  {
    std::string name;
    unsigned int layer;
    double x,y,z;
    VertexFPSType type;
  };

  /* * connection types
  **Connections can be of the types:
  **Bridges
  **Stairs
  **
  **both of these connectiontypes can be constructed using horizontal and vertical 'jumps' respectively
  ** a 'jump' is an element that shoots the player through space.
  */
  struct Connection_visual
  {
      std::string name;
      EdgeFPSType type;
      QtEdgeItem* edgeItem;
  };

  struct Connection
  {
      std::string name;
      EdgeFPSType type;
  };

  typedef adjacency_list<vecS, vecS, undirectedS, TreeNode_visual, Connection_visual> Graph_qt;
  typedef adjacency_list<vecS, vecS, undirectedS, TreeNode, Connection> Graph;

  typedef graph_traits<Graph>::vertex_descriptor Vertex;
  typedef graph_traits<Graph>::edge_descriptor Edge;

  typedef std::list<Vertex> VertexList;


  typedef std::pair<Graph::edge_descriptor, bool> edge_r;



#endif // GRAPHCONCEPT_H
