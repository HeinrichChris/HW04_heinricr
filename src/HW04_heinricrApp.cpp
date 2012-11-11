#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "heinricrStarbucks.h";
#include "cinder/gl/Texture.h";
#include "cinder/ImageIo.h";

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
	void prepareSettings(Settings* settings);
	int frame;

	Surface* surface;
	gl::Texture* texture;
};

void HW04_heinricrApp::prepareSettings(Settings* settings){
	(*settings).setWindowSize(700,550);
	(*settings).setResizable(false);
}

void HW04_heinricrApp::setup()
{
	heinricrStarbucks* starbucks = new heinricrStarbucks();
	Entry* nearest = starbucks->getNearest(0,0);

	surface = new Surface(loadImage("../map.jpg"));
	texture = new gl::Texture(*surface);

	frame = 0;

	//cout<<nearest->identifier<<", "<<nearest->x<<", "<<nearest->y<<endl;
}

void HW04_heinricrApp::mouseDown( MouseEvent event )
{
}

void HW04_heinricrApp::update()
{
	if(frame != 0){
		float x;
		float y;
	
		for(int i = 0; i<starbucks.starbucks.size(); i++){
	
			x = starbucks.starbucks[i].x;
			y = starbucks.starbucks[i].y;
	
			gl::color(255,0,0);
			gl::drawSolidRect(Rectf(x,y,x,y));
		}
	}
	frame++;
}

void HW04_heinricrApp::draw()
{
	gl::draw(*texture);
}

CINDER_APP_BASIC( HW04_heinricrApp, RendererGl )
