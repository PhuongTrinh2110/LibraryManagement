#include "ThuVienHam.h"
//Nhập ngày/tháng/năm và kiểm tra tính chính xác
void NhapNgayThangNam(int& dd, int& mm, int& yyyy)
{
	while (getchar() != '\n');
	printf("Nhap ngay: ");
	scanf_s("%d", &dd);
	printf("Nhap thang: ");
	scanf_s("%d", &mm);
	printf("Nhap nam: ");
	scanf_s("%d", &yyyy);

	while (dd > SoNgayCuaThang(mm, yyyy) || mm > 12)
	{
		printf("Ngay/Thang/Nam khong hop le\n");
		printf("Vui long nhap lai: ");
		printf("Nhap ngay: ");
		scanf_s("%d", &dd);
		printf("Nhap thang: ");
		scanf_s("%d", &mm);
		printf("Nhap nam: ");
		scanf_s("%d", &yyyy);
	}
}
//Kiểm tra năm yyyy có phải là năm nhuận hay không?
bool NamNhuan(int yyyy)
{
	if ((yyyy % 4 == 0 && yyyy % 100 != 0) || yyyy % 400 == 0) return true;
	return false;
}
//Hàm trả về số ngày max của tháng (ví dụ tháng 12 có 31 ngày)
int SoNgayCuaThang(int mm, int yyyy)
{
	switch (mm)
	{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12: return 31;
	case 4: case 6: case 9: case 11: return 30;
	case 2:
		if (NamNhuan(yyyy)) return 29;
		else return 28;
	}
	return 0;
}
/*
Cộng ngày/tháng/năm với số ngày nhất định nào đó
- dd: Ngày cần cộng
- mm: Tháng cần cộng
- yyyy: Năm cần cộng
- NumberDay: Số ngày cộng vào
*/
void CongNgayThangNam(int& dd, int& mm, int& yyyy, int NumberDay)
{
	dd = dd + NumberDay;
	while (dd > SoNgayCuaThang(mm, yyyy))
	{
		dd = dd - SoNgayCuaThang(mm, yyyy);
		mm += 1;
		if (mm > 12)
		{
			yyyy += 1;
			mm = 1;
		}
	}
}
/*
Hàm trừ 2 ngày/tháng/năm với nhau, trả về số ngày (hiệu của 2 ngày tháng năm)
- dd1, mm1, yyyy1: Ngày Tháng Năm trước - Số trừ
- dd2, mm2, yyyy2: Ngày Tháng Năm sau - Số bị trừ
Trả về hiệu của 2 vế trên
*/
int TruNgayThangNam(int dd1, int mm1, int yyyy1, int dd2, int mm2, int yyyy2)
{
	int Kq = 0;
	while (dd1 != dd2 || mm1 != mm2 || yyyy1 != yyyy2)
	{
		CongNgayThangNam(dd1, mm1, yyyy1, 1);
		Kq += 1;
		if (Kq == 365)
		{
			dd1 = dd2;
			mm1 = mm2;
			yyyy1 = yyyy2;
		}
	}
	return Kq;
}
