#pragma once

//CGAL HERE
#include<CGAL/basic.h>
#include<CGAL/Cartesian.h>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>


typedef CGAL::Cartesian<double> K;
typedef K::Point_2 Point_2;
typedef std::vector<Point_2>            Polygon_2;
typedef boost::shared_ptr<Polygon_2>    PolygonPtr;

#include "ss_types.h"

#include <CGAL/convex_hull_2.h>

using namespace demo;


class PolygonAlgorithms
{
public:
	PolygonAlgorithms(void);
	~PolygonAlgorithms(void);


static bool check_inside(Point_2 pt, Point_2 *pgn_begin, Point_2 *pgn_end, K traits)
{
/*
	switch(CGAL::bounded_side_2(pgn_begin, pgn_end,pt, traits)) 
  {
    case CGAL::ON_BOUNDED_SIDE :
		return true;
    case CGAL::ON_BOUNDARY:
		return false;
    case CGAL::ON_UNBOUNDED_SIDE:
		return false;
 }
 */
return false; 
}




static bool constructSkeleton(Polygon_2* boundary, std::vector<Point_2>* result)
{

	Polygon_2* poly= boundary;

	SSkelPtr sskel;
	SSkelBuilder builder ;

   builder.enter_contour(poly->begin(),poly->end());
   sskel = builder.construct_skeleton() ;

sskel->vertices_begin();
sskel->vertices_end();


Ogre::LogManager::getSingletonPtr()->logMessage("vertices: "); 
	

return true;
}


};




