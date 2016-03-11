#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

// 3 degree cube has 9 block in 1 face.
#define BLOCKNUM 9
#define FACENUM 6
#define BLOCKPERROW 3

// color of the block
typedef enum { WHITE = 0, YELLOW, BLUE, GREEN, RED, ORANGE } BLOCKCOLOR;
// position of the block: face to cube with UP/DOWN/LEFT/RIGHT/FRONT/BACK
typedef enum { U = 0, D, L, R, F, B } BLOCKPOS;
// x means turn left/right.  y for u/d and z for f/b
typedef enum { X = 0, Y, Z } CUBECOORDINATE;

// use fixed table to do sideblockmove
BLOCKPOS kXcoordMove[4] = {F, U, B, D};
BLOCKPOS kYcoordMove[4] = {F, R, B, L};
BLOCKPOS kZcoordMove[4] = {U, R, D, L};

// USlice means up/down rows in 1 cube face
typedef struct { BLOCKCOLOR row[BLOCKPERROW]; } CubeRow;

// CSlice means middle row in 1 cube face
typedef struct { BLOCKCOLOR column[BLOCKPERROW]; } CubeColumn;

// face means 1 face contains 2 USlice(up/down) and 1 CSlice
typedef struct { BLOCKCOLOR block[BLOCKNUM]; } CubeFace;

// cube is organized by 6 faces.
typedef struct { CubeFace face[FACENUM]; } Cube;

void init_cube(Cube *cube);
void show_cube(Cube *cube);

void showoneface(Cube *cube, BLOCKPOS faceidx);
void showfacename(BLOCKPOS faceidx);
void showblockcolor(BLOCKCOLOR color);

void getrowinface(CubeFace *face, int rowidx, CubeRow *rowinface);
void getcolumninface(CubeFace *face, int columnidx, CubeColumn *columninface);
void setrowinface(CubeFace *face, int rowidx, CubeRow rowinface);
void setcolumninface(CubeFace *face, int columnidx, CubeColumn columninface);

void FaceMove(Cube *cube, BLOCKPOS faceidx, bool isclockwise);
void faceblockmove(CubeFace *face, bool isclockwise);
void sideblockmove(Cube *cube, BLOCKPOS faceidx, bool isclockwise);

// move process always switch 90 dgree
void UpClockwise(Cube *cube);
void UpInvert(Cube *cube); // UpInvertClockWise Move
void DownClockwise(Cube *cube);
void DownInvert(Cube *cube); // UpInvertClockWise Move
void LeftClockwise(Cube *cube);
void LeftInvert(Cube *cube); // UpInvertClockWise Move
void RightClockwise(Cube *cube);
void RightInvert(Cube *cube); // UpInvertClockWise Move
void FrontClockwise(Cube *cube);
void FrontInvert(Cube *cube); // UpInvertClockWise Move
void BackClockwise(Cube *cube);
void BackInvert(Cube *cube); // UpInvertClockWise Move
