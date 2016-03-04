#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// color of the block
typedef enum { WHITE = 0, YELLOW, BLUE, GREEN, RED, ORANGE } BLOCKCOLOR;
// position of the block: face to cube with UP/DOWN/LEFT/RIGHT/FRONT/BACK
typedef enum { U = 0, D, L, R, F, B } BLOCKPOS;

// USlice means up/down rows in 1 cube face
typedef struct {
  BLOCKCOLOR edge;
  BLOCKCOLOR corner[2];
} USlice;

// CSlice means middle row in 1 cube face
typedef struct {
  BLOCKCOLOR center;
  BLOCKCOLOR edge[2];
} CSlice;

// face means 1 face contains 2 USlice(up/down) and 1 CSlice
typedef struct {
  CSlice middle;
  USlice updown[2];
} CubeFace;

// cube is organized by 6 faces.
typedef struct { CubeFace face[6]; } RubikCube;

void init_cube(RubikCube *cube);
void show_cube(RubikCube *cube);

void showoneface(RubikCube *cube, BLOCKPOS faceidx);
void showfacename(BLOCKPOS faceidx);
void showblockcolor(BLOCKCOLOR color);

// move process always switch 90 dgree
void UpClockwise(RubikCube *cube);
void UpInvert(RubikCube *cube); // UpInvertClockWise Move
void DownClockwise(RubikCube *cube);
void DownInvert(RubikCube *cube); // UpInvertClockWise Move
void LeftClockwise(RubikCube *cube);
void LeftInvert(RubikCube *cube); // UpInvertClockWise Move
void RightClockwise(RubikCube *cube);
void RightInvert(RubikCube *cube); // UpInvertClockWise Move
void FrontClockwise(RubikCube *cube);
void FrontInvert(RubikCube *cube); // UpInvertClockWise Move
void BackClockwise(RubikCube *cube);
void BackInvert(RubikCube *cube); // UpInvertClockWise Move

void SliceMove();
void FaceMove();
