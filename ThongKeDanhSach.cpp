#include "ThuVienHam.h"
/*
Thống kê số lượng sách tổng cộng có trong thư viện
Bao gồm các sách được mượn và chưa trả lại
Số sách này đã trừ ra số sách bị báo mất
nBooks: Số mã sách có trong thư viện
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và allQty: Số lượng tổng trong thư viện
*/
void ThongKeSoLuongSachTong(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int allQTy[20])
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("-----------DANH SACH TONG CAC SACH TRONG THU VIEN-------------\n");
	printf("STT  ISBN\tTitle\t\t    Author\t\tNXB\t\t  Publish   Type\t\tPrice\t  QTy\n");
	for (int i = 0; i < nBooks; i++)
	{
		printf("%-4d %-9s  %-20s%-20s%-18s%-8d  %-18s  %-8d  %-3d \n", i + 1, ISBN[i], BookName[i], Author[i], NXB[i], PublishYear[i], Type[i], Price[i], allQTy[i]);
	}
	int Total = TinhTongMangSoNguyen(allQTy, nBooks);
	printf("\nDay la danh sach tong so luong sach trong thu vien quan ly: %d quyen sach\n", Total);
	printf("- Bao gom sach dang duoc muon va chua tra lai\n");
	printf("- Da tru ra so sach bao mat\n");
	printf("\n-------------------------------------------------------------\n");
}
/*
Thống kê số lượng sách theo thể loại
Hiển thị danh sách thể loại và số lượng tương ứng
- nBooks: số ISBN quản lý trong thư viện
- Type[20][20]: Mảng chứa dữ liệu thể loại sách
- allQTy[20]: Mảng chứa dữ liệu số lượng sách theo tưng ISBN
*/
void ThongKeSLTheoTheLoai(int nBooks, char Type[20][20], int allQTy[20])
{
	int count[5] = { 0 };
	char Type_temp[5][20] = {"Giao trinh", "Truyen tranh", "Van hoc", "Khoa hoc", "Khac"};
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < nBooks; j++)
		{
			if (strcmp(Type_temp[i], Type[j]) == 0)
				count[i] += allQTy[j];
		}
	}
	printf("-------------THONG KE SO LUONG THEO THE LOAI SACH-------------\n");
	printf("STT    The loai\t\tSo luong\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%02d     %-20s   %02d\n", i + 1, Type_temp[i], count[i]);
	}
	printf("Thu vien phan loai 5 loai sach, so luong thong ke nhu tren!\n");
}
/*
Thống kê danh sách độc giả theo giới tính
- Nam
- Nữ
- KXD: Không xác định
nReaders: Số lượng độc giả quản lý
Gender[20][20]: Mảng chứa dữ liệu giới tính
*/
void ThongKeSLDGtheoGioiTinh(int nReaders, char Gender[20][20])
{
	int count[3] = { 0 };
	char Gender_temp[3][20] = { "Nam", "Nu", "KXD" };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < nReaders; j++)
		{
			if (strcmp(Gender_temp[i], Gender[j]) == 0)
				count[i] += 1;
		}
	}
	printf("-----------THONG KE SO LUONG DOC GIA THEO GIOI TINH-----------\n");
	printf("STT\t Gioi tinh\t So luong\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%02d\t %-10s\t %02d\n", i + 1, Gender_temp[i], count[i]);
	}
}
/*
Thống kê trong danh sách độc giả đang mượn sách (chưa trả) có ai đang bị trễ hạn không?
- nBorrow: Số lượng phiếu mượn sách đã lập
- bCode[20][20]: Mã độc giả mượn sách
- bISBN[20][20]: Mã sách được mượn
- borrowDay[20], borrowMonth[20], borrowYear[20]: Ngày Tháng Năm mượn
- returnDueDay[20], returnDueMonth[20], returnDueYear[20]: Ngày Tháng Năm dự kiến trả
- currentDay, currentMonth, currentYear: Ngày tháng năm hiện tại
*/
void ThongKeDocGiaTreHan(int nBorrow, char bCode[20][20], char bISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20], int currentDay, int currentMonth, int CurrentYear)
{
	int Number = 0;
	int NgayTre[20];
	printf("Ngay hien tai:  %02d/%02d/%04d\n\n", currentDay, currentMonth, CurrentYear);
	printf("------------------DANH SACH TRE HAN TRA SACH-----------------\n");
	printf("STT   Ma doc gia\tISBN\t   Ngay muon\t   Han tra sach\t   So ngay tre\n");
	for (int i = 0; i < nBorrow; i++)
	{
		if (TruNgayThangNam(borrowDay[i], borrowMonth[i], borrowYear[i], currentDay, currentMonth, CurrentYear) > 7)
		{
			NgayTre[Number] = TruNgayThangNam(borrowDay[i], borrowMonth[i], borrowYear[i], currentDay, currentMonth, CurrentYear) - 7;
			printf("%02d    %-14s    %-10s %02d/%02d/%04d\t   %02d/%02d/%04d\t   %-3d\n", Number + 1, bCode[i], bISBN[i], borrowDay[i], borrowMonth[i], borrowYear[i], returnDueDay[i], returnDueMonth[i], returnDueYear[i], NgayTre[Number]);
			Number += 1;
		}
	}
	printf("\nCo tong cong %d luot muon sach dang bi tre han\n", Number);
}

