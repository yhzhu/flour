/** File: FlourFile.h
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

#ifndef FLOUR_FILE_H
#define FLOUR_FILE_H

#include "NxOgre.h"
#include <string>

class FlourFile
{
  
 public:
  
  enum FileType
  {
   FileType_Mesh,
   FileType_Heightfield
  };
  
                                      FlourFile(const std::string& extension, const std::string& description, const std::string& opposite, FileType);
  
  virtual                            ~FlourFile();
  
  std::string                         getOpposite() const { return mOpposite; }

  std::string                         getExtension() const { return mExtension; }
  
  std::string                         getDescription() const { return mDescription; }
  
  FileType                            getType() const { return mType; }
  
  NxOgre::ArchiveResourceIdentifier   getARI(const std::string& archive_name, const std::string& path);

  std::string                         createOrGetArchive(const std::string& directory);
  
  virtual NxOgre::Mesh*               get(const std::string& path);
  
  virtual NxOgre::MeshData*           loadMesh(const std::string& path);
  
  virtual void                        saveMesh(const std::string& path, NxOgre::MeshData*);
  
  virtual NxOgre::ManualHeightField*  loadHeightfield(const std::string& path);
  
  virtual void                        saveHeightfield(const std::string& path, NxOgre::HeightFieldData*);
  
 protected:
  
  std::string                                             mExtension;
  
  std::string                                             mDescription;
  
  std::string                                             mOpposite;
  
  FileType                                                mType;
  
};

#endif