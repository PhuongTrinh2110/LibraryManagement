#include "ThuVienHam.h"

int main()
{
	//Bước 0: Nhập vào ngày tháng năm hiện tại
	int currentDay, currentMonth, currentYear;
	printf("CHUONG TRINH QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("Truoc tien, hay nhap vao ngay/ thang/ nam hien tai.\nNhan Enter de bat dau!");
	NhapNgayThangNam(currentDay, currentMonth, currentYear);
	printf("\n--------------------------------------------------------------\n");
	//Bước 1.1: Khai báo các biến liên quan độc giả
	int nReaders;
	char Code[20][20], Name[20][20],  Gender[20][20], Email[20][20], Addr[20][20];
	unsigned int CCCD[20];
	int bDay[20], bMonth[20], bYear[20], issueDay[20], issueMonth[20], issueYear[20], dueDay[20], dueMonth[20], dueYear[20];
	//Bước 1.2: Tạo danh sách sẵn có gồm 5 độc giả
	KhoiTaoDanhSachDocGia(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
	
	//Bước 2.1: Khai báo các biến liên quan sách
	int nBooks;
	char ISBN[20][20], BookName[20][20], Author[20][20], NXB[20][20], Type[20][20];
	int PublishYear[20], QTy[20], allQTy[20];
	unsigned int Price[20];
	//Bước 2.2: Tạo danh sách các sách sẵn có gồm 5 sách
	KhoiTaoListSach(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, QTy, allQTy);
 
	//Bước 3.1: Khai báo các biến liên quan mượn - trả sách
	int nBorrow, nReturn;
	char bCode[20][20], bISBN[20][20], rCode[20][20], rISBN[20][20];
	int borrowDay[20], borrowMonth[20], borrowYear[20], rborrowDay[20], rborrowMonth[20], rborrowYear[20];
	int returnDueDay[20], returnDueMonth[20], returnDueYear[20],rreturnDueDay[20],rreturnDueMonth[20],rreturnDueYear[20];
	int returnActDay[20], returnActMonth[20], returnActYear[20];
	int DelayDay[20];
	unsigned int TotalFine[20];

	//Bước 3.2: Tạo danh sách mượn - trả sách sẵn có
	KhoiTaoDanhSachMuonSach(nBorrow, bCode, bISBN, borrowDay, borrowMonth, borrowYear, returnDueDay, returnDueMonth, returnDueYear);
	KhoiTaoLichSuTraSach(nReturn, rCode, rISBN, rborrowDay, rborrowMonth, rborrowYear, rreturnDueDay, rreturnDueMonth, rreturnDueYear, returnActDay, returnActMonth, returnActYear, DelayDay, TotalFine);
	
	//Choice là số gán với chức năng chọn trong menu
	int Choice = 1;
	MainMenu(Choice);
	while (Choice != 0)
	{
		switch (Choice)
		{
		case 1:
			XemDanhSachDocGia(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
			printf("\n--------------------------------------------------------------\n");
			break;
		case 2:
			MenuChinhSuaListDocGia(Choice);
			switch (Choice)
			{
			case 1: 
				ThemDocGia(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
				break;
			case 2: 
				ChinhSuaThongTinDocGia(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
				break;
			case 3:
				XoaThongTinDocGia(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
				break;
			default:
				printf("Chuc nang khong hop le!\n");
				break;
			}
			break;
		case 3:
			XemListSach(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, QTy);
			printf("\n--------------------------------------------------------------\n");
			break;
		case 4:
			MenuChinhSuaListSach(Choice);
			switch (Choice)
			{
			case 1:
				ThemSach(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, QTy, allQTy);
				break;
			case 2:
				ChinhSuaThongTinSach(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, QTy, allQTy);
				break;
			case 3:
				XoaThongTinSach(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, QTy, allQTy);
				break;
			default:
				printf("Yeu cau khong hop le!\n");
				break;
			}
			break;
		case 5:
			MenuMuonTraSach(Choice);
			switch (Choice)
			{
			case 1:
				LapPhieuMuonSach(nBorrow, nReaders, nBooks, bCode, Code, bISBN, ISBN, borrowDay, borrowMonth, borrowYear, returnDueDay, returnDueMonth, returnDueYear, QTy);
				break;
			case 2:
				LapPhieuTraSach(nBorrow, nReturn, nBooks, bCode, rCode, bISBN, rISBN, ISBN, borrowDay, borrowMonth, borrowYear, returnDueDay, returnDueMonth, returnDueYear, rborrowDay, rborrowMonth, rborrowYear, rreturnDueDay, rreturnDueMonth, rreturnDueYear, returnActDay, returnActMonth, returnActYear, QTy, DelayDay, TotalFine);
				break;
			case 3:
				XemDanhSachMuonSach(nBorrow, bCode, bISBN, borrowDay, borrowMonth, borrowYear, returnDueDay, returnDueMonth, returnDueYear);
				break;
			case 4:
				XemLichSuTraSach(nReturn, rCode, rISBN, rborrowDay, rborrowMonth, rborrowYear, rreturnDueDay, rreturnDueMonth, rreturnDueYear, returnActDay, returnActMonth, returnActYear, DelayDay, TotalFine);
				break;
			case 5:
				BaoMatSach(nBorrow, nReturn, nBooks, bCode, rCode, bISBN, rISBN, ISBN, borrowDay, borrowMonth, borrowYear, returnDueDay, returnDueMonth, returnDueYear, rborrowDay, rborrowMonth, rborrowYear, rreturnDueDay, rreturnDueMonth, rreturnDueYear, returnActDay, returnActMonth, returnActYear, QTy, DelayDay, TotalFine, Price, allQTy);
				break;
			default:
				printf("Yeu cau khong hop le!\n");
				break;
			}
			break;
		case 6:
			MenuThongKeSoLuong(Choice);
			switch (Choice)
			{
			case 1:
				ThongKeSoLuongSachTong(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, allQTy);
				break;
			case 2:
				ThongKeSLTheoTheLoai(nBooks, Type, allQTy);
				break;
			case 3:
				XemDanhSachDocGia(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
				printf("Hien co %d doc gia\n", nReaders);
				break;
			case 4:
				ThongKeSLDGtheoGioiTinh(nReaders, Gender);
				break;
			case 5:
				XemDanhSachMuonSach(nBorrow, bCode, bISBN, borrowDay, borrowMonth, borrowYear, returnDueDay, returnDueMonth, returnDueYear);
				printf("Hien co %d sach duoc muon\n", nBorrow);
				break;
			case 6:
				ThongKeDocGiaTreHan(nBorrow, bCode, bISBN, borrowDay, borrowMonth, borrowYear, returnDueDay, returnDueMonth, returnDueYear, currentDay, currentMonth, currentYear);
				break;
			default:
				printf("Yeu cau khong hop le!\n");
				break;
			}
			break;
		case 7:
			MenuSearch(Choice);
			switch (Choice)
			{
			case 1:
				TimDocGiaTheoCCCD(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
				break;
			case 2:
				TimDocGiaTheoTen(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
				break;
			case 3:
				TimSachTheoISBN(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, QTy);
				break;
			case 4:
				TimSachTheoTen(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, QTy);
				break;
			default:
				printf("Chuc nang khong hop le!\n");
				break;
			}
			break;
		default:
			printf("Chuc nang khong hop le!\n");
			break;
		}
		//Hiển thị chọn chức năng để thực hiện tiếp theo
		printf("\n--------------------------------------------------------------\n");
		printf("0. Thoat chuong trinh\n");
		printf("1. Main Menu\n");
		printf("Chon chuc nang tiep theo: ");
		scanf_s("%d", &Choice);
		if (Choice == 1) MainMenu(Choice);
		else if (Choice == 0) break;
		else
		{
			printf("Yeu cau khong hop le\n");
			break;
		}
	}
	return 0;
}