/** File: FlourToolConvert.h
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

#ifndef FLOUR_TOOL_CONVERT_H
#define FLOUR_TOOL_CONVERT_H

#include "FlourTool.h"
#include "NxOgre.h"



class FlourConvert : public FlourTool
{
 public:
  
  enum Errors
  {
   ERROR_NoFile = 1000,
   ERROR_NoMeshData = 1001,
  };
  
  enum ConversionType
  {
   ConversionType_Convex,
   ConversionType_Triangle,
   ConversionType_Cloth,
   ConversionType_Heightfield,
  };

  FlourConvert(ConversionType);
  
 ~FlourConvert();
  
  void process();
  
  void convertConvex(const std::string&);
  
  void convertTriangle(const std::string&);
  
  void convertHeightfield(const std::string&);
  
  void convertCloth(const std::string&);

 protected:
  
  ConversionType mConversionType;
  
};

#endif