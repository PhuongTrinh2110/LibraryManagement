#include "ThuVienHam.h"
/*
Hàm xóa 1 dòng trong mảng ký tự (hay mảng chuỗi, với số cột là số ký tự tối đa của 1 chuỗi)
- str[20][20]: Mảng chứa dữ liệu các chuỗi cần xóa
- Vitri: Vị trí chuỗi trong mảng cần xóa
- n: Số lượng dữ liệu tron mảng sau khi đã xóa (nghĩa là -1)
*/
void XoaMangString(char str[20][20], int Vitri, int n)
{
	for (int i = Vitri; i < n; i++)
	{
		strcpy_s(str[i], str[i + 1]);
	}
}
/*
Hàm xóa 1 số nguyên trong mảng số nguyên
- Number[20]: Mảng chứa dữ liệu số nguyên
- Vitri: Vị trí số nguyên trong mảng cần xóa
- n: Số lượng dữ liệu có trong mảng sau khi xóa
*/
void XoaMangSoNguyen(int Number[20], int Vitri, int n)
{
	n = n - 1;
	for (int i = Vitri; i < n; i++)
	{
		Number[i] = Number[i + 1];
	}
}
/*
Hàm xóa số nguyên dương trong mảng số nguyên dương
- Number[20]: Mảng chứa dữ liệu số nguyên dương
- Vitri: Vị trí số nguyên trong mảng cần xóa
- n: Số lượng dữ liệu có trong mảng sau khi xóa
*/
void XoaMangSoNguyenDuong(unsigned int Number[20], int Vitri, int n)
{
	n = n - 1;
	for (int i = Vitri; i < n; i++)
	{
		Number[i] = Number[i + 1];
	}
}
/*
Hàm tính tổng mảng a có n chữ số nguyên
*/
int TinhTongMangSoNguyen(int a[20], int n)
{
	int Kq = 0;
	for (int i = 0; i < n; i++)
	{
		Kq += a[i];
	}
	return Kq;
}
/*
Kiểm tra mảng a và b có giống nhau không?
Giống 100%
*/
bool MangAvaMangBTrungKhop(char a[20], char b[20])
{
	if (strcmp(a, b) == 0)
		return true;
	return false;
}
/*
Kiểm tra xem mảng a có là con của mảng b không
*/
//Đếm số lần xuất hiện của mảng A trong mảng B
int DemSoLanXuatHienATrongB(int a[100], int na, int b[100], int nb)
{
	int sum_count = 0;
	for (int i = 0; i < nb; i++)
	{
		if (b[i] == a[0])
		{
			int count = 0;
			for (int j = 0; j < na; j++)
			{
				if (a[j] == b[i + j]) count++;
			}
			if (count == na) sum_count++;
		}
	}
	return sum_count;
}
//Kiểm tra mảng A có phải là con mảng B hay không
bool MangAlaConMangB(int a[100], int na, int b[100], int nb)
{
	for (int i = 0; i < nb - na + 1; i++)
	{
		if (b[i] == a[0])
		{
			int count = 0;
			for (int j = 0; j < na; j++)
			{
				if (a[j] != b[i + j]) break;
				count++;
			}
			if (count == na) return true;
		}
	}
	return false;
}
