#include <iostream>
#include "GridSampler.hpp"
#include "ImageManager.hpp"
#include "FGBGMatte.hpp"
#include "SDL/SDL.h"

#include <eigen3/Eigen/Sparse>

using namespace Eigen;

int main(int argc, char** argv) {
  SDL_Init(SDL_INIT_EVERYTHING);

  ImageManager img("test_img/bee.bmp");
  ImageManager img_guess("test_img/bee_guess.bmp");

  FGBGMatte matte(&img, &img_guess);

  ImageManager matte_img(matte.GetMatte());

  matte_img.SaveTo("test_img/bee_result.bmp");
  return 0;
}
