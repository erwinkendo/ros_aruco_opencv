// Copyright 2025 Fictionlab sp. z o.o.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
// THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#pragma once

#include <string>
#include <vector>
#include <utility>

#include <opencv2/aruco.hpp>

namespace aruco_opencv
{

struct BoardDescription
{
  std::string name;
  std::string type = "grid";  // "grid" (ArUco GridBoard) or "charuco"
  bool frame_at_center = false;
  // grid
  int markers_x = 0;
  int markers_y = 0;
  double separation = 0.0;
  int first_id = 0;
  // charuco: number of chessboard squares along the board X (width) and Y (height) axes
  int squares_x = 0;
  int squares_y = 0;
  double square_size = 0.0;
  // grid and charuco: side of one marker [m]
  double marker_size = 0.0;
};

struct LoadedBoard
{
  std::string name;
  cv::Ptr<cv::aruco::Board> board;
  // cv::aruco::Board is not polymorphic in OpenCV 4.6, so a ChArUco board cannot be told apart by a cast
  bool is_charuco = false;
};

class BoardLoader {
public:
  static bool load_from_file(
    const std::string & path,
    const cv::Ptr<cv::aruco::Dictionary> & dictionary,
    std::vector<LoadedBoard> & out_boards,
    std::string & error_message);
};

}  // namespace aruco_opencv
