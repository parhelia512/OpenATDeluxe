// EncryptTest.cpp: Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
using namespace std;

/*

int main(int argc, char argv[])
{
	int val = 0xC0CF;

	char filename[100];
	cout << "Enter Filename: " << "\n";
	cin.getline(filename, sizeof(filename));

	//char *endptr;
	//char fileOffsetI[100];
	//cout << "Enter Image Offset: " << "\n";
	//cin.getline(fileOffsetI, sizeof(fileOffsetI));
	//long fileOffset = std::strtol(fileOffsetI, &endptr, 10);

	//char fileSizeI[100];
	//cout << "Enter Image Size: " << "\n";
	//cin.getline(fileSizeI, sizeof(fileSizeI));
	//long fileSize = std::strtol(fileSizeI, &endptr, 10);

	readData(filename);

	system("pause");
	return 0;
}*/
/*

void *ConvertData(GFXLib *gfxLib, void *buffer, __int32 a3, char *data, __int32 a5, __int32 a6, __int32 a7, __int32 a8, __int32 a9){
	__int32 v9; // esi@5
	__int32 v10; // esi@5
	__int32 v11; // esi@5
	void *result; // eax@24
	_BYTE *v13; // ST74_4@28
	__int32 v14; // esi@30
	__int32 v15; // esi@30
	__int32 v16; // esi@30
	__int32 v17; // esi@53
	__int32 v18; // esi@53
	__int32 v19; // esi@53
	__int32 v21; // [sp+20h] [bp-78h]@53
	__int32 l; // [sp+28h] [bp-70h]@53
	__int32 v25; // [sp+34h] [bp-64h]@53
	unsigned __int16 v26; // [sp+38h] [bp-60h]@53
	__int32 v27; // [sp+3Ch] [bp-5Ch]@53
	__int32 j; // [sp+40h] [bp-58h]@40
	__int32 k; // [sp+44h] [bp-54h]@33
	__int32 v30; // [sp+48h] [bp-50h]@30
	char *v31; // [sp+4Ch] [bp-4Ch]@30
	__int32 v33; // [sp+54h] [bp-44h]@30
	unsigned __int16 v34; // [sp+58h] [bp-40h]@30
	__int32 v35; // [sp+5Ch] [bp-3Ch]@30
	__int32 i; // [sp+64h] [bp-34h]@26
	char *v39; // [sp+6Ch] [bp-2Ch]@0 MAPDST
	void *v40; // [sp+70h] [bp-28h]@25 MAPDST
	unsigned __int16 v41; // [sp+74h] [bp-24h]@14
	__int32 m; // [sp+78h] [bp-20h]@12
	__int32 n; // [sp+7Ch] [bp-1Ch]@8
	__int32 v44; // [sp+80h] [bp-18h]@5
	__int16 *v45; // [sp+84h] [bp-14h]@5
	__int32 v47; // [sp+8Ch] [bp-Ch]@5
	__int32 v48; // [sp+90h] [bp-8h]@5
	__int16 v49; // [sp+94h] [bp-4h]@5

	if (a3 != 15 && a3 != 16 || gfxLib->field_3 != 15 && gfxLib->field_3 != 16)
	{
		v40 = ctor_sizeT(4 * a6 * a5);
		switch (a3)
		{
		case 8:
			for (i = 0; i < a6 * a5; ++i)
			{
				*(_BYTE *)v40 = data[3 * *(_BYTE *)buffer + 2];
				v13 = (char *)v40 + 1;
				*v13++ = data[3 * *(_BYTE *)buffer + 1];
				*v13 = data[3 * *(_BYTE *)buffer];
				v40 = v13 + 2;
				buffer = (char *)buffer + 1;
			}
			break;
		case 16:
		case 24:
		case 32:
			v34 = a3 / 8;
			v31 = (char *)buffer;
			v14 = GetHighestSetBit(16711680);
			v35 = v14 - GetHighestSetBit(a7);
			v15 = GetHighestSetBit(65280);
			v33 = v15 - GetHighestSetBit(a8);
			v16 = GetHighestSetBit(255);
			v30 = v16 - GetHighestSetBit(a9);
			if (!v33 || v35 || v30)
			{
				for (j = a6 * a5; j > 0; --j)
				{
					*(_DWORD *)v40 = 0;
					if (v35 >= 0)
						*(_DWORD *)v40 |= ((a7 & *(_DWORD *)v31) << v35) & 0xFF0000;
					else
						*(_DWORD *)v40 |= (((unsigned int)a7 & *(_DWORD *)v31) >> -(char)v35) & 0xFF0000;
					if (v33 >= 0)
						*(_DWORD *)v40 |= ((a8 & *(_DWORD *)v31) << v33) & 0xFF00;
					else
						*(_DWORD *)v40 |= (((unsigned int)a8 & *(_DWORD *)v31) >> -(char)v33) & 0xFF00;
					if (v30 >= 0)
						*(_DWORD *)v40 |= ((a9 & *(_DWORD *)v31) << v30) & 0xFF;
					else
						*(_DWORD *)v40 |= (((unsigned int)a9 & *(_DWORD *)v31) >> -(char)v30) & 0xFF;
					v31 += v34;
					v40 = (char *)v40 + 4;
				}
			}
			else
			{
				for (k = a6 * a5; k > 0; --k)
				{
					*(_DWORD *)v40 = (unsigned __int8)*v31;
					if (v33 >= 0)
						*(_DWORD *)v40 |= ((a8 & *(_DWORD *)v31) << v33) & 0xFF00;
					else
						*(_DWORD *)v40 |= (((unsigned int)a8 & *(_DWORD *)v31) >> -(char)v33) & 0xFF00;
					v31 += v34;
					v40 = (char *)v40 + 4;
				}
			}
			break;
		default:
			break;
		}
		FreeHeap(buffer);
		switch (gfxLib->field_3)
		{
		case 15:
		case 16:
		case 24:
		case 32:
			v26 = (gfxLib->field_3 + 7) / 8;
			v39 = (char *)ctor_sizeT(v26 * a6 * a5);
			memset(v39, 0, v26 * a6 * a5);
			v17 = GetHighestSetBit(gfxLib->field_6);
			v27 = v17 - GetHighestSetBit(16711680);
			v18 = GetHighestSetBit(gfxLib->field_7);
			v25 = v18 - GetHighestSetBit(65280);
			v19 = GetHighestSetBit(gfxLib->field_8);
			v21 = v19 - GetHighestSetBit(255);
			for (l = 0; l < a6 * a5; ++l)
			{
				if (v27 >= 0)
					*(_DWORD *)v39 |= gfxLib->field_6 & ((*(_DWORD *)v40 & 0xFF0000) << v27);
				else
					*(_DWORD *)v39 |= gfxLib->field_6 & ((*(_DWORD *)v40 & 0xFF0000u) >> -(char)v27);
				if (v25 >= 0)
					*(_DWORD *)v39 |= gfxLib->field_7 & ((*(_DWORD *)v40 & 0xFF00) << v25);
				else
					*(_DWORD *)v39 |= gfxLib->field_7 & ((*(_DWORD *)v40 & 0xFF00u) >> -(char)v25);
				if (v21 >= 0)
					*(_DWORD *)v39 |= gfxLib->field_8 & ((*(_DWORD *)v40 & 0xFF) << v21);
				else
					*(_DWORD *)v39 |= gfxLib->field_8 & ((*(_DWORD *)v40 & 0xFFu) >> -(char)v21);
				v39 += v26;
				v40 = (char *)v40 + 4;
			}
			break;
		default:
			break;
		}
		FreeHeap(v40);
		result = v39;
	}
	else
	{
		v45 = (__int16 *)buffer;
		v9 = GetHighestSetBit(gfxLib->field_6);
		v48 = v9 - GetHighestSetBit(a7);
		v10 = GetHighestSetBit(gfxLib->field_7);
		v47 = v10 - GetHighestSetBit(a8);
		v11 = GetHighestSetBit(gfxLib->field_8);
		v44 = v11 - GetHighestSetBit(a9);
		v49 = (LOWORD(gfxLib->field_6) | LOWORD(gfxLib->field_7)) & ((a7 | a8) >> 1);
		if (v47 != -1 || v48 != -1 || v44)
		{
			for (m = a6 * a5; m > 0; --m)
			{
				*(_WORD *)buffer = 0;
				v41 = *v45;
				if (v48 >= 0)
					*(_WORD *)buffer |= gfxLib->field_6 & (unsigned __int16)(((unsigned __int16)a7 & v41) << v48);
				else
					*(_WORD *)buffer |= gfxLib->field_6 & (unsigned __int16)((signed int)(unsigned __int16)(a7 & v41) >> -(char)v48);
				if (v47 >= 0)
					*(_WORD *)buffer |= gfxLib->field_7 & (unsigned __int16)(((unsigned __int16)a8 & v41) << v47);
				else
					*(_WORD *)buffer |= gfxLib->field_7 & (unsigned __int16)((signed int)(unsigned __int16)(a8 & v41) >> -(char)v47);
				if (v44 >= 0)
					*(_WORD *)buffer |= gfxLib->field_8 & (unsigned __int16)(((unsigned __int16)a9 & v41) << v44);
				else
					*(_WORD *)buffer |= gfxLib->field_8 & (unsigned __int16)((signed int)(unsigned __int16)(a9 & v41) >> -(char)v44);
				++v45;
				buffer = (char *)buffer + 2;
			}
		}
		else
		{
			for (n = a6 * a5 - 1; n >= 0; --n)
				*((_WORD *)buffer + n) = v49 & ((signed int)*((_WORD *)buffer + n) >> 1) | a9 & *((_WORD *)buffer + n);
		}
		result = buffer;
	}
	return result;
}*/