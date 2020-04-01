#include <EasyBMP/EasyBMP.h>


BMP cahyo(const char* filename) {
	BMP bmp;
	bmp.ReadFromFile(filename);
	bmp.SetBitDepth(1);

	for (int i = 0; i < bmp.TellHeight; i++) {
		for (int j = 0; j < bmp.TellWidth; j++) {
			int Temp = (int)floor(0.299*bmp(i, j)->Red + 0.587*bmp(i, j)->Green + 0.114*bmp(i, j)->Blue);
			ebmpBYTE TempByte = (ebmpBYTE)Temp;
			bmp(i, j)->Red = TempByte;
			bmp(i, j)->Green = TempByte;
			bmp(i, j)->Blue = TempByte;
		}
	}
	return bmp;
}