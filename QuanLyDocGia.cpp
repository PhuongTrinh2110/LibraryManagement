#include "ThuVienHam.h"
/*
Các thông tin không được trùng bao gồm: 
- Mã độc giả
- CCCD
*/
/*
Tạo một danh sách độc giả sẵn nhằm dễ dàng thao tác hơn
Danh sách gồm 5 độc giả
*/
void KhoiTaoDanhSachDocGia(int& nReaders, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20])
{
	/*
	nReader: Số lượng độc giả, Code : Mã độc giả, Name : Tên độc giả
	CCCD, Email, Addr, Gender : Số CCCD, email, địa chỉ, giới tính của độc giả,
	bDay, bMonth, bYear : Ngày tháng năm sinh của độc giả
	issueDay, issueMonth, issueYear : Ngày tháng năm lập thẻ mượn sách
	dueDay, dueMonth, dueYear : Ngày tháng năm hết hạn của thẻ mượn sách
	*/
	nReaders = 5;
	char Code_temp[20][20] = {"A0001","A0002","A0003","A0004","A0005"};
	char Name_temp[20][20] = { "Nguyen A", "Hoang Ngoc B", "Le Thi C", "Tran Van D", "Pham Huyen E" };
	unsigned int CCCD_temp[20] = { 12345678, 12345679, 12345680, 12345681, 12345682 };
	char Gender_temp[20][20] = { "Nam", "Nu", "Nam", "Nu", "Nam" };
	char Email_temp[20][20] = { "678@gmail.com", "679@gmail.com", "680@gmail.com", "681@gmail.com", "682@gmail.com" };
	char Addr_temp[20][20] = { "HCM", "Dong Nai", "Ha Noi", "Da Nang", "Nghe An" };
	int bDay_temp[20] = { 1,2,3,4,5 };
	int bMonth_temp[20] = { 1,2,3,4,5 };
	int bYear_temp[20] = { 1990, 1991,1992,1993,1994,1995 };
	int issueDay_temp[20] = { 5,2,1,20,30 };
	int issueMonth_temp[20] = { 2, 3 ,5 ,12,9 };
	int issueYear_temp[20] = { 2021,2025,2022,2025,2024 };
	for (int i = 0; i < nReaders; i++)
	{
		strcpy_s(Code[i], Code_temp[i]);
		strcpy_s(Name[i], Name_temp[i]);
		CCCD[i] = CCCD_temp[i];
		strcpy_s(Gender[i], Gender_temp[i]);
		strcpy_s(Email[i], Email_temp[i]);
		strcpy_s(Addr[i], Addr_temp[i]);
		bDay[i] = bDay_temp[i];
		bMonth[i] = bMonth_temp[i];
		bYear[i] = bYear_temp[i];
		issueDay[i] = issueDay_temp[i];
		issueMonth[i] = issueMonth_temp[i];
		issueYear[i] = issueYear_temp[i];
	}
	for (int i = 0; i < nReaders; i++)
	{
		dueDay[i] = issueDay[i];
		dueMonth[i] = issueMonth[i];
		dueYear[i] = issueYear[i] + 4;
	}
}
/*
Hàm hiển thị danh sách độc giả hiện có
n: Số lượng độc giả, Code: Mã độc giả, Name: Tên độc giả
CCCD, Email, Addr, Gender: Số CCCD, email, địa chỉ, giới tính của độc giả, 
bDay, bMonth, bYear: Ngày tháng năm sinh của độc giả
issueDay, issueMonth, issueYear: Ngày tháng năm lập thẻ mượn sách
dueDay, dueMonth, dueYear: Ngày tháng năm hết hạn của thẻ mượn sách
*/
void XemDanhSachDocGia(int n, char Code[20][20], char Name[20][20],unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20],char Gender[20][20], char Email[20][20], char Addr[20][20],int issueDay[20], int issueMonth[20], int issueYear[20],int dueDay[20], int dueMonth[20], int dueYear[20])
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("------------------------DANH SACH DOC GIA---------------------\n");
	printf("STT  Code\t Name  \t\t\tCCCD\t      Birthday\t   Gender   Email\t\t  Address\t\tIssue Day\tDue Day\n");
	for (int i = 0; i < n; i++)
	{
		int no = i + 1;
		printf("%-5d%-12s%-23s%-14u%02d/%02d/%04d   %-9s% -22s% -20s %02d/%02d/%04d\t%02d/%02d/%04d\n",
			no, Code[i], Name[i], CCCD[i], bDay[i], bMonth[i], bYear[i], Gender[i], Email[i], Addr[i], 
			issueDay[i], issueMonth[i], issueYear[i], dueDay[i], dueMonth[i], dueYear[i]);
	}
}
/*
Thêm 1 độc giả mới vào danh sách độc giả đang có
n: Số lượng độc giả, Code: Mã độc giả, Name: Tên độc giả
CCCD, Email, Addr, Gender: Số CCCD, email, địa chỉ, giới tính của độc giả,
bDay, bMonth, bYear: Ngày tháng năm sinh của độc giả
issueDay, issueMonth, issueYear: Ngày tháng năm lập thẻ mượn sách
dueDay, dueMonth, dueYear: Ngày tháng năm hết hạn của thẻ mượn sách
Quy ước: Thẻ mượn sách có thời hạn 4 năm.
*/
void ThemDocGia(int& n, char Code[20][20], char Name[20][20],unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20],char Gender[20][20], char Email[20][20], char Addr[20][20],int issueDay[20], int issueMonth[20], int issueYear[20],int dueDay[20], int dueMonth[20], int dueYear[20])
{
	n += 1;
	printf("Doc gia STT %d trong danh sach\n", n);
	printf("Nhap ma doc gia AXXXX, voi XXXX la STT doc gia (VD: A0001): ");
	scanf_s("%s", Code[n - 1], 20);
	while (!KiemTraCodeTrung(Code, n, n-1))
	{
		printf("Ma doc gia da ton tai\n");
		printf("Nhap lai ma doc gia (VD: A0001): ");
		scanf_s("%s", Code[n - 1], 20);
	}
	printf("Nhap ten doc gia (VD: Phuong Trinh): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Name[n - 1], 20);
	printf("Nhap CCCD (VD: 12345678): ");
	while (getchar() != '\n');
	scanf_s("%u", &CCCD[n - 1]);
	while (!KiemTraCCCDTrung(CCCD, n, n-1))
	{
		printf("CCCD da ton tai\n");
		printf("Nhap lai CCCD (VD: 12345678): ");
		while (getchar() != '\n');
		scanf_s("%u", &CCCD[n - 1]);
	}
	printf("Nhap ngay thang nam sinh\n");
	NhapNgayThangNam(bDay[n - 1], bMonth[n - 1], bYear[n - 1]);
	while (getchar() != '\n');
	printf("Nhap gioi tinh Nam/Nu/KXD (Khong xac dinh): ");
	scanf_s("%[^\n]", Gender[n - 1], 20);
	printf("Nhap email: ");
	scanf_s("%s", Email[n - 1], 20);
	printf("Nhap dia chi (VD: TP HCM): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Addr[n - 1], 20);
	printf("Nhap ngay tao the muon sach\n");
	NhapNgayThangNam(issueDay[n - 1], issueMonth[n - 1], issueYear[n - 1]);
	dueDay[n - 1] = issueDay[n - 1];
	dueMonth[n - 1] = issueMonth[n - 1];
	dueYear[n - 1] = issueYear[n - 1] + 4;
	while (getchar() != '\n');
	printf("\nDa luu thong tin %s thanh cong\n", Name[n - 1]);
}
/*
Hàm chỉnh sửa thông tin độc giả
n: Số lượng độc giả, Code: Mã độc giả, Name: Tên độc giả
CCCD, Email, Addr, Gender: Số CCCD, email, địa chỉ, giới tính của độc giả,
bDay, bMonth, bYear: Ngày tháng năm sinh của độc giả
issueDay, issueMonth, issueYear: Ngày tháng năm lập thẻ mượn sách
dueDay, dueMonth, dueYear: Ngày tháng năm hết hạn của thẻ mượn sách
Quy ước: Thẻ mượn sách có thời hạn 4 năm.
*/
void ChinhSuaThongTinDocGia(int& nReaders, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20])
{
	int Choice;
	char Name_looking[20];
	char Code_looking[20];
	int Vitri, x;
	//Bước 1: Tìm độc giả theo tên
	printf("Nhap ten doc gia can chinh sua (VD: Nguyen A): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Name_looking, 20);
	x = DemSoDocGiaTheoTen(nReaders, Name, Name_looking);
	while (x == 0)
	{
		printf("Ten doc gia khong ton tai!\n");
		printf("1. Nhap lai ten doc gia\n");
		printf("2. Thoat chuong trinh chinh sua\n");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			printf("Nhap lai ten doc gia can chinh sua: ");
			while (getchar() != '\n');
			scanf_s("%[^\n]", Name_looking, 20);
			x = DemSoDocGiaTheoTen(nReaders, Name, Name_looking);
			break;
		case 2:
			printf("Thoat chuong trinh chinh sua danh sach doc gia\n");
			x = -1;
			break;
		default:
			printf("Yeu cau khong hop le!\n");
			x = -1;
			break;
		}
	}
	if (x > 0)
	{
		XemDanhSachDocGiaTheoTen(nReaders, x, Code, Name, Name_looking, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
		//Bước 2: Từ thông tin hiển thị, nhập mã độc giả
		printf("Nhap ma doc gia can chinh sua (VD: A0001): ");
		while (getchar() != '\n');
		scanf_s("%s", Code_looking, 20);
		//Bước 3: Tìm vị trí của mã độc giả đó trong mảng độc giả Code[20][20]
		Vitri = TimVitriMaDocGia(nReaders, Code, Code_looking);
		while (Vitri == -1)
		{
			printf("Ban nhap sai ma doc gia!\n");
			printf("1. Nhap lai ma doc gia\n");
			printf("2. Thoat chuong trinh chinh sua\n");
			printf("Vui long lua chon: ");
			scanf_s("%d", &Choice);
			switch (Choice)
			{
			case 1:
				printf("Nhap ma doc gia can chinh sua: ");
				while (getchar() != '\n');
				scanf_s("%s", Code_looking, 20);
				Vitri = TimVitriMaDocGia(nReaders, Code, Code_looking);
				break;
			case 2:
				printf("Thoat chuong trinh chinh sua thong tin doc gia!\n");
				Vitri = -2;
				break;
			default:
				printf("Yeu cau khong hop le!\n");
				printf("Thoat chuong trinh chinh sua thong tin doc gia!\n");
				Vitri = -2;
				break;
			}
		}
		if (Vitri >= 0)
		{
			//Bước 4: Lựa chọn thông tin cần chỉnh sửa
			printf("Ban muon chinh sua thong tin gi?\n");
			printf("1. Ma doc gia\n");
			printf("2. Ten doc gia\n");
			printf("3. CCCD\n");
			printf("4. Ngay/Thang/Nam sinh\n");
			printf("5. Gioi tinh\n");
			printf("6. Dia chi Email\n");
			printf("7. Dia chi cho o\n");
			printf("8. Ngay phat hanh the\n");
			printf("Nhap vao lua chon: ");
			scanf_s("%d", &Choice);
			switch (Choice)
			{
			case 1:
				ChinhSuaMaDocGia(Code, Vitri, nReaders);
				break;
			case 2:
				ChinhSuaTenDocGia(Name, Vitri, nReaders);
				break;
			case 3:
				ChinhSuaCCCD(CCCD, Vitri, nReaders);
				break;
			case 4:
				ChinhSuaBirthday(bDay, bMonth, bYear, Vitri, nReaders);
				break;
			case 5:
				ChinhSuaGioiTinh(Gender, Vitri, nReaders);
				break;
			case 6:
				ChinhSuaEmail(Email, Vitri, nReaders);
				break;
			case 7:
				ChinhSuaAddr(Addr, Vitri, nReaders);
				break;
			case 8:
				ChinhIssueDay(issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear, Vitri, nReaders);
				break;
			default:
				printf("Chuc nang khong hop le!\n");
				break;
			}
		}

	}
}
/*
Hàm xóa thông tin 1 độc giả
n: Số lượng độc giả, Code: Mã độc giả, Name: Tên độc giả
CCCD, Email, Addr, Gender: Số CCCD, email, địa chỉ, giới tính của độc giả,
bDay, bMonth, bYear: Ngày tháng năm sinh của độc giả
issueDay, issueMonth, issueYear: Ngày tháng năm lập thẻ mượn sách
dueDay, dueMonth, dueYear: Ngày tháng năm hết hạn của thẻ mượn sách
*/
void XoaThongTinDocGia(int& nReaders, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20])
{
	char Code_looking[20];
	//Bước 1: Tìm độc giả cần xóa theo tên
	TimDocGiaTheoTen(nReaders, Code, Name, CCCD, bDay, bMonth, bYear, Gender, Email, Addr, issueDay, issueMonth, issueYear, dueDay, dueMonth, dueYear);
	//Bước 2: Tìm độc giả theo mã độc giả Code
	printf("Co doc gia can xoa trong danh sach khong?\n");
	printf("1. Co\t\t2. Khong\n");
	printf("Nhap lua chon: ");
	int Choice;
	scanf_s("%d", &Choice);
	int Vitri = -1;
	switch (Choice)
	{
	case 1:
		printf("Nhap ma doc gia can xoa: ");
		while (getchar() != '\n');
		scanf_s("%s", Code_looking, 20);
		Vitri = TimVitriMaDocGia(nReaders, Code, Code_looking);
		while (Vitri == -1)
		{
			printf("Nhap lai ma doc gia can xoa: ");
			while (getchar() != '\n');
			scanf_s("%s", Code_looking, 20);
			Vitri = TimVitriMaDocGia(nReaders, Code, Code_looking);
		}
		//Bước 3: Tiến hành xóa
		nReaders -= 1;
		XoaMangString(Code, Vitri, nReaders);
		XoaMangString(Name, Vitri, nReaders);
		XoaMangSoNguyenDuong(CCCD, Vitri, nReaders);
		XoaMangSoNguyen(bDay, Vitri, nReaders);
		XoaMangSoNguyen(bMonth, Vitri, nReaders);
		XoaMangSoNguyen(bYear, Vitri, nReaders);
		XoaMangString(Gender, Vitri, nReaders);
		XoaMangString(Email, Vitri, nReaders);
		XoaMangString(Addr, Vitri, nReaders);
		XoaMangSoNguyen(issueDay, Vitri, nReaders);
		XoaMangSoNguyen(issueMonth, Vitri, nReaders);
		XoaMangSoNguyen(issueYear, Vitri, nReaders);
		XoaMangSoNguyen(dueDay, Vitri, nReaders);
		XoaMangSoNguyen(dueMonth, Vitri, nReaders);
		XoaMangSoNguyen(dueYear, Vitri, nReaders);
		//Bước 4: Thông báo
		printf("Da xoa thanh cong!\n");
		break;
	case 2:
		printf("Da dong chuc nang xoa!\n");
		break;
	default:
		printf("Yeu cau khong hop le!\n");
		break;
	}
}
/*
Hàm chỉnh sửa mã độc giả Code
- nReaders: Số lượng độc giả hiện có trong danh sách
- Code[20][20]: Mảng chứa các mã độc giả
- Vitri: Vị trí mã độc giả cần chỉnh sửa
*/
void ChinhSuaMaDocGia(char Code[20][20], int Vitri, int nReaders)
	{
		//Bước 1: Lưu tạm mã độc giả cũ
		char Code_old[20];
		strcpy_s(Code_old, Code[Vitri]);
		//Bước 2: Nhập mã độc giả mới
		printf("Nhap vao ma doc gia moi: ");
		while (getchar() != '\n');
		scanf_s("%s", Code[Vitri], 20);
		//Kiểm tra mã độc giả trùng
		while (!KiemTraCodeTrung(Code, nReaders, Vitri))
		{
			printf("Ma doc gia da ton tai\n");
			printf("Nhap lai ma doc gia moi: ");
			while (getchar() != '\n');
			scanf_s("%s", Code[Vitri], 20);
		}
		//Bước 3: Thông báo đã sửa đổi
		if (strcmp(Code[Vitri], Code_old) == 0)
			printf("!!!Ma doc gia khong thay doi!!!\n");
		else
			printf("Ma doc gia da thay doi %s => %s\n", Code_old, Code[Vitri]);
	}
/*
Hàm chỉnh sửa tên độc giả
- Name[20][20]: Mảng chứa tên độc giả
- Vitri: Vị trí tên độc giả cần sửa trong mảng độc giả
- nReaders: Số lượng độc giả hiện có
*/
void ChinhSuaTenDocGia(char Name[20][20], int Vitri, int nReaders)
{
	//Bước 1: Lưu tạm tên cũ
	char Name_old[20];
	strcpy_s(Name_old, Name[Vitri]);
	//Bước 2: Nhập vào tên mới
	printf("Ban dang thay doi ten doc gia\n");
	printf("Nhap vao ten moi: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Name[Vitri], 20);
	//Bước 3: Thông báo
	if (strcmp(Name_old, Name[Vitri]) == 0)
		printf("!!! Ten khong thay doi !!!\n");
	else
		printf("Ten doi tu %s => %s\n", Name_old, Name[Vitri]);
}
/*
Hàm chỉnh sửa CCCD
- CCCD[20]: Mảng chứa dữ liệu CCCD
- Vitri: Vị trí của CCCD trong mảng CCCD[20] cần chỉnh sửa
- nReaders: Số độc giả hiện có trong danh sách
*/
void ChinhSuaCCCD(unsigned int CCCD[20], int Vitri, int nReaders)
{
	//Bước 1: Lưu tạm CCCD cũ
	unsigned int CCCD_old = CCCD[Vitri];

	//Bước 2: Nhập vào CCCD mới
	printf("Ban dang chinh sua CCCD\n");
	printf("Nhap vao CCCD moi: ");
	while (getchar() != '\n');
	scanf_s("%u", &CCCD[Vitri]);
	//Kiểm tra CCCD mới có bị trùng không
	while (!KiemTraCCCDTrung(CCCD, nReaders, Vitri))
	{
		printf("CCCD da ton tai\n");
		printf("Nhap lai CCCD moi: ");
		while (getchar() != '\n');
		scanf_s("%u", &CCCD[Vitri]);
	}
	
	//Bước 3: Thông báo thay đổi
	if (CCCD[Vitri] == CCCD_old)
		printf("!!! CCCD khong thay doi !!!\n");
	else
		printf("CCCD da doi tu %u => %u\n", CCCD_old, CCCD[Vitri]);
}
/*
Chỉnh sửa ngày/ tháng/ năm sinh của độc giả
- bDay[20], bMonth[20], bYear[20]: Mảng chứa Ngày Tháng Năm sinh
- Vitri: Vị trí của ngày tháng năm sinh trong mảng Ngày Tháng Năm sinh cần chỉnh sửa
- nReaders: Số lượng độc giả có trong danh sách
*/
void ChinhSuaBirthday(int bDay[20], int bMonth[20], int bYear[20], int Vitri, int nReaders)
{
	//Bước 1: Lưu tạm ngày tháng năm sinh cũ
	int bDay_old = bDay[Vitri];
	int bMonth_old = bMonth[Vitri];
	int bYear_old = bYear[Vitri];
	//Bước 2: Nhập vào ngày tháng năm sinh mới
	printf("Thay doi ngay/thang/nam sinh cua doc gia\n");
	printf("Nhap vao ngay/thang/nam sinh moi\n");
	NhapNgayThangNam(bDay[Vitri], bMonth[Vitri], bYear[Vitri]);
	//Bước 3: Hiển thị thông báo
	if (bDay_old == bDay[Vitri] && bMonth_old == bMonth[Vitri] && bYear_old == bYear[Vitri])
		printf("!!! Ngay thang nam sinh khong thay doi !!!\n");
	else
		printf("Da thay doi Birthday %02d/%02d/%04d => %02d/%02d/%04d\n", bDay_old, bMonth_old, bYear_old, bDay[Vitri], bMonth[Vitri], bYear[Vitri]);
}
/*
Chỉnh sửa giới tính độc giả
- Gender[20][20]: Mảng chứa dữ liệu giới tính độc giả
- Vitri: Vị trí của dữ liệu cần chỉnh sửa trong mảng
- nReaders: Số lượng độc giả trong danh sách hiện có
*/
void ChinhSuaGioiTinh(char Gender[20][20], int Vitri, int nReaders)
{
	//Bước 1: Lưu tạm giới tính cũ
	char Gender_old[20];
	strcpy_s(Gender_old, Gender[Vitri]);
	//Bước 2: Nhập vào giới tính mới
	printf("Nhap vao gioi tinh Nam/Nu/KXD (Khong xac dinh): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Gender[Vitri], 20);
	//Bước 3: Thông báo thay đổi
	if (strcmp(Gender_old, Gender[Vitri]) == 0)
		printf("!!! Gioi tinh khong co thay doi !!!\n");
	else
		printf("Gioi tinh thay doi %s => %s\n", Gender_old, Gender[Vitri]);
}
/*
Chỉnh sửa địa chỉ Email của độc giả
- Email[20][20]: Mảng chứa dữ liệu Email độc giả
- Vitri: Vị trí của dữ liệu Email trong mảng cần chỉnh sửa
- nReaders: Số lượng độc giả hiện có trong danh sách
*/
void ChinhSuaEmail(char Email[20][20], int Vitri, int nReaders)
{
	//Bước 1: Lưu tạm Email cũ
	char Email_old[20];
	strcpy_s(Email_old, Email[Vitri]);
	//Bước 2: Nhập Email mới
	printf("Thay doi Email\n");
	printf("Nhap vao Email moi: ");
	scanf_s("%s", Email[Vitri], 20);
	//Bước 3: Thông báo thay đổi
	if (strcmp(Email_old, Email[Vitri]) == 0)
		printf("!!! Email khong thay doi !!!");
	else
		printf("Email thay doi %s => %s", Email_old, Email[Vitri]);
}
/*
Chỉnh sửa địa chỉ của độc giả
- Addr[20][20]: Mảng chứa dữ liệu địa chỉ của độc giả
- Vitri: Vị trí của dữ liệu địa chỉ trong mảng cần chỉnh sửa
- nReaders: Số lượng đọc giả trong danh sách hiện có
*/
void ChinhSuaAddr(char Addr[20][20], int Vitri, int nReaders)
{
	//Bước 1: Lưu tạm địa chỉ cũ
	char Addr_old[20];
	strcpy_s(Addr_old, Addr[Vitri]);
	//Bước 2: Nhập địa chỉ mới
	printf("Thay doi dia chi\n");
	printf("Nhap dia chi moi: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Addr[Vitri], 20);
	//Bước 3: Thông báo thay đổi
	if (strcmp(Addr_old, Addr[Vitri]) == 0)
		printf("!!! Khong co thay doi dia chi !!!\n");
	else
		printf("Dia chi thay doi %s => %s\n", Addr_old, Addr[Vitri]);
}
/*
Chỉnh sửa ngày tháng năm phát hành thẻ mượn sách
Đồng thời, điều chỉnh ngày tháng năm hết hạn của thẻ
issueDay, issueMonth, issueYear: Ngày tháng năm lập thẻ mượn sách
dueDay, dueMonth, dueYear: Ngày tháng năm hết hạn của thẻ mượn sách
Vitri: vị trí của dữ liệu cần sửa đổi trong mảng
nReaders: Số lượng độc giả hiện có trong danh sách
*/
void ChinhIssueDay(int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20], int Vitri, int nReaders)
{
	//Bước 1: Lưu tạm ngày phát hành thẻ cũ
	int issueDay_old = issueDay[Vitri];
	int issueMonth_old = issueMonth[Vitri];
	int issueYear_old = issueYear[Vitri];
	//Bước 2: Nhập ngày phát hành mới
	printf("Nhap ngay/ thang/ nam phat hanh the moi\n");
	NhapNgayThangNam(issueDay[Vitri], issueMonth[Vitri], issueYear[Vitri]);
	dueDay[Vitri] = issueDay[Vitri];
	dueMonth[Vitri] = issueMonth[Vitri];
	dueYear[Vitri] = issueYear[Vitri] + 4;
	//Bước 3: Thông báo thay đổi
	if (issueDay_old == issueDay[Vitri] && issueMonth_old == issueMonth[Vitri] && issueYear_old == issueYear[Vitri])
		printf("!!! Khong co thay doi !!!\n");
	else
	{
		printf("Da thay doi thong tin\n");
		printf("Ngay phat hanh %02d/%02d/%04d => %02d/%02d/%04d\n", issueDay_old, issueMonth_old, issueYear_old, issueDay[Vitri], issueMonth[Vitri], issueYear[Vitri]);
		printf("Ngay het han %02d/%02d/%04d\n", dueDay[Vitri], dueMonth[Vitri], dueYear[Vitri]);
	}
}
/*
Kiểm tra số CCCD tai Vitri trong mảng CCCD[20] có trùng hay không
Vitri: vị trí trong mảng chứ số CCCD cần kiểm tra
Hàm hỗ trợ cho hàm ThemDocGia
*/
bool KiemTraCCCDTrung(unsigned int CCCD[20], int nReaders, int Vitri)
{
	for (int i = 0; i < nReaders; i++)
	{
		if (i == Vitri) continue;
		if (CCCD[i] == CCCD[Vitri]) return false;
	}
	return true;
}
/*
Kiểm tra mã số độc giả tại Vitri xem có trùng hay không
Mã độc giả được lưu dạng mảng 2 chiều
- Cột: độ dài mã độc giả
- Dòng: Số lượng mã độc giả
Kiểm tra mã độc giả ở dòng Vitri
*/
bool KiemTraCodeTrung(char Code[20][20], int nReaders, int Vitri)
{
	for (int i = 0; i < nReaders; i++)
	{ 
		if (i == Vitri) continue;
		if (strcmp(Code[i], Code[Vitri])== 0) return false;
	}
	return true;
}
/*
Kiểm tra xem mã số độc giả có tồn tại trong mảng độc giả không?
- Code[20][20]: Mảng chứa dữ liệu mã độc giả
- nReaders: Số lượng độc giả trong mảng hiện có
- Code_looking[20]: Mã độc giả cần kiểm tra xem có tồn tại chưa
*/
bool KiemTraTonTaiCode(char Code[20][20], int nReaders, char Code_looking[20])
{
	for (int i = 0; i < nReaders; i++)
	{
		if (strcmp(Code[i], Code_looking) == 0)
			return true;
	}
	return false;
}
/*
Đếm số độc giả theo tên độc giả (Do tên độc giả có thể trùng)
- nReaders: Số lượng độc giả đang quản lý trong thư viện
- Name[20][20]: Mảng chứa dữ liệu độc giả quản lý
- Name_looking[20]: Dữ liệu tên độc giả cần đếm
Trả về số lượng độc giả có tên trùng với Name_looking
*/
int DemSoDocGiaTheoTen(int nReaders, char Name[20][20], char Name_looking[20])
{
	int Kq = 0;
	for (int i = 0; i < nReaders; i++)
	{
		if (strcmp(Name[i], Name_looking) == 0)
			Kq++;
	}
	return Kq;
}
/*
Xem danh sách độc giả hiển thị theo tên Name_looking
nReaders: Số lượng độc giả đang quản lý
n: Số lượng độc giả trùng tên, Code: Mã độc giả, Name: Tên độc giả
CCCD, Email, Addr, Gender: Số CCCD, email, địa chỉ, giới tính của độc giả,
bDay, bMonth, bYear: Ngày tháng năm sinh của độc giả
issueDay, issueMonth, issueYear: Ngày tháng năm lập thẻ mượn sách
dueDay, dueMonth, dueYear: Ngày tháng năm hết hạn của thẻ mượn sách
*/
void XemDanhSachDocGiaTheoTen(int nReaders, int n, char Code[20][20], char Name[20][20], char Name_looking[20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20])
{
	int vitri[20];
	int count = 0;
	for (int i = 0; i < nReaders; i++)
	{
		if (strcmp(Name[i], Name_looking) == 0)
		{
			vitri[count] = i;
			count++;
		}
	}
	printf("Co %d ket qua trung khop\n", count);
	printf("-----------------------DANH SACH KET QUA----------------------\n");
	printf("STT  Code\t Name  \t\t\tCCCD\t      Birthday\t   Gender   Email\t\t  Address\t\t\tIssue Day\tDue Day\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-5d%-12s%-23s%-14u%02d/%02d/%04d   %-9s% -22s% -20s %02d/%02d/%04d\t%02d/%02d/%04d\n",
			vitri[i] + 1, Code[vitri[i]], Name[vitri[i]], CCCD[vitri[i]], bDay[vitri[i]], bMonth[vitri[i]], bYear[vitri[i]], Gender[vitri[i]], Email[vitri[i]], Addr[vitri[i]],
			issueDay[vitri[i]], issueMonth[vitri[i]], issueYear[vitri[i]], dueDay[vitri[i]], dueMonth[vitri[i]], dueYear[vitri[i]]);
	}
}
/*
Tìm vị trí của số CCCD n trong mảng CCCD[20]
- n: Số CCCD cần tìm
- nReaders: Số độc giả hiện có trong mảng
- Hàm trả về vị trí của CCCD cần tìm trong mảng CCCD[20]
- Nếu không tìm thấy giá trị trả về -1
*/
int TimVitriCCCD(unsigned int CCCD[20], int nReaders, unsigned int n)
{
	for (int i = 0; i < nReaders; i++)
	{
		if (CCCD[i] == n) return i;
	}
	return -1;
}
/*
Tìm độc giả theo CCCD
Trả về các thông tin độc giả đã lưu
n: Số lượng độc giả, Code: Mã độc giả, Name: Tên độc giả
CCCD, Email, Addr, Gender: Số CCCD, email, địa chỉ, giới tính của độc giả,
bDay, bMonth, bYear: Ngày tháng năm sinh của độc giả
issueDay, issueMonth, issueYear: Ngày tháng năm lập thẻ mượn sách
dueDay, dueMonth, dueYear: Ngày tháng năm hết hạn của thẻ mượn sách
*/
void TimDocGiaTheoCCCD(int& n, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20])
{
	int CCCD_Lookup;
	printf("Nhap so CCCD can tim (VD:12345678): ");
	scanf_s("%d", &CCCD_Lookup);
	int i = TimVitriCCCD(CCCD, n, CCCD_Lookup);
	if (i == -1)
	{
		printf("CCCD khong ton tai/ khong hop le\n");
	}
	else
	{
		printf("-----------------------DANH SACH KET QUA----------------------\n");
		printf("STT  Code\t Name  \t\t\tCCCD\t      Birthday\t   Gender   Email\t\t  Address\t\t\tIssue Day\tDue Day\n");
		printf("%-5d%-12s%-23s%-14u%02d/%02d/%04d   %-9s% -22s% -20s %02d/%02d/%04d\t%02d/%02d/%04d\n",
			i+1, Code[i], Name[i], CCCD[i], bDay[i], bMonth[i], bYear[i], Gender[i], Email[i], Addr[i],
			issueDay[i], issueMonth[i], issueYear[i], dueDay[i], dueMonth[i], dueYear[i]);
	}
}
/*
Tìm độc giả theo tên
Do tên độc giả có thể trùng nên có thể hiển thị nhiều hơn 1 độc giả
n: Số lượng độc giả, Code: Mã độc giả, Name: Tên độc giả
CCCD, Email, Addr, Gender: Số CCCD, email, địa chỉ, giới tính của độc giả,
bDay, bMonth, bYear: Ngày tháng năm sinh của độc giả
issueDay, issueMonth, issueYear: Ngày tháng năm lập thẻ mượn sách
dueDay, dueMonth, dueYear: Ngày tháng năm hết hạn của thẻ mượn sách
*/
void TimDocGiaTheoTen(int& nReaders, char Code[20][20], char Name[20][20], unsigned int CCCD[20], int bDay[20], int bMonth[20], int bYear[20], char Gender[20][20], char Email[20][20], char Addr[20][20], int issueDay[20], int issueMonth[20], int issueYear[20], int dueDay[20], int dueMonth[20], int dueYear[20])
{
	char Name_looking[20];
	int vitri[20];
	int count = 0;
	printf("Nhap vao ten ban (VD: Nguyen A): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Name_looking, 20);
	for (int i = 0; i < nReaders; i++)
	{
		if (strcmp(Name[i], Name_looking) == 0)
		{
			vitri[count] = i;
			count++;
		}
	}
	int Choice = 0;
	while (count == 0)
	{
		printf("Ten khong ton tai hoac khong hop le\n");
		printf("Ban co muon tiep tuc tim ten khong?\n");
		printf("1. Co\t\t2. Khong\n");
		printf("Nhap lua chon: ");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			printf("Nhap lai ten ban (VD: Nguyen A): ");
			while (getchar() != '\n');
			scanf_s("%[^\n]", Name_looking, 20);
			for (int i = 0; i < nReaders; i++)
			{
				if (strcmp(Name[i], Name_looking) == 0)
				{
					vitri[count] = i;
					count++;
				}
			}
			break;
		case 2:
			count = -1;
			break;
		default:
			printf("Lua chon khong hop le!\n");
			break;
		}
	}
	if (count > 0)
	{
		printf("Co %d ket qua trung khop\n", count);
		printf("-----------------------DANH SACH KET QUA----------------------\n");
		printf("STT  Code\t Name  \t\t\tCCCD\t      Birthday\t   Gender   Email\t\t  Address\t\tIssue Day\tDue Day\n");
		for (int i = 0; i < count; i++)
		{
			printf("%-5d%-12s%-23s%-14u%02d/%02d/%04d   %-9s% -22s%-20s %02d/%02d/%04d\t%02d/%02d/%04d\n",
				vitri[i] + 1, Code[vitri[i]], Name[vitri[i]], CCCD[vitri[i]], bDay[vitri[i]], bMonth[vitri[i]], bYear[vitri[i]], Gender[vitri[i]], Email[vitri[i]], Addr[vitri[i]],
				issueDay[vitri[i]], issueMonth[vitri[i]], issueYear[vitri[i]], dueDay[vitri[i]], dueMonth[vitri[i]], dueYear[vitri[i]]);
		}
	}
}
/*
Hàm trả về vị trí của mã độc giả cần tìm trong mảng Code - mã độc giả
- nReaders: Số lượng độc giả hiện có
- Code[20][20]: Mảng chứa mã độc giả
- Code_looking[20]: mã độc giả cần tìm VD A0001)
Nếu không tìm thấy mã độc giả trong mảng thì trả về -1
*/
int TimVitriMaDocGia(int nReaders, char Code[20][20], char Code_looking[20])
{
	for (int i = 0; i < nReaders; i++)
	{
		if (strcmp(Code[i], Code_looking) == 0)
			return i;
	}
	return -1;
}



