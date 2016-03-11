// for rubic cube.

#include "rubikcube.h"

int main(void) {
  Cube *CurCube = calloc(1, sizeof(Cube));

  init_cube(CurCube);

  show_cube(CurCube);

  UpClockwise(CurCube);
  show_cube(CurCube);
  free(CurCube);
  return 0;
}

void init_cube(Cube *cube) {
  assert(cube != NULL);
  memset(cube, 0, sizeof(Cube));

  // use initcolor for fit index
  BLOCKCOLOR initcolor[6];
  initcolor[U] = YELLOW;
  initcolor[D] = WHITE;
  initcolor[L] = BLUE;
  initcolor[R] = GREEN;
  initcolor[F] = ORANGE;
  initcolor[B] = RED;

  int i, j;
  for (i = 0; i < FACENUM; i++) {
    for (j = 0; j < BLOCKNUM; j++) {
      cube->face[i].block[j] = initcolor[i];
    }
  }
  return;
}

void show_cube(Cube *cube) {
  assert(cube != NULL);
  int i;
  for (i = 0; i < FACENUM; i++) {
    showoneface(cube, i);
  }
  return;
}

void showfacename(BLOCKPOS faceidx) {
  switch (faceidx) {
    case U:
      printf("UP:\n");
      break;
    case D:
      printf("DOWN:\n");
      break;
    case L:
      printf("LEFT:\n");
      break;
    case R:
      printf("RIGHT:\n");
      break;
    case F:
      printf("FRONT:\n");
      break;
    case B:
      printf("BACK:\n");
      break;
    default:
      assert(false);
  }
  return;
}
void showblockcolor(BLOCKCOLOR color) {
  switch (color) {
    case WHITE:
      printf("WHITE ");
      break;
    case YELLOW:
      printf("YELLOW ");
      break;
    case GREEN:
      printf("GREEN ");
      break;
    case BLUE:
      printf("BLUE ");
      break;
    case RED:
      printf("RED ");
      break;
    case ORANGE:
      printf("ORANGE ");
      break;
    default:
      assert(false);
  }
  return;
}

void showoneface(Cube *cube, BLOCKPOS faceidx) {
  showfacename(faceidx);

  int i, j;
  CubeRow tmprow;
  for (i = 0; i < BLOCKNUM / BLOCKPERROW; i++) {
    getrowinface(&cube->face[faceidx], i, &tmprow);
    for (j = 0; j < BLOCKPERROW; j++) {
      showblockcolor(tmprow.row[j]);
    }
    printf("\n");
  }
}

void getrowinface(CubeFace *face, int rowidx, CubeRow *rowinface) {
  assert(rowinface != NULL);
  int i;
  for (i = 0; i < BLOCKPERROW; i++) {
    rowinface->row[i] = face->block[rowidx * BLOCKPERROW + i];
  }
  return;
}

void getcolumninface(CubeFace *face, int columnidx, CubeColumn *columninface) {
  assert(columninface != NULL);
  int i;
  for (i = 0; i < BLOCKPERROW; i++) {
    columninface->column[i] = face->block[columnidx + BLOCKPERROW * i];
  }
  return;
}

void setrowinface(CubeFace *face, int rowidx, CubeRow rowinface) {
  int i;
  for (i = 0; i < BLOCKPERROW; i++) {
    face->block[rowidx * BLOCKPERROW + i] = rowinface.row[i];
  }

  return;
}

void setcolumninface(CubeFace *face, int columnidx, CubeColumn columninface) {
  int i;
  for (i = 0; i < BLOCKPERROW; i++) {
    face->block[columnidx + BLOCKPERROW * i] = columninface.column[i];
  }
  return;
}

void FaceMove(Cube *cube, BLOCKPOS faceidx, bool isclockwise) {
  assert(cube != NULL);
  faceblockmove(&cube->face[faceidx], isclockwise);
  sideblockmove(cube, faceidx, isclockwise);
  return;
}

void faceblockmove(CubeFace *face, bool isclockwise) {
  assert(face != NULL);
  int i;
  if (isclockwise) {
    for (i = 0; i < BLOCKNUM; i++) {
    }
  } else {
  }
  return;
}

void sideblockmove(Cube *cube, BLOCKPOS faceidx, bool isclockwise) { return; }

void UpClockwise(Cube *cube) { return; }

void UpInvert(Cube *cube) { return; }

void DownClockwise(Cube *cube) { return; }

void DownInvert(Cube *cube) { return; }

void LeftClockwise(Cube *cube) {
  assert(cube != NULL);

  return;
}

void LeftInvert(Cube *cube) { return; }

void RightClockwise(Cube *cube) { return; }

void RightInvert(Cube *cube) { return; }

void FrontClockwise(Cube *cube) { return; }

void FrontInvert(Cube *cube) { return; }

void BackClockwise(Cube *cube) { return; }

void BackInvert(Cube *cube) { return; }
