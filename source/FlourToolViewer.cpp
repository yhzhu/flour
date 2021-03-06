/** File: FlourToolVersion.cpp
    Created on: 06-Sept-09
    Author: Robin Southern "betajaen"

    Copyright (c) 2009 Robin Southern

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/

#include "FlourToolViewer.h"
#include "Flour.h"
#include <iostream>

#include <NxOgre.h>
#include <GL/glut.h>

#include <boost/algorithm/string.hpp>

namespace N = NxOgre;
namespace E = NxOgre::Enums;

FlourViewer::FlourViewer()
: FlourTool("viewer", "View saved meshes or heightfields"),
  OpenGL(),
  mYaw(-0.785398163 * 2),
  mPitch(0.523598776),
  mDistance(12)
{
 
 mOptionsDescription.add_options()
    ("help", "Show this")
    ("file,f", boost::program_options::value< std::vector<std::string> >(), "File(s) to process")
 ;
 
 mPositionalOptions.add("file", -1);
 
 add_error(ERROR_NoFile, "Need at least one file.");
 
}

FlourViewer::~FlourViewer()
{
}

void FlourViewer::process()
{

 // Need at least one file.
 if (mVariablesMap.count("file") == 0)
 {
  error(ERROR_NoFile, true);
  return;
 }

 createWindow("Flour - Cupcake", 1024, 768, OpenGL::WindowIcon_Brick);
 createScene();
 orbitCamera(mYaw, mPitch, mDistance);
 std::vector<std::string> files = mVariablesMap["file"].as<std::vector<std::string>>();

 N::Vec3 pos;
 pos.x = 0;
 pos.y = 0;
 pos.z = 2;

 for (unsigned int i=0; i < files.size(); i++)
 {
  createBody(files[i], 0, pos);
  pos.z += 2;
 }

 startRendering();
}


void FlourViewer::onPostFrame()
{
}

void FlourViewer::onKeyEvent(char key)
{
}

void FlourViewer::onMouseDragEvent(int ButtonID, int dx, int dy)
{
 if (ButtonID == GLUT_LEFT_BUTTON)
 {
  mYaw   += (float(dx) * 0.0075f);
  mPitch -= (float(dy) * 0.0075f);
 }

 if (ButtonID == GLUT_RIGHT_BUTTON)
 {
  mDistance += (float(dy) * 0.005f);
 }
 
 orbitCamera(mYaw, mPitch, mDistance);
}

void FlourViewer::onMouseButtonEvent(int ButtonID, int x, int y)
{
}









