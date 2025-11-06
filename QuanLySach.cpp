#include "ThuVienHam.h"
/*
Các thông tin không được trùng bao gồm:
- Mã sách
*/
/*
Khởi tạo 5 sách có sẵn trong thư viện để dễ dàng chạy thử
nBooks: Số mã sách có trong thư viện
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và Qty: Số lượng hiện có trong thư viện
*/
void KhoiTaoListSach(int& nBooks, char ISBN[20][20], char BookName[20][20],char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20], int allQTy[20])
{
	nBooks = 5;
	char ISBN_temp[20][20] = { "I0001", "I0002", "I0003", "I0004", "I0005" };
	char BookName_temp[20][20] = { "Giai tich 1", "Giai tich 2", "Vat ly 1", "Vat ly 2", "Doraemon" };
	char Author_temp[20][20] = { "Ng Van A", "Ng Van A", "Ng Van B", "Ng Van B", "Fujiko" };
	char NXB_temp[20][20] = { "HCMUT", "HCMUT", "HCMUS", "HCMUS", "Kim Dong" };
	int PublishYear_temp[20] = { 2001, 2001, 2002,2002, 2005 };
	char Type_temp[20][20] = { "Giao trinh", "Giao trinh", "Giao trinh", "Giao trinh", "Truyen tranh" };
	unsigned int Price_temp[20] = { 50000, 50000, 50000, 50000, 20000 };
	int QTy_temp[20] = { 10, 10, 12, 10, 30 };
	int allQTy_temp[20] = { 12, 11, 14, 10, 30 };
	for (int i = 0; i < nBooks; i++)
	{
		strcpy_s(ISBN[i], ISBN_temp[i]);
		strcpy_s(BookName[i], BookName_temp[i]);
		strcpy_s(Author[i], Author_temp[i]);
		strcpy_s(NXB[i], NXB_temp[i]);
		PublishYear[i] = PublishYear_temp[i];
		strcpy_s(Type[i], Type_temp[i]);
		Price[i] = Price_temp[i];
		QTy[i] = QTy_temp[i];
		allQTy[i] = allQTy_temp[i];
	}
}
/*
Hàm xem Danh sách các sách trong thư viện hiện có
nBooks: Số mã sách có trong thư viện
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và Qty: Số lượng hiện có trong thư viện
*/
void XemListSach(int nBooks, char ISBN[20][20], char BookName[20][20],char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20])
{
	printf("QUAN LY THU VIEN TRUONG DAI HOC KHOA HOC TU NHIEN - DHQG TPHCM\n");
	printf("----------DANH SACH CAC SACH HIEN CO TRONG THU VIEN-----------\n");
	printf("STT  ISBN\tTitle\t\t    Author\t\tNXB\t\t  Publish   Type\t\tPrice\t  QTy\n");
	for (int i = 0; i < nBooks; i++)
	{
		printf("%-4d %-9s  %-20s%-20s%-18s%-8d  %-18s  %-8d  %-3d \n", i+1, ISBN[i], BookName[i], Author[i], NXB[i], PublishYear[i], Type[i], Price[i], QTy[i]);
	}
}
/*
Thêm một tên sách mới vào thư viện
nBooks: Số mã sách có trong thư viện
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và Qty: Số lượng hiện có trong thư viện
*/
void ThemSach(int& nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20], int allQTy[20])
{
	nBooks += 1;
	printf("Nhap vao ISBN (VD: I0001): ");
	scanf_s("%s", ISBN[nBooks - 1], 20);
	while (!KiemTraISBN(nBooks, ISBN, nBooks - 1))
	{
		printf("ISBN da ton tai\n");
		printf("Nhap lai ISBN (VD: I0001): ");
		while (getchar() != '\n');
		scanf_s("%s", ISBN[nBooks - 1], 20);
	}
	printf("Nhap vao ten sach (VD: Doraemon): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", BookName[nBooks - 1], 20);
	printf("Nhap vao ten tac gia (VD: Fujiko): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Author[nBooks - 1], 20);
	printf("Nhap Nha Xuat Ban (VD: Kim Dong): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", NXB[nBooks - 1], 20);
	printf("Nhap nam phat hanh (VD: 2007): ");
	while (getchar() != '\n');
	scanf_s("%d", &PublishYear[nBooks - 1]);
	printf("Nhap vao the loai (Giao trinh/ Truyen tranh/ Van hoc/ Khoa hoc/ Khac): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Type[nBooks - 1], 20);
	printf("Nhap vao gia (VND) (VD: 50000): ");
	while (getchar() != '\n');
	scanf_s("%u", &Price[nBooks - 1]);
	printf("Nhap vao so luong (VD: 5): ");
	while (getchar() != '\n');
	scanf_s("%d", &QTy[nBooks - 1]);
	printf("\nDa them sach thanh cong!\n");
	allQTy[nBooks - 1] = QTy[nBooks - 1];
}
/*
Chỉnh sửa thông tin sách
nBooks: Số mã sách có trong thư viện
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và Qty: Số lượng hiện có trong thư viện
*/
void ChinhSuaThongTinSach(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20], int allQTy[20])
{
	int Choice;
	char BookName_looking[20];
	char ISBN_loooking[20];
	int Vitri = -1;
	printf("Nhap ten sach can thay doi thong tin (VD: Doraemon): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", BookName_looking, 20);
	int x = DemSoLuongTheoTenSach(nBooks, BookName, BookName_looking);
	while (x == 0)
	{
		printf("Ten sach khong ton tai! Ban co muon tim lai khong?\n");
		printf("1. Co\n2. Khong\n");
		printf("Lua chon: ");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1: 
			printf("Nhap lai ten sach can thay doi thong tin (VD: Doraemon): ");
			while (getchar() != '\n');
			scanf_s("%[^\n]", BookName_looking, 20);
			x = DemSoLuongTheoTenSach(nBooks, BookName, BookName_looking);
			break;
		case 2:
			printf("Thoat chuong trinh chinh sua sach!\n");
			x = -1;
			break;
		default:
			printf("Yeu cau khong hop le!\n");
			printf("Thoat chuong trinh chinh sua sach!\n");
			x = -1;
			break;
		}
	}
	if (x > 0)
	{
		XemDanhSachTheoTenSach(nBooks, x, ISBN, BookName, BookName_looking, Author, NXB, PublishYear, Type, Price, QTy);
		printf("Nhap ma sach ISBN tuong ung ten sach can chinh sua thong tin: ");
		while (getchar() != '\n');
		scanf_s("%s", ISBN_loooking, 20);
		Vitri = TimVitriISBN(ISBN, ISBN_loooking, nBooks);
		while (Vitri == -1)
		{
			printf("ISBN khong dung, ban co muon nhap lai khong?\n");
			printf("1. Co\n2. Khong\n");
			printf("Lua chon: ");
			scanf_s("%d", &Choice);
			switch (Choice)
			{
			case 1: 
				printf("Nhap ma sach ISBN tuong ung ten sach can chinh sua thong tin: ");
				while (getchar() != '\n');
				scanf_s("%s", ISBN_loooking, 20);
				Vitri = TimVitriISBN(ISBN, ISBN_loooking, nBooks);
				break;
			case 2:
				printf("Thoat chuong trinh chinh sua sach!\n");
				Vitri = -2;
				break;
			default:
				printf("Yeu cau khong hop le!\n");
				printf("Thoat chuong trinh chinh sua sach!\n");
				Vitri = -2;
				break;
			}
		}
		if (Vitri >= 0)
		{
			printf("Chon thong tin can thay doi\n");
			printf("1. Ma sach ISBN\n");
			printf("2. Ten sach\n");
			printf("3. Tac gia\n");
			printf("4. Nha xuat ban\n");
			printf("5. Nam xuat ban Publish Year\n");
			printf("6. The loai\n");
			printf("7. Gia\n");
			printf("8. So luong\n");
			printf("Lua chon: ");
			scanf_s("%d", &Choice);
			switch (Choice)
			{
			case 1:
				ChinhSuaISBN(nBooks, ISBN, Vitri);
				break;
			case 2:
				ChinhSuaTenSach(nBooks, BookName, Vitri);
				break;
			case 3:
				ChinhSuaTacGia(nBooks, Author, Vitri);
				break;
			case 4:
				ChinhSuaNXB(nBooks, NXB, Vitri);
				break;
			case 5:
				ChinhSuaPublishYear(nBooks, PublishYear, Vitri);
				break;
			case 6:
				ChinhSuaTheLoai(nBooks, Type, Vitri);
				break;
			case 7:
				ChinhSuaGia(nBooks, Price, Vitri);
				break;
			case 8:
				ChinhSuaSoLuong(nBooks, QTy, allQTy, Vitri);
				break;
			default:
				printf("Chuc nang khong hop le!\n");
				break;
			}
		}
	}
}
/*
Hàm chỉnh sửa thông tin mã sách
- nBooks: Số lượng sách đang quản lý trong thư viện
- ISBN[20][20]: Mảng chứa dữ liệu mã sách
- Vitri: Vị trí ISBN cần chỉnh sửa trong mảng
*/
void ChinhSuaISBN(int nBooks, char ISBN[20][20], int Vitri)
{
	//Bước 1: Lưu tạm ISBN cũ
	char ISBN_old[20];
	strcpy_s(ISBN_old, ISBN[Vitri]);
	//Bước 2: Nhập ISBN mới
	printf("Thay doi ma sach ISBN\n");
	printf("Nhap ISBN moi: ");
	while (getchar() != '\n');
	scanf_s("%s", ISBN[Vitri], 20);
	while (!KiemTraISBN(nBooks, ISBN, Vitri))
	{
		printf("ISBN da ton tai, vui long nhap lai!\n");
		printf("Nhap lai ISBN moi: ");
		while (getchar() != '\n');
		scanf_s("%s", ISBN[Vitri], 20);
	}
	//Bước 3: Thông báo thay đổi
	if (strcmp(ISBN_old, ISBN[Vitri]) == 0)
		printf("!!! ISBN khong thay doi !!!\n");
	else
		printf("ISBN thay doi %s => %s\n", ISBN_old, ISBN[Vitri]);
}
/*
Chỉnh sửa tên sách
- nBooks: Số sách thư viện đang quản lý
- BookName[20][20]: Mảng chứa dữ liệu tên sách trong thư viện
- Vitri: Vị trí dữ liệu tên sách trong mảng cần chỉnh sửa
*/
void ChinhSuaTenSach(int nBooks, char BookName[20][20], int Vitri)
{
	//Bước 1: Lưu tạm tên sách cũ
	char BookName_old[20];
	strcpy_s(BookName_old, BookName[Vitri]);
	//Bước 2: Nhập vào tên sách mới
	printf("Chinh sua ten sach\n");
	printf("Nhap vao ten sach moi: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", BookName[Vitri], 20);
	//Bước 3: Thông báo thay đổi
	if (strcmp(BookName_old, BookName[Vitri]) == 0)
		printf("!!! Ten sach khong thay doi !!!\n");
	else
		printf("Ten sach thay doi %s => %s\n", BookName_old, BookName[Vitri]);
}
/*
Chỉnh sửa tên tác giả
- nBooks: Số lượng sách đang quản lý trong thư viện
- Author[20][20]: Mảng chứa dữ liệu tác giả của sách
- Vitri: Vị trí dữ liệu cần chỉnh sửa trong mảng tác giả
*/
void ChinhSuaTacGia(int nBooks, char Author[20][20], int Vitri)
{
	//Bước 1: Lưu tạm tên tác giả cũ
	char Author_old[20];
	strcpy_s(Author_old, Author[Vitri]);
	//Bước 2: Nhập tên tác giả mới
	printf("Thay doi ten tac gia\n");
	printf("Nhap ten tac gia moi: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Author[Vitri], 20);
	//Bước 3: Thông báo thay đổi
	if (strcmp(Author_old, Author[Vitri]) == 0)
		printf("!!! Ten tac gia khong thay doi !!!\n");
	else
		printf("Ten tac gia thay doi %s => %s\n", Author_old, Author[Vitri]);
}
/*
Chỉnh sửa thông tin nhà xuất bản của sách
- nBooks: Số lượng sách thư viện đang quản lý
- NXB[20][20]: Mảng chứa dữ liệu nhà xuất bản 
- Vitri: Vị trí dữ liệu cần chỉnh sửa trong mảng NXB
*/
void ChinhSuaNXB(int nBooks, char NXB[20][20], int Vitri)
{
	//Bước 1: Lưu tạm tên nhà xuất bản cũ
	char NXB_old[20];
	strcpy_s(NXB_old, NXB[Vitri]);
	//Bước 2: Nhập thông tin NXB mới
	printf("Thay doi NXB\n");
	printf("Nhap ten NXB moi: ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", NXB[Vitri], 20);
	//Bước 3: Thông báo thay đổi
	if (strcmp(NXB_old, NXB[Vitri]) == 0)
		printf("!!! Nha xuat ban khong thay doi !!!\n");
	else
		printf("NXB thay doi %s => %s\n", NXB_old, NXB[Vitri]);
}
/*
Chỉnh sửa thông tin năm xuất bản
- nBooks: Số lượng sách thư viện đang quản lý
- PublishYear[20]: Mảng chứa dữ liệu năm xuất bản
- Vitri: Vị trí dữ liệu trong mảng cần chỉnh sửa
*/
void ChinhSuaPublishYear(int nBooks, int PublishYear[20], int Vitri)
{
	int PublishYear_old = PublishYear[Vitri];
	printf("Chinh sua nam xuat ban\n");
	printf("Nhap nam xuat ban moi: ");
	scanf_s("%d", &PublishYear[Vitri]);
	if (PublishYear_old == PublishYear[Vitri])
		printf("!!! Nam xuat ban khong thay doi !!!\n");
	else
		printf("Nam xuat ban thay doi %d => %d\n", PublishYear_old, PublishYear[Vitri]);
}
/*
Chỉnh sửa thể loại sách
- nBooks: Số lượng sách thư viện đang quản lý
- Type[20][20]: Mảng chứa dữ liệu thể loại
- Vitri: Vị trí dữ liệu trong mảng cần chỉnh sửa
*/
void ChinhSuaTheLoai(int nBooks, char Type[20][20], int Vitri)
{
	char Type_old[20];
	strcpy_s(Type_old, Type[Vitri]);
	printf("Thay doi the loai sach\n");
	printf("Nhap vao the loai moi (Giao trinh/ Truyen tranh/ Van hoc/ Khoa hoc/ Khac): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", Type[Vitri], 20);
	if (strcmp(Type_old, Type[Vitri]) == 0)
		printf("!!! The loai khong thay doi !!!\n");
	else
		printf("The loai thay doi %s => %s\n", Type_old, Type[Vitri]);
}
/*
Chỉnh sửa giá của sách
- nBooks: Số lượng sách thư viện đang quản lý
- Price[20]: Mảng chứa dữ liệu giá
- Vitri: Vị trí dữ liệu trong mảng cần chỉnh sửa
*/
void ChinhSuaGia(int nBooks, unsigned int Price[20], int Vitri)
{
	unsigned int Price_old = Price[Vitri];
	printf("Thay doi gia cua sach\n");
	printf("Nhap vao gia moi: ");
	scanf_s("%u", &Price[Vitri]);
	if (Price[Vitri] == Price_old)
		printf("!!! Gia sach khong thay doi !!!\n");
	else
		printf("Gia sach thay doi %u => %u\n", Price_old, Price[Vitri]);
}
/*
Chỉnh sửa số lượng của sách
- nBooks: Số lượng sách thư viện đang quản lý
- QTy[20]: Mảng chứa dữ liệu số lượng mỗi tên sách
- Vitri: Vị trí dữ liệu trong mảng cần chỉnh sửa
*/
void ChinhSuaSoLuong(int nBooks, int QTy[20], int allQTy[20], int Vitri)
{
	int QTy_old = QTy[Vitri];
	printf("Thay doi so luong sach\n");
	printf("Nhap vao so luong sach moi: ");
	scanf_s("%d", &QTy[Vitri]);
	if (QTy_old == QTy[Vitri])
		printf("!!! So luong sach khong thay doi !!!\n");
	else
		printf("So luong sach thay doi %d => %d\n", QTy_old, QTy[Vitri]);
	allQTy[Vitri] += QTy[Vitri] - QTy_old;
}
/*
Hàm xóa thông tin 1 tên sách
nBooks: Số mã sách có trong thư viện
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và Qty: Số lượng hiện có trong thư viện
*/
void XoaThongTinSach(int& nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20], int allQTy[20])
{
	int Choice, Vitri;
	char ISBN_looking[20];
	//Bước 1: Nhập tên sách cần xóa để tìm ISBN chính xác của sách cần xóa
	TimSachTheoTen(nBooks, ISBN, BookName, Author, NXB, PublishYear, Type, Price, QTy);
	printf("Co sach can xoa trong danh sach khong?\n");
	printf("1. Co\t\t2. Khong\n");
	printf("Lua chon: ");
	scanf_s("%d", &Choice);
	switch (Choice)
	{
	case 1:
		printf("Nhap vao ISBN cua sach can xoa: ");
		scanf_s("%s", ISBN_looking, 20);
		Vitri = TimVitriISBN(ISBN, ISBN_looking, nBooks);
		if (Vitri >= 0)
		{
			nBooks -= 1;
			XoaMangString(ISBN, Vitri, nBooks);
			XoaMangString(BookName, Vitri, nBooks);
			XoaMangString(Author, Vitri, nBooks);
			XoaMangString(NXB, Vitri, nBooks);
			XoaMangSoNguyen(PublishYear, Vitri, nBooks);
			XoaMangString(Type, Vitri, nBooks);
			XoaMangSoNguyenDuong(Price, Vitri, nBooks);
			XoaMangSoNguyen(QTy, Vitri, nBooks);
			XoaMangSoNguyen(allQTy, Vitri, nBooks);
			printf("Da xoa thanh cong!\n");
			break;
		}
		else
		{
			printf("ISBN khong ton tai hoac khong hop le!\n");
			printf("Dong chuong trinh xoa thong tin sach!\n");
			break;
		}
	case 2:
		printf("Dong chuong trinh xoa thong tin sach!\n");
		break;
	default:
		printf("Yeu cau khong hop le!\n");
		printf("Dong chuong trinh xoa thong tin sach!\n");
		break;
	}
}
/*
Kiểm tra mã sách thêm vào có bị trùng hay không
- nBooks: Số sách (tên sách) có trong thư viện
- ISBN[20][20]: Mảng chứa mã sách
*/
bool KiemTraISBN(int nBooks, char ISBN[20][20], int Vitri)
{
	for (int i = 0; i < nBooks; i++)
	{
		if (i == Vitri) continue;
		if (strcmp(ISBN[i], ISBN[Vitri]) == 0)
			return false;
	}
	return true;
}
/*
Kiểm tra mã sách ISBN có tồn tại trong mảng dữ liệu quản lý sách không?
- nBooks: Số lượng ISBN đang quản lý
- ISBN[20][20]: Mảng chứa dữ liệu mã sách
- ISBN_looking[20]: Mã sách cần kiểm tra
*/
bool KiemTraTonTaiISBN(int nBooks, char ISBN[20][20], char ISBN_looking[20])
{
	for (int i = 0; i < nBooks; i++)
	{
		if (strcmp(ISBN[i], ISBN_looking) == 0)
			return true;
	}
	return false;
}
/*
Đếm số lượng sách theo tên sách
- nBooks: Số lượng ISBN đang quản lý trong thư viện
- BookName[20][20]: Mảng chứa dữ liệu tên sách
- BookName_looking[20]: Dữ liệu tên sách đang cần đếm số lượng
Hàm trả về số lượng sách trùng tên
*/
int DemSoLuongTheoTenSach(int nBooks, char BookName[20][20], char BookName_looking[20])
{
	int Kq = 0;
	for (int i = 0; i < nBooks; i++)
	{
		if (strcmp(BookName[i], BookName_looking) == 0)
			Kq++;
	}
	return Kq;
}
/*
Xem danh sách các sách theo tên sách (Có thể sách tên bị trùng)
nBooks: Số mã sách có trong thư viện
n: Số lượng sách theo tên sách
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
BookName_looking: Tên sách cần hiển thị
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và Qty: Số lượng hiện có trong thư viện
*/
void XemDanhSachTheoTenSach(int nBooks, int n, char ISBN[20][20], char BookName[20][20], char BookName_looking[20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20])
{
	int vitri[10];
	int count = 0;
	for (int i = 0; i < nBooks; i++)
	{
		if (strcmp(BookName[i], BookName_looking) == 0)
		{
			vitri[count] = i;
			count++;
		}
	}
	printf("Co %d ket qua trung khop\n", count);
	printf("----------------------DANH SACH KET QUA-----------------------\n");
	printf("STT  ISBN\tTitle\t\t    Author\t\tNXB\t\t  Publish   Type\t\tPrice\t  QTy\n");
	for (int i = 0; i < count; i++)
	{
		printf("%-4d %-9s  %-20s%-20s%-18s%-8d  %-18s  %-8d  %-3d \n", vitri[i] + 1, ISBN[vitri[i]], BookName[vitri[i]], Author[vitri[i]], NXB[vitri[i]], PublishYear[vitri[i]], Type[vitri[i]], Price[vitri[i]], QTy[vitri[i]]);
	}
}
/*
Tìm sách theo ISBN
nBooks: Số mã sách có trong thư viện
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và Qty: Số lượng hiện có trong thư viện
*/
void TimSachTheoISBN(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20])
{
	char ISBN_looking[20];
	printf("Nhap ISBN cua sach can tim (VD: I0001): ");
	scanf_s("%s", ISBN_looking, 20);
	int i = TimVitriISBN(ISBN, ISBN_looking, nBooks);
	if (i == -1)
	{
		printf("Ma ISBN khong ton tai\n");
	}
	else
	{
		printf("----------------------DANH SACH KET QUA-----------------------\n");
		printf("STT  ISBN\tTitle\t\t    Author\t\tNXB\t\t  Publish   Type\t\tPrice\t  QTy\n");
		printf("%-4d %-9s  %-20s%-20s%-18s%-8d  %-18s  %-8d  %-3d \n", i + 1, ISBN[i], BookName[i], Author[i], NXB[i], PublishYear[i], Type[i], Price[i], QTy[i]);
	}
}
/*
Tìm sách theo tên
nBooks: Số mã sách có trong thư viện
ISBN: Mã sách
BookName: Tên sách, Author: Tác giả của sách
NXB: Nhà xuất bản, PublishYear: Năm xuất bản
Type: Thể loại sách, Price: Giá và Qty: Số lượng hiện có trong thư viện
*/
void TimSachTheoTen(int nBooks, char ISBN[20][20], char BookName[20][20], char Author[20][20], char NXB[20][20], int PublishYear[20], char Type[20][20], unsigned int Price[20], int QTy[20])
{
	char BookName_looking[20];
	int vitri[10];
	int count = 0;
	printf("Nhap vao ten sach can tim (VD: Doraemon): ");
	while (getchar() != '\n');
	scanf_s("%[^\n]", BookName_looking, 20);
	for (int i = 0; i < nBooks; i++)
	{
		if (strcmp(BookName[i], BookName_looking) == 0)
		{
			vitri[count] = i;
			count++;
		}
	}
	int Choice;
	while (count == 0)
	{
		printf("Ten sach khong ton tai\n");
		printf("Co tiep tuc tim kiem khong?\n");
		printf("1. Co\t\t2. Khong\n");
		printf("Lua chon: ");
		scanf_s("%d", &Choice);
		switch (Choice)
		{
		case 1:
			printf("Nhap lai ten sach can tim (VD: Doraemon): ");
			while (getchar() != '\n');
			scanf_s("%[^\n]", BookName_looking, 20);
			for (int i = 0; i < nBooks; i++)
			{
				if (strcmp(BookName[i], BookName_looking) == 0)
				{
					vitri[count] = i;
					count++;
				}
			}
			break;
		case 2:
			printf("Ket thuc tim kiem sach\n");
			count = -1;
			break;
		default:
			printf("Yeu cau khong hop le!\n");
			count = -1;
			break;
		}
	}
	if (count > 0)
	{
		printf("Co %d ket qua trung khop\n", count);
		printf("----------------------DANH SACH KET QUA-----------------------\n");
		printf("STT  ISBN\tTitle\t\t    Author\t\tNXB\t\t  Publish   Type\t\tPrice\t  QTy\n");
		for (int i = 0; i < count; i++)
		{
			printf("%-4d %-9s  %-20s%-20s%-18s%-8d  %-18s  %-8d  %-3d \n", vitri[i] + 1, ISBN[vitri[i]], BookName[vitri[i]], Author[vitri[i]], NXB[vitri[i]], PublishYear[vitri[i]], Type[vitri[i]], Price[vitri[i]], QTy[vitri[i]]);
		}
	}
}
/*
Tìm vị trí của mã sách trong mảng ISBN
- ISBN[20][20]: Mảng chứa các mã sách
- ISBNN_looking: Giá trị ISBN cần tìm
- nBooks: Số lượng ISBN trong thư viện đang quản lý
- Trả về vị trí ISBN trong mảng, nếu không có thì trả về -1
*/
int TimVitriISBN(char ISBN[20][20], char ISBN_looking[20], int nBooks)
{
	for (int i = 0; i < nBooks; i++)
	{
		if (strcmp(ISBN[i], ISBN_looking) == 0)
			return i;
	}
	return -1;
}
