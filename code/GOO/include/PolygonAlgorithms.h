#pragma once

#include "Main.h"

//CGAL HERE
/*
#include<boost/shared_ptr.hpp>

#include<CGAL/basic.h>
#include<CGAL/Cartesian.h>
#include<CGAL/Polygon_2.h>
#include<CGAL/Exact_predicates_inexact_constructions_kernel.h>
#include<CGAL/Straight_skeleton_builder_2.h>
#include<CGAL/Polygon_offset_builder_2.h>
#include<CGAL/compute_outer_frame_margin.h>

//
// This example illustrates how to use the CGAL Straight Skeleton package
// to construct an offset contour on the outside of a polygon
//

// This is the recommended kernel

typedef CGAL::Exact_predicates_inexact_constructions_kernel Kernel;

typedef Kernel::Point_2 Point_2;
typedef CGAL::Polygon_2<Kernel>    Contour;
typedef boost::shared_ptr<Contour> ContourPtr;
typedef std::vector<ContourPtr>    ContourSequence ;

typedef CGAL::Straight_skeleton_2<Kernel> Ss;

typedef Ss::Halfedge_iterator Halfedge_iterator;
typedef Ss::Halfedge_handle   Halfedge_handle;
typedef Ss::Vertex_handle     Vertex_handle;

typedef CGAL::Straight_skeleton_builder_traits_2<Kernel>      SsBuilderTraits;
typedef CGAL::Straight_skeleton_builder_2<SsBuilderTraits,Ss> SsBuilder;

typedef CGAL::Polygon_offset_builder_traits_2<Kernel>                  OffsetBuilderTraits;
typedef CGAL::Polygon_offset_builder_2<Ss,OffsetBuilderTraits,Contour> OffsetBuilder;


*/

class PolygonAlgorithms
{
public:
	PolygonAlgorithms(void);
	~PolygonAlgorithms(void);

/*
static bool check_inside(Point_2 pt, Point_2 *pgn_begin, Point_2 *pgn_end, K traits)
{

	switch(CGAL::bounded_side_2(pgn_begin, pgn_end,pt, traits)) 
  {
    case CGAL::ON_BOUNDED_SIDE :
		return true;
    case CGAL::ON_BOUNDARY:
		return false;
    case CGAL::ON_UNBOUNDED_SIDE:
		return false;
 }
 
return false; 
}
*/
/*
	static bool constructSkeleton(std::vector<Point_2>& boundary, std::vector<Point_2>& result)
{
	SsBuilder ssb;

    // Enter the polygon as a hole of the frame (NOTE: as it is a hole we insert it in the opposite orientation)
    ssb.enter_contour(boundary.rbegin(),boundary.rend());
  
	// Construct the skeleton
    boost::shared_ptr<Ss> ss = ssb.construct_skeleton();


return true;
}
*/

};




