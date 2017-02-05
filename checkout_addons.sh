#!/bin/bash

#Dependencies of Sonoscopio
cd ../../../addons

#ofxDatGui------------------------
cd ofxDatGui
git checkout sonoscopio
cd ../

#ofxMSATimer------------------------
cd ofxMSATimer
git checkout 14e1ff8b0a358151ba13efadac96cf1c50266518
cd ../

#ofxRange------------------------
cd ofxRange
git checkout 8e232a33a0db5007c425c3d1ebc7f57ffb2232ac
cd ../

#ofxTextInputField------------------------
cd ofxTextInputField
git checkout e265bee9547cc1790395f9a1b83289e4e11a7624
cd ../

#ofxTimeMeasurements------------------------
cd ofxTimeMeasurements
git checkout 47fd27f73850dcaf27ffb5dcb339cbbc04e1af91
cd ../

#ofxTimecode------------------------
cd ofxTimecode
git checkout d8b6b97e1334453753b369ace86e0ce7113946b3
cd ../

#ofxTimeline------------------------
cd ofxTimeline
git checkout sonoscopio
cd ../

#ofxTween------------------------
cd ofxTween
git checkout 120757d613b497a7045ee64c1e548abf31ace38e
cd ../




