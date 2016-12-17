/*!
  @file   FaceLandmarkMeshMapper.h
  @author David Hirvonen
  @brief  Declaration of a FaceMeshMapper interface to the EOS library.

  This is based on sample code provided with the EOS library.

  See: https://github.com/patrikhuber/eos

  \copyright Copyright 2014-2016 Elucideye, Inc. All rights reserved.
  \license{This project is released under the 3 Clause BSD License.}

*/

#ifndef __drishti_face_FaceLandmarkMeshMapper_h__
#define __drishti_face_FaceLandmarkMeshMapper_h__ 1

#include "drishti/face/drishti_face.h"
#include "drishti/face/Face.h"

// experimental eos stuff
#include "eos/core/Landmark.hpp"
#include "eos/core/LandmarkMapper.hpp"
#include "eos/render/Mesh.hpp"

#include "opencv2/core/core.hpp"

#include <iostream>
#include <memory>

DRISHTI_FACE_NAMESPACE_BEGIN

class FaceLandmarkMeshMapper
{
public:

    struct Impl;

    using LandmarkCollection2d = eos::core::LandmarkCollection<cv::Vec2f>;

    FaceLandmarkMeshMapper(const std::string &modelfile, const std::string &mappingsfile);

    cv::Point3f operator()(const LandmarkCollection2d &landmarks, const cv::Mat &image, eos::render::Mesh &mesh, cv::Mat &isomap);

    cv::Point3f operator()(const FaceModel &face, const cv::Mat &image, eos::render::Mesh &mesh, cv::Mat &isomap);

    static void save(const eos::render::Mesh &mesh, const std::string &filename);

protected:

    std::shared_ptr<Impl> m_pImpl;
};

DRISHTI_FACE_NAMESPACE_END

#endif // __drishti_face_FaceLandmarkMeshMapper_h__ 
