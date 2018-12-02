#include "Slider.h"

void slider::setup(string _name, ofVec2f _position, ofVec2f _size, int _touchArea, int _startvalue)
{
    name = _name;
    position = _position;
    size = _size;
    touchArea = _touchArea;
    currentValue = _startvalue;
    
    myfont.load("SourceSansPro-Semibold.ttf", 32);
}

void slider::dragAble(ofVec2f _touchPoint)
{
    float currentValueToSize = ofMap(currentValue,LOWER_VALUE,UPPER_VALUE,LOWER_VALUE,size.x);
    
    if(_touchPoint.x > currentValueToSize-touchArea && _touchPoint.x < currentValueToSize+touchArea)
    {
        if(_touchPoint.y > position.y-touchArea && _touchPoint.y < position.y+size.y+touchArea)
        {
            cout << "Slider: " << name << " touched!";
            isDragable = true;
        }
    }
}

void slider::update(ofVec2f _touchPoint)
{    
    if(isDragable)
    {
        if(_touchPoint.x > position.x && _touchPoint.x < position.x+size.x)
        {
            currentValue = ofMap(_touchPoint.x,position.x,position.x+size.x,LOWER_VALUE, UPPER_VALUE);
            newDataAvailable = true;
        }
        else
        {
            newDataAvailable = false;
        }
    }
}

void slider::draw()
{
    float currentValueToSize = ofMap(currentValue,LOWER_VALUE,UPPER_VALUE,LOWER_VALUE,size.x);
    
    ofSetColor(100, 100, 100);
    ofDrawEllipse(position.x, position.y+size.y/2, size.y, size.y);
    ofDrawEllipse(position.x+size.x, position.y+size.y/2, size.y, size.y);
    ofDrawRectangle(position.x, position.y, size.x, size.y);
    
    ofSetColor(255,255,255);
    ofDrawEllipse(position.x+currentValueToSize, position.y+size.y/2, size.y, size.y);
    
    myfont.drawString(ofToString(currentValue), position.x+size.x/2, position.y-30);
}

int slider::getCurrentValue()
{
    return currentValue;
}
