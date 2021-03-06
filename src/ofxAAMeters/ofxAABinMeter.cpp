/*
 * Copyright (C) 2016 Leo Zimmerman [http://www.leozimmerman.com.ar]
 *
 * Sonoscopio is free software: you can redistribute it and/or modify it under
 * the terms of the GNU Affero General Public License as published by the Free
 * Software Foundation (FSF), either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the Affero GNU General Public License
 * version 3 along with this program.  If not, see http://www.gnu.org/licenses/
 *
 */

#include "ofxAABinMeter.h"

ofxAABinMeter::ofxAABinMeter(string name, int x, int y, int w, int h, int panelId) :  ofxAAMeter(name, x,  y,  w,  h, panelId){
    
    _meterOrient = HORIZONTAL;
    
    smoothSlider->setHeight(_line_h*0.75);
    onOffToggle->setHeight(_line_h*0.75);
    
    updateComponentsPositions();
    updateComponentsWidth();
    
    
    //spectrum cant be turned off
    //mfcc cant work if melBands is turn off
    if(_name == MTR_NAME_SPECTRUM ||
       _name == MTR_NAME_MFCC){
        
        onOffToggle->setVisible(false);
        onOffToggle->ofxDatGuiComponent::setEnabled(false);
        
    }
}

//-------------------------------------------------------
void ofxAABinMeter::draw(){

    
   
    
    //bounds-box
    ofPushStyle();
    ofNoFill();
    ofSetColor(_mainColor);
    ofDrawRectangle(_drawRect);
    ofPopStyle();
    
    drawLabel();
    
    if(_enabled) drawMeter();
    
    if(_bDrawFullDisplay){
       
        onOffToggle->drawTransparent();
        if(_enabled) smoothSlider->drawSimplified();
    }
    

}
//-------------------------------------------------------
void ofxAABinMeter::drawMeter(){
    
    if(getEnabled()==false) return;
    //-----------------------------
    
    ofFill();
    
    ofPushMatrix();
    ofTranslate(_x, _y);
    
    ofPushStyle();
    ofSetColor(COLOR_RECT_METER, COLOR_RECT_METER_ALPHA);
    
    
    float bin_w = (float) _w / _nBins;
    
    for (int i = 0;i < _values.size(); i++){
        float scaledValue = ofMap(_values[i], _minEstimatedValue, _maxEstimatedValue, 0.0, 1.0, true);//clamped value
        float bin_h = -1 * (scaledValue * _h);
        ofDrawRectangle(i*bin_w, _h, bin_w, bin_h);
    }
    
    ofPopStyle();
    
    ofPopMatrix();


}
//-------------------------------------------------------
void ofxAABinMeter::drawLabel(){
    
    ofPushMatrix();
    
    ofTranslate(_x, _y);
    
    if(_enabled) ofSetColor(_mainColor);
    else ofSetColor(COLOR_ONOFF_OFF);
    
    verdana->drawString(_name, _label_x, _line_h * 0.75);
    
    ofPopMatrix();
}


//-------------------------------------------------------
void ofxAABinMeter::setPosAndSize(int x, int y, int w, int h){
    
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    
    _drawRect.set(x, y, w, h);
    
    updateComponentsPositions();
    updateComponentsWidth();
    //updateColors();
    
}
//-------------------------------------------------------
void ofxAABinMeter::updateComponentsPositions(){
   
    smoothSlider->setPosition(_x + _w - _w * 0.25, _y);
    onOffToggle->setPosition(_x, _y);
    
}
//-------------------------------------------------------
void ofxAABinMeter::updateComponentsWidth(){
    
    //-:LABEL
    //constraing width
    float label_w = verdana->stringWidth(_name);
    float widthForLabel = _w * 0.95;
    if(label_w >= widthForLabel){
        float space_ratio = 1 / (label_w / widthForLabel);
        verdana->setLetterSpacing(space_ratio);
    }
    //align center
    label_w = verdana->stringWidth(_name);
    _label_x =  _w * .5 - label_w *.5;
    
    smoothSlider->setWidth(_w * 0.25 , 0.0);
    onOffToggle->setWidth (_w * 0.25, 0.0);

}
