#pragma once

namespace Ogre {

class MovableText : public MovableObject, public Renderable
{
    /******************************** MovableText data ****************************/
public:
    enum HorizontalAlignment    {H_LEFT, H_CENTER};
    enum VerticalAlignment      {V_BELOW, V_ABOVE, V_CENTER};
	
protected:
	String			mFontName;
	String			mType;
	String			mName;
	String			mCaption;
	HorizontalAlignment	mHorizontalAlignment;
	VerticalAlignment	mVerticalAlignment;

	ColourValue		mColor;
	RenderOperation	mRenderOp;
	AxisAlignedBox	mAABB;
	LightList		mLList;

	Ogre::Real			mCharHeight;
	Ogre::Real			mSpaceWidth;

	bool			mNeedUpdate;
	bool			mUpdateColors;
	bool			mOnTop;

	Ogre::Real			mTimeUntilNextToggle;
	Ogre::Real			mRadius;
    Ogre::Real            mAdditionalHeight;

	Camera			*mpCam;
	RenderWindow	*mpWin;
	Font			*mpFont;
	MaterialPtr		mpMaterial;
    MaterialPtr		mpBackgroundMaterial;

    /******************************** public methods ******************************/
public:
	MovableText(const String &name, const String &caption, const String &fontName = "BlueHighway", Ogre::Real charHeight = 1.0, const ColourValue &color = ColourValue::White);
	virtual ~MovableText();

	// Add to build on Shoggoth:
	
	   virtual void visitRenderables(Renderable::Visitor* visitor, bool debugRenderables = false);
	
	
    // Set settings
	void    setFontName(const String &fontName);
	void    setCaption(const String &caption);
	void    setColor(const ColourValue &color);
	void    setCharacterHeight(Ogre::Real height);
	void    setSpaceWidth(Ogre::Real width);
	void    setTextAlignment(const HorizontalAlignment& horizontalAlignment, const VerticalAlignment& verticalAlignment);
	void    setAdditionalHeight( Ogre::Real height );
    void    showOnTop(bool show=true);

    // Get settings
	const   String          &getFontName() const {return mFontName;}
    const   String          &getCaption() const {return mCaption;}
	const   ColourValue     &getColor() const {return mColor;}
	
    uint    getCharacterHeight() const {return mCharHeight;}
	uint    getSpaceWidth() const {return mSpaceWidth;}
    Ogre::Real    getAdditionalHeight() const {return mAdditionalHeight;}
    bool    getShowOnTop() const {return mOnTop;}
    AxisAlignedBox	        GetAABB(void) { return mAABB; }

	const   MaterialPtr       &getMaterial(void) const {assert(!mpMaterial.isNull());return mpMaterial;};

    /******************************** protected methods and overload **************/
protected:

    // from MovableText, create the object
	void	_setupGeometry();
	void	_updateColors();

	// from MovableObject
	void    getWorldTransforms(Matrix4 *xform) const;
    Ogre::Real    getBoundingRadius(void) const {return mRadius;};
	Ogre::Real    getSquaredViewDepth(const Camera *cam) const {return 0;};
    const   Quaternion        &getWorldOrientation(void) const;
    const   Vector3           &getWorldPosition(void) const;
	const   AxisAlignedBox    &getBoundingBox(void) const {return mAABB;};
	const   String            &getName(void) const {return mName;};
	const   String            &getMovableType(void) const {static String movType = "MovableText"; return movType;};

    void    _notifyCurrentCamera(Camera *cam);
	void    _updateRenderQueue(RenderQueue* queue);

	// from renderable
	void    getRenderOperation(RenderOperation &op);	
	const   LightList         &getLights(void) const {return mLList;};
};

}