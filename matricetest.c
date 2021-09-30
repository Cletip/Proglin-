#include "fonction.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void rempliBord(matrice *A)
{
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      if (i == j)
      {
        A->Mat[i][j] = 1;
      }
      else if (i == 0)
      {
        A->Mat[i][j] = pow(2, -(j + 1));
      }
      else if (j == 0)
      {
        A->Mat[i][j] = pow(2, -(i + 1));
      }
      else
      {
        A->Mat[i][j] = 0;
      }
    }
  }
}

void rempliDingDong(matrice *A)
{
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      A->Mat[i][j] = 1 / (2 * (A->largeur - (i + 1) - (j + 1) + 1.5f));
    }
  }
}

void rempliFranc(matrice *A)
{
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      if (i >= j + 2)
      {
        A->Mat[i][j] = 0;
      }
      else
      {
        A->Mat[i][j] = (i > j) ? (j + 1) : (i + 1);
      }
    }
  }
}

void rempliHilbertNeg(matrice *A)
{
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      A->Mat[i][j] = 1 / ((i + 1) + (j + 1) - 1.0f);
    }
  }
}

void rempliHilbertPos(matrice *A)
{
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      A->Mat[i][j] = 1 / ((i + 1) + (j + 1) + 1.0f);
    }
  }
}

void rempliKms(matrice *A)
{
  int p = ((float)rand() / RAND_MAX * 2.0 - 1.0);
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      A->Mat[i][j] = pow(p, abs(i - j));
    }
  }
}

void rempliLehmer(matrice *A)
{
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      if (i <= j)
      {
        A->Mat[i][j] = (i + 1) / (j + 1);
      }
      else
      {
        A->Mat[i][j] = (j + 1) / (i + 1);
      }
    }
  }
}

void rempliLotkin(matrice *A)
{
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      if (i == 1)
      {
        A->Mat[i][j] = 1;
      }
      else
      {
        A->Mat[i][j] = 1 / ((i + 1) + (j + 1) - 1);
      }
    }
  }
}

void rempliMoler(matrice *A)
{
  for (int i = 0; i < A->longueur; i++)
  {
    for (int j = 0; j < A->largeur; j++)
    {
      if (i == j)
      {
        A->Mat[i][j] = (i + 1);
      }
      else
      {
        A->Mat[i][j] = (i > j) ? (j + 1) - 2 : (i + 1) - 2;
      }
    }
  }
}
