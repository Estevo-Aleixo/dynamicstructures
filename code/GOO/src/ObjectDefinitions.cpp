#include "ObjectDefinitions.h"

ObjectDefinitions* ObjectDefinitions::mInstance=0; 

void ObjectDefinitions::Create(std::string& filename)
{
	//create singleton
	mInstance= new ObjectDefinitions(filename); 


}

void ObjectDefinitions::Destroy()
{

}


ObjectDefinitions::ObjectDefinitions(std::string& filename)
{
	//load file and definitions
	loadObjectDefinitions(filename); 
	loadDefaultObjects(); 
	
	//mObjects.push_back(new Object2DProperties(std::string("Triangle"),TRIANGLE_MESH,1.0,1.0,0.3)); 
	//mObjects.push_back(new Object2DProperties(std::string("Square"), SQUARE_MESH,1.0,1.0,0.3)); 
	//mObjects.push_back(new Object2DProperties(std::string("Hexagon"),HEXAGON_LINE_MESH,1.0,1.0,0.3)); 


}



ObjectDefinitions::~ObjectDefinitions(void)
{
}

void ObjectDefinitions::loadObjectDefinitions(std::string& filename)
{
	

}

Object2DProperties ObjectDefinitions::getObjectByName(const char* name)
{
	//make hash table with names;
	for(int i=0; i < mObjects.size(); i++)
	{
		if (mObjects[i].mName.compare(std::string(name))==0)
		{
			return mObjects[i];
		}  
	} 

	
	return this->mObjects[0];
}

std::vector<Object2DProperties>& ObjectDefinitions::getAll2DObjects()
{
		return this->mObjects; 
}

void ObjectDefinitions::loadDefaultObjects()
{
		Real cellSize= 1.0;
		Ogre::ColourValue colour=  Ogre::ColourValue(); 
		Ogre::ManualObject* cellHex; 
		Ogre::ManualObject* cellSquare; 
		Ogre::ManualObject* cellTriangle; 
		Object2DProperties newObject;
		

	//SQUARE
		//create square mesh
		b2PolygonDef* shapeDef= new b2PolygonDef();
		cellSquare= new Ogre::ManualObject("wireCellSquare"); 
		cellSquare->begin("square_cell",RenderOperation::OT_TRIANGLE_LIST); 
			cellSquare->position(Vector3(-0.5*cellSize,-0.5*cellSize,0));
			cellSquare->position(Vector3(0.5*cellSize,-0.5*cellSize,0));
			cellSquare->position(Vector3(0.5*cellSize,0.5*cellSize,0));
			cellSquare->position(Vector3(-0.5*cellSize,0.5*cellSize,0));
			cellSquare->quad(0,1,2,3); 
		cellSquare->end(); 
		cellSquare->convertToMesh(SQUARE_MESH);
		//set physical properties
		shapeDef->vertexCount=4; 
		shapeDef->vertices[0].Set(-0.5*cellSize,-0.5*cellSize); 
		shapeDef->vertices[1].Set(0.5*cellSize,-0.5*cellSize); 
		shapeDef->vertices[2].Set(0.5*cellSize,0.5*cellSize); 
		shapeDef->vertices[3].Set(-0.5*cellSize,0.5*cellSize); 
		shapeDef->density= 5.0;
		shapeDef->friction= 2.0;
		newObject= Object2DProperties("Square",SQUARE_MESH,shapeDef,1.0); 
		//newObject.filterData.groupIndex= -2;// layerID::layer1; 
		//newObject.filterData.categoryBits= 0x0004; 
		//newObject.filterData.maskBits = 0x0001;
		mObjects.push_back(newObject);
	
	//LOAD HEXAGON 
		shapeDef= new b2PolygonDef();
		Ogre::Radian angle= Ogre::Radian(Math::TWO_PI /6); 
		Ogre::Real x,y; 
		cellHex= new Ogre::ManualObject("wireCellHex"); 
		cellHex->clear(); 
		cellHex->begin("hexagon_cell",RenderOperation::OT_LINE_LIST); 
		shapeDef->vertexCount=6;
		for (int i=0; i < 6 ;i++){
			x= Math::Cos(angle * i);
			y= Math::Sin(angle * i);
			//mesh pos:
			cellHex->position(x,y,0); 
			//shape pos:
			shapeDef->vertices[i].Set((float32)x,(float32)y);
			cellHex->colour(colour); 
		} 
		for (int i=1; i < 6 ;i++){
			cellHex->index(i-1);	
			cellHex->index(i);	
		}
		cellHex->index(5);
		cellHex->index(0);
		cellHex->end(); 
		cellHex->convertToMesh(HEXAGON_LINE_MESH);  
		shapeDef->density= 5.0;
		shapeDef->friction= 2.0;
		newObject= Object2DProperties("Hexagon",HEXAGON_LINE_MESH,shapeDef,1.0);
		//newObject.filterData.groupIndex = -2;//layerID::layer2; 
		//newObject.filterData.categoryBits= 0x0002 ; 
		//newObject.filterData.maskBits = 0x0002 ;
		mObjects.push_back(newObject);

	//load triangle


	//load circle


//create triangle
	shapeDef= new b2PolygonDef();
	cellTriangle= new Ogre::ManualObject("cellTriangle"); 
	cellTriangle->clear(); 
	cellTriangle->begin("triangle_cell",RenderOperation::OT_TRIANGLE_LIST); 

	Ogre::Radian startAngle= Ogre::Radian(Math::PI/2); 
	Ogre::Radian intervalAngle= Ogre::Radian(Math::TWO_PI/3); 
	shapeDef->vertexCount=3;
	for (int i=0; i < 3 ;i++)
	{
		angle= startAngle + (intervalAngle* i);
		x= Math::Cos(angle);
		y= Math::Sin(angle);
		cellTriangle->position(x,y,0); 
		shapeDef->vertices[i].Set((float32)x,(float32)y);
	} 

	cellTriangle->colour(colour); 	
	cellTriangle->triangle(0,1,2);

	cellTriangle->end(); 

	cellTriangle->convertToMesh(TRIANGLE_MESH);  
	shapeDef->density= 5.0;
	shapeDef->friction= 2.0;
	newObject= Object2DProperties("Triangle",TRIANGLE_MESH,shapeDef,1.0); 
	//newObject.filterData.groupIndex= -2;//layerID::layer3; 
	//newObject.filterData.categoryBits= 0x0003 ; 
	//newObject.filterData.maskBits = 0x0003 ;
	mObjects.push_back(newObject);



	
//create Circle

	b2CircleDef* circleDef=new b2CircleDef();

	circleDef->density= 5.0;
	circleDef->friction= 2.0;
	circleDef->radius = 0.5f;

	newObject= Object2DProperties("Circle",SQUARE_MESH,circleDef,1.0); 
	//newObject.filterData.groupIndex= -2;//layerID::layer3; 
	//newObject.filterData.categoryBits= 0x0003 ; 
	//newObject.filterData.maskBits = 0x0003 ;
	mObjects.push_back(newObject);

}
