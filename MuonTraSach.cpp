#include "ThuVienHam.h"
/*
Khi lập phiếu mượn sách, sẽ được lưu vào danh sách mượn sách
Khi lập phiếu trả sách, sẽ được xóa khỏi danh sách mượn sách
Như vậy:
- Danh sách mượn sách cho thông tin các sách và độc giả đang mượn sách chưa trả
*/
/*
Khởi tạo danh sách mượn sách sẵn có để dễ dàng thao tác
- nBorrow: Số lượng phiếu mượn sách đã lập
- bCode[20][20]: Mã độc giả mượn sách
- bISBN[20][20]: Mã sách được mượn
- borrowDay[20], borrowMonth[20], borrowYear[20]: Ngày Tháng Năm mượn
- returnDueDay[20], returnDueMonth[20], returnDueYear[20]: Ngày Tháng Năm dự kiến trả
Lưu ý: Ngày trả dự kiến theo quy định là +7 ngày từ ngày mượn. VD mượn ngày 1 thì trả ngày 8.
*/
void KhoiTaoDanhSachMuonSach(int& nBorrow, char bCode[20][20], char bISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20])
{
	char bCode_temp[20][20] = { "A0001", "A0002", "A0001", "A0005", "A0001" };
	char bISBN_temp[20][20] = { "I0002", "I0003", "I0001", "I0001", "I0003" };
	int borrowDay_temp[20] = { 30, 29, 5, 6, 7 };
	int borrowMonth_temp[20] = { 9, 10, 11, 11, 11 };
	int borrowYear_temp[20] = { 2025, 2025, 2025, 2025, 2025 };

	nBorrow = 5;
	for (int i = 0; i < nBorrow; i++)
	{
		strcpy_s(bCode[i], bCode_temp[i]);
		strcpy_s(bISBN[i], bISBN_temp[i]);
		borrowDay[i] = borrowDay_temp[i];
		borrowMonth[i] = borrowMonth_temp[i];
		borrowYear[i] = borrowYear_temp[i];
		returnDueDay[i] = borrowDay_temp[i];
		returnDueMonth[i] = borrowMonth_temp[i];
		returnDueYear[i] = borrowYear_temp[i];
		CongNgayThangNam(returnDueDay[i], returnDueMonth[i], returnDueYear[i], 7);
	}
}
/*
Khởi tạo lịch sử trả sách sẵn có
nBorrow/nReturn/nBooks: số lượng sách đang mượn, số lượng đã trả, số ISBN sách quản lý
ISBN[20][20]: Mảng chứa ISBN của thư viện
bCode[20][20], bISBN[20][20]: Mảng Mã độc giả và mã sách trong danh sách mượn
rCode[20][20], rISBN[20][20]: Mảng mã độc giả và mã sách trong danh sách trả
borrowDay[20], borrowMonth[20], borrowYear[20]: Ngày mượn
returnDueDay[20], returnDueMonth[20], returnDueYear[20]: Hạn trả
rborrowDay[20], rborrowMonth[20], rborrowYear[20]: Ngày mượn chép vào danh sách lịch sử trả sách
rreturnDueDay[20], rreturnDueMonth[20], rreturnDueYear[20]: Hạn trả chép vào danh sách lịch sử trả sách
returnActDay[20], returnActMonth[20], returnActYear[20]: Ngày trả sách thật
QTy[20]: Số lượng của ISBN đó trong thư viện
DelayDay[20]: Ngày trễ
TotalFine[20] Số tiền bị phạt
*/
void KhoiTaoLichSuTraSach(int& nReturn, char rCode[20][20], char rISBN[20][20], int rborrowDay[20], int rborrowMonth[20], int rborrowYear[20], int rreturnDueDay[20], int rreturnDueMonth[20], int rreturnDueYear[20], int returnActDay[20], int returnActMonth[20], int returnActYear[20], int DelayDay[20], unsigned int TotalFine[20])
{
	nReturn = 5;
	char rCode_temp[20][20] = { "A0003", "A0002", "A0001", "A0001", "A0004" };
	char rISBN_temp[20][20] = { "I0005", "I0004", "I0003", "I0001", "I0001" };
	int rborrowDay_temp[20] = { 31, 5, 9, 20, 1 };
	int rborrowMonth_temp[20] = { 8, 9, 9, 10, 11 };
	int rborrowYear_temp[20] = { 2025, 2025, 2025, 2025, 2025 };
	int returnActDay_temp[20] = { 2, 12, 17, 29, 2 };
	int returnActMonth_temp[20] = { 9, 9, 9, 10, 11 };
	int returnActYear_temp[20] = { 2025, 2025, 2025, 2025, 2025 };
	for (int i = 0; i < nReturn; i++)
	{
		strcpy_s(rCode[i], rCode_temp[i]);
		strcpy_s(rISBN[i], rISBN_temp[i]);
		rborrowDay[i] = rborrowDay_temp[i];
		rborrowMonth[i] = rborrowMonth_temp[i];
		rborrowYear[i] = rborrowYear_temp[i];
		rreturnDueDay[i] = rborrowDay_temp[i];
		rreturnDueMonth[i] = rborrowMonth_temp[i];
		rreturnDueYear[i] = rborrowYear_temp[i];
		CongNgayThangNam(rreturnDueDay[i], rreturnDueMonth[i], rreturnDueYear[i], 7);
		returnActDay[i] = returnActDay_temp[i];
		returnActMonth[i] = returnActMonth_temp[i];
		returnActYear[i] = returnActYear_temp[i];
		DelayDay[i] = TruNgayThangNam(rborrowDay[i], rborrowMonth[i], rborrowYear[i], returnActDay[i], returnActMonth[i], returnActYear[i]) - 7;
		if (DelayDay[i] < 0)
		{
			DelayDay[i] = 0;
		}
		TotalFine[i] = DelayDay[i] * 5000;
	}
}
/*
Xem danh sách sách đang được mượn trong thư viện
- nBorrow: Số lượng phiếu mượn sách đã lập
- bCode[20][20]: Mã độc giả mượn sách
- bISBN[20][20]: Mã sách được mượn
- borrowDay[20], borrowMonth[20], borrowYear[20]: Ngày Tháng Năm mượn
- returnDueDay[20], returnDueMonth[20], returnDueYear[20]: Ngày Tháng Năm dự kiến trả
Lưu ý: Ngày trả dự kiến theo quy định là +7 ngày từ ngày mượn. VD mượn ngày 1 thì trả ngày 8
*/
void XemDanhSachMuonSach(int nBorrow, char bCode[20][20], char bISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20])
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("-------------------DANH SACH DANG MUON SACH-------------------\n");
	printf("STT  Code\t ISBN\t    Ngay muon sach\tNgay du kien tra sach\n");
	for (int i = 0; i < nBorrow; i++)
	{
		printf("%02d   %-10s  %-10s %02d/%02d/%04d\t\t%02d/%02d/%04d\n", i+1,bCode[i], bISBN[i], borrowDay[i], borrowMonth[i], borrowYear[i], returnDueDay[i], returnDueMonth[i], returnDueYear[i]);
	}
}
/*
Xem lịch sử trả sách (Sách đã mượn và được trả rồi)
nBorrow/nReturn/nBooks: số lượng sách đang mượn, số lượng đã trả, số ISBN sách quản lý
ISBN[20][20]: Mảng chứa ISBN của thư viện
bCode[20][20], bISBN[20][20]: Mảng Mã độc giả và mã sách trong danh sách mượn
rCode[20][20], rISBN[20][20]: Mảng mã độc giả và mã sách trong danh sách trả
borrowDay[20], borrowMonth[20], borrowYear[20]: Ngày mượn
returnDueDay[20], returnDueMonth[20], returnDueYear[20]: Hạn trả
rborrowDay[20], rborrowMonth[20], rborrowYear[20]: Ngày mượn chép vào danh sách lịch sử trả sách
rreturnDueDay[20], rreturnDueMonth[20], rreturnDueYear[20]: Hạn trả chép vào danh sách lịch sử trả sách
returnActDay[20], returnActMonth[20], returnActYear[20]: Ngày trả sách thật
QTy[20]: Số lượng của ISBN đó trong thư viện
DelayDay[20]: Ngày trễ
TotalFine[20] Số tiền bị phạt
*/
void XemLichSuTraSach(int nReturn, char rCode[20][20], char rISBN[20][20], int rborrowDay[20], int rborrowMonth[20], int rborrowYear[20], int rreturnDueDay[20], int rreturnDueMonth[20], int rreturnDueYear[20], int returnActDay[20], int returnActMonth[20], int returnActYear[20], int DelayDay[20], unsigned int TotalFine[20])
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("------------------------LICH SU TRA SACH----------------------\n");
	printf("STT  Code\t ISBN\t    Ngay muon sach\tNgay het han\t Ngay tra sach\t  Ngay tre\tTien phat (VND)\n");
	for (int i = 0; i < nReturn; i++)
	{
		printf("%02d   %-10s  %-10s %02d/%02d/%04d\t\t%02d/%02d/%04d\t %02d/%02d/%04d\t  %-5d\t\t%-10d\n", i +1, rCode[i], rISBN[i], rborrowDay[i], rborrowMonth[i], rborrowYear[i], rreturnDueDay[i], rreturnDueMonth[i], rreturnDueYear[i], returnActDay[i], returnActMonth[i], returnActYear[i], DelayDay[i], TotalFine[i]);
	}
	printf("\n**Luu y: Doc gia tra sach tre hon 1 nam => Mac dinh la 400 ngay, tien phat 2000000VND.\n");
}
/*
Hàm lập phiếu mượn sách (Có thể xem là thêm vào danh sách mượn sách)
- nBorrow: Số lượng phiếu mượn sách đã lập
- nReaders: Số độc giả trong thư viện
- bCode[20][20]: Mảng chứa mã độc giả mượn sách
- Code[20][20]: Mảng chứa mã độc giả trong thư viện
- bISBN[20][20]: Mảng chứa mã sách được mượn
- ISBN[20][20]: Mảng chứa mã sách trong thư viện
- borrowDay[20], borrowMonth[20], borrowYear[20]: Ngày Tháng Năm mượn
- returnDueDay[20], returnDueMonth[20], returnDueYear[20]: Ngày Tháng Năm dự kiến trả
Lưu ý: Ngày trả dự kiến theo quy định là +7 ngày từ ngày mượn.
*/
void LapPhieuMuonSach(int& nBorrow, int nReaders, int nBooks, char bCode[20][20], char Code[20][20], char bISBN[20][20], char ISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20], int QTy[20])
{
	printf("----------------------LAP PHIEU MUON SACH--------------------\n");
	//B1: Nhập mã độc giả, mã sách cần mượn, kiểm tra hợp lệ
	char Code_looking[20];
	char ISBN_looking[20];
	int Vitri;
	printf("Nhap vao ma doc gia (VD: A0001): ");
	while (getchar() != '\n');
	scanf_s("%s", Code_looking, 20);
	int Choice = 0;
	bool x = KiemTraTonTaiCode(Code, nReaders, Code_looking);
	while (x != true)
	{
		printf("Ma doc gia khong ton tai!\n");
		printf("Vui long chon chuc nang tiep theo!\n");
		printf("1. Nhap lai ma doc gia\n");
		printf("2. Thoat chuong trinh\n");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			printf("Nhap lai ma doc gia: ");
			while (getchar() != '\n');
			scanf_s("%s", Code_looking, 20);
			x = KiemTraTonTaiCode(Code, nReaders, Code_looking);
			break;
		case 2:
			printf("Dong chuc nang lap phieu muon sach!\n");
			x = true;
			break;
		default:
			printf("Yeu cau khong hop le!\n");
			x = true;
			break;
		}
	}
	if (KiemTraTonTaiCode(Code, nReaders, Code_looking))
	{
		char ISBN_looking[20];
		printf("Nhap vao ma sach ISBN can muon (VD: I0001): ");
		scanf_s("%s", ISBN_looking, 20);
		x = KiemTraTonTaiISBN(nBooks, ISBN, ISBN_looking);
		while (x != true)
		{
			printf("ISBN khong ton tai!\n");
			printf("Vui long chon chuc nang tiep theo!\n");
			printf("1. Nhap lai ISBN\n");
			printf("2. Thoat chuong trinh\n");
			printf("Lua chon: ");
			scanf_s("%d", &Choice);
			switch (Choice)
			{
			case 1:
				printf("Nhap lai ISBN: ");
				scanf_s("%s", ISBN_looking, 20);
				x = KiemTraTonTaiISBN(nBooks, ISBN, ISBN_looking);
				break;
			case 2:
				printf("Dong chuc nang lap phieu muon sach!\n");
				x = true;
				break;
			default:
				printf("Yeu cau khong hop le!\n");
				x = true;
				break;
			}
		}
		if (KiemTraTonTaiISBN(nBooks, ISBN, ISBN_looking))
		{
			Vitri = TimVitriISBN(ISBN, ISBN_looking, nBooks);
			if (QTy[Vitri] > 0)
			{
				nBorrow += 1;
				QTy[Vitri] -= 1;
				strcpy_s(bCode[nBorrow - 1], Code_looking);
				strcpy_s(bISBN[nBorrow - 1], ISBN_looking);
				printf("Nhap vao ngay/thang/nam muon sach!\n");
				NhapNgayThangNam(borrowDay[nBorrow - 1], borrowMonth[nBorrow - 1], borrowYear[nBorrow - 1]);
				returnDueDay[nBorrow - 1] = borrowDay[nBorrow - 1];
				returnDueMonth[nBorrow - 1] = borrowMonth[nBorrow - 1];
				returnDueYear[nBorrow - 1] = borrowYear[nBorrow - 1];
				CongNgayThangNam(returnDueDay[nBorrow - 1], returnDueMonth[nBorrow - 1], returnDueYear[nBorrow - 1], 7);
				printf("Da lap phieu muon sach thanh cong!\n");
				printf("Han tra sach %02d/%02d/%04d\nNho tra sach dung han nhe!^^\n", returnDueDay[nBorrow - 1], returnDueMonth[nBorrow - 1], returnDueYear[nBorrow - 1]);
			}
			else
				printf("Sach ban chon hien tai da het!\n");
		}
	}
}
/*
Lập phiếu trả sách: 
- Xóa thông tin trong Danh sách mượn sách
- Thêm thông tin vào danh sách lịch sử trả sách
nBorrow/nReturn/nBooks: số lượng sách đang mượn, số lượng đã trả, số ISBN sách quản lý
ISBN[20][20]: Mảng chứa ISBN của thư viện
bCode[20][20], bISBN[20][20]: Mảng Mã độc giả và mã sách trong danh sách mượn
rCode[20][20], rISBN[20][20]: Mảng mã độc giả và mã sách trong danh sách trả
borrowDay[20], borrowMonth[20], borrowYear[20]: Ngày mượn
returnDueDay[20], returnDueMonth[20], returnDueYear[20]: Hạn trả
rborrowDay[20], rborrowMonth[20], rborrowYear[20]: Ngày mượn chép vào danh sách lịch sử trả sách
rreturnDueDay[20], rreturnDueMonth[20], rreturnDueYear[20]: Hạn trả chép vào danh sách lịch sử trả sách
returnActDay[20], returnActMonth[20], returnActYear[20]: Ngày trả sách thật
QTy[20]: Số lượng của ISBN đó trong thư viện
DelayDay[20]: Ngày trễ
TotalFine[20] Số tiền bị phạt
*/
void LapPhieuTraSach(int& nBorrow, int& nReturn, int nBooks, char bCode[20][20], char rCode[20][20], char bISBN[20][20], char rISBN[20][20], char ISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20], int rborrowDay[20], int rborrowMonth[20], int rborrowYear[20], int rreturnDueDay[20], int rreturnDueMonth[20], int rreturnDueYear[20], int returnActDay[20], int returnActMonth[20], int returnActYear[20], int QTy[20], int DelayDay[20], unsigned int TotalFine[20])
{
	char Code_looking[20];
	char ISBN_looking[20];
	int Vitri, Choice;
	//Bước 1: Tìm thông tin trả sách
	printf("Nhap ma doc gia (VD: A0001): ");
	scanf_s("%s", Code_looking, 20);
	printf("Nhap vao ISBN sach can tra (VD: I0001): ");
	scanf_s("%s", ISBN_looking, 20);
	if (DocGiaCoMuonSach(nBorrow, bCode, bISBN, Code_looking, ISBN_looking))
	{
		printf("\n-------------------LAP PHIEU TRA SACH----------------------\n");
		//Lập danh sách quản lý lịch sử trả sách
		Vitri = TimVitriISBN(ISBN, ISBN_looking, nBooks);
		QTy[Vitri] += 1;
		nReturn += 1;
		Vitri = VitriDocGiavaISBN(nBorrow, bCode, bISBN, Code_looking, ISBN_looking);
		strcpy_s(rCode[nReturn - 1], bCode[Vitri]);
		strcpy_s(rISBN[nReturn - 1], bISBN[Vitri]);
		rborrowDay[nReturn - 1] = borrowDay[Vitri];
		rborrowMonth[nReturn - 1] = borrowMonth[Vitri];
		rborrowYear[nReturn - 1] = borrowYear[Vitri];
		rreturnDueDay[nReturn - 1] = returnDueDay[Vitri];
		rreturnDueMonth[nReturn - 1] = returnDueMonth[Vitri];
		rreturnDueYear[nReturn - 1] = returnDueYear[Vitri];
		//Tính số ngày trễ/ hoặc không trễ
		printf("Nhap vao ngay/thang/nam tra sach!\n");
		NhapNgayThangNam(returnActDay[nReturn - 1], returnActMonth[nReturn - 1], returnActYear[nReturn - 1]);
		DelayDay[nReturn - 1] = TruNgayThangNam(borrowDay[Vitri], borrowMonth[Vitri], borrowYear[Vitri], returnActDay[nReturn - 1], returnActMonth[nReturn - 1], returnActYear[nReturn - 1]) - 7;
		if (DelayDay[nReturn - 1] > 0 && DelayDay[nReturn - 1] <= 358)
		{
			while (DelayDay[nReturn - 1] == 358)
			{
				printf("Ban tre han hon 1 nam hoac nhap sai ngay tra sach!\n");
				printf("Neu ban tra sach tre han hon 1 nam thi phat co dinh 2000000 VND.\n");
				printf("Ban co dong y khong?\n");
				printf("1. OK\n2. Nhap lai ngay tra sach\n3. Thoat chuong trinh tra sach\n");
				scanf_s("%d", &Choice);
				switch (Choice)
				{
				case 1:
					TotalFine[nReturn - 1] = 2000000;
					printf("Ban bi phat %d VND\n", TotalFine[nReturn - 1]);
					DelayDay[nReturn - 1] = 400;
					break;
				case 2:
					printf("Nhap lai ngay/thang/nam tra sach!\n");
					NhapNgayThangNam(returnActDay[nReturn - 1], returnActMonth[nReturn - 1], returnActYear[nReturn - 1]);
					DelayDay[nReturn - 1] = TruNgayThangNam(borrowDay[Vitri], borrowMonth[Vitri], borrowYear[Vitri], returnActDay[nReturn - 1], returnActMonth[nReturn - 1], returnActYear[nReturn - 1]) - 7;
					break;
				case 3: 
					printf("Thoat chuong trinh tra sach!\n");
					DelayDay[nReturn - 1] = 500;
					nReturn -= 1;
					break;
				default:
					printf("Yeu cau khong hop le!\n");
					DelayDay[nReturn - 1] = 500;
					nReturn -= 1;
					break;
				}
			}
			if (DelayDay[nReturn - 1] > 0 && DelayDay[nReturn - 1] < 358)
			{
				printf("Ban tra sach tre %d ngay!\n", DelayDay[nReturn - 1]);
				TotalFine[nReturn - 1] = DelayDay[nReturn - 1] * 5000;
				printf("Ban bi phat %d VND\n", TotalFine[nReturn - 1]);
			}
		}
		else if (DelayDay[nReturn - 1] <= 0)
		{
			printf("Ban tra sach dung han!\n");
			TotalFine[nReturn - 1] = 0;
		}
		//Xóa thông tin mượn sách trong danh sách mượn sách
		if (DelayDay[nReturn - 1] != 500 && DelayDay[nReturn] != 500)
		{
			nBorrow -= 1;
			XoaMangString(bCode, Vitri, nBorrow);
			XoaMangString(bISBN, Vitri, nBorrow);
			XoaMangSoNguyen(borrowDay, Vitri, nBorrow);
			XoaMangSoNguyen(borrowMonth, Vitri, nBorrow);
			XoaMangSoNguyen(borrowYear, Vitri, nBorrow);
			XoaMangSoNguyen(returnDueDay, Vitri, nBorrow);
			XoaMangSoNguyen(returnDueMonth, Vitri, nBorrow);
			XoaMangSoNguyen(returnDueYear, Vitri, nBorrow);
		}
	}
	else
	{
		printf("Thong tin khong trung khop!\n");
		printf("Co the ban da tra sach nay hoac chua muon!\n");
		printf("Vui long xem lai danh sach muon / tra de nhap chinh xac nhe!\n");
	}
}
/*
Hàm báo mất sách
Nội dung sẽ tương tự với hàm lập phiếu trả sách
- Dữ liệu được xóa bên danh sách đang mượn sách
- Dữ liệu được thêm vào danh sách lịch sử trả sách
nBorrow/nReturn/nBooks: số lượng sách đang mượn, số lượng đã trả, số ISBN sách quản lý
ISBN[20][20]: Mảng chứa ISBN của thư viện
bCode[20][20], bISBN[20][20]: Mảng Mã độc giả và mã sách trong danh sách mượn
rCode[20][20], rISBN[20][20]: Mảng mã độc giả và mã sách trong danh sách trả
borrowDay[20], borrowMonth[20], borrowYear[20]: Ngày mượn
returnDueDay[20], returnDueMonth[20], returnDueYear[20]: Hạn trả
rborrowDay[20], rborrowMonth[20], rborrowYear[20]: Ngày mượn chép vào danh sách lịch sử trả sách
rreturnDueDay[20], rreturnDueMonth[20], rreturnDueYear[20]: Hạn trả chép vào danh sách lịch sử trả sách
returnActDay[20], returnActMonth[20], returnActYear[20]: Ngày trả sách thật
QTy[20]: Số lượng của ISBN đó trong thư viện
DelayDay[20]: Ngày trễ
TotalFine[20] Số tiền bị phạt = 200% giá sách
*/
void BaoMatSach(int& nBorrow, int& nReturn, int nBooks, char bCode[20][20], char rCode[20][20], char bISBN[20][20], char rISBN[20][20], char ISBN[20][20], int borrowDay[20], int borrowMonth[20], int borrowYear[20], int returnDueDay[20], int returnDueMonth[20], int returnDueYear[20], int rborrowDay[20], int rborrowMonth[20], int rborrowYear[20], int rreturnDueDay[20], int rreturnDueMonth[20], int rreturnDueYear[20], int returnActDay[20], int returnActMonth[20], int returnActYear[20], int QTy[20], int DelayDay[20], unsigned int TotalFine[20], unsigned int Price[20], int allQTy[20])
{
	char Code_looking[20];
	char ISBN_looking[20];
	int Vitri1, Vitri, Choice;
	//Nhập mã độc giả và mã sách ISBN đã mượn, kiểm tra xem có trong danh sách mượn không?
	printf("Nhap ma doc gia (VD: A0001): ");
	scanf_s("%s", Code_looking, 20);
	printf("Nhap ma sach ISBN (VD: I0002): ");
	scanf_s("%s", ISBN_looking, 20);
	if (DocGiaCoMuonSach(nBorrow, bCode, bISBN, Code_looking, ISBN_looking))
	{
		Vitri1 = TimVitriISBN(ISBN, ISBN_looking, nBooks);
		//Tính số tiền phạt mất sách
		nReturn += 1;
		TotalFine[nReturn - 1] = Price[Vitri1] * 2;
		printf("\n-------------------THONG BAO MAT SACH----------------------\n");
		//Tìm vị trí thông tin mượn sách trong danh sách mượn sách
		Vitri = VitriDocGiavaISBN(nBorrow, bCode, bISBN, Code_looking, ISBN_looking);
		strcpy_s(rCode[nReturn - 1], bCode[Vitri]);
		strcpy_s(rISBN[nReturn - 1], bISBN[Vitri]);
		rborrowDay[nReturn - 1] = borrowDay[Vitri];
		rborrowMonth[nReturn - 1] = borrowMonth[Vitri];
		rborrowYear[nReturn - 1] = borrowYear[Vitri];
		rreturnDueDay[nReturn - 1] = returnDueDay[Vitri];
		rreturnDueMonth[nReturn - 1] = returnDueMonth[Vitri];
		rreturnDueYear[nReturn - 1] = returnDueYear[Vitri];
		//Tính số ngày trễ hạn
		printf("Nhap vao ngay/thang/nam tra sach!\n");
		NhapNgayThangNam(returnActDay[nReturn - 1], returnActMonth[nReturn - 1], returnActYear[nReturn - 1]);
		DelayDay[nReturn - 1] = TruNgayThangNam(borrowDay[Vitri], borrowMonth[Vitri], borrowYear[Vitri], returnActDay[nReturn - 1], returnActMonth[nReturn - 1], returnActYear[nReturn - 1]) - 7;

		if (DelayDay[nReturn - 1] > 0 && DelayDay[nReturn - 1] <= 358)
		{
			while (DelayDay[nReturn - 1] == 358)
			{
				printf("Ban bao mat sach tre han hon 1 nam hoac nhap sai ngay!\n");
				printf("Neu ban bao mat sach tre hon 1 nam thi phat co dinh 2000000 VND.\n");
				printf("Ban co dong y khong?\n");
				printf("1. OK\n2. Nhap lai ngay bao mat sach\n3. Thoat chuong trinh bao mat sach\n");
				scanf_s("%d", &Choice);
				switch (Choice)
				{
				case 1:
					DelayDay[nReturn - 1] = 400;
					TotalFine[nReturn - 1] = 2000000;
					printf("Tien phat tre han la %d VND va tien phat mat sach la %d\n", DelayDay[nReturn - 1] * 5000, TotalFine[nReturn - 1]);
					TotalFine[nReturn - 1] += (DelayDay[nReturn - 1] * 5000);
					printf("Tong tien phat la %d\n", TotalFine[nReturn - 1]);
					break;
				case 2:
					printf("Nhap lai ngay/thang/nam tra sach!\n");
					NhapNgayThangNam(returnActDay[nReturn - 1], returnActMonth[nReturn - 1], returnActYear[nReturn - 1]);
					DelayDay[nReturn - 1] = TruNgayThangNam(borrowDay[Vitri], borrowMonth[Vitri], borrowYear[Vitri], returnActDay[nReturn - 1], returnActMonth[nReturn - 1], returnActYear[nReturn - 1]) - 7;
					break;
				case 3:
					printf("Thoat chuong trinh bao mat sach!\n");
					DelayDay[nReturn - 1] = 500;
					nReturn -= 1;
					break;
				default:
					printf("Yeu cau khong hop le!\n");
					DelayDay[nReturn - 1] = 500;
					nReturn -= 1;
					break;
				}
			}
			if (DelayDay[nReturn - 1] > 0 && DelayDay[nReturn - 1] < 358)
			{
				printf("Ban tra sach tre %d ngay!\n", DelayDay[nReturn - 1]);
				printf("Tien phat tre han la %d VND va tien phat mat sach la %d VND\n", DelayDay[nReturn - 1] * 5000, TotalFine[nReturn - 1]);
				TotalFine[nReturn - 1] += (DelayDay[nReturn - 1] * 5000);
				printf("Tong tien phat la %d VND\n", TotalFine[nReturn - 1]);
			}
		}
		else
		{
			printf("Ban khong bi phat tra sach tre han\n");
			printf("Tong tien phat mat sach la %d\n", TotalFine[nReturn - 1]);
		}
		//Xóa thông tin mượn sách trong danh sách mượn sách
		if (DelayDay[nReturn - 1] != 500 && DelayDay[nReturn] != 500)
		{
			nBorrow -= 1;
			XoaMangString(bCode, Vitri, nBorrow);
			XoaMangString(bISBN, Vitri, nBorrow);
			XoaMangSoNguyen(borrowDay, Vitri, nBorrow);
			XoaMangSoNguyen(borrowMonth, Vitri, nBorrow);
			XoaMangSoNguyen(borrowYear, Vitri, nBorrow);
			XoaMangSoNguyen(returnDueDay, Vitri, nBorrow);
			XoaMangSoNguyen(returnDueMonth, Vitri, nBorrow);
			XoaMangSoNguyen(returnDueYear, Vitri, nBorrow);
			allQTy[Vitri1] -= 1;
		}
	}
	else
	{
		printf("Ban da tra sach nay hoac chua muon sach nay\n");
		printf("Vui long xem lai danh sach muon/ tra de nhap chinh xac!\n");
		printf("Dong chuong trinh bao mat sach\n");
	}
}
/*
Kiểm tra xem độc giả có mã Code có mượn sách mã ISBN đó không?
- bCode[20][20]: Mảng chứa dữ liệu mã độc giả mượn sách
- bISBN[20][20]: Mảng chứa dữ liệu ISBN đã được mượn
- Code_looking[20]: mã độc giả cần dò tìm
- ISBN_looking[20]: ISBN sách cần dò tìm
- nBorrrow: Số lượt mượn sách trong danh sách mượn sách
*/
bool DocGiaCoMuonSach(int nBorrow, char bCode[20][20], char bISBN[20][20], char Code_looking[20], char ISBN_looking[20])
{
	for (int i = 0; i < nBorrow; i++)
	{
		if (strcmp(bCode[i], Code_looking) == 0 && strcmp(bISBN[i], ISBN_looking) == 0)
			return true;
	}
	return false;
}
/*
Hàm trả về vị trí độc giả và ISBN trùng với tìm kiếm trong danh sách mượn sách
- bCode[20][20]: Mảng chứa dữ liệu mã độc giả mượn sách
- bISBN[20][20]: Mảng chứa dữ liệu ISBN đã được mượn
- Code_looking[20]: mã độc giả cần dò tìm
- ISBN_looking[20]: ISBN sách cần dò tìm
- nBorrrow: Số lượt mượn sách trong danh sách mượn sách
*/
int VitriDocGiavaISBN(int nBorrow, char bCode[20][20], char bISBN[20][20], char Code_looking[20], char ISBN_looking[20])
{
	for (int i = 0; i < nBorrow; i++)
	{
		if (strcmp(bCode[i], Code_looking) == 0 && strcmp(bISBN[i], ISBN_looking) == 0)
			return i;
	}
	return -1;
}
