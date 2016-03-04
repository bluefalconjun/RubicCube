// for rubic cube.

#include "rubikcube.h"

int main(void) {
  RubikCube *CurCube = calloc(1, sizeof(RubikCube));

  init_cube(CurCube);

  show_cube(CurCube);

  UpClockwise(CurCube);
  show_cube(CurCube);
  free(CurCube);
  return 0;
}

void init_cube(RubikCube *cube) {
  assert(cube != NULL);
  memset(cube, 0, sizeof(RubikCube));

  // use initcolor for fit index
  BLOCKCOLOR initcolor[6];
  initcolor[U] = YELLOW;
  initcolor[D] = WHITE;
  initcolor[L] = BLUE;
  initcolor[R] = GREEN;
  initcolor[F] = ORANGE;
  initcolor[B] = RED;

  int i, k, l;
  for (i = 0; i < 6; i++) {
    cube->face[i].middle.center = initcolor[i];
    for (k = 0; k < 2; k++) {
      cube->face[i].middle.edge[k] = initcolor[i];
      cube->face[i].updown[k].edge = initcolor[i];
      for (l = 0; l < 2; l++) {
        cube->face[i].updown[k].corner[l] = initcolor[i];
      }
    }
  }
  return;
}

void show_cube(RubikCube *cube) {
  assert(cube != NULL);
  int i;
  for (i = 0; i < 6; i++) {
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

void showoneface(RubikCube *cube, BLOCKPOS faceidx) {
  showfacename(faceidx);
  // show block in face from up to down, left to right.
  showblockcolor(cube->face[faceidx].updown[U].corner[U]);
  showblockcolor(cube->face[faceidx].updown[U].edge);
  showblockcolor(cube->face[faceidx].updown[U].corner[D]);
  printf("\n");

  showblockcolor(cube->face[faceidx].middle.edge[U]);
  showblockcolor(cube->face[faceidx].middle.center);
  showblockcolor(cube->face[faceidx].middle.edge[D]);
  printf("\n");

  showblockcolor(cube->face[faceidx].updown[D].corner[U]);
  showblockcolor(cube->face[faceidx].updown[D].edge);
  showblockcolor(cube->face[faceidx].updown[D].corner[D]);
  printf("\n");
}

void UpClockwise(RubikCube *cube) {
#if 0
    // record current cornerblock[faceidx][L], edgeblock[faceidx]
    // cornerblock[faceidx][R]
    BLOCKCOLOR tmpcornerl, tmpedge, tmpcornerr;

    // for upper colums  of face F/L/B/R
    tmpcornerl = cube->cornerblock[F][U][L];
    tmpedge = cube->edgeblock[F][U];
    tmpcornerr = cube->cornerblock[F][U][R];

    cube->cornerblock[F][U][L] = cube->cornerblock[R][U][L];
    cube->edgeblock[F][U] = cube->edgeblock[R][U];
    cube->cornerblock[F][U][R] = cube->cornerblock[R][U][R];

    cube->cornerblock[R][U][L] = cube->cornerblock[B][U][L];
    cube->edgeblock[R][U] = cube->edgeblock[B][U];
    cube->cornerblock[R][U][R] = cube->cornerblock[B][U][R];

    cube->cornerblock[B][U][L] = cube->cornerblock[L][U][L];
    cube->edgeblock[B][U] = cube->edgeblock[L][U];
    cube->cornerblock[B][U][R] = cube->cornerblock[L][U][R];

    cube->cornerblock[L][U][L] = tmpcornerl;
    cube->edgeblock[L][U] = tmpedge;
    cube->cornerblock[L][U][R] = tmpcornerr;

    // for colums of face U
    tmpcornerl = cube->cornerblock[U][D][L];
    tmpedge = cube->edgeblock[U][D];

    cube->cornerblock[U][D][L] = cube->cornerblock[U][D][R];
    cube->edgeblock[U][D] = cube->edgeblock[U][R];

    cube->cornerblock[U][D][R] = cube->cornerblock[U][U][R];
    cube->edgeblock[U][R] = cube->edgeblock[U][U];

    cube->cornerblock[U][U][R] = cube->cornerblock[U][U][L];
    cube->edgeblock[U][U] = cube->edgeblock[U][L];

    cube->cornerblock[U][U][L] = tmpcornerl;
    cube->edgeblock[U][L] = tmpedge;
#endif
  return;
}

void UpInvert(RubikCube *cube) { return; }

void DownClockwise(RubikCube *cube) { return; }

void DownInvert(RubikCube *cube) { return; }

void LeftClockwise(RubikCube *cube) { return; }

void LeftInvert(RubikCube *cube) { return; }

void RightClockwise(RubikCube *cube) { return; }

void RightInvert(RubikCube *cube) { return; }

void FrontClockwise(RubikCube *cube) { return; }

void FrontInvert(RubikCube *cube) { return; }

void BackClockwise(RubikCube *cube) { return; }

void BackInvert(RubikCube *cube) { return; }
