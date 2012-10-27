#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "heinricrStarbucks.h";

using namespace ci;
using namespace ci::app;
using namespace std;

class HW04_heinricrApp : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	heinricrStarbucks starbucks; 

};

void HW04_heinricrApp::setup()
{
	heinricrStarbucks* starbucks = new heinricrStarbucks();
	Entry* nearest = starbucks->getNearest(0,0);

	cout<<nearest->identifier<<", "<<nearest->x<<", "<<nearest->y<<endl;
}

void HW04_heinricrApp::mouseDown( MouseEvent event )
{
}

void HW04_heinricrApp::update()
{
}

void HW04_heinricrApp::draw()
{
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 
}

CINDER_APP_BASIC( HW04_heinricrApp, RendererGl )
