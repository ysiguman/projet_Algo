/* inclusion des librairies */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _INCL_GUARD
	#define _INCL_GUARD

	#define DIM 1

	int N, K;

	#pragma pack(1)


	//#####################################
	//### STRUCTURE DE L ENTETE DE L IMAGE
	//#####################################
	struct headerImg
	{
		int size;
		int width;
		int height;
		short plans;
		short depth;
		int compr;
		int sizeTotal;
		int hRes;
		int vRes;
		int nbColor;
		int nbColorImp;
	};



	//#####################################
	//### STRUCTURE DE L ENTETE DU FICHIER
	//#####################################
	struct headerFile
	{
		char sign[2];
		int size;
		int reserved;
		int offset;

		struct headerImg img;
	};


	//#####################################
	//### STRUCTURE DES PIXELS
	//#####################################
	typedef struct
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
	//	unsigned char reserved;

	} color;

	typedef struct
	{
		unsigned char b;
		unsigned char g;
		unsigned char r;
		unsigned char reserved;

	} palette;




	//#####################################
	//### FONCTIONS LOCALES
	//#####################################
	// GEstion BMP couleur 2D
	void borderColor (color **tab, const int width, const int heigth);
	color ** readColor (color **tab, const int width, const int heigth, FILE *fichier);
	void writeColor (color **tab, const int width, const int heigth, FILE *fichier);

	// GEstion BMP couleur 1D
	void borderColor1D (color *tab, const int width, const int heigth);
	color * readColor1D (color *tab, const int width, const int heigth, FILE *fichier);
	void writeColor1D (color *tab, const int width, const int heigth, FILE *fichier);

	// GEstion BMP N&B 2D
	void borderBW (unsigned char **tab, const int width, const int heigth);
	unsigned char ** readBW (unsigned char **tab, const int width, const int height, FILE *fichier);
	void writeBW (unsigned char **tab, const int width, const int heigth, FILE *fichier);
	palette ** readPalette (palette **tab, FILE *fichier, int nbColor);
	void writePalette (palette **tab, FILE *fichier);

	// GEstion BMP N&B 1D
	void borderBW1D (unsigned char *tab, const int width, const int heigth);
	unsigned char * readBW1D (unsigned char *tab, const int width, const int height, FILE *fichier);
	void writeBW1D (unsigned char *tab, const int width, const int heigth, FILE *fichier);
	palette * readPalette1D (palette *tab, FILE *fichier, int nbColor);
	void writePalette1D (palette *tab, FILE *fichier);

	// Fonction annexe
	void tab2d(FILE *fichier, FILE *fichierOut, struct headerFile header);
	void tab1d(FILE *fichier, FILE *fichierOut, struct headerFile header);
	void readHeader(struct headerFile *header, FILE *fichier);
	int menu();
#endif